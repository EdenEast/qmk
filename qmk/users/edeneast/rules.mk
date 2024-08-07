# Common flags
AUDIO_ENABLE         ?= no  # Use the audio system
BOOTMAGIC_ENABLE     ?= no  # Disable to allow keys during system boot
COMMAND_ENABLE       ?= no  # Commands for debug and configuration
CONSOLE_ENABLE       ?= no  # Console for debugging
GRAVE_ESC_ENABLE     ?= no  # Dont use it, save space
MIDI_ENABLE          ?= no  # Dont use it, save space
RGBLIGHT_ENABLE      ?= no  # No rgb
SPACE_CADET_ENABLE   ?= no  # Dont use it, save space

COMBO_ENABLE         ?= yes # Combo keys together
TAP_DANCE_ENABLE     ?= no  # Used for tmux prefix key
LEADER_ENABLE        ?= no  # Enable leader keys

# Required features
DEFERRED_EXEC_ENABLE = yes # Enable defer execution for os detection startup
EXTRAKEY_ENABLE      = yes # Audio controls and system controls
LTO_ENABLE           = yes # Optimize at link time for resulting smaller files
OS_DETECTION_ENABLE  = yes # Enable os detection

SRC += edeneast.c
SRC += process_records.c
SRC += os_detect.c
SRC += callbacks.c
SRC += features/layer_lock.c

# Feature defaults
SENTENCE_CASE_ENABLE ?= yes
SMART_CASE_ENABLE    ?= yes

# Feature settings
ifeq ($(strip $(STENO_ENABLE)), yes)
	STENO_PROTOCOL     = geminipr # Better protocol for steno
	VIRTSER_ENABLE     = yes # Required for steno
endif

ifeq ($(strip $(DEBUG_ENABLE)), yes)
	COMMAND_ENABLE = yes  # Commands for debug and configuration
	CONSOLE_ENABLE = yes  # Console for debugging
	OPT_DEFS += -DDEBUG_ENABLE
endif

ifeq ($(strip $(COMBO_ENABLE)), yes)
	INTROSPECTION_KEYMAP_C = combos.c
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	SRC += dances.c
endif

ifeq ($(strip $(OLED_ENABLE)), yes)
	SRC += oled.c
endif

ifeq ($(strip $(LEADER_ENABLE)), yes)
	SRC += leader.c
endif

ifeq ($(strip $(SMART_CASE_ENABLE)), yes)
	SRC += smart_case.c
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
