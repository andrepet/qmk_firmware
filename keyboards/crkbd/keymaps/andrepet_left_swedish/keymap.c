/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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
#include "keymap_swedish.h" // left-half master
#include <process_key_override.h>

enum corne_layers {
  _COLEMAK,
  _QWERTY,
  _NUM,
  _NAV,
  _FUN,
  _SYM,
  _MOUSE
};

// Shortcut to make keymap more readable
#define COL_T TO(_COLEMAK)
#define QWE_T TO(_QWERTY)

#define SYM_BSPC LT(_SYM,KC_BSPC)
#define SYM_0 LT(_SYM,SE_0)
#define NUM_SPC	LT(_NUM,KC_SPC)
#define NAV_SPC LT(_NAV,KC_SPC)
#define NUM_ENT LT(_NUM,KC_ENT)
#define MOUSE_DEL LT(_MOUSE,KC_DEL)
#define NAV_MIN LT(_NAV,SE_MINS)
#define FUN_TAB LT(_FUN,KC_TAB)

// Right-hand home block mods (windows standard)
#define CTL_AE RCTL_T(SE_ADIA) // colemak / qwerty
#define SFT_QO RSFT_T(SE_QUOT) // colemak / qwerty
#define ALT_AO LALT_T(SE_ARNG) // colemak / qwerty
#define GUI_SL LGUI_T(KC_PSLS) // colemak / qwerty

// Right-hand mouse layer home block mods
#define SHF_DWN RSFT_T(KC_DOWN)
#define CTL_UP  RCTL_T(KC_UP)
#define ALT_RG  LALT_T(KC_RGHT)

// Left-hand home block mods (windows standard)
#define LC_ESC  LCTL_T(KC_ESC)     // colemak / qwerty
#define ALT_TCK LALT_T(SE_GRV)     // colemak
#define ALT_TAB LALT_T(KC_TAB)     // windows
#define GUI_Z   LGUI_T(KC_Z)       // colemak / qwerty

// one shot modifiers
#define OS_GUI OSM(MOD_LGUI)
#define OS_ALT OSM(MOD_LALT)
#define OS_CTL OSM(MOD_LCTL)
#define OS_SHF OSM(MOD_LSFT)

