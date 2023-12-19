#include <stdio.h>
#include <stdlib.h>

typedef int tipoElemento; // Tipo de Dado que o Nó Armazena (Alterar de Acordo com o Problema)
typedef struct No {
	tipoElemento info; // Informação do Elemento
	struct No *prox; // Ponteiro para o Próximo Elemento
	struct No *ant; // Ponteiro para o Elemento Anterior
} SNo;
typedef SNo *PNo;

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