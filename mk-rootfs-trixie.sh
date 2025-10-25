#!/bin/bash -e

# Directory contains the target rootfs
TARGET_ROOTFS_DIR="binary"

if [ -e $TARGET_ROOTFS_DIR ]; then
	sudo rm -rf $TARGET_ROOTFS_DIR
fi

if [ "$ARCH" == "armhf" ]; then
	ARCH='armhf'
elif [ "$ARCH" == "arm64" ]; then
	ARCH='arm64'
else
    echo -e "\033[36m please input is: armhf or arm64...... \033[0m"
fi

if [ ! $VERSION ]; then
	VERSION="release"
fi

if [ ! -e live-image-$ARCH.tar.tar.gz ]; then
	echo "\033[36m Run sudo lb build first \033[0m"
fi

finish() {
	sudo umount -lf $TARGET_ROOTFS_DIR/proc || true
        sudo umount -lf $TARGET_ROOTFS_DIR/sys || true
        sudo umount -lf $TARGET_ROOTFS_DIR/dev/pts || true
        sudo umount -lf $TARGET_ROOTFS_DIR/dev || true
	exit -1
}
trap finish ERR

echo -e "\033[36m Extract image \033[0m"
sudo tar -xpf live-image-$ARCH.tar.tar.gz

sudo cp -rf ../linux/linux/tmp/lib/modules $TARGET_ROOTFS_DIR/lib

# packages folder
sudo mkdir -p $TARGET_ROOTFS_DIR/packages
sudo cp -rf ../packages/$ARCH/* $TARGET_ROOTFS_DIR/packages

# overlay folder
sudo cp -rf ../overlay/* $TARGET_ROOTFS_DIR/

echo -e "\033[36m Change root.....................\033[0m"
if [ "$ARCH" == "armhf" ]; then
	sudo cp /usr/bin/qemu-arm-static $TARGET_ROOTFS_DIR/usr/bin/
elif [ "$ARCH" == "arm64"  ]; then
	sudo cp /usr/bin/qemu-aarch64-static $TARGET_ROOTFS_DIR/usr/bin/
fi
sudo mount -o bind /proc $TARGET_ROOTFS_DIR/proc
sudo mount -o bind /sys $TARGET_ROOTFS_DIR/sys
sudo mount -o bind /dev $TARGET_ROOTFS_DIR/dev
sudo mount -o bind /dev/pts $TARGET_ROOTFS_DIR/dev/pts

cat << EOF | sudo chroot $TARGET_ROOTFS_DIR

rm -rf /etc/resolv.conf
echo -e "nameserver 8.8.8.8\nnameserver 8.8.4.4" > /etc/resolv.conf
resolvconf -u
apt-get update
apt-get upgrade -y
apt-get install -y build-essential git wget v4l-utils lightdm lxde libegl1 libgles2 libgbm1 libgl1-mesa-dri libglx-mesa0 mesa-vdpau-drivers
ldconfig

chmod o+x /usr/lib/dbus-1.0/dbus-daemon-launch-helper
chmod +x /etc/rc.local

cp /packages/rtlbt/rtl8761bu* /lib/firmware/rtl_bt/
apt-get install -f -y

# Create the linaro user account
/usr/sbin/useradd -d /home/linaro -G adm,sudo,video -m -N -u 29999 linaro
echo -e "linaro:linaro" | chpasswd
echo -e "linaro-alip" | tee /etc/hostname

# Default gnome-xorg.desktop
sed -i 's/#WaylandEnable=false/WaylandEnable=false/g' /etc/gdm3/daemon.conf
rm -f /usr/share/wayland-sessions/ubuntu*.desktop /usr/share/wayland-sessions/gnome*.desktop

systemctl disable gdm3
systemctl enable lightdm
systemctl enable resize-helper
chsh -s /bin/bash linaro

#---------------Clean--------------
rm -rf /var/lib/apt/lists/*
sync
EOF

sudo umount -lf $TARGET_ROOTFS_DIR/proc || true
sudo umount -lf $TARGET_ROOTFS_DIR/sys || true
sudo umount -lf $TARGET_ROOTFS_DIR/dev/pts || true
sudo umount -lf $TARGET_ROOTFS_DIR/dev || true
sync
