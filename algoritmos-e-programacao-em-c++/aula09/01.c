#include "stdio.h"
#include "../utils.h"

struct Pessoa {
	char nome[60];
	char sexo;
	char cidade[60];
	int idade;
	int idadePai;
	int idadeMae;
	int numeroFilhos;
	double renda;
};
struct Relatorio {
	double mediaFilhos;
	double mediaIdadePais;
	double mediaIdadeMaes;
	double mediaRenda;
	Pessoa pessoaMaiorRenda;
	Pessoa pessoaMenorRenda;
};

struct Pessoa realizarQuestionario();
void imprimirMenu();
void imprimirQuestionario(struct Pessoa pessoas[], int relatoriosRealizados);
struct Relatorio gerarRelatorio(struct Pessoa pessoas[], int relatoriosRealizados);

int main() {
	int menu = 0;
	int relatoriosRealizados = 0;
	struct Pessoa pessoas[250];

	while(menu != 3) {
		clear();
		imprimirMenu();
		readInt("Escolha uma opção:", &menu);

		switch (menu) {
			case 1:
				clear();
				pessoas[relatoriosRealizados] = realizarQuestionario();
				relatoriosRealizados++;
				break;
			case 2:
				clear();
				imprimirQuestionario(pessoas, relatoriosRealizados);
				break;
		}
	}

	separator();

	return 0;
}

struct Pessoa realizarQuestionario() {
	struct Pessoa pessoa;
	readString("1. Qual é o seu nome?", pessoa.nome);
	readChar("2. Qual é o seu sexo (M/F)?", &pessoa.sexo);
	readString("3. Qual é a sua cidade?", pessoa.cidade);
	readInt("4. Qual é a sua idade?", &pessoa.idade);
	readInt("5. Qual é a idade do seu pai?", &pessoa.idadePai);
	readInt("6. Qual é a idade da sua mãe?", &pessoa.idadeMae);
	readInt("7. Quantos filhos você tem?", &pessoa.numeroFilhos);
	readDouble("8. Qual a renda da família?", &pessoa.renda);

	return pessoa;
}

void imprimirMenu() {
	printf("1. Responder questionário\n");
	printf("2. Relatório de questionário\n");
	printf("3. Sair\n");
}

void imprimirQuestionario(struct Pessoa pessoas[], int relatoriosRealizados) {
	char sair[1];
	struct Relatorio relatorio = gerarRelatorio(pessoas, relatoriosRealizados);

	printf("Número médio de filhos: %f\n", relatorio.mediaFilhos);
	printf("Idade média dos pais: %f\n", relatorio.mediaIdadePais);
	printf("Idade média das mães: %f\n", relatorio.mediaIdadeMaes);

	printf("Idade do entrevistado com maior renda: %d\n", relatorio.pessoaMaiorRenda.idade);
	printf("Cidade do entrevistado com maior renda: %s\n", relatorio.pessoaMaiorRenda.cidade);

	printf("Idade do pai do entrevistado com menor renda: %d\n", relatorio.pessoaMenorRenda.idadePai);
	printf("Idade da mãe do entrevistado com menor renda: %d\n", relatorio.pessoaMenorRenda.idadeMae);

	printf("Renda média: %f\n", relatorio.mediaRenda);

	readString("Deseja voltar para o menu (S/N)?", sair);
}

struct Relatorio gerarRelatorio(struct Pessoa pessoas[], int relatoriosRealizados) {
	int somaFilhos = 0, somaIdadePais = 0, somaIdadeMaes = 0;
	double somaRenda = 0;
	struct Relatorio relatorio;

	for (int i = 0; i < relatoriosRealizados; i++) {
		struct Pessoa pessoa = pessoas[i];

		somaFilhos += pessoa.numeroFilhos;
		somaIdadePais += pessoa.idadePai;
		somaIdadeMaes += pessoa.idadeMae;
		somaRenda += pessoa.renda;

		if(pessoa.renda > relatorio.pessoaMaiorRenda.renda) {
			relatorio.pessoaMaiorRenda = pessoa;
		}

		if(pessoa.renda < relatorio.pessoaMenorRenda.renda) {
			relatorio.pessoaMenorRenda = pessoa;
		}
	}

	relatorio.mediaFilhos = somaFilhos / relatoriosRealizados;
	relatorio.mediaIdadePais = somaIdadePais / relatoriosRealizados;
	relatorio.mediaIdadeMaes = somaIdadeMaes / relatoriosRealizados;
	relatorio.mediaRenda = somaRenda / relatoriosRealizados;

	return relatorio;
}
