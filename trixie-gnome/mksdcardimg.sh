#!/bin/sh
BOOT=/dev/sda
dd if=/dev/zero of=${BOOT} bs=1M count=0 seek=7168
parted -s ${BOOT} mklabel gpt
parted -s ${BOOT} unit s mkpart loader1 64 8063
parted -s ${BOOT} unit s mkpart loader2 16384 24575
parted -s ${BOOT} unit s mkpart trust 24576 32767
parted -s ${BOOT} unit s mkpart boot 32768 1081343
parted -s ${BOOT} set 4 boot on
parted -s ${BOOT} -- unit s mkpart rootfs 1081344 -34s
ROOT_UUID="B921B045-1DF0-41C3-AF44-4C6F280D3FAE"
gdisk ${BOOT} <<EOF
x
c
5
${ROOT_UUID}
w
y
EOF
dd if=../uboot/out/idbloader.img of=${BOOT} bs=4096 seek=8 conv=notrunc,fsync
dd if=../uboot/out/uboot.img of=${BOOT} bs=4096 seek=2048 conv=notrunc,fsync
dd if=../uboot/out/trust.img of=${BOOT} bs=4096 seek=3072 conv=notrunc,fsync
dd if=../linux/out/boot.img of=${BOOT} bs=4096 seek=4096 conv=notrunc,fsync
dd if=../rootfs-trixie/linaro-rootfs.img of=${BOOT} bs=4096 seek=135168 conv=notrunc,fsync
