#include QMK_KEYBOARD_H
#include "charybdis.h"

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
        MY_RU_SHCH, KC_Q,         KC_W,         KC_F,         LT(REPL,KC_P), KC_B,        KC_J,            LT(REPR,KC_L), KC_U,         KC_Y,         KC_QUOT,      LSFT(KC_SLSH),
        MY_RU_CHE,  LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T),  MEH_T(KC_G), MEH_T(KC_M),     KC_N,          LCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O), KC_COMM,
        MY_RU_ZHE,  KC_Z,         KC_X,         KC_C,         KC_D,          KC_V,        KC_K,            KC_H,          KC_COMM,      KC_DOT,       KC_SLSH,      KC_DOT,
                                  LT(MEDIA,KC_ESC), LT(NAV,KC_SPC), LT(MOUSE,KC_TAB),     LT(SYM,KC_ENT),  LT(NUM,KC_BSPC),
                                                    KC_LGUI,        KC_MEH,               LT(FUN,KC_DEL)
  ),

  [MEDIA] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, KC_TRNS,
        KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_MEH,  KC_NO,   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_TRNS,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   OU_AUTO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
                                        KC_NO, KC_NO, KC_NO, KC_MSTP, KC_MPLY,
                                        KC_NO, KC_NO,        KC_MUTE
  ),

    [NAV] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, QK_BOOT,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,   KC_TRNS,
    KC_TRNS, KC_LGUI,  KC_LALT, KC_LCTL, KC_LSFT, KC_MEH,  CW_TOGG, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,
    KC_TRNS, KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS,
                                        KC_NO, KC_NO, KC_NO, KC_ENT, KC_BSPC,
                                        KC_NO, KC_NO,        KC_DEL
    ),

    //  TODO: update DRAGSCROLL_MODE, make it vertical and horizontal
    [MOUSE] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS,      KC_TRNS,
        KC_TRNS, QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,        U_RDO,   U_PST,   U_CPY,           U_CUT,   U_UND,        KC_TRNS,
        KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, SNIPING_MODE, KC_BTN3, KC_BTN1, DRAGSCROLL_MODE, KC_BTN2, SNIPING_MODE, KC_TRNS,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_BTN4, KC_NO,           KC_NO,   KC_BTN5,      KC_TRNS,
                                                KC_NO, KC_NO, KC_NO, KC_BTN2, KC_BTN1,
                                                KC_NO, KC_NO,        KC_BTN3
    ),

    [SYM] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT, KC_TRNS,
        KC_TRNS, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, KC_MEH,  KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_TRNS,
        KC_TRNS, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_TRNS,
                                   KC_LPRN, KC_RPRN, KC_UNDS, KC_NO, KC_NO,
                                            KC_NO,   KC_NO,   KC_NO
    ),

    [NUM] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,         KC_TRNS,       KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, KC_NO,   KC_NO,           KC_NO,           KC_NO,         QK_BOOT,          KC_TRNS,
        KC_TRNS, KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,  KC_MEH,  LSFT_T(KC_LEFT), LCTL_T(KC_DOWN), LALT_T(KC_UP), LGUI_T(KC_RIGHT), KC_TRNS,
        KC_TRNS, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, KC_NO,   KC_NO,           KC_NO,           KC_NO,         KC_NO,            KC_TRNS,
                                                KC_DOT, KC_0, KC_MINS, KC_NO, KC_NO,
                                                       KC_NO, KC_NO,   KC_NO
    ),

    [FUN] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_F12,  KC_F7,   KC_F8,   KC_F9,  KC_PSCR, KC_NO,  KC_NO,   KC_NO,   KC_NO,   QK_BOOT, KC_TRNS,
        KC_TRNS, KC_F11,  KC_F4,   KC_F5,   KC_F6,  KC_SCRL, KC_MEH, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_TRNS,
        KC_TRNS, KC_F10,  KC_F1,   KC_F2,   KC_F3,  KC_PAUS, KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_TRNS,
                                             KC_APP, KC_SPC, KC_TAB, KC_NO, KC_NO,
                                               KC_NO, KC_NO, KC_NO
    ),

    [REPL] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,   KC_U,    KC_Y,   KC_QUOT, KC_TRNS,
        KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_MEH,  KC_M,    KC_N,   KC_E,    KC_I,   KC_O, KC_TRNS,
        KC_TRNS, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,   KC_COMM, KC_DOT, KC_SLSH, KC_TRNS,
                                  KC_LSFT, KC_LSFT, KC_LSFT,     LT(SYM,KC_ENT),  LT(NUM,KC_BSPC),
                                           KC_LSFT, KC_LSFT,     LT(FUN,KC_DEL)
    ),

    [REPR] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_Q,    KC_W,    KC_F,    KC_P,   KC_B,   KC_J,   KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_TRNS,
        KC_TRNS, KC_A,    KC_R,    KC_S,    KC_T,   KC_G,   KC_MEH, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_TRNS,
        KC_TRNS, KC_Z,    KC_X,    KC_C,    KC_D,   KC_V,   KC_K,   KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_TRNS,
            LT(MEDIA,KC_ESC), LT(NAV,KC_SPC), LT(MOUSE,KC_TAB),     KC_LSFT,  KC_LSFT,
                                    KC_LGUI,        KC_MEH,         KC_LSFT
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
