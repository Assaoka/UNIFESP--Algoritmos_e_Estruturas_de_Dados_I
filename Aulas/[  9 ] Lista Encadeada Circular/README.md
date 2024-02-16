<h1 align="center"> Lista Encadeada Circular </h1>

# Definição de Lista Encadeada Circular:
Uma Lista Encadeada Circular é uma Lista Encadeada em que o `Último Elemento` Aponta para o `Primeiro Elemento.` 
<br>&emsp;&emsp; 1. A `Estrutura` Permanece a Mesma, mas o `Comportamento` é Diferente. 
<br>&emsp;&emsp; 2. Guardamos um Ponteiro para o `Último Elemento` da Lista, para Facilitar a `Inserção no Fim da Lista.` Isso Proporciona uma `Maneira Simplificada` de Implementar uma `Fila Encadeada`, pois isso dispensa a Necessidade da Estrutura auxiliar `Fila`.

~~~c
typedef int tipoElemento; // Tipo de Dado que o Nó Armazena (Alterar de Acordo com o Problema)
typedef struct No {
	tipoElemento info; // Informação do Elemento
	struct No *prox; // Ponteiro para o Próximo Elemento
} SNo;
typedef SNo *PNo;
~~~

&emsp;&emsp; Uma coisa importante a se notar é que nessa estrutura de dados, o ultimo elemento não aponta para `NULL`, mas sim para o primeiro elemento da lista. Isso é essencial para montar as operações de inserção e remoção de elementos.



# Operações Básicas com Lista Encadeada Circular:
## `1. Inserir Nó:`
### `| Início:`
~~~c
PNo inserirIni (PNo ult, tipoElemento v) {
	PNo novo = (PNo) malloc (sizeof(SNo)); // Alocando Memória para o Novo Nó

	novo->info = v; // Atribuindo o Valor ao Novo Nó
	if (ult == NULL) { // Se a Lista Estiver Vazia
		novo->prox = novo; // O Novo Nó Aponta para Ele Mesmo
		return novo; // O Novo Nó Se Torna o Último (E Único) Elemento da Lista
	}
	novo->prox = ult->prox; // Caso Contrário, o Novo Nó Aponta para o Primeiro Elemento da Lista
	ult->prox = novo; // O Último Elemento da Lista Aponta para o Novo Nó

	return ult; // Retorna o Último Elemento da Lista (Que Continua o Mesmo)
}
~~~
### `| Fim:`
&emsp;&emsp; A única diferença entre inserir no início e no fim é que no fim, o ponteiro para o último elemento da lista é atualizado para o novo elemento. Essa função pode ser utilizada para uma fila encadeada circular.
~~~c
PNo inserirFim (PNo ult, tipoElemento v) {
	PNo novo = (PNo) malloc(sizeof(SNo)); // Alocando Memória para o Novo Nó

	novo->info = v; // Atribuindo o Valor ao Novo Nó
	if (ult == NULL) { // Se a Lista Estiver Vazia
		novo->prox = novo; // O Novo Nó Aponta para Ele Mesmo
		return novo; // O Novo Nó Se Torna o Último (E Único) Elemento da Lista
	}
	novo->prox = ult->prox; // Caso Contrário, o Novo Nó Aponta para o Primeiro Elemento da Lista
	ult->prox = novo; // O Último Elemento da Lista Aponta para o Novo Nó

	return novo; // Retorna o Novo Elemento da Lista (Que Agora é o Último). Essa é a Única Diferença entre Inserir no Início e no Fim.
}
~~~
### `| Índex:`
&emsp;&emsp; Iremos considerar que 0 representa a primeira posição na lista. A inserção ocorrerá no início se o índice for menor que 0. Caso o índice seja maior que o número de elementos, vamos continuar percorrendo a lista até o índice.
~~~c
PNo inserirIndex (PNo ult, tipoElemento v, int index) {
	PNo novo = (PNo) malloc(sizeof(SNo)); // Alocando Memória para o Novo Nó
	PNo ant, paux; // ant = Ponteiro para o Nó Anterior; paux = Ponteiro Auxiliar para Percorrer a Lista
	int i; // Contador

	novo->info = v; // Atribuindo o Valor ao Novo Nó
	if (ult == NULL) { // Se a Lista Estiver Vazia
		novo->prox = novo; // O Novo Nó Aponta para Ele Mesmo
		return novo; // O Novo Nó Se Torna o Último (E Único) Elemento da Lista
	}
	
	for (i = 0, ant = ult, paux = ult->prox; i < index; i++, paux = paux->prox) ant = paux; // Percorrendo a Lista até o Índice
	
	novo->prox = ant->prox; // O Novo Nó Aponta para o Próximo Elemento do Anterior de Onde Ele Será Inserido
	ant->prox = novo; // O Anterior Aponta para o Novo Nó

	if (ant == ult && index != 0) return novo; // Se o Índice for 0, o Novo Nó Será o Novo Último
	else return ult; // Retorna o Último Elemento da Lista (Sofrendo Alterações ou Não)
}
~~~

