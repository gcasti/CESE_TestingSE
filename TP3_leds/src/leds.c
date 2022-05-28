#include "leds.h"

#define LED_TO_BIT_OFFSSET  1
#define BIT_MASK            1
#define LEDS_ALL_OFF        0

static uint16_t * port;

uint16_t LedToMask(uint8_t led){
    return (LED_TO_BIT_OFFSSET << (led -BIT_MASK));
}

void LedsInit(uint16_t * direction){
    port = direction;
    *port = LEDS_ALL_OFF;
}

void LedTurnOn(uint8_t led){
    *port |= LedToMask(led);
}

void LedTurnOff(uint8_t led){
    *port &= ~LedToMask(led);
}