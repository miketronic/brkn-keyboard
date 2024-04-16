// Copyright 2023 @miketronic -- Mike B <mxb540@gmail.com>
// SPDX-License-Identifier: GPL-2.0+

#include "miketronic.h"


enum combos {
  COMBO_Q,
  COMBO_B,
  COMBO_V,
  COMBO_P,
  COMBO_Z,
  COMBO_X,
  COMBO_J,
  COMBO_K,
  COMBO_QUES,
  COMBO_EXLM,
  COMBO_BSPC,
  COMBO_BSPC1,
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;
const uint16_t PROGMEM combo_q[]      = { TD_WESC, KC_F, COMBO_END };
const uint16_t PROGMEM combo_b[]      = { KC_F, GNUM, COMBO_END };
const uint16_t PROGMEM combo_v[]      = { AMACRO, KC_R, COMBO_END };
const uint16_t PROGMEM combo_p[]      = { KC_R, SSYM, COMBO_END };
const uint16_t PROGMEM combo_z[]      = { CFN, DCTRL, COMBO_END };
const uint16_t PROGMEM combo_x[]      = { DCTRL, TALT, COMBO_END };
const uint16_t PROGMEM combo_j[]      = { KC_M, KC_L, COMBO_END };
const uint16_t PROGMEM combo_k[]      = { KC_N, KC_E, COMBO_END };
const uint16_t PROGMEM combo_ques[]   = { TD_OCOM, TD_YDOT, COMBO_END };
const uint16_t PROGMEM combo_exlm[]   = { KC_E, KC_I, COMBO_END };
const uint16_t PROGMEM combo_bspc[]   = { GNUM, KC_M, COMBO_END };
const uint16_t PROGMEM combo_bspc1[]  = { KC_L, KC_U, COMBO_END };


combo_t key_combos[] = {
  [COMBO_Q]   = COMBO(combo_q, KC_Q),
  [COMBO_B]   = COMBO(combo_b, KC_B),
  [COMBO_V]   = COMBO(combo_v, KC_V),
  [COMBO_P]   = COMBO(combo_p, KC_P),
  [COMBO_Z]   = COMBO(combo_z, KC_Z),
  [COMBO_X]   = COMBO(combo_x, KC_X),
  [COMBO_J]   = COMBO(combo_j, KC_J),
  [COMBO_K]   = COMBO(combo_k, KC_K),
  [COMBO_QUES]   = COMBO(combo_ques, KC_QUES),
  [COMBO_EXLM]   = COMBO(combo_exlm, KC_EXLM),
  [COMBO_BSPC]   = COMBO(combo_bspc, KC_BSPC),
  [COMBO_BSPC1]   = COMBO(combo_bspc1, KC_BSPC)
};

//uint16_t get_combo_term(uint16_t index, combo_t *combo) {
//
//    switch (index) {
//        case COMBO_BSPC:
//            return 110;
//    }
//
//   return COMBO_TERM;
//
//}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /* ALPHA9
  * ┌──────┬──────┬──────┐          ┌──────┬──────┬──────┐
  * │ W    │ F    │ G    │          │ M    │ L    │ U    │
  * │     [Q]    [B] NUM │          │     [J]   [BSPC]   │
  * ├──────╆━━━━━━╅──────┤          ├──────╆━━━━━━╅──────┤
  * │ A    ┃ R    ┃ S    │          │ N    ┃ E    ┃ I    │
  * │MACRO[V]    [P] SYM │          │     [K]    [!]     │
  * ├──────╄━━━━━━╃──────┤          ├──────╄━━━━━━╃──────┤
  * │ C    │ D    │ T    │          │ H    │ O    │ Y    │
  * │ FN  [Z]    [X]     │          │MOUSE │tt , [?] tt .│
  * └──────┴──────┴───┬──┴───┐  ┌───┴──┬───┴──────┴──────┘
  *                   │ SPC  │  │ ENT  │
  *                   │ SHIFT│  │ SHIFT│
  *                   └──────┘  └──────┘
  *              Hold both shifts for CAPS WORD
  * 
  * W+F    = Q
  * F+G    = B
  * A+R    = V
  * R+S    = P
  * C+D    = Z
  * D+T    = X
  * M+L    = J
  * L+U    = Backspace
  * N+E    = K
  * E+I    = !
  * O+Y    = ?
  * 
  *
  * 
  */ 


