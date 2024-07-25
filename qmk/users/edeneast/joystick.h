#pragma once

#include "quantum.h"

// Joystick Button Count
#ifndef JOYSTICK_BUTTON_COUNT
#  define JOYSTICK_BUTTON_COUNT 17
#endif

// Joystick Axes Count
#ifndef JOYSTICK_AXIS_COUNT
#  define JOYSTICK_AXIS_COUNT 2
#endif

// Joystick Axes Resolution
#ifndef JOYSTICK_AXIS_RESOLUTION
#  define JOYSTICK_AXIS_RESOLUTION 8
#endif

#define JOYSTICK_KEYCODE_DEFINITIONS(...) _JOYSTICK_KEYCODE_DEFINITIONS(__VA_ARGS__)
// clang-format off
#define _JOYSTICK_KEYCODE_DEFINITIONS( \
  JS_UP, JS_DN, JS_LF, JS_RT, \
  DP_UP, DP_DN, DP_LF, DP_RT, \
  JS_BTU, JS_BTD, JS_BTL, JS_BTR, \
  JS_L1, JS_L2, JS_L3, JS_R1, JS_R2, JS_R3, \
  JS_SEL, JS_STRT, JS_HOM \
)

typedef enum {
  // Off (L + R = L + R)
  SODC_OFF,

  // Neutral (L + R = N, U + D = U)
  SODC_NEUTRAL,

  // Last Input Priority (L + R = R)
  SODC_LIP,
} socd_mode_t;

void reset_socd_mode(void);
void set_socd_mode(socd_mode_t mode);

/**
 * Handler function for joystick.
 */
bool process_joystick(uint16_t keycode, keyrecord_t* record);
