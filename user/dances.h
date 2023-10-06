#pragma once
#include QMK_KEYBOARD_H

/**
 * TAP DANCE
 * https://docs.qmk.fm/#/feature_tap_dance
 */

// Custon tap dance keys
enum dances {
  TD_MEDIA_NEXT_PREV = 0,
  TD_GRV_PAIRS,
  TD_ALT_RAISE_LAYER,
  TD_GUI_RAISE_LAYER,
};

#define TD_MDNP TD(TD_MEDIA_NEXT_PREV)
#define TD_GRV TD(TD_GRV_PAIRS)
#define TD_LALT TD(TD_ALT_RAISE_LAYER)
#define TD_LGUI TD(TD_GUI_RAISE_LAYER)

// Define a type for as many tap dance states as you need
typedef enum {
  TD_NONE = 0,
  TD_UNKNOWN,
  TD_1X_TAP,
  TD_1X_HOLD,
  TD_2X_TAP,
  TD_2X_HOLD,
  TD_3X_TAP,
  TD_3X_HOLD,
  TD_4X_TAP,
  TD_4X_HOLD,
} td_state_t;

// Define an instance sturcture for a single tap dance state
typedef struct {
  bool is_press_action;
  td_state_t state;
} td_tap_t;

/**
 * @brief Determine the current tap dance state
 * @param A tap dance state struct.
 * @return A struct.
 */
td_state_t cur_dance(tap_dance_state_t *state);
