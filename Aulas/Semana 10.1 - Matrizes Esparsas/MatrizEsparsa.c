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

// Liberar:
void liberar (PME matriz) {
	PNo p;
	int i;
	for (i = 0; i < MAX_LINHA; i++) {
		for (p = matriz[i]; matriz[i] != NULL; p = matriz[i]) { // Percorre a linha liberando os nós
			matriz[i] = p->prox;
			free(p);
		}
	}
}


// Questão 1: Crie uma função que encontra o maior valor em uma matriz esparsa e substituí a primeira ocorrência desse valor por 0.
void apagarMaior (PME matriz) {
	int i, linhaM;
	PNo ant, p, antM, pM;
	for (i = 0, p = matriz[i]; p == NULL && i < MAX_LINHA; i++, p = matriz[i]); // Encontra a primeira linha não vazia
	for (antM = NULL, pM = matriz[i], linhaM = i; i < MAX_LINHA; i++) {
		for (ant = NULL, p = matriz[i]; p != NULL; ant = p, p = p->prox) // Percorre a linha
			if (p->valor > pM->valor) { // Se o valor do elemento é maior que o maior valor encontrado até agora
				pM = p;
				antM = ant;
				linhaM = i;
			}
	}
	if (pM != NULL) { // Se encontrou um elemento (a matriz não é vazia)
		if (antM == NULL) matriz[linhaM] = pM->prox; 
		else antM->prox = pM->prox;
		free(pM);
	}
}


// Questão 2: Faça uma função que receba como parâmetros duas matrizes esparsas e retorne uma matriz esparsa que seja a soma das duas matrizes recebidas. Considere que as matrizes recebidas possuem o mesmo número de linhas e colunas.
void somaMatrizes (PME matriz1, PME matriz2, PME resposta) {
	int i, j, valor; 
	PNo p, q, ant;
	for (i = 0; i < MAX_LINHA; i++) {
		for (ant = NULL, p = matriz1[i], q = matriz2[i], j = 0; j < MAX_LINHA; j++) { // Percorre as duas linhas ao mesmo tempo
			valor = 0;
			if (p != NULL && p->coluna == j) { // Se existe um elemento na posição na primeira matriz, soma e avança
				valor += p->valor;
				p = p->prox;
			} if (q != NULL && q->coluna == j) { // Se existe um elemento na posição na segunda matriz, soma e avança
				valor += q->valor;
				q = q->prox;
			} if (valor != 0) { // Se o resultado da soma é diferente de zero, insere na matriz resposta
				if (ant == NULL) resposta[i] = ant = criarNo(valor, j, NULL); // Se é o primeiro elemento da linha
				else { // Caso contrário
					ant->prox = criarNo(valor, j, NULL); // Insere no final da linha
					ant = ant->prox; // Atualiza o ponteiro para o último elemento da linha
				}
			}
		}
	}
}