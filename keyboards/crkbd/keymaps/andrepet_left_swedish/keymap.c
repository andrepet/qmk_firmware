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
// #include "keymap_swedish_pro_mac_iso.h" // right-half master

enum corne_layers {
  _COLEMAK,
  _QWERTY,
  _NUM,
  _NAV,
  _TOG_NAV,
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
#define TOGNAV_ LT(_TOG_NAV,SE_MINS)
#define FUN_TAB LT(_FUN,KC_TAB)

// Left-hand home block mods (windows standard)
#define SHF_T LSFT_T(KC_T) // colemak
#define CTL_S LCTL_T(KC_S) // colemak
#define ALT_R LALT_T(KC_R) // colemak
#define GUI_A LGUI_T(KC_A) // colemak

// Left-hand home block mods extensions (windows standard)
#define MOD_W MT(MOD_LCTL | MOD_LGUI, KC_W) // control, gui
#define MOD_F LSA_T(KC_F) // shift, alt
#define MOD_G MEH_T(KC_G) // control, shift, alt
#define MOD_X LAG_T(KC_X) // alt, gui
#define MOD_C LCA_T(KC_C) // control, alt
#define MOD_D RCS_T(KC_D) // shift, control
#define MOD_V HYPR_T(KC_V) // left control, shift, alt, command

// Left-hand home block mods (windows standard) for short-commands
#define SHF_C_T LSFT_T(C(KC_T)) // colemak
#define CTL_C_S LCTL_T(C(KC_S)) // colemak
#define ALT_C_R LALT_T(C(KC_R)) // colemak
#define GUI_C_A LGUI_T(C(KC_A)) // colemak

// Right-hand home block mods (windows standard)
#define SFT_N RSFT_T(KC_N) // colemak
#define CTL_E RCTL_T(KC_E) // colemak
#define ALT_I LALT_T(KC_I) // colemak
#define GUI_O RGUI_T(KC_O) // colemak
#define SFT_J RSFT_T(KC_J) // qwerty
#define CTL_K RCTL_T(KC_K) // qwerty
#define ALT_L LALT_T(KC_L) // qwerty
#define GUI_OO RGUI_T(SE_ODIA) // qwerty
#define CTL_AE RCTL_T(SE_ADIA) // colemak / qwerty

// Right-hand home block mods extensions (windows standard)
#define MOD_U RSA_T(KC_U) // shift, alt
#define MOD_Y MT(MOD_RCTL | MOD_RGUI, KC_Y) // control, command
#define MOD_M MEH_T(KC_M) // control, shift, alt (MEH)
#define MOD_K HYPR_T(KC_K) // control, shift, alt, command (HYPES)
#define MOD_H RCS_T(KC_H) // shift, control
#define MOD_COMM LCA_T(SE_COMM) // control, alt
#define MOD_DOT RAG_T(SE_DOT) // alt, gui

// Right-hand mouse layer home block mods
#define SHF_DWN RSFT_T(KC_DOWN)
#define CTL_UP RCTL_T(KC_UP)
#define ALT_RG LALT_T(KC_RGHT)

// shift and control
#define RS_QUOT RSFT_T(SE_QUOT)
#define LC_ESC  LCTL_T(KC_ESC)

// Key Overrides
const key_override_t semicolon_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_SCLN, SE_COLN);
const key_override_t comma_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, SE_LABK);
const key_override_t dot_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_DOT, SE_RABK);
const key_override_t slash_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_PSLS, SE_QUES);
const key_override_t plus_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_PLUS, SE_EQL);
const key_override_t quot_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_QUOT, SE_DQUO);
const key_override_t shift_quot_key_override = ko_make_basic(MOD_MASK_SHIFT, RS_QUOT, SE_DQUO);
//const key_override_t pipe_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_PIPE, SE_BSLS);
const key_override_t dlr_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_DLR, SE_EURO);
const key_override_t pnd_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_PND, SE_MICR);
const key_override_t curr_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_CURR, SE_SECT);
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
    &shift_quot_key_override,
    //&pipe_key_override,
    &dlr_key_override,
    &pnd_key_override,
    &curr_key_override,
    &se_lbrc_key_override,
    &se_rbrc_key_override,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
   S(SE_ACUT),KC_Q    ,MOD_W   ,MOD_F   ,KC_P    ,KC_B    ,                     KC_J    ,KC_L    ,MOD_U   ,MOD_Y   ,SE_ODIA ,SE_ARNG ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     LC_ESC  ,GUI_A   ,ALT_R   ,CTL_S   ,SHF_T   ,MOD_G   ,                     MOD_M   ,SFT_N   ,CTL_E   ,ALT_I   ,GUI_O   ,CTL_AE  ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     SE_BSLS ,KC_Z    ,MOD_X   ,MOD_C   ,MOD_D   ,MOD_V   ,                     MOD_K   ,MOD_H   ,MOD_COMM,MOD_DOT ,KC_PSLS ,RS_QUOT ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         FUN_TAB ,NAV_SPC ,NUM_ENT ,  MOUSE_DEL,SYM_BSPC,MO(_TOG_NAV)
                                      //`--------------------------'  `--------------------------'
  ),

  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,                     KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,SE_ARNG ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     LC_ESC  ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,                     KC_H    ,SFT_J   ,CTL_K   ,ALT_L   ,GUI_OO  ,CTL_AE  ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,                     KC_N    ,KC_M    ,SE_COMM ,SE_DOT  ,KC_PSLS ,RS_QUOT ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         FUN_TAB ,KC_SPC ,NUM_ENT  ,  MOUSE_DEL,SYM_BSPC,MO(_TOG_NAV)
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_TAB  ,SE_1    ,SE_2    ,SE_3    ,SE_4    ,SE_5    ,                     SE_6    ,SE_7    ,SE_8    ,SE_9    ,SE_0    ,SE_MINS ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     TG(_NUM),KC_LGUI ,KC_LALT ,KC_LCTL ,KC_LSFT ,KC_MEH  ,                     SE_COMM ,SE_4    ,SE_5    ,SE_6    ,SE_SCLN ,SE_PLUS ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT ,C(KC_Z) ,C(KC_X) ,C(KC_C) ,C(KC_D) ,KC_HYPR ,                     SE_DOT  ,SE_1    ,SE_2    ,KC_3    ,SE_COLN ,SE_DQUO ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         MO(_FUN),NAV_SPC ,KC_ENT  ,   SE_EQL  ,SYM_0   ,TOGNAV_
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     XXXXXXX ,SE_EXLM ,SE_AT   ,C(KC_F) ,C(KC_P) ,A(C(KC_B)),                   KC_HOME ,KC_PGDN ,KC_PGUP ,KC_END  ,SE_ACUT ,SE_MINS ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX ,GUI_C_A ,ALT_C_R ,CTL_C_S ,SHF_C_T ,KC_MEH  ,                     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,SE_SCLN ,SE_PLUS ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT ,C(KC_Z) ,C(KC_X) ,C(KC_C) ,C(KC_D) ,C(KC_V) ,                     XXXXXXX ,KC_VOLD ,KC_VOLU ,XXXXXXX ,SE_COLN ,SE_DQUO ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX ,XXXXXXX ,XXXXXXX ,   SE_EQL  ,SE_UNDS ,SE_MINS
                                      //`--------------------------'  `--------------------------'
  ),


  [_FUN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     CG_SWAP ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                     KC_F12  ,KC_F7   ,KC_F8   ,KC_F9   ,SE_ACUT ,SE_MINS ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     CG_NORM ,KC_LGUI ,KC_LALT ,KC_LCTL ,KC_LSFT ,COL_T   ,                     KC_F11  ,KC_F4   ,KC_F5   ,KC_F6   ,SE_SCLN ,SE_PLUS ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     RGB_TOG ,RGB_HUI ,RGB_SAI ,RGB_VAI ,RGB_MOD ,QWE_T   ,                     KC_F10  ,KC_F1   ,KC_F2   ,KC_F3   ,SE_COLN ,SE_DQUO ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX ,XXXXXXX ,XXXXXXX ,   KC_DEL  ,KC_BSPC ,KC_CAPS
                                      //`--------------------------'  `--------------------------'
  ),

  [_TOG_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     SE_TILD ,SE_EXLM ,SE_AT   ,SE_LBRC ,SE_RBRC ,SE_HASH ,                     KC_HOME ,KC_PGDN ,KC_PGUP ,KC_END  ,XXXXXXX ,XXXXXXX ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     SE_PND  ,SE_AMPR ,SE_DLR  ,SE_LPRN ,SE_RPRN ,SE_PERC ,                     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,XXXXXXX ,XXXXXXX ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     SE_CURR ,SE_PIPE ,SE_CIRC ,SE_LABK ,SE_RABK ,SE_ASTR ,                     XXXXXXX ,KC_VOLD ,KC_VOLU ,XXXXXXX ,XXXXXXX ,KC_RSFT ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_CAPS,TG(_MOUSE),TG(_NUM),   XXXXXXX ,XXXXXXX ,XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     SE_TILD,SE_EXLM,ALGR(SE_AT),ALGR(SE_LBRC),ALGR(SE_RBRC),SE_HASH,                     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     SE_PND  ,SE_AMPR,ALGR(SE_DLR),SE_LPRN ,SE_RPRN ,SE_PERC,                     XXXXXXX ,KC_LSFT ,KC_LCTL ,KC_LALT ,KC_LGUI ,XXXXXXX ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     SE_CURR,ALGR(SE_LABK),SE_CIRC,SE_LABK,SE_RABK,SE_ASTR,                     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_RSFT ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_SPC  ,KC_SPC  ,KC_ENT  ,   XXXXXXX ,XXXXXXX ,XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_MOUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_TAB  ,XXXXXXX ,KC_WH_L ,KC_MS_U ,KC_WH_R ,XXXXXXX ,                G(KC_LEFT),S(C(KC_TAB)),C(KC_TAB),G(KC_RGHT),XXXXXXX ,XXXXXXX ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   TG(_MOUSE),XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,XXXXXXX ,                     KC_LEFT ,SHF_DWN ,CTL_UP  ,ALT_RG  ,KC_LGUI ,XXXXXXX ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX ,XXXXXXX ,KC_BTN2 ,KC_WH_D ,KC_WH_U ,XXXXXXX ,                     XXXXXXX ,KC_BTN1 ,KC_BTN2 ,KC_ACL0 ,KC_ACL1 ,KC_ACL2 ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_SPC  ,KC_BTN1 ,KC_BTN2 ,   XXXXXXX ,XXXXXXX ,XXXXXXX
                                      //`--------------------------'  `--------------------------
  )

};
