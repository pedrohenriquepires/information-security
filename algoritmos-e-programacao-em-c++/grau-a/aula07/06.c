#include "stdio.h"
#include "../utils.h"

int main()
{
	int size = 10;

	char matriz[size][size];

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matriz[i][j] = '-';
		}
	}

	for (int i = 0; i < size; i++) {
		matriz[i][i] = 'x';
	}

	for (int i = 0; i < size; i++) {
        matriz[i][9 - i] = 'x';
    }

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%c ", matriz[i][j]);
		}

		printf("\n");
	}

	return 0;
}
