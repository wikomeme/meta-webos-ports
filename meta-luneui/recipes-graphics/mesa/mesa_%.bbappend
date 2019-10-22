# Use gallium and llvmpipe for rendering in qemu
PACKAGECONFIG_append_class-target_qemuall = " gallium-llvm"

# Enable freedreno driver for hammerhead
PACKAGECONFIG[freedreno] = ""
PACKAGECONFIG_append_hammerhead = " kmsro freedreno"
GALLIUMDRIVERS_append_hammerhead = "${@bb.utils.contains('PACKAGECONFIG', 'freedreno', ',freedreno', '', d)}"
