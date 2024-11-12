#include QMK_KEYBOARD_H

#define KC_LG_RBR LGUI_T(KC_RBRC)
#define KC_LC_GRV LCTL_T(KC_GRV)
#define KC_LA_BCL LALT_T(KC_BSLS)

#define KC_RG_LBR RGUI_T(KC_LBRC)
#define KC_RC_QUO RCTL_T(KC_QUOT)
#define KC_RA_MIN RALT_T(KC_MINUS)

#define KC_L2_TAB LT(2,KC_TAB)
#define KC_LS_SPC LSFT_T(KC_SPC)
#define KC_L1_ENT LT(1,KC_ENT)

#define KC_L1_ESC LT(1,KC_ESC)
#define KC_RS_BSP RSFT_T(KC_BSPC)
#define KC_L2_DEL LT(2,KC_DEL)

#define KC_L3_TAB LT(3, KC_TAB)
#define KC_L3_DEL LT(3, KC_DEL)

#define KC_L3_ENT LT(3,KC_ENT)
#define KC_L3_ESC LT(3,KC_ESC)

#define KC_LG_NLC LGUI_T(KC_NUM)
#define KC_LC_PPL LCTL_T(KC_PPLS)
#define KC_LA_EQL LALT_T(KC_EQL)

#define KC_LG__F1 LGUI_T(KC_F1)
#define KC_RG_F12 RGUI_T(KC_F12)


#define KC_LG_SCL LGUI_T(KC_SCRL)
#define KC_LC_PAU LCTL_T(KC_PAUS)
#define KC_LA_INS LALT_T(KC_INS)

#define KC_RG_CAP RGUI_T(KC_CAPS)
#define KC_RC_APP RCTL_T(KC_APP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT(
//┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                   ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
   KC_LG_RBR ,   KC_Q   ,   KC_W   ,   KC_E   ,   KC_R   ,   KC_T   ,                                       KC_Y   ,   KC_U   ,   KC_I   ,   KC_O   ,   KC_P   ,KC_RG_LBR ,
//├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
   KC_LC_GRV ,   KC_A   ,   KC_S   ,   KC_D   ,   KC_F   ,   KC_G   ,                                       KC_H   ,   KC_J   ,   KC_K   ,   KC_L   ,  KC_SCLN ,KC_RC_QUO ,
//├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
   KC_LA_BCL ,   KC_Z   ,   KC_X   ,   KC_C   ,   KC_V   ,   KC_B   ,                                       KC_N   ,   KC_M   ,  KC_COMM ,   KC_DOT,   KC_SLSH ,KC_RA_MIN ,
//└──────────┴──────────┴──────────┴──────────┼──────────┼──────────┼──────────┐             ┌──────────┼──────────┼──────────┼──────────┴──────────┴──────────┴──────────┘
                                               KC_L2_TAB ,KC_LS_SPC , KC_L1_ENT,              KC_L1_ESC ,KC_RS_BSP ,KC_L2_DEL
                                           // └──────────┴──────────┴──────────┘             └──────────┴──────────┴──────────┘
),
[1] = LAYOUT(
//┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                   ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
   KC_LG__F1 ,   KC_F2  ,   KC_F3  ,   KC_F4  ,   KC_F5  ,   KC_F6  ,                                       KC_F7  ,   KC_F8  ,   KC_F9  ,   KC_F10 ,   KC_F11 ,KC_RG_F12 ,
//├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
   KC_LC_PPL ,  KC_EXLM ,   KC_AT  ,  KC_HASH ,  KC_DLR  , KC_PERC  ,                                     KC_CIRC  , KC_AMPR  ,  KC_ASTR ,  KC_LPRN ,  KC_RPRN ,  KC_UNDS ,
//├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
   KC_LA_EQL ,   KC_1   ,   KC_2   ,   KC_3   ,   KC_4   ,   KC_5   ,                                       KC_6   ,   KC_7   ,   KC_8   ,   KC_9   ,   KC_0   ,KC_RA_MIN ,
//└──────────┴──────────┴──────────┴──────────┼──────────┼──────────┼──────────┐             ┌──────────┼──────────┼──────────┼──────────┴──────────┴──────────┴──────────┘
                                               KC_L3_TAB , _______  , _______  ,               _______  , _______  ,KC_L3_DEL
                                           // └──────────┴──────────┴──────────┘             └──────────┴──────────┴──────────┘
),
[2] = LAYOUT(
//┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                   ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
   KC_LG_NLC , KC_PSLS  ,   KC_P7  ,   KC_P8  ,   KC_P9  ,   TO(3)  ,                                     KC_WH_U  ,  KC_HOME ,  KC_MPLY , KC_PGUP  ,  KC_VOLU ,KC_RG_CAP ,
//├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
   KC_LC_PPL , KC_PAST  ,   KC_P4  ,   KC_P5  ,   KC_P6  , KC_PMNS,                                       KC_LEFT  ,  KC_DOWN ,   KC_UP  , KC_RGHT  ,  KC_VOLD ,KC_RC_APP ,
//├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
   KC_LA_EQL ,  KC_P0   ,   KC_P1  ,   KC_P2  ,   KC_P3  , KC_PDOT,                                       KC_WH_D  ,  KC_END  ,  KC_PSCR , KC_PGDN  ,  KC_MUTE , KC_RALT  ,
//└──────────┴──────────┴──────────┴──────────┼──────────┼──────────┼──────────┐             ┌──────────┼──────────┼──────────┼──────────┴──────────┴──────────┴──────────┘
                                                _______  , _______  ,KC_L3_ENT ,              KC_L3_ESC , _______  , _______
                                           // └──────────┴──────────┴──────────┘             └──────────┴──────────┴──────────┘
),
[3] = LAYOUT(
//┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                   ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
   KC_LG_SCL , RGB_VAI  , KC_BTN1  , KC_MS_U  , KC_BTN2  ,  KC_WH_U ,                                     KC_WH_U  ,  KC_BTN1 ,  KC_MS_U ,  KC_BTN2 ,  BL_UP  , KC_RGUI  ,
//├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
   KC_LC_PAU , RGB_VAD  , KC_MS_L  , KC_MS_D  , KC_MS_R  ,  KC_BTN3 ,                                     KC_BTN3  ,  KC_MS_L ,  KC_MS_D ,  KC_MS_R ,  BL_DOWN  , KC_RCTL  ,
//├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
   KC_LA_INS , RGB_TOG  ,  QK_REBOOT   ,   TO(2)  ,   TO(1)  ,  KC_WH_D ,                                     KC_MS_D  ,   TO(1)  ,   TO(2)  ,   QK_REBOOT  ,  BL_TOGG , KC_RALT  ,
//└──────────┴──────────┴──────────┴──────────┼──────────┼──────────┼──────────┐             ┌──────────┼──────────┼──────────┼──────────┴──────────┴──────────┴──────────┘
                                                _______  , KC_LSFT  , _______  ,               _______  , KC_RSFT  , _______
                                           // └──────────┴──────────┴──────────┘             └──────────┴──────────┴──────────┘
)
};
const rgblight_segment_t PROGMEM my_layer0[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 0, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM my_layer1[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 7, HSV_RED}
);
const rgblight_segment_t PROGMEM my_layer2[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 7, HSV_GREEN}
);
const rgblight_segment_t PROGMEM my_layer3[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 7, HSV_CYAN}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layer0,
    my_layer1,
    my_layer2,
    my_layer3// Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
};

layer_state_t layer_state_set_user(layer_state_t state) {
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    return state;
};
