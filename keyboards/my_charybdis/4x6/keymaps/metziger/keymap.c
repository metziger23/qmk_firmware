#include QMK_KEYBOARD_H
#include "charybdis.h"
#include "charybdis.c" // NOTE: if not included than SNIPING and DRGSCRL not working
#include "keymap_russian.h"

enum charybdis_keymap_layers {
    BASE = 0,
    MEDIA,
    NAV,
    MOUSE,
    SYM,
    NUM,
    FUN,
    REPL,
    REPR,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
        KC_ESC,     KC_1,         KC_2,         KC_3,         KC_4,          KC_5,        KC_6,            KC_7,          KC_8,         KC_9,         KC_0,         KC_MINS,
        KC_LBRC,    KC_Q,         KC_W,         KC_F,         LT(REPL,KC_P), KC_B,        KC_J,            LT(REPR,KC_L), KC_U,         KC_Y,         KC_QUOT,      KC_RBRC,
        KC_COLN,    LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T),  RGUI_T(KC_G), RGUI_T(KC_M),     LSFT_T(KC_N),  LCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O), KC_SCLN,
        KC_LPRN,    KC_Z,         KC_X,         KC_C,         KC_D,          KC_V,        KC_K,            KC_H,          KC_COMM,      KC_DOT,       KC_SLSH,      KC_RPRN,
                                  LT(MEDIA,KC_ESC), LT(NAV,KC_SPC), LT(MOUSE,KC_TAB),     LT(SYM,KC_ENT),  LT(NUM,KC_BSPC),
                                                    LSFT(KC_QUOT),  LCTL(KC_6),           LT(FUN,KC_DEL)
  ),

  [MEDIA] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, KC_TRNS,
        KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_RGUI,  KC_NO,   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_TRNS,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   OU_AUTO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
                                        KC_NO, KC_NO, KC_NO, KC_MSTP, KC_MPLY,
                                        KC_NO, KC_NO,        KC_MUTE
  ),

    [NAV] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, QK_BOOT,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,   KC_TRNS,
    KC_TRNS, KC_LGUI,  KC_LALT, KC_LCTL, KC_LSFT, KC_RGUI,  CW_TOGG, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,
    KC_TRNS, KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS,
                                        KC_NO, KC_NO, KC_NO, KC_ENT, KC_BSPC,
                                        KC_NO, KC_NO,        KC_DEL
    ),

    //  TODO: update DRAGSCROLL_MODE, make it vertical and horizontal
    [MOUSE] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS,      KC_TRNS,
        KC_TRNS, QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,        U_RDO,   U_PST,   U_CPY,           U_CUT,   U_UND,        KC_TRNS,
        KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, SNIPING,      KC_BTN3, KC_BTN1, DRGSCRL,         KC_BTN2, SNIPING,      KC_TRNS,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_BTN4, KC_NO,           KC_NO,   KC_BTN5,      KC_TRNS,
                                                KC_NO, KC_NO, KC_NO, KC_BTN2, KC_BTN1,
                                                KC_NO, KC_NO,        KC_BTN3
    ),

    [SYM] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LCBR, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT, KC_RCBR,
        KC_TRNS, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, KC_RGUI,  KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_TRNS,
        KC_TRNS, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_TRNS,
                                   KC_LPRN, KC_RPRN, KC_UNDS, KC_NO, KC_NO,
                                            KC_NO,   KC_NO,   KC_NO
    ),

    [NUM] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,         KC_TRNS,       KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, KC_NO,   KC_NO,           KC_NO,           KC_NO,         QK_BOOT,          KC_TRNS,
        KC_TRNS, KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,  KC_RGUI,  LSFT_T(KC_LEFT), LCTL_T(KC_DOWN), LALT_T(KC_UP), LGUI_T(KC_RIGHT), KC_TRNS,
        KC_TRNS, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, KC_NO,   KC_NO,           KC_NO,           KC_NO,         KC_NO,            KC_TRNS,
                                                KC_DOT, KC_0, KC_MINS, KC_NO, KC_NO,
                                                       KC_NO, KC_NO,   KC_NO
    ),

    [FUN] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_F12,  KC_F7,   KC_F8,   KC_F9,  KC_PSCR, KC_NO,  KC_NO,   KC_NO,   KC_NO,   QK_BOOT, KC_TRNS,
        KC_TRNS, KC_F11,  KC_F4,   KC_F5,   KC_F6,  KC_SCRL, KC_RGUI, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_TRNS,
        KC_TRNS, KC_F10,  KC_F1,   KC_F2,   KC_F3,  KC_PAUS, KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_TRNS,
                                             KC_APP, KC_SPC, KC_TAB, KC_NO, KC_NO,
                                               KC_NO, KC_NO, KC_NO
    ),

    [REPL] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,   KC_U,    KC_Y,   KC_QUOT, KC_TRNS,
        KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_RGUI,  KC_M,    KC_N,   KC_E,    KC_I,   KC_O, KC_TRNS,
        KC_TRNS, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,   KC_COMM, KC_DOT, KC_SLSH, KC_TRNS,
                                  KC_LSFT, KC_LSFT, KC_LSFT,     LT(SYM,KC_ENT),  LT(NUM,KC_BSPC),
                                           KC_LSFT, KC_LSFT,     LT(FUN,KC_DEL)
    ),

    [REPR] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_Q,    KC_W,    KC_F,    KC_P,   KC_B,   KC_J,   KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_TRNS,
        KC_TRNS, KC_A,    KC_R,    KC_S,    KC_T,   KC_G,   KC_RGUI, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_TRNS,
        KC_TRNS, KC_Z,    KC_X,    KC_C,    KC_D,   KC_V,   KC_K,   KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_TRNS,
            LT(MEDIA,KC_ESC), LT(NAV,KC_SPC), LT(MOUSE,KC_TAB),     KC_LSFT,  KC_LSFT,
                              LSFT(KC_QUOT),  LCTL(KC_6),           KC_LSFT
    ),
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(

    'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
                   'L', 'L', 'L', 'R', 'R',
                        'L', 'L', 'R'
);
// clang-format on

