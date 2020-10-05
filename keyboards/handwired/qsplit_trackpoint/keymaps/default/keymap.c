#include QMK_KEYBOARD_H
#include <print.h>

enum layer_names {
     _MOUSE
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     [_MOUSE] = LAYOUT(
        KC_BTN1,    KC_BTN3,    KC_BTN2 \
    )
};
