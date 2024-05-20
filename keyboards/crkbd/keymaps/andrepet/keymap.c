#include QMK_KEYBOARD_H
//#include "keymap_swedish.h" // left-half master
#include "keymap_swedish_pro_mac_iso.h" // right-half master

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

//enum unicode_keycodes {
//    AO,
//    AO_,
//    AE,
//    AE_,
//    OO,
//    OO_,
//    DLR,
//    EU,
//    PND,
//    YEN,
//    PIPE,
//    BSLSH,
//    ACUTE,
//    UMLAUT,
//    GRAVE,
//    TILDE
//};

//const uint32_t PROGMEM unicode_map[] = {
//    [AO]  = 0xE5, // å
//    [AO_] = 0xC5, // Å
//    [AE]  = 0xE4, // ä
//    [AE_] = 0xC4, // Ä
//    [OO]  = 0xF6, // ö
//    [OO_] = 0xD6, // Ö
//    [DLR] = 0x24, // $
//    [EU] = 0x20AC, // €
//    [PND] = 0xA3, // £
//    [YEN] = 0xA5, // ¥
//    [PIPE] = 0x7C, // |
//    [BSLSH] = 0x5C, /* \ */
//    [ACUTE] = 0x0301, // ́ (combine)
//    [UMLAUT] = 0x0308, // ̈ (combine)
//    [GRAVE] = 0x02CB, // ˋ
//    [TILDE] = 0x223C // ~
//};

//// unicode letters for åÅ, äÄ, öÖ
//#define U_AO XP(X(AO),X(AO_))
//#define U_AE XP(X(AE),X(AE_))
//#define U_OO XP(X(OO),X(OO_))

//// unicode signs
//#define U_DLR_EU XP(X(DLR), X(EU))
//#define U_PND_YEN XP(X(PND), X(YEN))
//#define U_PIPES XP(X(PIPE), X(BSLSH))
//#define U_BSLSH UC(BSLSH)
//#define U_ACCENT XP(X(ACUTE), X(UMLAUT))
//#define U_GRAVE XP(X(GRAVE), X(TILDE))

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

// Left-hand home block mods (mac standard)
#define SHF_T LSFT_T(KC_T) // colemak
#define COM_S LGUI_T(KC_S) // colemak
#define ALT_R LALT_T(KC_R) // colemak
#define CTL_A LCTL_T(KC_A) // colemak

// Left-hand home block mods extensions (mac standard)
#define MOD_W MT(MOD_LCTL | MOD_LGUI, KC_W) // control, command
#define MOD_F LSA_T(KC_F) // shift, alt
#define MOD_G MEH_T(KC_G) // control, shift, alt
#define MOD_X LCA_T(KC_X) // control, alt
#define MOD_C LAG_T(KC_C) // alt, command
#define MOD_D LSG_T(KC_D) // shift, command
#define MOD_V HYPR_T(KC_V) // left control, shift, alt, command

// Left-hand home block mods (mac standard) for short-commands
#define SHF_G_T LSFT_T(G(KC_T)) // colemak
#define COM_G_S LGUI_T(G(KC_S)) // colemak
#define ALT_G_R LALT_T(G(KC_R)) // colemak
#define CTL_G_A LCTL_T(G(KC_A)) // colemak

// Right-hand home block mods (mac standarc)
#define SFT_N RSFT_T(KC_N) // colemak
#define COM_E RGUI_T(KC_E) // colemak
#define ALT_I LALT_T(KC_I) // colemak
#define CTL_O RCTL_T(KC_O) // colemak
#define SFT_J RSFT_T(KC_J) // qwerty
#define COM_K RGUI_T(KC_K) // qwerty
#define ALT_L LALT_T(KC_L) // qwerty
#define CTL_OO RCTL_T(SE_ODIA) // qwerty
#define CTL_AE RCTL_T(SE_ADIA) // colemak / qwerty

// Right-hand home block mods extensions (mac standard)
#define MOD_U RSA_T(KC_U) // shift, alt
#define MOD_Y MT(MOD_RCTL | MOD_RGUI, KC_Y) // control, command
#define MOD_M MEH_T(KC_M) // control, shift, alt (MEH)
#define MOD_K HYPR_T(KC_K) // control, shift, alt, command (HYPES)
#define MOD_H RSG_T(KC_H) // shift, command
#define MOD_COMM RAG_T(SE_COMM) // alt, command
#define MOD_DOT LCA_T(SE_DOT) // control, alt

// Right-hand mouse layer home block mods
#define SHF_DWN RSFT_T(KC_DOWN)
#define COM_UP RGUI_T(KC_UP)
#define ALT_RG LALT_T(KC_RGHT)

// shift and control
#define RS_QUOT	 RSFT_T(SE_QUOT)
#define LC_ESC   LCTL_T(KC_ESC)

