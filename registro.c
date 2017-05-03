/*
 * Arquivo que realiza a importação dos registros armazenados em um arquivo do tipo .csv para um arquivo .bin,
 * realizando as devidas separações entre campos(usando delimitadores de campos), e entre registros.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <registro.h>

#define ESPACO 32
#define ENTER 10

// Estrutura que compõe os dados de um registro, isto é, cada variável representa um campo e a estrutura, o registro.
struct registro {
	char *CNPJ; // campo fixo
	char *nomeSocial; // campo variavel
	char *nomeFantasia; // campo variavel
	char *dataRegistro; // campo fixo
	char *dataCancelamento; // campo fixo 
	char *motivoCancelamento; // campo variavel
	char *nomeEmpresa; // campo variavel
	char *CNPJAuditor; // campo fixo
};

// Função que realiza a leitura do arquivo de entrada .csv
char *realizaLeitura(FILE *stream) {
	char *string = NULL, letra;
	int size = 0;

	do {
		letra = fgetc(stream);
		if (letra == EOF) {
			flag = 0;
			return NULL;
		}

		string = (char *)realloc(string, sizeof(char)*(size+1));
		if (letra != ';' && letra != ENTER) string[size++] = letra;
		else if (letra == ';' || letra == ENTER)string[size++] = '\0'; // caso encontre o delimitador de string, encerra a leitura.
	} while(letra != ';' && letra != ENTER); // condição para encerrar a leitura.

	return string;
}

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



void testeSaida(){
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

// Função que preenche os dados de um registro em uma estrutura de dados.
void preencheRegistro(FILE *stream, struct registro *r) {
	(*r).CNPJ = realizaLeitura(stream);
	if(!flag) return; // flag que desliga quando o arquivo de entrada foi completamente lido
	(*r).nomeSocial = realizaLeitura(stream);
	(*r).nomeFantasia = realizaLeitura(stream);
	(*r).dataRegistro = realizaLeitura(stream);
	(*r).dataCancelamento = realizaLeitura(stream);
	(*r).motivoCancelamento = realizaLeitura(stream);
	(*r).nomeEmpresa = realizaLeitura(stream);
	(*r).CNPJAuditor = realizaLeitura(stream);	
}

// Função que transfere os dados do registro armazenado na estrutura para um arquivo binário.
void transfereRegistro(FILE *stream, struct registro r) {
	char aux = '|'; // caracter que representa o delimitador de registro.
	int v = 64+strlen(r.nomeSocial)+strlen(r.nomeFantasia)+strlen(r.motivoCancelamento)+strlen(r.nomeEmpresa);

	fwrite(&v, sizeof(int), 1, stream); // tamanho do registros
	// escreve os dados no arquivo binário e coloca delimitador em campos de tamanho variável.
	fwrite(r.CNPJ, sizeof(char), 19, stream);
	free(r.CNPJ);
	fwrite(r.nomeSocial, sizeof(char), strlen(r.nomeSocial)+1, stream);
	free(r.nomeSocial);
	fwrite(&aux, sizeof(char), 1, stream);
	fwrite(r.nomeFantasia, sizeof(char), strlen(r.nomeFantasia)+1, stream);
	free(r.nomeFantasia);
	fwrite(&aux, sizeof(char), 1, stream);
	fwrite(r.dataRegistro, sizeof(char), 9, stream);
	free(r.dataRegistro);
	fwrite(r.dataCancelamento, sizeof(char), 9, stream);
	free(r.dataCancelamento);
	fwrite(r.motivoCancelamento, sizeof(char), strlen(r.motivoCancelamento)+1, stream);
	free(r.motivoCancelamento);
	fwrite(&aux, sizeof(char), 1, stream);
	fwrite(r.nomeEmpresa, sizeof(char), strlen(r.nomeEmpresa)+1, stream);
	free(r.nomeEmpresa);
	fwrite(&aux, sizeof(char), 1, stream);
	fwrite(r.CNPJAuditor, sizeof(char), 19, stream);
	free(r.CNPJAuditor);
}

// Função que importa um registro do arquivo .csv para o arquivo .bin mantendo o ponteiro da leitura onde parou na leitura anterior.
void importaRegistro(FILE *stream) {
	FILE *binaryFile = fopen("RegBin.dat", "wb"); // abre ou cria o arquivo binário.
	struct registro reg;

	flag = 1;
	do {
		preencheRegistro(stream, &reg); // preenche o registro na estrutura de dados.
 		if (flag) transfereRegistro(binaryFile, reg); // transfere os dados da estrutura para o arquivo binário.
 	} while(flag);
 	
 	fclose(binaryFile);	
}
