all:
	gcc -o main trabalho1.c registro.c interface.c leituraArquivoBinario.c -I.

run:
	./main
