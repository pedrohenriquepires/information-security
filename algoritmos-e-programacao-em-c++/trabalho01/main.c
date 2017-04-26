#include "stdio.h"
#include "string.h"
#include "utils.h"
#include "stdbool.h"
#include "menu.constants.h"
#include "occupant.struct.h"
#include "chair.struct.h"

int rows, columns;
int reserved = 0, available = 0, men = 0, women = 0;

void handleMenuChoice(int menuChoice, double ticketPrice, Chair chairs[rows][columns]);
void menu(double ticketPrice, Chair chairs[rows][columns]);
void prePopulateChairs(Chair chairs[rows][columns]);
void renderMap(Chair chairs[rows][columns]);
void renderMenu();
Chair reserveChair();
void setCineProperties(double *ticketPrice);
float getPercentage(int number, int total);
void chairCondition(Chair chairs[rows][columns]);
void renderPercentageBar(float percentual);
void printChairDetail(Chair chair, int row, int column);
void sexCondition(Chair chairs[rows][columns]);

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

	int row, column, chairsLength;

	clear();

	if(menuChoice == EXIT) {
		printf("Bye! :)\n");
		return;
	}

	switch (menuChoice) {
		Chair chair;
		int counter;

		case AVAILABLE_CHAIR:
		{
			renderMap(chairs);

			separator();
			space();

			readInt("Informe a fileira:", &row);
			readInt("Informe a coluna:", &column);
			separator();
			space();

			chair = chairs[row - 1][column - 1];

			if(!chair.reserved) {
				printf("O assento está livre!");
				space();
			} else {
				printChairDetail(chair, row -1, column - 1);
			}

			space();
			blockSection();

			break;
		}
		case AVAILABLE_CHAIRS:
		{
			renderMap(chairs);

			separator();
			space();

			readInt("Informe a fileira:", &row);
			readInt("Informe a coluna:", &column);
			readInt("Informe o número de cadeiras:", &chairsLength);

			int availableChairsColumns[columns];
			counter = 0;

			for(int c = column - 1; c < column + (chairsLength - 1); c++) {
				if(column + (chairsLength - 1) > columns) {
					c = 0;
					column = 1;
					row++;
				}

				if(chairs[row - 1][c].reserved) {
					column = c + 2;
					counter = 0;
				} else {
					availableChairsColumns[counter] = c;
					counter++;
				}

				space();
			}

			clear();
			printf("Assentos encontrados:\n");
			separator();

			for(int c = 0; c < chairsLength; c++) {
				printf(" - [%d - %d]\n", row, availableChairsColumns[c] + 1);
			}

			space();
			blockSection();

			break;
		}
		case CHAIR_RESERVE:
		{
			renderMap(chairs);

			separator();
			space();

			readInt("Informe a fileira:", &row);
			readInt("Informe a coluna:", &column);
			readInt("Informe o número de cadeiras:", &chairsLength);

			int chairsColumns[chairsLength];
			counter = 0;

			for(int c = column - 1; c < column + (chairsLength - 1); c++) {
				if(column + (chairsLength - 1) > columns) {
					c = 0;
					column = 1;
					row++;
				}

				if(chairs[row - 1][c].reserved) {
					column = c + 2;
					counter = 0;
				} else {
					chairsColumns[counter] = c;
					counter++;
				}

				space();
			}

			for(int c = 0; c < chairsLength; c++) {
				clear();

				printf("Assento [%d - %d]", row, chairsColumns[c] + 1);
				space();
				separator();
				space();

				chairs[row - 1][chairsColumns[c]] = reserveChair();

				separator();
			}

			clear();

			renderMap(chairs);

			space();
			blockSection();

			break;
		}
		case CHAIR_RELEASE:
		{
			renderMap(chairs);

			separator();
			space();

			readInt("Informe a fileira:", &row);
			readInt("Informe a coluna:", &column);
			readInt("Informe o número de cadeiras:", &chairsLength);

			for (int i = column - 1; i < (column - 1) + chairsLength; i++) {
				chairs[row - 1][i].reserved = false;
			}

			clear();

			renderMap(chairs);

			space();
			blockSection();

			break;
		}
		case REPORTS_RESERVES_DETAILS:
		{
			for(int row = 0; row < rows; row++) {
				for(int column = 0; column < columns; column++) {
					if (chairs[row][column].reserved) {
						printChairDetail(chairs[row][column], row, column);
					}
				}
			}

			blockSection();

			break;
		}
		case REPORTS_CHAIRS_CONDITION:
		{
			chairCondition(chairs);
			float percentual = getPercentage(reserved, rows * columns);

			printf("Reserved: %d - %.1f%%\t", reserved, percentual);
			renderPercentageBar(percentual);

			space();
			space();

			percentual = getPercentage(available, rows * columns);

			printf("Available: %d - %.1f%%\t", available, percentual);
			renderPercentageBar(percentual);

			space();
			space();

			blockSection();

			break;
		}
		case REPORT_CHAIRS_SEX:
		{
			sexCondition(chairs);
			float percentual = getPercentage(men, men + women);

			printf("Masculinos: %d - %.1f%%\t", men, percentual);
			renderPercentageBar(percentual);

			space();
			space();

			percentual = getPercentage(women, men + women);

			printf("Femininos: %d - %.1f%%\t", women, percentual);
			renderPercentageBar(percentual);

			space();
			space();

			blockSection();

			break;
		}
		case REPORT_CHAIRS_BY_AGE:
		{
			int range[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

			for(int row = 0; row < rows; row++) {
				for(int column = 0; column < columns; column++) {
					if(chairs[row][column].reserved) {
						int index = (chairs[row][column].occupant.age - 1) / 10;

						range[index]++;
					}
				}
			}

			chairCondition(chairs);

			for (int i = 0; i < 10; i++) {
				float percentual = getPercentage(range[i], reserved);

				printf("%d ~ %d: %d - %.1f%%\t", i * 10 + 1, (i + 1) * 10 , range[i], percentual);
				renderPercentageBar(percentual);
				space();
			}

			blockSection();
			break;
		}
		case REPORT_CHAIRS_PAYING:
		{
			int rangeAge[] = {0, 0, 0};
			double rangeMoney[] = {0, 0, 0};
			double total = 0;

			for(int row = 0; row < rows; row++) {
				for(int column = 0; column < columns; column++) {
					if(chairs[row][column].reserved) {
						if(chairs[row][column].occupant.age <= 17) {
							rangeMoney[0] += ticketPrice / 2;
							total += ticketPrice / 2;
							rangeAge[0]++;
						} else if(chairs[row][column].occupant.age >= 60) {
							rangeMoney[2] += ticketPrice / 2;
							total += ticketPrice / 2;
							rangeAge[2]++;
						} else {
							rangeMoney[1] += ticketPrice;
							total += ticketPrice;
							rangeAge[1]++;
						}
					}
				}
			}

			chairCondition(chairs);

			for (int i = 0; i < 3; i++) {
				float percentual = getPercentage(rangeAge[i], reserved);

				switch (i) {
					case 0:
					{
						printf("1 ~ 17 anos: %d - %.1f%%\t", rangeAge[i], percentual);
						renderPercentageBar(percentual);
						printf(" - R$%.2lf", rangeMoney[i]);
						space();

						break;
					}
					case 1:
					{
						printf("18 ~ 59 anos: %d - %.1f%%\t", rangeAge[i], percentual);
						renderPercentageBar(percentual);
						printf(" - R$%.2lf", rangeMoney[i]);
						space();

						break;
					}
					case 2:
					{
						printf("> 60 anos: %d - %.1f%%\t", rangeAge[i], percentual);
						renderPercentageBar(percentual);
						printf(" - R$%.2lf", rangeMoney[i]);
						space();

						break;
					}
				}

			}

			blockSection();
			break;
		}
	}
}

