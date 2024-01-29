# Create an image that can be written onto a SD card using dd.

inherit image_types

# Use an uncompressed ext4 by default as rootfs
IMG_ROOTFS_TYPE = "ext4"
IMG_ROOTFS = "${IMGDEPLOYDIR}/${IMAGE_BASENAME}-${MACHINE}.${IMG_ROOTFS_TYPE}"

# This image depends on the rootfs image
IMAGE_TYPEDEP:rk3328-gpt-img = "${IMG_ROOTFS_TYPE}"

GPTIMG = "${IMAGE_BASENAME}-${MACHINE}-gpt.img"
BOOT_IMG = "${IMAGE_BASENAME}-${MACHINE}-boot.img"
IDBLOADER = "idbloader.img"

# Get From radxa-binary loader
DDR_BIN = "radxa-binary/ddr.bin"
LOADER_BIN = "radxa-binary/loader.bin"
MINILOADER_BIN = "radxa-binary/miniloader.bin"
ATF_BIN = "radxa-binary/atf.bin"
BL31_ELF = "radxa-binary/bl31.elf"
TRUST_IMG = "trust.img"
# Not from radxa-binary
UBOOT_IMG = "u-boot.img"

GPTIMG_APPEND:rk3328 = "console=tty1 console=ttyS2,1500000n8 rw \
	root=PARTUUID=b921b045-1d rootfstype=ext4 init=/sbin/init rootwait"

# default partitions [in Sectors]
# More info at http://rockchip.wikidot.com/partitions
LOADER1_SIZE = "8000"
RESERVED1_SIZE = "128"
RESERVED2_SIZE = "8192"
LOADER2_SIZE = "8192"
ATF_SIZE = "8192"
BOOT_SIZE = "229376"

# WORKROUND: miss recipeinfo
do_image_rk3328_gpt_img[depends] += " \
	radxa-binary-native:do_populate_lic \
	virtual/bootloader:do_populate_lic"

do_image_rk3328_gpt_img[depends] += " \
	parted-native:do_populate_sysroot \
	mtools-native:do_populate_sysroot \
	gptfdisk-native:do_populate_sysroot \
	dosfstools-native:do_populate_sysroot \
	radxa-binary-native:do_populate_sysroot \
	radxa-binary-loader:do_deploy \
	virtual/kernel:do_deploy \
	virtual/bootloader:do_deploy"

PER_CHIP_IMG_GENERATION_COMMAND:rk3328 = "generate_rk3328_loader_image"

IMAGE_CMD:rk3328-gpt-img () {
	# Change to image directory
	cd ${DEPLOY_DIR_IMAGE}

	# Remove the existing image
	rm -f "${GPTIMG}"
	rm -f "${BOOT_IMG}"

	create_rk_image

	${PER_CHIP_IMG_GENERATION_COMMAND}

	cd ${DEPLOY_DIR_IMAGE}
	if [ -f ${WORKDIR}/${BOOT_IMG} ]; then
		cp ${WORKDIR}/${BOOT_IMG} ./
	fi
}

