#include "dances.h"
#include "edeneast.h"

// Initialize tap structure associated with example tap dance key
static td_tap_t media_tap_state = {.is_press_action = true, .state = TD_NONE};

td_state_t cur_dance(tap_dance_state_t *state) {
  switch (state->count) {
  case 1:
    if (!state->pressed)
      return TD_1X_TAP;
    else
      return TD_1X_HOLD;
  case 2:
    return TD_2X_TAP;
    break;
  case 3:
    return TD_3X_TAP;
    break;
  case 4:
    return TD_4X_TAP;
    break;
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

// Register tap dance actios to qmk
tap_dance_action_t tap_dance_actions[] = {
    [TD_MEDIA_NEXT_PREV] =
        ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_media_finished, td_media_reset),
};
