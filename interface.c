#include <stdio.h>
#include <stdlib.h>

void interfaceInicial() {
	printf("########################Trabalho de Organização########################\n");
	printf("Autores:\nBruno Homma\nLeonardo Mendes\nKeith Tsukada Sasaki\nValeska Paroni\n\n");
	printf("Escolha uma das opções abaixo:\n");
	printf("1 - Criar arquivo organizado com campos e registros\n");
	printf("2 - Recuperar os dados de todos os registros no arquivos\n");
	printf("3 - Recuperar dados de um registro do arquivo por filtro de pesquisa\n");
	printf("4 - Recuperar dados de um registro selecionado\n");
	printf("5 - Recuperar o dado de um campo selecionado de um registro escolhido\n");
	printf("6 - Encerrar o programa\n");
}

void interfaceFacial() {
	printf("Preencher os  filtros da seguinte maneira:\n");
	printf("<tipo de campo> <chave do campo>\n");
	printf("Tipos de Campos(escolher o campo escrevendo da maneira como descrita abaixo):\n");
	printf("- cnpj\n");
	printf("- nome_social\n");
	printf("- nome_fantasma\n");
	printf("- data_registro\n");
	printf("- data_cancelamento\n");
	printf("- motivo_cancelamento\n");
	printf("- nome_empresa\n");
	printf("- cnpj_auditor\n");
}	