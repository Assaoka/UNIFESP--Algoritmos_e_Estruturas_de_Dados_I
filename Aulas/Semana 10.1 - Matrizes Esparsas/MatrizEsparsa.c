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

}


// Remoção:

// Busca:

// Impressão: