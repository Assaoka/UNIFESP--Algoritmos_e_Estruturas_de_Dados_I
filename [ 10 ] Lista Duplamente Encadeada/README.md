<h1 align="center"> Lista Duplamente Encadeada <br>
  <a href="../[  9 ] Lista Encadeada Circular/"><img src="https://img.shields.io/badge/Anterior-Lista Encadeada Circular-215a36" alt="Anterior"></a>
  <a href="../[ 11 ] Lista Genérica/"><img src="https://img.shields.io/badge/Próximo-Lista Genérica-215a36" alt="Próximo"></a>
</h1>

# Definição de Lista Duplamente Encadeada:
&emsp;&emsp; Da mesma forma que os outros tipos de lista, uma Lista Duplamente Encadeada é uma estrutura de dados que Armazena Elementos de Forma Encadeada. A diferença é que cada Nó possui `Dois Ponteiros` (Um para o Próximo Elemento e outro para o Elemento Anterior). `Isso Permite que a Lista Seja Percorrida em Ambos os Sentidos` (Do Início para o Fim e do Fim para o Início).

&emsp;&emsp; De certa forma, isso `facilita a remoção de elementos` (pois não precisamos percorrer a lista para encontrar o elemento anterior ao que será removido), `mas ao mesmo tempo, torna as operações mais complexas` (pois precisamos atualizar mais ponteiros para manter a lista corretamente encadeada). Podemos criar uma estrutura de nó da seguinte forma:
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
	return novo; // Retorna a Lista Atualizada (Novo Nó)
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
&emsp;&emsp; Uma desvantagem da Lista Simplesmente Encadeada é a dificuldade de remover um elemento. Mesmo que saibamos o endereço do elemento a ser removido, é necessário percorrer a lista para encontrar o elemento anterior ao que será removido. 

&emsp;&emsp; A Lista Duplamente Encadeada resolve esse problema, pois podemos percorrer a lista em ambos os sentidos. Basta encontrar o elemento a ser removido e atualizar os ponteiros do elemento anterior e do elemento posterior ao que será removido.
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

# Lista Duplamente Encadeada e Circular:
&emsp;&emsp; A Lista Duplamente Encadeada e Circular é uma Lista Duplamente Encadeada em que o Último Elemento aponta para o Primeiro Elemento e o Primeiro Elemento aponta para o Último Elemento. Você pode escolher guardar o endereço do último ou do primeiro elemento, pois ambos são "equivalentes" (se você tiver o endereço do último elemento, pode obter o endereço do primeiro elemento e vice-versa, então é possível inserir e remover elementos no início e no fim da lista com a mesma complexidade idependente de qual endereço você escolher guardar). Não tenho a intenção de refazer todas as funções para a lista circular, mas você pode fazer isso se quiser.

# Exercícios:
## `Questão 1:` Escreva uma função que remova de uma lista duplamente encadeada todos os elementos que contêm o valor de y.
&emsp;&emsp; Dica: Utilize a função `remover` e a função `buscar` para encontrar os elementos a serem removidos.

## `Questão 2:` Escreva uma função que insira um elemento em ordem crescente em uma lista duplamente encadeada

---