// Key Overrides
const key_override_t semicolon_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_SCLN, SE_COLN);
const key_override_t comma_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, SE_LABK);
const key_override_t dot_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_DOT, SE_RABK);
const key_override_t slash_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_PSLS, SE_QUES);
const key_override_t plus_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_PLUS, SE_EQL);
const key_override_t quot_key_override = ko_make_basic(MOD_MASK_SHIFT, SFT_QO, SE_DQUO);
const key_override_t pipe_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_PIPE, SE_BSLS);
const key_override_t dlr_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_DLR, SE_EURO);
const key_override_t at_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_AT, SE_PND);
// These two are needed to get same bracket shift behaviour as macos
const key_override_t se_lbrc_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_LBRC, SE_LCBR);
const key_override_t se_rbrc_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_RBRC, SE_RCBR);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &semicolon_key_override,
    &comma_key_override,
    &dot_key_override,
    &slash_key_override,
    &plus_key_override,
    &quot_key_override,
    &pipe_key_override,
    &dlr_key_override,
    &at_key_override,
    &se_lbrc_key_override,
    &se_rbrc_key_override
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     SE_GRV  ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B    ,                     KC_J    ,KC_L    ,KC_U    ,KC_Y    ,SE_ODIA ,ALT_AO  ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     LC_ESC  ,KC_A    ,KC_R    ,KC_S    ,KC_T    ,KC_G    ,                     KC_M    ,KC_N    ,KC_E    ,KC_I    ,KC_O    ,CTL_AE  ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT ,GUI_Z   ,KC_X    ,KC_C    ,KC_D    ,KC_V   ,                      KC_K    ,KC_H    ,SE_COMM ,SE_DOT  ,KC_PSLS ,SFT_QO  ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         FUN_TAB ,NAV_SPC ,NUM_ENT ,  MOUSE_DEL,SYM_BSPC,MO(_NAV)
                                      //`--------------------------'  `--------------------------'
  ),

  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     ALT_TAB ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,                     KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,ALT_AO  ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     LC_ESC  ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,                     KC_H    ,KC_J    ,KC_K    ,KC_L    ,SE_ODIA ,CTL_AE  ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT ,GUI_Z   ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,                     KC_N    ,KC_M    ,SE_COMM ,SE_DOT  ,KC_PSLS ,SFT_QO  ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         FUN_TAB ,KC_SPC ,NUM_ENT  ,  MOUSE_DEL,SYM_BSPC,MO(_NAV)
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_TAB  ,SE_1    ,SE_2    ,SE_3    ,SE_4    ,SE_5    ,                     SE_6    ,SE_7    ,SE_8    ,SE_9    ,SE_0    ,SE_MINS ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     TG(_NUM),KC_LGUI ,KC_LALT ,KC_LCTL ,KC_LSFT ,KC_MEH  ,                     SE_COMM ,SE_4    ,SE_5    ,SE_6    ,SE_SCLN ,SE_PLUS ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT ,C(KC_Z) ,C(KC_X) ,C(KC_C) ,C(KC_D) ,KC_HYPR ,                     SE_DOT  ,SE_1    ,SE_2    ,SE_3    ,KC_PSLS ,SE_ASTR ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         MO(_FUN),NAV_SPC ,KC_ENT  ,   SE_EQL  ,SYM_0   ,NAV_MIN
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_TAB  ,SE_EXLM ,SE_AT   ,C(KC_F) ,C(KC_P) ,A(C(KC_B)),                   KC_HOME ,KC_PGDN ,KC_PGUP ,KC_END  ,SE_ACUT ,SE_MINS ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LCTL ,OS_GUI  ,OS_ALT  ,OS_CTL  ,OS_SHF  ,C(KC_T) ,                     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,SE_SCLN ,SE_PLUS ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT ,C(KC_Z) ,C(KC_X) ,C(KC_C) ,C(KC_D) ,C(KC_V) ,                     XXXXXXX ,KC_VOLD ,KC_VOLU ,XXXXXXX ,SE_COLN ,SE_DQUO ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_CAPS,TG(_MOUSE),TG(_NUM),   SE_EQL  ,SE_UNDS ,SE_MINS
                                      //`--------------------------'  `--------------------------'
  ),


  [_FUN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     DM_RSTP ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,RGB_TOG ,                     KC_F12  ,KC_F7   ,KC_F8   ,KC_F9   ,SE_ACUT ,SE_MINS ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     DM_REC1 ,KC_LGUI ,KC_LALT ,KC_LCTL ,KC_LSFT ,COL_T   ,                     KC_F11  ,KC_F4   ,KC_F5   ,KC_F6   ,SE_SCLN ,SE_PLUS ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     DM_PLY1 ,RGB_HUI ,RGB_SAI ,RGB_VAI ,RGB_MOD ,QWE_T   ,                     KC_F10  ,KC_F1   ,KC_F2   ,KC_F3   ,KC_PSLS ,SE_DQUO ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX ,XXXXXXX ,XXXXXXX ,   KC_DEL  ,KC_BSPC ,KC_CAPS
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
SE_TILD,SE_EXLM,ALGR(SE_AT),ALGR(SE_LBRC),ALGR(SE_RBRC),SE_HASH,                XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     SE_DIAE ,SE_AMPR,ALGR(SE_DLR),SE_LPRN ,SE_RPRN ,SE_PERC,                   XXXXXXX ,OS_SHF  ,OS_CTL  ,OS_ALT  ,OS_GUI  ,KC_RCTL ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     SE_BSLS,ALGR(SE_LABK),SE_CIRC,SE_LABK,SE_RABK,SE_ASTR,                     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_RSFT ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_TAB  ,KC_SPC  ,KC_ENT  ,   XXXXXXX ,XXXXXXX ,XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_MOUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_TAB  ,XXXXXXX ,XXXXXXX ,KC_MS_U ,XXXXXXX ,KC_WH_U ,                S(C(KC_TAB)), A(KC_LEFT),A(KC_RGHT),C(KC_TAB),XXXXXXX ,XXXXXXX ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   TG(_MOUSE),KC_WH_L ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_R ,                     KC_LEFT ,SHF_DWN ,CTL_UP  ,ALT_RG  ,KC_LGUI ,KC_RCTL ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_WH_D ,                     KC_BTN3 ,KC_BTN1 ,KC_BTN2 ,KC_ACL0 ,KC_ACL1 ,KC_ACL2 ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_BTN3 ,KC_BTN1 ,KC_BTN2 ,   XXXXXXX ,XXXXXXX ,XXXXXXX
                                      //`--------------------------'  `--------------------------
  )

};
