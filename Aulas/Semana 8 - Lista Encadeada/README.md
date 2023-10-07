<h1 align="center"> Semana 7.1 - Lista Encadeada </h1>

## Definição de Lista Encadeada:
Uma Lista Encadeada é uma Generalização das Pilhas e Filas:
<br>&emsp;&emsp; 1. O `Novo Elemento` pode ser Inserido em `Qualquer Posição da Lista.`
<br>&emsp;&emsp; 1. O `Novo Elemento` pode ser Retirado em `Qualquer Posição da Lista.`

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

