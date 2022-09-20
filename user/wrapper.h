#pragma once
#include "edeneast.h"
#include "keymap_steno.h"

// Taken from users/drashna
#if (!defined(LAYOUT) && defined(KEYMAP))
#define LAYOUT KEYMAP
#endif

#define LAYOUT_5x6_WRAPPER(...)         LAYOUT_5x6(__VA_ARGS__)
#define LAYOUT_split_3x6_3_WRAPPER(...) LAYOUT_split_3x6_3(__VA_ARGS__)
#define KEYMAP_wrapper(...)             LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...)             LAYOUT(__VA_ARGS__)

#define ______________NUMBER_LEFT______________         KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5
#define ______________NUMBER_RIGHT_____________         KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0
#define _______________________________________         _______,_______,_______,_______,_______
#define _______________________________________________ _______,_______,_______,_______,_______,_______
//                             |

// Alpha:
// ╭───────┬───────┬───────┬───────┬───────┬───────╮  ╭───────┬───────┬───────┬───────┬───────┬───────╮
// │  Tab  │ Q/Gui │   W   │   F   │   P   │   B   │  │   J   │   L   │   U   │   Y   │ ;/Gui │   =   │
// ├───────┼───────┼───────┼───────┼───────┼───────┤  ├───────┼───────┼───────┼───────┼───────┼───────┤
// │Esc/Ctl│   A   │   R   │   S   │   T   │   G   │  │   M   │   N   │   E   │   I   │   O   │ '/Ctl │
// ├───────┼───────┼───────┼───────┼───────┼───────┤  ├───────┼───────┼───────┼───────┼───────┼───────┤
// │Tmx/Sft│ Z/Alt │   X   │   C   │   D   │   V   │  │   K   │   H   │   ,   │   .   │[/]/Alt│Ent/Sft│
// ╰───────┴───────┴───────┴───────┴───────┴───────╯  ╰───────┴───────┴───────┴───────┴───────┴───────╯
#define _________________COLEMAK_DH_L1_________________ KC_TAB ,GUI_Q  ,KC_W   ,KC_F   ,KC_P   ,KC_B
#define _________________COLEMAK_DH_L2_________________ CTL_ESC,KC_A   ,KC_R   ,KC_S   ,KC_T   ,KC_G
#define _________________COLEMAK_DH_L3_________________ TD_TMUX,ALT_Z  ,KC_X   ,KC_C   ,KC_D   ,KC_V

#define _________________COLEMAK_DH_R1_________________ KC_J   ,KC_L   ,KC_U   ,KC_Y   ,GUI_SCN,KC_EQL
#define _________________COLEMAK_DH_R2_________________ KC_M   ,KC_N   ,KC_E   ,KC_I   ,KC_O   ,CTL_QOT
#define _________________COLEMAK_DH_R3_________________ KC_K   ,KC_H   ,KC_COMM,KC_DOT ,ALT_SLH,SFT_ENT

// Symbols:
//   - ^ and $ are placed at beinging and end of layer just like regex meanings
//   - ( and ) result in < and > when shifted.
//   - All brackets are accessable from up index and middle with shifts
//   - 0 and 1 are placed on home keys as they are the most used
//     - Symbols are also accessable though shifts
//     - ! is accessed by shift right home index
//     - = / - _ ' " are omitted as they are accessable from alpha layer
//     - -> and != are for programming shortcuts
// ╭───────┬───────┬───────┬───────┬───────┬───────╮  ╭───────┬───────┬───────┬───────┬───────┬───────╮
// │       │       │   ->  │   [   │   ]   │   |   │  │   \   │ ( [<] │ ) [>] │   !=  │       │       │
// ├───────┼───────┼───────┼───────┼───────┼───────┤  ├───────┼───────┼───────┼───────┼───────┼───────┤
// │       │   ^   │   @   │   #   │   0   │   *   │  │   +   │   1   │   `   │   ~   │   $   │       │
// ├───────┼───────┼───────┼───────┼───────┼───────┤  ├───────┼───────┼───────┼───────┼───────┼───────┤
// │       │   6   │   7   │   8   │   9   │   %   │  │   &   │   2   │   3   │   4   │   5   │       │
// ╰───────┴───────┴───────┴───────┴───────┴───────╯  ╰───────┴───────┴───────┴───────┴───────┴───────╯
#define ____________________SYMB_L1____________________ _______,_______,KC_AROW,KC_LBRC,KC_RBRC,KC_PIPE
#define ____________________SYMB_L2____________________ _______,KC_CIRC,KC_AT  ,KC_HASH,KC_0   ,KC_ASTR
#define ____________________SYMB_L3____________________ _______,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_PERC

