#include "qsplit_mod.h"
#include "qwiic.h"
#include <stdio.h>
#include <print.h>
#include <inttypes.h>

enum layer_names {
     _QWERTY,
     _COLEMAK,
    _FN1,
    _FN2
};

#ifdef POT_ENABLE
  #include "analog.h"
#endif

float qwerty_song[][2] = SONG(QWERTY_SOUND);
float colemak_song[][2] = SONG(COLEMAK_SOUND);
float linux_sound[][2] = SONG(UNICODE_LINUX);
float windows_sound[][2] = SONG(UNICODE_WINDOWS);
float encoder_sound[][2] = SONG(TERMINAL_SOUND);

float caps_on[][2] = SONG(CAPS_LOCK_ON_SOUND);
float caps_ff[][2] = SONG(CAPS_LOCK_OFF_SOUND);

float song_one[][2] = SONG(CAMPANELLA);
float song_two[][2] = SONG(FANTASIE_IMPROMPTU);
float song_three[][2] = SONG(NOCTURNE_OP_9_NO_1);
float song_four[][2] = SONG(USSR_ANTHEM);


uint16_t counterst = 0;
int16_t pot_oldVal = 0;
int16_t pot_val    = 0;
int16_t pot_ccVal  = 0;
#define POT_TOLERANCE 12
char wpm_str[10];
enum custom_keycodes { QWERTY = SAFE_RANGE, ALT_GUI, GUI_ALT, LAYOUT_MOD, MAIN_ENCODER, SONG1, SONG2, SONG3, SONG4 };
enum encoder_layers {media, backlit, scroll, brightness};
bool isDarwin = true;
int base_layout = _QWERTY;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_QWERTY] = KEYMAP(
                                             KC_GESC, KC_1,    KC_2,    KC_3,   KC_4,     KC_6,         KC_8, KC_9,   KC_0,    KC_MINS,  KC_EQL,  KC_BSPC, KC_DEL,  MAIN_ENCODER,
                                             KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,     KC_5,         KC_7, KC_I,   KC_O,    KC_P,     KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
                                             KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,     KC_T,         KC_U, KC_J,   KC_K,    KC_L,     KC_SCLN, KC_QUOT, KC_ENT,  KC_PGDN,
                                     MU_MOD, KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,     KC_G,         KC_Y, KC_N,   KC_M,    KC_COMM,  KC_DOT,  KC_SLSH, KC_LSFT, KC_UP,
		 RGB_MOD, RGB_RMOD, KC_LCTL, GUI_ALT, ALT_GUI, KC_SPC, MO(_FN2), KC_B,         KC_H, KC_SPC, ALT_GUI, MO(_FN1), KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT),

	[_COLEMAK] = KEYMAP(
                                             KC_GESC, KC_1,    KC_2,    KC_3,   KC_4,     KC_6,         KC_8, KC_9,   KC_0,    KC_MINS,  KC_EQL,  KC_BSPC, KC_DEL,  MAIN_ENCODER,
                                             KC_TAB,  KC_Q,    KC_W,    KC_F,   KC_P,     KC_5,         KC_7, KC_U,   KC_Y,    KC_SCLN,     KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
                                             KC_CAPS, KC_A,    KC_R,    KC_S,   KC_T,     KC_G,         KC_L, KC_N,   KC_E,    KC_I,     KC_O, KC_QUOT, KC_ENT,  KC_PGDN,
                                     MU_MOD, KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,     KC_D,         KC_J, KC_K,   KC_M,    KC_COMM,  KC_DOT,  KC_SLSH, KC_LSFT, KC_UP,
		 RGB_MOD, RGB_RMOD, KC_LCTL, GUI_ALT, ALT_GUI, KC_SPC, MO(_FN2), KC_B,         KC_H, KC_SPC, ALT_GUI, MO(_FN1), KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT),


	[_FN1] = KEYMAP(
                          KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F6,           KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_BSPC, _______,
                          _______, _______, _______, _______, _______, KC_F5,           KC_F7,   _______, _______, _______, _______, _______, _______, KC_HOME,
                          _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, KC_END,
                 _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______),

	[_FN2] = KEYMAP(
		_______, SONG1, SONG2, SONG3, SONG4, _______,_______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

};






bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GUI_ALT:
            if (record->event.pressed) {
                register_code(!isDarwin?KC_LGUI:KC_LALT);
            }else{
                unregister_code(!isDarwin?KC_LGUI:KC_LALT);
            }
            return false;
        case ALT_GUI:
            if (record->event.pressed) {
                dprint("alt gui");

                register_code(isDarwin?KC_LGUI:KC_LALT);
            }else{
                unregister_code(isDarwin?KC_LGUI:KC_LALT);
            }
            return false;
        case LAYOUT_MOD:
            if (record->event.pressed) {
                dprint("LAYOUT_MOD pressed");
                if(base_layout == _QWERTY){
                    base_layout = _COLEMAK;
                    set_single_persistent_default_layer(_COLEMAK);
                } else {
                    base_layout = _QWERTY;
                    set_single_persistent_default_layer(_QWERTY);
                }
            }

            return false;
        case MAIN_ENCODER:
            if (record->event.pressed) {
                if(layer_state_is(_FN1) || layer_state_is(_FN2)){
                    if(base_layout == _QWERTY){
                        base_layout = _COLEMAK;
                        set_single_persistent_default_layer(_COLEMAK);
                        PLAY_SONG(colemak_song);
                    } else {
                        base_layout = _QWERTY;
                        set_single_persistent_default_layer(_QWERTY);
                        PLAY_SONG(qwerty_song);
                    }
                }else{
                    tap_code(KC_MPLY);
                }
            }
            return false;
        case SONG1:
            if (record->event.pressed) {
                PLAY_SONG(song_one);
            }
            return false;
        case SONG2:
            if (record->event.pressed) {
                PLAY_SONG(song_two);
            }
            return false;
        case SONG3:
            if (record->event.pressed) {
                PLAY_SONG(song_three);
            }
            return false;
        case SONG4:
            if (record->event.pressed) {
                PLAY_SONG(song_four);
            }
            return false;


    }
	return true;
}

void matrix_init_user(void) {
#ifdef POT_ENABLE
    analogReference(ADC_REF_POWER);
#endif
}

void matrix_scan_user(void) {
    //  dprint("Scanning user");
#ifdef POT_ENABLE
    pot_val   = (analogReadPin(F0));
    pot_ccVal = pot_val / 8;
    if (abs(pot_val - pot_oldVal) > POT_TOLERANCE) {
        pot_oldVal = pot_val;
        dprintf("%"PRIu16 "\n", pot_ccVal);
    }
#endif

}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}



void handle_encoder_media(bool clockwise, bool fn1, bool fn2){
    if(clockwise){
        if(fn1){
            tap_code(KC_MNXT);
        }else if(fn2){
            tap_code(KC_MFFD);
        }else{
            tap_code(KC_VOLU);
        }
    }else {
        if(fn1){
            tap_code(KC_MPRV);
        }else if(fn2){
            tap_code(KC_MRWD);
        }else{
            tap_code(KC_VOLD);
        }
    }
}

void handle_encoder_backlit(bool clockwise, bool fn1, bool fn2){
    if(clockwise){
        if(fn1){
            rgblight_increase_hue();
        }else if(fn2){
            rgblight_increase_sat();
        }else{
            rgblight_increase_val();
        }
    }else {
        if(fn1){
            rgblight_decrease_hue();
        }else if(fn2){
            rgblight_decrease_sat();
        }else{
            rgblight_decrease_val();
        }
    }
}

void handle_encoder_scroll(bool clockwise, bool fn1, bool fn2){
    if(clockwise){
        if(fn1){
            tap_code(KC_WH_R);
        }else if(fn2){
            tap_code(KC_WH_R);
        }else{
            tap_code(KC_WH_D);
        }
    }else {
        if(fn1){
            tap_code(KC_WH_L);
        }else if(fn2){
            tap_code(KC_WH_L);
        }else{
            tap_code(KC_WH_U);
        }
    }
}

void handle_encoder_brightnes(bool clockwise, bool fn1, bool fn2){
    if (clockwise) {
        clicky_freq_up();
    } else {
        clicky_freq_down();
    }
}


#ifdef QWIIC_MICRO_OLED_ENABLE

