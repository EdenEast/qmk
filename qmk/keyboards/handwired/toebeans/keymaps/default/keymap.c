// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┐
     * │ 1 │ 2 │ 3 │
     * └───┴───┴───┘
     */
    [0] = LAYOUT(
        KC_P1,   KC_A,   QK_BOOT
    )
};
// clang-format on
