#include <stdio.h>
#include <stdlib.h>

typedef int tipoElemento; // Tipo de Dado que o Nó Armazena (Alterar de Acordo com o Problema)
typedef struct No {
	tipoElemento info; // Informação do Elemento
	struct No *prox; // Ponteiro para o Próximo Elemento
	struct No *ant; // Ponteiro para o Elemento Anterior
} SNo;
typedef SNo *PNo;

PNo inserirIni (PNo lista, tipoElemento v) {
	PNo novo = (PNo) malloc(sizeof(SNo)); // Aloca Memória para o Novo Nó
	novo->info = v; // Atribui o Valor ao Novo Nó
	novo->prox = lista; // O Novo Nó Aponta para o Primeiro Elemento da Lista
    novo->ant = NULL; // O Novo Nó Aponta para NULL (Início da Lista)
    
	if (lista != NULL) lista->ant = novo; // O Primeiro Elemento da Lista Aponta para o Novo Nó
	lista = novo; // O Primeiro Elemento da Lista Agora é o Novo Nó
	return lista; // Retorna a Lista Atualizada (Novo Nó)
}

PNo inserirFim (PNo lista, tipoElemento v) {
	PNo novo = (PNo) malloc (sizeof(SNo)); // Aloca Memória para o Novo Nó
	PNo ant, paux; // ant = Ponteiro para o Nó Anterior, paux = Ponteiro Auxiliar para Percorrer a Lista

	novo->info = v; // Atribui o Valor ao Novo Nó
	novo->prox = NULL; // O Novo Nó Aponta para NULL (Fim da Lista)
	for (ant = NULL, paux = lista; paux != NULL; paux = paux->prox) ant = paux; // Percorre a Lista até o Fim
	novo->ant = ant; // O Novo Nó Aponta para o Último Elemento da Lista

	if (ant == NULL) lista = novo; // Se a Lista Estiver Vazia, o Novo Nó é o Primeiro Elemento
	else ant->prox = novo; // Caso Contrário, o Antigo Último Elemento Aponta para o Novo Nó

	return lista; // Retorna a Lista Atualizada (Primeiro Elemento, Sofrendo Alterações ou Não)
}

PNo inserirIndex (PNo lista, tipoElemento v, int index) { 
	PNo novo = (PNo) malloc(sizeof(SNo)); // Aloca Memória para o Novo Nó
	PNo ant, paux; // ant = Ponteiro para o Nó Anterior, paux = Ponteiro Auxiliar para Percorrer a Lista
	int i; // i = Contador

	novo->info = v; // Atribui o Valor ao Novo Nó
	for (i = 0, ant = NULL, paux = lista; i < index && paux != NULL; i++, paux = paux->prox) ant = paux; // Percorre a Lista até o Fim ou até o Índice

	novo->ant = ant; // O Novo Nó Aponta para o Nó Anterior
	if (ant == NULL) { // Se a Lista Estiver Vazia ou o Índice For 0 (ou Menor)
		novo->prox = lista; // O Novo Nó Aponta para o Primeiro Elemento da Lista
		if (lista != NULL) lista->ant = novo; // O Primeiro Elemento da Lista Aponta para o Novo Nó
		lista = novo; // O Primeiro Elemento da Lista Agora é o Novo Nó
	} else { // Caso Contrário
		novo->prox = ant->prox; // O Novo Nó Aponta para o Próximo Elemento do Anterior
		if (novo->prox != NULL) novo->prox->ant = novo; // O Anterior do Próximo Elemento do Novo Nó Aponta para o Novo Nó
		ant->prox = novo; // O Anterior Aponta para o Novo Nó
	}

	return lista; // Retorna a Lista Atualizada (Primeiro Elemento, Sofrendo Alterações ou Não)
}


PNo remover (PNo removido, PNo lista) {
	if (removido == NULL) return lista; // Se não deve remover nada, retorna a lista
	if (removido->prox != NULL) removido->prox->ant = removido->ant; // Não é o último elemento
	if (removido->ant != NULL) removido->ant->prox = removido->prox; // Não é o primeiro elemento
	else { // É o primeiro elemento
		lista = lista->prox;
		if (lista != NULL) lista->ant = NULL;
	}
	free(removido);
	return lista;
}

void listar (PNo lista) {
	PNo aux; // Ponteiro Auxiliar para Percorrer a Lista
	for (aux = lista; aux != NULL; aux = aux->prox) // Percorre a Lista
		printf("%d ", aux->info); // Imprime a Informação do Elemento
	printf("\n");

	// Percorrer a Lista em Ordem Inversa
	for (aux = lista; aux->prox != NULL; aux = aux->prox); // Percorre a Lista até o Fim
	for (; aux != NULL; aux = aux->ant) // Percorre a Lista em Ordem Inversa
		printf("%d ", aux->info); // Imprime a Informação do Elemento
	printf("\n");
}

PNo liberar (PNo lista) {
	PNo aux; // Ponteiro Auxiliar para Percorrer a Lista
	for (aux = lista; aux != NULL; aux = lista) { // Percorre a Lista
		lista = lista->prox; // O Primeiro Elemento da Lista Agora é o Próximo Elemento do Nó Removido
		free(aux); // Libera a Memória Alocada para o Nó Removido
	}
	return NULL; // Retorna NULL (Lista Vazia)
}

int main () {
	PNo lista = NULL; // Inicializa a Lista Vazia

	lista = inserirIni(lista, 2); // Insere o Elemento 2 no Início da Lista
	lista = inserirIni(lista, 1); // Insere o Elemento 1 no Início da Lista
	lista = inserirFim(lista, 4); // Insere o Elemento 3 no Fim da Lista
	lista = inserirFim(lista, 5); // Insere o Elemento 4 no Fim da Lista
	
	
	lista = inserirIndex(lista, 0, 0); // Insere o Elemento 0 no Índice 0 da Lista
	listar(lista); // Lista a Lista (0 1 2 6 7)

	lista = inserirIndex(lista, 3, 3); // Insere o Elemento 3 no Índice 3 da Lista
	listar(lista); // Lista a Lista (0 1 2 3 6 7)

	lista = inserirIndex(lista, 6, 6); // Insere o Elemento 6 no Índice 6 da Lista
	listar(lista); // Lista a Lista (0 1 2 3 6 7 6)

	lista = inserirIndex(lista, 7, 10); // Insere o Elemento 7 no Índice 10 da Lista
	listar(lista); // Lista a Lista (0 1 2 3 6 7 6 7)
	
	
	lista = remover(lista, lista); // Remove o Primeiro Elemento da Lista
	listar(lista); // Lista a Lista (1 2 3 6 7 6 7)

	PNo aux;
	for (aux = lista; aux != NULL; aux = aux->prox) {
		printf("%d\n", aux->info);
		if (aux->info == 3) {
			lista = remover(aux, lista); // Remove o Elemento 3 da Lista
			break;
		}
	}
	listar(lista);

	for (aux = lista; aux->prox != NULL; aux = aux->prox);
	lista = remover(aux, lista); // Remove o Último Elemento da Lista
	listar(lista);

	lista = liberar(lista); // Libera a Memória Alocada para a Lista
	return 0;
}