## `2. Remover Nó:`
### `| Início:`
&emsp;&emsp; Utilizando essa função em conjunto com a função de inserção no fim, podemos implementar uma fila encadeada circular sem a necessidade de uma estrutura auxiliar `Fila`.
~~~c
PNo removerIni (PNo ult, tipoElemento *v) {
	PNo lixo; // Ponteiro para o Nó que Será Removido

	if (ult == NULL) return NULL; // Se a Lista Estiver Vazia, Retorna NULL
	lixo = ult->prox; // O Nó que Será Removido é o Primeiro Elemento da Lista
	*v = lixo->info; // Retorna a Informação do Nó a Ser Removido
	if (ult == ult->prox) { // Se o Último Elemento da Lista Apontar para Ele Mesmo (Lista Só Possui um Elemento)
		free (lixo); // Libera a Memória Alocada para o Nó
		return NULL; // Retorna NULL (Lista Vazia)
	}
	ult->prox = lixo->prox; // Caso Contrário, o Último Elemento Aponta para o Próximo do Nó a Ser Removido
	free (lixo); // Libera a Memória Alocada para o Nó

	return ult; // Retorna o Último Elemento da Lista
}
~~~
### `| Fim:`
~~~c
PNo removerFim (PNo ult, tipoElemento *v) {
	PNo ant, lixo; // ant = Ponteiro para o Nó Anterior; lixo = Ponteiro para o Nó que Será Removido

	if (ult == NULL) return NULL; // Se a Lista Estiver Vazia, Retorna NULL
	for (ant = ult, lixo = ult->prox; lixo != ult; ant = lixo, lixo = lixo->prox); // Percorrendo a Lista até o Último Elemento
	*v = lixo->info; // Retorna a Informação do Nó a Ser Removido
	if (ant == lixo) ant = NULL; // Se o Anterior é o Próprio Nó a Ser Removido, A Lista Só Possui um Elemento (Ficará Vazia Após a Remoção)
	else ant->prox = lixo->prox; // Caso Contrário, o Anterior Aponta para o Próximo do Nó a Ser Removido
	free(lixo); // Libera a Memória Alocada para o Nó

	return ant; // Atualiza o Ponteiro para o Último Elemento da Lista (Que Será o Anterior do Nó Removido, ou NULL)
}
~~~
### `| Índex:`
~~~c
PNo removerIndex (PNo ult, tipoElemento *v, int index) {
	PNo ant, lixo;
	int i;

	if (ult == NULL) return NULL; // Se a Lista Estiver Vazia, Retorna NULL
	for (i = 0, ant = ult, lixo = ult->prox; i < index; i++, ant = lixo, lixo = lixo->prox); // Percorrendo a Lista até o Índice

	*v = lixo->info; // Retorna a Informação do Nó a Ser Removido
	if (ant == lixo) ant = NULL;
	else ant->prox = lixo->prox; // Caso Contrário, o Anterior Aponta para o Próximo do Nó a Ser Removido

	free(lixo); // Libera a Memória Alocada para o Nó
	if (ult == lixo) return ant; 
	//ult = ant; // Se o Último Elemento da Lista for o Nó a Ser Removido, o Anterior Será o Novo Último
	else return ult; // Retorna o Último Elemento da Lista (Que Pode Ter Sido Alterado)
}
~~~

## `3. Buscar:`
~~~c
PNo buscar (PNo ult, tipoElemento v) {
	PNo procurado; // Ponteiro para Percorrer a Lista

	if (ult == NULL) return NULL; // Se a Lista Estiver Vazia, Retorna NULL
	for (procurado = ult->prox; procurado != ult; procurado = procurado->prox) { // Percorrendo a Lista
		if (procurado->info == v) return procurado; // Se o Valor do Nó Atual for o Valor Procurado, Retorna o Nó
	}
	if (ult->info == v) return ult; // Se o Valor do Último Nó for o Valor Procurado, Retorna o Último Nó (Fazemos isso pois o Último Nó não é Verificado no For)

	return NULL; // Se Não Encontrar o Elemento, Retorna NULL
}
~~~

## `4. Listar:`
~~~c
void listar (PNo ult) {
	PNo aux; // Ponteiro para Percorrer a Lista

	for (aux = ult->prox; aux != ult; aux = aux->prox) // Percorre a Lista
		printf("%d ", aux->info); // Imprime o Valor do Nó Atual
	if (ult != NULL) printf("%d\n", ult->info); // Se a Lista Estiver Vazia, Não Entrará Aqui nem no For, Então Não Imprime Nada. Se a Lista só Possuir um Elemento, o For Não é Executado, mas o Último Nó é Impresso Aqui.
}
~~~

## `5. Liberar:`
~~~c
PNo liberar (PNo ult) {
	PNo aux; // Ponteiro para Percorrer a Lista

	for (aux = ult->prox; aux != ult; aux = ult->prox) { // Percorre a Lista
		ult->prox = aux->prox; // O Último Elemento Aponta para o Próximo do Nó Atual
		free(aux); // Libera a Memória Alocada para o Nó Atual
	}
	if (ult != NULL) free(ult); // Libera a Memória Alocada para o Último Nó (Que é o Único que Restou)

	return NULL; // Retorna NULL (Lista Vazia)
}
~~~

#