#define ____________________SYMB_R1____________________ KC_BSLS,KC_LPLT,KC_RPGT,KC_NEQL,_______,_______
#define ____________________SYMB_R2____________________ KC_PLUS,KC_1   ,KC_GRV ,KC_TILD,KC_DLR ,_______
#define ____________________SYMB_R3____________________ KC_AMPR,KC_2   ,KC_3   ,KC_4   ,KC_5   ,_______

// Navigation:
//   - Modifier keys added on the left hand to make moving windows in most floating window managers
//   - Dedicated browser back and forward as this is different on different OS
// ╭───────┬───────┬───────┬───────┬───────┬───────╮  ╭───────┬───────┬───────┬───────┬───────┬───────╮
// │       │       │       │       │       │       │  │  Home │ Page+ │ Page- │  End  │       │       │
// ├───────┼───────┼───────┼───────┼───────┼───────┤  ├───────┼───────┼───────┼───────┼───────┼───────┤
// │       │ Super │  Alt  │ Shift │  Ctrl │       │  │   ←   │   ↓   │   ↑   │   →   │       │       │
// ├───────┼───────┼───────┼───────┼───────┼───────┤  ├───────┼───────┼───────┼───────┼───────┼───────┤
// │       │       │       │       │       │       │  │BwsrBak│  Prev │  Play │  Next │BwsrFwd│       │
// ╰───────┴───────┴───────┴───────┴───────┴───────╯  ╰───────┴───────┴───────┴───────┴───────┴───────╯
#define ____________________NAVI_L1____________________ _______,_______,_______,_______,_______,_______
#define ____________________NAVI_L2____________________ _______,KC_LGUI,KC_LALT,KC_LSFT,KC_LCTL,_______
#define ____________________NAVI_L3____________________ _______,_______,_______,_______,_______,_______

#define ____________________NAVI_R1____________________ KC_HOME,KC_PGUP,KC_PGDN,KC_END ,_______,_______
#define ____________________NAVI_R2____________________ KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,_______,_______
#define ____________________NAVI_R3____________________ KC_WBAK,KC_MPRV,KC_MPLY,KC_MNXT,KC_WFWD,_______

// Adjust:
//   - Layer is entered by activating nav and sym (tri layer activation)
// ╭───────┬───────┬───────┬───────┬───────┬───────╮  ╭───────┬───────┬───────┬───────┬───────┬───────╮
// │  F11  │ F1/Gui│   F2  │   F3  │   F4  │   F5  │  │   F6  │   F7  │   F8  │   F9  │F10/Gui│  F12  │
// ├───────┼───────┼───────┼───────┼───────┼───────┤  ├───────┼───────┼───────┼───────┼───────┼───────┤
// │       │       │       │       │       │       │  │Bright+│  Vol+ │  Mic  │       │       │       │
// ├───────┼───────┼───────┼───────┼───────┼───────┤  ├───────┼───────┼───────┼───────┼───────┼───────┤
// │ Reset │       │       │       │ STENO │  Game │  │Bright-│  Vol- │  Mute │       │       │ Reset │
// ╰───────┴───────┴───────┴───────┴───────┴───────╯  ╰───────┴───────┴───────┴───────┴───────┴───────╯
#define _____________________ADJ_L1____________________ KC_F11 ,GUI_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5
#define _____________________ADJ_L2____________________ _______,_______,_______,_______,_______,_______
#define _____________________ADJ_L3____________________ RESET  ,_______,_______,_______,ENB_STN,ENB_GME