/* screen off after this many milliseconds */
#include "timer.h"
#define ScreenOffInterval 60000 /* milliseconds */
static uint16_t last_flush;

volatile uint8_t led_numlock = false;
volatile uint8_t  led_capslock = false;
volatile uint8_t  led_scrolllock = false;

static uint8_t layer;
static bool queue_for_send = false;
// static uint8_t encoder_value = 32;

__attribute__ ((weak))
void draw_ui(void) {
  clear_buffer();
  last_flush = timer_read();
  send_command(DISPLAYON);

/* Boston MK title is 55 x 10 pixels */
#define OS_INDICATOR_X 0
#define OS_INDICATOR_Y 0

    draw_string(OS_INDICATOR_X + 1, OS_INDICATOR_Y + 2, "OS", PIXEL_ON, NORM, 0);
    draw_rect_filled_soft(OS_INDICATOR_X + 14, OS_INDICATOR_Y + 1, 5 + (3 * 6), 9, PIXEL_ON, NORM);
    draw_string(OS_INDICATOR_X + 17, OS_INDICATOR_Y + 2, isDarwin?"MAC":"WIN", PIXEL_OFF, NORM, 0);


/* Layer indicator is 41 x 10 pixels */
#define LAYER_INDICATOR_X 39
#define LAYER_INDICATOR_Y 0
  draw_string(LAYER_INDICATOR_X + 1, LAYER_INDICATOR_Y + 2, "LAYOUT", PIXEL_ON, NORM, 0);
  draw_rect_filled_soft(LAYER_INDICATOR_X + 20+ (3 * 6), LAYER_INDICATOR_Y + 1, 5 + (3 * 6), 9, PIXEL_ON, NORM);
  draw_string(LAYER_INDICATOR_X + 23+ (3 * 6), OS_INDICATOR_Y + 2, base_layout == _QWERTY?"QWE":"COL", PIXEL_OFF, NORM, 0);


#define MATRIX_DISPLAY_X 0
#define MATRIX_DISPLAY_Y 14

for (uint8_t x = 0; x < 5; x++) {
    uint8_t pointX = 5 + x;
    for (uint8_t y = 0; y < 16; y++) {
            uint8_t pointY = 16 - y;
            uint8_t pointYY = 8 -  pointY;
            if(y < 8){
            draw_pixel(MATRIX_DISPLAY_X + y + y + 4, MATRIX_DISPLAY_Y + x + x + 2, (matrix_get_row(x) & (1 << y)) > 0, NORM);
            draw_pixel(MATRIX_DISPLAY_X + y + y + 5, MATRIX_DISPLAY_Y + x + x + 2, (matrix_get_row(x) & (1 << y)) > 0, NORM);
            draw_pixel(MATRIX_DISPLAY_X + y + y + 4, MATRIX_DISPLAY_Y + x + x + 3, (matrix_get_row(x) & (1 << y)) > 0, NORM);
            draw_pixel(MATRIX_DISPLAY_X + y + y + 5, MATRIX_DISPLAY_Y + x + x + 3, (matrix_get_row(x) & (1 << y)) > 0, NORM);
            }else{
            draw_pixel(MATRIX_DISPLAY_X + y + y + 4, MATRIX_DISPLAY_Y + x + x + 2, (matrix_get_row(pointX) & (1 << pointYY)) > 0, NORM);
            draw_pixel(MATRIX_DISPLAY_X + y + y + 5, MATRIX_DISPLAY_Y + x + x + 2, (matrix_get_row(pointX) & (1 << pointYY)) > 0, NORM);
            draw_pixel(MATRIX_DISPLAY_X + y + y + 4, MATRIX_DISPLAY_Y + x + x + 3, (matrix_get_row(pointX) & (1 << pointYY)) > 0, NORM);
            draw_pixel(MATRIX_DISPLAY_X + y + y + 5, MATRIX_DISPLAY_Y + x + x + 3, (matrix_get_row(pointX) & (1 << pointYY)) > 0, NORM);
            }
    }
}

  // Matrix loaction frame
  draw_rect_soft(MATRIX_DISPLAY_X, MATRIX_DISPLAY_Y, 38, 14, PIXEL_ON, NORM);
  /*oled location on thumbnail */
  draw_rect_filled_soft(MATRIX_DISPLAY_X + 1, MATRIX_DISPLAY_Y + 2, 7, 2, PIXEL_ON, NORM);
  /* DIPswitch location*/
  draw_rect_filled_soft(MATRIX_DISPLAY_X + 2, MATRIX_DISPLAY_Y + 5, 2, 1, PIXEL_ON, NORM);
  draw_rect_filled_soft(MATRIX_DISPLAY_X + 5, MATRIX_DISPLAY_Y + 5, 2, 1, PIXEL_ON, NORM);
  /* Potentio slide location*/
  draw_rect_filled_soft(MATRIX_DISPLAY_X + 2, MATRIX_DISPLAY_Y + 6, 1, 7, PIXEL_ON, NORM);
/*
  draw_rect_soft(0, 13, 64, 6, PIXEL_ON, NORM);
  draw_line_vert(encoder_value, 13, 6, PIXEL_ON, NORM);
*/

/* Mod display is 41 x 16 pixels */
#define MOD_DISPLAY_X 42
#define MOD_DISPLAY_Y 17

  uint8_t mods = get_mods();
  if (mods & MOD_LSFT) {
    draw_rect_filled_soft(MOD_DISPLAY_X + 0, MOD_DISPLAY_Y, 5 + (1 * 6), 11, PIXEL_ON, NORM);
    draw_string(MOD_DISPLAY_X + 3, MOD_DISPLAY_Y + 2, "S", PIXEL_OFF, NORM, 0);
  } else {
    draw_string(MOD_DISPLAY_X + 3, MOD_DISPLAY_Y + 2, "S", PIXEL_ON, NORM, 0);
  }
  if (mods & MOD_LCTL) {
    draw_rect_filled_soft(MOD_DISPLAY_X + 10+2, MOD_DISPLAY_Y, 5 + (1 * 6), 11, PIXEL_ON, NORM);
    draw_string(MOD_DISPLAY_X + 13+2, MOD_DISPLAY_Y + 2, "C", PIXEL_OFF, NORM, 0);
  } else {
    draw_string(MOD_DISPLAY_X + 13+2, MOD_DISPLAY_Y + 2, "C", PIXEL_ON, NORM, 0);
  }
  if (mods & MOD_LALT) {
    draw_rect_filled_soft(MOD_DISPLAY_X + 20+4, MOD_DISPLAY_Y, 5 + (1 * 6), 11, PIXEL_ON, NORM);
    draw_string(MOD_DISPLAY_X + 23+4, MOD_DISPLAY_Y + 2, "A", PIXEL_OFF, NORM, 0);
  } else {
    draw_string(MOD_DISPLAY_X + 23+4, MOD_DISPLAY_Y + 2, "A", PIXEL_ON, NORM, 0);
  }
  if (mods & MOD_LGUI) {
    draw_rect_filled_soft(MOD_DISPLAY_X + 30+6, MOD_DISPLAY_Y, 5 + (1 * 6), 11, PIXEL_ON, NORM);
    draw_string(MOD_DISPLAY_X + 33+6, MOD_DISPLAY_Y + 2, "G", PIXEL_OFF, NORM, 0);
  } else {
    draw_string(MOD_DISPLAY_X + 33+6, MOD_DISPLAY_Y + 2, "G", PIXEL_ON, NORM, 0);
  }

/* Lock display is 23 x 32 */
#define LOCK_DISPLAY_X 104
#define LOCK_DISPLAY_Y 0

  if (led_numlock == true) {
    draw_rect_filled_soft(LOCK_DISPLAY_X, LOCK_DISPLAY_Y, 5 + (3 * 6), 9, PIXEL_ON, NORM);
    draw_string(LOCK_DISPLAY_X + 3, LOCK_DISPLAY_Y + 1, "NUM", PIXEL_OFF, NORM, 0);
  } else if (led_numlock == false) {
    draw_string(LOCK_DISPLAY_X + 3, LOCK_DISPLAY_Y + 1, "NUM", PIXEL_ON, NORM, 0);
  }
  if (led_capslock == true) {
    draw_rect_filled_soft(LOCK_DISPLAY_X + 0, LOCK_DISPLAY_Y + 11, 5 + (3 * 6), 9, PIXEL_ON, NORM);
    draw_string(LOCK_DISPLAY_X + 3, LOCK_DISPLAY_Y + 11 +1, "CAP", PIXEL_OFF, NORM, 0);
  } else if (led_capslock == false) {
    draw_string(LOCK_DISPLAY_X + 3, LOCK_DISPLAY_Y + 11 +1, "CAP", PIXEL_ON, NORM, 0);
  }

  if (led_scrolllock == true) {
    draw_rect_filled_soft(LOCK_DISPLAY_X + 0, LOCK_DISPLAY_Y + 22, 5 + (3 * 6), 9, PIXEL_ON, NORM);
    draw_string(LOCK_DISPLAY_X + 3, LOCK_DISPLAY_Y + 22 +1, "SCR", PIXEL_OFF, NORM, 0);
  } else if (led_scrolllock == false) {
    draw_string(LOCK_DISPLAY_X + 3, LOCK_DISPLAY_Y + 22 +1, "SCR", PIXEL_ON, NORM, 0);
  }

    sprintf(wpm_str, "WPM %03d", get_current_wpm());
    draw_string(0, 34, wpm_str, PIXEL_ON, NORM, 0);
    // itoa(D_RH,data,10);
    // draw_string(10, 2, data, PIXEL_ON, NORM, 0);

  send_buffer();
}

