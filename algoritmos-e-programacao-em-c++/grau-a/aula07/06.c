#include "stdio.h"
#include "../utils.h"

int main()
{
	char matriz[10][10];

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			matriz[i][j] = '-';
		}
	}

	for (int i = 0; i < 10; i++) {
		matriz[i][i] = 'x';
	}

	for (int i = 0; i < 10; i++) {
        matriz[i][9 - i] = 'x';
    }

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%c ", matriz[i][j]);
		}

		printf("\n");
	}

	return 0;
}
