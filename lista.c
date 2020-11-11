#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

/*
typedef struct nodo{
    void* elemento;
    struct nodo* siguiente;
}nodo_t;

typedef struct lista{
    nodo_t* nodo_inicio;
    nodo_t* nodo_fin;
    size_t cantidad;
}lista_t;

typedef struct lista_iterador{
    nodo_t* corriente;
    lista_t* lista;
}lista_iterador_t;
*/

#define EXITO 0
#define ERROR -1

void destruir_nodo(nodo_t* nodo) {
    if (nodo->siguiente)
        destruir_nodo(nodo->siguiente);
    free(nodo);
}

void lista_destruir(lista_t* lista) {
    size_t elementos_toales = lista->cantidad;
    if (lista && (elementos_toales > 0)) {
        if (lista->nodo_inicio)
            destruir_nodo(lista->nodo_inicio);
    }
    if (lista) {
        free(lista);
    }
}
/*
 * Funcion que recorre la lista 
*/
nodo_t* recorrer_lista(lista_t* lista, size_t posicion) {
    if (lista->cantidad == 1) return lista->nodo_inicio;
    nodo_t* nodo_siguiente = lista->nodo_inicio->siguiente;
    for (int i = 0; i < posicion; i++) {
        nodo_siguiente = nodo_siguiente->siguiente;
    }
    return nodo_siguiente;
}

int lista_insertar_en_posicion(lista_t* lista, void* elemento, size_t posicion) {
    if (!lista) return ERROR;
    if (posicion >= lista->cantidad) {
        int agregar = lista_insertar(lista, elemento);
        return agregar;
    }
    nodo_t* nodo_aux = calloc(1, sizeof(nodo_t));
    if (!nodo_aux) {
        free(nodo_aux);
        return ERROR;
    }
    nodo_aux->elemento = elemento;
    lista->cantidad ++;
    nodo_t* nodo_siguiente = recorrer_lista(lista, posicion);
    nodo_aux->siguiente = nodo_siguiente;
    nodo_t* nodo_anterior = recorrer_lista(lista, posicion-1);
    nodo_anterior->siguiente = nodo_aux;
    return EXITO;
}

int lista_insertar(lista_t* lista, void* elemento) {
    size_t final = lista->cantidad;
    nodo_t* nodo_anterior = NULL;
    if (final > 0)
        nodo_anterior = lista->nodo_fin;
    nodo_t* nodo_aux = calloc(1, sizeof(nodo_t));
    if (!nodo_aux) {
        free(nodo_aux);
        return ERROR;
    }
    lista->nodo_fin = nodo_aux; 
    lista->nodo_fin->elemento = elemento;
    lista->nodo_fin->siguiente = NULL;
    if (final > 0) nodo_anterior->siguiente = lista->nodo_fin;
    if (final == 0) lista->nodo_inicio = lista->nodo_fin;
    lista->cantidad ++;

    return EXITO;
}

lista_t* lista_crear(){
    lista_t* nueva_lista = calloc(11,sizeof(lista_t));
    if (!nueva_lista) return NULL;
    
    return nueva_lista;
}