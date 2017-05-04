#include <stdio.h>
#include <stdlib.h>
#include <registro1.h>
#include <registro2.h>
#include <buscafiltrada.h>
#include <interface.h>
#include <leituraArquivoBinario.h>

#define ENTER 10
#define ESPACO 32

void catch_string(char **str1, char **str2) {
	char letra;
	int s1 = 0, s2 = 0;

	(*str1) = NULL;
	(*str2) = NULL;

	do {
		letra = fgetc(stdin);
		(*str1) = (char *)realloc((*str1), sizeof(char)*(s1+1));
		if (letra != ESPACO) (*str1)[s1++] = letra;
		else (*str1)[s1++] = '\0';
	} while (letra != ESPACO);

	do {
		letra = fgetc(stdin);
		(*str2) = (char *)realloc((*str2), sizeof(char)*(s2+1));
		if (letra != ENTER) (*str2)[s2++] = letra;
		else (*str2)[s2++] = '\0';
	} while(letra != ENTER);
}

int main (int argc, char **argv) {
<<<<<<< HEAD
	FILE *registros = fopen("SCC0215012017projeto01turmaBdadosCompanhias.csv", "r"); // abre o arquivo de entrada para organizar os registros em um arquivos de saidas
	int op, nroCampo, nroRegistro; // auxiliar para escolher as opções do programa
=======
	FILE *stream;
	char *filtro, *chave;
	int op; // auxiliar para escolher as opções do programa
>>>>>>> 8ae3a500ff3daa04386c16ecf586d494154848a9

	do {
<<<<<<< HEAD
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
=======
		interfaceInicial(); // cria um menu para escolher as operações do programa
		do {
			op = fgetc(stdin)-48; // pega um valor do teclado;
			if (op == 0 || op > 6) printf("Opcão Inválida. Escolha uma opção válida!\n");
			getchar();
		} while (op == 0 || op > 6);	
			
		switch(op) {
			case 1: // cria o arquivo binario
				stream = fopen("SCC0215012017projeto01turmaBdadosCompanhias.csv", "r"); // abre o arquivo de entrada para organizar os registros em um arquivos de saidas
				importaRegistro_metodo1(stream);
				printf("Arquivo 1 Criado com sucesso!\n");
				fclose(stream);
				stream = fopen("SCC0215012017projeto01turmaBdadosCompanhias.csv", "r");
				importaRegistro_metodo2(stream);
				printf("Arquivo 2 Criado com sucesso!\n");
				fclose(stream);
				break;

			case 3:
				stream = fopen("RegBin_metodo1.dat", "rb");
				interfaceFacial();
				printf("Filtro: ");
				catch_string(&filtro, &chave);
				buscaFiltrada(stream, filtro, chave);
				fclose(stream);
				break;

			case 6:
				printf("Programa encerrado...\n");
				break;		
		}
	} while (op != 6);	
>>>>>>> 8ae3a500ff3daa04386c16ecf586d494154848a9

	
	fclose(registros);
	return 0;
}