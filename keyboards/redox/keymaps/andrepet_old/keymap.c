#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _Q_SWE 1
#define _Q_SWE_SFT 2
#define _COLEMAK 3
#define _C_SWE 4
#define _C_SWE_SFT 5
#define _SYM 6
#define _NAV 7
#define _FUN 8

// Shortcut to make keymap more readable
#define QWE_T	TO(_QWERTY)
#define Q_SWE_T	TO(_Q_SWE)
#define Q_SWE_SFT	LT(_Q_SWE_SFT,KC_LSFT)
#define Q_SWE_BSL	LT(_Q_SWE_SFT,KC_BSLS)

#define COL_T	TO(_COLEMAK)
#define C_SWE_T	TO(_C_SWE)
#define C_SWE_SFT	LT(_C_SWE_SFT,KC_LSFT)
#define C_SWE_BSL	LT(_C_SWE_SFT,KC_BSLS)

#define FUN_L  	MO(_FUN)

#define SYM_GRV	LT(_SYM,KC_GRV)
#define SYM_MIN	LT(_SYM,KC_MINS)
#define SYM_HOM LT(_SYM,KC_HOME)
#define SYM_END LT(_SYM,KC_END)
#define NAV_ENT	LT(_NAV,KC_ENT)
#define NAV_DEL	LT(_NAV,KC_DEL)

// shift and control
#define LC_ESC  LCTL_T(KC_ESC)
#define RC_QUOT RCTL_T(KC_QUOT)
#define RS_BSLS	RSFT_T(KC_BSLS)
#define RGUI_BS	RGUI_T(KC_BSPC)

// swedish characters lower and uppercase
#define KC_AO	UC(0xE5)
#define KC_S_AO	UC(0xC5)
#define KC_OO	UC(0xF6)
#define KC_S_OO UC(0xD6)
#define KC_AE	UC(0xE4)
#define KC_S_AE UC(0xC4)

#define KILL_P LAG(KC_ESC)

// Tap Dance declarations
enum {
    TD_PGD_SYM,
    TD_PGU_NAV,
    TD_C_NAV,
    TD_C_SYM,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for page down, twice for toggle symbol layer
    [TD_PGD_SYM] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_PGDN, _SYM),
    // Tap once for page up, twice for toggle navigation layer
    [TD_PGU_NAV] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_PGUP, _NAV),
    // Tap/hold once for Ctrl, twice for toggle navigation layer
    [TD_C_NAV] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_LCTL, _NAV),
    // Tap/hold once for Ctrl, twice for toggle symbol layer
    [TD_C_SYM] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_LCTL, _SYM),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
	   SYM_GRV ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,SYM_MIN ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,TD(TD_PGD_SYM),              TD(TD_PGU_NAV),KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_EQL  ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   LC_ESC  ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,SYM_HOM ,                          SYM_END ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,RC_QUOT ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,C_SWE_T ,COL_T   ,        QWE_T   ,Q_SWE_T ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,RS_BSLS ,
	//├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
	   FUN_L   ,KC_LCTL ,KC_LALT ,KC_LGUI ,     KC_SPC  ,    KC_SPC  ,NAV_ENT ,        NAV_DEL ,KC_BSPC ,    RGUI_BS ,     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT
	//└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

	[_Q_SWE] = LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
	   SYM_GRV ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,SYM_MIN ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,TD(TD_PGD_SYM),              TD(TD_PGU_NAV),KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_AO   ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   LC_ESC  ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,SYM_HOM ,                          SYM_END ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_OO   ,KC_AE   ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   Q_SWE_SFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B  ,C_SWE_T ,COL_T   ,        QWE_T   ,Q_SWE_T ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,Q_SWE_BSL ,
	//├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
	   FUN_L   ,KC_LCTL ,KC_LALT ,KC_LGUI ,     KC_SPC  ,    KC_SPC  ,NAV_ENT ,        NAV_DEL ,KC_BSPC ,    RGUI_BS ,     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT
	//└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

	[_Q_SWE_SFT] = LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                                                ┌────────┬────────┬────────┬────────┬────────┬────────┐
	LSFT(KC_GRV),LSFT(KC_1),LSFT(KC_2),LSFT(KC_3),LSFT(KC_4),LSFT(KC_5),                               RSFT(KC_6),RSFT(KC_7),RSFT(KC_8),RSFT(KC_9),RSFT(KC_0),RSFT(KC_MINS),
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                              ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
LSFT(KC_TAB),LSFT(KC_Q),LSFT(KC_W),LSFT(KC_E),LSFT(KC_R),LSFT(KC_T),LSFT(KC_PGDN),             RSFT(KC_PGUP),RSFT(KC_Y),RSFT(KC_U),RSFT(KC_I),RSFT(KC_O),RSFT(KC_P),KC_S_AO,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                              ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
LSFT(KC_LCTL),LSFT(KC_A),LSFT(KC_S),LSFT(KC_D),LSFT(KC_F),LSFT(KC_G),LSFT(KC_HOME),              RSFT(KC_END),RSFT(KC_H),RSFT(KC_J),RSFT(KC_K),RSFT(KC_L),KC_S_OO,KC_S_AE,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐            ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
KC_LSFT,LSFT(KC_Z),LSFT(KC_X),LSFT(KC_C),LSFT(KC_V),LSFT(KC_B),C_SWE_T,COL_T  ,         QWE_T,Q_SWE_T,RSFT(KC_N),RSFT(KC_M),RSFT(KC_COMM),RSFT(KC_DOT),RSFT(KC_SLSH),RSFT(KC_BSLS),
	//├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤            ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
