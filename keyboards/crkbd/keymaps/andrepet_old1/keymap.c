/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any lat

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// Layers
#define _QWERTY 0
#define _Q_SWE 1
#define _Q_SWE_SFT 2
#define _COLEMAK 3
#define _C_SWE 4
#define _C_SWE_SFT 5
#define _SYM 6
#define _FUN 7
#define _NAV 8

// qwerty and colemak
#define QWE_T	TO(_QWERTY)
#define Q_SWE_T	TO(_Q_SWE)
#define Q_SWE_SFT	LT(_Q_SWE_SFT,KC_LSFT)
#define Q_SWE_BSL	LT(_Q_SWE_SFT,KC_BSLS)

#define COL_T	TO(_COLEMAK)
#define C_SWE_T	TO(_C_SWE)
#define C_SWE_SFT	MO(_C_SWE_SFT)
#define C_SWE_BSL	LT(_C_SWE_SFT,KC_BSLS)

// special layers
// #define NUM_ENT	LT(_NUM,KC_ENT)
#define FUN_L  	MO(_FUN)
#define NAV_ENT	LT(_NAV,KC_ENT)
#define NAV_BSP	LT(_NAV,KC_BSPC)
#define SYM_G LT(_SYM,KC_G)
#define SYM_M LT(_SYM,KC_M)
#define SYM_H LT(_SYM,KC_H)

// shift and control
#define LC_ESC  LCTL_T(KC_ESC)
#define RC_QUOT RCTL_T(KC_QUOT)
#define RS_BSLS	RSFT_T(KC_BSLS)
#define RGUI_BS	RGUI_T(KC_BSPC)

// swedish characters lower and uppercase
#define KC_AO	UC(0xE5)
#define KC_S_AO	UC(0xC5)
#define KC_AE	UC(0xE4)
#define KC_S_AE UC(0xC4)
#define KC_OO	UC(0xF6)
#define KC_S_OO UC(0xD6)

#define KILL_P LAG(KC_ESC)

// Key Overrides
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPACE, KC_DELETE);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    NULL // Null terminate the array of overrides!
};

