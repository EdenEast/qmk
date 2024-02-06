#include QMK_KEYBOARD_H

#include "os_detect.h"

static os_variant_t os_variant       = OS_UNSURE;
static uint8_t      detect_try_count = 0;

bool is_macos(void) {
  return os_variant == OS_MACOS;
}
bool is_linux(void) {
  return os_variant == OS_LINUX;
}
bool is_windows(void) {
  return os_variant == OS_WINDOWS;
}

void try_detect_os(void) {
  if (os_variant != OS_UNSURE) return;

  if (detect_try_count > 10) {
    os_variant = OS_WINDOWS;
    return;
  }
  os_variant = detected_host_os();
  detect_try_count++;
}

bool process_os_toggle(uint16_t keycode, keyrecord_t *record) {
  try_detect_os();
  return true;
}
