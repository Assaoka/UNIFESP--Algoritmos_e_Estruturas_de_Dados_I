#include <stdio.h>
#include <stdlib.h>

// Definição de tipos:
#define MAX_LINHA 10
typedef struct no {
	int valor, coluna; // valor e coluna do elemento
	struct no *prox; // ponteiro para o próximo elemento da linha
} SNo;
typedef SNo *PNo; // ponteiro para SNo
typedef PNo PME[MAX_LINHA]; // Vetor de ponteiros para guardar o endereço do primeiro nó de cada linha


// Inicialização:
void inicializa(PME matriz) {
	int i;
	for (i = 0; i < MAX_LINHA; i++) matriz[i] = NULL; // inicializa todas as linhas com NULL (vazias)
}

// Inserção:
PNo criarNo (int valor, int coluna, PNo prox) { // Aloca um novo nó com os valores passados e retorna o endereço
	PNo novo = (PNo)malloc(sizeof(SNo));
	novo->valor = valor;
	novo->coluna = coluna;
	novo->prox = prox;
	return novo;
}

void inserir (PME matriz, int valor, int linha, int coluna) {
	PNo ant, p;
	if (valor == 0 || linha >= MAX_LINHA) return; // Se o valor a ser inserido é zero ou a linha é inválida, não faz nada
	for (ant = NULL, p = matriz[linha]; p != NULL && p->coluna < coluna; ant = p, p = p->prox); // percorre a linha até encontrar a posição correta
	if (p != NULL && p->coluna == coluna) p->valor = valor; // Se já existe um elemento na posição, atualiza o valor
	else if (ant == NULL) matriz[linha] = criarNo(valor, coluna, p); // Inserir no início da linha
	else ant->prox = criarNo(valor, coluna, p); // Inserir no meio ou no final da linha
}


// Remoção:
void remover (PME matriz, int linha, int coluna) {
	PNo ant, p;
	if (linha >= MAX_LINHA) return; // Se a linha é inválida, não faz nada
	for (ant = NULL, p = matriz[linha]; p != NULL && p->coluna < coluna; ant = p, p = p->prox); // percorre a linha até encontrar a posição correta
	if (p != NULL && p->coluna == coluna) { // Se existe um elemento na posição
		if (ant == NULL) matriz[linha] = p->prox; // Se é o primeiro elemento da linha
		else ant->prox = p->prox; // Se é um elemento do meio ou do final da linha
		free(p); // Libera o nó
	}
}

// Busca:
int buscar (PME matriz, int linha, int coluna) {
	PNo p;
	if (linha >= MAX_LINHA) return 0; // Se a linha é inválida, retorna 0. O ideal seria retornar um valor que não pode ser um elemento da matriz
	for (p = matriz[linha]; p != NULL && p->coluna < coluna; p = p->prox); // percorre a linha até encontrar a posição correta
	if (p != NULL && p->coluna == coluna) return p->valor; // Se existe um elemento na posição, retorna o valor
	return 0; // Se não existe um elemento na posição, retorna 0
}

// Impressão:
void imprimir (PME matriz, int colunas) {
	PNo p;
	int i, j;
	for (i = 0; i < MAX_LINHA; i++) {
		for (j = 0, p = matriz[i]; j < colunas; j++) {
			if (p != NULL && p->coluna == j) { // Se existe um elemento na posição
				printf("%d\t", p->valor); // Imprime o valor
				p = p->prox; // Avança para o próximo elemento da linha
			} else printf("0\t"); // Se não existe um elemento na posição, imprime 0
		}
		printf("\n");
	}
}

