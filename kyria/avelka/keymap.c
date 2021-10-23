/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Left-hand home row mods colemak
#define GUI_A LGUI_T(KC_A)
#define CTR_A LCTL_T(KC_A)
#define ALT_R LALT_T(KC_R)
#define SFT_S LSFT_T(KC_S)
#define CTR_T LCTL_T(KC_T)
#define GIU_T LGUI_T(KC_T)

// Right-hand home row mods colemak
#define CTR_N RCTL_T(KC_N)
#define GUI_N LGUI_T(KC_N)
#define SFT_E RSFT_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define GUI_O LGUI_T(KC_O)
#define CTR_O LCTL_T(KC_O)

enum layers {
    _COLEMAK_DH,
    _COLEMAK_DH_OSX,
    _NAV,
    _FUNCTION,
    _ADJUST,
    _NUMR,
    _NUML,
    _GAMING,
    _CODE
};


// Aliases for readability
#define COLEMAK  DF(_COLEMAK_DH)
#define CMK_OSX  DF(_COLEMAK_DH_OSX)
#define GAMING   DF(_GAMING)


#define NAV      MO(_NAV)
#define CODE     MO(_CODE)
#define NUM_R    MO(_NUMR)
#define NUM_L    MO(_NUML)
#define FKEYS    MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)

#define NAV_ENT  LT(_NAV, KC_ENT)
#define COD_SPC  LT(_CODE, KC_SPC)
#define NBL_SPC  LT(_NUML, KC_SPC)
#define NBR_SPC  LT(_NUMR, KC_SPC)
#define FUN_SPC  LT(_FUNCTION, KC_SPC)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)




#define KC_MOR  LSFT(KC_COMM)
#define KC_LSS  LSFT(KC_DOT)
#define KC_COLN  LSFT(KC_SCLN)
#define KC_SQOT  LSFT(KC_QUOT)





// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/*
 * Base Layer: Colemak DH
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  | ;  : |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   V  | [ {  |CapsLk|  |F-keys|  ] } |   K  |   H  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */

    [_COLEMAK_DH] = LAYOUT(
     KC_ESC  , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   ,                                     KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_BSPC,
     KC_TAB  , CTR_A  , ALT_R  , SFT_S  , GIU_T  , KC_G   ,                                     KC_M   , GUI_N  , SFT_E  , ALT_I  , CTR_O  , KC_QUOT,
     NAV_ENT , KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   , KC_LBRC, SH_TG  , SH_TG  , KC_RBRC, KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH,  KC_ENT,
                                 ADJUST , KC_LSFT, COD_SPC, NBR_SPC , KC_ENT, KC_DEL , FUN_SPC, NBL_SPC, KC_RALT, KC_LGUI
    ),

		[_COLEMAK_DH_OSX] = LAYOUT(
     KC_ESC  , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   ,                                     KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_BSPC,
     KC_TAB  , GUI_A  , ALT_R  , SFT_S  , CTR_T  , KC_G   ,                                     KC_M   , CTR_N  , SFT_E  , ALT_I  , GUI_O  , KC_QUOT,
     NAV_ENT , KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   , KC_LBRC, SH_TG  , SH_TG  , KC_RBRC, KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH,  KC_ENT ,
                                 ADJUST , KC_LSFT, COD_SPC, NBR_SPC , KC_ENT, KC_DEL , FUN_SPC, NBL_SPC, KC_RALT, KC_LGUI
    ),

    [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_PGUP , KC_HOME, KC_UP,   KC_END,  KC_VOLU, KC_BSPC,
      _______, KC_LCTL, KC_LALT, KC_LSFT, KC_LGUI, _______,                                     KC_PGDN , KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, KC_DEL ,
      XXXXXXX, _______, _______, _______, _______, _______, _______, KC_SLCK, _______, _______, KC_PAUSE, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_PSCR,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),


    [_NUMR] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_BSLS, KC_P7 , KC_P8, KC_P9, KC_EQL , KC_BSPC,
      _______, KC_LCTL, KC_LALT, KC_LSFT, KC_LGUI, _______,                                     KC_AMPR, KC_P4 , KC_P5, KC_P6, KC_PLUS, KC_DEL,
      _______, _______, _______, _______, _______, _______, _______, KC_SLCK, KC_NLCK, _______, KC_UNDS, KC_P1 , KC_P2, KC_P3, KC_SLSH, KC_ENT,
                                 _______, _______, _______, XXXXXXX, _______, KC_SPC , KC_MINS, KC_P0  , KC_DOT,  _______
    ),

    [_NUML] = LAYOUT(
      KC_EQL , KC_DEL , KC_P7  , KC_P8  , KC_P9  , KC_BSLS,                                     _______, _______, _______, _______, _______, _______,                                     
      KC_PLUS, KC_BSPC, KC_P4  , KC_P5  , KC_P6  , KC_AMPR,                                     _______, KC_RGUI, KC_RSFT, KC_LALT, KC_RCTL, _______,                                     
      KC_SLSH, KC_ENT , KC_P1  , KC_P2  , KC_P3  , KC_UNDS, _______, KC_SLCK, KC_NLCK, _______, _______, _______, _______, _______, _______, _______,  
                                 _______, KC_DOT , KC_P0  , KC_MINS, KC_SPC , _______, XXXXXXX, _______, _______,  _______
    ),
    
    [_FUNCTION] = LAYOUT(
      _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______,                                     _______, _______, _______, _______, _______, _______,
      _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,                                     _______, KC_RGUI, KC_RSFT, KC_LALT, KC_RCTL, _______,
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______
    ),


    [_CODE] = LAYOUT(
      _______, KC_ASTR, KC_QUES, KC_MINS, KC_HASH, KC_TILD,                                     KC_GRV , KC_LCBR, KC_SLSH, KC_RCBR, KC_SCLN, KC_DEL ,
      _______, KC_EXLM, KC_MOR , KC_EQL , KC_LSS , KC_PERC,                                     KC_SQOT, KC_LPRN, KC_PIPE, KC_RPRN, KC_COLN, KC_BSPC,
      _______, KC_AT  , KC_PLUS, KC_UNDS, KC_COMM, KC_CIRC, KC_AMPR, _______, KC_NLCK, KC_UNDS, KC_QUOT, KC_LBRC, KC_BSLS, KC_RBRC, KC_COMM, KC_ENT ,
                                 _______, _______, _______, XXXXXXX, _______, KC_SPC , KC_MINS, KC_P0  , KC_DOT,  _______
    ),


    [_ADJUST] = LAYOUT(
      _______, _______, _______, COLEMAK, CMK_OSX, GAMING ,                                    _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, _______, _______, _______,                                    RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,  RGB_MOD, _______,
      _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
                                 _______, _______, _______,_______, _______, _______, _______, _______, _______, _______
    ),


    [_GAMING] = LAYOUT(
      KC_ESC ,   KC_1 ,   KC_2 ,  KC_3  ,  KC_4  ,  KC_5 ,                                     _______, _______, _______, _______, _______, COLEMAK,
      KC_TAB , KC_LSFT,   KC_A ,  KC_W  ,  KC_D  ,  KC_Q ,                                     _______, _______, _______, _______, _______, CMK_OSX,
      KC_ENT , KC_LCTL,   KC_X ,  KC_S  ,  KC_E  ,  KC_M ,   KC_F , KC_ENT , _______, _______, _______, _______, _______, _______, _______, KC_ENT ,
                                ADJUST , KC_LSFT, COD_SPC, NBR_SPC , KC_ENT, KC_DEL , FUN_SPC, NBL_SPC, KC_RALT, KC_LGUI
    ),

};

