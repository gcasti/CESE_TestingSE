# Testing Software Embebido

Repositorio que contiene la resolución de los trabajos prácticos del curso.

## Trabajo práctico 3. TDD.

Completar el trabajo presentado en clase para desarrollar un controlador de led utilizando la técnica de TDD. Se completan las siguientes pruebas:

1. Después de la inicialización todos los LEDs deben quedar apagados.
2. Se puede prender un LED individual.
3. Se puede apagar un LED individual.
4. Se pueden prender y apagar múltiples LED’s.
5. Se pueden prender todos los LEDs de una vez.
6. Se pueden apagar todos los LEDs de una vez.
7. Se puede consultar el estado de un LED.

## Trabajo práctico 4. Testing unitario.

## Enunciado
Seleccionar una biblioteca (o componente) del software a desarrollar en el TP final de la
carrera de especialización / maestría y escribir un test unitario con ceedling que incluya por
lo menos 5 test cases. El archivo de test debe tener por lo menos 65 líneas de extensión

## Propuesta
Realizar el desarrollo de una librería para cálculo de peso a partir de los datos que provenientes de un conversor analógico digital utilizando la técnica TDD y testing unitario

### Requerimientos de la librería:

1. Siempre que exista un dato disponible debe calcularse el peso de la carga empleando la fórmula siguiente: Weigth = m*code + Wzero - Wtare

Donde: 
* Weigth: Peso calculado
* m   = pendiente para el cálculo del peso
* code= código de entrada 
* Wzs = valor del cero determinado por el usuario
* Wt  = valor de tara determinado por el usuario 

2. El dato de entrada corresponde a un entero con signo de 32 bits que representa las valores de un conversor analógico digital(AD). Se emplea una indicación booleana cuando exite un nuevo dato disponible.

3. Deben almacenarse los parámetros m , Wzs y Wt. 

4. El valor m puede configurarse mediante el siguiente procedimiento
* El usuario ingresa el valor del peso de referencia (Wref)
* El usuario coloca el peso de referencia 
* Se almacena el código del AD correspondiente en Cref
* El usuario retira el peso de referencia
* Se almacena el código del AD correspondiente en Czero
* Se calcula la pendiente como: m = Wref/(Cref - Czs)
	
5. El usuario puede configurar el valor del peso cero almacenando en Wzero adquiriendo último valor de peso disponible.

6. El usuario puede configurar el valor de la tara almacenanda en Wtare adquiriendo último valor de peso disponible.

7. Los valores del código del AD utilizados deben poder promediarse tomando una cantidad configurable de muestras. 



