#ifndef _REGISTRO_H_
#define _REGISTRO_H_

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

typedef struct registro t_registro;
int flag;

void importaRegistro(FILE *stream);

#endif