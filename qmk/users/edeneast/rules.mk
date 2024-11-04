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

SRC += process_records.c
SRC += callbacks.c
SRC += features/layer_lock.c

# Feature defaults
SENTENCE_CASE_ENABLE ?= yes
SMART_CASE_ENABLE    ?= no
SOCD_CLEANER_ENABLE  ?= no
STENO_ENABLE         ?= no

# Allow for keymap or userspace rules.mk to specify an alternate location for the keymap array
INTROSPECTION_KEYMAP_C = edeneast.c

# Feature settings
ifeq ($(strip $(ACHORDION_ENABLE)), yes)
	SRC += features/achordion.c
	OPT_DEFS += -DACHORDION_ENABLE
endif

ifeq ($(strip $(DEBUG_ENABLE)), yes)
	COMMAND_ENABLE = yes  # Commands for debug and configuration
	CONSOLE_ENABLE = yes  # Console for debugging
	OPT_DEFS += -DDEBUG_ENABLE
endif

ifeq ($(strip $(OLED_ENABLE)), yes)
	SRC += oled.c
endif

ifeq ($(strip $(LEADER_ENABLE)), yes)
	SRC += leader.c
endif

ifeq ($(strip $(OS_DETECTION_ENABLE)), yes)
	SRC += os_detect.c
	OPT_DEFS += -DOS_DETECTION_ENABLE
endif

ifeq ($(strip $(SENTENCE_CASE_ENABLE)), yes)
	SRC += features/sentence_case.c
	OPT_DEFS += -DSENTENCE_CASE_ENABLE
endif

ifeq ($(strip $(SMART_CASE_ENABLE)), yes)
	SRC += smart_case.c
	OPT_DEFS += -DSMART_CASE_ENABLE
endif

ifeq ($(strip $(SOCD_CLEANER_ENABLE)), yes)
	SRC += features/socd_cleaner.c
	OPT_DEFS += -DSOCD_CLEANER_ENABLE
endif

ifeq ($(strip $(STENO_ENABLE)), yes)
	STENO_PROTOCOL = geminipr # Better protocol for steno
	VIRTSER_ENABLE = yes # Required for steno
endif

# Enable this for boards that dont have a shift key (macro pads)
ifeq ($(strip $(FLASH_BOOTLOADER)), yes)
	OPT_DEFS += -DFLASH_BOOTLOADER
endif
