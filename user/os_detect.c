#include QMK_KEYBOARD_H

#include "process_records.h"
#include "os_detect.h"

static os_variant_t os_variant = OS_UNSURE;
static uint8_t detect_try_count = 0;

void print_variant(os_variant_t os) {
  switch (os) {
  case OS_UNSURE:
    xprintf("unknown OS Detected\n");
    break;
  case OS_LINUX:
    xprintf("Linux Detected\n");
    break;
  case OS_WINDOWS:
    xprintf("Windows Detected\n");
    break;
  case OS_MACOS:
    xprintf("MacOS Detected\n");
    break;
    case OS_IOS:
        xprintf("iOS Detected\n");
        break;
  }
}

bool is_macos(void) { return  os_variant == OS_MACOS; }
bool is_linux(void) { return os_variant == OS_LINUX; }
bool is_windows(void) { return os_variant == OS_WINDOWS; }

void try_detect_os(void) {
  if (os_variant != OS_UNSURE)
    return;

  if (detect_try_count > 10) {
    os_variant = OS_WINDOWS;
    return;
  }
  os_variant = detected_host_os();
  detect_try_count++;
}

void startup_os_detect(void) {
 os_variant = detected_host_os();

  switch (os_variant) {
  case OS_UNSURE:
    xprintf("unknown OS Detected\n");
    break;
  case OS_LINUX:
    xprintf("Linux Detected\n");
    break;
  case OS_WINDOWS:
    xprintf("Windows Detected\n");
    break;
  case OS_MACOS:
    xprintf("MacOS Detected\n");
    break;
    case OS_IOS:
        xprintf("iOS Detected\n");
        break;
  }
}

uint32_t startup_exec(uint32_t trigger_time, void *cb_arg) {
    startup_os_detect();
    return 0;
}

void keyboard_post_init_user(void) {
    defer_exec(1500, startup_exec, NULL);
}

bool process_os_toggle(uint16_t keycode, keyrecord_t *record) {
  try_detect_os();

  switch (keycode) {
        case DB_OS:
            print_variant(detected_host_os());
        return false;
}
  return true;
}
