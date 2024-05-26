#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

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

enum redox_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  NAV,
  NUM,
  FUN,
  SYM,
  MOUSE,
  OPT
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

// Right-hand home row mods (mac standarc)
#define SFT_N RSFT_T(KC_N) // colemak
#define GUI_E RGUI_T(KC_E) // colemak
#define ALT_I LALT_T(KC_I) // colemak
#define CTL_O RCTL_T(KC_O) // colemak
#define SFT_J RSFT_T(KC_J) // qwerty
#define GUI_K RGUI_T(KC_K) // qwerty
#define ALT_L LALT_T(KC_L) // qwerty
#define CTL_OO RCTL_T(SE_ODIA) // qwerty


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
	   SE_TILD ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,SE_MINS ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   KC_TAB  ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B    ,KC_PGDN ,                          KC_PGUP ,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,SE_ODIA ,SE_ARNG ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   LC_ESC  ,CTL_A   ,ALT_R   ,GUI_S   ,SHFT_T  ,KC_G    ,KC_HOME ,                          KC_END  ,KC_M    ,SFT_N   ,GUI_E   ,ALT_I   ,CTL_O   ,SE_ADIA ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_D    ,KC_V    ,COL_T   ,QWE_T   ,        QWE_T   ,COL_T   ,KC_K    ,KC_H    ,SE_COMM ,SE_DOT  ,SE_SCLN ,RS_QUOT ,
	//├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
	   OPT_L   ,KC_LCTL ,KC_LALT ,KC_LGUI      ,NAV_SPC     ,NUM_SPC ,FUN_ENT ,       MOUSE_DEL,SYM_BSPC    ,SYM_BSPC     ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT
	//└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

	[_QWERTY] = LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
	   SE_TILD ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,SE_MINS ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_PGDN ,                          KC_PGUP ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,SE_ARNG ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   LC_ESC  ,CTL_A   ,ALT_S   ,GUI_D   ,SFT_F   ,KC_G    ,KC_HOME ,                          KC_END  ,KC_H    ,SFT_J   ,GUI_K   ,ALT_L   ,CTL_OO  ,SE_ADIA ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,COL_T   ,QWE_T   ,        QWE_T   ,COL_T   ,KC_N    ,KC_M    ,SE_COMM ,SE_DOT  ,SE_SCLN ,RS_QUOT ,
	//├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
	   OPT_L   ,KC_LCTL ,KC_LALT ,KC_LGUI      ,NAV_SPC     ,NUM_SPC ,FUN_ENT ,       MOUSE_DEL,SYM_BSPC    ,SYM_BSPC     ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT
	//└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),


	[_NAV] = LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
	   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          KC_NO,G(SE_ODIA),S(C(KC_TAB)),C(KC_TAB),G(SE_ODIA),SE_ACUT,KC_NO,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       XXXXXXX ,KC_LCTL ,KC_LALT ,KC_LGUI ,KC_LSFT ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,SE_QUOT ,SE_PLUS ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   KC_LSFT ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,KC_HOME ,KC_PGDN ,KC_PGUP ,KC_END  ,KC_PSLS ,SE_MINS ,
	//├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
	   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        SE_PLUS ,SE_MINS     ,KC_BSPC      ,KC_MRWD ,KC_VOLD ,KC_VOLU ,KC_MFFD
	//└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

    [_NUM] = LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
	   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_P7   ,KC_P8   ,KC_P9   ,SE_ACUT ,XXXXXXX,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       XXXXXXX ,KC_LCTL ,KC_LALT ,KC_LGUI ,KC_LSFT ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_P4   ,KC_P5   ,KC_P6   ,SE_QUOT ,SE_PLUS ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   KC_LSFT ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_P1   ,KC_P2   ,KC_P3   ,KC_PSLS ,SE_MINS ,
	//├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
	   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        SE_PLUS ,SE_MINS     ,KC_P0        ,KC_MRWD ,KC_VOLD ,KC_VOLU ,KC_MFFD
	//└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

    [_FUN] = LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
	   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,KC_F12  ,KC_F7   ,KC_F8   ,KC_F9   ,SE_ACUT ,XXXXXXX,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       XXXXXXX ,KC_LCTL ,KC_LALT ,KC_LGUI ,KC_LSFT ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,KC_F11  ,KC_F4   ,KC_F5   ,KC_F6   ,SE_QUOT ,SE_PLUS ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   KC_LSFT ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,KC_F10  ,KC_F1   ,KC_F2   ,KC_F3   ,KC_PSLS ,SE_MINS ,
	//├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
	   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        SE_PLUS ,SE_MINS     ,KC_CAPS      ,KC_MRWD ,KC_VOLD ,KC_VOLU ,KC_MFFD
	//└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

	[_SYM] = LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
	   SE_TILD ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   SE_TILD ,SE_EXLM ,SE_AT ,S(SE_LBRC),S(SE_RBRC),SE_ASTR,XXXXXXX,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       XXXXXXX ,SE_AMPR ,SE_DLR  ,SE_LBRC ,SE_RBRC ,SE_HASH ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_LSFT ,KC_LGUI ,KC_LALT ,KC_LCTL ,XXXXXXX ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   XXXXXXX ,SE_LCBR ,SE_CIRC ,SE_LPRN ,SE_RPRN ,SE_PERC ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_RSFT ,
	//├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
	   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     KC_SPC  ,    KC_SPC  ,KC_ENT  ,        XXXXXXX ,XXXXXXX     ,XXXXXXX      ,KC_MRWD ,KC_VOLD ,KC_VOLU ,KC_MFFD
	//└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

    [_MOUSE] = LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
	   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   XXXXXXX ,XXXXXXX ,KC_WH_L ,KC_MS_U ,KC_WH_R ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_ESC  ,XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_LSFT ,KC_LGUI ,KC_LALT ,KC_LCTL ,XXXXXXX ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   XXXXXXX ,XXXXXXX ,KC_BTN2 ,KC_WH_D ,KC_WH_U ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_BTN1 ,KC_ACL0 ,KC_ACL1 ,KC_ACL2 ,KC_RSFT ,
	//├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
	   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     KC_SPC  ,    KC_BTN1 ,KC_BTN2 ,        XXXXXXX ,XXXXXXX     ,XXXXXXX      ,KC_MRWD ,KC_VOLD ,KC_VOLU ,KC_MFFD
	//└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

	[_OPT] = LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
	   RGB_TOG ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   RGB_MOD ,RGB_HUI ,RGB_SAI ,RGB_VAI ,KC_NO   ,KC_NO   ,KC_NO   ,                          KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,XXXXXXX ,XXXXXXX  ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   KC_ESC  ,RGB_HUD ,RGB_SAD ,RGB_VAD ,KC_NO   ,KC_NO   ,KC_F11  ,                          KC_F12  ,CG_SWAP ,CG_NORM ,KC_NO   ,KC_NO   ,XXXXXXX ,XXXXXXX ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   KC_LSFT ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_NO   ,KC_NO   ,        KC_NO   ,KC_NO   ,KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_RSFT ,
	//├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
	   KC_TRNS ,KC_LCTL ,KC_LALT ,KC_LGUI ,     KC_NO   ,    KC_NO   ,KC_NO   ,        KC_NO   ,KC_NO   ,    KC_NO   ,     KC_NO   ,KC_BRID ,KC_BRIU ,KC_NO
	//└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	)
};
