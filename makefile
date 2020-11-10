all: lista_se prueba exe

lista_se: pruebas.c lista.c 
	gcc pruebas.c lista.c -o lista_se -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0

prueba: lista_se
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./lista_se

exe: lista_se
	./lista_se