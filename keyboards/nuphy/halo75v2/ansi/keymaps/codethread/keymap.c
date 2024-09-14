// Copyright 2024  Evgeny Kapusta (@ryodeushii)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "ansi.h"
#include "keycodes.h"
#include QMK_KEYBOARD_H

#define K_A LT(_NAV, KC_A)
#define K_S LALT_T(KC_S)
#define K_D LT(_NAV, KC_D)
#define K_F LT(_SYM, KC_F)

#define K_J LT(_SYM, KC_J)
#define K_K LCTL_T(KC_K)
#define K_L LALT_T(KC_L)
#define K_SEMI ALL_T(KC_SCLN)

#define SPACE LT(_SYM, KC_SPC)
#define ____ _______

enum layers {
    _MAC,
    _SYM,
    _GAME, // This layer is only available with the physical switch and must be layer 3
    _MOUSE,
    _NAV,
    _NUPHY,
    _NUPHY_2,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌────────────┬──────┬──────┬──────────┬────────────┬───────────┬─────────┬──────┬──────┬──────┬────────┬────────────┬──────┬──────────┬──────┬──────┐
//    │    esc     │ bRID │ bRIU │ MAC_TASK │ MAC_SEARCH │ MAC_VOICE │ MAC_DND │ mprv │ mply │ mnxt │  mute  │    vold    │ volu │ MAC_PRTA │ ins  │ del  │
//    ├────────────┼──────┼──────┼──────────┼────────────┼───────────┼─────────┼──────┼──────┼──────┼────────┼────────────┼──────┼──────────┼──────┼──────┤
//    │     `      │  1   │  2   │    3     │     4      │     5     │    6    │  7   │  8   │  9   │   0    │     -      │  =   │   bspc   │      │ home │
//    ├────────────┼──────┼──────┼──────────┼────────────┼───────────┼─────────┼──────┼──────┼──────┼────────┼────────────┼──────┼──────────┤      ├──────┤
//    │    tab     │  q   │  w   │    e     │     r      │     t     │    y    │  u   │  i   │  o   │   p    │     [      │  ]   │    \     │      │ end  │
//    ├────────────┼──────┼──────┼──────────┼────────────┼───────────┼─────────┼──────┼──────┼──────┼────────┼────────────┼──────┴──────────┤      ├──────┤
//    │     ^      │ K_A  │ K_S  │   K_D    │    K_F     │     g     │    h    │ K_J  │ K_K  │ K_L  │ K_SEMI │     '      │       ent       │      │ pgup │
//    ├────────────┼──────┼──────┼──────────┼────────────┼───────────┼─────────┼──────┼──────┼──────┼────────┼────────────┴──────┬──────────┼──────┼──────┤
//    │     󰘶      │  z   │  x   │    c     │     v      │     b     │    n    │  m   │  ,   │  .   │   /    │       rsft        │          │  up  │ pgdn │
//    ├────────────┼──────┼──────┼──────────┴────────────┴───────────┴─────────┴──────┴──────┴──────┼────────┼────────────┬──────┼──────────┼──────┼──────┤
//    │ MO(_MOUSE) │ lOPT │ lgui │                                󱁐                                 │  rgui  │ MO(_NUPHY) │      │   left   │ down │ rght │
//    └────────────┴──────┴──────┴──────────────────────────────────────────────────────────────────┴────────┴────────────┘      └──────────┴──────┴──────┘
[_MAC] = LAYOUT(
  KC_ESC     , KC_BRID , KC_BRIU , MAC_TASK , MAC_SEARCH , MAC_VOICE , MAC_DND , KC_MPRV , KC_MPLY , KC_MNXT , KC_MUTE , KC_VOLD    , KC_VOLU , MAC_PRTA , KC_INS  , KC_DEL  ,
  KC_GRV     , KC_1    , KC_2    , KC_3     , KC_4       , KC_5      , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_MINS    , KC_EQL  , KC_BSPC  ,           KC_HOME ,
  KC_TAB     , KC_Q    , KC_W    , KC_E     , KC_R       , KC_T      , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_LBRC    , KC_RBRC , KC_BSLS  ,           KC_END  ,
  KC_LCTL    , K_A     , K_S     , K_D      , K_F        , KC_G      , KC_H    , K_J     , K_K     , K_L     , K_SEMI  , KC_QUOT    ,       KC_ENT       ,           KC_PGUP ,
  KC_LSFT    , KC_Z    , KC_X    , KC_C     , KC_V       , KC_B      , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH ,       KC_RSFT        ,            KC_UP   , KC_PGDN ,
  MO(_MOUSE) , KC_LOPT , KC_LCMD ,                                   SPACE                                   , KC_RCMD , MO(_NUPHY) ,           KC_LEFT  , KC_DOWN , KC_RIGHT
),

//    ┌───┬───┬───┬───┬───┬───┬─────┬───┬───┬────┬───┬───┬───┬───┬───┬───┐
//    │   │   │   │   │   │   │     │   │   │    │   │   │   │   │   │   │
//    ├───┼───┼───┼───┼───┼───┼─────┼───┼───┼────┼───┼───┼───┼───┼───┼───┤
//    │   │   │   │   │   │   │     │   │   │    │   │   │   │   │   │   │
//    ├───┼───┼───┼───┼───┼───┼─────┼───┼───┼────┼───┼───┼───┼───┤   ├───┤
//    │   │   │ * │ _ │ % │ @ │ ../ │ [ │ ] │ $  │   │ [ │ ] │ \ │   │   │
//    ├───┼───┼───┼───┼───┼───┼─────┼───┼───┼────┼───┼───┼───┴───┤   ├───┤
//    │   │ ! │ = │ ( │ ) │ ~ │  -  │ { │ } │ => │ \ │ ' │  ent  │   │   │
//    ├───┼───┼───┼───┼───┼───┼─────┼───┼───┼────┼───┼───┴───┬───┼───┼───┤
//    │   │   │ ^ │ & │ + │   │     │ | │ ` │ #  │   │ rsft  │   │   │   │
//    ├───┼───┼───┼───┴───┴───┴─────┴───┴───┴────┼───┼───┬───┼───┼───┼───┤
//    │   │   │   │                              │   │   │   │   │   │   │
//    └───┴───┴───┴──────────────────────────────┴───┴───┘   └───┴───┴───┘
[_SYM] = LAYOUT(
  ____ , ____       , ____          , ____          , ____       , ____     , ____     , ____            , ____             , ____      , ____         , ____    , ____    , ____    , ____ , ____,
  ____ , ____       , ____          , ____          , ____       , ____     , ____     , ____            , ____             , ____      , ____         , ____    , ____    , ____    ,        ____,
  ____ , ____       , KC_ASTERISK   , KC_UNDERSCORE , KC_PERCENT , KC_AT    , UPDIR    , KC_LEFT_BRACKET , KC_RIGHT_BRACKET , KC_DOLLAR , ____         , KC_LBRC , KC_RBRC , KC_BSLS ,        ____,
  ____ , KC_EXCLAIM , KC_EQUAL      , KC_LPRN       , KC_RPRN    , KC_TILDE , KC_MINUS , KC_LCBR         , KC_RCBR          , ARROW     , KC_BACKSLASH , KC_QUOT ,      KC_ENT       ,        ____,
  ____ , ____       , KC_CIRCUMFLEX , KC_AMPR       , KC_PLUS    , ____     , ____     , KC_PIPE         , KC_GRAVE         , KC_HASH   , ____         ,      KC_RSFT      ,           ____ , ____,
  ____ , ____       , ____          ,                                               ____                                                , ____         , ____    ,           ____    , ____ , ____
),

//    ┌────────────┬────────────┬──────────┬────┬────┬────┬────┬────┬────┬────┬─────────┬────────────┬────┬─────────┬─────────┬──────────┐
//    │     no     │     no     │    no    │ no │ no │ no │ no │ no │ no │ no │   no    │     no     │ no │   no    │   no    │    no    │
//    ├────────────┼────────────┼──────────┼────┼────┼────┼────┼────┼────┼────┼─────────┼────────────┼────┼─────────┼─────────┼──────────┤
//    │     no     │     no     │    no    │ no │ no │ no │ no │ no │ no │ no │   no    │     no     │ no │   no    │         │    no    │
//    ├────────────┼────────────┼──────────┼────┼────┼────┼────┼────┼────┼────┼─────────┼────────────┼────┼─────────┤         ├──────────┤
//    │     no     │     no     │    no    │ no │ no │ no │ no │ no │ no │ no │   no    │     no     │ no │   no    │         │    no    │
//    ├────────────┼────────────┼──────────┼────┼────┼────┼────┼────┼────┼────┼─────────┼────────────┼────┴─────────┤         ├──────────┤
//    │     no     │     no     │    no    │ no │ no │ no │ no │ no │ no │ no │   no    │     no     │      no      │         │    no    │
//    ├────────────┼────────────┼──────────┼────┼────┼────┼────┼────┼────┼────┼─────────┼────────────┴────┬─────────┼─────────┼──────────┤
//    │     no     │     no     │    no    │ no │ no │ no │ no │ no │ no │ no │   no    │       no        │         │ RGB_VAI │    no    │
//    ├────────────┼────────────┼──────────┼────┴────┴────┴────┴────┴────┴────┼─────────┼────────────┬────┼─────────┼─────────┼──────────┤
//    │ SIDE_MOD_B │ SIDE_MOD_B │ SIDE_SPI │             SIDE_SPD             │ RGB_SPI │ SIDE_MOD_A │    │ RGB_MOD │ RGB_HUI │ SIDE_HUI │
//    └────────────┴────────────┴──────────┴──────────────────────────────────┴─────────┴────────────┘    └─────────┴─────────┴──────────┘
[_GAME] = LAYOUT(
  KC_NO      , KC_NO      , KC_NO    , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO   , KC_NO      , KC_NO , KC_NO   , KC_NO   , KC_NO   ,
  KC_NO      , KC_NO      , KC_NO    , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO   , KC_NO      , KC_NO , KC_NO   ,           KC_NO   ,
  KC_NO      , KC_NO      , KC_NO    , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO   , KC_NO      , KC_NO , KC_NO   ,           KC_NO   ,
  KC_NO      , KC_NO      , KC_NO    , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO   , KC_NO      ,      KC_NO      ,           KC_NO   ,
  KC_NO      , KC_NO      , KC_NO    , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO   ,       KC_NO        ,           RGB_VAI , KC_NO   ,
  SIDE_MOD_B , SIDE_MOD_B , SIDE_SPI ,                       SIDE_SPD                        , RGB_SPI , SIDE_MOD_A ,         RGB_MOD , RGB_HUI , SIDE_HUI
),

//    ┌─────┬────┬──────┬────┬────┬────┬──────┬──────┬──────┬──────┬──────┬──────┬─────┬──────────┬──────┬──────┐
//    │ esc │ f1 │  f2  │ f3 │ f4 │ f5 │  f6  │  f7  │  f8  │  f9  │ f10  │ f11  │ f12 │ WIN_PRTA │ ins  │ del  │
//    ├─────┼────┼──────┼────┼────┼────┼──────┼──────┼──────┼──────┼──────┼──────┼─────┼──────────┼──────┼──────┤
//    │  `  │ 1  │  2   │ 3  │ 4  │ 5  │  6   │  7   │  8   │  9   │  0   │  -   │  =  │   bspc   │      │ home │
//    ├─────┼────┼──────┼────┼────┼────┼──────┼──────┼──────┼──────┼──────┼──────┼─────┼──────────┤      ├──────┤
//    │ tab │ q  │  w   │ e  │ r  │ t  │ wh_u │ btn1 │ btn2 │ wh_d │  p   │  [   │  ]  │    \     │      │ end  │
//    ├─────┼────┼──────┼────┼────┼────┼──────┼──────┼──────┼──────┼──────┼──────┼─────┴──────────┤      ├──────┤
//    │  ^  │ a  │  s   │ d  │ f  │ g  │ ms_l │ ms_d │ ms_u │ ms_r │  ;   │  '   │      ent       │      │ pgup │
//    ├─────┼────┼──────┼────┼────┼────┼──────┼──────┼──────┼──────┼──────┼──────┴─────┬──────────┼──────┼──────┤
//    │  󰘶  │ z  │  x   │ c  │ v  │ b  │  n   │  m   │  ,   │  .   │  /   │    rsft    │          │  up  │ pgdn │
//    ├─────┼────┼──────┼────┴────┴────┴──────┴──────┴──────┴──────┼──────┼──────┬─────┼──────────┼──────┼──────┤
//    │     │ ⎇  │ lgui │                    󱁐                     │ ralt │ lgui │     │   left   │ down │ rght │
//    └─────┴────┴──────┴──────────────────────────────────────────┴──────┴──────┘     └──────────┴──────┴──────┘
[_MOUSE] = LAYOUT(
  KC_ESC  , KC_F1   , KC_F2   , KC_F3 , KC_F4 , KC_F5 , KC_F6       , KC_F7      , KC_F8    , KC_F9         , KC_F10  , KC_F11  , KC_F12  , WIN_PRTA , KC_INS  , KC_DEL  ,
  KC_GRV  , KC_1    , KC_2    , KC_3  , KC_4  , KC_5  , KC_6        , KC_7       , KC_8     , KC_9          , KC_0    , KC_MINS , KC_EQL  , KC_BSPC  ,           KC_HOME ,
  KC_TAB  , KC_Q    , KC_W    , KC_E  , KC_R  , KC_T  , KC_MS_WH_UP , KC_BTN1    , KC_BTN2  , KC_MS_WH_DOWN , KC_P    , KC_LBRC , KC_RBRC , KC_BSLS  ,           KC_END  ,
  KC_LCTL , KC_A    , KC_S    , KC_D  , KC_F  , KC_G  , KC_MS_LEFT  , KC_MS_DOWN , KC_MS_UP , KC_MS_RIGHT   , KC_SCLN , KC_QUOT ,       KC_ENT       ,           KC_PGUP ,
  KC_LSFT , KC_Z    , KC_X    , KC_C  , KC_V  , KC_B  , KC_N        , KC_M       , KC_COMM  , KC_DOT        , KC_SLSH ,      KC_RSFT      ,            KC_UP   , KC_PGDN ,
  ____    , KC_LALT , KC_LCMD ,                                   KC_SPC                                    , KC_RALT , KC_LWIN ,           KC_LEFT  , KC_DOWN , KC_RIGHT
),

//    ┌───┬───┬───┬───┬───┬───┬──────┬──────┬──────┬──────┬─────┬───┬───┬───┬───┬───┐
//    │   │   │   │   │   │   │      │      │      │      │     │   │   │   │   │   │
//    ├───┼───┼───┼───┼───┼───┼──────┼──────┼──────┼──────┼─────┼───┼───┼───┼───┼───┤
//    │   │   │   │   │   │   │      │      │      │      │     │   │   │   │   │   │
//    ├───┼───┼───┼───┼───┼───┼──────┼──────┼──────┼──────┼─────┼───┼───┼───┤   ├───┤
//    │   │   │   │   │   │   │      │      │      │      │     │   │   │   │   │   │
//    ├───┼───┼───┼───┼───┼───┼──────┼──────┼──────┼──────┼─────┼───┼───┴───┤   ├───┤
//    │   │ 󰘶 │ ⎇ │   │ 󰘳 │   │ left │ down │  up  │ rght │ ent │   │       │   │   │
//    ├───┼───┼───┼───┼───┼───┼──────┼──────┼──────┼──────┼─────┼───┴───┬───┼───┼───┤
//    │   │   │   │   │   │   │ G([) │ G({) │ G(}) │ G(]) │     │       │   │   │   │
//    ├───┼───┼───┼───┴───┴───┴──────┴──────┴──────┴──────┼─────┼───┬───┼───┼───┼───┤
//    │   │   │   │                 bspc                  │     │   │   │   │   │   │
//    └───┴───┴───┴───────────────────────────────────────┴─────┴───┘   └───┴───┴───┘
[_NAV] = LAYOUT(
  ____ , ____    , ____    , ____ , ____    , ____ , ____               , ____       , ____       , ____                , ____   , ____ , ____ , ____ , ____ , ____,
  ____ , ____    , ____    , ____ , ____    , ____ , ____               , ____       , ____       , ____                , ____   , ____ , ____ , ____ ,        ____,
  ____ , ____    , ____    , ____ , ____    , ____ , ____               , ____       , ____       , ____                , ____   , ____ , ____ , ____ ,        ____,
  ____ , KC_LSFT , KC_LALT , ____ , KC_LGUI , ____ , KC_LEFT            , KC_DOWN    , KC_UP      , KC_RIGHT            , KC_ENT , ____ ,    ____     ,        ____,
  ____ , ____    , ____    , ____ , ____    , ____ , G(KC_LEFT_BRACKET) , G(KC_LCBR) , G(KC_RCBR) , G(KC_RIGHT_BRACKET) , ____   ,    ____     ,        ____ , ____,
  ____ , ____    , ____    ,                                          KC_BSPC                                           , ____   , ____ ,        ____ , ____ , ____
),

//    ┌───────────────────┬────────────────────┬─────────────────────┬───────────────────────┬────┬────┬────┬────┬─────────┬─────────┬─────┬─────┬─────┬──────────┬─────────┬─────────┐
//    │      QK_BOOT      │         f1         │         f2          │          f3           │ f4 │ f5 │ f6 │ f7 │   f8    │   f9    │ f10 │ f11 │ f12 │ MAC_PRTA │   ins   │   del   │
//    ├───────────────────┼────────────────────┼─────────────────────┼───────────────────────┼────┼────┼────┼────┼─────────┼─────────┼─────┼─────┼─────┼──────────┼─────────┼─────────┤
//    │      LNK_RF       │      LNK_BLE1      │      LNK_BLE2       │       LNK_BLE3        │    │    │    │    │         │         │     │     │     │ BAT_SHOW │         │         │
//    ├───────────────────┼────────────────────┼─────────────────────┼───────────────────────┼────┼────┼────┼────┼─────────┼─────────┼─────┼─────┼─────┼──────────┤         ├─────────┤
//    │     RGB_TEST      │ SLEEP_TIMEOUT_SHOW │ DEBOUNCE_PRESS_SHOW │ DEBOUNCE_RELEASE_SHOW │    │    │    │    │         │         │     │     │     │          │         │         │
//    ├───────────────────┼────────────────────┼─────────────────────┼───────────────────────┼────┼────┼────┼────┼─────────┼─────────┼─────┼─────┼─────┴──────────┤         ├─────────┤
//    │   TOG_CAPS_IND    │ SLEEP_TIMEOUT_INC  │ DEBOUNCE_PRESS_INC  │ DEBOUNCE_RELEASE_INC  │    │    │    │    │         │         │     │     │                │         │         │
//    ├───────────────────┼────────────────────┼─────────────────────┼───────────────────────┼────┼────┼────┼────┼─────────┼─────────┼─────┼─────┴─────┬──────────┼─────────┼─────────┤
//    │ DEEP_SLEEP_TOGGLE │ SLEEP_TIMEOUT_DEC  │ DEBOUNCE_PRESS_DEC  │ DEBOUNCE_RELEASE_DEC  │    │    │    │    │ RGB_SPD │ RGB_SPI │     │           │          │ RGB_VAI │         │
//    ├───────────────────┼────────────────────┼─────────────────────┼───────────────────────┴────┴────┴────┴────┴─────────┴─────────┼─────┼─────┬─────┼──────────┼─────────┼─────────┤
//    │                   │     SLEEP_MODE     │  DEEP_SLEEP_TOGGLE  │                         MO(_NUPHY_2)                          │     │     │     │ RGB_MOD  │ RGB_VAD │ RGB_HUI │
//    └───────────────────┴────────────────────┴─────────────────────┴───────────────────────────────────────────────────────────────┴─────┴─────┘     └──────────┴─────────┴─────────┘
[_NUPHY] = LAYOUT(
  QK_BOOT           , KC_F1              , KC_F2               , KC_F3                 , KC_F4 , KC_F5 , KC_F6 , KC_F7 , KC_F8   , KC_F9   , KC_F10 , KC_F11 , KC_F12 , MAC_PRTA , KC_INS  , KC_DEL ,
  LNK_RF            , LNK_BLE1           , LNK_BLE2            , LNK_BLE3              , ____  , ____  , ____  , ____  , ____    , ____    , ____   , ____   , ____   , BAT_SHOW ,           ____   ,
  RGB_TEST          , SLEEP_TIMEOUT_SHOW , DEBOUNCE_PRESS_SHOW , DEBOUNCE_RELEASE_SHOW , ____  , ____  , ____  , ____  , ____    , ____    , ____   , ____   , ____   , ____     ,           ____   ,
  TOG_CAPS_IND      , SLEEP_TIMEOUT_INC  , DEBOUNCE_PRESS_INC  , DEBOUNCE_RELEASE_INC  , ____  , ____  , ____  , ____  , ____    , ____    , ____   , ____   ,       ____        ,           ____   ,
  DEEP_SLEEP_TOGGLE , SLEEP_TIMEOUT_DEC  , DEBOUNCE_PRESS_DEC  , DEBOUNCE_RELEASE_DEC  , ____  , ____  , ____  , ____  , RGB_SPD , RGB_SPI , ____   ,      ____       ,            RGB_VAI , ____   ,
  ____              , SLEEP_MODE         , DEEP_SLEEP_TOGGLE   ,                               MO(_NUPHY_2)                                , ____   , ____   ,          RGB_MOD  , RGB_VAD , RGB_HUI
),

//    ┌──────────┬──────────┬──────────┬────────────┬───┬───┬───┬───┬───┬───┬───┬───┬───┬────────────┬──────────┬──────────┐
//    │ DEV_boot │          │          │            │   │   │   │   │   │   │   │   │   │            │          │          │
//    ├──────────┼──────────┼──────────┼────────────┼───┼───┼───┼───┼───┼───┼───┼───┼───┼────────────┼──────────┼──────────┤
//    │          │          │          │            │   │   │   │   │   │   │   │   │   │            │          │          │
//    ├──────────┼──────────┼──────────┼────────────┼───┼───┼───┼───┼───┼───┼───┼───┼───┼────────────┤          ├──────────┤
//    │          │          │          │            │   │   │   │   │   │   │   │   │   │            │          │          │
//    ├──────────┼──────────┼──────────┼────────────┼───┼───┼───┼───┼───┼───┼───┼───┼───┴────────────┤          ├──────────┤
//    │          │ SIDE_SPD │ SIDE_SPI │ SIDE_MOD_B │   │   │   │   │   │   │   │   │                │          │          │
//    ├──────────┼──────────┼──────────┼────────────┼───┼───┼───┼───┼───┼───┼───┼───┴───┬────────────┼──────────┼──────────┤
//    │          │          │          │            │   │   │   │   │   │   │   │       │            │ SIDE_VAI │          │
//    ├──────────┼──────────┼──────────┼────────────┴───┴───┴───┴───┴───┴───┼───┼───┬───┼────────────┼──────────┼──────────┤
//    │          │          │          │                                    │   │   │   │ SIDE_MOD_A │ SIDE_VAD │ SIDE_HUI │
//    └──────────┴──────────┴──────────┴────────────────────────────────────┴───┴───┘   └────────────┴──────────┴──────────┘
[_NUPHY_2] = LAYOUT(
  DEV_RESET , ____     , ____     , ____       , ____ , ____ , ____ , ____ , ____ , ____ , ____ , ____ , ____ , ____       , ____     , ____    ,
  ____      , ____     , ____     , ____       , ____ , ____ , ____ , ____ , ____ , ____ , ____ , ____ , ____ , ____       ,            ____    ,
  ____      , ____     , ____     , ____       , ____ , ____ , ____ , ____ , ____ , ____ , ____ , ____ , ____ , ____       ,            ____    ,
  ____      , SIDE_SPD , SIDE_SPI , SIDE_MOD_B , ____ , ____ , ____ , ____ , ____ , ____ , ____ , ____ ,       ____        ,            ____    ,
  ____      , ____     , ____     , ____       , ____ , ____ , ____ , ____ , ____ , ____ , ____ ,    ____     ,              SIDE_VAI , ____    ,
  ____      , ____     , ____     ,                         ____                         , ____ , ____ ,        SIDE_MOD_A , SIDE_VAD , SIDE_HUI
)
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Get current mod and one-shot mod states.
    const uint8_t mods         = get_mods();
    const uint8_t oneshot_mods = get_oneshot_mods();

