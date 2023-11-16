#include "edeneast.h"

#ifdef CONSOLE_ENABLE
void keyboard_post_init_user(void) {
  // Used to help debug using qmk's console.
  debug_enable=true;
}
#endif