#ifdef OLED_ENABLE


static void render_led(void) {
  led_t led_usb_state = host_keyboard_led_state();
  oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
  oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
  oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
}

static void render_status(void) {

    
    // clang-format on
  
    oled_write_P(PSTR("Kyria\n\n"), false);
    // Host Keyboard Layer Status
  
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _COLEMAK_DH:
            oled_write_P(PSTR("Cmk-DH Lnx/win\n"), false);
            break;
				case _COLEMAK_DH_OSX:
            oled_write_P(PSTR("Cmk-dh OsX\n"), false); 
            break;
        case _NAV:
            oled_write_P(PSTR("Nav\n"), false);
            break;
        case _NUMR:
            oled_write_P(PSTR("Num Right\n"), false);
            break;
        case _FUNCTION:
            oled_write_P(PSTR("Function\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        case _NUML:
            oled_write_P(PSTR("Num Left\n"), false);
            break;
				case _GAMING:
            oled_write_P(PSTR("Gaming\n"), false);
            break;
        case _CODE:
          oled_write_P(PSTR("Code\n"), false);
          break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Write host Keyboard LED Status to OLEDs
    render_led();

}

void oled_task_user(void) {
    render_status();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
}

#endif

bool encoder_update_user(uint8_t index, bool clockwise) {
  /* With an if statement we can check which encoder was turned. */
  if (index == 0) { /* First encoder */
   
    if (!clockwise) {
      tap_code(KC_PGDN);
    } else {
      tap_code(KC_PGUP);
    }
  } else if (index == 1) { /* Second encoder */
  if (layer_state_is(_NUMR) || layer_state_is(_NUML) || layer_state_is(_NAV)  || layer_state_is(_CODE) ) {
       if (!clockwise) {
        tap_code(KC_UP);
      } else {
        tap_code(KC_DOWN);
      }
    } else {
      if (!clockwise) {
        tap_code(KC_RGHT);
      } else {
        tap_code(KC_LEFT);
      }
    }
  }
	return false;
}