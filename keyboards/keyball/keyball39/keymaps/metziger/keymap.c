/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"
#include "keymap_russian.h"

enum layer_names {
    BASE,
    MEDIA,
    NAV,
    MOUSE,
    SYM,
    NUM,
    FUN,
    SFTFUN,
    REPL,
    REPR,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default
  [BASE] = LAYOUT_right_ball(
    KC_Q,               KC_W,               KC_F,               LT(REPL,KC_P),          KC_B,                 KC_J,                   LT(REPR,KC_L),        KC_U,                     KC_Y,               KC_QUOT,
    LGUI_T(KC_A),       LALT_T(KC_R),       LCTL_T(KC_S),       LSFT_T(KC_T),           MEH_T(KC_G),          MEH_T(KC_M),            LSFT_T(KC_N),         LCTL_T(KC_E),             LALT_T(KC_I),       LGUI_T(KC_O),
    KC_Z,               KC_X,               KC_C,               KC_D,                   KC_V,                 LT(SFTFUN,KC_K),        LT(FUN,KC_H),         KC_COMM,                  KC_DOT,             KC_SLSH,
    MY_RU_E,            MY_RU_SHCH,         MY_RU_EF,           LT(MEDIA,KC_ESC),       LT(NAV,KC_SPC),       LT(MOUSE,KC_TAB),       LT(SYM,KC_ENT),       LT(NUM,KC_BSPC),          MY_RU_TSE
  ),

  [MEDIA] = LAYOUT_right_ball(
    QK_BOOT,       KC_NO,       KC_NO,       KC_NO,       KC_NO,      RGB_TOG,     RGB_MOD,     RGB_HUI,     RGB_SAI,     RGB_VAI,
    KC_LGUI,     KC_LALT,     KC_LCTL,     KC_LSFT,     KC_MEH,     KC_NO,       KC_MPRV,     KC_VOLD,     KC_VOLU,     KC_MNXT,
    KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,      OU_AUTO,     KC_NO,       KC_NO,       KC_NO,       KC_NO,
    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_NO,       KC_NO,      KC_NO,       KC_MSTP,     KC_MPLY,     KC_TRNS
  ),

  [NAV] = LAYOUT_right_ball(
    QK_BOOT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_MEH, CW_TOGG, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,  KC_NO,   KC_ENT,  KC_BSPC, KC_TRNS
  ),

  [MOUSE] = LAYOUT_right_ball(
    QK_BOOT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     U_RDO,   U_PST,   U_CPY,       U_CUT,       U_UND,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, SNIPER_MO, KC_BTN3, KC_BTN1, SCRL_MO_VRT, KC_BTN2,     SNIPER_MO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_BTN4, SCRL_MO_FRE, SCRL_MO_HOR, KC_BTN5,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,     KC_NO,   KC_MUTE, KC_DEL,      KC_TRNS
  ),

    [SYM] = LAYOUT_right_ball(
    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT,
    KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, KC_MEH,  KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_LPRN, KC_RPRN, KC_UNDS, KC_NO,   KC_NO,   KC_TRNS
    ),

    [NUM] = LAYOUT_right_ball(
    KC_LBRC, KC_7,    KC_8,    KC_9,   KC_RBRC, KC_NO,   KC_NO,           KC_NO,           KC_NO,         QK_BOOT,
    KC_SCLN, KC_4,    KC_5,    KC_6,   KC_EQL,  KC_MEH,  LSFT_T(KC_LEFT), LCTL_T(KC_DOWN), LALT_T(KC_UP), LGUI_T(KC_RIGHT),
    KC_GRV,  KC_1,    KC_2,    KC_3,   KC_BSLS, KC_NO,   KC_NO,           KC_NO,           KC_NO,         KC_NO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_DOT, KC_0,    KC_MINS, KC_NO,           KC_NO,           KC_TRNS
    ),

    [FUN] = LAYOUT_right_ball(
    KC_F12,  KC_F7,   KC_F8,   KC_F9,  KC_PSCR, KC_NO,  KC_NO,   KC_NO,   KC_NO,   QK_BOOT,
    KC_F11,  KC_F4,   KC_F5,   KC_F6,  KC_SCRL, KC_MEH, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_F10,  KC_F1,   KC_F2,   KC_F3,  KC_PAUS, KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_APP, KC_SPC,  KC_TAB, KC_NO,   KC_NO,   KC_TRNS
    ),

