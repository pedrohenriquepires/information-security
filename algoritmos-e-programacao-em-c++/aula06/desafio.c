#include "stdio.h"
#include "../utils.h"

void imprimeHistograma(int tamanho, double menorNota, int menorNotaContador, double maiorNota, int maiorNotaContador, int * notasTurma, double total);
int verificaMenorNota(double menorNotaAtual, double nota);
int verificaMaiorNota(double maiorNotaAtual, double nota);

int main()
{
	int tamanho, menorNotaContador = 0, maiorNotaContador = 0, notasTurma[8];
	double menorNota = 10, maiorNota = 0, total = 0;

	readInt("Informe o tamanho da turma", &tamanho);

	for (int i = 0; i < tamanho; i++) {
		double nota;
		readDouble("Informe uma nota", &nota);
		total += nota;

		if(nota < 3.1) {
			notasTurma[0]++;
		} else if(nota < 4.1) {
			notasTurma[1]++;
		} else if(nota < 5.1) {
			notasTurma[2]++;
		} else if(nota < 6.1) {
			notasTurma[3]++;
		} else if(nota < 7.1) {
			notasTurma[4]++;
		} else if(nota < 8.1) {
			notasTurma[5]++;
		} else if(nota < 9.1) {
			notasTurma[6]++;
		} else {
			notasTurma[7]++;
		}

		if(verificaMenorNota(menorNota, nota) == 1) {
			menorNota = nota;
			menorNotaContador = 1;
		} else {
			if(verificaMenorNota(menorNota, nota) == 0) {
				menorNotaContador++;
			}
		}

		if(verificaMaiorNota(maiorNota, nota) == 1) {
			maiorNota = nota;
			maiorNotaContador = 1;
		} else {
			if(verificaMaiorNota(maiorNota, nota) == 0) {
				maiorNotaContador++;
			}
		}
	}

	separator();

	imprimeHistograma(tamanho, menorNota, menorNotaContador, maiorNota, maiorNotaContador, notasTurma, total);

	return 0;
}

int verificaMenorNota(double menorNotaAtual, double nota) {
	if(nota < menorNotaAtual) {
		return 1;
	} else {
		if(nota == menorNotaAtual) {
			return 0;
		} else {
			return -1;
		}
	}
}

int verificaMaiorNota(double maiorNotaAtual, double nota) {
	if(nota > maiorNotaAtual) {
		return 1;
	} else {
		if(nota == maiorNotaAtual) {
			return 0;
		} else {
			return -1;
		}
	}
}

void imprimeHistograma(int tamanho, double menorNota, int menorNotaContador, double maiorNota, int maiorNotaContador, int * notasTurma, double total) {
	printf("Menor nota: %.1f (%dx)\n", menorNota, menorNotaContador);
	printf("Maior nota: %.1f (%dx)\n", maiorNota, maiorNotaContador);
	printf("Média da turma: %.1f\n\n", total / tamanho);

	printf("0.0 ~  3.0: ");
	repeatChar('*', notasTurma[0]);
	printf("\n");

	printf("3.1 ~  4.0: ");
	repeatChar('*', notasTurma[1]);
	printf("\n");

	printf("4.1 ~  5.0: ");
	repeatChar('*', notasTurma[2]);
	printf("\n");

	printf("5.1 ~  6.0: ");
	repeatChar('*', notasTurma[3]);
	printf("\n");

	printf("6.1 ~  7.0: ");
	repeatChar('*', notasTurma[4]);
	printf("\n");

	printf("7.1 ~  8.0: ");
	repeatChar('*', notasTurma[5]);
	printf("\n");

	printf("8.1 ~  9.0: ");
	repeatChar('*', notasTurma[6]);
	printf("\n");

	printf("9.1 ~ 10.0: ");
	repeatChar('*', notasTurma[7]);
	printf("\n");
}
