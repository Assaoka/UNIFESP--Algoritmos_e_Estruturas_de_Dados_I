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
void inserir (PME matriz, int valor, int linha, int coluna) {
    PNo ant, p, novo = (PNo)malloc(sizeof(SNo));
    novo->valor = valor;
    novo->coluna = coluna;

    for (ant = NULL, p = matriz[linha]; p != NULL && coluna > p->coluna; ant = p, p = p->prox); // percorre a linha até encontrar a posição correta
    novo->prox = p;
    if (ant == NULL) matriz[linha] = novo; // inserção no início da linha
    else ant->prox = novo; // inserção no meio ou no final da linha
}


// Remoção:

// Busca:

// Impressão: