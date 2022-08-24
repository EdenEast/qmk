#include "tap_dances.h"
#include "edeneast.h"

// Determine the current tap dance state
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (!state->pressed) return TD_DOUBLE_TAP;
        else return TD_DOUBLE_HOLD;
    }
    else return TD_UNKNOWN;
}

static td_tap_t tm_tap_state = {
    .state = TD_NONE
};

// Dance to determine what base layout to use
// 1 - Colemak
// 2 - Game
void dance_base_layer(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1: // Colemak
            set_single_persistent_default_layer(_COLEMAK_DH);
            break;
        case 2: // Game
            set_single_persistent_default_layer(_GAME);
            break;
    }

    reset_tap_dance(state);
}

void dance_tmux(qk_tap_dance_state_t *state, void *user_data) {
    tm_tap_state.state = cur_dance(state);
    uint8_t mod_state = get_mods();
    switch (tm_tap_state.state) {
        case TD_SINGLE_TAP:
            clear_mods();
            add_mods(MOD_BIT(KC_LCTL));
            tap_code(KC_A);
            set_mods(mod_state);
            break;
        default:
            register_mods(MOD_BIT(KC_LSFT));
            break;
    }
}

void tm_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (tm_tap_state.state != TD_SINGLE_TAP) {
        unregister_mods(MOD_BIT(KC_LSFT));
    }
    tm_tap_state.state = TD_NONE;
}


qk_tap_dance_action_t tap_dance_actions[] = {
    [DANCE_LAYER] = ACTION_TAP_DANCE_FN(dance_base_layer),
    [DANCE_TMUX] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_tmux, tm_reset),
};
