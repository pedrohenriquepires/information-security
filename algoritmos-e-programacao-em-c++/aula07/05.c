#include "stdio.h"
#include "../utils.h"

int main()
{
	int linhas, colunas;

	double matriz[10][10];

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			matriz[i][j] = (i + 1) + ((j + 1) * 0.1);
		}
	}

	do {
		readInt("Informe a quantidade de linhas (menor que 10)", &linhas);
	} while(linhas > 10);

	do {
		readInt("Informe a quantidade de colunas (menor que 10)", &colunas);
	} while(colunas > 10);

	double matrizNova[linhas][colunas];

	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++) {
			matrizNova[i][j] = matriz[9 - i][9 - j];
		}
	}

	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++) {
			printf("%-5.1f ", matrizNova[i][j]);
		}
		printf("\n");
	}

	return 0;
}