#define _____________________ADJ_R1____________________ KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,GUI_F10 ,KC_F11
#define _____________________ADJ_R2____________________ KC_BRIU,KC_VOLU,TG_MIC ,_______,_______,_______
#define _____________________ADJ_R3____________________ KC_BRID,KC_VOLD,KC_MUTE,_______,_______,RESET

// Steno:
// ╭───────┬───────┬───────┬───────┬───────┬───────╮  ╭───────┬───────┬───────┬───────┬───────┬───────╮
// │   #   │   #   │   #   │   #   │   #   │   #   │  │   #   │   #   │   #   │   #   │   #   │   #   │
// ├───────┼───────┼───────┼───────┼───────┼───────┤  ├───────┼───────┼───────┼───────┼───────┼───────┤
// │       │   S   │   T   │   P   │   H   │   *   │  │   *   │   F   │   P   │   L   │   T   │   D   │
// ├───────┼───────┼───────┼───────┼───────┼───────┤  ├───────┼───────┼───────┼───────┼───────┼───────┤
// │  Exit │   S   │   K   │   W   │   R   │   *   │  │   *   │   R   │   B   │   G   │   S   │   Z   │
// ╰───────┴───────┴───────┴───────┴───────┴───────╯  ╰───────┴───────┴───────┴───────┴───────┴───────╯
#define ____________________STENO_L1___________________ STN_N1 ,STN_N2 ,STN_N3 ,STN_N4 ,STN_N5 ,STN_N6
#define ____________________STENO_L2___________________ STN_FN ,STN_S1 ,STN_TL ,STN_PL ,STN_HL ,STN_ST1
#define ____________________STENO_L3___________________ EXT_STN,STN_S2 ,STN_KL ,STN_WL ,STN_RL ,STN_ST2

#define ____________________STENO_R1___________________ STN_N7 ,STN_N8 ,STN_N9 ,STN_NA ,STN_NB ,STN_NC
#define ____________________STENO_R2___________________ STN_ST3,STN_FR ,STN_PR ,STN_LR ,STN_TR ,STN_DR
#define ____________________STENO_R3___________________ STN_ST4,STN_RR ,STN_BR ,STN_GR ,STN_SR ,STN_ZR

// Game:
// ╭───────┬───────┬───────┬───────┬───────┬───────╮  ╭───────┬───────┬───────┬───────┬───────┬───────╮
// │   `   │  Tab  │   Q   │   W   │   E   │   R   │  │   T   │   Y   │   U   │   I   │   O   │   P   │
// ├───────┼───────┼───────┼───────┼───────┼───────┤  ├───────┼───────┼───────┼───────┼───────┼───────┤
// │  Esc  │ Shift │   A   │   S   │   D   │   F   │  │   G   │   H   │   J   │   K   │   L   │Colemak│
// ├───────┼───────┼───────┼───────┼───────┼───────┤  ├───────┼───────┼───────┼───────┼───────┼───────┤
// │  Alt  │  Ctrl │   Z   │   X   │   C   │   V   │  │   B   │   N   │   M   │   ,   │   .   │   /   │
// ╰───────┴───────┴───────┴───────┴───────┴───────╯  ╰───────┴───────┴───────┴───────┴───────┴───────╯
#define ____________________GAME_L1____________________ KC_GRV ,KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R
#define ____________________GAME_L2____________________ KC_ESC ,KC_LSFT,KC_A   ,KC_S   ,KC_D   ,KC_F
#define ____________________GAME_L3____________________ KC_LALT,KC_LCTL,KC_Z   ,KC_X   ,KC_C   ,KC_V

#define ____________________GAME_R1____________________ KC_T   ,KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P
#define ____________________GAME_R2____________________ KC_G   ,KC_H   ,KC_J   ,KC_K   ,KC_L   ,EXT_GME
#define ____________________GAME_R3____________________ KC_B   ,KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH

