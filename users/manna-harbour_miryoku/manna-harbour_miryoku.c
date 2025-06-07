// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H

#include "manna-harbour_miryoku.h"
#include "keymap_russian.h"


// Additional Features double tap guard

enum {
    U_TD_BOOT,
#define MIRYOKU_X(LAYER, STRING) U_TD_U_##LAYER,
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};

void u_td_fn_boot(tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    reset_keyboard();
  }
}

#define MIRYOKU_X(LAYER, STRING) \
void u_td_fn_U_##LAYER(tap_dance_state_t *state, void *user_data) { \
  if (state->count == 2) { \
    default_layer_set((layer_state_t)1 << U_##LAYER); \
  } \
}
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X

tap_dance_action_t tap_dance_actions[] = {
    [U_TD_BOOT] = ACTION_TAP_DANCE_FN(u_td_fn_boot),
#define MIRYOKU_X(LAYER, STRING) [U_TD_U_##LAYER] = ACTION_TAP_DANCE_FN(u_td_fn_U_##LAYER),
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};


// keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#define MIRYOKU_X(LAYER, STRING) [U_##LAYER] = U_MACRO_VA_ARGS(MIRYOKU_LAYERMAPPING_##LAYER, MIRYOKU_LAYER_##LAYER),
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};


// shift functions

const key_override_t capsword_key_override = ko_make_basic(MOD_MASK_SHIFT, CW_TOGG, KC_CAPS);

const key_override_t **key_overrides = (const key_override_t *[]){
    &capsword_key_override,
    NULL
};


// thumb combos

#if defined (MIRYOKU_KLUDGE_THUMBCOMBOS)
const uint16_t PROGMEM thumbcombos_base_right[] = {LT(U_SYM, KC_ENT), LT(U_NUM, KC_BSPC), COMBO_END};
const uint16_t PROGMEM thumbcombos_base_left[] = {LT(U_NAV, KC_SPC), LT(U_MOUSE, KC_TAB), COMBO_END};
const uint16_t PROGMEM thumbcombos_nav[] = {KC_ENT, KC_BSPC, COMBO_END};
const uint16_t PROGMEM thumbcombos_mouse[] = {KC_BTN2, KC_BTN1, COMBO_END};
const uint16_t PROGMEM thumbcombos_media[] = {KC_MSTP, KC_MPLY, COMBO_END};
const uint16_t PROGMEM thumbcombos_num[] = {KC_0, KC_MINS, COMBO_END};
  #if defined (MIRYOKU_LAYERS_FLIP)
const uint16_t PROGMEM thumbcombos_sym[] = {KC_UNDS, KC_LPRN, COMBO_END};
  #else
const uint16_t PROGMEM thumbcombos_sym[] = {KC_RPRN, KC_UNDS, COMBO_END};
  #endif
const uint16_t PROGMEM thumbcombos_fun[] = {KC_SPC, KC_TAB, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
  COMBO(thumbcombos_base_right, LT(U_FUN, KC_DEL)),
  COMBO(thumbcombos_base_left, LT(U_MEDIA, KC_ESC)),
  COMBO(thumbcombos_nav, KC_DEL),
  COMBO(thumbcombos_mouse, KC_BTN3),
  COMBO(thumbcombos_media, KC_MUTE),
  COMBO(thumbcombos_num, KC_DOT),
  #if defined (MIRYOKU_LAYERS_FLIP)
  COMBO(thumbcombos_sym, KC_RPRN),
  #else
  COMBO(thumbcombos_sym, KC_LPRN),
  #endif
  COMBO(thumbcombos_fun, KC_APP)
};
#endif

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

const uint16_t PROGMEM lang_switch_combo[] = {LSFT_T(KC_N), LCTL_T(KC_E), COMBO_END};

combo_t key_combos[] = {
    COMBO(lang_switch_combo, LANG_SWITCH),
};

static bool is_lang_switched = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    is_lang_switched = !is_lang_switched;
    /* if (keycode == LANG_SWITCH && record->event.pressed) { */
    /*     // Press Cmd/Win key */
    /*     register_code(KC_LGUI); // KC_LGUI is the left Cmd/Win key */
    /*     // Press Space */
    /*     register_code(KC_SPACE); */
    /**/
    /*     is_lang_switched = !is_lang_switched; */
    /**/
    /*     // Release Space */
    /*     unregister_code(KC_SPACE); */
    /*     // Release Cmd/Win key */
    /*     unregister_code(KC_LGUI); */
    /**/
    /*     return false; // Skip further processing of this key */
    /* } */
    /* if (is_lang_switched && get_mods() & MOD_MASK_SHIFT && keycode == KC_Y && record->event.pressed) { */
    /**/
    /*     register_code(KC_LSFT); // KC_LGUI is the left Cmd/Win key */
    /*     register_code(RU_YERU); */
    /*     unregister_code(RU_YERU); */
    /*     unregister_code(KC_LSFT); */
    /**/
    /*     return false; // Skip further processing of this key */
    /* } */
    /**/
    return true; // Process other keycodes normally
}

#define COMBO_MUST_TAP_PER_COMBO

#ifdef COMBO_MUST_TAP_PER_COMBO
bool get_combo_must_tap(uint16_t combo_index, combo_t *combo) {
    // If you want all combos to be tap-only, just uncomment the next line
    // return true

    // If you want *all* combos, that have Mod-Tap/Layer-Tap/Momentary keys in its chord, to be tap-only, this is for you:
    uint16_t key;
    uint8_t idx = 0;
    while ((key = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
        switch (key) {
            case QK_MOD_TAP...QK_MOD_TAP_MAX:
            case QK_LAYER_TAP...QK_LAYER_TAP_MAX:
            case QK_MOMENTARY...QK_MOMENTARY_MAX:
                return true;
        }
        idx += 1;
    }
    return false;

}
#endif
