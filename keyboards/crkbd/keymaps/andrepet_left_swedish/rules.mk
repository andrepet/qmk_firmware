TAP_DANCE_ENABLE = no
KEY_OVERRIDE_ENABLE = yes
UNICODEMAP_ENABLE = no # used to handle unicode characters, not using it anymore
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no		    # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE = yes			# Enable per-key RGB
OLED_DRIVER_ENABLE = yes 		# Enable check for oled at all for each press
MOUSEKEY_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes

# to save filesize
LTO_ENABLE = yes #  Enables Link Time Optimization (LTO) when compiling the keyboard. This makes the process take longer, but it can significantly reduce the compiled size (and since the firmware is small, the added time is not noticeable).
CONSOLE_ENABLE = no
BOOTMAGIC_ENABLE = no
COMMAND_ENABLE   = no  # Commands for debug and configuration
SWAP_HANDS_ENABLE= no  # Allow swapping hands of keyboard
