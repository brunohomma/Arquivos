#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <registro.h>

int *pos;

void printRegistro(char *registro) {
	int campo = 1;
	int pos = 0;

	while (campo < 9) {
		switch(campo) {
			case 1:
				printf("CNPJ: ");
				while (registro[pos] != '\0') {
					printf("%c", registro[pos]);
					pos++;
				}
				printf("\n");
				break;
			case 2:
				printf("Nome Social: ");
				while (registro[pos] != '\0') {
					printf("%c", registro[pos]);
					pos++;
				}
				printf("\n");
				break;
			case 3:
				printf("Nome Fantasma: ");
				while (registro[pos] != '\0') {
					printf("%c", registro[pos]);
					pos++;
				}
				printf("\n");
				break;
			case 4:
				printf("Data de Registro: ");
				while (registro[pos] != '\0') {
					printf("%c", registro[pos]);
					pos++;
				}
				printf("\n");
				break;
			case 5:
				printf("Data de Cancelamento: ");
				while (registro[pos] != '\0') {
					printf("%c", registro[pos]);
					pos++;
				}
				printf("\n");
				break;
			case 6:
				printf("Motivo do Cancelamento: ");
				while (registro[pos] != '\0') {
					printf("%c", registro[pos]);
					pos++;
				}
				printf("\n");
				break;
			case 7:
				printf("Nome da Empresa: ");
				while (registro[pos] != '\0') {
					printf("%c", registro[pos]);
					pos++;
				}
				printf("\n");
				break;
			case 8:
				printf("CNPJ do Auditor: ");
				while (registro[pos] != '\0') {
					printf("%c", registro[pos]);
					pos++;
				}
				printf("\n");
				break;
		}

		if (registro[pos] == '\0') {
			campo++;
			pos++;
			if (registro[pos] == '|') pos++;
		}	
	}
}

void buscaPor(char *registro, int size, char *chave, int campo) {
	int counter = 1;
	int ponteiro = 0, p = 0;
	char *key;
	int j;

	while (ponteiro < size) {
		if (counter == campo) {
			key = (char *)malloc(sizeof(char)*(pos[p]-(ponteiro-1)));
			j = 0;
			for (int i = ponteiro; i <= pos[p]; i++) key[j++] = registro[i];
			if (strcmp(key, chave) == 0) printRegistro(registro);

			free(key);
			ponteiro = size;
		}

		else {
			ponteiro = pos[p++]+1;
			if (registro[ponteiro] == '|') ponteiro += 1;
			counter++;
		}
	}	
}

char *registros(FILE *stream, int *s) {
	int reg_size, p = 0;
	char *registro;
	pos = (int *)malloc(sizeof(int)*8);

	fread(&reg_size, sizeof(int), 1, stream);
	if (reg_size == EOF) {
		(*s) = 0;
		return NULL;
	}
	registro = (char *)malloc(sizeof(char)*reg_size);
	for (int i = 0; i < reg_size; i++) {
		fread(&registro[i], sizeof(char), 1, stream);
		if (registro[i] == '\0') pos[p++] = i;
	}

	(*s) = reg_size;

	return registro;	
}

void buscaFiltrada(FILE *stream, char *filtro, char *chave) {
	char *registro;
	int reg_size;

	do {
		registro = registros(stream, &reg_size);
		if (reg_size) {
			if (strcmp(filtro, "cnpj") == 0) {
				buscaPor(registro, reg_size, chave, 1);
			}
			
			else if (strcmp(filtro, "nome_social") == 0) {
				buscaPor(registro, reg_size, chave, 2);
			}
			
			else if (strcmp(filtro, "nome_fantasma") == 0) {
				buscaPor(registro, reg_size, chave, 3);
			}
			
			else if (strcmp(filtro, "data_registro") == 0) {
				buscaPor(registro, reg_size, chave, 4);
			}
			
			else if (strcmp(filtro, "data_cancelamento") == 0) {
				buscaPor(registro, reg_size, chave, 5);
			}
			
			else if (strcmp(filtro, "motivo_cancelamento") == 0) {
				buscaPor(registro, reg_size, chave, 6);
			}
			
			else if (strcmp(filtro, "nome_empresa") == 0) {
				buscaPor(registro, reg_size, chave, 7);
			}
			
			else if (strcmp(filtro, "cnpj_auditor") == 0) {
				buscaPor(registro, reg_size, chave, 8);
			}

			else printf("Não existe buscas para esse filtro!\n");

			if (registro != NULL) {
				free(registro);
				free(pos);
			}
		}
	} while(reg_size);				
}