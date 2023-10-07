<h1 align="center"> Semana 7.0 - Fila Encadeada </h1>
 
## Definição de Fila Encadeada:
Uma Fila Encadeada é uma Estrutura de Dados que Segue o Princípio `FIFO` (First In First Out), ou seja, `O Primeiro Elemento a Entrar na Fila é o Primeiro a Sair.`
<br>&emsp;&emsp;1. O `Novo Elemento` Sempre é `Inserido no Final` (Ordem de Chegada);
<br>&emsp;&emsp;2. O `Elemento Removido` é Sempre o que `Chegou há Mais Tempo na Fila`;

<br>Cada Elemento é Representado por Outra Estrutura que Contém um Ponteiro para o Próximo Elemento da Fila e o Valor do Elemento em si.
~~~c
typedef int tipoElemento; // Tipo de Dado que a Fila Armazena (Alterar de Acordo com o Problema)
typedef struct No {
	tipoElemento info; // Informação do Elemento
	struct No *prox; // Ponteiro para o Próximo Elemento
} SNo;
typedef SNo *PNo;
~~~

<br>Uma fila encadeada pode ser implementada usando uma estrutura que contém um ponteiro para o primeiro elemento da fila e um ponteiro para o último elemento da fila.
~~~c
typedef struct Fila {
	PNo ini; // Primeiro Elemento da Fila
	PNo fim; // Último Elemento da Fila
} SFila;
typedef SFila *PFila;
~~~





## Operações Básicas com Filas Encadeadas:
### `1. Criar uma Fila Vazia`
~~~c
PFila inicializar () { 
	PFila novo = (PFila) malloc(sizeof(SFila)); // Aloca Espaço para a Fila
	novo->ini = NULL; 
	novo->fim = NULL;
	return novo;
}
~~~
