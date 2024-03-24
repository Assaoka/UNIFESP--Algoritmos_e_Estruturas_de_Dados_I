#include <stdio.h>
#include <stdlib.h>

typedef int tipoElemento; // Tipo de Dado que a Fila Armazena (Alterar de Acordo com o Problema)
typedef struct No {
	tipoElemento info; // Informação do Elemento
	struct No *prox; // Ponteiro para o Próximo Elemento
} SNo;
typedef SNo *PNo;

typedef struct Fila {
	PNo ini; // Primeiro Elemento da Fila
	PNo fim; // Último Elemento da Fila
} SFila;
typedef SFila *PFila;

PFila inicializar () { 
	PFila novo = (PFila) malloc(sizeof(SFila)); // Aloca Espaço para a Fila
	novo->ini = NULL; 
	novo->fim = NULL;
	return novo;
}

PNo insere (PFila fila, tipoElemento v) {
	if (fila == NULL) return NULL; // Fila Não Inicializada (Erro)

	PNo novo = (PNo) malloc(sizeof(SNo)); // Aloca Espaço para o Novo Elemento
	novo->info = v; // Insere a Informação no Novo Elemento
	novo->prox = NULL; // O Novo Elemento Aponta para o Antigo Topo
	
	if (fila->ini == NULL) fila->ini = novo; // Fila Vazia (Inicio aponta para o novo elemento)
	else fila->fim->prox = novo; // Fila Não Vazia (O último elemento aponta para o novo elemento)
	
	fila->fim = novo; // Atualiza o Fim da Fila
	return fila->fim; // Retorna o Novo Fim da Fila
}

PNo remover (PFila fila, tipoElemento *v) {
	if (fila == NULL) return NULL; // Fila Não Inicializada (Erro)

	PNo lixo = fila->ini; // Ponteiro Auxiliar para o Elemento a Ser Removido
	if (fila->ini == NULL) return NULL; // Fila Vazia (Impossível Remover)
	
	*v = lixo->info; // Retorna a Informação do Elemento Removido
	if (fila->ini == fila->fim) fila->fim = NULL; // Fila com Apenas um Elemento (Atualiza o Fim da Fila)
	fila->ini = lixo->prox; // Atualiza o Início da Fila
	
	free(lixo); // Libera o Espaço Alocado do Elemento Removido
	return fila->ini; // Retorna o Novo Início da Fila
}

void listar (PNo ini) {
	PNo aux; // Ponteiro Auxiliar para Percorrer a Fila
	for (aux = ini; aux != NULL; aux = aux->prox) // Percorre a Fila
		printf("%d ", aux->info); // Imprime a Informação do Elemento
	printf("\n");
}

void listarR (PNo ini) {
	if (ini == NULL) { // Fila Vazia OU Fim da Fila
		printf("\n");
		return;
	}   
	printf("%d ", ini->info); // Imprime a Informação do Elemento
	listarR(ini->prox); // Chama a Função para o Próximo Elemento (Recursão)
}

PFila liberar (PFila fila) {
	PNo aux; // Ponteiro Auxiliar para Percorrer a Fila
	if (fila == NULL) return NULL; // Fila Não Inicializada (Erro)
	for (aux = fila->ini; aux != NULL; aux = fila->ini) { // Percorre a Fila
		fila->ini = aux->prox; // Atualiza o Início da Fila para não Perder a Referência
		free(aux); // Libera o Espaço Alocado do Elemento Removido
	}
	free(fila); // Libera o Espaço Alocado da Fila
	return NULL; // Fila Vazia
}
