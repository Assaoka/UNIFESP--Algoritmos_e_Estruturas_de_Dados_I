<h1 align="center"> Semana 14 - Árvores Binárias de Busca </h1>

## Árvores Binárias:
&emsp;&emsp; Dentro da variedade de árvores, as árvores binárias são as mais usadas. Elas são um caso especial onde  `nenhum nó tem grau maior do que dois,` ou seja, cada nó pode ter no máximo dois filhos.

&emsp;&emsp; As subárvores de uma árvore binária são chamadas de `subárvore esquerda` e `subárvore direita.` A ordem entre os filhos é importante, `um filho à esquerda é diferente de um filho à direita.` Se trocarmos a ordem dos filhos de um nó obtemos outra árvore.

&emsp;&emsp; Cada nó deve armazenar 3 campos:
<br>&emsp;&emsp;&emsp;&emsp; 1. `A informação que o nó guarda.`
<br>&emsp;&emsp;&emsp;&emsp; 2. `Um ponteiro para o filho da esquerda.`
<br>&emsp;&emsp;&emsp;&emsp; 3. `Um ponteiro para o filho da direita.`

&emsp;&emsp; Uma estrutura que podemos usar para representar uma árvore binária é a seguinte:
~~~c
typedef int tipoElemento; // Tipo de dado que o nó armazena (alterar de acordo com o problema)
typedef struct ArvoreBinaria {
	tipoElemento info; // Informação do nó
	struct ArvoreBinaria *esq; // Ponteiro para o no da esquerda
	struct ArvoreBinaria *dir; // Ponteiro para o no da direita
} SArv;
typedef SArv *PArv;
~~~


## Operações Básicas com Árvores Binárias:
### `1. Criar:`
~~~c
PArv cria (tipoElemento info, PArv esq, PArv dir) {
	PArv novo = (PArv)malloc(sizeof(SArv)); // Aloca memória para o novo nó
	novo->info = info; // Insere a informação no novo nó
	novo->esq = esq; // Faz o ponteiro da esquerda apontar para o nó da esquerda
	novo->dir = dir; // Faz o ponteiro da direita apontar para o nó da direita
	return novo; // Retorna o novo nó
}
~~~
&emsp;&emsp; `Como a implementação de uma árvore é recursiva,` a função cria pode ser utilizada tanto para `criar uma árvore` inteira quanto para `criar uma subárvore` e inserir em uma árvore já existente (fazendo um nó receber como filho a subárvore criada).

### `2. Imprimir:`
&emsp;&emsp; Aqui temos que introduzir um conceito novo. `A impressão de uma árvore binária pode ser feita de três formas:`
<br>&emsp;&emsp;&emsp;&emsp; 1. `Prefixa:` Imprime primeiro a raiz, depois a subárvore esquerda e por último a subárvore direita.
<br>&emsp;&emsp;&emsp;&emsp; 2. `Infixa:` Imprime primeiro a subárvore esquerda, depois a raiz e por último a subárvore direita.
<br>&emsp;&emsp;&emsp;&emsp; 3. `Pósfixa:` Imprime primeiro a subárvore esquerda, depois a subárvore direita e por último a raiz.
~~~c
void imprimir (PArv a) {
	if (a == NULL) return; // Condição de parada
	printf("%d ", a->info); // Alterar de acordo com o problema
	imprimir(a->esq); // Imprimir a subárvore esquerda
	imprimir(a->dir); // Imprimir a subárvore direita
}
~~~
&emsp;&emsp; O código acima imprime a árvore de forma `prefixa.` Para imprimir nas outras formas, basta trocar a ordem das três últimas linhas.

### `3. Buscar:`
&emsp;&emsp; Para busca em árvores binárias, podemos retornar verdadeiro ou falso, ou retornar o nó que contém a informação buscada.
~~~c
int buscarVF (PArv a, tipoElemento v) {
	if (a == NULL) return 0; // Condição de parada (não achou)
	if (a->info == v) return 1; // Condição de parada (achou)
	return (buscarVF(a->esq, v) || buscarVF(a->dir, v)); // Busca na subárvore esquerda, se não achar, busca na subárvore direita. Propaga o resultado da busca
}
~~~
~~~c
PArv buscarNo (PArv a, tipoElemento v) {
	PArv aux; // Guarda o resultado da busca
	if (a == NULL) return NULL; // Condição de parada (não achou)
	if (a->info == v) return a; // Condição de parada (achou)
	aux = buscarNo(a->esq, v); // Busca na subárvore esquerda
	if (aux != NULL) return aux; // Se achou, retorna o resultado da busca
	return buscarNo(a->dir, v); // Se não achou, retorna o resultado da busca na subárvore direita
}
~~~

### `4. Liberar:`
&emsp;&emsp; Para liberar uma árvore binária, devemos liberar o nó e seus filhos na ordem `pósfixa.` Caso seja liberado na ordem `prefixa` ou `infixa,` perdemos a referência para os filhos.
~~~c
PArv liberar (PArv a) {
	if (a == NULL) return NULL; // Condição de parada
	a->esq = liberar(a->esq); // Libera a subárvore esquerda
	a->dir = liberar(a->dir); // Libera a subárvore direita
	free(a); // Libera o nó
	return NULL; // Retorna NULL
}
~~~
&emsp;&emsp; Essa função também pode ser utilizada para `podar uma subárvore,` fazendo o nó pai do nó a ser podado receber NULL no ponteiro para o filho correspondente.


## Exercícios:
### `Questão 1:` Escreva uma função que conte a quantidade de nós em uma árvore binária. O protótipo da função deve ser dado por: int quant_nos(PArv a);
~~~c
int quant_nos(PArv a) {
	if (a == NULL) return 0; // Condição de parada
	return (1 + quant_nos(a->esq) + quant_nos(a->dir)); // retorna a quantidade de descendentes + 1 para representar o próprio nó.
}
~~~

### `Questão 2:` Escreva uma função que percorre uma árvore binária para determinar sua altura. O protótipo da função deve ser dado por: int altura(PArv a);
&emsp;&emsp; Para resolver esse problema, devemos lembrar que a altura de uma subárvore vazia é -1.
~~~c
int maior(int a, int b) {return (a > b) ? a : b;} // Operador ternário (condição) ? (se verdadeiro) : (se falso)
int altura(PArv a) {
	if (a == NULL) return -1; // Condição de parada (Árvore vazia tem altura -1)
	return (1 + maior(altura(a->esq), altura(a->dir))); // Retorna a maior altura entre as subárvores esquerda e direita + 1 para representar o próprio nó.
}
~~~
