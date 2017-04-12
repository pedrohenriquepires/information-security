#include "stdio.h"
#include "utils.h"
#include "chair.struct.h"

int rows, columns;

void menu(double ticketPrice, Chair chairs[rows][columns]);
void renderMenu();
void handleMenuChoice(int menuChoice, double ticketPrice, Chair chairs[rows][columns]);

int main() {
	// clear();

	double ticketPrice;
	int rows, columns;

	separator();
	printf("Olá! Seja bem-vindo(a) ao sistema de gerenciamento do CineC! \nPara começar, vamos preencher algumas informações básicas.\n");
	separator();

	readDouble("Informe o valor do ingresso: R$", &ticketPrice);
	readInt("Informe a quantidade de fileiras da sala:", &rows);
	readInt("Informe a quantidade de assentos por fileira da sala:", &columns);

	Chair chairs[rows][columns];

	menu(ticketPrice, chairs);

	return 0;
}

void menu(double ticketPrice, Chair chairs[rows][columns]) {
	int menuChoice = 0;

	do {
		renderMenu();
		readInt("Escolha uma opção: ", &menuChoice);
		handleMenuChoice(menuChoice, ticketPrice, chairs);
	} while(menuChoice != 5);
}

void renderMenu() {
	clear();

	separator();
	printf("	Menu\n");
	separator();

	printf("1. Consultar disponibilidade de cadeiras.\n\n");
}

void handleMenuChoice(int menuChoice, double ticketPrice, Chair chairs[rows][columns]) {
	char exit;
	int line;
	int row;

	switch (menuChoice) {
		case 1:
			printf("%d", chairs[0][0].available);

			break;
	}

	readChar("Deseja voltar para o menu (S/N)?", &exit);
}