    [SFTFUN] = LAYOUT_right_ball(
    LSFT(KC_F12), LSFT(KC_F7), LSFT(KC_F8), LSFT(KC_F9),  LSFT(KC_PSCR), KC_NO,        KC_NO,   KC_NO,         KC_NO,         QK_BOOT,
    LSFT(KC_F11), LSFT(KC_F4), LSFT(KC_F5), LSFT(KC_F6),  LSFT(KC_SCRL), KC_MEH,       KC_LSFT, LSFT(KC_LCTL), LSFT(KC_LALT), LSFT(KC_LGUI),
    LSFT(KC_F10), LSFT(KC_F1), LSFT(KC_F2), LSFT(KC_F3),  LSFT(KC_PAUS), KC_NO,        KC_NO,   KC_NO,         KC_NO,         KC_NO,
    KC_TRNS,      KC_TRNS,     KC_TRNS,     LSFT(KC_APP), LSFT(KC_SPC),  LSFT(KC_TAB), KC_NO,   KC_NO,         KC_TRNS
    ),

    [REPL] = LAYOUT_right_ball(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,   KC_U,    KC_Y,   KC_QUOT,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_MEH,  KC_M,    KC_N,   KC_E,    KC_I,   KC_O,
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,   KC_COMM, KC_DOT, KC_SLSH,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_LSFT, KC_LSFT, KC_LSFT, KC_ENT, KC_BSPC, KC_TRNS
    ),

    [REPR] = LAYOUT_right_ball(
    KC_Q,    KC_W,    KC_F,    KC_P,   KC_B,   KC_J,   KC_L,    KC_U,    KC_Y,    KC_QUOT,
    KC_A,    KC_R,    KC_S,    KC_T,   KC_G,   KC_MEH, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_Z,    KC_X,    KC_C,    KC_D,   KC_V,   KC_K,   KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_ESC, KC_SPC, KC_TAB, KC_LSFT, KC_LSFT, KC_TRNS
    ),

};
// clang-format on

/* layer_state_t layer_state_set_user(layer_state_t state) { */
/*     // Auto enable scroll mode when the highest layer is 3 */
/*     keyball_set_scroll_mode(get_highest_layer(state) == 3); */
/*     return state; */
/* } */

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

static bool is_lang_switched = false;
static bool lang_switching_started = false;
int get_ru_sym(int eng_sym);

// shift functions

const key_override_t capsword_key_override = ko_make_basic(MOD_MASK_SHIFT, CW_TOGG, KC_CAPS);

const key_override_t ru_hard_sign_key_override = {
    .trigger_mods           = MOD_MASK_SHIFT,
    .layers                 = ~0,
    .suppressed_mods        = MOD_MASK_SHIFT,
    .options                = ko_options_default,
    .negative_mod_mask      = 0,
    .custom_action          = NULL,
    .context                = NULL,
    .trigger                = KC_Z,
    .replacement            = RU_HARD,
    .enabled                = &is_lang_switched
};

const key_override_t **key_overrides = (const key_override_t *[]){
    &capsword_key_override,
    &ru_hard_sign_key_override,
    NULL
};


// thumb combos

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
    'L', 'L', 'L', 'L', 'L',   'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L',   'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L',   'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',   'R', 'R',           'R'
);

