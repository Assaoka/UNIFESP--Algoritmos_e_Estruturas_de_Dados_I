#include <stdio.h>
#include <stdlib.h>

typedef struct ArvoreBinaria {
	int chave; // Informação do nó
	struct ArvoreBinaria *esq; // Ponteiro para o no da esquerda (menor)
	struct ArvoreBinaria *dir; // Ponteiro para o no da direita (maior)
} SArv;
typedef SArv *PArv;

// 1. Inserir:


// 2. Remover:


// 3. Buscar:

// Questão 2: Escreva uma função que obtenha o menor valor da árvore. 
int menor (PArv a) {

}

// Questão 3: Escreva uma função que imprime todos os valores dos nós da árvore que sejam menores que x, em ordem crescente.
void showmenor (PArv a, int x) {

}

// Questão 4: Escreva uma função que receba uma lista encadeada e construa uma ABB com os elementos desta lista. Liberar a lista e retornar a árvore gerada.


// Questão 5: Escreva uma função para verificar se uma árvore binária é ABB.
int verificaABB (PArv a) {
	
}