FUN_L,LSFT(KC_LCTL),LSFT(KC_LALT),LSFT(KC_LGUI),LSFT(KC_SPC),LSFT(KC_SPC),LSFT(KC_ENT),    RSFT(KC_DEL),RSFT(KC_BSPC),RSFT(KC_BSPC),RSFT(KC_LEFT),RSFT(KC_DOWN),RSFT(KC_UP),RSFT(KC_RGHT)
	//└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘            └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

	[_COLEMAK] = LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
	   SYM_GRV ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,SYM_MIN ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   KC_TAB  ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B    ,TD(TD_PGD_SYM),              TD(TD_PGU_NAV),KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN ,KC_EQL  ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   LC_ESC  ,KC_A    ,KC_R    ,KC_S    ,KC_T    ,KC_G    ,SYM_HOM ,                          SYM_END ,KC_M    ,KC_N    ,KC_E    ,KC_I    ,KC_O    ,RC_QUOT ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_D    ,KC_V    ,C_SWE_T ,COL_T   ,        QWE_T   ,Q_SWE_T ,KC_K    ,KC_H    ,KC_COMM ,KC_DOT  ,KC_SLSH ,RS_BSLS ,
	//├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
	   FUN_L   ,KC_LCTL ,KC_LALT ,KC_LGUI ,     KC_SPC  ,    KC_SPC  ,NAV_ENT ,        NAV_DEL ,KC_BSPC ,    RGUI_BS ,     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT
	//└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

	[_C_SWE] = LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
	   SYM_GRV ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,SYM_MIN ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   KC_TAB  ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B    ,TD(TD_PGD_SYM),              TD(TD_PGU_NAV),KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_OO   ,KC_AO   ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   LC_ESC  ,KC_A    ,KC_R    ,KC_S    ,KC_T    ,KC_G    ,SYM_HOM ,                          SYM_END ,KC_M    ,KC_N    ,KC_E    ,KC_I    ,KC_O    ,KC_AE   ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   C_SWE_SFT,KC_Z   ,KC_X    ,KC_C    ,KC_D    ,KC_V    ,C_SWE_T ,COL_T   ,        QWE_T   ,Q_SWE_T ,KC_K    ,KC_H    ,KC_COMM ,KC_DOT  ,KC_SLSH ,C_SWE_BSL ,
	//├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
	   FUN_L   ,KC_LCTL ,KC_LALT ,KC_LGUI ,     KC_SPC  ,    KC_SPC  ,NAV_ENT ,        NAV_DEL ,KC_BSPC ,    RGUI_BS ,     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT
	//└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

	[_C_SWE_SFT] = LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                                                ┌────────┬────────┬────────┬────────┬────────┬────────┐
	LSFT(KC_GRV),LSFT(KC_1),LSFT(KC_2),LSFT(KC_3),LSFT(KC_4),LSFT(KC_5),                               RSFT(KC_6),RSFT(KC_7),RSFT(KC_8),RSFT(KC_9),RSFT(KC_0),RSFT(KC_MINS),
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                              ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
LSFT(KC_TAB),LSFT(KC_Q),LSFT(KC_W),LSFT(KC_F),LSFT(KC_P),LSFT(KC_B),LSFT(KC_PGDN),             RSFT(KC_PGUP),RSFT(KC_J),RSFT(KC_L),RSFT(KC_U),RSFT(KC_Y),KC_S_OO,KC_S_AO,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                              ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
LSFT(KC_LCTL),LSFT(KC_A),LSFT(KC_R),LSFT(KC_S),LSFT(KC_T),LSFT(KC_G),LSFT(KC_HOME),              RSFT(KC_END),RSFT(KC_M),RSFT(KC_N),RSFT(KC_E),RSFT(KC_I),RSFT(KC_O),KC_S_AE,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐            ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
KC_LSFT,LSFT(KC_Z),LSFT(KC_X),LSFT(KC_C),LSFT(KC_D),LSFT(KC_V),C_SWE_T,COL_T  ,        QWE_T,Q_SWE_T,RSFT(KC_K),RSFT(KC_H),RSFT(KC_COMM),RSFT(KC_DOT),RSFT(KC_SLSH),RSFT(KC_BSLS),
	//├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤            ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
