# pthread

En esta carpeta están los archivos del taller de sistemas distribuidos.

- Ejemplo 3s-00-mod
Este ejemplo se modificó para calcular el tiempo de ejecucíon de las funciones de inicialización y de conteo en el vector, usando variables tipo struct timeval, que tienen un campo que cuenta secundos y otro para microsegundos.

- Ejemplo 3s-01-mod

En este ejemplo se trató de implementar los tiempos de ejecución de los hilos, pero el programa tiene un error inherente que no permite calcular estos tiempos. Las preguntas de este ejemplo:
    - El vector grande tiene un tamaño de 1.000.000.000 * 4bytes (tamaño de las variables int); esto es, 4GB.
    - El programa no está bien implementado. La cuenta que hace al crear los 8 hilos no llega al valor total de 3s en el vector, porque termina antes de que terminen los hilos de ejecución. Esta es también la razón por la cual no se pudo calcular el tiempo de ejecución de cada hilo.

- Ejemplo 3s-02-mod

En este ejemplo los valores resultantes de la cuenta no son iguales. Esto se da por un efecto llamado "race condition". Este efecto se da porque en algún momento dos (o más hilos) están incrementando la variable "count", y al devolver al mismo tiempo el valor de esta variable a memoria solo se incrementa una sola vez, independiente de que sean varios hilos simultaneamente que estén tratando de incrementar esta variable. Para visualizar el tiempo de ejecución de los hilos cambia algo respecto a los ejemplos anteriores: En este caso se vuelve a mostrar cuando empieza el hilo a ejecutarse, y cuando termina la ejecución indica el número del hilo y cuánto tiempo se demoró en su ejecución.

- Ejemplo 3s-03-mod

En este ejemplo, los valores si son correctos. La manera en que se logra esto es usando los "mutex", que reservan el acceso de una variable, de manera que no suceda lo misom del ejemplo 3s-02-mod, en el que hilos concurrentes buscaban modificar al tiempo una variable y esta solo se modificaba una vez. El tiempo total de la cuenta de 3s en el vector se extendió bastante, fué de 502 segundos; icluso mayor que en los casos secuenciales (entre 150 y 250 segundos).

- Ejemplo 3s-04-mod

La gran diferencia entre este ejemplo y el 3s-03-mod radica en que el mutex (la opción de reservar una variable durante cada hilo de ejecución) no se hace antes de todo el ciclo de cada hilo, sino que se bloquea únicamente al modificar el contador. El tiempo promedio de 3 ejecuciones del ejemplo 3s-03 fue de 286.72 segundos, mientras que en el caso del ejemplo 3s-04 fue de 88.59 segundos. Esta diferencia se explica porque el ejemplo 3 es parecido a la versión secuencial (con la adición de las creaciones de los hilos); mientras que el ejemplo 4 si es en paralelo, reservando unicamente cada vez cuando se incrementa, haciendo de manera paralela el incremento de los índices de búsqueda del vector.

- Ejemplo 3s-05-mod

En este caso el programa se ejecuta rápido para los primeros 6 hilos creados, y para los dos últimos hay una demora mayor. En general es más ágil que los anteriores, la manera de implementar el contado privado e incrementar la variable compartida al terminar de ejecutarse le da un plus de agilidad; pero no se observó una mejora significativa respecto al ejemplo 04 (tiempo de conteo: 96.31, comparado con los 88.59 de promedio del ejemplo 04); aunque si fue más ágil que algunas de las ejecuciones del ejemplo anterior.

