#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *registro(FILE *stream, int *s) {
	int reg_size;
	char *registro;

	fread(&reg_size, sizeof(int), 1, stream);
	if (reg_size == EOF) {
		(*s) = 0;
		return NULL;
	}
	registro = (char *)malloc(sizeof(char)*reg_size);
	fread(registro, sizeof(char), reg_size, stream);

	(*s) = reg_size;

	return registro;	
}

int main() {
	char *teste;
	FILE *stream = fopen("RegBin.bin", "rb");
	int size;

	do {
		teste = registro(stream, &size);
		for (int i = 0; i < size; i++)
			printf("%c", teste[i]);
		if (teste != NULL) free(teste);
	} while (size);	

	fclose(stream);

	return 0;
}