/* const uint16_t PROGMEM mute_combo_base[]     = {KC_F, LT(U_REPL, KC_P), COMBO_END}; */
/* const uint16_t PROGMEM del_combo_base[]      = {LT(U_REPR, KC_L), KC_U, COMBO_END}; */
/* const uint16_t PROGMEM mute_combo_rep[]      = {KC_F, KC_P, COMBO_END}; */
/* const uint16_t PROGMEM del_combo_rep[]       = {KC_L, KC_U, COMBO_END}; */
/* const uint16_t PROGMEM mute_combo_sftfun[]   = {LSFT(KC_F8), LSFT(KC_F9), COMBO_END}; */
/* const uint16_t PROGMEM mute_combo_num[]      = {KC_8, KC_9, COMBO_END}; */
/* const uint16_t PROGMEM del_combo_mouse_nav[] = {U_PST, U_CPY, COMBO_END}; */
/* const uint16_t PROGMEM del_combo_media[]     = {RGB_MOD, RGB_HUI, COMBO_END}; */
/* const uint16_t PROGMEM mute_combo_fun[]      = {KC_F8, KC_F9, COMBO_END}; */
/* const uint16_t PROGMEM mute_combo_sym[]      = {KC_ASTR, KC_LPRN, COMBO_END}; */
/**/
/* combo_t key_combos[] = { */
/*     COMBO(mute_combo_base,     KC_MUTE), */
/*     COMBO(del_combo_base,      KC_DEL), */
/*     COMBO(mute_combo_rep,      KC_MUTE), */
/*     COMBO(del_combo_rep,       KC_DEL), */
/*     COMBO(mute_combo_sftfun,   KC_MUTE), */
/*     COMBO(mute_combo_num,      KC_MUTE), */
/*     COMBO(del_combo_mouse_nav, KC_DEL), */
/*     COMBO(del_combo_media,     KC_DEL), */
/*     COMBO(mute_combo_fun,      KC_MUTE), */
/*     COMBO(mute_combo_sym,      KC_MUTE), */
/* }; */

/* const uint16_t PROGMEM lang_switch_combo[] = {LSFT_T(KC_N), LCTL_T(KC_E), COMBO_END}; */
/**/
/* combo_t key_combos[] = { */
/*     COMBO(lang_switch_combo, LANG_SWITCH), */
/* }; */

uint32_t finish_lang_switching(uint32_t trigger_time, void *cb_arg) {
    /* do something */
    lang_switching_started = false;
    return 0;
}

bool is_non_basic_symbol(uint16_t keycode) {
    switch (keycode) {
        case KC_LCBR: return true;
        case KC_RCBR: return true;
        case KC_COLN: return true;
        case KC_AT: return true;
        case KC_HASH: return true;
        case KC_DLR: return true;
        case KC_CIRC: return true;
        case KC_AMPR: return true;

        case KC_PIPE: return true;
    }
    return false;
}

