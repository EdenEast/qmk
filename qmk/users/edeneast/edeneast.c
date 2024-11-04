#include "edeneast.h"

#ifdef COMBO_ENABLE
#  include "combos.c"
#endif

// `tap_dance_action_t tap_dance_actions` required to be in the keymap.c file this ensures that this will
// be sourced in the keymap.c file https://github.com/qmk/qmk_firmware/issues/24530#issuecomment-2439673620
#ifdef TAP_DANCE_ENABLE
#  include "dances.c"
#endif
