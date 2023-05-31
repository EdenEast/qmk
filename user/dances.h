#pragma once
#include QMK_KEYBOARD_H

/**
 * TAP DANCE
 * https://docs.qmk.fm/#/feature_tap_dance
 */

// Custon tap dance keys
enum dances {
  TD_MEDIA_NEXT_PREV = 0,
};

#define TD_MDNP TD(TD_MEDIA_NEXT_PREV)

// Define a type for as many tap dance states as you need
typedef enum {
  TD_NONE = 0,
  TD_UNKNOWN,
  TD_1X_TAP,
  TD_1X_HOLD,
  TD_2X_TAP,
  TD_3X_TAP,
  TD_4X_TAP,
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
