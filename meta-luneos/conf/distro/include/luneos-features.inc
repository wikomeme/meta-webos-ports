# Copyright (c) 2012-2013 LG Electronics, Inc.

# Keep in sync with setting in oe-core/meta/conf/distro/include/default-distrovars.inc
# TODO: Maybe change this to use "_remove" when it's introduced in bitbake

# Split some features to separate variables
# Remove argp (not used in OE anymore) and x11 (not needed for Open webOS)
WEBOS_DISTRO_FEATURES_DEFAULT = "\
  alsa ext2 irda largefile xattr \
"
WEBOS_DISTRO_FEATURES_OPENGL = "opengl"
# Remove x11
WEBOS_DISTRO_FEATURES_WINDOW_SYSTEM = ""
WEBOS_DISTRO_FEATURES_BUSES = "pci pcmcia"
WEBOS_DISTRO_FEATURES_USB = "usbhost usbgadget"
WEBOS_DISTRO_FEATURES_CONNECTIVITY = "bluetooth 3g wifi bluez5 nfc"
WEBOS_DISTRO_FEATURES_NETWORKING = "nfs zeroconf"

WEBOS_DISTRO_FEATURES_LD = "ld-is-gold"

WEBOS_DISTRO_FEATURES_INIT = "systemd"
WEBOS_DISTRO_FEATURES_INIT_CONSIDERED = "sysvinit"
DISTRO_FEATURES_BACKFILL_CONSIDERED += "${WEBOS_DISTRO_FEATURES_INIT_CONSIDERED} bluez4"

DISTRO_FEATURES = "\
  ${WEBOS_DISTRO_FEATURES_DEFAULT} \
  ${WEBOS_DISTRO_FEATURES_OPENGL} \
  ${WEBOS_DISTRO_FEATURES_WINDOW_SYSTEM} \
  ${WEBOS_DISTRO_FEATURES_BUSES} \
  ${WEBOS_DISTRO_FEATURES_USB} \
  ${WEBOS_DISTRO_FEATURES_CONNECTIVITY} \
  ${WEBOS_DISTRO_FEATURES_NETWORKING} \
  ${WEBOS_DISTRO_FEATURES_LIBC} \
  ${WEBOS_DISTRO_FEATURES_LD} \
  ${WEBOS_DISTRO_FEATURES_INIT} \
"

# Enable adb support
DISTRO_FEATURES += "adb"

# For proper support of wayland through the whole stack we need to set it as distro
# feature (e.g. mesa requiers it to be set to compile the egl platform module)
DISTRO_FEATURES += "wayland"

# Use vc4graphics for all raspberrypi MACHINEs
MACHINE_FEATURES_append_rpi = " vc4graphics"

# Our mesa doesn't provide gl.pc used by glmark2
PACKAGECONFIG_remove_pn-glmark2 = "wayland-gl drm-gl"
# Fails with libhybris
# | ../src/gl-state-egl.cpp: In member function 'bool GLStateEGL::gotValidDisplay()':
# | ../src/gl-state-egl.cpp:438:9: error: 'PFNEGLGETPLATFORMDISPLAYEXTPROC' was not declared in this scope
# |          PFNEGLGETPLATFORMDISPLAYEXTPROC get_platform_display =
# |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# | ../src/gl-state-egl.cpp:438:9: note: suggested alternative: 'PFNGLGETNUNIFORMIVEXTPROC'
# |          PFNEGLGETPLATFORMDISPLAYEXTPROC get_platform_display =
# |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# |          PFNGLGETNUNIFORMIVEXTPROC
# | ../src/gl-state-egl.cpp:442:13: error: 'get_platform_display' was not declared in this scope
# |          if (get_platform_display != nullptr) {
# |              ^~~~~~~~~~~~~~~~~~~~
PACKAGECONFIG_remove_pn-glmark2 = "wayland-gles2"
