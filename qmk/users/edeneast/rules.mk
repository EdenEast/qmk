# Common flags to disable to save space
AUDIO_ENABLE         ?= no  # Use the audio system
BOOTMAGIC_ENABLE     ?= no  # Disable to allow keys during system boot
COMMAND_ENABLE       ?= no  # Commands for debug and configuration
CONSOLE_ENABLE       ?= no  # Console for debugging
GRAVE_ESC_ENABLE     ?= no  # Dont use it, save space
MIDI_ENABLE          ?= no  # Dont use it, save space
RGBLIGHT_ENABLE      ?= no  # No rgb
SPACE_CADET_ENABLE   ?= no  # Dont use it, save space

# Required features
DEFERRED_EXEC_ENABLE = yes # Enable defer execution for os detection startup
EXTRAKEY_ENABLE      = yes # Audio controls and system controls
LTO_ENABLE           = yes # Optimize at link time for resulting smaller files
OS_DETECTION_ENABLE  = yes # Enable os detection
LAYER_LOCK_ENABLE    = yes

# Optional default features
COMBO_ENABLE         ?= yes # Combo keys together
TAP_DANCE_ENABLE     ?= no  # Used for tmux prefix key
LEADER_ENABLE        ?= no  # Enable leader keys
STENO_ENABLE         ?= no  # Add Steno support

# Allow for keymap or userspace rules.mk to specify an alternate location for the keymap array
INTROSPECTION_KEYMAP_C = edeneast.c

SRC += process_records.c
SRC += callbacks.c

# -----------------------------------------------------------------------------
# Feature enable options

ACHORDION_ENABLE ?= yes
ifeq ($(strip $(ACHORDION_ENABLE)), yes)
	SRC += features/achordion.c
	OPT_DEFS += -DACHORDION_ENABLE
endif

SENTENCE_CASE_ENABLE ?= yes
ifeq ($(strip $(SENTENCE_CASE_ENABLE)), yes)
	SRC += features/sentence_case.c
	OPT_DEFS += -DSENTENCE_CASE_ENABLE
endif

SMART_CASE_ENABLE ?= no
ifeq ($(strip $(SMART_CASE_ENABLE)), yes)
	SRC += smart_case.c
	OPT_DEFS += -DSMART_CASE_ENABLE
endif

SOCD_CLEANER_ENABLE ?= no
ifeq ($(strip $(SOCD_CLEANER_ENABLE)), yes)
	SRC += features/socd_cleaner.c
	OPT_DEFS += -DSOCD_CLEANER_ENABLE
endif

# -----------------------------------------------------------------------------
# Builtin enable options

# Enable this for boards that dont have a shift key (macro pads)
ifeq ($(strip $(FLASH_BOOTLOADER)), yes)
	OPT_DEFS += -DFLASH_BOOTLOADER
endif

ifeq ($(strip $(DEBUG_ENABLE)), yes)
	COMMAND_ENABLE = yes  # Commands for debug and configuration
	CONSOLE_ENABLE = yes  # Console for debugging
	OPT_DEFS += -DDEBUG_ENABLE
endif

ifeq ($(strip $(LEADER_ENABLE)), yes)
	SRC += leader.c
endif

ifeq ($(strip $(OS_DETECTION_ENABLE)), yes)
	SRC += os_detect.c
	OPT_DEFS += -DOS_DETECTION_ENABLE
endif

ifeq ($(strip $(STENO_ENABLE)), yes)
	STENO_PROTOCOL = geminipr # Better protocol for steno
	VIRTSER_ENABLE = yes # Required for steno
endif

