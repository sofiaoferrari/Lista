# TDA Lista
#### Algoritmos y Programacion II
#
#
### - Introduccion:
Este programa fue realizado para fortalecer los conocimientos sobre los TDA Lista, Pila, Cola e Iteradores externo e interno. Para ello se tuvo que llevar a cabo la cracion de cada uno de ellos, respetando sus caracteristicasde funcionamiento.
### - Funcionamiento: 
Para la creacion de cada uno de los TDA se tuvo que realizar mediante distintas funciones. Primero se realizaron las de lista que son las mas generales e importantes (en este caso). Luego se crearon las de Pila y Cola, en la mayoria de los casos, reutilizando algunas de las funciones previas de Lista ya que, dependiendo la accion, son muy similares. Por ultimo se crearon ambos iteradores, tanto externo como interno, cumpliendo la funcion de iterar la lista creada previamente con las funciones de Lista.

### - Compilacion:
 El programa debe ser compilado mediante gcc con la siguiente linea de compilacion:
```sh
gcc pruebas.c lista.c -o lista_se -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0
```
O tambien se puede realizar utilizando el makefile con la siguiente linea:
 ```sh     
    make compilar
``` 

### - Ejecucion:
Una vez compilado se debe ejecutar con la siguiente linea de ejecuccion:
```sh     
   ./lista_se
```
O tambien se puede realizar utilizando el makefile con la siguiente linea:
 ```sh     
    make ejecutar
``` 

#
### Conceptos a saber:
#
#### 1. Lista

>Una lista es una agrupacion de elementos de cualquier tipo de dato. Cada uno de estos elementos tiene un sucesor (menos el ultimo) y un procesor (menos el primero). Una vez creada (create) la lista, esta se crea vacia (isEmpty) y tiene la particularidad de que, a diferencia de los TDA Pila y Cola, puede acceder a cualquiera de sus elementos y eleminarlos (deleteAt), asi como tambien puede insertar (insertAt) un nuevo elemento en cualquier parte de la misma. Cuando ya no se utilice mas la lista, esta se debe destruir (destroy).

**- Diferencias entre simple y doblemente enlazadas:**
    Lista simple y doblemente enlzada son dos tipos de lista, y ambas utilizan la implementacion de nodos. La diferencia que tienen es que, la lista simplemente enlazada contiene nodos con un puntero a su nodo siguiente, por lo que siempre se va a poder recorrer la lista hacia adelante, sin poder retroceder. Mientras que la lista doblemente enlazada contiene nodos con punteros a su nodo siguiente y a su nodo anterior, permitiendo recorrer la lista en ambos sentidos.

#### 2. Pila y Cola
>La pila es una estructura de cualquier tipo de dato. Asi como la lista, tambien agrupa elementos pero respetando la regla LIFO (Last in, First Out). Esto quiere decir que, una vez creada (create) la pila vacia (isEmpty), a esta se le pueden ir apilando (push) elementos pero siempre "por encima" del ultimo apilado, donde su ultimo elemento es el tope (top). Cuando se quieran desapilar (pop) elementos, tambien va a ser desde el ultimo apilado. 
Por otro lado, la cola tambien es una estructura de datos, pero FIFO (First in, First Out). Cuando se crea la cola, los elementos se van a encolando a lo ultimo, es decir, despues del ultimo elemento ingresado y cuando se quieran desencolar va a comenzar por el primero que se encolo, y asi. Tanto pila como cola deben ser destruidos cuando no se quieran utilizar mas.

#### 3. Iterador
>Un iterador es un TDA auxiliar, el cual guarda la informacion que se necesita para optimizar los accesos a la estructura de la lista.
**Iterador externo e iterador interno**
La diferencia entre iterador externo e interno, es que el externo recorre la lista a traves de un puntero a sus nodos, el cual va cambiando de posicion a la siguiente por cada iteracion, mientras que el interno va accediendo a sus elementos a traves de un puntero. Esto provoca un cambio de complejidad O(n) en listas a O(1) en iteradores
