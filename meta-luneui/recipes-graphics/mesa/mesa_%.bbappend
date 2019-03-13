# Use gallium and llvmpipe for rendering
PACKAGECONFIG_append = " gallium gallium-llvm"

PACKAGECONFIG_append = " gbm"

# Enable freedreno driver
GALLIUMDRIVERS_append_hammerhead = ",freedreno"
