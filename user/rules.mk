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
STENO_ENABLE       = yes # Enable steno
STENO_PROTOCOL     = geminipr # Better protocol for steno
VIRTSER_ENABLE     = yes # Required for steno
TAP_DANCE_ENABLE   = yes # Used for tmux prefix key

# Add LTO compile flag
# https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/
EXTRAFLAGS += -flto

SRC += edeneast.c
SRC += process_records.c
SRC += combos.c
SRC += dances.c

ifeq ($(strip $(OLED_ENABLE)), yes)
	SRC += oled.c
endif