void renderPercentageBar(float percentual) {
	printf("[");
	for(int i = 0; i < 20; i++){
		if(percentual >= 5){
			percentual = percentual - 5;
			printf("=");
		} else if(percentual > 0){
			percentual = percentual - 2.5;
			printf("-");
		}else if(percentual <= 0){
			printf(".");
		}
	}
	printf("]");
}

void menu(double ticketPrice, Chair chairs[rows][columns]) {
	int menuChoice = 0;

	do {
		renderMenu();
		readInt("Escolha uma opção:", &menuChoice);
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

	printf("	Menu");
	separator();
	space();

	printf("1. Consulta de disponibilidade de assento.\n");
	printf("2. Consulta de disponibilidade de assentos conjuntos.\n");
	printf("3. Reserva de assentos.\n");
	printf("4. Liberação de assentos.\n");

	space();
	space();
	printf("     Relatórios");
	separator();
	space();

	printf("5. Detalhes de reservas.\n");
	printf("6. Ocupação da sala.\n");
	printf("7. Reservas por sexo.\n");
	printf("8. Reservas por faixa de idade.\n");
	printf("9. Receita total.\n");

	space();
	space();
	printf("10. Sair.\n");
	separator();
}

Chair reserveChair() {
	Chair chair;

	readString("Informe o nome do ocupante:", chair.occupant.name);
	readChar("Informe o sexo do ocupante (M/F):", &chair.occupant.gender);
	readInt("Informe a idade do ocupante:", &chair.occupant.age);

	chair.reserved = true;

	return chair;
}

void setCineProperties(double *ticketPrice) {
	separator();
	printf("Olá! Seja bem-vindo(a) ao sistema de gerenciamento do CineC! \nPara começar, vamos preencher algumas informações básicas.\n");
	separator();

	readDouble("Informe o valor do ingresso: R$", ticketPrice);
	readInt("Informe a quantidade de fileiras da sala:", &rows);
	readInt("Informe a quantidade de assentos por fileira da sala:", &columns);
}

float getPercentage(int number, int total) {
	return number * 100 / total;
}

void chairCondition(Chair chairs[rows][columns]) {
	reserved = 0;
	available = 0;

	for(int row = 0; row < rows; row++) {
		for(int column = 0; column < columns; column++) {
			if (chairs[row][column].reserved) {
				reserved ++;
			} else {
				available ++;
			}
		}
	}
}

void sexCondition(Chair chairs[rows][columns]) {
	men = 0;
	women = 0;

	for(int row = 0; row < rows; row++) {
		for(int column = 0; column < columns; column++) {
			if (chairs[row][column].reserved && chairs[row][column].occupant.gender == 'M') {
				men ++;
			} else if(chairs[row][column].reserved) {
				women ++;
			}
		}
	}
}

void printChairDetail(Chair chair, int row, int column) {
	printf("O assento [%d - %d] está reservado para:", row + 1, column + 1);
	space();
	printf("%s\n", chair.occupant.name);
	printf("%s\n", chair.occupant.gender == 'M' ? "Homem" : "Mulher");
	printf("%d\n", chair.occupant.age);

	space();
}
