#include "dances.h"
#include "edeneast.h"

// Initialize tap structure associated with example tap dance key
static td_tap_t media_tap_state = {.is_press_action = true, .state = TD_NONE};

// Initialize tap structure associated with example tap dance key
static td_tap_t grv_pair_tap_state = {.is_press_action = true,
                                      .state = TD_NONE};

static td_tap_t alt_mod_tap_state = {.is_press_action = true, .state = TD_NONE};
static td_tap_t gui_mod_tap_state = {.is_press_action = true, .state = TD_NONE};

td_state_t cur_dance(tap_dance_state_t *state) {
  switch (state->count) {
  case 1:
    return !state->pressed ? TD_1X_TAP : TD_1X_HOLD;
  case 2:
    return !state->pressed ? TD_2X_TAP : TD_2X_HOLD;
  case 3:
    return !state->pressed ? TD_3X_TAP : TD_3X_HOLD;
  case 4:
    return !state->pressed ? TD_4X_TAP : TD_4X_HOLD;
  default:
    return TD_UNKNOWN;
  }
}

// Functions that control what our tap dance key does
void td_media_finished(tap_dance_state_t *state, void *user_data) {
  media_tap_state.state = cur_dance(state);
  switch (media_tap_state.state) {
  case TD_1X_TAP:
    tap_code16(KC_MNXT);
    break;
  case TD_2X_TAP:
    tap_code16(KC_MPRV);
    break;
  default:
    break;
  }
}

// cleanup state
void td_media_reset(tap_dance_state_t *state, void *user_data) {
  media_tap_state.state = TD_NONE;
}

void tap_pair(uint16_t keycode, uint8_t times) {
  for (uint8_t i = 0; i < times * 2; ++i) {
    tap_code16(keycode);
  }
  for (uint8_t i = 0; i < times; ++i) {
    tap_code16(KC_LEFT);
  }
}

// Functions that control what our tap dance key does
void td_grv_pairs_finished(tap_dance_state_t *state, void *user_data) {
  media_tap_state.state = cur_dance(state);
  switch (media_tap_state.state) {
  case TD_1X_TAP:
    tap_code16(KC_GRV);
    break;
  case TD_2X_TAP:
    tap_pair(KC_GRV, 1);
    break;
  case TD_3X_TAP:
    tap_pair(KC_GRV, 3);
    break;
  case TD_4X_TAP:
    tap_pair(KC_GRV, 4);
    break;
  default:
    break;
  }
}

// cleanup state
void td_grv_pairs_reset(tap_dance_state_t *state, void *user_data) {
  grv_pair_tap_state.state = TD_NONE;
}

void dance_mod_layer_finished(tap_dance_state_t *state, td_tap_t *td_state,
                              uint8_t layer, uint16_t mod) {
  td_state->state = cur_dance(state);
  switch (td_state->state) {
  case TD_1X_TAP: // single tap sets oneshot layer to RAISE
    set_oneshot_layer(layer, ONESHOT_START);
    clear_oneshot_layer_state(ONESHOT_PRESSED);
    break;
  case TD_1X_HOLD: // Single hold for alt key
    register_code(mod);
    break;
  case TD_2X_TAP: // Single hold for alt key
    set_oneshot_layer(layer, ONESHOT_START);
    set_oneshot_layer(layer, ONESHOT_PRESSED);
    break;
  case TD_2X_HOLD: // Single hold for alt key
    register_code(mod);
    layer_on(layer);
    break;
  default:
    break;
  }
}

void dance_mod_layer_reset(tap_dance_state_t *state, td_tap_t *td_state,
                           uint8_t layer, uint16_t mod) {
  td_state->state = TD_NONE;
  switch (td_state->state) {
  case TD_1X_TAP:
    break;
  case TD_1X_HOLD:
    unregister_code(mod);
    break;
  case TD_2X_TAP:
    break;
  case TD_2X_HOLD:
    layer_off(layer);
    unregister_code(mod);
    break;
  default:
    break;
  }
}

void td_alt_raise_finished(tap_dance_state_t *state, void *user_data) {
  dance_mod_layer_finished(state, &alt_mod_tap_state, _RAISE, KC_LALT);
}
void td_alt_raise_reset(tap_dance_state_t *state, void *user_data) {
  dance_mod_layer_reset(state, &alt_mod_tap_state, _RAISE, KC_LALT);
}

void td_gui_raise_finished(tap_dance_state_t *state, void *user_data) {
  dance_mod_layer_finished(state, &gui_mod_tap_state, _RAISE, KC_LGUI);
}
void td_gui_raise_reset(tap_dance_state_t *state, void *user_data) {
  dance_mod_layer_reset(state, &gui_mod_tap_state, _RAISE, KC_LGUI);
}

// Register tap dance actios to qmk
tap_dance_action_t tap_dance_actions[] = {
    [TD_MEDIA_NEXT_PREV] =
        ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_media_finished, td_media_reset),

    [TD_GRV_PAIRS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_grv_pairs_finished,
                                                  td_grv_pairs_reset),

    [TD_ALT_RAISE_LAYER] = ACTION_TAP_DANCE_FN_ADVANCED(
        NULL, td_alt_raise_finished, td_alt_raise_reset),
};
