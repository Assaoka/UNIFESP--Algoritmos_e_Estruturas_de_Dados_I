#include <stdio.h>
#include <stdlib.h>

typedef int tipoElemento; // Tipo de dado que o nó armazena (alterar de acordo com o problema)
typedef struct ArvoreBinaria {
	tipoElemento info; // Informação do nó
	struct ArvoreBinaria *esq; // Ponteiro para o no da esquerda
	struct ArvoreBinaria *dir; // Ponteiro para o no da direita
} SArv;
typedef SArv *PArv;

PArv cria (tipoElemento info, PArv esq, PArv dir) {
	PArv novo = (PArv)malloc(sizeof(SArv)); // Aloca memória para o novo nó
	novo->info = info; // Insere a informação no novo nó
	novo->esq = esq; // Faz o ponteiro da esquerda apontar para o nó da esquerda
	novo->dir = dir; // Faz o ponteiro da direita apontar para o nó da direita
	return novo; // Retorna o novo nó
}

void imprimir (PArv a) {
	if (a == NULL) return; // Condição de parada
	printf("%d ", a->info); // Alterar de acordo com o problema
	imprimir(a->esq); // Imprimir a subárvore esquerda
	imprimir(a->dir); // Imprimir a subárvore direita
}

int buscarVF (PArv a, tipoElemento v) {
	if (a == NULL) return 0; // Condição de parada (não achou)
	if (a->info == v) return 1; // Condição de parada (achou)
	return (buscarVF(a->esq, v) || buscarVF(a->dir, v)); // Busca na subárvore esquerda, se não achar, busca na subárvore direita. Propaga o resultado da busca
}

PArv buscarNo (PArv a, tipoElemento v) {
	PArv aux; // Guarda o resultado da busca
	if (a == NULL) return NULL; // Condição de parada (não achou)
	if (a->info == v) return a; // Condição de parada (achou)
	aux = buscarNo(a->esq, v); // Busca na subárvore esquerda
	if (aux != NULL) return aux; // Se achou, retorna o resultado da busca
	return buscarNo(a->dir, v); // Se não achou, retorna o resultado da busca na subárvore direita
}

PArv liberar (PArv a) {
	if (a == NULL) return NULL; // Condição de parada
	a->esq = liberar(a->esq); // Libera a subárvore esquerda
	a->dir = liberar(a->dir); // Libera a subárvore direita
	free(a); // Libera o nó
	return NULL; // Retorna NULL
}

int quant_nos(PArv a) {
	if (a == NULL) return 0; // Condição de parada
	return (1 + quant_nos(a->esq) + quant_nos(a->dir)); // retorna a quantidade de descendentes + 1 para representar o próprio nó.
}

int maior(int a, int b) {return (a > b) ? a : b;} // Operador ternário (condição) ? (se verdadeiro) : (se falso)
int altura(PArv a) {
	if (a == NULL) return -1; // Condição de parada (Árvore vazia tem altura -1)
	return (1 + maior(altura(a->esq), altura(a->dir))); // Retorna a maior altura entre as subárvores esquerda e direita + 1 para representar o próprio nó.
}

void imprimir (PArv a, int i) {
	if (a == NULL) return; // Condição de parada
	for (int j = 0; j < i; j++) printf("\t"); // Imprime os tabs de acordo com o nível do nó atual (paragrafação)
	printf("%d\n", a->chave); // Imprime a chave do nó atual
	imprimir(a->esq, i + 1); // Imprime a subárvore da esquerda
	imprimir(a->dir, i + 1); // Imprime a subárvore da direita
}
