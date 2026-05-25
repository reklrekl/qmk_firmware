SRC += gmmk.c
SRC += drivers/eeprom/eeprom_sn32_legacy.c
SRC += drivers/flash/sn32_legacy_flash_ops.c

# reduce stack size
# 0xE0 known working,  0xA0 needed according to AI
USE_EXCEPTIONS_STACKSIZE = 0xC8
# 0x1D0 known working, 0x174 needed according to AI
USE_PROCESS_STACKSIZE = 0x1B0
TOP_SYMBOLS = 10000

# Size and optimization flags: LTO, optimize for size, strip unused
EXTRAFLAGS += -flto -Os -ffunction-sections -fdata-sections -DNO_DEBUG -DNO_PRINT -fstack-usage
LDFLAGS += -Wl,--gc-sections


MOUSE_ENABLE = no
RAW_ENABLE = no
JOYSTICK_ENABLE = no
DIGITIZER_ENABLE = no
VIRTSER_ENABLE = no
