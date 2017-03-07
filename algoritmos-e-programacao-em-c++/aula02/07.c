#include "stdio.h"
#include "../utils.h"

// Solicitar duas letras "a" e "b" e imprimir na tela se a letra "a" é igual,
// antecessora ou sucessora da letra "b". Utilizar a tabela ASCII para consulta;
int main()
{
    char primeiraLetra;
    char segundaLetra;

    readChar("Informe a primeira letra", &primeiraLetra);
    readChar("Informe a segunda letra", &segundaLetra);

	printf("A letra '%c' é %s letra '%c'\n", primeiraLetra, (primeiraLetra == segundaLetra) ? "igual a"
                                                           : ((primeiraLetra > segundaLetra ? "sucessora" : "antecessora")), segundaLetra);

	return 0;
}