// Tap Dance declarations
enum {
    TD_GUI_SYM,
    TD_C_SYM,
    TD_ALT_NAV,
    TD_C_NAV,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap/hold once for GUI/command, twice for toggle Sym layer
    [TD_GUI_SYM] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_LGUI, _SYM),
    // Tap/hold once for Ctrl, twice for toggle Sym layer
    [TD_C_SYM] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_LCTL, _SYM),
    // Tap/hold once for Alt/option, twice for toggle Nav layer
    [TD_ALT_NAV] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_LALT, _NAV),
    // Tap/hold once for Ctrl, twice for toggle Nav layer
    [TD_C_NAV] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_LCTL, _NAV),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_EQL ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       LC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,   SYM_G,                        SYM_H,    KC_J,    KC_K,    KC_L, KC_SCLN, RC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, RS_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    TD(TD_C_SYM) , KC_SPC , NAV_ENT,   KC_BSPC , NAV_BSP, TD(TD_ALT_NAV)
                                      //`--------------------------'  `--------------------------'

  ),

  [_Q_SWE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,------------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_AO   ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------|
       LC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,   SYM_G,                        SYM_H,    KC_J,    KC_K,    KC_L,   KC_OO, KC_AE   ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------|
    Q_SWE_SFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,Q_SWE_BSL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+---------|
                                    TD(TD_C_SYM) , KC_SPC , NAV_ENT,   KC_BSPC , NAV_BSP, TD(TD_ALT_NAV)
                                      //`--------------------------'  `--------------------------'
  ),

  [_Q_SWE_SFT] = LAYOUT_split_3x6_3(
  //,-------------------------------------------------------------------------.                            ,----------------------------------------------------------------------------------.
        KC_TAB    ,LSFT(KC_Q),LSFT(KC_W),LSFT(KC_E),LSFT(KC_R),   LSFT(KC_T),                               RSFT(KC_Y),   RSFT(KC_U),   RSFT(KC_I),   RSFT(KC_O),   RSFT(KC_P),      KC_S_AO,
  //|-------------+----------+----------+----------+-------------+------------|                            |-------------+-------------+-------------+------------+-------------+-------------|
     LSFT(KC_LCTL),LSFT(KC_A),LSFT(KC_S),LSFT(KC_D),LSFT(KC_F),   LSFT(KC_G),                               RSFT(KC_H),   RSFT(KC_J),   RSFT(KC_K),   RSFT(KC_L),      KC_S_OO,      KC_S_AE,
  //|-------------+----------+----------+----------+-------------+------------|                            |-------------+-------------+-------------+------------+-------------+-------------|
        KC_LSFT   ,LSFT(KC_Z),LSFT(KC_X),LSFT(KC_C),LSFT(KC_V),   LSFT(KC_B),                               RSFT(KC_N),   RSFT(KC_M),   RSFT(KC_COMM),RSFT(KC_DOT),RSFT(KC_SLSH),RSFT(KC_BSLS),
  //|-------------+----------+----------+----------+-------------+------------+------------|  |------------+-------------+-------------+-------------+------------+-------------+-------------|
                                                    LSFT(KC_LCTL),LSFT(KC_SPC),LSFT(KC_ENT),   KC_DEL      ,RSFT(KC_BSPC),RSFT(KC_RALT)
                                                 //`---------------------------------------'  `----------------------------------------'
  ),

  [_COLEMAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_EQL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       LC_ESC,    KC_A,    KC_R,    KC_S,    KC_T,   SYM_G,                        SYM_M,    KC_N,    KC_E,    KC_I, KC_O   , RC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, RS_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                  TD(TD_GUI_SYM) , KC_SPC , NAV_ENT,   KC_BSPC , NAV_BSP, TD(TD_ALT_NAV)
                                      //`--------------------------'  `--------------------------'

  ),

  [_C_SWE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,------------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,   KC_OO,  KC_AO  ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------|
       LC_ESC,    KC_A,    KC_R,    KC_S,    KC_T,   SYM_G,                        SYM_M,    KC_N,    KC_E,    KC_I,  KC_O  , KC_AE   ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------|
    C_SWE_SFT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,C_SWE_BSL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+---------|
                                  TD(TD_GUI_SYM) , KC_SPC , NAV_ENT,   KC_BSPC , NAV_BSP, TD(TD_ALT_NAV)
                                      //`--------------------------'  `--------------------------'
  ),

  [_C_SWE_SFT] = LAYOUT_split_3x6_3(
  //,-------------------------------------------------------------------------.                            ,----------------------------------------------------------------------------------.
        KC_TAB    ,LSFT(KC_Q),LSFT(KC_W),LSFT(KC_F),LSFT(KC_P),   LSFT(KC_B),                               RSFT(KC_J),   RSFT(KC_L),   RSFT(KC_U),   RSFT(KC_Y),       KC_S_OO ,      KC_S_AO,
  //|-------------+----------+----------+----------+-------------+------------|                            |-------------+-------------+-------------+------------+-------------+-------------|
     LSFT(KC_LCTL),LSFT(KC_A),LSFT(KC_R),LSFT(KC_S),LSFT(KC_T),   LSFT(KC_G),                               RSFT(KC_M),   RSFT(KC_N),   RSFT(KC_E),   RSFT(KC_I),   RSFT(KC_O)  ,      KC_S_AE,
  //|-------------+----------+----------+----------+-------------+------------|                            |-------------+-------------+-------------+------------+-------------+-------------|
        KC_LSFT   ,LSFT(KC_Z),LSFT(KC_X),LSFT(KC_C),LSFT(KC_D),   LSFT(KC_V),                               RSFT(KC_K),   RSFT(KC_H),   RSFT(KC_COMM),RSFT(KC_DOT),RSFT(KC_SLSH),RSFT(KC_BSLS),
  //|-------------+----------+----------+----------+-------------+------------+------------|  |------------+-------------+-------------+-------------+------------+-------------+-------------|
                                                    LSFT(KC_LGUI),LSFT(KC_SPC),LSFT(KC_ENT),  KC_DEL       ,RSFT(KC_BSPC),RSFT(KC_RALT)
                                                 //`---------------------------------------'  `----------------------------------------'
  ),

  [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_GRV  ,KC_EXLM ,KC_AT   ,KC_LCBR ,KC_RCBR ,KC_PAST ,                     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 TD(TD_C_SYM),KC_AMPR ,KC_DLR  ,KC_LBRC ,KC_RBRC ,KC_HASH ,                     KC_HOME ,KC_4    ,KC_5    ,KC_6    ,KC_PPLS , RC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT ,KC_PIPE ,KC_CIRC ,KC_LPRN ,KC_RPRN ,KC_PERC ,                     KC_END  ,KC_1    ,KC_2    ,KC_3    ,KC_EQL  , RS_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_LGUI ,KC_SPC  , FUN_L  ,    FUN_L  , KC_0  , KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KILL_P ,LSG(KC_F12),KC_WH_L,KC_MS_U,KC_WH_R,LAG(KC_B),            G(KC_LBRC),S(C(KC_TAB)),C(KC_TAB),G(KC_RBRC), KC_NO , KC_NO  ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 TD(TD_C_NAV), KC_NO  ,KC_MS_L ,KC_MS_D ,KC_MS_R ,A(KC_F7),                      KC_LEFT,KC_DOWN ,KC_UP   ,KC_RGHT , KC_NO  , KC_NO  ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_NO  ,KC_BTN2 ,KC_WH_D ,KC_WH_U ,S(KC_F6),                      KC_NO  ,KC_BTN1 ,KC_ACL0 ,KC_ACL1 ,KC_ACL2 , KC_NO  ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_LGUI , KC_SPC , KC_ENT ,   KC_BSPC ,KC_BSPC , KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [_FUN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                      KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LC_ESC , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_F11 ,                      KC_F12 , UC_M_WC, UC_M_MA, UC_M_LN, KC_NO  , RC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, C_SWE_T, COL_T  ,                      QWE_T  , Q_SWE_T, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_LGUI , KC_SPC , KC_ENT ,    KC_DEL , KC_BSPC, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )

};
