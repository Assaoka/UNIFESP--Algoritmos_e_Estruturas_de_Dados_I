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
	if (valor == 0) return; // Se o valor a ser inserido é zero, não faz nada
	for (ant = NULL, p = matriz[linha]; p != NULL && p->coluna < coluna; ant = p, p = p->prox); // percorre a linha até encontrar a posição correta
	if (p != NULL && p->coluna == coluna) p->valor = valor; // Se já existe um elemento na posição, atualiza o valor
	else if (ant == NULL) matriz[linha] = criarNo(valor, coluna, p); // Inserir no início da linha
	else ant->prox = criarNo(valor, coluna, p); // Inserir no meio ou no final da linha
}


// Remoção:
void remover (PME matriz, int linha, int coluna) {
	PNo ant, p;
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
	for (p = matriz[linha]; p != NULL && p->coluna < coluna; p = p->prox); // percorre a linha até encontrar a posição correta
	if (p != NULL && p->coluna == coluna) return p->valor; // Se existe um elemento na posição, retorna o valor
	return 0; // Se não existe um elemento na posição, retorna 0
}

// Impressão:
int imprimir (PME matriz) {

}
