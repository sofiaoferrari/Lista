#include <stdio.h>
#include "lista.h"
#include "pa2mm.h"

#define EXITO true
#define ERROR false

void probar_destruir_lista(lista_t* lista) {
    lista_destruir(lista);
    bool destruccion = ERROR;
    if (lista) destruccion = EXITO;
    pa2m_afirmar(destruccion,"Puedo destruir la lista");
}

void pruebo_agregar_elemento_en_posicion_inexistente(lista_t* lista, size_t posicion, char elemento) {
    int agregar = lista_insertar_en_posicion(lista, &elemento, posicion);
    if (agregar == 0) agregar = EXITO;
    else agregar = ERROR;
    pa2m_afirmar(agregar,"Puedo insertar un elemento a la lista aunque la posicion no exista");
}

void pruebo_agregar_elemento_en_posicion(lista_t* lista, size_t posicion, char elemento) {
    int agregar = lista_insertar_en_posicion(lista, &elemento, posicion);
    if (agregar == 0) agregar = EXITO;
    else agregar = ERROR;
    pa2m_afirmar(agregar,"Puedo insertar un elemento a la lista en una posicion existente");
}

void pruebo_agregar_otro_elemento(lista_t* lista, char elemento) {
    int agregar = lista_insertar(lista, &elemento);
    if (agregar == 0) agregar = EXITO;
    else agregar = ERROR;
    pa2m_afirmar(agregar,"Puedo insertar un segundo elemento a la lista");
}

void pruebo_agregar_elemento(lista_t* lista, char elemento) {
    int agregar = lista_insertar(lista, &elemento);
    if (agregar == 0) agregar = EXITO;
    else agregar = ERROR;
    pa2m_afirmar(agregar,"Puedo insertar un elemento a la lista");
}

lista_t* probar_creacion() {
    lista_t* nueva_lista = lista_crear();
    bool creacion = EXITO;
    if (!nueva_lista) creacion = ERROR;
    pa2m_afirmar(creacion,"Puedo crear la lista");
    return nueva_lista;
}

int main(){
    pa2m_nuevo_grupo("PRUEBAS DE LISTA");
    lista_t* lista_de_prueba = probar_creacion();
    if(!lista_de_prueba) return ERROR;
    pruebo_agregar_elemento(lista_de_prueba, 'a');
    pruebo_agregar_otro_elemento(lista_de_prueba, 'b');
    pruebo_agregar_otro_elemento(lista_de_prueba, 'f');
    pruebo_agregar_elemento_en_posicion(lista_de_prueba,1, 'c');
    pruebo_agregar_elemento_en_posicion(lista_de_prueba,2, 'd');
    pruebo_agregar_elemento_en_posicion_inexistente(lista_de_prueba,5, 'd');
    printf("\n Cant d elem: %ld", lista_de_prueba->cantidad);

    probar_destruir_lista(lista_de_prueba);

    pa2m_nuevo_grupo("PRUEBAS DE PILA");

    pa2m_nuevo_grupo("PRUEBAS DE COLA");
    return EXITO;
}