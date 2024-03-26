# SWAP_HANDS_ENABLE = yes
ACHORDION_ENABLE     = yes
TAP_DANCE_ENABLE     = yes

ifeq ($(strip $(SWAP_HANDS_ENABLE)), yes)
	SRC += swap_hand.c
endif
