#ifndef _LEDS_H
#define _LEDS_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Configura el módulo y apaga todos los leds
 * 
 * @param direction Dirección del puerto GPIO que controla los leds
 */
void LedsInit(uint16_t * direction);

/**
 * @brief Prende un led
 * 
 * @param led Número de led a prender (1 a 16)
 */
void LedTurnOn(uint8_t led);

/**
 * @brief Apaga un led
 * 
 * @param led Número de led a apagar (1 a 16)
 */
void LedTurnOff(uint8_t led);

/**
 * @brief Prende todos los leds
 * 
 */
void LedTurnOnAll(void);

/**
 * @brief Apaga todos los leds
 * 
 */
void LedTurnOffAll(void);

/**
 * @brief Obtiene el estado de un led específico
 * 
 * @param led Número de led a apagar (1 a 16)
 * @return true : led prendido
 * @return false : led apagado 
 */
bool getStateLed(uint8_t led);
      
#endif