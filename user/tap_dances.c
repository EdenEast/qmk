#include "tap_dances.h"
#include "edeneast.h"

// Dance to determine what base layout to use
// 1 - Colemak
// 2 - Qwerty
// 3 - Game
void dance_base_layer(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1: // Colemak
            set_single_persistent_default_layer(_COLEMAK_DH);
            break;
        case 2: // Qwerty
            set_single_persistent_default_layer(_QWERTY);
            break;
        case 3: // Game
            set_single_persistent_default_layer(_GAME);
            break;
    }

    reset_tap_dance(state);
}


qk_tap_dance_action_t tap_dance_actions[] = {
    [DANCE_LAYER] = ACTION_TAP_DANCE_FN(dance_base_layer)
};
