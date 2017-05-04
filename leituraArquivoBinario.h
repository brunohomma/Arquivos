#ifndef _LEITURAARQUIVOBINARIO_H_
#define _LEITURAARQUIVOBINARIO_H_

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


void lerArquivoBinario();
void parte6(int nroCampo,int nroReg);
void parte5(int nroReg);

#endif