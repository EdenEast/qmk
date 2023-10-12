#pragma once

#include QMK_KEYBOARD_H

#include "os_detection.h"

bool is_macos(void);
bool is_linux(void);
bool is_windows(void);

bool process_os_toggle(uint16_t keycode, keyrecord_t *record);
