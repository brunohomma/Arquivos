#include <stdio.h>

int main() {	
	FILE *stream = fopen("RegBin.bin", "rb");
	char letra;

	do {
		fread(&letra, sizeof(char), 1, stream);
		printf("%c", letra);
	} while (letra != EOF);

	return 0;
}
