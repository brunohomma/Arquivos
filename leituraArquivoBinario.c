#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <leituraArquivoBinario.h>

void lerRegistroBinario(FILE *stream){
	int i, fieldSize = 0, regSize; // cria uma variavel para armazenar o tamanho do registro, e o contador do tamanho de campos.
	char c;	// cria uma variavel para armazenar o byte lido no arquivo.

	// lê o tamanho do registro, contido nos 4 primeiros bytes do arquivo.
	fread(&regSize, sizeof(int), 1, stream);

	char CNPJ[19];	// cria a variavel CNPJ, que tem tamanho fixo de 19 caracteres.
	fread(&CNPJ[0], sizeof(char), sizeof(CNPJ), stream);	// realiza a leitura do CNPJ.
	for(i = 0; i < sizeof(CNPJ); i++) printf("%c", CNPJ[i]);	// imprime na tela o CNPJ e um \n logo após.
	printf("\n");
	
	// varre o arquivo procurando por um delimitador de campo '|' e ao mesmo tempo incrementa um contador.
	while(c != '|'){
		fread(&c, sizeof(char), 1, stream);
		fieldSize++;
	}
	fseek(stream, fieldSize*-1, SEEK_CUR);	// assim que acha o '|', volta fieldSize vezes no arquivo.

	char nomeSocial[fieldSize-1];	// cria a variavel para armazenar o Nome Social.
	fread(&nomeSocial[0], sizeof(char), fieldSize-1, stream);	// faz a leitura do nome social.
	for(i = 0; i < fieldSize-1; i++) printf("%c", nomeSocial[i]);	// imprime na tela o nome social e um \n logo após.	printf("\n");
	printf("\n");
	fieldSize = 0;	// zera o contador de campos de tamanho variado.
	c = 0;	// atribui nulo para c.

	fseek(stream, 1, SEEK_CUR);	// pula o delimitador

	while(c != '|'){
		fread(&c, sizeof(char), 1, stream);
		fieldSize++;
	}
	fseek(stream, fieldSize*-1, SEEK_CUR);

	// APLICA A MESMA LOGICA AO NOME FANTASIA
	char nomeFantasia[fieldSize-1];
	fread(&nomeFantasia[0], sizeof(char), fieldSize-1, stream);
	for(i = 0; i < fieldSize-1; i++) printf("%c", nomeFantasia[i]);
	printf("\n");
	fieldSize = 0;
	c = 0;

	fseek(stream, 1, SEEK_CUR);	// pula o delimitador

	char dataRegistro[9];
	fread(&dataRegistro[0], sizeof(char), sizeof(dataRegistro), stream);
	for(i = 0; i < sizeof(dataRegistro); i++) printf("%c", dataRegistro[i]);
	printf("\n");
	
	
	char dataCancelamento[9];
	fread(&dataCancelamento[0], sizeof(char), sizeof(dataCancelamento), stream);
	for(i = 0; i < sizeof(dataCancelamento); i++) printf("%c", dataCancelamento[i]);
	printf("\n");
	

	while(c != '|'){
		fread(&c, sizeof(char), 1, stream);
		fieldSize++;
	}	
	fseek(stream, fieldSize*-1, SEEK_CUR);
	char motivoCancelamento[fieldSize-1];
	fread(&motivoCancelamento[0], sizeof(char), fieldSize-1, stream);
	for(i = 0; i < fieldSize-1; i++) printf("%c", motivoCancelamento[i]);
	printf("\n");
	fieldSize = 0;
	c = 0;


	fseek(stream, 1, SEEK_CUR);

	while(c != '|'){
		fread(&c, sizeof(char), 1, stream);
		fieldSize++;
	}
	fseek(stream, fieldSize*-1, SEEK_CUR);

	char nomeEmpresa[fieldSize-1];
	fread(&nomeEmpresa[0], sizeof(char), sizeof(nomeEmpresa), stream);
	for(i = 0; i < fieldSize-1; i++) printf("%c", nomeEmpresa[i]);
	printf("\n");

	fseek(stream, 1, SEEK_CUR);

	char CNPJAuditor[19];
	fread(&CNPJAuditor[0], sizeof(char), sizeof(CNPJAuditor), stream);
	for(i = 0; i < 19; i++) printf("%c", CNPJAuditor[i]);
	printf("\n");
}


void lerArquivoBinario(){
	FILE *binaryFile = fopen("RegBin.dat", "rb");

	char CNPJ[18], c;
	int regIndex = 1;
		
	if(binaryFile == NULL){
		printf("I could not read this file!\n");
		return;
	}else {
		while(regIndex < 199){
			printf("------------------- REGISTRO %d --------------------------\n", regIndex);
			lerRegistroBinario(binaryFile);
			printf("----------------------------------------------------------\n\n");
			regIndex++;
		}
		
	}
	
	fclose(binaryFile);
}