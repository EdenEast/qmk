#include "edeneast.h"

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case A_SFT:
  case O_SFT:
    return TAPPING_TERM + 200;
  default:
    return TAPPING_TERM;
  }
}