// Key Overrides
const key_override_t semicolon_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_SCLN, SE_COLN);
const key_override_t comma_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, SE_LABK);
const key_override_t dot_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_DOT, SE_RABK);
const key_override_t slash_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_PSLS, SE_QUES);
const key_override_t plus_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_PLUS, SE_EQL);
const key_override_t quot_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_QUOT, SE_DQUO);
const key_override_t shift_quot_key_override = ko_make_basic(MOD_MASK_SHIFT, RS_QUOT, SE_DQUO);
const key_override_t pipe_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_PIPE, SE_BSLS);
const key_override_t dlr_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_DLR, SE_EURO);
const key_override_t pnd_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_PND, SE_YEN);
const key_override_t iexl_key_override = ko_make_basic(MOD_MASK_SHIFT, SE_IEXL, SE_IQUE);

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
    NULL // Null terminate the array of overrides!
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_TAB  ,KC_Q    ,MOD_W   ,MOD_F   ,KC_P    ,KC_B    ,                     KC_J    ,KC_L    ,MOD_U   ,MOD_Y   ,SE_ODIA ,SE_ARNG ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     LC_ESC  ,CTL_A   ,ALT_R   ,COM_S   ,SHF_T   ,MOD_G   ,                     MOD_M   ,SFT_N   ,COM_E   ,ALT_I   ,CTL_O   ,CTL_AE  ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     SE_BSLS ,KC_Z    ,MOD_X   ,MOD_C   ,MOD_D   ,MOD_V   ,                     MOD_K   ,MOD_H   ,MOD_COMM,MOD_DOT ,KC_PSLS ,RS_QUOT ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         MO(_FUN),NAV_SPC ,NUM_ENT ,  MOUSE_DEL,SYM_BSPC,MO(_TOG_NAV)
                                      //`--------------------------'  `--------------------------'
  ),

  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,                     KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,SE_ARNG ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     LC_ESC  ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,                     KC_H    ,SFT_J   ,COM_K   ,ALT_L   ,CTL_OO  ,CTL_AE  ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,                     KC_N    ,KC_M    ,SE_COMM ,SE_DOT  ,KC_PSLS ,RS_QUOT ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         MO(_FUN),KC_SPC ,NUM_ENT  ,  MOUSE_DEL,SYM_BSPC,MO(_TOG_NAV)
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_TAB  ,SE_1    ,SE_2    ,SE_3    ,SE_4    ,SE_5    ,                     SE_6    ,SE_7    ,SE_8    ,SE_9    ,SE_0    ,SE_MINS ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     TG(_NUM),KC_LCTL ,KC_LALT ,KC_LGUI ,KC_LSFT ,KC_MEH  ,                     SE_COMM ,SE_4    ,SE_5    ,SE_6    ,SE_SCLN ,SE_PLUS ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT ,G(KC_Z) ,G(KC_X) ,G(KC_C) ,G(KC_D) ,KC_HYPR ,                     SE_DOT  ,SE_1    ,SE_2    ,KC_3    ,SE_COLN ,SE_DQUO ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         MO(_FUN),NAV_SPC ,KC_ENT  ,   SE_EQL  ,SYM_0   ,TOGNAV_
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     XXXXXXX ,SE_EXLM ,SE_AT   ,G(KC_F) ,G(KC_P) ,A(G(KC_B)),                   KC_HOME ,KC_PGDN ,KC_PGUP ,KC_END  ,SE_ACUT ,SE_MINS ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX ,CTL_G_A ,ALT_G_R ,COM_G_S ,SHF_G_T ,KC_MEH  ,                     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,SE_SCLN ,SE_PLUS ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT ,G(KC_Z) ,G(KC_X) ,G(KC_C) ,G(KC_D) ,G(KC_V) ,                     XXXXXXX ,KC_VOLD ,KC_VOLU ,XXXXXXX ,SE_COLN ,SE_DQUO ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX ,XXXXXXX ,XXXXXXX ,   SE_EQL  ,SE_UNDS ,SE_MINS
                                      //`--------------------------'  `--------------------------'
  ),


  [_FUN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     CG_SWAP ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                     KC_F12  ,KC_F7   ,KC_F8   ,KC_F9   ,SE_ACUT ,SE_MINS ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     CG_NORM ,KC_LCTL ,KC_LALT ,KC_LGUI ,KC_LSFT ,COL_T   ,                     KC_F11  ,KC_F4   ,KC_F5   ,KC_F6   ,SE_SCLN ,SE_PLUS ,
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
     SE_IEXL ,SE_PIPE ,SE_CIRC ,SE_LABK ,SE_RABK ,SE_ASTR ,                     XXXXXXX ,KC_VOLD ,KC_VOLU ,XXXXXXX ,XXXXXXX ,KC_RSFT ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        XXXXXXX,TG(_MOUSE),TG(_NUM),   XXXXXXX ,XXXXXXX ,XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     SE_TILD ,SE_EXLM ,SE_AT   ,SE_LBRC ,SE_RBRC ,SE_HASH ,                     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     SE_PND  ,SE_AMPR ,SE_DLR  ,SE_LPRN ,SE_RPRN ,SE_PERC ,                     XXXXXXX ,KC_LSFT ,KC_LGUI ,KC_LALT ,KC_LCTL ,XXXXXXX ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     SE_IEXL ,SE_PIPE ,SE_CIRC ,SE_LABK ,SE_RABK ,SE_ASTR ,                     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_RSFT ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_SPC  ,KC_SPC  ,KC_ENT  ,   XXXXXXX ,XXXXXXX ,XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_MOUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_TAB  ,XXXXXXX ,KC_WH_L ,KC_MS_U ,KC_WH_R ,XXXXXXX ,                G(KC_LEFT),S(C(KC_TAB)),C(KC_TAB),G(KC_RGHT),XXXXXXX ,XXXXXXX ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   TG(_MOUSE),XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,XXXXXXX ,                     KC_LEFT ,SHF_DWN ,COM_UP  ,ALT_RG  ,KC_RCTL ,XXXXXXX ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX ,XXXXXXX ,KC_BTN2 ,KC_WH_D ,KC_WH_U ,XXXXXXX ,                     XXXXXXX ,KC_BTN1 ,KC_BTN2 ,KC_ACL0 ,KC_ACL1 ,KC_ACL2 ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_SPC  ,KC_BTN1 ,KC_BTN2 ,   XXXXXXX ,XXXXXXX ,XXXXXXX
                                      //`--------------------------'  `--------------------------
  )

};
