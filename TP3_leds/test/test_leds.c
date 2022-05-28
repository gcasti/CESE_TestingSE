/*Después de la inicialización todos los LEDs deben quedar apagados.
• Se puede prender un LED individual.
• Se puede apagar un LED individual.
• Se pueden prender y apagar múltiples LED’s.
• Se pueden prender todos los LEDs de una vez.
• Se pueden apagar todos los LEDs de una vez.
• Se puede consultar el estado de un LED.
• Revisar limites de los parametros.
• Revisar parámetros fuera de los limites.*/

#include "unity.h"
#include "leds.h"
//#include "mock_errores.h"

static uint16_t virtual_leds;
   
void setUp(void){
   LedsInit(&virtual_leds);
}

void tearDown(void){
}

//Después de la inicialización todos los LEDs deben quedar apagados.
void test_LedsOffAfterCreate(void)
{
    virtual_leds = 0xFFFF;
    LedsInit(&virtual_leds);
    TEST_ASSERT_EQUAL_HEX16(0x0000,virtual_leds);
}

//Se puede prender un LED individual.
void test_TurnOnOneLed(void){
    LedTurnOn(5);
    TEST_ASSERT_EQUAL_HEX16(1 << 4 , virtual_leds);
}

//Se puede apagar un LED individual.
void test_TurnOffOneLed(void){
    LedTurnOn(5);
    LedTurnOff(5);
    TEST_ASSERT_EQUAL_HEX16(0x0000 , virtual_leds);
}

//Se pueden prender y apagar múltiples LED’s.
void test_TurnOnAndOffManyLeds(void){
    LedTurnOn(5);
    LedTurnOn(5);
    LedTurnOn(11);
    LedTurnOff(3);
    LedTurnOff(11);
    TEST_ASSERT_EQUAL_HEX16( 1 << 4 , virtual_leds);
}

/*void test_InvalidUpperLimitTurnOnLed(void){
    RegistrarMensaje_Expect(ALERTA, "LedTurnOn",0,"Numero de led invalido");
    RegistrarMensaje_IgnoreArg_linea();
    LedTurnOn(17);
}*/