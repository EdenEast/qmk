# Common flags
AUDIO_ENABLE       = no  # Use the audio system
BOOTMAGIC_ENABLE   = no  # Disable to allow keys during system boot
COMMAND_ENABLE     = no  # Commands for debug and configuration
CONSOLE_ENABLE     = no  # Console for debugging
GRAVE_ESC_ENABLE   = no  # Dont use it, save space
MIDI_ENABLE        = no  # Dont use it, save space
MOUSEKEY_ENABLE    = no  # Mouse keys
RGBLIGHT_ENABLE    = no  # No rgb
SPACE_CADET_ENABLE = no  # Dont use it, save space

COMBO_ENABLE       = yes # Combo keys together
LTO_ENABLE         = yes # Optimize at link time for resulting smaller files
EXTRAKEY_ENABLE    = yes # Audio controls and system controls
NKRO_ENABLE        = yes # NKey Rollover
# STENO_ENABLE       = yes # Enable steno
# TAP_DANCE_ENABLE   = yes # Used for tmux prefix key

ifeq ($(strip $(STENO_ENABLE)), yes)
	STENO_PROTOCOL     = geminipr # Better protocol for steno
	VIRTSER_ENABLE     = yes # Required for steno
endif

# Feature enables
ACHORDION_ENABLE   = yes

# Add LTO compile flag
# https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/
EXTRAFLAGS += -flto

SRC += edeneast.c
SRC += process_records.c
SRC += combos.c

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

