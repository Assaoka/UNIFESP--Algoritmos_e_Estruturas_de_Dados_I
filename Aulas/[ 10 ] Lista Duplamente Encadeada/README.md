<h1 align="center"> Lista Duplamente Encadeada </h1>

# Definição de Lista Duplamente Encadeada:
Uma Lista Duplamente Encadeada é uma Lista em que Cada Nó Possui Dois Ponteiros (Um para o Próximo Elemento e Outro para o Elemento Anterior). Isso Permite que a Lista Seja Percorrida em Ambos os Sentidos (Do Início para o Fim e do Fim para o Início).

~~~c
typedef int tipoElemento; // Tipo de Dado que o Nó Armazena (Alterar de Acordo com o Problema)
typedef struct No {
	tipoElemento info; // Informação do Elemento
	struct No *prox; // Ponteiro para o Próximo Elemento
	struct No *ant; // Ponteiro para o Elemento Anterior
} SNo;
typedef SNo *PNo;
~~~


# Operações Básicas com Lista Duplamente Encadeada:
## `1. Inserir Nó:`
### `| Início:`
~~~c
PNo inserirIni (PNo lista, tipoElemento v) {
	PNo novo = (PNo) malloc(sizeof(SNo)); // Aloca Memória para o Novo Nó
	novo->info = v; // Atribui o Valor ao Novo Nó
	novo->prox = lista; // O Novo Nó Aponta para o Primeiro Elemento da Lista
    novo->ant = NULL; // O Novo Nó Aponta para NULL (Início da Lista)
    
	if (lista != NULL) lista->ant = novo; // O Primeiro Elemento da Lista Aponta para o Novo Nó
	lista = novo; // O Primeiro Elemento da Lista Agora é o Novo Nó
	return lista; // Retorna a Lista Atualizada (Novo Nó)
}
~~~
### `| Fim:`
~~~c
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
~~~
### `| Index:`
~~~c
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
~~~

## `2. Remover Nó:`
&emsp;&emsp; Uma vantagem da Lista Duplamente Encadeada é que podemos remover um elemento conhecendo apenas o endereço do elemento a ser removido. Podemos fazer isso da seguinte forma:
~~~c
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
~~~

&emsp;&emsp; Para remover um elemento basta encontrar o endereço do elemento com um laço de repetição e chamar a função `remover` passando o endereço do elemento a ser removido e a lista.


## `3. Buscar, Listar e Liberar:`
&emsp;&emsp; Podemos utilizar as mesmas funções da Lista Simplesmente Encadeada, pois a estrutura dos nós é a mesma. A única diferença é que temos um ponteiro a mais para percorrer a lista.
~~~c
PNo buscar (PNo lista, tipoElemento v) {
	PNo procurado; // Ponteiro para Percorrer a Lista
	for (procurado = lista; procurado != NULL; procurado = procurado->prox) // Percorre a Lista
		if (procurado->info == v) return procurado; // Se Encontrar o Elemento, Retorna o Nó
	return NULL; // Se Não Encontrar o Elemento, Retorna NULL
}
~~~

~~~c
void listar (PNo lista) {
	PNo aux; // Ponteiro Auxiliar para Percorrer a Lista
	for (aux = lista; aux != NULL; aux = aux->prox) // Percorre a Lista
		printf("%d ", aux->info); // Imprime a Informação do Elemento
	printf("\n");
}
~~~

~~~c
PNo liberar (PNo lista) {
	PNo aux; // Ponteiro Auxiliar para Percorrer a Lista
	for (aux = lista; aux != NULL; aux = lista) { // Percorre a Lista
		lista = lista->prox; // O Primeiro Elemento da Lista Agora é o Próximo Elemento do Nó Removido
		free(aux); // Libera a Memória Alocada para o Nó Removido
	}
	return NULL; // Retorna NULL (Lista Vazia)
}
~~~