static bool is_lang_switched = false;
static bool lang_switching_started = false;
int get_ru_sym(int eng_sym);

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

        case KC_GRAVE: return true;
        case KC_TILD: return true;

        case KC_BSLS: return true;

        case KC_LBRC: return true;
        case KC_LPRN: return true;
        case KC_RBRC: return true;
        case KC_SCLN: return true;
        case KC_RPRN: return true;
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    const bool is_shift_on = (get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT;
    const bool is_ctrl_on = (get_mods() | get_oneshot_mods()) & MOD_MASK_CTRL;
    const bool is_alt_on = (get_mods() | get_oneshot_mods()) & MOD_MASK_ALT;
    const bool is_gui_on = (get_mods() | get_oneshot_mods()) & MOD_MASK_GUI;

    const bool switch_lang = record->event.pressed && keycode == LT(NUM,KC_BSPC) && record->tap.count
        && is_shift_on && !is_ctrl_on && !is_alt_on && !is_gui_on;

    if (switch_lang) {
        if (lang_switching_started) { return false; }
        is_lang_switched = !is_lang_switched;
        tap_code16(KC_RSFT);
        return false; // Skip further processing of this key
    } else if (is_lang_switched && record->event.pressed &&
                (record->tap.count || IS_BASIC_KEYCODE(keycode) ||
                is_non_basic_symbol(keycode))) {

        if (is_ctrl_on || is_alt_on || is_gui_on) return true;

        int ru_key = get_ru_sym(keycode);
        if (!ru_key) return true;
        tap_code16(ru_key);
        return false; // Skip further processing of this key
    }

    return true; // Process other keycodes normally
}