void led_set_user(uint8_t usb_led) {
    if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
      if (led_numlock == false){led_numlock = true;}
    } else {
      if (led_numlock == true){led_numlock = false;}
    }
    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
      if (led_capslock == false){led_capslock = true;}
    } else {
      if (led_capslock == true){led_capslock = false;}
    }
    if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {
      if (led_scrolllock == false){led_scrolllock = true;}
    } else {
      if (led_scrolllock == true){led_scrolllock = false;}
    }
}

uint32_t layer_state_set_kb(uint32_t state) {
  state = layer_state_set_user(state);
  layer = biton32(state);
  queue_for_send = true;
  return state;
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  queue_for_send = true;
  return process_record_user(keycode, record);
}




void encoder_update_user(uint8_t index, bool clockwise) {
    bool fn1 = layer_state_is(_FN1);
    bool fn2 = layer_state_is(_FN2);
    if (index == 0) { /* First encoder */
       handle_encoder_scroll(clockwise, fn1, fn2);
    } else if (index == 1) { /* Second encoder */
       handle_encoder_backlit(clockwise, fn1, fn2);
    } else if (index == 2) { /* Second encoder */
       handle_encoder_brightnes(clockwise, fn1, fn2);
    } else if (index == 3) { /* Second encoder */
       handle_encoder_media(clockwise, fn1, fn2);
    }
    // PLAY_SONG(encoder_sound);
//   queue_for_send = true;
}


