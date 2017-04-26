#include "stdio.h"
#include "../utils.h"

int main()
{
	double matriz[10][10];

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			matriz[i][j] = (i + 1) + ((j + 1) * 0.1);
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%-5.1f ", matriz[i][j]);
		}
		printf("\n");
	}

	return 0;
}
