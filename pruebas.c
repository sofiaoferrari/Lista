#include "lista.h"
#include "pa2mm.h"
#include <stdio.h>

#define EXITO 0
#define ERROR -1
#define VACIA 0
#define PRIMERO 0
#define UNITARIA 1


void probar_si_elementos_son_los_esperados(lista_t* lista, char elementos[]) {
    int es_el_esperado = false;
    for(size_t i=0; i<lista_elementos(lista); i++) {
        if (elementos[i] == *(char*)lista_elemento_en_posicion(lista, i))
            es_el_esperado = true;
        switch (i) {
        case 0:
            pa2m_afirmar(es_el_esperado,"El 1er elemento es el esperado");
            break;
        case 1:
            pa2m_afirmar(es_el_esperado,"El 2ndo elemento es el esperado");
            break;
        case 2:
            pa2m_afirmar(es_el_esperado,"El 3er elemento es el esperado");
            break;
        case 3:
            pa2m_afirmar(es_el_esperado,"El 4to elemento es el esperado");
            break;
        case 4:
            pa2m_afirmar(es_el_esperado,"El 5to elemento es el esperado");
            break;
        case 5:
            pa2m_afirmar(es_el_esperado,"El 6to elemento es el esperado");
            break;
        }
        
    }
}

void insertar_elementos(lista_t* lista, char elementos[]) {
    size_t i=0;
    for (; i < 4; i++) {
        lista_insertar(lista, &elementos[i]);
    }
    pa2m_afirmar((i == 4), "Puedo insertar 4 elementos a la lista");
}

lista_t* probar_creacion(const char* AFIRMACION) {
    lista_t* nueva_lista = lista_crear();
    bool creacion = true;
    if (!nueva_lista) creacion = false;
    pa2m_afirmar(creacion, AFIRMACION);
    return nueva_lista;
}

bool funcion_iterar(void* elemento, void* contador){
    char elementos[] = {'a','c','b','d'};
    if(elemento && contador)
        pa2m_afirmar((*(char*)elemento == elementos[*(int*)contador]),"El elemento iterado es el esperado");
        (*(int*)contador)++;
    return true;
}

void pruebas_de_iterador_in() {
    char elementos[] = {'a','c','b','d'};
    int contador=0;
    size_t iterados = 0;
    iterados = lista_con_cada_elemento(NULL, funcion_iterar, (void*)&contador);
    pa2m_afirmar(iterados == 0,"No se puede iterar si la lista no existe");
    lista_t* lista = lista_crear();
    iterados = lista_con_cada_elemento(lista, funcion_iterar, (void*)&contador);
    pa2m_afirmar(iterados == 0,"No se puede iterar si la lista esta vacia");
    iterados = lista_con_cada_elemento(lista, insertar_elementos, (void*)&contador);
    pa2m_afirmar(iterados == 0,"No se puede iterar si la funcion de iteracion no existe");
    insertar_elementos(lista, elementos);
    iterados = lista_con_cada_elemento(lista, funcion_iterar, (void*)&contador);
    pa2m_afirmar(iterados == 4,"La cantidad de iterados es correcta");
    lista_destruir(lista);
    printf("\n");

}

void recorro_lista_iterador_ex(lista_iterador_t* iterador, char elementos[]) {
    bool coinciden = false;
    int i = 0;
    for(iterador; lista_iterador_tiene_siguiente(iterador); lista_iterador_avanzar(iterador)) {
        coinciden =  (elementos[i] == *(char*)lista_iterador_elemento_actual(iterador));
        switch (i) {
        case 0:
            pa2m_afirmar(coinciden,"El 1er elemento iterado es el esperado");
            break;
        case 1:
            pa2m_afirmar(coinciden,"El 2ndo elemento iterado es el esperado");
            break;
        case 2:
            pa2m_afirmar(coinciden,"El 3er elemento iterado es el esperado");
            break;
        case 3:
            pa2m_afirmar(coinciden,"El 4to elemento iterado es el esperado");
            break;
        }
        i++;
    }
}

void pruebas_de_iterador_ex() {
    char elementos[] = {'a','c','b','d'};
    lista_iterador_t* iterador_null = lista_iterador_crear(NULL);
    pa2m_afirmar(!iterador_null, "No puedo crear un iterador externo si la lista no existe");
    lista_t* lista = lista_crear();
    lista_iterador_t* iterador_vacio = lista_iterador_crear(lista);
    pa2m_afirmar(iterador_vacio, "Puedo crear un iterador externo con una lista vacia");
    pa2m_afirmar(!lista_iterador_tiene_siguiente(iterador_vacio), "El iterador no tiene siguiente");
    pa2m_afirmar(!lista_iterador_avanzar(iterador_vacio), "No puedo avanzar");
    lista_iterador_destruir(iterador_vacio);
    insertar_elementos(lista, elementos);
    lista_iterador_t* iterador = lista_iterador_crear(lista);
    pa2m_afirmar(iterador, "Puedo crear un iterador externo con una lista de 4 elementos");
    recorro_lista_iterador_ex(iterador, elementos);
    lista_iterador_destruir(iterador);
    lista_destruir(lista);
    printf("\n");
}

void desencolar_elementos(lista_t* cola, char elementos[]) {
    int i = 0;
    bool coinciden = false;
    int se_pudo = ERROR;
    while (i < 4) {
        coinciden = (*(char*)lista_primero(cola) == elementos[i]);
        pa2m_afirmar(coinciden, "El primer elemento de la cola es el esperado");
        se_pudo = lista_desencolar(cola);
        pa2m_afirmar(!se_pudo, "Puedo desencolar un elemento de la cola");
        i++;
    }
}

int encolar_elementos(lista_t* cola, char elementos[]) {
    int i = 0;
    int corte = EXITO;
    while (!corte && (i < 4)) {
        corte = lista_encolar(cola, &elementos[i]);
        i++;
    }
    return (i == 4);
}

void pruebas_de_cola() {
    char elementos[] = {'a','c','b','d'};
    pa2m_afirmar(lista_primero(NULL) == NULL , "El primer elemento de la cola es NULL cuando no existe");
    lista_t* cola = lista_crear();
    pa2m_afirmar(lista_primero(cola) == NULL , "El primer elemento de la cola es NULL cuando esta vacia");
    int se_pudo = encolar_elementos(cola, elementos);
    pa2m_afirmar(se_pudo, "Puedo encolar 4 elementos");
    desencolar_elementos(cola, elementos);
    pa2m_afirmar(lista_primero(cola) == NULL , "Puedo desencolar todos sus elementos");
    lista_destruir(cola);
    printf("\n");
}

void desapilar_elementos(lista_t* pila, char elementos[]) {
    int i = 0;
    bool coinciden = false;
    int se_pudo = ERROR;
    while (i < 4) {
        coinciden = (*(char*)lista_tope(pila) == elementos[i]);
        pa2m_afirmar(coinciden, "El tope de la pila es el esperado");
        se_pudo = lista_desapilar(pila);
        pa2m_afirmar(!se_pudo, "Puedo desapilar un elemento de la pila");
        i++;
    }
}

bool apilar_elementos(lista_t* pila, char elementos[]) {
    int i = 0, j = 3;
    int corte = EXITO;
    while (!corte && (i < 4)) {
        corte = lista_apilar(pila, &elementos[j]);
        i++;
        j--;
    }
    return (i == 4);
}

void pruebas_de_pila() {
    char elementos[] = {'a','c','b','d'};
    pa2m_afirmar(lista_tope(NULL) == NULL , "El tope de la pila es NULL cuando no existe");
    lista_t* pila = lista_crear();
    pa2m_afirmar(lista_tope(pila) == NULL , "El tope de la pila es NULL cuando esta vacia");
    int se_pudo = apilar_elementos(pila, elementos);
    pa2m_afirmar(se_pudo, "Puedo apilar 4 elementos");
    desapilar_elementos(pila, elementos);
    pa2m_afirmar(lista_tope(pila) == NULL , "Puedo desapilar todos sus elementos");
    lista_destruir(pila);
    printf("\n");
}

int pruebas_de_eliminacion_multiple(lista_t* lista, int cantidad, size_t posicion) {
    size_t total = lista_elementos(lista);
    int corte = EXITO, condicion = EXITO;
    int i = 0, j = 0;

    while (!corte && (i < cantidad)) {
        corte = lista_borrar(lista);
        i++;
    }
    while (!condicion && (j < cantidad)) {
        condicion = lista_borrar_de_posicion(lista, posicion);
        j++;
    }

    bool borrar = lista_elementos(lista) == (total - (cantidad*2));
    return borrar;
}

lista_t* pruebas_de_insercion_multiple() {
    lista_t* lista = lista_crear();
    int elemento = 1;
    int se_pudo = ERROR;
    int corte = EXITO;
    int i = 0;
    while (!corte && (i < 10000)) {
        corte = lista_insertar(lista, &elemento);
        i++;
    }
    pa2m_afirmar(lista_elementos(lista) == 10000, "Se pudo insertar 10k elementos a una lista vacia");
    se_pudo = pruebas_de_eliminacion_multiple(lista, 2000, 50);
    pa2m_afirmar(se_pudo, "Se pudo borrar 2k elementos desde la ultima posicion");
    pa2m_afirmar(se_pudo, "Se pudo borrar 2k elementos siempre de la posicion 50");
    pa2m_afirmar(lista_elementos(lista) == 6000, "Se pudieron borrar 4k de elementos de la lista");
    se_pudo = pruebas_de_eliminacion_multiple(lista, 500, 25);
    pa2m_afirmar(se_pudo, "Se pudo borrar 500 elementos desde la ultima posicion");
    pa2m_afirmar(se_pudo, "Se pudo borrar 500 elementos siempre de la posicion 25 "); 
    pa2m_afirmar(lista_elementos(lista) == 5000, "Se pudieron borrar 1k de elementos de la lista");
    pa2m_afirmar(lista_elementos(lista) == 5000, "Quedan 5k elementos en la lista");
    
    lista_destruir(lista);
    printf("\n");
}

void pruebas_de_eliminacion_simple(lista_t* lista) {
    pa2m_afirmar(lista_elementos(lista) == 6, "La lista contiene 6 elementos");
    pa2m_afirmar(lista_borrar(lista) == EXITO, "Puedo borrar el ultimo elemento de la lista");
    pa2m_afirmar(lista_elementos(lista) == 5, "La lista contiene 5 elementos");
    pa2m_afirmar(lista_borrar_de_posicion(lista, 0) == EXITO, "Puedo borrar el primer elemento de la lista");
    pa2m_afirmar(lista_elementos(lista) == 4, "La lista contiene 4 elementos");
    pa2m_afirmar(lista_borrar_de_posicion(lista, 13) == EXITO, "Puedo borrar un elemento de la posicion 13");
    pa2m_afirmar(lista_elementos(lista) == 3, "La lista contiene 3 elementos");
    lista_destruir(lista);
    printf("\n");
}

lista_t* pruebas_de_insercion_simple() {
    lista_t* lista = lista_crear();
    char elementos[] = {'c','a','d','z','b','f'};
    char elementos_ordenados[] = {'a','b','c','d','f','z'};
    pa2m_afirmar(lista_insertar_en_posicion(lista, &elementos[4], 500) == EXITO, "Puedo insertar un elemento en la posicion 500 aunque la lista este vacia");
    pa2m_afirmar(lista_insertar(lista, &elementos[3]) == EXITO, "Puedo insertar un elemento en la ultima posicion");
    pa2m_afirmar(lista_insertar_en_posicion(lista, &elementos[1], 0) == EXITO, "Puedo insertar un elemento en la primer posicion");
    pa2m_afirmar(lista_insertar_en_posicion(lista, &elementos[2], 2) == EXITO, "Puedo insertar un elemento en la tercer posicion");
    pa2m_afirmar(lista_insertar_en_posicion(lista, &elementos[0], 2) == EXITO, "Puedo insertar un elemento en la mitad de la lista");
    pa2m_afirmar(lista_insertar_en_posicion(lista, &elementos[5], 4) == EXITO, "Puedo insertar un elemento en la 4ta posicion");
    pa2m_afirmar(lista_elementos(lista) == 6, "La lista contiene 6 elementos");
    probar_si_elementos_son_los_esperados(lista, elementos_ordenados);
    printf("\n");
    return lista;
}

