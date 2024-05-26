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
// #include "keymap_swedish.h" // left-half master
#include "keymap_swedish_pro_mac_iso.h" // right-half master

enum redox_layers {
  _COLEMAK,
  _QWERTY,
  _NAV,
  _NUM,
  _FUN,
  _SYM,
  _MOUSE,
  _OPT
};

// Shortcut to make keymap more readable
#define COL_T	TO(_COLEMAK)
#define QWE_T	TO(_QWERTY)

#define NAV_SPC	LT(_NAV,KC_SPC)
#define NUM_SPC LT(_NUM,KC_SPC)
#define FUN_ENT LT(_FUN,KC_ENT)
#define SYM_BSPC LT(_SYM,KC_BSPC)
#define MOUSE_DEL LT(_MOUSE,KC_DEL)
#define OPT_BSPC LT(_OPT,KC_BSPC)
#define OPT_L  	MO(_OPT)

// Left-hand home row mods (mac standard)
#define SHFT_T LSFT_T(KC_T) // colemak
#define GUI_S LGUI_T(KC_S) // colemak
#define ALT_R LALT_T(KC_R) // colemak
#define CTL_A LCTL_T(KC_A) // colemak & qwerty
#define SFT_F LSFT_T(KC_F) // qwerty
#define GUI_D LGUI_T(KC_D) // qwerty
#define ALT_S LALT_T(KC_S) // qwerty

// Left-hand home block mods extensions (mac standard)
#define MOD_W MT(MOD_LCTL | MOD_LGUI, KC_W) // control, command
#define MOD_F LSA_T(KC_F) // shift, alt
#define MOD_X LCA_T(KC_X) // control, alt
#define MOD_C LAG_T(KC_C) // alt, command
#define MOD_D LSG_T(KC_D) // shift, command

// Left-hand home block mods (mac standard) for short-commands
#define SHF_G_T LSFT_T(G(KC_T)) // colemak
#define COM_G_S LGUI_T(G(KC_S)) // colemak
#define ALT_G_R LALT_T(G(KC_R)) // colemak
#define CTL_G_A LCTL_T(G(KC_A)) // colemak

// Right-hand home row mods (mac standarc)
#define SFT_N RSFT_T(KC_N) // colemak
#define GUI_E RGUI_T(KC_E) // colemak
#define ALT_I LALT_T(KC_I) // colemak
#define CTL_O RCTL_T(KC_O) // colemak
#define SFT_J RSFT_T(KC_J) // qwerty
#define GUI_K RGUI_T(KC_K) // qwerty
#define ALT_L LALT_T(KC_L) // qwerty
#define CTL_OO RCTL_T(SE_ODIA) // qwerty
#define CTL_AE RCTL_T(SE_ADIA) // colemak / qwerty

// Right-hand home block mods extensions (mac standard)
#define MOD_U RSA_T(KC_U) // shift, alt
#define MOD_Y MT(MOD_RCTL | MOD_RGUI, KC_Y) // control, command
#define MOD_H RSG_T(KC_H) // shift, command
#define MOD_COMM RAG_T(SE_COMM) // alt, command
#define MOD_DOT LCA_T(SE_DOT) // control, alt

// Right-hand mouse layer home block mods
#define SHF_DWN RSFT_T(KC_DOWN)
#define COM_UP RGUI_T(KC_UP)
#define ALT_RG LALT_T(KC_RGHT)

// shift and control
#define RS_QUOT	RSFT_T(SE_QUOT)
#define LC_ESC  LCTL_T(KC_ESC)

// Key Overrides
const key_override_t semicolon_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_SCLN, SE_COLN);
const key_override_t comma_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_COMM, KC_GRV);
const key_override_t dot_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_DOT, S(KC_GRV));
const key_override_t slash_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_PSLS, SE_QUES);
const key_override_t plus_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_PLUS, SE_EQL);
const key_override_t quot_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_QUOT, SE_DQUO);
const key_override_t shift_quot_key_override = ko_make_basic(MOD_MASK_SHIFT, RS_QUOT, SE_DQUO);
const key_override_t pipe_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_PIPE, SE_BSLS);
const key_override_t dlr_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_DLR, SE_EURO);
const key_override_t pnd_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_PND, SE_YEN);
const key_override_t iexl_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_IEXL, SE_IQUE);

