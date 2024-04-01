#include "os_detect.h"

os_variant_t os_type;

bool is_macos(void) {
  return os_type == OS_MACOS;
}

bool is_windows(void) {
  return os_type == OS_WINDOWS || os_type == OS_UNSURE;
}

bool is_linux(void) {
  return os_type == OS_LINUX;
}

void set_os(os_variant_t os) {
  os_type = os;
}

uint32_t os_detect_startup(uint32_t trigger_time, void *cb_arg) {
  os_type = detected_host_os();
  switch (os_type) {
    case OS_LINUX:
      xprintf("Linux Detected\n");
      break;
    case OS_WINDOWS:
      xprintf("Windows Detected\n");
      break;
    case OS_MACOS:
      xprintf("Macos Detected\n");
      break;
    default:
      xprintf("Unknown OS Detected\n");
      break;
  }

  return os_type ? 0 : 500;
}

bool process_os_toggle(uint16_t keycode, keyrecord_t *record) {
  os_variant_t variant;
  switch (keycode) {
    case OS_RST:
      variant = detected_host_os();
      if (variant != OS_UNSURE) {
        os_type = variant;
      }
      return false;
    case OS_WIN:
      os_type = OS_WINDOWS;
      return false;
    case OS_MAC:
      os_type = OS_MACOS;
      return false;
    case OS_LNX:
      os_type = OS_LINUX;
      return false;
  }
  return true;
}
