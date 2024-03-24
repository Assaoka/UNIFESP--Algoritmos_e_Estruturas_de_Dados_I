#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha {
	int info; // Informação do Elemento
	struct Pilha *prox; // Ponteiro para o Próximo Elemento
} SPilha;
typedef SPilha *PPilha;

PPilha push (PPilha topo, int v) {
	PPilha novo = (PPilha)malloc(sizeof(SPilha)); // Aloca Espaço para o Novo Elemento
	novo->info = v; // Insere a Informação no Novo Elemento
	novo->prox = topo; // O Novo Elemento Aponta para o Antigo Topo
	return novo; // Retorna o Novo Topo da Pilha
}

PPilha pop (PPilha topo, int *v) {
	PPilha p = topo; // Ponteiro Auxiliar para o Elemento a Ser Removido
	if (topo == NULL) return NULL; // Pilha Vazia

	*v = topo->info; // Retorna a Informação do Elemento Removido
	topo = topo->prox; // Atualiza o Topo para não Perder a Referência
	free(p); // Libera o Espaço Alocado do Elemento Removido
	return topo; // Retorna o Novo Topo da Pilha
}

void listar (PPilha topo) {
	PPilha p; // Ponteiro Auxiliar para Percorrer a Pilha
	for (p = topo; p != NULL; p = p->prox) { // Percorre a Pilha
		printf("%d ", p->info); // Imprime a Informação do Elemento
	}
}

PPilha liberar (PPilha topo) {
	PPilha p; // Ponteiro Auxiliar para Percorrer a Pilha
	for (p = topo; p != NULL; p = topo) { // Percorre a Pilha
		topo = topo->prox; // Atualiza o Topo para não Perder a Referência
		free(p); // Libera o Espaço Alocado do Elemento Removido
	}
	return NULL; // Pilha Vazia
}

void listarR (PPilha topo) {
	if (topo == NULL) return; // Pilha Vazia
	printf("%d ", topo->info); // Imprime a Informação do Elemento
	listarR(topo->prox); // Chama a Função para o Próximo Elemento (Recursão)
}

void listarRInv (PPilha topo) {
	if (topo == NULL) return; // Pilha Vazia
	listarRInv(topo->prox); // Chama a Função para o Próximo Elemento (Recursão)
	printf("%d ", topo->info); // Imprime a Informação do Elemento
}

PPilha liberarR (PPilha topo) {
	if (topo == NULL) return NULL; // Pilha Vazia
	liberarR(topo->prox); // Chama a Função para o Próximo Elemento (Recursão)
	free(topo); // Libera o Espaço Alocado do Elemento Removido
	return NULL; // Pilha Vazia
}
