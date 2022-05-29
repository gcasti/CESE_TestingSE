/*
1) Después de la inicialización todos los LEDs deben quedar apagados.
2) Se puede prender un LED individual.
3) Se puede apagar un LED individual.
4) Se pueden prender y apagar múltiples LED’s.
5) Se pueden prender todos los LEDs de una vez.
6) Se pueden apagar todos los LEDs de una vez.
7) Se puede consultar el estado de un LED.
8) Revisar limites de los parametros.
9) Revisar parámetros fuera de los limites.*/

#include "unity.h"
#include "leds.h"

static uint16_t virtual_leds;
   
void setUp(void){
   LedsInit(&virtual_leds);
}

void tearDown(void){
}

// 1) Después de la inicialización todos los LEDs deben quedar apagados.
void test_LedsOffAfterCreate(void)
{
    virtual_leds = 0xFFFF;
    LedsInit(&virtual_leds);
    TEST_ASSERT_EQUAL_HEX16(0x0000,virtual_leds);
}

// 2) Se puede prender un LED individual.
void test_TurnOnOneLed(void){
    LedTurnOn(5);
    TEST_ASSERT_EQUAL_HEX16(1 << 4 , virtual_leds);
}

// 3) Se puede apagar un LED individual.
void test_TurnOffOneLed(void){
    LedTurnOn(5);
    LedTurnOff(5);
    TEST_ASSERT_EQUAL_HEX16(0x0000 , virtual_leds);
}

// 4) Se pueden prender y apagar múltiples LED’s.
void test_TurnOnAndOffManyLeds(void){
    LedTurnOn(5);
    LedTurnOn(5);
    LedTurnOn(11);
    LedTurnOff(3);
    LedTurnOff(11);
    TEST_ASSERT_EQUAL_HEX16( 1 << 4 , virtual_leds);
}

// 5) Se pueden prender todos los LEDs de una vez.
void test_TurnOnAllLeds(void){
    int i = 0;
    for(i=0;i < 15;i++)
    {
        LedTurnOff(i);
    }
    LedTurnOnAll();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF,virtual_leds);
}

// 6) Se pueden apagar todos los LEDs de una vez.
void test_TurnOffAllLed(void){
    LedTurnOnAll();
    LedTurnOffAll();
    TEST_ASSERT_EQUAL_HEX16(0x0000 , virtual_leds);
}
