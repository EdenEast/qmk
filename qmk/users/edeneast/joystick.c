#include QMK_KEYBOARD_H
#include "joystick.h"

// https://github.com/kh411d/qmk_hitbox_keymaps/blob/master/reviung41/keymaps/hitbox/keymap.c
// https://github.com/brentaro/QMK_SOCD_Cleaner/blob/main/README.md
// https://github.com/brentaro/QMK_HID_Gamepad_with_SOCD/blob/main/sample/keymap.c

// Input Map
// UP:    button 12 | LS Axis (1, -127)
// DOWN:  button 13 | LS Axis (1, 127)
// LEFT:  button 14 | LS Axis (0, -127)
// RIGHT: button 15 | LS Axis (0, 127)
//
// Button Down:  button 0
// Button Right: button 1
// Button Left:  button 2
// Button Up:    button 3
//
// Select:   button 8
// Start:    button 8
//
// L1: button 4 | L2: button 6 | L3: button 10
// R1: button 5 | R2: button 7 | R3: button 11

// left stick axis 0,1  |  right stick axis 2,3
joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    JOYSTICK_AXIS_VIRTUAL, // x
    JOYSTICK_AXIS_VIRTUAL, // y
};

static socd_mode_t socd_mode = SODC_NEUTRAL;

void reset_socd_mode() {
  socd_mode = SODC_NEUTRAL;
}
void set_socd_mode(socd_mode_t mode) {
  socd_mode = mode;
}

bool process_joystick(uint16_t keycode, keyrecord_t* record) {
  return true;
}
