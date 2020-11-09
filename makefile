all: lista_se prueba

lista_se: *c
	gcc *.c -o lista_se -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0

prueba: lista_se
	valgrind --leak -check=full --track -origins=yes --show -reachable=yes ./ lista_se