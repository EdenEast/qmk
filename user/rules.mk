SRC += edeneast.c \
       process_records.c

# Common flags
LTO_ENABLE       = yes # Optimize at link time for resulting smaller files
EXTRAKEY_ENABLE  = yes # Audio controls and system controls
NKRO_ENABLE      = yes # NKey Rollover
COMMAND_ENABLE   = no  # Commands for debug and configuration
TAP_DANCE_ENABLE = yes # Used for tmux prefix key
STENO_ENABLE     = yes # Enable steno

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
    SRC += tap_dances.c
endif

ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
    SRC += oled.c
endif

