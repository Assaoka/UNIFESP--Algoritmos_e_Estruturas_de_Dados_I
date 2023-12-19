#include <stdio.h>

void MaiorMenorEficiente (int V[], int Tam, int *Maior, int *Menor) {
	int i = 2;
	if (Tam % 2 == 1) { // Se for impar, maior e menor viram V[0]
		*Maior = *Menor = V[0];
		i = 1;
	} else { // Se for par, o Maior recebe o maior dos dois primeiros e o Menor o menor
		if (V[0] > V[1]) *Maior = V[0], *Menor = V[1];
		else *Maior = V[1], *Menor = V[0];
	}

	while (i < Tam) {
		if (V[i] > V[i + 1]) { // Analisa o Maior com o maior e o Menor com o Menor.
			if (V[i] > *Maior) *Maior = V[i];
			if (V[i + 1] < *Menor) *Menor = V[i + 1];
		} else {
			if (V[i + 1] > *Maior) *Maior = V[i + 1];
			if (V[i] < *Menor) *Menor = V[i];
		}
		i += 2; // Anda para as duas próximas casas
	}
}

void LerVetor (int V[], int Tam) {
	int i = -1;
	while (++i < Tam)
		printf("V[%d] = ", i), scanf(" %d", &V[i]);
}

int main() {
	int Tam;
	printf("Digite o tamanho do vetor: "), scanf("%d", &Tam);
	
	int V[Tam];
	LerVetor(V, Tam);

	int Maior, Menor;
	MaiorMenorEficiente(V, Tam, &Maior, &Menor);
	printf("\nMaior: %d\nMenor: %d\n", Maior, Menor);

	return 0;
}