// Alpha:
//   - Thumb keys are defined by priority do first priority seonds and third
//     3       2       1          1       2       3
// ╭───────┬───────┬───────╮  ╭───────┬───────┬───────╮
// │  Nav  │Tab/Sym│BSP/SFT│  │ Space │ -/Nav │  Sym  │
// ╰───────┴───────┴───────╯  ╰───────┴───────┴───────╯
#define TB_DFL1 SFT_BSP
#define TB_DFL2 LT(_SYM, KC_TAB)
#define TB_DFL3 MO(_NAV)

#define TB_DFR1 KC_SPC
#define TB_DFR2 LT(_NAV, KC_MINS)
#define TB_DFR3 MO(_SYM)

// Symbols:
// ╭───────┬───────┬───────╮  ╭───────┬───────┬───────╮
// │       │       │       │  │       │       │       │
// ╰───────┴───────┴───────╯  ╰───────┴───────┴───────╯
#define TB_SYL1 _______
#define TB_SYL2 _______
#define TB_SYL3 _______

#define TB_SYR1 _______
#define TB_SYR2 _______
#define TB_SYR3 _______

// Navigation:
// ╭───────┬───────┬───────╮  ╭───────┬───────┬───────╮
// │       │       │  Bspc │  │       │       │       │
// ╰───────┴───────┴───────╯  ╰───────┴───────┴───────╯
#define TB_NVL1 KC_BSPC
#define TB_NVL2 _______
#define TB_NVL3 _______

#define TB_NVR1 _______
#define TB_NVR2 _______
#define TB_NVR3 _______

// Adjust:
// ╭───────┬───────┬───────╮  ╭───────┬───────┬───────╮
// │       │       │       │  │       │       │       │
// ╰───────┴───────┴───────╯  ╰───────┴───────┴───────╯
#define TB_AJL1 _______
#define TB_AJL2 _______
#define TB_AJL3 _______

#define TB_AJR1 _______
#define TB_AJR2 _______
#define TB_AJR3 _______

// Adjust:
//   - Steno thumbs matter the order in which they are assigned
//   - Maps should keep to the order below
// ╭───────┬───────┬───────╮  ╭───────┬───────┬───────╮
// │       │   A   │   O   │  │   E   │   U   │       │
// ╰───────┴───────┴───────╯  ╰───────┴───────┴───────╯
#define TB_STL1 STN_O
#define TB_STL2 STN_A
#define TB_STL3 _______

#define TB_STR1 STN_E
#define TB_STR2 STN_U
#define TB_STR3 _______

// Game:
//   - TODO: Tapdace one of these keys to move out of gaming layer so only need left side active
// ╭───────┬───────┬───────╮  ╭───────┬───────┬───────╮
// │   M   │   I   │ Space │  │  Bspc │ Enter │  Del  │
// ╰───────┴───────┴───────╯  ╰───────┴───────┴───────╯
#define TB_GML1 KC_SPC
#define TB_GML2 KC_I
#define TB_GML3 KC_M

#define TB_GMR1 KC_BSPC
#define TB_GMR2 KC_ENT
#define TB_GMR3 KC_DEL

// ╭───────┬───────┬───────┬───────┬───────┬───────╮  ╭───────┬───────┬───────┬───────┬───────┬───────╮
// │       │       │       │       │       │       │  │       │       │       │       │       │       │
// ├───────┼───────┼───────┼───────┼───────┼───────┤  ├───────┼───────┼───────┼───────┼───────┼───────┤
// │       │       │       │       │       │       │  │       │       │       │       │       │       │
// ├───────┼───────┼───────┼───────┼───────┼───────┤  ├───────┼───────┼───────┼───────┼───────┼───────┤
// │       │       │       │       │       │       │  │       │       │       │       │       │       │
// ╰───────┴───────┴───────┴───────┴───────┴───────╯  ╰───────┴───────┴───────┴───────┴───────┴───────╯
