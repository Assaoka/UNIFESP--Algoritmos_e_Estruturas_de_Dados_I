<h1 align="center" style="text-decoration: underline; font-weight: bold;"> Lista Encadeada </h1>

# Definição de Lista Encadeada:
Uma Lista Encadeada é uma Generalização das Pilhas e Filas:
<br>&emsp;&emsp; 1. O `Novo Elemento` pode ser Inserido em `Qualquer Posição da Lista.`
<br>&emsp;&emsp; 2. O `Novo Elemento` pode ser Retirado em `Qualquer Posição da Lista.`

Cada Elemento da lista é chamado de Nó, e cada nó possui dois campos:
<br>&emsp;&emsp;1. Um Campo que Armazena `Informação do Elemento.`
<br>&emsp;&emsp;2. Um `Ponteiro` que Aponta para o `Próximo Elemento.`

~~~c
typedef int tipoElemento; // Tipo de Dado que o Nó Armazena (Alterar de Acordo com o Problema)
typedef struct No {
	tipoElemento info; // Informação do Elemento
	struct No *prox; // Ponteiro para o Próximo Elemento
} SNo;
typedef SNo *PNo;
~~~



# Operações Básicas com Lista Encadeada:
## `1. Inserir Nó:`
### `| Início:`
~~~c
PNo inserirIni (PNo lista, tipoElemento v) {
	PNo novo = (PNo) malloc(sizeof(SNo)); // Aloca Memória para o Novo Nó
	novo->info = v; // Atribui o Valor ao Novo Nó
	novo->prox = lista; // O Novo Nó Aponta para o Primeiro Elemento da Lista
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
	if (ant == NULL) lista = novo; // Se a Lista Estiver Vazia, o Novo Nó é o Primeiro Elemento
	else ant->prox = novo; // Caso Contrário, o Antigo Último Elemento Aponta para o Novo Nó

	return lista; // Retorna a Lista Atualizada (Primeiro Elemento, Sofrendo Alterações ou Não)
}
~~~
### `| Índex:`
Iremos considerar que 0 representa a primeira posição na lista. Além disso, a inserção ocorrerá no início se o índice for menor que 0 e no final se for maior do que o tamanho da lista, como tratamento de erros.
~~~c
PNo inserirIndex (PNo lista, tipoElemento v, int index) { 
	PNo novo = (PNo) malloc(sizeof(SNo)); // Aloca Memória para o Novo Nó
	PNo ant, paux; // ant = Ponteiro para o Nó Anterior, paux = Ponteiro Auxiliar para Percorrer a Lista
	int i; // i = Contador

	novo->info = v; // Atribui o Valor ao Novo Nó
	for (i = 0, ant = NULL, paux = lista; i < index && paux != NULL; i++, paux = paux->prox) ant = paux; // Percorre a Lista até o Fim ou até o Índice
	if (ant == NULL) { // Se a Lista Estiver Vazia ou o Índice For 0 (ou Menor)
		novo->prox = lista; // O Novo Nó Aponta para o Primeiro Elemento da Lista
		lista = novo; // O Primeiro Elemento da Lista Agora é o Novo Nó
	} else { // Caso Contrário
		novo->prox = ant->prox; // O Novo Nó Aponta para o Próximo Elemento do Anterior
		ant->prox = novo; // O Anterior Aponta para o Novo Nó
	}

	return lista; // Retorna a Lista Atualizada (Primeiro Elemento, Sofrendo Alterações ou Não)
}
~~~

