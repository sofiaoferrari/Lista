#include <stdio.h>
#include "lista.h"
#include "pa2mm.h"

#define EXITO true
#define ERROR false

void probar_destruir_lista(lista_t* lista, const char* AFIRMACION) {
    lista_destruir(lista);
    bool destruccion = ERROR;
    if (lista) destruccion = EXITO;
    pa2m_afirmar(destruccion, AFIRMACION);
}

void compruebo_si_hay_la_cantidad_esperada(lista_t* lista, size_t cantidad_esperada, const char* AFIRMACION) {
    size_t es_la_esperada = ERROR;
    if (cantidad_esperada == lista_elementos(lista))
        es_la_esperada = EXITO;
    pa2m_afirmar(es_la_esperada, AFIRMACION);
}

void compruebo_que_lista_esta_vacia(lista_t* lista, const char* AFIRMACION) {
    bool vacia = lista_vacia(lista);
    if (!lista || (lista->cantidad > 0))
        vacia = EXITO;
    pa2m_afirmar(vacia, AFIRMACION);

}

void pruebo_obtener_elemento_de_lista_vacia(lista_t* lista, size_t posicion) {
    bool obtenido = ERROR;
    void* elemento = lista_elemento_en_posicion(lista, posicion);
    if (elemento == NULL) obtenido = EXITO;
    pa2m_afirmar(obtenido, "No puedo obtener un elemento de una lista vacia");
}

void probar_si_elementos_son_los_esperados(lista_t* lista) {
    int es_el_esperado = ERROR;
    char elementos[4] = {'a','c','b','d'};
    for(size_t i=0; i<lista_elementos(lista); i++) {
        if (elementos[i] == *(char*)lista_elemento_en_posicion(lista, i)){
            es_el_esperado = EXITO;
        }
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
        }
    }
}

void pruebo_obtener_ultimo_elemento(lista_t* lista, const char* AFIRMACION) {
    bool obtenido = EXITO;
    void* elemento = lista_ultimo(lista);
    if (!elemento) obtenido = ERROR;
    if ((lista->cantidad == 0) && (!elemento)) obtenido = EXITO;
    pa2m_afirmar(obtenido, AFIRMACION);
}

void pruebo_obtener_elemento(lista_t* lista, size_t posicion, const char* AFIRMACION) {
    bool obtenido = EXITO;
    void* elemento = lista_elemento_en_posicion(lista, posicion);
    if (!elemento) obtenido = ERROR;
    pa2m_afirmar(obtenido, AFIRMACION);
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

lista_t* probar_creacion(const char* AFIRMACION) {
    lista_t* nueva_lista = lista_crear();
    bool creacion = EXITO;
    if (!nueva_lista) creacion = ERROR;
    pa2m_afirmar(creacion, AFIRMACION);
    return nueva_lista;
}

void pruebas_de_lista_con_1_solo_elemento() {
    lista_t* lista_unitaria = probar_creacion("Puedo crear una lista vacia");
    pruebo_agregar_elemento(lista_unitaria, 'a');
    compruebo_que_lista_esta_vacia(lista_unitaria, "La lista no esta vacia");
    compruebo_si_hay_la_cantidad_esperada(lista_unitaria, 1, "La lista contiene un unico elemento");
    pruebo_obtener_elemento(lista_unitaria, 0, "Puedo obtener el unico elemento de la lista");
    pruebo_obtener_ultimo_elemento(lista_unitaria, "Puedo obtener el unico elemento de la lista accediendo al ultimo");
    probar_destruir_lista(lista_unitaria, "Puedo destruir una lista unitaria");
}

void pruebas_de_lista_vacia(){
    lista_t* lista_vacia = probar_creacion("Puedo crear una lista vacia");
    pruebo_obtener_elemento_de_lista_vacia(lista_vacia, 0);
    pruebo_obtener_ultimo_elemento(lista_vacia, "No puedo obtener el ultimo elemento de la lista porque esta vacia");
    probar_destruir_lista(lista_vacia, "Puedo destruir una lista vacia");
}

void pruebas_de_lista_con_4_elementos() {
     lista_t* lista_de_prueba = probar_creacion("Puedo crear la lista");
    pruebo_agregar_elemento(lista_de_prueba, 'a');
    pruebo_agregar_otro_elemento(lista_de_prueba, 'b');
    pruebo_agregar_elemento_en_posicion(lista_de_prueba, 1, 'c');
    pruebo_agregar_elemento_en_posicion_inexistente(lista_de_prueba, 10, 'd');
    compruebo_que_lista_esta_vacia(lista_de_prueba, "La lista no esta vacia");
    compruebo_si_hay_la_cantidad_esperada(lista_de_prueba, 4, "La lista contiene 4 elementos");
    pruebo_obtener_elemento(lista_de_prueba, 0, "Puedo obtener un elemento de una posicion especifica");
    pruebo_obtener_ultimo_elemento(lista_de_prueba, "Puedo obtener el ultimo elemento de la lista");
    probar_si_elementos_son_los_esperados(lista_de_prueba);
    //printf("\n Cant d elem: %ld\n", lista_de_prueba->cantidad);
    probar_destruir_lista(lista_de_prueba, "Puedo destruir una lista que contiene elementos");
}

int main(){
    pa2m_nuevo_grupo("PRUEBAS DE LISTA");
    pruebas_de_lista_con_4_elementos();
    printf("\n");
    pruebas_de_lista_vacia();
    printf("\n");
    pruebas_de_lista_con_1_solo_elemento();
    pa2m_nuevo_grupo("PRUEBAS DE PILA");

    pa2m_nuevo_grupo("PRUEBAS DE COLA");
    return EXITO;
}