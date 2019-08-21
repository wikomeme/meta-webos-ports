# Copyright (c) 2019 Christophe Chapuis <chris.chapuis@gmail.com>

DESCRIPTION = "GLib bindings for mce."
LICENSE = "MIT"
SECTION = "webos/support"
LIC_FILES_CHKSUM = "file://src/mce_display.c;beginline=1;endline=35;md5=999eef94327cfda24c3f60f25ee98fd7"

DEPENDS = "glib-2.0 glib-2.0-native libglibutil"

inherit pkgconfig

SRC_URI = "git://git.merproject.org/mer-core/libmce-glib.git;protocol=git;branch=master \
           file://0001-Makefile-use-CC-from-bitbake.patch \
           https://git.merproject.org/mer-core/mce-dev/raw/03a4de12e5fabad8c0d846663e1a1a2cbfd88957/include/mce/dbus-names.h;name=dbus-names \
           https://git.merproject.org/mer-core/mce-dev/raw/03a4de12e5fabad8c0d846663e1a1a2cbfd88957/include/mce/mode-names.h;name=mode-names"
S = "${WORKDIR}/git"

SRC_URI[dbus-names.md5sum] = "2040ea70d49e679fe915dc6bc76a7aa1"
SRC_URI[mode-names.md5sum] = "b4927cca05e21114a5ba40c0d1e27f8a"

PV = "1.0.5-1+git${SRCPV}"
SRCREV = "29091d9f0d21e8989b81900bd3fa5f2280ae022b"

EXTRA_OEMAKE = "KEEP_SYMBOLS=1"
PARALLEL_MAKE = ""

do_compile_prepend() {
    mkdir ${S}/include/mce
    cp -f ${WORKDIR}/dbus-names.h ${S}/include/mce/
    cp -f ${WORKDIR}/mode-names.h ${S}/include/mce/
}

do_install() {
    make install DESTDIR=${D}
    make install-dev DESTDIR=${D}
}
