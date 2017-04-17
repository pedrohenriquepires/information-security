#include "stdio.h"
#include "string.h"
#include "utils.h"
#include "stdbool.h"
#include "menu.constants.h"
#include "occupant.struct.h"
#include "chair.struct.h"

int rows, columns;

void handleMenuChoice(int menuChoice, double ticketPrice, Chair chairs[rows][columns]);
void menu(double ticketPrice, Chair chairs[rows][columns]);
void prePopulateChairs(Chair chairs[rows][columns]);
void renderMap(Chair chairs[rows][columns]);
void renderMenu();
void setCineProperties(double *ticketPrice);

int main() {
	clear();

	double ticketPrice;

	setCineProperties(&ticketPrice);

	Chair chairs[rows][columns];

	prePopulateChairs(chairs);
	menu(ticketPrice, chairs);

	return 0;
}

void handleMenuChoice(int menuChoice, double ticketPrice, Chair chairs[rows][columns]) {
	char leave;
	int row;
	int column;

	clear();

	if(menuChoice == EXIT) {
		printf("Bye! :)\n");
		return;
	}

	switch (menuChoice) {
		case AVAILABLE_CHAIR:
			readInt("Informe a fileira: ", &row);
			readInt("Informe a coluna: ", &column);
			separator();
			space();

			Chair chair = chairs[row][column];

			if(!chair.reserved) {
				printf("O assento está livre!");
				space();
			} else {
				printf("O assento está reservado para:");
				space();
				printf("%s\n", chair.occupant.name);
				printf("%s\n", chair.occupant.gender == 'M' ? "Homem" : "Mulher");
				printf("%d\n", chair.occupant.age);
			}

			space();
			readChar("Deseja voltar para o menu (S/N)?", &leave);

			break;
		case CHAIR_RESERVE:
			renderMap(chairs);

			space();

			readInt("Informe a fileira: ", &row);
			readInt("Informe a coluna: ", &column);

			Chair chair = chairs[row][column];

			if(chair.reserved) {
				printf("")
			} else {}

			break;
	}
}

void menu(double ticketPrice, Chair chairs[rows][columns]) {
	int menuChoice = 0;


	do {
		renderMenu();
		readInt("Escolha uma opção: ", &menuChoice);
		handleMenuChoice(menuChoice, ticketPrice, chairs);
	} while(menuChoice != EXIT);
}

void prePopulateChairs(Chair chairs[rows][columns]) {
	for(int row = 0; row < rows; row++) {
		for(int column = 0; column < columns; column++) {
			chairs[row][column].reserved = false;
		}
	}
}

void renderMap(Chair chairs[rows][columns]) {
	for(int row = -1; row < rows; row++) {
		space();
		for(int column = 0; column < columns; column++) {
			if(column == 0) {
				if(row + 1 != 0) {
					printf("%02d\t", row + 1);
				} else {
					printf(" \t");
				}
			}
			if(row == -1) {
				if(column + 1 != 0) {
					printf("%02d\t", column + 1);
				}
			} else {
				printf("%c\t", chairs[row][column].reserved ? 'X' : '.');
			}
		}
		space();
	}
}

void renderMenu() {
	clear();

	separator();
	printf("	Menu\n");
	separator();

	printf("1. Consulta de disponibilidade de assento.\n");
	printf("2. Consulta de disponibilidade de assentos conjuntos.\n");
	printf("3. Reserva de assentos.\n");
	printf("4. Liberação de assentos.\n");
	printf("5. Sair.\n");
}

void setCineProperties(double *ticketPrice) {
	separator();
	printf("Olá! Seja bem-vindo(a) ao sistema de gerenciamento do CineC! \nPara começar, vamos preencher algumas informações básicas.\n");
	separator();

	readDouble("Informe o valor do ingresso: R$", ticketPrice);
	readInt("Informe a quantidade de fileiras da sala:", &rows);
	readInt("Informe a quantidade de assentos por fileira da sala:", &columns);
}
