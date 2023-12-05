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
    for (ant = NULL, p = matriz[linha]; p != NULL && p->coluna < coluna; ant = p, p = p->prox); // percorre a linha até encontrar a posição correta para a coluna
    if (p != NULL && p->coluna == coluna) p->valor = valor; // Se já existe um elemento na posição, atualiza o valor
    else if (ant == NULL) matriz[linha] = criarNo(valor, coluna, p); // Inserir no início da linha
    else ant->prox = criarNo(valor, coluna, p); // Inserir no meio ou no final da linha
}


// Remoção:

// Busca:

// Impressão: