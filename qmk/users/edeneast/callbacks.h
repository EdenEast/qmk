#pragma once
#include QMK_KEYBOARD_H

void keyboard_pre_init_keymap(void);
void keyboard_post_init_keymap(void);

void matrix_scan_keymap(void);

void          eeconfig_init_keymap(void);
layer_state_t layer_state_set_keymap(layer_state_t state);
