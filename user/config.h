// Home row mod settings
#undef TAPPING_TERM
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

// Prevent normal rollover from triggering mods
#define IGNORE_MOD_TAP_INTERRUPT

// This prevents accidental repeats of the tap-hold keys when typing quickly.
#define TAPPING_FORCE_HOLD

// This prevents short hold periods to be interpreted as individual taps when
// typing quickly.
#define PERMISSIVE_HOLD

// The setting below defines how many times you need to tap a TT() to toggle the
// layer.
#define TAPPING_TOGGLE 3

// Limits the max. amount of layers to 8 to save firmware memory. Will not sure
// more then 8. #define LAYER_STATE_8BIT

// Recommended for heavy chording.
#define QMK_KEYS_PER_SCAN 4

// NKRO_ENABLE only enables the ability this forces NKRO
#define FORCE_NKRO

// Number of combos
#define COMBO_COUNT 30

// ms to register a combo
#define COMBO_TERM 20
