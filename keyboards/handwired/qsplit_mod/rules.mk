# Comment this on the left side
# MCU = atmega32u4
# BOOTLOADER = caterina

# Comment this on the right side
MCU = at90usb1286
BOOTLOADER = halfkay

BOOTMAGIC_ENABLE ?= no	# Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE ?= yes	# Mouse keys(+4700)
EXTRAKEY_ENABLE ?= yes	# Audio control and System control(+450)
CONSOLE_ENABLE ?= false	# Console for debug(+400)
COMMAND_ENABLE ?= no    # Commands for debug and configuration
SLEEP_LED_ENABLE ?= no  # Breathing sleep LED during USB suspend
NKRO_ENABLE ?= no		# USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE ?= no  # Enable keyboard backlight functionality
SPLIT_KEYBOARD = yes
ENCODER_ENABLE = yes
RGBLIGHT_ENABLE = yes

# Comment this on the right side keyboard
QWIIC_ENABLE += MICRO_OLED
DIP_SWITCH_ENABLE = yes
AUDIO_ENABLE = yes
SRC += analog.c
WPM_ENABLE = yes