## `2. Remover Nó:`
### `| Início:`
~~~c
PNo removerIni (PNo lista, tipoElemento *v) {
	PNo lixo = lista; // Ponteiro para o Nó que Será Removido
	if (lista == NULL) return NULL; // Se a Lista Estiver Vazia, Retorna NULL

	*v = lixo->info; // Retorna a Informação do Nó a Ser Removido
	lista = lixo->prox; // O Primeiro Elemento da Lista Agora é o Próximo Elemento do Nó Removido
	free(lixo); // Libera a Memória Alocada para o Nó Removido
	return lista; // Retorna a Lista Atualizada (Próximo do Nó Removido)
}
~~~
### `| Fim:`
~~~c
PNo removerFim (PNo lista, tipoElemento *v) {
	PNo ant, lixo; // ant = Ponteiro para o Nó Anterior, lixo = Ponteiro para o Nó que Será Removido

	if (lista == NULL) return NULL; // Se a Lista Estiver Vazia, Retorna NULL
	for (ant = NULL, lixo = lista;  lixo->prox != NULL; lixo = lixo->prox) ant = lixo; // Percorre a Lista até o Fim (Dessa Forma, ant Aponta para o Penúltimo Elemento)
	
	if (ant == NULL) lista = NULL; // Se a Lista Tinha Apenas um Elemento, Agora a Lista é Vazia
	else ant->prox = NULL; // Caso Contrário, o Antigo Penúltimo Elemento Aponta para NULL (Se tornando o Último Elemento)
	*v = lixo->info; // Retorna a Informação do Nó a Ser Removido
	free(lixo); // Libera a Memória Alocada para o Nó Removido
	
	return lista; // Retorna a Lista Atualizada (Primeiro Elemento, Sofrendo Alterações ou Não)
}
~~~
### `| Índex:`
~~~c
PNo removerIndex (PNo lista, tipoElemento *v, int index) {
	PNo ant, lixo; // ant = Ponteiro para o Nó Anterior, lixo = Ponteiro para o Nó que Será Removido
	int i; // i = Contador

	if (lista == NULL) return NULL; // Se a Lista Estiver Vazia, Retorna NULL
	for (i = 0, ant = NULL, lixo = lista; i < index && lixo->prox != NULL; i++, lixo = lixo->prox) ant = lixo; // Percorre a Lista até o Fim ou até o Índice (Dessa Forma, ant Aponta para o Nó Anterior ao Removido)
	
	if (ant == NULL) lista = lixo->prox; // Se Queremos Remover o Primeiro Elemento, o Primeiro Elemento da Lista Agora é o Próximo Elemento do Nó Removido (Se a Lista Tiver Apenas um Elemento, a Lista Agora é Vazia)
	else ant->prox = lixo->prox; // Caso Contrário, o Anterior Aponta para o Próximo Elemento do Nó Removido
	*v = lixo->info; // Retorna a Informação do Nó a Ser Removido
	free(lixo); // Libera a Memória Alocada para o Nó Removido
	return lista; // Retorna a Lista Atualizada (Primeiro Elemento, Sofrendo Alterações ou Não)
}
~~~

## `3. Buscar:`
~~~c
PNo buscar (PNo lista, tipoElemento v) {
	PNo procurado; // Ponteiro para Percorrer a Lista
	for (procurado = lista; procurado != NULL; procurado = procurado->prox) // Percorre a Lista
		if (procurado->info == v) return procurado; // Se Encontrar o Elemento, Retorna o Nó
	return NULL; // Se Não Encontrar o Elemento, Retorna NULL
}
~~~

## `4. Listar:`
~~~c
void listar (PNo lista) {
	PNo aux; // Ponteiro Auxiliar para Percorrer a Lista
	for (aux = lista; aux != NULL; aux = aux->prox) // Percorre a Lista
		printf("%d ", aux->info); // Imprime a Informação do Elemento
	printf("\n");
}
~~~

## `5. Liberar:`
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



# Teste para as Funções:
~~~c
int main () {
	PNo lista = NULL, auxBusca;
	tipoElemento v;

	// Teste 1: Inserir no início da lista
	lista = inserirIni(lista, 1);
	lista = inserirIni(lista, 2);
	lista = inserirIni(lista, 3);
	lista = inserirIni(lista, 4);
	listar(lista); // Deve imprimir: 4 3 2 1

	// Teste 2: Inserir no fim da lista
	lista = inserirFim(lista, 5);
	lista = inserirFim(lista, 6);
	lista = inserirFim(lista, 7);
	lista = inserirFim(lista, 8);
	listar(lista); // Deve imprimir: 4 3 2 1 5 6 7 8

	// Teste 3: Inserir em uma posição específica da lista
	lista = inserirIndex(lista, 9, 0);
	lista = inserirIndex(lista, 10, 2);
	lista = inserirIndex(lista, 11, 15);
	lista = inserirIndex(lista, 12, -1);
	listar(lista); // Deve imprimir: 12 9 4 10 3 2 1 5 6 7 8 11

	// Teste 4: Remover do início da lista
	lista = removerIni(lista, &v);
	listar(lista); // Deve imprimir: 9 4 10 3 2 1 5 6 7 8 11

	// Teste 5: Remover do fim da lista
	lista = removerFim(lista, &v);
	lista = removerFim(lista, &v);
	listar(lista); // Deve imprimir: 9 4 10 3 2 1 5 6 7

	// Teste 6: Remover de uma posição específica da lista
	lista = removerIndex(lista, &v, 4); // Deve remover o elemento 2
	lista = removerIndex(lista, &v, -11); // Deve remover o elemento 9
	lista = removerIndex(lista, &v, 15); // Deve remover o elemento 7
	listar(lista); // Deve imprimir: 4 10 3 1 5 6

	// Teste 7: Buscar um elemento na lista
		// Deve imprimir: Elemento encontrado: 4
		auxBusca = buscar(lista, 4); // Deve encontrar o elemento 4
		if (auxBusca != NULL) printf("Elemento encontrado: %d\n", auxBusca->info); 
		else printf("Elemento inexistente.\n");
	
		// Deve imprimir: Elemento não encontrado.
		auxBusca = buscar(lista, 33); // Não deve encontrar o elemento 33
		if (auxBusca != NULL) printf("Elemento encontrado: %d\n", auxBusca->info);
		else printf("Elemento inexistente.\n");

	// Teste 8: Liberar a lista
	lista = liberar(lista); 
	listar(lista); // Deve imprimir uma linha em branco

	return 0;
}
~~~