int get_ru_sym(int eng_sym) {
    const bool is_shift_on = (get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT;

    switch (eng_sym) {
        case KC_Q: return RU_TSE;
        case KC_W: return RU_KA;
        case KC_F: return RU_EL;
        case LT(REPL, KC_P): return RU_BE;
        case KC_P: return RU_BE;
        case KC_B: return RU_SHTI;
        case KC_J: return RU_HARD;
        case LT(REPR, KC_L): return RU_YERU;
        case KC_L: return RU_YERU;
        case KC_U: return RU_YA;
        case KC_Y: return RU_E;
        case KC_QUOTE: return RU_EF;
        case LGUI_T(KC_A): return RU_ZE;
        case KC_A: return RU_ZE;
        case LALT_T(KC_R): return RU_VE;
        case KC_R: return RU_VE;
        case LCTL_T(KC_S): return RU_EN;
        case KC_S: return RU_EN;
        case LSFT_T(KC_T): return RU_TE;
        case KC_T: return RU_TE;
        case RGUI_T(KC_G): return RU_DE;
        case KC_G: return RU_DE;
        case RGUI_T(KC_M): return RU_I;
        case KC_M: return RU_I;
        case LSFT_T(KC_N): return RU_A;
        case KC_N: return RU_A;
        case LCTL_T(KC_E): return RU_O;
        case KC_E: return RU_O;
        case LALT_T(KC_I): return RU_IE;
        case KC_I: return RU_IE;
        case LGUI_T(KC_O): return RU_ES;
        case KC_O: return RU_ES;
        case KC_Z: return RU_HA;
        case KC_X: return RU_PE;
        case KC_C: return RU_ER;
        case KC_D: return RU_EM;
        case KC_V: return RU_GHE;
        case KC_K: return RU_YO;
        case KC_H: return RU_SOFT;
        case KC_COMMA: return RU_U;
        case KC_DOT: return IS_LAYER_ON(NUM) ? (is_shift_on ? RU_LPRN : RU_DOT) : RU_YU;
        case KC_SLSH: return RU_SHA;

        case KC_LBRC: return IS_LAYER_ON(BASE) ? RU_SHCH : is_shift_on ? S(RALT(KC_LPRN)) : RALT(KC_GRV);
        case KC_RBRC: return IS_LAYER_ON(BASE) ? (is_shift_on ? S(RALT(KC_DOT)) : RU_DOT) : is_shift_on ? S(RALT(KC_RPRN)) : S(RALT(KC_GRV));

        case KC_LCBR: return S(RALT(KC_LPRN));
        case KC_RCBR: return S(RALT(KC_RPRN));

        case KC_SCLN: return IS_LAYER_ON(BASE) ? (is_shift_on ? S(RALT(KC_COMM)) : RU_COMM) : RU_SCLN;
        case KC_COLN: return IS_LAYER_ON(BASE) ? RU_CHE : RU_COLN;

        case KC_AT: return RALT(KC_2);
        case KC_HASH: return RALT(KC_3);
        case KC_DLR: return RALT(KC_4);
        case KC_CIRC: return RALT(KC_6);
        case KC_AMPR: return RALT(KC_7);

        case KC_BSLS: return is_shift_on ? S(RALT(KC_PIPE)) : KC_BSLS;
        case KC_PIPE: return S(RALT(KC_PIPE));

        case KC_GRAVE: return is_shift_on ? RU_DQUO : RALT(KC_O);
        case KC_TILD: return RU_DQUO;

        case KC_LPRN: return IS_LAYER_ON(BASE) ? RU_ZHE : KC_LPRN;
        case KC_RPRN: return IS_LAYER_ON(BASE) ? (is_shift_on ? RU_QUES : RU_SLSH) : KC_RPRN;
    }
    return KC_NO;
}

#define ko_make_ru_sft_num(num) \
((const key_override_t){                                                                \
  .trigger_mods      = MOD_MASK_SHIFT,\
  .layers            = ~NUM,\
  .suppressed_mods   = MOD_MASK_SHIFT,\
  .options           = ko_options_default,\
  .negative_mod_mask = 0,\
  .custom_action     = NULL,\
  .context           = NULL,\
  .trigger           = num,\
  .replacement       = RALT(num),\
  .enabled           = &is_lang_switched\
})

const key_override_t capsword_key_override = ko_make_basic(MOD_MASK_SHIFT, CW_TOGG, KC_CAPS);

const key_override_t ru_sft_2 = ko_make_ru_sft_num(KC_2);
const key_override_t ru_sft_3 = ko_make_ru_sft_num(KC_3);
const key_override_t ru_sft_4 = ko_make_ru_sft_num(KC_4);
const key_override_t ru_sft_6 = ko_make_ru_sft_num(KC_6);
const key_override_t ru_sft_7 = ko_make_ru_sft_num(KC_7);

const key_override_t **key_overrides = (const key_override_t *[]){
  &capsword_key_override,
  &ru_sft_2, &ru_sft_2, &ru_sft_3, &ru_sft_4, &ru_sft_6, &ru_sft_7,
  NULL
};

