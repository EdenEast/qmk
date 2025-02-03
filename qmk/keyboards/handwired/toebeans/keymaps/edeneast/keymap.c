// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum keymap_keycodes {
  TG_SETT = NEW_SAFE_RANGE, // Toggle settings
  DB_CLCK,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┐
     * │ 1 │ 2 │ 3 │
     * └───┴───┴───┘
     */
    [0] = LAYOUT(
        KC_P1,   DB_CLCK,   QK_BOOT
    )
};
// clang-format on

uint16_t rand_range(uint16_t min, uint16_t max) {
  uint16_t diff = max - min;
  return (uint16_t)(((double)(diff + 1) / RAND_MAX) * rand() + min);
}

static bool     execute_double_click = false;
static bool     has_clicked          = false;
static uint16_t click_timer          = 0;
static uint16_t delay                = 0;

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DB_CLCK:
      if (record->event.pressed) {
        register_code16(MS_BTN1);
        has_clicked          = true;
        execute_double_click = true;
        click_timer          = timer_read();
        delay                = 0;
      } else {
        execute_double_click = false;
        if (has_clicked) {
          unregister_code16(MS_BTN1);
          has_clicked = false;
          delay       = 0;
        }
      }
      return false;

    default:
      return true;
  }
}

void matrix_scan_keymap(void) {
  if (execute_double_click) {
    if (!has_clicked) {
      if (delay == 0) delay = rand_range(150, 250);

      if (timer_elapsed(click_timer) >= delay) {
        register_code16(MS_BTN1);
        has_clicked = true;
        click_timer = timer_read();
        delay       = 0;
      }
    } else {
      if (delay == 0) delay = rand_range(110, 130);

      if (timer_elapsed(click_timer) >= delay) {
        unregister_code16(MS_BTN1);
        has_clicked = false;
        click_timer = timer_read();
        delay       = 0;
      }
    }
  }
}

void keyboard_post_init_keymap(void) {
  // Seed random number genreator
  srand(timer_read32());
}
