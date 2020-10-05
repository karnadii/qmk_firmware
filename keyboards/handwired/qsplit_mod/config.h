#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    karnadii
#define PRODUCT         qsplit65_rev2
#define DESCRIPTION     "handwired 65 keyboard"

// #define MASTER_RIGHT // Comment this line for the left half firmware
#define MASTER_LEFT // Comment this line for the right half firmware

/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 8

/* key matrix pins */
#ifdef MASTER_LEFT
#define MATRIX_ROW_PINS { C0, C1, C2, C4, C3 }
#define MATRIX_COL_PINS { E1, E0, D7, F3, D5, D4, D3, D2 }
#endif

#ifdef MASTER_RIGHT
#define MATRIX_ROW_PINS { B3, B1, F6, F7, F5 }
#define MATRIX_COL_PINS { B2, B6, B5, B4, E6, D7, C6, D4 }
#endif

#define MATRIX_ROW_PINS_RIGHT { B3, B1, F6, F7, F5 }
#define MATRIX_COL_PINS_RIGHT { B2, B6, B5, B4, E6, D7, C6, D4 }
#define UNUSED_PINS
#define USE_I2C
// #define SOFT_SERIAL_PIN D1
/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

// Right encoder.
#ifdef MASTER_LEFT
#define ENCODERS_PAD_A { C6, F7, F5 }
#define ENCODERS_PAD_B { C7, F6, F2 }
#endif

#ifdef MASTER_RIGHT
#define ENCODERS_PAD_A { D3 }
#define ENCODERS_PAD_B { D2 }
#endif

#define ENCODERS_PAD_A_RIGHT { D3 }
#define ENCODERS_PAD_B_RIGHT { D2 }
#define ENCODER_RESOLUTION 4

#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 28
#define RGBLED_SPLIT { 14, 14 }
#define RGB_DI_PIN F1

#ifdef MASTER_LEFT
#define RGBLIGHT_LED_MAP { 21, 0, 1,2,3,4,5,6,6,18,18,18, 19, 20,     15,16, 17, 17, 17, 7,7,8,9,10,11,12,13,14  }
#endif

#ifdef MASTER_RIGHT
#define RGBLIGHT_LED_MAP { 15,16, 17, 17, 17, 7,7,8,9,10,11,12,13,14 ,21, 0, 1,2,3,4,5,6,6,18,18,18, 19, 20      }
#endif

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

// DIP SWITCH
#ifdef DIP_SWITCH_ENABLE
#define DIP_SWITCH_PINS { B5, B4, B3, B2, E6, E7, B0, B1 }
#endif


#ifdef AUDIO_ENABLE
#define MUSIC_MAP
#define MUSIC_MASK keycode != KC_NO
#define C5_AUDIO
// #define B6_AUDIO
#define AUDIO_CLICKY
#define AUDIO_CLICKY_FREQ_RANDOMNESS 1.5f
// #define AUDIO_CLICKY_FREQ_DEFAULT 65.0f
#endif

#ifdef QWIIC_MICRO_OLED_ENABLE
#define I2C_ADDRESS_SA0_1 0x3C
#define LCDWIDTH      128
#define LCDHEIGHT     64

#endif

#ifdef MASTER_LEFT
/*enable midi slider*/
#define POT_ENABLE
#endif

#endif