  [_ALPHA] = LAYOUT_wrapper (
    ______ALPHA_9_001_L______,  ______ALPHA_9_001_R______,
    ______ALPHA_9_002_L______,  ______ALPHA_9_002_R______,
    ______ALPHA_9_003_L______,  ______ALPHA_9_003_R______,
    ______ALPHA_9_004_L______,  ______ALPHA_9_004_R______
  ),


 /* MACROS
  * ┌──────┬──────┬──────┐          ┌──────┬──────┬──────┐
  * │      │  M11 │ M12  │          │ M13  │ M14  │ M15  │
  * │      │      │      │          │      │      │      │
  * ├──────╆━━━━━━╅──────┤          ├──────╆━━━━━━╅──────┤
  * │ XXXX ┃  M3  ┃  M4  │          │ M8   ┃ M9   ┃ M10  │
  * │ XXXX ┃      ┃      │          │      ┃      ┃      │
  * ├──────╄━━━━━━╃──────┤          ├──────╄━━━━━━╃──────┤
  * │      │  M1  │  M2  │          │ M5   │ M6   │ M7   │
  * │      │      │      │          │      │      │      │
  * └──────┴──────┴───┬──┴───┐  ┌───┴──┬───┴──────┴──────┘
  *                   │ SPC  │  │ ENT  │
  *                   │      │  │      │
  *                   └──────┘  └──────┘
  * 
  */

  [_MACRO] = LAYOUT_wrapper (
    ______MACRO_9_001_L______,  ______MACRO_9_001_R______,
    ______MACRO_9_002_L______,  ______MACRO_9_002_R______,
    ______MACRO_9_003_L______,  ______MACRO_9_003_R______,
    ______MACRO_9_004_L______,  ______MACRO_9_004_R______
  ),


 /* NUMBERS
  * ┌──────┬──────┬──────┐          ┌──────┬──────┬──────┐
  * │      │  _   │ XXXX │          │ 7    │ 8    │ 9    │
  * │      │  -   │ XXXX │          │      │      │      │
  * ├──────╆━━━━━━╅──────┤          ├──────╆━━━━━━╅──────┤
  * │      ┃      ┃      │          │ 4    ┃ 5    ┃ 6    │
  * │      ┃      ┃      │          │      ┃      ┃      │
  * ├──────╄━━━━━━╃──────┤          ├──────╄━━━━━━╃──────┤
  * │ BOOT │      │      │          │ 1    │ 2    │ 3    │
  * │      │      │      │          │      │ 0    │      │
  * └──────┴──────┴───┬──┴───┐  ┌───┴──┬───┴──────┴──────┘
  *                   │ SPC  │  │ ENT  │
  *                   │      │  │      │
  *                   └──────┘  └──────┘
  * 
  */

  [_NUM] = LAYOUT_wrapper (
    _______NUM_9_001_L_______,  _______NUM_9_001_R_______,
    _______NUM_9_002_L_______,  _______NUM_9_002_R_______,
    _______NUM_9_003_L_______,  _______NUM_9_003_R_______,
    _______NUM_9_004_L_______,  _______NUM_9_004_R_______
  ),


  /* MOUSE
  * ┌──────┬──────┬──────┐          ┌──────┬──────┬──────┐
  * │WHEEL │MOUSE │WHEEL │          │  F2  │      │      │
  * │ UP   │ UP   │ DOWN │          │      │      │      │
  * ├──────╆━━━━━━╅──────┤          ├──────╆━━━━━━╅──────┤
  * │MOUSE ┃MOUSE ┃MOUSE │          │  _   ┃      ┃      │
  * │LEFT  ┃DOWN  ┃RIGHT │          │  -   ┃      ┃      │
  * ├──────╄━━━━━━╃──────┤          ├──────╄━━━━━━╃──────┤
  * │MOUSE │MOUSE │MOUSE │          │ XXXX │      │      │
  * │BTN2  │BTN1  │BTN3  │          │ XXXX │      │      │
  * └──────┴──────┴───┬──┴───┐  ┌───┴──┬───┴──────┴──────┘
  *                   │ SPC  │  │ ENT  │
  *                   │      │  │      │
  *                   └──────┘  └──────┘
  * 
  */

