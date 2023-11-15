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
};

#define TD_MDNP TD(TD_MEDIA_NEXT_PREV)
#define TD_GRV TD(TD_GRV_PAIRS)

// Define a type for as many tap dance states as you need
typedef enum {
  TD_NONE = 0,
  TD_UNKNOWN,
  TD_SINGLE_TAP,
  TD_SINGLE_HOLD,
  TD_DOUBLE_TAP,
  TD_DOUBLE_HOLD,
  TD_DOUBLE_SINGLE_TAP,  // Send two single taps
  TD_TRIPLE_TAP,
  TD_TRIPLE_HOLD,
  TD_QUAD_TAP,
  TD_QUAD_HOLD,
} td_state_t;

/**
 * @brief Determine the current tap dance state
 * @param A tap dance state struct.
 * @return A struct.
 */
td_state_t dance_state(tap_dance_state_t *state);
