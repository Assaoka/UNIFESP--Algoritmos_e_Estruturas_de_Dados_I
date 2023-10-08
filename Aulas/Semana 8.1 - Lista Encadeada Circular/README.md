<h1 align="center"> Semana 8.1 - Lista Encadeada Circular </h1>

## Definição de Lista Encadeada Circular:
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



## Operações Básicas com Pilhas Encadeadas:
### `1. Inserir Nó:`
#### `| Início:`
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
#### `| Fim:`
~~~c

~~~
#### `| Índex:`
Iremos considerar que 0 representa a primeira posição na lista. Além disso, a inserção ocorrerá no início se o índice for menor que 0 e no final se for maior do que o tamanho da lista, como tratamento de erros.
~~~c

~~~
