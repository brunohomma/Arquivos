#include <stdio.h>
#include <stdlib.h>
#include <registro.h>
#include <interface.h>
#include <leituraArquivoBinario.h>

int main (int argc, char **argv) {
	FILE *registros = fopen("SCC0215012017projeto01turmaBdadosCompanhias.csv", "r"); // abre o arquivo de entrada para organizar os registros em um arquivos de saidas
	int op, nroCampo, nroRegistro; // auxiliar para escolher as opções do programa

	interfaceInicial(); // cria um menu para escolher as operações do programa
	do {
		op = fgetc(stdin)-48; // pega um valor do teclado;
		if (op == 0 || op > 5) printf("Opcão Inválida. Escolha uma opção válida!\n");
		getchar();

	} while (op == 0 || op > 5);	
	
	switch(op) {
		case 1: // cria o arquivo binario
			importaRegistro(registros);
			printf("Arquivo Criado com sucesso!\n");
			break;

		case 2:
			lerArquivoBinario();
			break;

		case 3:
			scanf("%d", &nroRegistro);
			parte5(nroRegistro);
			break;

		case 4:
			scanf("%d", &nroCampo);
			scanf("%d", &nroRegistro);
			parte6(nroRegistro, nroCampo);
			break;
			
	}

	
	fclose(registros);
	return 0;
}