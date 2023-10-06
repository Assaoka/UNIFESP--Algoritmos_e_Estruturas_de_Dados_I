<h1 align="center"> Semana 6 (17/09/2023) - Pilha Encadeada </h1>
 
## Definição de Pilha: 
`Último a Entrar, Primeiro a Sair` ("Last In, First Out" -> `LIFO`)	
<br>&emsp;&emsp;1.  O `Novo Elemento` é Sempre Inserido no `Topo da Pilha`
<br>&emsp;&emsp;2. O `Elemento Removido` é Sempre o que `Chegou a Menos Tempo na Pilha`

~~~c
typedef struct Pilha {
	int info; // Informação do Elemento
	struct Pilha *prox; // Ponteiro para o Próximo Elemento
} SPilha;
typedef SPilha *PPilha;
~~~




## Operações Básicas Sobre Pilhas:
### `1. Empilhar Elemento:` Push
~~~c
PPilha push (PPilha topo, int v) {
	PPilha novo = (PPilha)malloc(sizeof(SPilha)); // Aloca Espaço para o Novo Elemento
	novo->info = v; // Insere a Informação no Novo Elemento
	novo->prox = topo; // O Novo Elemento Aponta para o Antigo Topo
	return novo; // Retorna o Novo Topo da Pilha
}
~~~

### `2. Desempilhar Elemento:` Pop
~~~c
PPilha pop (PPilha topo, int *v) {
	PPilha p = topo; // Ponteiro Auxiliar para o Elemento a Ser Removido
	if (topo == NULL) return NULL; // Pilha Vazia

	*v = topo->info; // Retorna a Informação do Elemento Removido
	topo = topo->prox; // Atualiza o Topo para não Perder a Referência
	free(p); // Libera o Espaço Alocado do Elemento Removido
	return topo; // Retorna o Novo Topo da Pilha
}
~~~


### `3. Listar Elementos da Pilha:`
~~~c
void listar (PPilha topo) {
	PPilha p; // Ponteiro Auxiliar para Percorrer a Pilha
	for (p = topo; p != NULL; p = p->prox) { // Percorre a Pilha
		printf("%d ", p->info); // Imprime a Informação do Elemento
	}
}
~~~


### `4. Liberar Espaços Alocados:`
~~~c
PPilha liberar (PPilha topo) {
	PPilha p; // Ponteiro Auxiliar para Percorrer a Pilha
	for (p = topo; p != NULL; p = topo) { // Percorre a Pilha
		topo = topo->prox; // Atualiza o Topo para não Perder a Referência
		free(p); // Libera o Espaço Alocado do Elemento Removido
	}
	return NULL; // Pilha Vazia
}
~~~



## Exercícios:
### `Questão 1:` Faça uma função recursiva que imprime a pilha.
~~~c
void listarR (PPilha topo) {
	if (topo == NULL) return; // Pilha Vazia
	printf("%d ", topo->info); // Imprime a Informação do Elemento
	listarR(topo->prox); // Chama a Função para o Próximo Elemento (Recursão)
}
~~~

~~~c

~~~

### `Questão 2:` Faça uma função recursiva que libera a pilha.
~~~c
~~~
