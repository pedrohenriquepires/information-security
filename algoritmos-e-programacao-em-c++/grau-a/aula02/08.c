#include "stdio.h"
#include "../utils.h"
#include "time.h"

// Faça um algoritmo que receba como entrada um horário inicial e um
// horário final no formato “hh:mm:ss”. Calcule o intervalo de tempo
// entre essas duas horas e apresente na tela no formato “hh:nn:ss”
int main()
{
	int horasInicial, minutosInicial, segundosInicial,
		horasFinal, minutosFinal, segundosFinal,
		diferencaHoras, diferencaMinutos, diferencaSegundos;

	readTime("Informe o horário inicial (HH:MM:SS)", &horasInicial, &minutosInicial, &segundosInicial);
	readTime("Informe o horário final (HH:MM:SS)", &horasFinal, &minutosFinal, &segundosFinal);

	// CONVERTER TUDO EM SEGUNDOS

	if(diferencaHoras >= 0) {
		printf("Diferença: %.2d:%.2d:%.2d\n", diferencaHoras, diferencaMinutos, diferencaSegundos);
	} else {
		printf("Horário final não pode ser maior que horário inicial\n");
	}

	return 0;
}
