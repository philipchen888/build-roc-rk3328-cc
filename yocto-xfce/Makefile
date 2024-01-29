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
	\rm -rf ../meta-rockchip/recipes-multimedia/rockchip-rkaiq; \
	\rm -f ../meta-rockchip/recipes-kernel/linux/*.bb; \
	cp -rf ../../patches/resize-helper ../meta-rockchip/recipes-bsp/; \
	cp ../../patches/xfce-desktop-image.bb ../meta/recipes-graphics/images/; \
	\rm -rf ../meta-rockchip/recipes-graphics/; \
	cp -r ../../patches/recipes-graphics ../meta-rockchip/; \
	cp ../../patches/rockchip-rk3328-evb.conf ../meta-rockchip/conf/machine/; \
	\rm -rf ../meta-rockchip/recipes-bsp/u-boot/files/; \
	mkdir ../meta-rockchip/recipes-bsp/u-boot/files/; \
	cp ../../patches/radxa-binary* ../meta-rockchip/recipes-bsp/rk-binary/; \
	cp ../../patches/u-boot-rockchip.bb ../meta-rockchip/recipes-bsp/u-boot/; \
	cp ../../patches/modify.patch ../meta-rockchip/recipes-bsp/u-boot/files/; \
	cp ../../patches/rk3328-gpt-img.bbclass ../meta-rockchip/classes/; \
	cp ../../patches/linux-rockchip_4.4.bb ../meta-rockchip/recipes-kernel/linux/; \
	cp ../../patches/bblayers.conf ./conf/; \
	cp ../../patches/local.conf ./conf/
