#include "stdio.h"
#include "../utils.h"

// Solicitar uma letra e imprimir na tela se ela é maiúscula ou minúscula.
// Utilizar a tabela ASCII para consulta;
int main()
{
	char letra;

    readChar("Informe a letra", &letra);

	if(letra >= 'A' && letra <= 'Z') {
		printf("A letra é maiúscula\n");
	} else if(letra >= 'a' && letra <= 'z') {
		printf("A letra é minúscula\n");
	} else {
		printf("Não é uma letra\n");
	}

	return 0;
}