// Key Overrides - top row digits right hand side
const key_override_t digit_6_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_6, SE_CIRC);
const key_override_t digit_7_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_7, SE_AMPR);
const key_override_t digit_8_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_8, SE_ASTR);
const key_override_t digit_9_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_9, SE_LPRN);
const key_override_t digit_0_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_0, SE_RPRN);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &semicolon_key_override,
    &comma_key_override,
    &dot_key_override,
    &slash_key_override,
    &plus_key_override,
    &quot_key_override,
    &shift_quot_key_override,
    &pipe_key_override,
    &dlr_key_override,
    &pnd_key_override,
    &iexl_key_override,

    &digit_6_key_override,
    &digit_7_key_override,
    &digit_8_key_override,
    &digit_9_key_override,
    &digit_0_key_override,
    NULL // Null terminate the array of overrides!
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_COLEMAK] = LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
	   SE_TILD ,SE_1    ,SE_2    ,SE_3    ,SE_4    ,SE_5    ,                                            SE_6    ,SE_7    ,SE_8    ,SE_9    ,SE_0    ,SE_MINS ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   KC_TAB  ,KC_Q    ,MOD_W   ,MOD_F   ,KC_P    ,KC_B    ,KC_HYPR ,                          KC_HYPR ,KC_J    ,KC_L    ,MOD_U   ,MOD_Y   ,SE_ODIA ,SE_ARNG ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   LC_ESC  ,CTL_A   ,ALT_R   ,GUI_S   ,SHFT_T  ,KC_G    ,KC_MEH  ,                          KC_MEH  ,KC_M    ,SFT_N   ,GUI_E   ,ALT_I   ,CTL_O   ,CTL_AE  ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   KC_LSFT ,KC_Z    ,MOD_X   ,MOD_C   ,MOD_D   ,KC_V    ,KC_HOME ,KC_END  ,        KC_PGUP ,KC_PGDN ,KC_K    ,MOD_H   ,MOD_COMM,MOD_DOT ,KC_PSLS ,RS_QUOT ,
	//├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
	   OPT_L   ,KC_LCTL ,KC_LALT ,KC_LGUI      ,NAV_SPC     ,NUM_SPC ,FUN_ENT ,       MOUSE_DEL,SYM_BSPC    ,SYM_BSPC     ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT
	//└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

	[_QWERTY] = LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
	   SE_TILD ,SE_1    ,SE_2    ,SE_3    ,SE_4    ,SE_5    ,                                            SE_6    ,SE_7    ,SE_8    ,SE_9    ,SE_0    ,SE_MINS ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_HYPR ,                          KC_HYPR ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,SE_ARNG ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   LC_ESC  ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_MEH  ,                          KC_MEH  ,KC_H    ,SFT_J   ,GUI_K   ,ALT_L   ,CTL_OO  ,CTL_AE ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_HOME ,KC_END  ,        KC_PGUP ,KC_PGDN ,KC_N    ,KC_M    ,SE_COMM ,SE_DOT  ,KC_PSLS ,RS_QUOT ,
	//├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
	   OPT_L   ,KC_LCTL ,KC_LALT ,KC_LGUI      ,NAV_SPC     ,NUM_SPC ,FUN_ENT ,       MOUSE_DEL,SYM_BSPC    ,SYM_BSPC     ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT
	//└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),


	[_NAV] = LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
	   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   XXXXXXX ,SE_EXLM ,SE_AT  ,G(KC_F) ,G(KC_P) ,A(G(KC_B)),KC_HYPR,                          KC_HYPR,G(KC_LEFT),S(C(KC_TAB)),C(KC_TAB),G(KC_RGHT),SE_ACUT,SE_MINS,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       XXXXXXX ,CTL_G_A ,ALT_G_R ,COM_G_S ,SHF_G_T ,G(KC_F) ,KC_MEH  ,                          KC_MEH  ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,SE_SCLN ,SE_PLUS ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   KC_LSFT ,G(KC_Z) ,G(KC_X) ,G(KC_C) ,G(KC_D) ,G(KC_V) ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,KC_HOME ,KC_PGDN ,KC_PGUP ,KC_END  ,SE_COLN ,SE_DQUO ,
	//├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
	   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        SE_PLUS ,SE_MINS     ,KC_BSPC      ,KC_MRWD ,KC_VOLD ,KC_VOLU ,KC_MFFD
	//└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

    [_NUM] = LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
	   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_HYPR ,                          KC_HYPR ,XXXXXXX ,SE_7    ,SE_8    ,SE_9    ,SE_ACUT ,SE_MINS ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       XXXXXXX ,KC_LCTL ,KC_LALT ,KC_LGUI ,KC_LSFT ,XXXXXXX ,KC_MEH  ,                          KC_MEH  ,SE_COMM ,SE_4    ,SE_5    ,SE_6    ,SE_SCLN ,SE_PLUS ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   KC_LSFT ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,SE_DOT  ,SE_1    ,SE_2    ,SE_3    ,SE_COLN ,SE_DQUO ,
	//├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
	   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        SE_EQL  ,SE_MINS     ,SE_0         ,KC_MRWD ,KC_VOLD ,KC_VOLU ,KC_MFFD
	//└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

    [_FUN] = LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
	   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_HYPR ,                          KC_HYPR ,KC_F12  ,KC_F7   ,KC_F8   ,KC_F9   ,SE_ACUT ,SE_MINS ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       XXXXXXX ,KC_LCTL ,KC_LALT ,KC_LGUI ,KC_LSFT ,XXXXXXX ,KC_MEH  ,                          KC_MEH  ,KC_F11  ,KC_F4   ,KC_F5   ,KC_F6   ,SE_SCLN ,SE_PLUS ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   KC_LSFT ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,KC_F10  ,KC_F1   ,KC_F2   ,KC_F3   ,SE_COLN ,SE_DQUO ,
	//├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
	   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        SE_PLUS ,SE_MINS     ,KC_CAPS      ,KC_MRWD ,KC_VOLD ,KC_VOLU ,KC_MFFD
	//└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

	[_SYM] = LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
	   SE_TILD ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   SE_TILD ,SE_EXLM ,SE_AT   ,SE_LBRC ,SE_RBRC ,SE_HASH ,KC_HYPR,                           KC_HYPR ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       SE_PND  ,SE_AMPR ,SE_DLR  ,SE_LPRN ,SE_RPRN ,SE_PERC ,KC_MEH  ,                          KC_MEH  ,XXXXXXX ,KC_LSFT ,KC_LGUI ,KC_LALT ,KC_LCTL ,XXXXXXX ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   SE_IEXL ,SE_PIPE ,SE_CIRC ,SE_LABK ,SE_RABK ,SE_ASTR ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_RSFT ,
	//├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
	   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     KC_SPC  ,    KC_SPC  ,KC_ENT  ,        XXXXXXX ,XXXXXXX     ,XXXXXXX      ,KC_MRWD ,KC_VOLD ,KC_VOLU ,KC_MFFD
	//└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

    [_MOUSE] = LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
	   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   XXXXXXX ,XXXXXXX ,KC_WH_L ,KC_MS_U ,KC_WH_R ,XXXXXXX ,KC_HYPR ,                          KC_HYPR ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_ESC  ,XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,XXXXXXX ,KC_MEH  ,                          KC_MEH  ,KC_LEFT ,SHF_DWN ,COM_UP  ,ALT_RG  ,KC_RCTL ,XXXXXXX ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   XXXXXXX ,XXXXXXX ,KC_BTN2 ,KC_WH_D ,KC_WH_U ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_BTN1 ,KC_BTN2 ,KC_ACL0 ,KC_ACL1 ,KC_ACL2 ,
	//├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
	   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     KC_SPC  ,    KC_BTN1 ,KC_BTN2 ,        XXXXXXX ,XXXXXXX     ,XXXXXXX      ,KC_MRWD ,KC_VOLD ,KC_VOLU ,KC_MFFD
	//└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

	[_OPT] = LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
	   RGB_TOG ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   CG_SWAP ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,                          KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,XXXXXXX ,XXXXXXX  ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   CG_NORM ,KC_LCTL ,KC_LALT ,KC_LGUI ,KC_LSFT ,KC_NO   ,KC_F11  ,                          KC_F12  ,CG_SWAP ,CG_NORM ,KC_NO   ,KC_NO   ,XXXXXXX ,XXXXXXX ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   RGB_TOG ,RGB_HUI ,RGB_SAI ,RGB_VAI ,RGB_MOD ,KC_NO   ,COL_T   ,QWE_T   ,        QWE_T   ,COL_T   ,KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_RSFT ,
	//├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
	   KC_TRNS ,KC_LCTL ,KC_LALT ,KC_LGUI ,     KC_NO   ,    KC_NO   ,KC_NO   ,        KC_NO   ,KC_NO   ,    KC_NO   ,     KC_NO   ,KC_BRID ,KC_BRIU ,KC_NO
	//└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	)
};
