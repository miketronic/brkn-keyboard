// Copyright 2024 
// miketronic@github sepultor@discord -- Mike B <mxb540@gmail.com>
// SPDX-License-Identifier: GPL-2.0+

#include QMK_KEYBOARD_H

uint16_t copy_paste_timer;

enum layers {
  _ALPHA,
  _MACRO,
  _NUM,
  _MOUSE,
  _TB,
  _FN,
  _SYMB
};

// Layer macros
#define SSYM    LT(_SYMB, KC_S)         // Tap for "S", hold for Symbols layer
#define CFN     LT(_FN, KC_C)           // Tap for "C", hold for FN layer
#define GNUM    LT(_NUM, KC_G)          // Tap for "G", hold for Numbers layer
#define HMOUSE  LT(_MOUSE, KC_H)        // Tap for "H", hold for Mouse layer
#define FTB     LT(_TB, KC_F)           // Tap for "F", hold for Trackball layer
#define AMACRO  LT(_MACRO, KC_A)        // Tap for "A", hold for Macro layer
#define SFTSPC  SFT_T(KC_SPC)           // Tap for "Space", hold for Shift
#define SFTENT  SFT_T(KC_ENT)           // Tap for "Enter", hold for Shift

// Mod Tap
#define DCTRL   CTL_T(KC_D)             // Tap for "D", hold for Ctrl
#define TALT    ALT_T(KC_T)             // Tap for "T", hold for Alt

// MISC
#define CALTDEL LCTL(LALT(KC_DEL))	    // Ctrl Alt Del
#define TSKMGR  LCTL(LSFT(KC_ESC))	    // Task Manager
#define CLIP    LCTL(LALT(KC_Q))	    	// Clipboard (Ditto)
#define SS      LCTL(LALT(KC_G))		    // Greenshot region
#define AT      LSFT(KC_2)
#define DELWORD LCTL(KC_BSPC)         
#define COPY    LCTL(KC_C)
#define PASTE   LCTL(KC_V)
#define ____    KC_TRNS
#define XXXX    KC_NO
#define XXXXXXX KC_NO


// Tap Dance
enum tapdance_id{
  T_WESC = 0,
  T_20,
  T_OCOM,
  T_YDOT,
  T_UBSPC
};

#define TD_WESC  TD(T_WESC)
#define TD_20    TD(T_20)
#define TD_OCOM  TD(T_OCOM)
#define TD_YDOT  TD(T_YDOT)
#define TD_UBSPC TD(T_UBSPC)

tap_dance_action_t tap_dance_actions[] = {
  [T_WESC] = ACTION_TAP_DANCE_DOUBLE(KC_W, KC_ESC),                     // "w", Escape
  [T_20] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_0),                         // "2", "0"
  [T_OCOM] = ACTION_TAP_DANCE_DOUBLE(KC_O, KC_COMMA),	                // "O", ","
  [T_YDOT] = ACTION_TAP_DANCE_DOUBLE(KC_Y, KC_DOT),                     // "Y", "."
  [T_UBSPC] = ACTION_TAP_DANCE_DOUBLE(KC_U, KC_BSPC),                   // "U", backspace
};

