#include "leader.h"
#include "os_detect.h"

__attribute__((weak)) void leader_end_keymap(void) {}
void                       leader_end_user(void) {
  if (leader_sequence_two_keys(KC_O, KC_R)) {
    reset_os();
  }
  if (leader_sequence_two_keys(KC_O, KC_M)) {
    set_os_macos();
  }
  if (leader_sequence_two_keys(KC_O, KC_W)) {
    set_os_win();
  }
  if (leader_sequence_two_keys(KC_O, KC_L)) {
    set_os_linux();
  }
  leader_end_keymap();
}
