#include "edeneast.h"

// Examples:
// https://github.com/qmk/qmk_firmware/blob/6f54286/users/ibnuda/combo.h

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

// enum for combos.
enum combos
{
    // Left hand combinations
    LUP_LUR_NEIGHBOUR,
    LUR_LUM_NEIGHBOUR,
    LUM_LUI_NEIGHBOUR,
    LUI_LUII_NEIGHBOUR,
    LLP_LLR_NEIGHBOUR,
    LLR_LLM_NEIGHBOUR,
    LLM_LLI_NEIGHBOUR,
    LLI_LLII_NEIGHBOUR,
    LUI_LUP_INDEX,
    LUI_LUR_INDEX,
    LLI_LLP_INDEX,
    LLI_LLR_INDEX,

    // Right hand combinations
    RUP_RUR_NEIGHBOUR,
    RUR_RUM_NEIGHBOUR,
    RUM_RUI_NEIGHBOUR,
    RUI_RUII_NEIGHBOUR,
    RLP_RLR_NEIGHBOUR,
    RLR_RLM_NEIGHBOUR,
    RLM_RLI_NEIGHBOUR,
    RLI_RLII_NEIGHBOUR,
    RUI_RUP_INDEX,
    RUI_RUR_INDEX,
    RLI_RLP_INDEX,
    RLI_RLR_INDEX,

    // Both hand combinations
    B_LLM_RLM_COMBO,
};

// Left hand combinations
const uint16_t PROGMEM lup_lur_combo[] = { LUP, LUR, COMBO_END };
const uint16_t PROGMEM lur_lum_combo[] = { LUR, LUM, COMBO_END };
const uint16_t PROGMEM lum_lui_combo[] = { LUM, LUI, COMBO_END };
const uint16_t PROGMEM lui_luii_combo[] = { LUI, LUII, COMBO_END };
const uint16_t PROGMEM llp_llr_combo[] = { LLP, LLR, COMBO_END };
const uint16_t PROGMEM llr_llm_combo[] = { LLR, LLM, COMBO_END };
const uint16_t PROGMEM llm_lli_combo[] = { LLM, LLI, COMBO_END };
const uint16_t PROGMEM lli_llii_combo[] = { LLI, LLII, COMBO_END };

const uint16_t PROGMEM lui_lup_combo[] = { LUI, LUP, COMBO_END };
const uint16_t PROGMEM lui_lur_combo[] = { LUI, LUR, COMBO_END };
const uint16_t PROGMEM lli_llp_combo[] = { LLI, LLP, COMBO_END };
const uint16_t PROGMEM lli_llr_combo[] = { LLI, LLR, COMBO_END };

// Right hand combinations
const uint16_t PROGMEM rup_rur_combo[] = { RUP, RUR, COMBO_END };
const uint16_t PROGMEM rur_rum_combo[] = { RUR, RUM, COMBO_END };
const uint16_t PROGMEM rum_rui_combo[] = { RUM, RUI, COMBO_END };
const uint16_t PROGMEM rui_ruii_combo[] = { RUI, RUII, COMBO_END };
const uint16_t PROGMEM rlp_rlr_combo[] = { RLP, RLR, COMBO_END };
const uint16_t PROGMEM rlr_rlm_combo[] = { RLR, RLM, COMBO_END };
const uint16_t PROGMEM rlm_rli_combo[] = { RLM, RLI, COMBO_END };
const uint16_t PROGMEM rli_rlii_combo[] = { RLI, RLII, COMBO_END };

const uint16_t PROGMEM rui_rup_combo[] = { RUI, RUP, COMBO_END };
const uint16_t PROGMEM rui_rur_combo[] = { RUI, RUR, COMBO_END };
const uint16_t PROGMEM rli_rlp_combo[] = { RLI, RLP, COMBO_END };
const uint16_t PROGMEM rli_rlr_combo[] = { RLI, RLR, COMBO_END };

// Both hand combinations
const uint16_t PROGMEM B_llm_rlm_combo[] = { LLM, RLM, COMBO_END };

// clang-format off
combo_t key_combos[COMBO_COUNT] = {
    [LLM_LLI_NEIGHBOUR] = COMBO(llm_lli_combo, KC_GRV),
    [LLR_LLM_NEIGHBOUR] = COMBO(llr_llm_combo, KC_TILD),

    [RUP_RUR_NEIGHBOUR] = COMBO(rup_rur_combo, KC_DEL),
    [RLR_RLM_NEIGHBOUR] = COMBO(rlr_rlm_combo, KC_EXLM),
    [RLM_RLI_NEIGHBOUR] = COMBO(rlm_rli_combo, KC_PIPE),
    [RLI_RLR_INDEX]     = COMBO(rli_rlr_combo, KC_BSLS),
};
