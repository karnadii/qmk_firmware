#pragma once

#ifdef __AVR__
 #include <avr/io.h>
 #include <avr/pgmspace.h>
#elif defined(ESP8266)
 #include <pgmspace.h>
#else
 #define PROGMEM
#endif


const unsigned char font[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x3E, 0x5B, 0x4F, 0x5B, 0x3E, 0x00,
  0x3E, 0x6B, 0x4F, 0x6B, 0x3E, 0x00,
  0x1C, 0x3E, 0x7C, 0x3E, 0x1C, 0x00,
  0x18, 0x3C, 0x7E, 0xBC, 0x18, 0x00,
  0x1C, 0x57, 0x7D, 0x57, 0x1C, 0x00,
  0x1C, 0x5E, 0x7F, 0x5E, 0x1C, 0x00,
  0x00, 0x18, 0x3C, 0x18, 0x00, 0x00,
  0xFF, 0xE7, 0xC3, 0xE7, 0xFF, 0x00,
  0x00, 0x18, 0x24, 0x18, 0x00, 0x00,
  0xFF, 0xE7, 0xDB, 0xE7, 0xFF, 0x00,
  0x30, 0x48, 0x3A, 0x06, 0x0E, 0x00,
  0x26, 0x29, 0x79, 0x29, 0x26, 0x00,
  0x40, 0x7F, 0x05, 0x05, 0x07, 0x00,
  0x40, 0x7F, 0x05, 0x25, 0x3F, 0x00,
  0x5A, 0x3C, 0x66, 0x3C, 0x5A, 0x00,
  0x7F, 0x3E, 0x1C, 0x1C, 0x08, 0x00,
  0x08, 0x1C, 0x1C, 0x3E, 0x7F, 0x00,
  0x14, 0x22, 0x7F, 0x22, 0x14, 0x00,
  0x5F, 0x5F, 0x00, 0x5F, 0x5F, 0x00,
  0x06, 0x09, 0x7F, 0x01, 0x7F, 0x00,
  0x00, 0x66, 0x89, 0x95, 0x6A, 0x00,
  0x60, 0x60, 0x60, 0x60, 0x60, 0x00,
  0x94, 0xA2, 0xFF, 0xA2, 0x94, 0x00,
  0x08, 0x04, 0x7E, 0x04, 0x08, 0x00,
  0x10, 0x20, 0x7E, 0x20, 0x10, 0x00,
  0x08, 0x08, 0x2A, 0x1C, 0x08, 0x00,
  0x08, 0x1C, 0x2A, 0x08, 0x08, 0x00,
  0x1E, 0x10, 0x10, 0x10, 0x10, 0x00,
  0x0C, 0x1E, 0x0C, 0x1E, 0x0C, 0x00,
  0x30, 0x38, 0x3E, 0x38, 0x30, 0x00,
  0x06, 0x0E, 0x3E, 0x0E, 0x06, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x5E, 0x00, 0x00, 0x00,
  0x00, 0x06, 0x00, 0x06, 0x00, 0x00,
  0x14, 0x3E, 0x14, 0x3E, 0x14, 0x00,
  0x24, 0x2A, 0x7F, 0x2A, 0x12, 0x00,
  0x26, 0x16, 0x08, 0x34, 0x32, 0x00,
  0x36, 0x4A, 0x56, 0x20, 0x50, 0x00,
  0x00, 0x0A, 0x06, 0x00, 0x00, 0x00,
  0x00, 0x3C, 0x42, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x42, 0x3C, 0x00, 0x00,
  0x2A, 0x1C, 0x3E, 0x1C, 0x2A, 0x00,
  0x08, 0x08, 0x3E, 0x08, 0x08, 0x00,
  0x00, 0xA0, 0x60, 0x00, 0x00, 0x00,
  0x08, 0x08, 0x08, 0x08, 0x08, 0x00,
  0x00, 0x00, 0x60, 0x60, 0x00, 0x00,
  0x20, 0x10, 0x08, 0x04, 0x02, 0x00,
  0x3C, 0x42, 0x42, 0x42, 0x3C, 0x00,
  0x00, 0x44, 0x7E, 0x40, 0x00, 0x00,
  0x64, 0x52, 0x52, 0x52, 0x4C, 0x00,
  0x22, 0x42, 0x4A, 0x4A, 0x36, 0x00,
  0x38, 0x24, 0x22, 0x7E, 0x20, 0x00,
  0x2E, 0x4A, 0x4A, 0x4A, 0x32, 0x00,
  0x3C, 0x4A, 0x4A, 0x4A, 0x32, 0x00,
  0x02, 0x02, 0x62, 0x1A, 0x06, 0x00,
  0x34, 0x4A, 0x4A, 0x4A, 0x34, 0x00,
  0x4C, 0x52, 0x52, 0x52, 0x3C, 0x00,
  0x00, 0x00, 0x14, 0x00, 0x00, 0x00,
  0x00, 0x40, 0x34, 0x00, 0x00, 0x00,
  0x00, 0x08, 0x14, 0x22, 0x00, 0x00,
  0x14, 0x14, 0x14, 0x14, 0x14, 0x00,
  0x00, 0x00, 0x22, 0x14, 0x08, 0x00,
  0x00, 0x04, 0x52, 0x0A, 0x04, 0x00,
  0x3E, 0x41, 0x5D, 0x59, 0x4E, 0x00,
  0x7C, 0x12, 0x12, 0x12, 0x7C, 0x00,
  0x7E, 0x4A, 0x4A, 0x4A, 0x34, 0x00,
  0x3C, 0x42, 0x42, 0x42, 0x42, 0x00,
  0x7E, 0x42, 0x42, 0x42, 0x3C, 0x00,
  0x7E, 0x4A, 0x4A, 0x4A, 0x42, 0x00,
  0x7E, 0x0A, 0x0A, 0x0A, 0x02, 0x00,
  0x3C, 0x42, 0x42, 0x52, 0x34, 0x00,
  0x7E, 0x08, 0x08, 0x08, 0x7E, 0x00,
  0x00, 0x00, 0x7E, 0x00, 0x00, 0x00,
  0x20, 0x40, 0x42, 0x3E, 0x00, 0x00,
  0x7E, 0x10, 0x08, 0x14, 0x62, 0x00,
  0x7E, 0x40, 0x40, 0x40, 0x40, 0x00,
  0x7E, 0x04, 0x08, 0x04, 0x7E, 0x00,
  0x7E, 0x04, 0x08, 0x10, 0x7E, 0x00,
  0x3C, 0x42, 0x42, 0x42, 0x3C, 0x00,
  0x7E, 0x12, 0x12, 0x12, 0x0C, 0x00,
  0x3C, 0x42, 0x52, 0x22, 0x5C, 0x00,
  0x7E, 0x12, 0x12, 0x32, 0x4C, 0x00,
  0x4C, 0x52, 0x52, 0x52, 0x34, 0x00,
  0x02, 0x02, 0x7E, 0x02, 0x02, 0x00,
  0x3E, 0x40, 0x40, 0x40, 0x3E, 0x00,
  0x1E, 0x20, 0x40, 0x20, 0x1E, 0x00,
  0x3E, 0x40, 0x38, 0x40, 0x3E, 0x00,
  0x62, 0x14, 0x08, 0x14, 0x62, 0x00,
  0x06, 0x08, 0x70, 0x08, 0x06, 0x00,
  0x62, 0x52, 0x4A, 0x46, 0x42, 0x00,
  0x00, 0x7E, 0x42, 0x42, 0x00, 0x00,
  0x02, 0x04, 0x08, 0x10, 0x20, 0x00,
  0x00, 0x00, 0x42, 0x42, 0x7E, 0x00,
  0x08, 0x04, 0x02, 0x04, 0x08, 0x00,
  0x40, 0x40, 0x40, 0x40, 0x40, 0x00,
  0x00, 0x00, 0x06, 0x0A, 0x00, 0x00,
  0x60, 0x54, 0x54, 0x54, 0x7C, 0x00,
  0x7E, 0x48, 0x48, 0x48, 0x30, 0x00,
  0x30, 0x48, 0x48, 0x48, 0x48, 0x00,
  0x30, 0x48, 0x48, 0x48, 0x7E, 0x00,
  0x38, 0x54, 0x54, 0x54, 0x58, 0x00,
  0x00, 0x08, 0x7C, 0x0A, 0x00, 0x00,
  0x98, 0xA4, 0xA4, 0xA4, 0x78, 0x00,
  0x7E, 0x08, 0x08, 0x08, 0x70, 0x00,
  0x00, 0x00, 0x7A, 0x00, 0x00, 0x00,
  0x20, 0x40, 0x40, 0x3A, 0x00, 0x00,
  0x7E, 0x10, 0x28, 0x44, 0x00, 0x00,
  0x00, 0x00, 0x7E, 0x40, 0x00, 0x00,
  0x7C, 0x04, 0x78, 0x04, 0x78, 0x00,
  0x7C, 0x04, 0x04, 0x04, 0x78, 0x00,
  0x38, 0x44, 0x44, 0x44, 0x38, 0x00,
  0xFC, 0x24, 0x24, 0x24, 0x18, 0x00,
  0x18, 0x24, 0x24, 0x24, 0xFC, 0x00,
  0x7C, 0x08, 0x04, 0x04, 0x08, 0x00,
  0x48, 0x54, 0x54, 0x54, 0x24, 0x00,
  0x00, 0x04, 0x7E, 0x44, 0x00, 0x00,
  0x3C, 0x40, 0x40, 0x20, 0x7C, 0x00,
  0x1C, 0x20, 0x40, 0x20, 0x1C, 0x00,
  0x3C, 0x40, 0x30, 0x40, 0x3C, 0x00,
  0x44, 0x28, 0x10, 0x28, 0x44, 0x00,
  0x5C, 0xA0, 0xA0, 0xA0, 0x7C, 0x00,
  0x44, 0x64, 0x54, 0x4C, 0x44, 0x00,
  0x00, 0x08, 0x36, 0x41, 0x00, 0x00,
  0x00, 0x00, 0xFF, 0x00, 0x00, 0x00,
  0x00, 0x41, 0x36, 0x08, 0x00, 0x00,
  0x02, 0x01, 0x02, 0x04, 0x02, 0x00,
  0x3C, 0x26, 0x23, 0x26, 0x3C, 0x00,
  0x7E, 0xFF, 0xC3, 0xBD, 0xBD, 0xBD,
  0xDB, 0xFF, 0x83, 0xED, 0xED, 0xED,
  0x83, 0xFF, 0x81, 0xED, 0xED, 0xED,
  0xF3, 0xFF, 0x7E, 0x00, 0x00, 0x00,
  0x7E, 0xFF, 0xB3, 0xAD, 0xAD, 0xAD,
  0xCB, 0xFF, 0xC3, 0xBD, 0xBD, 0xBD,
  0xDB, 0xFF, 0x81, 0xED, 0xCD, 0xAD,
  0xF3, 0xFF, 0x7E, 0x00, 0x00, 0x00,
  0x7E, 0xFF, 0xE1, 0xDF, 0xBF, 0xDF,
  0xE1, 0xFF, 0xC3, 0xBD, 0xBD, 0xBD,
  0xC3, 0xFF, 0x81, 0xBF, 0xBF, 0xBF,
  0xBF, 0xFF, 0x7E, 0x00, 0x00, 0x00,
  0x7E, 0xFF, 0x81, 0xB5, 0xB5, 0xB5,
  0xCB, 0xFF, 0x81, 0xED, 0xCD, 0xAD,
  0xB3, 0xFF, 0xFD, 0xFD, 0x81, 0xFD,
  0xFD, 0xFF, 0x7E, 0x00, 0x00, 0x00,
  0x7E, 0x81, 0x4C, 0x52, 0x52, 0x52,
  0x34, 0x81, 0x7E, 0x00, 0x00, 0x00,
  0x7E, 0x81, 0x3C, 0x42, 0x42, 0x42,
  0x24, 0x81, 0x7E, 0x00, 0x00, 0x00,
  0x7E, 0xFF, 0x81, 0xFB, 0xE7, 0xFB,
  0x81, 0xFF, 0x83, 0xED, 0xED, 0xED,
  0x83, 0xFF, 0xC3, 0xBD, 0xBD, 0xBD,
  0xDB, 0xFF, 0x7E, 0x00, 0x00, 0x00,
  0x00, 0x03, 0x03, 0x03, 0x06, 0x18,
  0x30, 0x63, 0x63, 0x63, 0x00, 0x00,
  0x00, 0x00, 0x08, 0x0C, 0xBE, 0xBF,
  0xBE, 0x0C, 0x08, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x7E, 0x81, 0x3C, 0x42, 0x42, 0x42,
  0x24, 0x00, 0x7C, 0x12, 0x12, 0x12,
  0x7C, 0x00, 0x7E, 0x12, 0x12, 0x12,
  0x0C, 0x81, 0x7E, 0x00, 0x00, 0x00,
  0x7E, 0x81, 0x4C, 0x52, 0x52, 0x52,
  0x34, 0x00, 0x3C, 0x42, 0x42, 0x42,
  0x24, 0x00, 0x7E, 0x12, 0x32, 0x52,
  0x0C, 0x81, 0x7E, 0x00, 0x00, 0x00,
  0x7E, 0xFF, 0x81, 0xFB, 0xE7, 0xFB,
  0x81, 0xFF, 0x81, 0xB5, 0xB5, 0xB5,
  0xBD, 0xFF, 0x81, 0xBD, 0xBD, 0xBD,
  0xC3, 0xFF, 0x7E, 0x00, 0x00, 0x00,
  0x7E, 0xFF, 0x81, 0xB5, 0xB5, 0xB5,
  0xCB, 0xFF, 0x81, 0xEF, 0xF7, 0xEB,
  0x9D, 0xFF, 0x81, 0xBF, 0xBF, 0xBF,
  0xBF, 0xFF, 0x7E, 0x00, 0x00, 0x00,
  0x7E, 0x81, 0x7C, 0x12, 0x12, 0x12,
  0x7C, 0x81, 0x7E, 0x00, 0x00, 0x00,
  0x7E, 0x81, 0x3C, 0x42, 0x42, 0x52,
  0x34, 0x81, 0x7E, 0x00, 0x00, 0x00,
  0x7E, 0xFF, 0x81, 0xDF, 0xE7, 0xDF,
  0x81, 0xFF, 0xFF, 0xBD, 0x81, 0xBD,
  0xFF, 0xFF, 0x81, 0xFB, 0xF7, 0xCF,
  0x81, 0xFF, 0x7E, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x08, 0x0C, 0xFE, 0xFF,
  0xFE, 0x0C, 0x08, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x7E, 0xFF, 0xB3, 0xAD, 0xAD, 0xAD,
  0xCB, 0xFF, 0x7E, 0x00, 0x00, 0x00,
  0x7E, 0xFF, 0xC3, 0xBD, 0xBD, 0xBD,
  0xDB, 0xFF, 0x7E, 0x00, 0x00, 0x00,
  0x7E, 0xFF, 0x83, 0xED, 0xED, 0xED,
  0x83, 0xFF, 0x7E, 0x00, 0x00, 0x00,
  0x7E, 0xFF, 0xC3, 0xBD, 0xBD, 0xAD,
  0xCB, 0xFF, 0x7E, 0x00, 0x00, 0x00,
  0x7E, 0xFF, 0xC3, 0xBD, 0xBD, 0xBD,
  0xC3, 0xFF, 0x7E, 0x00, 0x00, 0x00,
  0x7E, 0xFF, 0xFF, 0xBB, 0x81, 0xBF,
  0xFF, 0xFF, 0x7E, 0x00, 0x00, 0x00,
  0x7E, 0xFF, 0x9B, 0xAD, 0xAD, 0xAD,
  0xB3, 0xFF, 0x7E, 0x00, 0x00, 0x00,
  0x7E, 0xFF, 0xDD, 0xBD, 0xB5, 0xB5,
  0xC9, 0xFF, 0x7E, 0x00, 0x00, 0x00,
  0x7E, 0xFF, 0xE7, 0xEB, 0xED, 0x81,
  0xFF, 0xFF, 0x7E, 0x00, 0x00, 0x00,
  0x7E, 0xFF, 0xD1, 0xB5, 0xB5, 0xB5,
  0xCD, 0xFF, 0x7E, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x77, 0x77, 0x77, 0x00,
  0x77, 0x77, 0x77, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x18, 0x0C, 0x06, 0x03,
  0x06, 0x0C, 0x18, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xE7, 0xA5, 0xFF, 0x24,
  0x24, 0xFF, 0xA5, 0xE7, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};