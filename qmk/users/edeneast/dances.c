#include "dances.h"
#include "edeneast.h"

__attribute__((weak)) td_state_t dance_state(tap_dance_state_t *state) {
  if (state->count == 1) {
    return (state->interrupted || !state->pressed) ? TD_SINGLE_TAP
                                                   : TD_SINGLE_HOLD;
  }
  if (state->count == 2) {
    // TD_DOUBLE_SINGLE_TAP is used to distinguish between typing something like
    // 'pepper', and actually wanting a tap dance double tap action when hitting
    // 'pp'.
    if (state->interrupted)
      return TD_DOUBLE_SINGLE_TAP;
    else if (state->pressed)
      return TD_DOUBLE_HOLD;
    else
      return TD_DOUBLE_TAP;
  }
  if (state->count == 3) {
    return (state->interrupted || !state->pressed) ? TD_TRIPLE_TAP
                                                   : TD_TRIPLE_HOLD;
  }
  if (state->count == 4) {
    return (state->interrupted || !state->pressed) ? TD_QUAD_TAP : TD_QUAD_HOLD;
  }

  return TD_UNKNOWN;
}

// Single tap for next track and double tap for prev track
void td_media_next_prev(tap_dance_state_t *state, void *user_data) {
  switch (dance_state(state)) {
  case TD_SINGLE_TAP:
    tap_code16(KC_MNXT);
    break;
  case TD_DOUBLE_SINGLE_TAP:
  case TD_DOUBLE_TAP:
    tap_code16(KC_MPRV);
    break;
  default:
    break;
  }
}

// ------------------------------------------------------------------------------------------------

void tap_pair(uint16_t keycode, uint8_t times) {
  for (uint8_t i = 0; i < times * 2; ++i) {
    tap_code16(keycode);
  }
  for (uint8_t i = 0; i < times; ++i) {
    tap_code16(KC_LEFT);
  }
}

// Functions that control what our tap dance key does
void td_grv_pairs(tap_dance_state_t *state, void *user_data) {
  switch (dance_state(state)) {
  case TD_SINGLE_TAP:
    tap_code16(KC_GRV);
    break;
  case TD_DOUBLE_SINGLE_TAP:
  case TD_DOUBLE_TAP:
    tap_pair(KC_GRV, 1);
    break;
  case TD_TRIPLE_TAP:
    tap_pair(KC_GRV, 3);
    break;
  case TD_QUAD_TAP:
    tap_pair(KC_GRV, 4);
    break;
  default:
    break;
  }
}

// Register tap dance actios to qmk
tap_dance_action_t tap_dance_actions[] = {
    [TD_MEDIA_NEXT_PREV] = ACTION_TAP_DANCE_FN(td_media_next_prev),
    [TD_GRV_PAIRS] = ACTION_TAP_DANCE_FN(td_grv_pairs),
};
