# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
AUDIO_ENABLE = no           # Audio output
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
COMMAND_ENABLE = no         # Commands for debug and configuration
CONSOLE_ENABLE = no         # Console for debug
EXTRAKEY_ENABLE = yes       # Audio control and System control
LTO_ENABLE = yes            # Link time optimise, reduce firmware size
MOUSEKEY_ENABLE = yes       # Mouse keys
NKRO_ENABLE = yes           # Enable N-Key Rollover
OLED_DRIVER = SSD1306
OLED_ENABLE = yes
RGBLIGHT_ENABLE = yes       # Enable keyboard RGB
ENCODER_ENABLE = yes		# Encoders
TAP_DANCE_ENABLE = yes
