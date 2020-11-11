CC= gcc
WFLAGS= -Wall -Wconversion -Werror -Wtype-limits -pedantic -O0
all: compilar exe_valgrind exe
compilar:
	$(CC) lista.c pruebas.c -o lista_se -g $(FLAGS) 

exe: compilar 
	./lista_se

exe_valgrind: compilar
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./lista_se

compilar_gdb:
	$(CC) -g lista.c pruebas.c  $(FLAGS) -o lista.exe

gdb: compilar_gdb
	gdb lista.exe

compilar_mini:
	$(CC) -g lista.c lista_minipruebas.c  $(FLAGS) -o lista_mini

exe_mini: compilar_mini
	./lista_mini

compilar_gdb_mini: 
	$(CC) -g lista.c lista_minipruebas.c  $(FLAGS) -o mini.exe

gdb_mini: compilar_gdb_mini
	gdb mini.exe

exe_mini_valgrind: compilar_mini
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./lista_mini