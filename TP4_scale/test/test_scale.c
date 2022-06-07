/* Test de la librería:
1. Al inicializarse la librería se verifica el parámetro m tenga un valor de configuración disponible.
2. Si no existe un valor de configuración se indica al usuario que realice el procedimiento de calibración.
3. Se actualiza el cálculo del peso(Weigth) siempre que exista un valor del AD disponible.
4. Se indica al usuario que existe un nuevo valor de peso disponible.
5. Se puede leer el último valor de peso disponible.
6. Se puede calcular el peso promediando una cantidad configurable de valores del código del AD.
7. Se puede configurar la cantidad de muestras que se promedian.
8. Se puede almacenar el valor del peso cero(Wzero) cuando el usuario lo solicite. 
9. Se puede almacenar el valor de la tara(Wtare) cuando el usuario lo solicite.
10. Los valores Wzero y Wtare se pueden calcular realizando el promedio según la cantidad de muestras que se configuró.
*/

#include "unity.h"
#include "mock_ads1232.h"
#include "stdbool.h"
#include "scale.h"

void setUp(void)
{
    scale_init();
}

void tearDown(void)
{
}

// 1. Al inicializarse la librería se verifica el parámetro m tenga un valor de configuración disponible.
void test_init_scale(void)
{
    bool test_config = false;
    
    test_config = scale_init(); 
    
    TEST_ASSERT_TRUE(test_config);
}

// 2. Si no existe un valor de configuración se indica al usuario que realice el procedimiento de calibración.
void test_config_scale(void)
{
    bool test_config = false;

    test_config = scale_getConfigStatus();

    TEST_ASSERT_TRUE_MESSAGE(test_config,"Realice la calibracion");
}

bool aux_ads1232_newValue(void)
{
    return true;
}
int32_t aux_ads1232_readCode(void)
{
    return 8542;
}

// 3. Se actualiza el cálculo del peso(Weigth) siempre que exista un valor del AD disponible.
void test_updateWeigth(void)
{
    float weigth = 0;
    bool new_value = false;
    ads1232_newValue_fake.custom_fake = aux_ads1232_newValue;
    ads1232_readCode_fake.custom_fake = aux_ads1232_readCode;
 
    new_value = scale_newWeigth();
    TEST_ASSERT_FALSE(new_value);

    // Se simula la presencia de un valor del AD
    bool ads1232_newValue = true;       
    if(ads1232_newValue){
        weigth = scale_updateWeigth();
    }
    TEST_ASSERT_TRUE(scale_newWeigth);
    TEST_ASSERT_FLOAT_WITHIN (0.01f, 8542, weigth);

}
