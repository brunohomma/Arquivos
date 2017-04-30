#include <stdio.h>
#include <stdlib.h>
#include <registro.h>

int main (int argc, char **argv) {
	FILE *registros = fopen("SCC0215012017projeto01turmaBdadosCompanhias.csv", "r");

	importaRegistro(registros);
	fclose(registros);

	return 0;
}