enum custom_keycodes{
  MAKE = QK_USER,
  M01,
  M02,
  M03,
  M04,
  M05,
  M06, 
  M07,
  M08,
  EMAIL,
  RGB1,
  RGB2,	
  RGB3,
  RGB4,
  RGB5,
  ANGLE,
  PAREN,
  BRACES,
  CCCV,
  ENDHOME,
  UNDOER,
  SYM1,
  SYM2,
  SYM3,
  SYM4,
  SYM5,
  SYM6,
  SYM7,
  SYM8,
  SSPC,
  SENT
};

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
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;
const uint16_t PROGMEM combo_q[]      = { TD_WESC, FTB, COMBO_END };
const uint16_t PROGMEM combo_b[]      = { FTB, GNUM, COMBO_END };
const uint16_t PROGMEM combo_v[]      = { AMACRO, KC_R, COMBO_END };
const uint16_t PROGMEM combo_p[]      = { KC_R, SSYM, COMBO_END };
const uint16_t PROGMEM combo_z[]      = { CFN, DCTRL, COMBO_END };
const uint16_t PROGMEM combo_x[]      = { DCTRL, TALT, COMBO_END };
const uint16_t PROGMEM combo_j[]      = { KC_M, KC_L, COMBO_END };
const uint16_t PROGMEM combo_k[]      = { KC_N, KC_E, COMBO_END };
const uint16_t PROGMEM combo_ques[]   = { TD_OCOM, TD_YDOT, COMBO_END };
const uint16_t PROGMEM combo_exlm[]   = { KC_E, KC_I, COMBO_END };
const uint16_t PROGMEM combo_bspc[]   = { KC_L, KC_U, COMBO_END };


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
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 /* ALPHA9 
  * 
  * ┌─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┐
  * │     │ W   │ F   │ G   │     │   │     │ M   │ L   │ U   │     │
  * │     │ ESC Q     B     │     │   │     │     J    BSPC   │     │
  * ├─────┼─────┼─────╆━━━━━╅─────┤   ├─────╆━━━━━╅─────┼─────┼─────┤
  * │     │ A   │ R   ┃ S   ┃ G   │   │ Y   ┃ N   ┃ E   │ O   │ I   │
  * │     │     │     ┃     ┃     │   │     ┃     ┃     │     │     │
  * ├─────┼─────┼─────╄━━━━━╃─────┤   ├─────╄━━━━━╃─────┼─────┼─────┤
  * │ Z   │ X   │ M   │ C   │ V   │   │ K   │ L   │ SPC │ SPC │ENTER│
  * │ FN  │ CTRL│ ALT │ OS  │     │   │     │     │  ,  │  .  │SHIFT│
  * └─────┴─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┴─────┘
  *                   │OSM  │SPACE│   │ DEL │ENTER│COPY │
  *                   │SHIFT│ SYMB│     │   │MOUSE│ARROW│PASTE│
  *                   └─────┴─────┘   └─────┴─────┴─────┘     
  * 
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
  [_ALPHA] = LAYOUT (
   KC_TAB,  TD_WESC,  FTB,      GNUM,    KC_M,    KC_L,    KC_U,    KC_BSPC,
   KC_LSFT, AMACRO,   KC_R,     SSYM,    KC_N,    KC_E,    KC_I,    KC_DEL,
   CCCV,    CFN,      DCTRL,    TALT,    HMOUSE,  TD_OCOM, TD_YDOT, M08,
   SFTSPC,  SFTSPC,   RGB_TOG,  RGB_TOG, SFTENT,  SFTENT
  ),

  [_MACRO] = LAYOUT (
   KC_TAB,  M08,    M08,    M08,     XXXX,    XXXX, XXXX, XXXX,
   XXXX,    XXXX,   M03,    M04,     XXXX,    XXXX, XXXX, XXXX,
   XXXX,    XXXX,   M01,    M02,     M05,     M06,  M07,  M08,
   SFTSPC,  SFTSPC, KC_A,   KC_B,    SFTENT,  SFTENT
  ),

  [_NUM] = LAYOUT (
   KC_TAB,  KC_MINS, KC_UNDS, XXXX,    KC_7,   KC_8,  KC_9,  KC_BSPC,
   CCCV,    XXXX,    XXXX,    XXXX,    KC_4,   KC_5,  KC_6,  KC_DEL,
   XXXX,    QK_BOOT, XXXX,    XXXX,    KC_1,   TD_20, KC_3,  M08,
   SFTSPC,  SFTSPC,  KC_A,    KC_B,    SFTENT, SFTENT
  ),

  [_MOUSE] = LAYOUT (
   XXXX,    KC_WH_U,  KC_MS_U,  KC_WH_D,    KC_MINS,  XXXX, XXXX, XXXX,
   XXXX,    KC_MS_L,  KC_MS_D,  KC_MS_R,    KC_UNDS,  XXXX, XXXX, XXXX,
   XXXX,    KC_BTN3,  KC_BTN2,  KC_BTN1,    XXXX,     XXXX, XXXX, XXXX,
   KC_BTN2, KC_BTN1,  KC_BTN3,  KC_BTN3,    KC_BTN1,  KC_BTN2
  ),

  [_TB] = LAYOUT (
   RGB_TOG, XXXX,    XXXX,      XXXX,     KC_BTN1,  KC_BTN2,  KC_BTN3, XXXX,
   RGB_MOD, RGB_HUI, XXXX,      XXXX,     XXXX,     XXXX,     XXXX,    XXXX,
   RGB_VAI, RGB_SAI, XXXX,      KC_LSFT,  XXXX,     XXXX,     XXXX,    XXXX,
   KC_BTN2, KC_BTN1, KC_BTN3,   KC_BTN3,  KC_BTN1,  KC_BTN2
  ),

  [_FN] = LAYOUT (
   KC_TAB, CCCV,    CLIP,    SS,      KC_F2,    KC_UP,   KC_DEL,  KC_BSPC,
   XXXX,   XXXX,    XXXX,    XXXX,    KC_LEFT,  KC_DOWN, KC_RGHT, KC_DEL,
   XXXX,   XXXX,    XXXX,    XXXX,    UNDOER,   XXXX,    ENDHOME, XXXX,
   SFTSPC, SFTSPC,  KC_A,    KC_B,    SFTENT,   SFTENT
  ),

  [_SYMB] = LAYOUT (
   XXXX,   XXXX,    SYM1,   XXXX,        PAREN,   BRACES,  ANGLE, XXXX,
   XXXX,   XXXX,    SYM2,   XXXX,        SYM3,    SYM4,    SYM5,  XXXX,
   XXXX,   XXXX,    XXXX,   XXXX,        SYM6,    SYM7,    SYM8,  XXXX,
   SFTSPC, SFTSPC,  KC_A,   KC_B,        SFTENT,  SFTENT
  ),

};


bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case AMACRO:
            return false;
        case DCTRL:
            return false;
        case CFN:
            return false;
        case TALT:
            return false;
        case SSYM:
            return false;
        case GNUM:
            return false;
        case FTB:
            return false;            
        case HMOUSE:
            return false;
        case SENT:
            return false;
        case SSPC:
            return false;
        default:
            // Force the dual-role key press to be handled as a modifier if any
            // other key was pressed while the mod-tap key is held down.
            return true;
    }
}


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record){
switch (keycode) {
	  case CCCV:
				return 80;
			default:
				return TAPPING_TERM;
		}
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M01:
            if (record->event.pressed) {
                SEND_STRING("//a11");
            }
            return false;
            break;

        case M02:
            if (record->event.pressed) {
                SEND_STRING("//a12");
            }
            return false;
            break;

        case M03:
            if (record->event.pressed) {
                SEND_STRING("//a08");
            }
            return false;
            break;

        case M04:
            if (record->event.pressed) {
                SEND_STRING("//a09");
            }
            return false;
            break;

        case M05:
            if (record->event.pressed) {
                SEND_STRING("//th");
            }
            return false;
            break;

        case M06:
            if (record->event.pressed) {
                SEND_STRING("//re");
            }
            return false;
            break;

        case M07:
            if (record->event.pressed) {
                SEND_STRING("//yw");
            }
            return false;
            break;

        case M08:
            if (record->event.pressed) {
                tap_random_base64();
            }
            return false;
            break;

        case EMAIL:
            if (record->event.pressed) {
                SEND_STRING("//email\n");
            }
            return false;
            break;

        case CCCV: // One key copy/paste
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) { // Hold, copy
                    tap_code16(LCTL(KC_C));
                } else { // Tap, paste
                    tap_code16(LCTL(KC_V));
                }
            }
            return false;
            break;

        case SSPC: // Hold shift, Tap space
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
                register_code(KC_LSFT); // Hold, shift
            } else {
                unregister_code(KC_LSFT);
                if (timer_elapsed(copy_paste_timer) < TAPPING_TERM) { 
                    tap_code(KC_SPC);
                }
            }
            return false;
            break;

        case SENT: // Hold shift, Tap Enter
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
                register_code(KC_RSFT); // Hold, shift
            } else {
                unregister_code(KC_RSFT);
                if (timer_elapsed(copy_paste_timer) < TAPPING_TERM) { 
                    tap_code(KC_ENT);
                }
            }
            return false;
            break;
            
        case ENDHOME:
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                    tap_code16(KC_HOME);
                } else {
                    tap_code16(KC_END);
                }
            }
            return false;
            break;

        case UNDOER:
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                    SEND_STRING(SS_LCTL("y"));
                } else {
                    SEND_STRING(SS_LCTL("z"));
                }
            }
            return false;
            break;

        case SYM1:
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                    tap_code16(KC_CIRC);
                } else {
                    tap_code16(KC_ASTR);
                }
            }
            return false;
            break;

        case SYM2:
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                    tap_code16(KC_PLUS);
                } else {
                    tap_code16(KC_EQL);
                }
            }
            return false;
            break;

        case SYM3:
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                    tap_code16(KC_SCLN);
                } else {
                    tap_code16(KC_COLN);
                }
            }
            return false;
            break;

        case SYM4:
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                    tap_code16(KC_BSLS);
                } else {
                    tap_code16(KC_SLSH);
                }
            }
            return false;
            break;

        case SYM5:
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                    tap_code16(KC_AMPR);
                } else {
                    tap_code16(KC_PIPE);
                }
            }
            return false;
            break;

        case SYM6:
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                    tap_code16(KC_DQUO);
                } else {
                    tap_code16(KC_QUOT);
                }
            }
            return false;
            break;

        case SYM7:
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                    tap_code16(KC_HASH);
                } else {
                    tap_code16(KC_AT);
                }
            }
            return false;
            break;

        case SYM8:
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                    tap_code16(KC_DLR);
                } else {
                    tap_code16(KC_PERC);
                }
            }
            return false;
            break;

        case ANGLE:
            if (record->event.pressed) {
                SEND_STRING("<>");
                tap_code(KC_LEFT);
            }
            return false;
            break;

        case BRACES:
            if (record->event.pressed) {
                SEND_STRING("[]");
                tap_code(KC_LEFT);
            }
            return false;
            break;

        case PAREN:
            if (record->event.pressed) {
                SEND_STRING("()");
                tap_code(KC_LEFT);
            }
            return false;
            break;

    }
    return true;
}



void keyboard_post_init_user(void) {
    pointing_device_set_cpi_on_side(true, 100); //Set cpi on left side to a low value for slower scrolling.
    pointing_device_set_cpi_on_side(false, 2000); //Set cpi on right side to a reasonable value for mousing.
}

report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
    left_report.h = left_report.x;
    left_report.v = left_report.y;
    left_report.x = 0;
    left_report.y = 0;
    return pointing_device_combine_reports(left_report, right_report);
}
