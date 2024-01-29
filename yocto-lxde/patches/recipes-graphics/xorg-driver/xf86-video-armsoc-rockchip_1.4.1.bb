require recipes-graphics/xorg-driver/xorg-driver-video.inc

SUMMARY = "X.Org X server -- ARM SOC display driver"
LICENSE = "MIT-X & GPLv2+"
LIC_FILES_CHKSUM = "file://COPYING;md5=10ce5de3b111315ea652a5f74ec0c602"

DEPENDS += "virtual/libx11 libdrm xorgproto"

SRCREV = "${AUTOREV}"
SRC_URI = "git://github.com/mth/xf86-video-armsoc"
SRC_URI_append = " file://20-armsoc.conf"

FILES_${PN} += "${datadir}/X11/xorg.conf.d/20-armsoc.conf"

S = "${WORKDIR}/git"

RDEPENDS_${PN} += "xserver-xorg-module-exa"

do_install_append() {
  install -d ${D}/${datadir}/X11/xorg.conf.d
  install -m 0644 ${WORKDIR}/20-armsoc.conf ${D}/${datadir}/X11/xorg.conf.d
}
