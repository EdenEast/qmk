SRC += edeneast.c \
       process_records.c

# Common flags
LTO_ENABLE      = yes # Optimize at link time for resulting smaller files
EXTRAKEY_ENABLE = yes # Audio controls and system controls
NKRO_ENABLE     = yes # NKey Rollover
COMMAND_ENABLE  = yes # Commands for debug and configuration

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
    SRC += tap_dances.c
endif
