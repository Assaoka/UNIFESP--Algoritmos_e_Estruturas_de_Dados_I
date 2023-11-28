#include <stdio.h>
#include <stdlib.h>

typedef struct ArvoreBinaria {
	int chave; // Informação do nó
	struct ArvoreBinaria *esq; // Ponteiro para o no da esquerda (menor)
	struct ArvoreBinaria *dir; // Ponteiro para o no da direita (maior)
} SArv;
typedef SArv *PArv;