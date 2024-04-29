#include QMK_KEYBOARD_H
//#include "keymap_swedish.h"
#include "keymap_swedish_pro_osx_iso.h"

enum corne_layers {
  _COLEMAK,
  _QWERTY,
  _NAV,
  _NUM,
  _SYM_NAV,
  _FUN,
  _SYM,
  _MOUSE
};

enum corne_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  NAV,
  NUM,
  SYM_NAV,
  FUN,
  SYM,
  MOUSE
};

// Shortcut to make keymap more readable
#define COL_T	TO(_COLEMAK)
#define QWE_T	TO(_QWERTY)

#define NUM_SPC	LT(_NUM,KC_SPC)
#define NAV_SPC LT(_NAV,KC_SPC)
#define FUN_ENT LT(_FUN,KC_ENT)
#define MOUSE_DEL LT(_MOUSE,KC_DEL)
#define SYMNAV_B LT(_SYM_NAV,KC_BSPC)
#define SYM_BSPC LT(_SYM,KC_BSPC)

// Left-hand home block mods (mac standard)
#define SHF_T LSFT_T(KC_T) // colemak
#define COM_S LGUI_T(KC_S) // colemak
#define ALT_R LALT_T(KC_R) // colemak
#define CTL_A LCTL_T(KC_A) // colemak

// Right-hand home block mods (mac standarc)
#define SFT_N RSFT_T(KC_N) // colemak
#define COM_E RGUI_T(KC_E) // colemak
#define ALT_I LALT_T(KC_I) // colemak
#define CTL_O RCTL_T(KC_O) // colemak
#define SFT_J RSFT_T(KC_J) // qwerty
#define COM_K RGUI_T(KC_K) // qwerty
#define ALT_L LALT_T(KC_L) // qwerty
#define CTL_OO RCTL_T(SE_ODIA) // qwerty

// shift and control
#define RS_QUOT	RSFT_T(SE_QUOT)
#define LC_ESC  LCTL_T(KC_ESC)

// Key Overrides
const key_override_t semicolon_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_SCLN, SE_COLN);
const key_override_t comma_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_COMM, SE_LABK);
const key_override_t dot_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_DOT, SE_RABK);
const key_override_t slash_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_PSLS, SE_QUES);
const key_override_t plus_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_PLUS, SE_EQL);
const key_override_t quot_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_QUOT, SE_DQUO);
const key_override_t shift_quot_key_override = ko_make_basic(MOD_MASK_SHIFT, RS_QUOT, SE_DQUO);
const key_override_t pipe_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_PIPE, SE_BSLS);
const key_override_t dlr_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_DLR, SE_EURO);
const key_override_t pnd_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_PND, SE_YEN);
const key_override_t iexl_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_IEXL, SE_IQUE);

