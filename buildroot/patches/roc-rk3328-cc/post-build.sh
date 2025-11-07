#!/bin/sh

BOARD_DIR="$(dirname $0)"

install -m 0644 -D $BOARD_DIR/../../../../../linux/linux/arch/arm64/boot/Image $BINARIES_DIR/Image
install -m 0644 -D $BOARD_DIR/../../../../../linux/linux/arch/arm64/boot/dts/rockchip/rk3328-roc-cc.dtb $BINARIES_DIR/rk3328-roc-cc.dtb
install -m 0644 -D $BOARD_DIR/../../../../../linux/rk3328.conf $BINARIES_DIR/extlinux/extlinux.conf

# install -m 0644 -D "${BOARD_DIR}/extlinux.conf" "${TARGET_DIR}/boot/extlinux/extlinux.conf"
install -m 0644 -D $BOARD_DIR/../../../../../uboot/out/trust.img $BINARIES_DIR/trust.img
install -m 0644 -D $BOARD_DIR/../../../../../uboot/out/uboot.img $BINARIES_DIR/uboot.img
install -m 0644 -D $BOARD_DIR/../../../../../uboot/out/idbloader.img $BINARIES_DIR/idbloader.img
