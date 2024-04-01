#pragma once

#include QMK_KEYBOARD_H
#include "os_detection.h"

bool is_macos(void);
bool is_windows(void);
bool is_linux(void);

void reset_os(void);
void set_os(os_variant_t os_type);
void set_os_win(void);
void set_os_macos(void);
void set_os_linux(void);

uint32_t os_detect_startup(uint32_t trigger_time, void *cb_arg);
bool     process_os_toggle(uint16_t keycode, keyrecord_t *record);
