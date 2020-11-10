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

void lista_destruir(lista_t* lista) {
    if (lista->nodo_inicio) {
        free(lista->nodo_inicio);
    }
    if (lista) {
        free(lista);
    }
}

int lista_insertar(lista_t* lista, void* elemento) {
    size_t final = lista->cantidad;
    if (final == 0) {
        nodo_t* nodo_aux = calloc(1, sizeof(nodo_t));
        if (!nodo_aux) return ERROR;
        lista->nodo_fin = nodo_aux; 
        lista->nodo_fin[final].elemento = elemento;
        lista->nodo_fin[final].siguiente = NULL;
        lista->nodo_inicio = lista->nodo_fin;
        lista->cantidad ++;
    }
    printf("\n primer elemento de la lista: %p", lista->nodo_inicio[0].elemento);
    return EXITO;
}

lista_t* lista_crear(){
    lista_t* nueva_lista = calloc(11,sizeof(lista_t));
    if (!nueva_lista) return NULL;
    
    return nueva_lista;
}