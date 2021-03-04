#include "eden.h"
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK_DH] = LAYOUT_split_3x6_3_WRAPPER (
        ________________COLEMAK_DH_L1__________________,                        ________________COLEMAK_DH_R1__________________,
        ________________COLEMAK_DH_L2__________________,                        ________________COLEMAK_DH_R2__________________,
        ________________COLEMAK_DH_L3__________________,                        ________________COLEMAK_DH_R3__________________,
                                        TB_CMLL,TB_CMLL,TB_CMLL,        TB_CMLL,TB_CMLL,TB_CMLL
    ),
    [_QWERTY] = LAYOUT_split_3x6_3_WRAPPER (
        ________________QWERTY_L1______________________,                        ________________QWERTY_R1______________________,
        ________________QWERTY_L2______________________,                        ________________QWERTY_R2______________________,
        ________________QWERTY_L3______________________,                        ________________QWERTY_R3______________________,
                                        _______,_______,_______,        _______,_______,_______
    ),
    [_NUM] = LAYOUT_split_3x6_3_WRAPPER (
        ________________NUM_L1_________________________,                        ________________NUM_R1_________________________,
        ________________NUM_L2_________________________,                        ________________NUM_R2_________________________,
        ________________NUM_L3_________________________,                        ________________NUM_R3_________________________,
                                        TB_NMLL,TB_NMLC,TB_NMLR,        TB_NMRL,TB_NMRC,TB_NMRR
    ),
    [_SYM] = LAYOUT_split_3x6_3_WRAPPER (
        ________________SYM_L1_________________________,                        ________________SYM_R1_________________________,
        ________________SYM_L2_________________________,                        ________________SYM_R2_________________________,
        ________________SYM_L3_________________________,                        ________________SYM_R3_________________________,
                                        TB_SYLL,TB_SYLC,TB_SYLR,        TB_SYRL,TB_SYRC,TB_SYRR
    ),
    [_FN] = LAYOUT_split_3x6_3_WRAPPER (
        ________________FN_L1__________________________,                        ________________FN_R1__________________________,
        ________________FN_L2__________________________,                        ________________FN_R2__________________________,
        ________________FN_L3__________________________,                        ________________FN_R3__________________________,
                                        TB_FNLL,TB_FNLC,TB_FNLR,        TB_FNRL,TB_FNRC,TB_FNRR
    ),
    [_NAV] = LAYOUT_split_3x6_3_WRAPPER (
        ________________NAV_L1_________________________,                        ________________NAV_R1_________________________,
        ________________NAV_L2_________________________,                        ________________NAV_R2_________________________,
        ________________NAV_L3_________________________,                        ________________NAV_R3_________________________,
                                        TB_NVLL,TB_NVLC,TB_NVLR,        TB_NVRL,TB_NVRC,TB_NVRR
    ),
    [_MEDIA] = LAYOUT_split_3x6_3_WRAPPER (
        ________________MDA_L1_________________________,                        ________________MDA_R1_________________________,
        ________________MDA_L2_________________________,                        ________________MDA_R2_________________________,
        ________________MDA_L3_________________________,                        ________________MDA_R3_________________________,
                                        TB_MELL,TB_MELC,TB_MELR,        TB_MERL,TB_MERC,TB_MERR
    ),
    [_MOUSE] = LAYOUT_split_3x6_3_WRAPPER (
        ________________MOS_L1_________________________,                        ________________MOS_R1_________________________,
        ________________MOS_L2_________________________,                        ________________MOS_R2_________________________,
        ________________MOS_L3_________________________,                        ________________MOS_R3_________________________,
                                        TB_MOLL,TB_MOLC,TB_MOLR,        TB_MORL,TB_MORC,TB_MORR
    ),
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_master) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_master) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_DRIVER_ENABLE