#ifdef DIP_SWITCH_ENABLE
 void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if(active) { audio_on(); } else { audio_off(); }
            break;
        case 1:
            if(active) { clicky_on(); } else { clicky_off(); }
            break;
        case 2:
            if(active) { music_on(); } else { music_off(); }
            break;
        case 3:
            if(active) { rgblight_enable(); } else { rgblight_disable();};
        case 4:
            if(active) { isDarwin = true; PLAY_SONG(linux_sound);} else { isDarwin = false; PLAY_SONG(windows_sound);};
    }
    queue_for_send = true;
}
#endif

#endif
void matrix_init_kb(void) {
    queue_for_send = true;
	matrix_init_user();

}



void matrix_scan_kb(void) {
if (queue_for_send) {
   /* store next eight bit in CheckSum */
#ifdef QWIIC_MICRO_OLED_ENABLE
   draw_ui();
#endif
   queue_for_send = false;
  }
#ifdef QWIIC_MICRO_OLED_ENABLE
  if (timer_elapsed(last_flush) > ScreenOffInterval) {
  send_command(DISPLAYOFF);      /* 0xAE */
  }
#endif
  if (counterst == 0) {
    //testPatternFB(o_fb);
  }
  counterst = (counterst + 1) % 1024;
  //rgblight_task();
	matrix_scan_user();
}

bool led_update_user(led_t led_state) {

    if(led_state.caps_lock){
        PLAY_SONG(caps_on);
    } else{
        PLAY_SONG(caps_ff);
    }


    return true;
}
