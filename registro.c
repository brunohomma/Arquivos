/*
 * Arquivo que realiza a importação dos registros armazenados em um arquivo do tipo .csv para um arquivo .bin,
 * realizando as devidas separações entre campos(usando delimitadores de campos), e entre registros.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <registro.h>

#define ESPACO 32

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
	int tam = 0;

	do {
		letra = fgetc(stream);
		if (letra != ESPACO && letra != EOF) { // verifica se há um carater espaco ou se o ponteiro está no fim do arquivo.
			string = (char *)realloc(sizeof(char)*(size+1));
			if (letra != ';') string[size++] = letra;
			else string[size++] = '\0'; // caso encontre o delimitador de string, encerra a leitura.
		}
	} while(letra != ';' && letra != EOF); // condição para encerrar a leitura.

	return string;
}

// Função que preenche os dados de um registro em uma estrutura de dados.
void preencheRegistro(struct registro r) {
	r.CNPJ = realizaLeitura(stream);
	r.nomeSocial = realizaLeitura(stream);
	r.nomeFantasia = realizaLeitura(stream);
	r.dataRegistro = realizaLeitura(stream);
	r.dataCancelamento = realizaLeitura(stream);
	r.motivoCancelamento = realizaLeitura(stream);
	r.nomeEmpresa = realizaLeitura(stream);
	r.CNPJAuditor = realizaLeitura(stream);	
}

// Função que transfere os dados do registro armazenado na estrutura para um arquivo binário.
void transfereRegistro(FILE *bf, struct registro r) {
	char aux[] = "|"; // string que representa o delimitador de registro.

	// escreve os dados no arquivo binário e coloca delimitador em campos de tamanho variável.
	fwrite(r.CNPJ, sizeof(char), 18,stream);
	fwrite(r.nomeSocial, sizeof(char), strlen(r.nomeSocial),stream);
	fwrite(aux, sizeof(char), 1, stream);
	fwrite(r.nomeFantasia, sizeof(char),strlen(r.nomeFantasia),stream);
	fwrite(aux, sizeof(char), 1, stream);
	fwrite(r.dataRegistro, sizeof(char), 8,stream);
	fwrite(r.dataCancelamento, sizeof(char), 8,stream);
	fwrite(r.motivoCancelamento, sizeof(char),strlen(r.motivoCancelamento),stream);
	fwrite(aux, sizeof(char), 1, stream);
	fwrite(r.nomeEmpresa, sizeof(char),strlen(r.nomeEmpresa),stream);
	fwrite(aux, sizeof(char), 1, stream);
	fwrite(r.CNPJAuditor, sizeof(char), 18,stream);
}

// Função que importa um registro do arquivo .csv para o arquivo .bin mantendo o ponteiro da leitura onde parou na leitura anterior.
void importaRegistro(FILE *stream) {
	FILE *binaryFile = fopen("RegBin.bin", "ab"); // abre ou cria o arquivo binário.
	struct registro reg;

	preencheRegistro(reg); // preenche o registro na estrutura de dados.
	transfereRegistro(binaryFile, reg); // transfere os dados da estrutura para o arquivo binário.
}