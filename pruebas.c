#include <stdio.h>
#include "lista.h"
#include "pa2mm.h"

#define EXITO 0
#define ERROR -1

bool probar_creacion(lista_t* lista) {
    if (!nueva_lista) {
        printf("error de lista");
        return ERROR;
    }
}

int main(){
    lista_t* nueva_lista = lista_crear();
    
    char elemento = 'a';
    lista_insertar(nueva_lista, &elemento);
    lista_destruir(nueva_lista);

    return EXITO;
}