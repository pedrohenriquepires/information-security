#include "stdio.h"
#include "../utils.h"

int valor,
    quantidadeTotal,
    quantidadePares,
    quantidadeImpares,
    soma,
    maior,
    menor = 0;
double media;

void somaParOuImpar(int valor) {
    if(valor % 2 == 0)
        quantidadePares++;
    else
        quantidadeImpares++;
}

void verificaMaior(int valor) {
    if(valor > maior)
        maior = valor;
}

void verificaMenor(int valor) {
    if(valor < menor || menor == 0)
        menor = valor;
}

void calculaMedia() {
    media = soma / quantidadeTotal;
}

void imprimeResultado() {
    printf("\n----------------------------\n");
    printf("Quantidade de números: %d\n", quantidadeTotal);
    printf("Quantidade de pares: %d\n", quantidadePares);
    printf("Quantidade de ímpares: %d\n", quantidadeImpares);
    printf("Soma total: %d\n", soma);
    printf("Média aritmética: %.2f\n", media);
    printf("Maior número: %d\n", maior);
    printf("Menor número: %d\n", menor);
}

int main()
{
    do {
        printf("(0 para sair)\n");
        readInt("Informe um valor inteiro positivo", &valor);

        if(valor > 0) {
            quantidadeTotal++;
            soma += valor;

            somaParOuImpar(valor);
            verificaMaior(valor);
            verificaMenor(valor);
        }
    } while(valor != 0);

    calculaMedia();
    imprimeResultado();

	return 0;
}