create_rk_image () {

	# last dd rootfs will extend gpt image to fit the size,
	# but this will overrite the backup table of GPT
	# will cause corruption error for GPT
	IMG_ROOTFS_SIZE=$(stat -L --format="%s" ${IMG_ROOTFS})

	GPTIMG_MIN_SIZE=$(expr $IMG_ROOTFS_SIZE + \( ${LOADER1_SIZE} + ${RESERVED1_SIZE} + ${RESERVED2_SIZE} + ${LOADER2_SIZE} + ${ATF_SIZE} + ${BOOT_SIZE} + 35 \) \* 512 )

	GPT_IMAGE_SIZE=$(expr $GPTIMG_MIN_SIZE \/ 1024 \/ 1024 + 2)

	# Initialize sdcard image file
	dd if=/dev/zero of=${GPTIMG} bs=1M count=0 seek=6144

	# Create partition table
	parted -s ${GPTIMG} mklabel gpt

	# Create vendor defined partitions
	LOADER1_START=64
	RESERVED1_START=$(expr ${LOADER1_START} + ${LOADER1_SIZE})
	RESERVED2_START=$(expr ${RESERVED1_START} + ${RESERVED1_SIZE})
	LOADER2_START=$(expr ${RESERVED2_START} + ${RESERVED2_SIZE})
	ATF_START=$(expr ${LOADER2_START} + ${LOADER2_SIZE})
	BOOT_START=$(expr ${ATF_START} + ${ATF_SIZE})
	ROOTFS_START=$(expr ${BOOT_START} + ${BOOT_SIZE})

	parted -s ${GPTIMG} unit s mkpart loader1 64 8063
	parted -s ${GPTIMG} unit s mkpart loader2 16384 24575
	parted -s ${GPTIMG} unit s mkpart trust 24576 32767

	# Create boot partition and mark it as bootable
	parted -s ${GPTIMG} unit s mkpart boot 32768 1081343
	parted -s ${GPTIMG} set 4 boot on

	# Create rootfs partition
	parted -s ${GPTIMG} -- unit s mkpart rootfs 1081344 -34s

	parted ${GPTIMG} print

	ROOT_UUID="B921B045-1DF0-41C3-AF44-4C6F280D3FAE"

	# Change rootfs partuuid
	gdisk ${GPTIMG} <<EOF
x
c
5
${ROOT_UUID}
w
y
EOF

	# Delete the boot image to avoid trouble with the build cache
	rm -f ${WORKDIR}/${BOOT_IMG}
	# Create boot partition image
	BOOT_BLOCKS=$(LC_ALL=C parted -s ${GPTIMG} unit b print | awk '/ 4 / { print substr($4, 1, length($4 -1)) / 512 /2 }')
	BOOT_BLOCKS=$(expr $BOOT_BLOCKS / 63 \* 63)

	mkfs.vfat -n "boot" -S 512 -C ${WORKDIR}/${BOOT_IMG} 1024100
	mcopy -i ${WORKDIR}/${BOOT_IMG} -s ${DEPLOY_DIR_IMAGE}/${KERNEL_IMAGETYPE}-${MACHINE}.bin ::${KERNEL_IMAGETYPE}
	DTB_NAME=""
	DTB_NAME=$(echo "${KERNEL_DEVICETREE}" | cut -d '/' -f 2)

	mcopy -i ${WORKDIR}/${BOOT_IMG} -s ${DEPLOY_DIR_IMAGE}/${DTB_NAME} ::${DTB_NAME}

	mmd -i ${WORKDIR}/${BOOT_IMG} ::/extlinux
	mcopy -i ${WORKDIR}/${BOOT_IMG} -s ~/myproj2/build-roc-rk3328-cc/yocto-xfce/patches/rk3328.conf ::/extlinux/extlinux.conf
	# Burn Boot Partition
	dd if=${WORKDIR}/${BOOT_IMG} of=${GPTIMG} conv=notrunc,fsync seek=32768

	# Burn Rootfs Partition
	dd if=${IMG_ROOTFS} of=${GPTIMG} conv=notrunc,fsync seek=1081344

}

generate_rk3328_loader_image () {
	LOADER1_START=64
	RESERVED1_START=$(expr ${LOADER1_START} + ${LOADER1_SIZE})
	RESERVED2_START=$(expr ${RESERVED1_START} + ${RESERVED1_SIZE})
	LOADER2_START=$(expr ${RESERVED2_START} + ${RESERVED2_SIZE})
	ATF_START=$(expr ${LOADER2_START} + ${LOADER2_SIZE})
	BOOT_START=$(expr ${ATF_START} + ${ATF_SIZE})
	ROOTFS_START=$(expr ${BOOT_START} + ${BOOT_SIZE})

	# Burn bootloader
	loaderimage --pack --uboot ${DEPLOY_DIR_IMAGE}/u-boot-${MACHINE}.bin ${DEPLOY_DIR_IMAGE}/${UBOOT_IMG} 0x200000 --size 1024 1

	/usr/bin/mkimage -n ${SOC_FAMILY} -T rksd -d ${DEPLOY_DIR_IMAGE}/${DDR_BIN} ${DEPLOY_DIR_IMAGE}/${IDBLOADER}
	cat ${DEPLOY_DIR_IMAGE}/${MINILOADER_BIN} >>${DEPLOY_DIR_IMAGE}/${IDBLOADER}
	cat >${DEPLOY_DIR_IMAGE}/trust.ini <<EOF
[VERSION]
MAJOR=1
MINOR=2
[BL30_OPTION]
SEC=0
[BL31_OPTION]
SEC=1
PATH=${BL31_ELF}
ADDR=0x10000
[BL32_OPTION]
SEC=0
[BL33_OPTION]
SEC=0
[OUTPUT]
PATH=trust.img
EOF

	trust_merger --size 1024 1 ${DEPLOY_DIR_IMAGE}/trust.ini

	dd if=${DEPLOY_DIR_IMAGE}/${IDBLOADER} of=${GPTIMG} conv=notrunc,fsync seek=64
	dd if=${DEPLOY_DIR_IMAGE}/${UBOOT_IMG} of=${GPTIMG} conv=notrunc,fsync seek=16384
	dd if=${DEPLOY_DIR_IMAGE}/${TRUST_IMG} of=${GPTIMG} conv=notrunc,fsync seek=24576
}
