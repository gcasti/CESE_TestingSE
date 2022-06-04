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

void setUp(void)
{
}

void tearDown(void)
{
}

// test ceedling
void test_init_project(void){
    TEST_FAIL_MESSAGE("Proyecto inicial");
}
