all:
	gcc -o main trabalho1.c registro1.c registro2.c interface.c buscafiltrada.c -I.

run:
	./main
