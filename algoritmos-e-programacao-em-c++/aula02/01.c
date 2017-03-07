#include "stdio.h"

// Modifique o último exemplo para exibir ao usuário a mensagem
// "Parabéns, você passou direto!" caso a sua nota seja igual ou superior a 8.5;
int main()
{
	float notaFinal = 6.0;

	if(notaFinal >= 8.5) {
		printf("Passou Direto!\n");
	} else if(notaFinal >= 6.0 && notaFinal < 8.5) {
		printf("Grau C para aumentar a nota\n");
	} else {
		printf("Grau C para poder passar\n");
	}

	return 0;
}
