SUMMARY = "Basic desktop image for RK3328 boards"

IMAGE_FEATURES += "splash package-management ssh-server-openssh hwcodecs x11"

LICENSE = "MIT"

inherit core-image extrausers

# let's make sure we have a good image..
REQUIRED_DISTRO_FEATURES = "pam systemd"

EXTRA_USERS_PARAMS = "usermod -P rock root;"
EXTRA_USERS_PARAMS += "useradd -P rock rock;"

# make sure we boot to desktop
# by default and without x11-base in IMAGE_FEATURES we default to multi-user.target
SYSTEMD_DEFAULT_TARGET = "graphical.target"

CORE_IMAGE_BASE_INSTALL += " \
    kernel-modules \
    packagegroup-rk3328-console \
    openbox \
    packagegroup-xfce-extended \
    lxdm \
"
