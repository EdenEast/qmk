#include "combos.h"

// #ifndef NO_USER_COMBOS
// #  define COMBOS_DEF "combos_user.inc"
// #endif
//
// // clang-format off
// #define C_ENUM(name, val, ...) name,
// #define C_DATA(name, val, ...) uint16_t const name##_combo[] PROGMEM = {__VA_ARGS__, COMBO_END};
// #define C_TYPE(name, val, ...) [name] = COMBO(name##_combo, val),
// #define A_TYPE(name, val, ...) [name] = COMBO_ACTION(name##_combo),
// #define P_SSTR(name, val, ...) case name: if (pressed) { SEND_STRING(val); } break;
// #define P_FNCT(name, val, ...) case name: if (pressed) { val; } break;
// #define UNUSED(...)
// // clang-format on
//
// #define COMB C_ENUM
// #define SSTR C_ENUM
// #define FNCT C_ENUM
// #define ADVC C_ENUM
// enum combos {
// #ifdef COMBOS_DEF
// #  include COMBOS_DEF
// #endif
// #ifdef COMBOS_KEYMAP
// #  include COMBOS_KEYMAP
// #endif
// };
//
// #undef COMB
// #undef SSTR
// #undef FNCT
// #undef ADVC
// #define COMB C_DATA
// #define SSTR C_DATA
// #define FNCT C_DATA
// #define ADVC C_DATA
// #ifdef COMBOS_DEF
// #  include COMBOS_DEF
// #endif
// #ifdef COMBOS_KEYMAP
// #  include COMBOS_KEYMAP
// #endif

#undef COMB
#undef SSTR
#undef FNCT
#undef ADVC
#define COMB C_TYPE
#define SSTR A_TYPE
#define FNCT A_TYPE
#define ADVC A_TYPE
combo_t key_combos[] = {
#ifdef COMBOS_DEF
#  include COMBOS_DEF
#endif
#ifdef COMBOS_KEYMAP
#  include COMBOS_KEYMAP
#endif
};

#undef COMB
#undef SSTR
#undef FNCT
#undef ADVC
#define COMB UNUSED
#define SSTR P_SSTR
#define FNCT P_ACTN
#define ADVC UNUSED
void process_combo_event(uint16_t combo_index, bool pressed) {
#ifdef COMBO_CUSTOM_KEYMAP
  if (!process_combo_event_keymap(combo_index, pressed)) {
    return;
  }
#endif
#ifdef COMBO_CUSTOM_USER
  if (!process_combo_event_user(combo_index, pressed)) {
    return;
  }
#endif

  switch (combo_index) {
#ifdef COMBOS_DEF
#  include COMBOS_DEF
#endif
#ifdef COMBOS_KEYMAP
#  include COMBOS_KEYMAP
#endif
  }
}

#undef COMB
#undef SSTR
#undef FNCT
#undef ADVC