FUN_L,LSFT(KC_LCTL),LSFT(KC_LALT),LSFT(KC_LGUI),LSFT(KC_SPC),LSFT(KC_SPC),LSFT(KC_ENT),    RSFT(KC_DEL),RSFT(KC_BSPC),RSFT(KC_BSPC),RSFT(KC_LEFT),RSFT(KC_DOWN),RSFT(KC_UP),RSFT(KC_RGHT)
	//└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘            └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

	[_SYM] = LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
	   KC_GRV  ,KC_EXLM ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   KC_TAB  ,KC_QUES ,KC_AT   ,KC_LCBR ,KC_RCBR ,KC_PAST ,KC_NO   ,                          KC_NO   ,KC_UP   ,KC_P7   ,KC_P8   ,KC_P9   ,KC_PMNS ,KC_EQL  ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   TD(TD_C_SYM),KC_AMPR ,KC_DLR  ,KC_LBRC ,KC_RBRC ,KC_HASH ,KC_NO   ,                          KC_NO   ,KC_LEFT ,KC_P4   ,KC_P5   ,KC_P6   ,KC_PPLS ,KC_RGHT ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   KC_LSFT ,KC_PIPE ,KC_CIRC ,KC_LPRN ,KC_RPRN ,KC_PERC ,KC_NO   ,KC_NO   ,        KC_NO   ,KC_NO   ,KC_DOWN ,KC_P1   ,KC_P2   ,KC_P3   ,KC_EQL  ,RS_BSLS ,
	//├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
	   KC_TRNS ,KC_LCTL ,KC_LALT ,KC_LGUI ,     KC_SPC  ,    KC_SPC  ,NAV_ENT ,        NAV_DEL ,KC_BSPC ,    KC_P0   ,     KC_DOT  ,KC_COMM ,KC_LEFT ,KC_RGHT
	//└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

	[_NAV] = LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
	   KILL_P  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   KC_TAB  ,LSG(KC_F12),KC_WH_L,KC_MS_U,KC_WH_R,LAG(KC_B),KC_NO  ,                         KC_NO,G(KC_LBRC),S(C(KC_TAB)),C(KC_TAB),G(KC_RBRC),KC_NO,KC_EQL,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   TD(TD_C_NAV), KC_NO  ,KC_MS_L ,KC_MS_D ,KC_MS_R ,A(KC_F7),KC_NO   ,                          KC_NO   ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,KC_NO   ,RC_QUOT ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   KC_LSFT , KC_NO  ,KC_BTN2 ,KC_WH_D ,KC_WH_U ,S(KC_F6),KC_NO   ,KC_NO   ,        KC_NO   ,KC_NO   ,KC_NO   ,KC_BTN1 ,KC_ACL0 ,KC_ACL1 ,KC_ACL2 ,RS_BSLS ,
	//├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
	   KC_TRNS ,KC_LCTL ,KC_LALT ,KC_LGUI ,     KC_SPC  ,    KC_BTN1 ,KC_BTN2 ,        KC_DEL  ,KC_BSPC ,    KC_MPLY ,     KC_MRWD ,KC_VOLD ,KC_VOLU ,KC_MFFD
	//└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

	[_FUN] = LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
	   RGB_TOG ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_NO   ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   KC_NO   ,RGB_HUI ,RGB_SAI ,RGB_VAI ,KC_NO   ,KC_NO   ,KC_NO   ,                          KC_NO   ,UC_M_WC ,UC_M_MA ,UC_M_LN ,KC_NO   ,KC_SCLN ,KC_EQL  ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   LC_ESC  ,RGB_HUD ,RGB_SAD ,RGB_VAD ,KC_NO   ,KC_NO   ,KC_F11  ,                          KC_F12  ,CG_SWAP ,CG_NORM ,KC_NO   ,KC_NO   ,KC_SCLN ,RC_QUOT ,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
	   KC_LSFT ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_NO   ,KC_NO   ,        KC_NO   ,KC_NO   ,KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,RS_BSLS ,
	//├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
	   KC_TRNS ,KC_LCTL ,KC_LALT ,KC_LGUI ,     KC_NO   ,    KC_NO   ,KC_NO   ,        KC_NO   ,KC_NO   ,    KC_NO   ,     KC_NO   ,KC_BRID ,KC_BRIU ,KC_NO
	//└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	)
};
