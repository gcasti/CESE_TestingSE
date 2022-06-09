# Testing Software Embebido

Repositorio que contiene la resolución de los trabajos prácticos del curso.

---
## Trabajo práctico 3. TDD.

Completar el trabajo presentado en clase para desarrollar un controlador de led utilizando la técnica de TDD. Se completan las siguientes pruebas:

1. Después de la inicialización todos los LEDs deben quedar apagados.
2. Se puede prender un LED individual.
3. Se puede apagar un LED individual.
4. Se pueden prender y apagar múltiples LED’s.
5. Se pueden prender todos los LEDs de una vez.
6. Se pueden apagar todos los LEDs de una vez.
7. Se puede consultar el estado de un LED.

---
## Trabajo práctico 4. Testing unitario.

### Enunciado
Seleccionar una biblioteca (o componente) del software a desarrollar en el TP final de la
carrera de especialización / maestría y escribir un test unitario con ceedling que incluya por
lo menos 5 test cases. El archivo de test debe tener por lo menos 65 líneas de extensión

### Propuesta
Realizar el desarrollo de una librería para cálculo de peso a partir de los datos adquiridos por un conversor analógico digital(AD) utilizando la técnica TDD y testing unitario.

Los datos de entrada son un entero signado de 32 bits. Se empleará una indicación booleana cuando existe un nuevo dato disponible.

### Requerimientos de la librería:

1. Siempre que exista un dato disponible debe calcularse el peso de la carga empleando la siguiente fórmula:
 __Weigth = m * code + Wzero - Wtare__

    Donde: 
    * Weigth: peso calculado
    * m    : pendiente para el cálculo del peso
    * code : código del AD 
    * Wzero : valor cero determinado por el usuario
    * Wtare : valor de tara determinado por el usuario 

2. Debe indicarse al usuario que existe un nuevo valor de peso calculado.

3. El valor **m** puede configurarse mediante el siguiente procedimiento
    * El usuario debe ingresar el valor del peso de referencia (Wref).
    * El usuario debe colocar el peso de referencia sobre la plataforma. 
    * Debe almacenarse el código del AD correspondiente en Cref
    * El usuario debe retirar el peso de referencia de la plataforma.
    * Debe almacenarse el código del AD correspondiente en Czero
    * Se calcula la pendiente como: m = Wref/(Cref - Czs)
    	
4. El usuario puede configurar el valor del peso cero almacenando en Wzero realizando un promedio configurable de los últimos valores de peso disponibles.

5. El usuario puede configurar el valor de la tara almacenanda en Wtare realizando un promedio configurable de los últimos valores de peso disponible.

6. Los valores del código del AD utilizados durante la calibración deben poder promediarse tomando una cantidad configurable de muestras.


### Test de la librería:
1. Al inicializarse la librería se verifica que el parámetro m tenga un valor de configuración disponible.

2. Si no existe un valor de configuración se indica al usuario que realice el procedimiento de calibración.

3. Se actualiza el cálculo del peso(Weigth) siempre que exista un valor del AD disponible.

4. Se indica al usuario que existe un nuevo valor de peso disponible.

5. Se puede leer el último valor de peso disponible.

6. Se puede calcular el peso promediando valores del código del AD.

7. Se puede configurar la cantidad de muestras que se promedian.

8. Se puede almacenar el valor del peso cero(Wzero) cuando el usuario lo solicite. 

9. Se puede almacenar el valor de la tara(Wtare) cuando el usuario lo solicite.

10. Los valores Wzero y Wtare se pueden calcular realizando el promedio según la cantidad de muestras que se configuró.

#### Test rutina calibración
TBC!




