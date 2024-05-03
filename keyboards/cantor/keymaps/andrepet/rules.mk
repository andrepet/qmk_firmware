TAP_DANCE_ENABLE = no
KEY_OVERRIDE_ENABLE = yes
UNICODEMAP_ENABLE = no # used to handle unicode characters, not using it anymore

# to save filesize
LTO_ENABLE = yes #  Enables Link Time Optimization (LTO) when compiling the keyboard. This makes the process take longer, but it can significantly reduce the compiled size (and since the firmware is small, the added time is not noticeable).
CONSOLE_ENABLE = no
BOOTMAGIC_ENABLE = no
COMMAND_ENABLE   = no  # Commands for debug and configuration
SWAP_HANDS_ENABLE= no  # Allow swapping hands of keyboard
OLED_DRIVER_ENABLE = no # Don't chech for oled at all for each press
