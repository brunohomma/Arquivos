/*
 * Arquivo que realiza a importação dos registros armazenados em um arquivo do tipo .csv para um arquivo .dat,
 * realizando as devidas separações entre campos(usando delimitadores de campos), e entre registros.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <registro1.h>

#define ESPACO 32
#define ENTER 10

// Função que realiza a leitura do arquivo de entrada .csv
char *realizaLeitura_metodo1(FILE *stream) {
	char *string = NULL, letra;
	int size = 0;

	do {
		letra = fgetc(stream);
		if (letra == EOF) {
			flag = 0;
			return NULL;
		}
		if (letra != 13) { // parece que tem um caracter inválido de valor 13 no fim de cada registro no arquivo .csv
			string = (char *)realloc(string, sizeof(char)*(size+1));
			if (letra != ';' && letra != ENTER) string[size++] = letra;
			else if (letra == ';' || letra == ENTER)string[size++] = '\0'; // caso encontre o delimitador de string, encerra a leitura.
		}
	} while(letra != ';' && letra != ENTER); // condição para encerrar a leitura.

	return string;
}


// Função que preenche os dados de um registro em uma estrutura de dados.
<<<<<<< HEAD:registro.c
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
=======
void preencheRegistro_metodo1(FILE *stream, struct registro *r) {
	(*r).CNPJ = realizaLeitura_metodo1(stream);
	if(!flag) return; // flag que desliga quando o arquivo de entrada foi completamente lido
	(*r).nomeSocial = realizaLeitura_metodo1(stream);
	(*r).nomeFantasia = realizaLeitura_metodo1(stream);
	(*r).dataRegistro = realizaLeitura_metodo1(stream);
	(*r).dataCancelamento = realizaLeitura_metodo1(stream);
	(*r).motivoCancelamento = realizaLeitura_metodo1(stream);
	(*r).nomeEmpresa = realizaLeitura_metodo1(stream);
	(*r).CNPJAuditor = realizaLeitura_metodo1(stream);	
>>>>>>> 8ae3a500ff3daa04386c16ecf586d494154848a9:registro1.c
}

// Função que transfere os dados do registro armazenado na estrutura para um arquivo binário.
void transfereRegistro_metodo1(FILE *stream, struct registro r) {
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
<<<<<<< HEAD:registro.c
void importaRegistro(FILE *stream) {
	FILE *binaryFile = fopen("RegBin.dat", "wb"); // abre ou cria o arquivo binário.
=======
void importaRegistro_metodo1(FILE *stream) {
	FILE *binaryFile = fopen("RegBin_metodo1.dat", "wb"); // abre ou cria o arquivo binário.
>>>>>>> 8ae3a500ff3daa04386c16ecf586d494154848a9:registro1.c
	struct registro reg;

	flag = 1;
	do {
<<<<<<< HEAD:registro.c
		preencheRegistro(stream, &reg); // preenche o registro na estrutura de dados.
 		if (flag) transfereRegistro(binaryFile, reg); // transfere os dados da estrutura para o arquivo binário.
=======
		preencheRegistro_metodo1(stream, &reg); // preenche o registro na estrutura de dados.
 		if (flag) transfereRegistro_metodo1(binaryFile, reg); // transfere os dados da estrutura para o arquivo binário.
>>>>>>> 8ae3a500ff3daa04386c16ecf586d494154848a9:registro1.c
 	} while(flag);
 	
 	fclose(binaryFile);	
}