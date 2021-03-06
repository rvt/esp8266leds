#pragma once
#include <stdint.h>
#include "leds.h"


/*
   IR Remote
   Encoding: NEC
   +------+------+------+------+
   |  UP  | Down | OFF  |  ON  |
   +------+------+------+------+
   |  R   |  G   |  B   |  W   |
   +------+------+------+------+
   |  1   |  2   |  3   |FLASH |
   +------+------+------+------+
   |  4   |  5   |  6   |STROBE|
   +------+------+------+------+
   |  7   |  8   |  9   | FADE |
   +------+------+------+------+
   |  10  |  11  |  12  |SMOOTH|
   +------+------+------+------+
*/

#ifdef IR_REMOTE
#define ARILUX_IR_CODE_KEY_UP 0xFF906F
#define ARILUX_IR_CODE_KEY_DOWN 0xFFB847
#define ARILUX_IR_CODE_KEY_OFF 0xFFF807
#define ARILUX_IR_CODE_KEY_ON 0xFFB04F
#define ARILUX_IR_CODE_KEY_R 0xFF9867
#define ARILUX_IR_CODE_KEY_G 0xFFD827
#define ARILUX_IR_CODE_KEY_B 0xFF8877
#define ARILUX_IR_CODE_KEY_W 0xFFA857
#define ARILUX_IR_CODE_KEY_1 0xFFE817
#define ARILUX_IR_CODE_KEY_2 0xFF48B7
#define ARILUX_IR_CODE_KEY_3 0xFF6897
#define ARILUX_IR_CODE_KEY_FLASH 0xFFB24D
#define ARILUX_IR_CODE_KEY_4 0xFF02FD
#define ARILUX_IR_CODE_KEY_5 0xFF32CD
#define ARILUX_IR_CODE_KEY_6 0xFF20DF
#define ARILUX_IR_CODE_KEY_STROBE 0xFF00FF
#define ARILUX_IR_CODE_KEY_7 0xFF50AF
#define ARILUX_IR_CODE_KEY_8 0xFF7887
#define ARILUX_IR_CODE_KEY_9 0xFF708F
#define ARILUX_IR_CODE_KEY_FADE 0xFF58A7
#define ARILUX_IR_CODE_KEY_10 0xFF38C7
#define ARILUX_IR_CODE_KEY_11 0xFF28D7
#define ARILUX_IR_CODE_KEY_12 0xFFF00F
#define ARILUX_IR_CODE_KEY_SMOOTH 0xFF30CF
#endif

/*
   RF Remote
   Encoding: Chinese Protocol 1
   Codes provided by KmanOz (https://github.com/KmanOz)
   +--------+--------+--------+
   |   ON   | Toggle |   OFF  |
   +--------+--------+--------+
   | Speed+ | Mode+  | Bright+|
   +--------+--------+--------+
   | Speed- | Mode-  | Bright-|
   +--------+--------+--------+
   |  RED   | GREEN  |  BLUE  |
   +--------+--------+--------+
   | ORANGE | LT GRN | LT BLUE|
   +--------+--------+--------+
   | AMBER  |  CYAN  | PURPLE |
   +--------+--------+--------+
   | YELLOW |  PINK  | WHITE  |
   +--------+--------+--------+
*/

#ifdef RF_REMOTE
#define ARILUX_REMOTE_KEY_ON (REMOTE_CODE + 0x01)
#define ARILUX_REMOTE_KEY_TOGGLE (REMOTE_CODE + 0x02)
#define ARILUX_REMOTE_KEY_OFF (REMOTE_CODE + 0x03)
#define ARILUX_REMOTE_KEY_SPEED_PLUS (REMOTE_CODE + 0x04)
#define ARILUX_REMOTE_KEY_MODE_PLUS (REMOTE_CODE + 0x05)
#define ARILUX_REMOTE_KEY_BRIGHT_PLUS (REMOTE_CODE + 0x06)
#define ARILUX_REMOTE_KEY_SPEED_MINUS (REMOTE_CODE + 0x07)
#define ARILUX_REMOTE_KEY_MODE_MINUS (REMOTE_CODE + 0x08)
#define ARILUX_REMOTE_KEY_BRIGHT_MINUS (REMOTE_CODE + 0x09)
#define ARILUX_REMOTE_KEY_RED (REMOTE_CODE + 0x0A)
#define ARILUX_REMOTE_KEY_GREEN (REMOTE_CODE + 0x0B)
#define ARILUX_REMOTE_KEY_BLUE (REMOTE_CODE + 0x0C)
#define ARILUX_REMOTE_KEY_ORANGE (REMOTE_CODE + 0x0D)
#define ARILUX_REMOTE_KEY_LTGRN (REMOTE_CODE + 0x0E)
#define ARILUX_REMOTE_KEY_LTBLUE (REMOTE_CODE + 0x0F)
#define ARILUX_REMOTE_KEY_AMBER (REMOTE_CODE + 0x10)
#define ARILUX_REMOTE_KEY_CYAN (REMOTE_CODE + 0x11)
#define ARILUX_REMOTE_KEY_PURPLE (REMOTE_CODE + 0x12)
#define ARILUX_REMOTE_KEY_YELLOW (REMOTE_CODE + 0x13)
#define ARILUX_REMOTE_KEY_PINK (REMOTE_CODE + 0x14)
#define ARILUX_REMOTE_KEY_WHITE (REMOTE_CODE + 0x15)
#endif

/**
 * PWM LEDS using Standard Arduino methods
 */

class PwmLeds : public Leds {
private:
    const uint8_t m_redPin;
    const uint8_t m_greenPin;
    const uint8_t m_bluePin;
    const uint8_t m_white1Pin;
    const uint8_t m_white2Pin;

    mutable float m_lastRed;
    mutable float m_lastGreen;
    mutable float m_lastBlue;
    mutable float m_lastWhite1;
    mutable float m_lastWhite2;
public:
    PwmLeds(const uint8_t red_pin, const uint8_t green_pin, const uint8_t blue_pin, const uint8_t white1_pin, const uint8_t white2_pin);
    bool init(void) const;
    virtual bool setAll(const float p_red, const float p_green, const float p_blue, const float p_white1, const float p_white2) const;

};
