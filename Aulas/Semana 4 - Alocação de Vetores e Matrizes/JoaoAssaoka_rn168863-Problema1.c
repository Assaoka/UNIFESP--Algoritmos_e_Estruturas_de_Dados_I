// João Victor Assaoka Ribeiro - rn168863
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nome[21]; // 20 Caracteres + '/0'
	int num;
} CARRO;

int main() {
	int N, i, j, Aux_Num, Aux_Controle; // 3 ≤ N ≤ 1000
	CARRO **carros, *Troca_Struct;

	// "A primeira linha da entrada contém o número N (3≤N≤1000) de participantes da corrida."
	scanf(" %d", &N);
	if ((N < 3) || (N > 1000)) return 0;

	// "As próximas N linhas contêm os seguintes dados dos competidores: número do carro e nome. O número do carro é um inteiro positivo e único. O nome é um nome simples (sem espaço) de até 20 caracteres."
	carros = (CARRO **)malloc(N * sizeof(CARRO *));
	if (carros == NULL) exit(1); // Erro na Alocação
	for (i = 0; i < N; i++) {
		carros[i] = (CARRO *)malloc(sizeof(CARRO));
		if (carros[i] == NULL) exit(1); // Erro na Alocação
		scanf(" %d %s", &carros[i]->num, carros[i]->nome);
	}

	// "Na linha seguinte, são passados N números separados por espaços, correspondendo aos números dos carros em ordem de largada, do primeiro ao último carro."
	for (i = 0; i < N; i++)	{
		scanf(" %d", &Aux_Num);
		for (j = i; j < N; j++) {
			if (carros[j]->num == Aux_Num) {
				Troca_Struct = carros[j];
				carros[j] = carros[i];
				carros[i] = Troca_Struct;
			}
		}
	}

	// "Nas linhas seguintes, são apresentadas as ultrapassagens. Cada uma dessas linhas contém o  número do carro que faz a ultrapassagem sobre o carro a sua frente. A última linha contém o número -1, indicando o final da entrada."
	do {
		scanf(" %d", &Aux_Controle);
		if (Aux_Controle != -1) {
			if (carros[0]->num != Aux_Controle) {
				for (i = 1; i < N; i++) {
					if (carros[i]->num == Aux_Controle) {					
						Troca_Struct = carros[i];
						carros[i] = carros[i - 1];
						carros[i - 1] = Troca_Struct;
					}
				}
			}
		}
	} while (Aux_Controle != -1);

	// Você deve imprimir a lista com o número e o nome dos três primeiros colocados da corrida, sendo um participante por linha, do primeiro para o terceiro lugar.
	for (i = 0; i < 3; i++)	{
		printf("%d %s\n", carros[i]->num, carros[i]->nome);
	}

	// Libera a Memoria Alocada
	for (i = 0; i < N; i++)
		free(carros[i]);
	free(carros);
	return 0;
}
