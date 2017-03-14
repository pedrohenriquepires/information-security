#include "stdio.h"
#include "../utils.h"

int main()
{
	int colunas;

	readInt("Informe a quantidade de colunas", &colunas);

	printf("\n------------------\n\n");

	for(int l = 0; l <= colunas; l++) {
	    for(int c = colunas - l; c >= 0; c--) {
            printf("* ");
        }

        printf("\n");
	}

	printf("\n------------------\n");

	return 0;
}