bool is_bottom_row_ru_sym(uint16_t keycode) {
    return ( keycode == MY_RU_E || keycode == MY_RU_SHCH || keycode == MY_RU_EF || keycode == MY_RU_TSE);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    const bool is_shift_on = (get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT;
    const bool is_ctrl_on = (get_mods() | get_oneshot_mods()) & MOD_MASK_CTRL;
    const bool is_alt_on = (get_mods() | get_oneshot_mods()) & MOD_MASK_ALT;
    const bool is_gui_on = (get_mods() | get_oneshot_mods()) & MOD_MASK_GUI;

    /* && layer_state_is(0) */
    const bool switch_lang = record->event.pressed && keycode == LT(NUM,KC_BSPC) && record->tap.count
        && is_shift_on && !is_ctrl_on && !is_alt_on && !is_gui_on;

    if (switch_lang) {
        if (lang_switching_started) { return false; }

        is_lang_switched = !is_lang_switched;
        /* register_code(KC_LGUI); // KC_LGUI is the left Cmd/Win key */
        /* register_code(KC_SPACE); */
        /* tap_code16_delay(LGUI(KC_SPACE), 50); */
        /* unregister_code(KC_LEFT_SHIFT); */
        /* lang_switching_started = true; */
        /* defer_exec(30, finish_lang_switching, NULL); */
        /* wait_ms(5); */
        /* register_code(KC_LGUI); */
        /**/
        /* wait_ms(10); */
        /**/
        /* register_code(KC_SPACE); */
        /* wait_ms(10); */
        /* unregister_code(KC_SPACE); */
        /* wait_ms(10); */
        /**/
        /* unregister_code(KC_LGUI); */
        /* wait_ms(5); */
        /**/
        /* register_code(KC_LEFT_SHIFT); */

        tap_code16(KC_F19);

        return false; // Skip further processing of this key
    } else if (is_lang_switched && record->event.pressed &&
        (record->tap.count || IS_BASIC_KEYCODE(keycode) ||
        is_bottom_row_ru_sym(keycode) || is_non_basic_symbol(keycode))) {
        if (is_ctrl_on || is_alt_on || is_gui_on) return true;

        int ru_key = get_ru_sym(keycode);
        if (!ru_key) return true;
        tap_code16(ru_key);
        return false; // Skip further processing of this key
    }

    return true; // Process other keycodes normally
}

/* bool get_combo_must_tap(uint16_t combo_index, combo_t *combo) { */
/*     // If you want all combos to be tap-only, just uncomment the next line */
/*     // return true */
/**/
/*     // If you want *all* combos, that have Mod-Tap/Layer-Tap/Momentary keys in its chord, to be tap-only, this is for you: */
/*     uint16_t key; */
/*     uint8_t idx = 0; */
/*     while ((key = pgm_read_word(&combo->keys[idx])) != COMBO_END) { */
/*         switch (key) { */
/*             case QK_MOD_TAP...QK_MOD_TAP_MAX: */
/*             case QK_LAYER_TAP...QK_LAYER_TAP_MAX: */
/*             case QK_MOMENTARY...QK_MOMENTARY_MAX: */
/*                 return true; */
/*         } */
/*         idx += 1; */
/*     } */
/*     return false; */
/**/
/* } */

int get_ru_sym(int eng_sym) {
    bool is_shift_on = (get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT;
    switch (eng_sym) {
        case KC_Q: return RU_YU;
        case KC_W: return RU_ZHE;
        case KC_F: return RU_SHA;
        case LT(REPL, KC_P): return RU_PE;
        case KC_P: return RU_PE;
        case KC_B: return RU_BE;
        case KC_J: return RU_SHTI;
        case LT(REPR, KC_L): return RU_EL;
        case KC_L: return RU_EL;
        case KC_U: return RU_U;
        case KC_Y: return RU_YERU;
        case KC_QUOTE: return RU_YA;
        case LGUI_T(KC_A): return RU_A;
        case KC_A: return RU_A;
        case LALT_T(KC_R): return RU_ER;
        case KC_R: return RU_ER;
        case LCTL_T(KC_S): return RU_ES;
        case KC_S: return RU_ES;
        case LSFT_T(KC_T): return RU_TE;
        case KC_T: return RU_TE;
        case MEH_T(KC_G): return RU_GHE;
        case KC_G: return RU_GHE;
        case MEH_T(KC_M): return RU_EM;
        case KC_M: return RU_EM;
        case LSFT_T(KC_N): return RU_EN;
        case KC_N: return RU_EN;
        case LCTL_T(KC_E): return RU_IE;
        case KC_E: return RU_IE;
        case LALT_T(KC_I): return RU_I;
        case KC_I: return RU_I;
        case LGUI_T(KC_O): return RU_O;
        case KC_O: return RU_O;
        case KC_Z: { if (is_shift_on) return KC_NO; return RU_SOFT; }
        case KC_X: return RU_HA;
        case KC_C: return RU_ZE;
        case KC_D: return RU_DE;
        case KC_V: return RU_VE;
        case LT(SFTFUN, KC_K): return RU_KA;
        case KC_K: return RU_KA;
        case LT(FUN,KC_H): return RU_CHE;
        case KC_H: return RU_CHE;
        case KC_COMMA: { if (is_shift_on) return RALT(S(KC_COMMA)); return RU_COMM;}
        case KC_DOT: { if (is_shift_on) return RALT(S(KC_DOT)); return RU_DOT;}
        case KC_SLSH: { if (is_shift_on) return RU_QUES; return RU_SLSH; }

        case MY_RU_E: return RU_E;
        case MY_RU_SHCH: return RU_SHCH;
        case MY_RU_EF: return RU_EF;
        case MY_RU_TSE: return RU_TSE;

        case KC_LBRC: return RALT(KC_GRV);
        case KC_RBRC: return S(RALT(KC_GRV));

        case KC_LCBR: return S(RALT(KC_LPRN));
        case KC_RCBR: return S(RALT(KC_RPRN));

        case KC_SCLN: return RU_SCLN;
        case KC_COLN: return RU_COLN;

        case KC_AT: return RALT(KC_2);
        case KC_HASH: return RALT(KC_3);
        case KC_DLR: return RALT(KC_4);
        case KC_CIRC: return RALT(KC_6);
        case KC_AMPR: return RALT(KC_7);

        case KC_PIPE: return S(RALT(KC_PIPE));
    }
    return KC_NO;
}
