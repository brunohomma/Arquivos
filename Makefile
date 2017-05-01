all:
	gcc -o main trabalho1.c registro.c interface.c buscafiltrada.c -I.

run:
	./main
