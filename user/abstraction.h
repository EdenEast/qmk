// keycode abstraction
// ABC:
//  A: L  = left
//     R  = right
//  B: U  = upper row
//     M  = middle row
//     L  = lower row
//  C: PP = outer pinkey finger
//     P  = pinky finger
//     R  = ring finger
//     M  = middle finger
//     I  = index finger
//     II = inner index finger

// Keymap layout for colemak
// clang-format off
#define LUP  KC_Q
#define LUR  KC_W
#define LUM  KC_F
#define LUI  KC_P
#define LUII KC_B

#define LMP  KC_A
#define LMR  KC_R
#define LMM  KC_S
#define LMI  KC_T
#define LMII KC_G

#define LLP  ALT_Z // KC_Z
#define LLR  GUI_X // KC_X
#define LLM  KC_C
#define LLI  KC_D
#define LLII KC_V

// -----------------------------------------------------------------------------

#define RUP  KC_SCLN
#define RUR  KC_Y
#define RUM  KC_U
#define RUI  KC_L
#define RUII KC_J

#define RMP  KC_O
#define RMR  KC_I
#define RMM  KC_E
#define RMI  KC_N
#define RMII KC_M

#define RLP  ALT_SLH // KC_SLSH
#define RLR  GUI_DOT // KC_DOT
#define RLM  KC_COMM
#define RLI  KC_H
#define RLII KC_K