// Key Overrides - top row digits right hand side
const key_override_t digit_6_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_6, SE_CIRC);
const key_override_t digit_7_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_7, SE_AMPR);
const key_override_t digit_8_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_8, SE_ASTR);
const key_override_t digit_9_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_9, SE_LPRN);
const key_override_t digit_0_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_0, SE_RPRN);

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

  [_COLEMAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_TAB  ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B    ,                     KC_J    ,KC_L    ,KC_U    ,KC_Y    ,SE_ODIA ,SE_ARNG ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     LC_ESC  ,CTL_A   ,ALT_R   ,COM_S   ,SHF_T   ,KC_G    ,                     KC_M    ,SFT_N   ,COM_E   ,ALT_I   ,CTL_O   ,SE_ADIA ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_D    ,KC_V    ,                     KC_K    ,KC_H    ,SE_COMM ,SE_DOT  ,SE_SCLN ,RS_QUOT ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         NUM_SPC ,NAV_SPC ,FUN_ENT ,  MOUSE_DEL,SYM_BSPC,SYMNAV_B
                                      //`--------------------------'  `--------------------------'
  ),

  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,                     KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,SE_ARNG ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     LC_ESC  ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,                     KC_H    ,SFT_J   ,COM_K   ,ALT_L   ,CTL_OO  ,SE_ADIA ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,                     KC_N    ,KC_M    ,SE_COMM ,SE_DOT  ,SE_SCLN ,RS_QUOT ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_SPC  ,KC_SPC ,FUN_ENT  ,  MOUSE_DEL,SYM_BSPC,SYMNAV_B
                                      //`--------------------------'  `--------------------------'

  ),

  [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                     KC_HOME ,KC_PGDN ,KC_PGUP ,KC_END  ,SE_ACUT ,XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX ,KC_LCTL ,KC_LALT ,KC_LGUI ,KC_LSFT ,XXXXXXX ,                     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,SE_QUOT ,SE_PLUS ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                     XXXXXXX ,KC_VOLD ,KC_VOLU ,XXXXXXX ,KC_PSLS ,SE_MINS ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX ,XXXXXXX ,XXXXXXX ,   SE_EQL  ,SE_UNDS ,KC_BSPC
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     XXXXXXX ,SE_1    ,SE_2    ,SE_3    ,SE_4    ,SE_5    ,                     SE_6    ,SE_7    ,SE_8    ,SE_9    ,SE_0    ,XXXXXXX ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX ,KC_LCTL ,KC_LALT ,KC_LGUI ,KC_LSFT ,XXXXXXX ,                     SE_4    ,SE_4    ,SE_5    ,SE_6    ,SE_QUOT ,SE_PLUS ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                     SE_1    ,SE_1    ,SE_2    ,SE_3    ,KC_PSLS ,SE_MINS ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX ,XXXXXXX ,XXXXXXX ,   KC_DEL  ,SE_0    ,KC_BSPC
                                      //`--------------------------'  `--------------------------'
  ),

  [_FUN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     CG_SWAP ,UC_M_WC ,UC_M_MA ,UC_M_LN ,XXXXXXX ,XXXXXXX ,                     KC_F12  ,KC_F7   ,KC_F8   ,KC_F9   ,SE_ACUT ,XXXXXXX ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     CG_NORM ,KC_LCTL ,KC_LALT ,KC_LGUI ,KC_LSFT ,COL_T   ,                     KC_F11  ,KC_F4   ,KC_F5   ,KC_F6   ,SE_QUOT ,SE_PLUS ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT ,KC_CAPS ,XXXXXXX ,XXXXXXX ,XXXXXXX ,QWE_T   ,                     KC_F10  ,KC_F1   ,KC_F2   ,KC_F3   ,KC_PSLS ,SE_MINS ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX ,XXXXXXX ,XXXXXXX ,   SE_EQL  ,SE_UNDS ,KC_BSPC
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYM_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     SE_TILD ,SE_EXLM ,SE_AT   ,SE_LBRC ,SE_RBRC ,SE_ASTR ,                     KC_HOME ,KC_PGDN ,KC_PGUP ,KC_END  ,XXXXXXX ,XXXXXXX ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     SE_PND  ,SE_AMPR ,SE_DLR  ,SE_LPRN ,SE_RPRN ,SE_HASH ,                     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,XXXXXXX ,XXXXXXX ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     SE_IEXL ,SE_PIPE ,SE_CIRC ,SE_LABK ,SE_RABK ,SE_PERC ,                     XXXXXXX ,KC_VOLD ,KC_VOLU ,XXXXXXX ,XXXXXXX ,KC_RSFT ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_SPC  ,KC_SPC  ,KC_ENT  ,   XXXXXXX ,XXXXXXX ,XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     SE_TILD ,SE_EXLM ,SE_AT   ,SE_LBRC ,SE_RBRC ,SE_ASTR ,                     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     SE_PND  ,SE_AMPR ,SE_DLR  ,SE_LPRN ,SE_RPRN ,SE_HASH ,                     XXXXXXX ,KC_LSFT ,KC_LGUI ,KC_LALT ,KC_LCTL ,XXXXXXX ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     SE_IEXL ,SE_PIPE ,SE_CIRC ,SE_LABK ,SE_RABK ,SE_PERC ,                     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_RSFT ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_SPC  ,KC_SPC  ,KC_ENT  ,   XXXXXXX ,XXXXXXX ,XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_MOUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     XXXXXXX ,XXXXXXX ,KC_WH_L ,KC_MS_U ,KC_WH_R ,XXXXXXX ,                G(SE_ODIA),S(C(KC_TAB)),C(KC_TAB),G(SE_ODIA),XXXXXXX ,XXXXXXX ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_ESC  ,XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,XXXXXXX ,                     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,XXXXXXX ,XXXXXXX ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX ,XXXXXXX ,KC_BTN2 ,KC_WH_D ,KC_WH_U ,XXXXXXX ,                     XXXXXXX ,KC_BTN1 ,KC_ACL0 ,KC_ACL1 ,KC_ACL2 ,KC_RSFT ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_SPC  ,KC_BTN1 ,KC_BTN2 ,   XXXXXXX ,XXXXXXX ,XXXXXXX
                                      //`--------------------------'  `--------------------------
  )

};
