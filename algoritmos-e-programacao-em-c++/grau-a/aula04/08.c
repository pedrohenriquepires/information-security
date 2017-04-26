#include "stdio.h"
#include "../utils.h"

int main()
{
	int linhas, colunas;

	readInt("Informe a quantidade de linhas", &linhas);
	readInt("Informe a quantidade de colunas", &colunas);

	printf("\n------------------\n\n");

	for(int i = 0; i < linhas; i++) {
		for(int i = 0; i < colunas; i++) {
			printf("* ");
		}
		printf("\n");
	}

	printf("\n------------------\n");

	return 0;
}
