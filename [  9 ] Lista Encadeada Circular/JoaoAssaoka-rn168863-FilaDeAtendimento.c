// João Victor Assaoka Ribeiro - rn168863
#include <stdio.h>
#include <stdlib.h>

typedef struct fila { // Estrutura que representa um cliente. 
	// Os clientes são inseridos no final da fila (na função InsereFilaCirc) e removidos do início da fila (na função ImprimeELibera). Como o Primeiro a Entrar é o Primeiro a Sair ("First-In-First-Out"), essa estrutura de dados é uma fila.
	int num; // Número de Identificação do cliente (Iniciando em 0, conversão necessária para imprimir o resultado)
	struct fila *prox; // Ponteiro para o próximo cliente
} SFila;
typedef SFila *PFila;

typedef struct SUltimoFila { // Estrutura que representa um caixa
	int tempo; // Tempo total de atendimento do caixa (Utilizado para descobrir qual caixa que fica livre primeiro)
	PFila ultimo; // Guarda o último elemento da fila (Permite que acessemos qualquer elemento da fila, pois foi implementada como lista circular)
} SUltimoFila;
typedef SUltimoFila *PUltimoFila;

int BuscarMenorTempo (SUltimoFila VetFilas[], int A) {
	int i, menor;
	for (i = menor = 0; i < A; i++) {
		if (VetFilas[i].tempo < VetFilas[menor].tempo) menor = i; // "Quando dois ou mais atendentes estiverem disponíveis a prioridade de atendimento é do atendente com menor número de identificação." Fazemos isso comparando apenas se é menor, pois utilizamos a posição do vetor +1 como identificação do caixa. 
	}
	return menor;
}

void InsereFilaCirc (PUltimoFila Caixa, int T, int num) {
	PFila novo = (PFila) malloc(sizeof(SFila)); // Aloca memória para o novo cliente
	Caixa->tempo += T; // Atualiza o tempo total de atendimento do caixa
	novo->num = num; // Atribui a identificação do cliente

	if (Caixa->ultimo == NULL) { // Se a fila estiver vazia
		novo->prox = novo; // O novo cliente aponta para ele mesmo
		Caixa->ultimo = novo; // O último cliente é o novo cliente
		return;
	}
	// Se a fila não estiver vazia (dado que se estiver vazia, a função já retornou)
	novo->prox = Caixa->ultimo->prox; // O novo cliente aponta para o primeiro cliente da fila
	Caixa->ultimo->prox = novo; // O último cliente aponta para o novo cliente
	Caixa->ultimo = novo; // O último cliente é o novo cliente
}

void ImprimeELibera (PUltimoFila Caixa) {
	PFila p = Caixa->ultimo->prox; // p aponta para o primeiro cliente da fila
	
	// Não precisamos checar se é null porque a função só é chamada se Caixa->ultimo != NULL
	
	while (p != Caixa->ultimo) { // Enquanto não chegar no último cliente
		printf(" %d", p->num + 1); // Imprime a identificação do cliente atual
		Caixa->ultimo->prox = p->prox; // O último cliente aponta para o próximo do cliente atual
		free(p); // Libera o cliente atual
		p = Caixa->ultimo->prox; // p aponta para o próximo cliente
	}
	printf(" %d\n", p->num + 1); // Imprime a identificação do último cliente
	free(p); // Libera o último cliente
}

int main () {
	int N, A, T, i, j; // N = Número de clientes, A = Número de atendentes, T = Tempo de atendimento
	PUltimoFila VetFilas;

	// "A entrada para cada teste se inicia informado a quantidade de clientes N (1 ≤ N ≤ 1023) que vão ser atendidas e o número de atendentes A (1 ≤ A ≤ 25)."
	scanf(" %d %d", &N, &A);
	if ((N < 1)||(N > 1023)||(A < 1)||(A > 25)) return 1; // (1 ≤ N ≤ 1023) e (1 ≤ A ≤ 25)

	// "A fila de atendimento deve ser simplesmente encadeada e dinâmica, mas o vetor de filas pode ser estático."
	VetFilas = (PUltimoFila) malloc(A * sizeof(SUltimoFila)); 
	for (i = 0; i < A; i++) { // Inicializa o vetor de filas
		VetFilas[i].tempo = 0;
		VetFilas[i].ultimo = NULL;
	}

	for (i = 0; i < N; i++) { // Lê o tempo de atendimento de cada cliente e insere na fila de menor tempo
		scanf(" %d", &T);
		j = BuscarMenorTempo(VetFilas, A); // Busca o caixa com menor tempo de atendimento
		InsereFilaCirc((VetFilas + j), T, i); // Insere o cliente na fila do caixa com menor tempo de atendimento
	}

	for (i = 0; i < A; i++) { // Imprime o resultado
		printf("%d:", i + 1); // Número de identificação do caixa
		if (VetFilas[i].ultimo != NULL) ImprimeELibera((VetFilas + i)); // Se o caixa atendeu alguém, imprime a fila de clientes atendidos e libera a memória
		else printf("\n"); // "Quando um atendente/caixa não atender ninguém, a linha de exibição deste caixa deve mostrar apenas a identificação do caixa sem nenhuma fila de clientes atendidos"
	}
	free(VetFilas); // Libera o vetor de filas
	
	return 0;
}
