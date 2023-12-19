<h1 align="center"> Lista Duplamente Encadeada </h1>

## Definição de Lista Duplamente Encadeada:
Uma Lista Duplamente Encadeada é uma Lista em que Cada Nó Possui Dois Ponteiros (Um para o Próximo Elemento e Outro para o Elemento Anterior).
<br>&emsp;&emsp; 1. A Estrutura é Alterada, pois cada nó possui dois ponteiros.
<br>&emsp;&emsp; 2. A Inserção e Remoção de Elementos é Facilitado, pois não Precisamos de um Ponteiro Auxiliar para Percorrer a Lista. 
<br>&emsp;&emsp; 3. Ao Mesmo Tempo, a Inserção e Remoção de Elementos é mais Complexa, pois Precisamos Atualizar Dois Ponteiros.


## Operações Básicas com Lista Duplamente Encadeada:
### `2. Remover Nó:`
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

Em Breve...