void pruebas_de_lista_unitaria() {
    char elementos[] = {'a'};
    lista_t* lista = lista_crear();
    pa2m_afirmar(lista_insertar(lista, &elementos[0]) == EXITO, "Puedo crear una lista unitaria");
    pa2m_afirmar(lista_elementos(lista) == 1, "La lista contiene un unico elemento");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 0) != NULL, "Puedo obtener el unico elemento de la lista");
    probar_si_elementos_son_los_esperados(lista, elementos);
    pa2m_afirmar(lista_primero(lista) == lista_ultimo(lista), "El primer y ultimo elemento son el mismo");
    pa2m_afirmar(lista_borrar_de_posicion(lista, 5) == EXITO, "Puedo borrar el unico elemento de la lista aunque la posicion no exista");
    pa2m_afirmar(lista_vacia(lista) == true, "La lista se encuentra vacia");
    lista_destruir(lista);
    printf("\n");
}

void pruebas_de_lista_vacia(){
    lista_t* lista = lista_crear();
    pa2m_afirmar(lista_vacia(lista) == true, "La lista esta vacia");
    pa2m_afirmar(lista_elementos(lista) == 0, "La lista no contiene elementos");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 3) == NULL, "Obtengo NULL al acceder a cualquier posicion de la lista");
    pa2m_afirmar(lista_primero(lista) == NULL, "No puedo obtener el primer elemento de la lista porque esta vacia");  
    int borrar = lista_borrar(lista);
    int borrar_posicion = lista_borrar_de_posicion(lista, 5);
    pa2m_afirmar(borrar && borrar_posicion, "No me permite borrar elementos porque la lista esta vacia");
    pa2m_afirmar(lista_vacia(lista) == true, "La lista continua vacia");
    lista_destruir(lista);
    printf("\n");
}

void pruebas_de_lista_con_4_elementos() {
    char elementos[] = {'a','c','b','d'};
    lista_t* lista = probar_creacion("Puedo crear una lista");
    insertar_elementos(lista, elementos);
    pa2m_afirmar(lista_vacia(lista) == false, "La lista no esta vacia");
    pa2m_afirmar(lista_elementos(lista) == 4, "La lista contiene 4 elementos");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 2) != NULL, "Puedo obtener un elemento de una posicion especifica");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 5) == NULL, "Obtengo NULL al acceder a una posicion inexistente");
    probar_si_elementos_son_los_esperados(lista, elementos);
    pa2m_afirmar(lista_borrar(lista) == EXITO, "Puedo borrar el ultimo elemento de la lista");
    pa2m_afirmar(lista_borrar_de_posicion(lista, 0) == EXITO, "Puedo borrar el primer elemento de la lista");
    pa2m_afirmar(lista_elementos(lista) == 2, "La lista contiene 2 elementos");
    pa2m_afirmar(lista_ultimo(lista) != NULL, "Puedo obtener el ultimo elemento de la lista");    
    lista_destruir(lista);
    printf("\n");   
}

int main(){
    pa2m_nuevo_grupo("PRUEBAS DE LISTA");
    pruebas_de_lista_con_4_elementos();
    
    pa2m_nuevo_grupo("PRUEBAS DE LISTA CON UN UNICO ELEMENTO");
    pruebas_de_lista_unitaria();

    pa2m_nuevo_grupo("PRUEBAS DE LISTA VACIA");
    pruebas_de_lista_vacia();

    pa2m_nuevo_grupo("PRUEBAS DE INSERCION SIMPLE");
    lista_t* lista_simple = pruebas_de_insercion_simple();

    pa2m_nuevo_grupo("PRUEBAS DE ELIMINACION SIMPLE");
    pruebas_de_eliminacion_simple(lista_simple);
    
    pa2m_nuevo_grupo("PRUEBAS DE INSERCION Y ELIMINACION MULTIPLE");
    lista_t* lista_multiple = pruebas_de_insercion_multiple();

    pa2m_nuevo_grupo("PRUEBAS DE LISTA CON COMPORTAMIENTO DE PILA");
    pruebas_de_pila();

    pa2m_nuevo_grupo("PRUEBAS DE LISTA CON COMPORTAMIENTO DE COLA");
    pruebas_de_cola();

    pa2m_nuevo_grupo("PRUEBAS DE ITERADOR EXTERNO");
    pruebas_de_iterador_ex();

    pa2m_nuevo_grupo("PRUEBAS DE ITERADOR INTERNO");
    pruebas_de_iterador_in();

    pa2m_mostrar_reporte();
    return EXITO;
}