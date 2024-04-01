#include "callbacks.h"
#include "os_detect.h"

#ifdef ACHORDION_ENABLE
#  include "features/achordion.h"
#endif

__attribute__((weak)) void keyboard_pre_init_keymap(void) {}
void                       keyboard_pre_init_user(void) {
#ifdef CONSOLE_ENABLE
  // Used to help debug using qmk's console.
  debug_enable = true;
#endif

  keyboard_pre_init_keymap();
}

__attribute__((weak)) void keyboard_post_init_keymap(void) {}
void                       keyboard_post_init_user(void) {
#ifdef DEFERRED_EXEC_ENABLE
  defer_exec(100, os_detect_startup, NULL);
#endif

  keyboard_post_init_keymap();
}

__attribute__((weak)) void matrix_scan_keymap(void) {}
void                       matrix_scan_user(void) {
  matrix_scan_keymap();
#ifdef ACHORDION_ENABLE
  achordion_task();
#endif
}