  [_MOUSE] = LAYOUT_wrapper (
    _____MOUSE_9_001_L_______,  _____MOUSE_9_001_R_______,
    _____MOUSE_9_002_L_______,  _____MOUSE_9_002_R_______,
    _____MOUSE_9_003_L_______,  _____MOUSE_9_003_R_______,
    _____MOUSE_9_004_L_______,  _____MOUSE_9_004_R_______
  ),
   



 /* FUNCTION
  * ┌──────┬──────┬──────┐          ┌──────┬──────┬──────┐
  * │ CCCV │ CLIP │ SS   │          │ CAPS │ UP   │DELETE│
  * │      │      │      │          │ WORD │      │      │
  * ├──────╆━━━━━━╅──────┤          ├──────╆━━━━━━╅──────┤
  * │ TAB  ┃      ┃      │          │ LEFT ┃ DOWN ┃ RIGHT│
  * │ M5   ┃      ┃      │          │      ┃      ┃      │
  * ├──────╄━━━━━━╃──────┤          ├──────╄━━━━━━╃──────┤
  * │ XXXX │      │      │          │ UNDO │ PG UP│ HOME │
  * │ XXXX │      │      │          │ REDO │ PG DN│ END  │
  * └──────┴──────┴───┬──┴───┐  ┌───┴──┬───┴──────┴──────┘
  *                   │ SPC  │  │ ENT  │
  *                   │      │  │      │
  *                   └──────┘  └──────┘
  * 
  * 
 */

  [_FN] = LAYOUT_wrapper (
    ____FUNCTION_9_001_L_____,  ____FUNCTION_9_001_R_____,
    ____FUNCTION_9_002_L_____,  ____FUNCTION_9_002_R_____,
    ____FUNCTION_9_003_L_____,  ____FUNCTION_9_003_R_____,
    ____FUNCTION_9_004_L_____,  ____FUNCTION_9_004_R_____
  ),



   /* SYMBOLS
  * ┌──────┬──────┬──────┐          ┌──────┬──────┬──────┐
  * │      │      │  *   │          │  (   │  [   │  =   │
  * │      │      │  ^   │          │  )   │  ]   │  +   │
  * ├──────╆━━━━━━╅──────┤          ├──────╆━━━━━━╅──────┤
  * │      ┃      ┃ XXXX │          │  :   ┃  /   ┃  |   │
  * │      ┃      ┃ XXXX │          │  ;   ┃  \   ┃  &   │
  * ├──────╄━━━━━━╃──────┤          ├──────╄━━━━━━╃──────┤
  * │      │      │      │          │  '   │  @   │  %   │
  * │      │      │      │          │  "   │  #   │  $   │
  * └──────┴──────┴───┬──┴───┐  ┌───┴──┬───┴──────┴──────┘
  *                   │ SPC  │  │ ENT  │
  *                   │      │  │      │
  *                   └──────┘  └──────┘
  *
 */

  [_SYMB] = LAYOUT_wrapper (
    _______SYM_9_001_L_______,  _______SYM_9_001_R_______,
    _______SYM_9_002_L_______,  _______SYM_9_002_R_______,
    _______SYM_9_003_L_______,  _______SYM_9_003_R_______,
    _______SYM_9_004_L_______,  _______SYM_9_004_R_______
  ),

    
};

 

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case AMACRO:
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return false;
        case ISFT:
            return false;
        case DCTRL:
            return false;
        case CFN:
            return false;
        case TALT:
            return false;
        case CGUI:
            return false;
        case GNUM:
            return false;
        case KMOUSE:
            return false;
        case HMOUSE:
            return false;
        default:
            // Force the dual-role key press to be handled as a modifier if any
            // other key was pressed while the mod-tap key is held down.
            return true;
    }
}
