// Home row mod settings
#undef TAPPING_TERM
#define TAPPING_TERM 180
#define TAPPING_TERM_PER_KEY

// Prevent normal rollover from triggering mods
/* #define IGNORE_MOD_TAP_INTERRUPT */

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0

// This prevents short hold periods to be interpreted as individual taps when
// typing quickly.
#define PERMISSIVE_HOLD

// The setting below defines how many times you need to tap a TT() to toggle
// the layer.
#define TAPPING_TOGGLE 3

// Limits the max. amount of layers to 8 to save firmware memory. Will not sure
// more then 8.
#define LAYER_STATE_8BIT

// Recommended for heavy chording.
#define QMK_KEYS_PER_SCAN 4

#ifdef COMBO_ENABLE
// ms to register a combo
#undef COMBO_TERM
#define COMBO_TERM 20
// #define COMBO_COUNT 10
#endif

// Enable make compile command
#define ENABLE_COMPILE_KEYCODE
