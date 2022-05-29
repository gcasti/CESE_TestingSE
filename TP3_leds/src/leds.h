#ifndef _LEDS_H
#define _LEDS_H

#include <stdint.h>
#include <stdbool.h>
/**Documentar
*/
void LedsInit(uint16_t * direction);

void LedTurnOn(uint8_t led);

void LedTurnOff(uint8_t led);

void LedTurnOnAll(void);

void LedTurnOffAll(void);

bool getStateLed(uint8_t led);
      
#endif