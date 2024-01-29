export ARCH=arm64
export OUT=$(PWD)/out
export CROSS_COMPILE=/usr/local/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-
export BL31=$(PWD)/rkbin/rk33/rk3328_bl31_v1.34.bin

u-boot: cleanuboot builduboot postbuilduboot

cleanuboot:
	\rm -f $(OUT)/idbloader.img
	\rm -f $(OUT)/rk3328_loader_ddr786_v1.06.243.bin
	\rm -f $(OUT)/trust.img
	\rm -f $(OUT)/uboot.img

builduboot:
	cd u-boot; \
	make clean; \
	make ARCH=arm64 roc-cc-rk3328_defconfig; \
	make all

postbuilduboot:
	cd u-boot; \
	../rkbin/tools/loaderimage --pack --uboot ./u-boot-dtb.bin uboot.img 0x200000; \
	./tools/mkimage -n rk3328 -T rksd -d ../rkbin/rk33/rk3328_ddr_786MHz_v1.06.bin idbloader.img; \
	cat ../rkbin/rk33/rk3328_miniloader_v2.43.bin >> idbloader.img; \
	cp idbloader.img ${OUT}/; \
	cp ../rkbin/rk33/rk3328_loader_ddr786_v1.06.243.bin ${OUT}/; \
	../rkbin/tools/trust_merger ../trust.ini; \
	cp uboot.img ${OUT}/; \
	cp trust.img ${OUT}/
