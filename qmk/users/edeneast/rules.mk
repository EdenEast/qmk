# Common flags
AUDIO_ENABLE        = no  # Use the audio system
BOOTMAGIC_ENABLE    = no  # Disable to allow keys during system boot
COMMAND_ENABLE      = yes  # Commands for debug and configuration
CONSOLE_ENABLE      = yes  # Console for debugging
GRAVE_ESC_ENABLE    = no  # Dont use it, save space
MIDI_ENABLE         = no  # Dont use it, save space
MOUSEKEY_ENABLE     = no  # Mouse keys
RGBLIGHT_ENABLE     = no  # No rgb
SPACE_CADET_ENABLE  = no  # Dont use it, save space

COMBO_ENABLE        = yes # Combo keys together
LTO_ENABLE          = yes # Optimize at link time for resulting smaller files
EXTRAKEY_ENABLE     = yes # Audio controls and system controls
CAPS_WORD_ENABLE    = yes
# NKRO_ENABLE         = yes # NKey Rollover
# STENO_ENABLE        = yes # Enable steno
TAP_DANCE_ENABLE    = yes # Used for tmux prefix key
OS_DETECTION_ENABLE = yes # Enable os detection

ifeq ($(strip $(STENO_ENABLE)), yes)
	STENO_PROTOCOL     = geminipr # Better protocol for steno
	VIRTSER_ENABLE     = yes # Required for steno
endif

# Feature enables
# ACHORDION_ENABLE     = yes
SENTENCE_CASE_ENABLE = yes

# Add LTO compile flag
# https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/
EXTRAFLAGS += -flto

SRC += edeneast.c
SRC += process_records.c
SRC += os_detect.c
SRC += smart_case.c

ifeq ($(strip $(COMBO_ENABLE)), yes)
	INTROSPECTION_KEYMAP_C = combos.c
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	SRC += dances.c
endif

ifeq ($(strip $(OLED_ENABLE)), yes)
	SRC += oled.c
endif

ifeq ($(strip $(ACHORDION_ENABLE)), yes)
	SRC += features/achordion.c
	OPT_DEFS += -DACHORDION_ENABLE
endif

ifeq ($(strip $(SENTENCE_CASE_ENABLE)), yes)
	SRC += features/sentence_case.c
	OPT_DEFS += -DSENTENCE_CASE_ENABLE
endif

# Enable this for boards that dont have a shift key (macro pads)
ifeq ($(strip $(FLASH_BOOTLOADER)), yes)
    OPT_DEFS += -DFLASH_BOOTLOADER
endif
