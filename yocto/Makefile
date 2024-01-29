get_kernel:
	cd kernel.git; \
	cp ../kernelpatches/fireflyrk3328_linux_defconfig ./arch/arm64/configs/; \
	cp ../kernelpatches/rk3328-roc-cc.dts ./arch/arm64/boot/dts/rockchip/; \
	cp ../kernelpatches/rk3328.dtsi ./arch/arm64/boot/dts/rockchip/; \
	cp ../kernelpatches/rk3328-box-plus-dram-timing.dtsi ./arch/arm64/boot/dts/rockchip/; \
	cp ../kernelpatches/rk3328-dram-default-timing.dtsi ./arch/arm64/boot/dts/rockchip/; \
	cp ../kernelpatches/Makefile ./arch/arm64/boot/dts/rockchip/; \
	git init; \
	git add * ; \
	git commit -m "initial release"; \
	git status; \
	git remote add origin https://github.com/radxa/kernel.git

apply_patches:
	cd poky/build; \
	cp -r ../../patches/recipes-graphics ../meta-radxa/; \
	cp ../../patches/rockchip-rk3328-evb.conf ../meta-radxa/conf/machine/; \
	cp ../../patches/u-boot-rockchip.bb ../meta-radxa/recipes-bsp/u-boot/; \
	cp ../../patches/modify.patch ../meta-radxa/recipes-bsp/u-boot/files/; \
	cp -r ../../patches/images ../meta-radxa/recipes-core/; \
	cp -r ../../patches/packagegroups ../meta-radxa/recipes-core/; \
	cp ../../patches/rk3328-gpt-img.bbclass ../meta-radxa/classes/; \
	cp ../../patches/linux-rockchip_4.4.bb ../meta-radxa/recipes-kernel/linux/; \
	cp ../../patches/bblayers.conf ./conf/; \
	cp ../../patches/local.conf ./conf/
