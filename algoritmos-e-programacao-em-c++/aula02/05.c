#include "stdio.h"
#include "../utils.h"

// Solicitar um número inteiro "a" representando uma temperatura em
// graus Celsius. Imprimir na tela se nessa temperatura a água se
// encontra em estado sólido, líquido ou gasoso;
int main()
{
	int a;
	const int TEMPERATURA_SOLIDIFICACAO = 0;
	const int TEMPERATURA_EBULICAO = 100;

    readInt("Informe a temperatura da água", &a);

	printf("O estado da água é ");

	if(a <= TEMPERATURA_SOLIDIFICACAO) {
		printf("sólido\n");
	} else if(a >= TEMPERATURA_EBULICAO) {
		printf("gasoso\n");
	} else {
		printf("líquido\n");
	}

	return 0;
}