    switch (keycode) {
        case UPDIR: // Types ../ to go up a directory on the shell.
            if (record->event.pressed) {
                SEND_STRING("../");
            }
            return false;

        case ARROW: // Arrow macro, types -> or =>.
            if (record->event.pressed) {
                if ((mods | oneshot_mods) & MOD_MASK_SHIFT) { // Is shift held?
                    // Temporarily delete shift.
                    del_oneshot_mods(MOD_MASK_SHIFT);
                    unregister_mods(MOD_MASK_SHIFT);
                    SEND_STRING("->");
                    register_mods(mods); // Restore mods.
                } else {
                    SEND_STRING("=>");
                }
            }
            return false;
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    // If you find that you frequently trigger the modifier of your mod-tap(s) by accident,
    // for example, that's a sign that your tapping term may be too low so tap DT_UP a few
    // times to increase the tapping term until that no longer happens. On the flip side,
    // if you get superfluous characters when you actually intended to momentarily activate
    // a layer, tap DT_DOWN to lower the tapping term.
    switch (keycode) {
        case K_A:
        case K_S:
        case K_D:
        case K_F:

        case K_J:
        case K_K:
        case K_L:
        case K_SEMI:

            // found 200 pretty good just dropping a little
            // found 220 almost perfect but hitting mods on works like useCallback, useState it seems (maybe i was tired)
            // found 240 almost perfect but hitting mods on test
            return 260;
        case SPACE:

            // 180 good, hitting chars a little bit when in the flow
            return 160;
        default:
            // default 200
            // 140 works well for most keys
            // 100,pretty darn tough, need to really tap that mofo
            return 140;
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    // this controls how pressing then holding a key works
    // for most keys i want this, e.g jj should move down lines till i release
    // however for space, as it's my mod key, i want the mod
    // this will disable the ability to enter space continually, pitty
    switch (keycode) {
        case SPACE:
            return 0;
        default:
            return 150;
    }
}

const uint16_t PROGMEM test_combo1[] = {K_K, K_L, COMBO_END};
combo_t                key_combos[]  = {
    COMBO(test_combo1, KC_BSPC),
};

/*
qmk:json:start
{
  "comment_preview": {
    "keymap_overrides": {
      "_______": " ",
      "____": " ",
      "UPDIR": "../",
      "ARROW": "=>",
      "KC_SPC": "󱁐",
      "SPACE": "󱁐",
      "KC_MEH": "MEH",
      "KC_HYPR": ""
    }
  }
}
qmk:json:end
*/
