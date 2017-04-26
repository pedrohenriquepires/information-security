#include "stdio.h"
#include "../utils.h"

int main()
{
    int tamanho;

    do {
        readInt("Informe o tamanho da matriz (3 ~ 15)", &tamanho);
    } while(tamanho < 3 || tamanho > 15);

    char matriz[tamanho][tamanho];

    for (int i = 0; i < tamanho; i++) {
		for (int j = 0; j < tamanho; j++) {
			matriz[i][j] = '-';
		}
	}

    for (int i = 0; i < tamanho / 2; i++) {
        if(tamanho % 2 == 0) {
            matriz[i][(tamanho / 2) - (i + 1)] = 'x';
            matriz[(tamanho - 1) - i][(tamanho / 2) - (i + 1)] = 'x';
        } else {
            matriz[i][(tamanho / 2) - i] = 'x';
            matriz[(tamanho - 1) - i][(tamanho / 2) - i] = 'x';
        }

        matriz[i][(tamanho / 2) + i] = 'x';
        matriz[(tamanho - 1) - i][(tamanho / 2) + i] = 'x';
    }

    if(tamanho % 2 != 0) {
        matriz[tamanho / 2][0] = 'x';
        matriz[tamanho / 2][tamanho - 1] = 'x';
    }


    for (int i = 0; i < tamanho; i++) {
		for (int j = 0; j < tamanho; j++) {
			printf("%c ", matriz[i][j]);
		}

		printf("\n");
	}

    return 0;
}
