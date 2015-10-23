# pthread

En esta carpeta están los archivos del taller de sistemas distribuidos.

- Ejemplo 3s-00-mod
Este ejemplo se modificó para calcular el tiempo de ejecucíon de las funciones de inicialización y de conteo en el vector, usando variables tipo struct timeval, que tienen un campo que cuenta secundos y otro para microsegundos.

- Ejemplo 3s-01-mod

En este ejemplo se trató de implementar los tiempos de ejecución de los hilos, pero el programa tiene un error inherente que no permite calcular estos tiempos. Las preguntas de este ejemplo:
    - El vector grande tiene un tamaño de 1.000.000.000 * 4bytes (tamaño de las variables int); esto es, 4GB.
    - El programa no está bien implementado. La cuenta que hace al crear los 8 hilos no llega al valor total de 3s en el vector, porque termina antes de que terminen los hilos de ejecución. Esta es también la razón por la cual no se pudo calcular el tiempo de ejecución de cada hilo.

- Ejemplo 3s-02-mod

En este ejemplo los valores resultantes de la cuenta no son iguales. Esto se da por un efecto llamado "race condition". Este efecto se da porque en algún momento dos (o más hilos) están incrementando la variable "count", y al devolver al mismo tiempo el valor de esta variable a memoria solo se incrementa una sola vez, independiente de que sean varios hilos simultaneamente que estén tratando de incrementar esta variable.

- 

