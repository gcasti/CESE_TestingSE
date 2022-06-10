/*
 * ads1232.h
 *
 *  Created on: 14 abr. 2022
 *      Author: Guillermo Luis Castiglioni
 */

#ifndef INC_ADS1232_H_
#define INC_ADS1232_H_

#ifdef __cplusplus
extern "C" {
#endif

/** =====[Inclusión de dependencia públicas ]==========================*/
#include <stdint.h>
#include <stdbool.h>

/** =====[Definición de tipos de datos públicos ]==========================*/
typedef bool bool_t;

/**
 *  Definición de ganancias disponibles
 */
typedef enum {
	GAIN1 = 1,
	GAIN2 = 2,
	GAIN64 = 64,
	GAIN128 = 128
} gain_t;

/*
 * Definición de canales de entradas disponibles
 */
typedef enum {
	CHANNEL_IN1 ,
	CHANNEL_IN2 ,
	CHANNEL_TEMP
} analog_input_t;

/*
 * Definición de velocidad de adquisición
 */
typedef enum {
	LOW_SPEED = 0,		/* 10 SPS */
	HIGH_SPEED = 1		/* 80 SPS */
} speed_t;

typedef enum {
	PWR_ENABLE = 0 ,
	PWR_DISABLE = 1
} pwr_t;


/*
 *  Estructura que almacena el estado de configuración del ADC
 */

typedef struct {
	gain_t gain  ;	  				// Indica la ganancia que se encuentra seteada
	analog_input_t analog_input ;	// Indica el canal que se encuentra seleccionado
	speed_t speed;					// Indica la velocidad de adquisición
	pwr_t pwr;						// Indica si el modo de bajo consumo está activado
}configADS1232_t;

/** =====[Declaración de funciones públicas ]==========================*/

/***********************************************************************
 *  @brief Inicialización del driver
 *
 *  @details
 *   	Se inicia el driver empleando una configuración por defecto
 *   	CHANNEL_IN1,GAIN1,LOW_SPEED,PWR_DISABLE
 *
 *  @param		None
 *  @return     None
 *  @warning 	Se presupone que el hardware del SPI y GPIO se encuentra
 *  			inicializado
 **********************************************************************/
void ads1232_InitDriver();

/***********************************************************************
 *  @brief Inicialización de la lectura continua de datos
 *
 *  @param		None
 *  @return     None
 **********************************************************************/
void ads1232_Start();

/***********************************************************************
 *  @brief Se detiene la lectura continua de datos
 *
 *  @param		None
 *  @return     None
 **********************************************************************/
void ads1232_Stop();

/***********************************************************************
 *  @brief Indica si existe un dato disponible almacenado en el driver
 *
 *  @param		None
 *  @return     true: existe un dato disponible para leer
 *  			false: caso contrario
 **********************************************************************/
bool_t ads1232_newData(void);

/***********************************************************************
 *  @brief Lectura de un dato adquirido
 *
 *  @param		None
 *  @return     Valor de tensión en mV
 **********************************************************************/
float ads1232_readData(void);

/***********************************************************************
 *  @brief Lectura del código de un dato adquirido
 *
 *  @param		None
 *  @return     Valor en cuentas del dato adquirido
 *  @warning	El valor adquirido es de 24 bits, se completa el resto
 *  			con ceros
 **********************************************************************/
int32_t ads1232_readCode(void);

/***********************************************************************
 *  @brief Coloca el AD en modo apagado
 *
 *  @param		None
 *  @return     None
 **********************************************************************/
void ads1232_EnablePowerDown(void);

/***********************************************************************
 *  @brief Enciende la adquisición del AD
 *
 *  @param		None
 *  @return     None
 **********************************************************************/
void ads1232_DisablePowerDown(void);

/***********************************************************************
 *  @brief Adquisición  en alta velocidad
 *
 *  @details Se configura la frecuencia de adquisición en 80SPS
 *
 *  @param		None
 *  @return     None
 **********************************************************************/
void ads1232_EnabletHighSpeed(void);

/***********************************************************************
 *  @brief Adquisición en baja velocidad
 *
 *  @details Se configura la frecuencia de adquisición en 10SPS
 *
 *  @param		None
 *  @return     None
 **********************************************************************/
void ads1232_DisabletHighSpeed(void);

/***********************************************************************
 *  @brief Configura el canal de entrada
 *
 *  @param		canal de entrada
 *  			CHANNEL_IN1,CHANNEL_IN1,CHANNEL_TEMP
 *  @return     None
 **********************************************************************/
void ads1232_ConfigInput(analog_input_t channel);

/***********************************************************************
 *  @brief Configura la ganancia del PGA
 *
 *  @param		ganancia
 *  			GAIN1,GAIN2,GAIN64,GAIN128
 *  @return     None
 **********************************************************************/
void ads1232_ConfigGain(gain_t gain);


configADS1232_t ads1232_GetConfig(void);


/***********************************************************************
 *  @brief Lectura de datos
 *
 *  @details
 *		Función que debe ejecutarse en la rutina de interrupción del módulo
 *		GPIO para manejo del pin DRDY
 *
 *  @param		None
 *  @return     None
 **********************************************************************/
void _IRQ_ads1232(void);

#ifdef __cplusplus
}
#endif

#endif /* INC_ADS1232_H_ */

