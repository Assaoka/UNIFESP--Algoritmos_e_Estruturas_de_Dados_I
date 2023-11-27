<h1 align="center"> Semana 12 - Árvores Binárias </h1>

## Introdução a Árvores:
&emsp;&emsp; Sendo uma das `classes de estruturas de dados mais importantes,` as árvores são estruturas de dados que `permitem representar dados com hierarquias,` o que é muito útil para representar alguns tipos de dados como:
<br>&emsp;&emsp; 1. Um sistema de arquivos de um computador.
<br>&emsp;&emsp; 2. O organograma de uma empresa.
<br>&emsp;&emsp; 3. A divisão de um livro em capítulos, seções, tópicos...
<br>&emsp;&emsp; 4. A árvore genealógica de uma pessoa.

&emsp;&emsp; `Formalmente,` uma árvore é um conjunto `finito` de nós, onde:
<br>&emsp;&emsp; 1. Uma árvore é um grafo conexo `acíclico.`
<br>&emsp;&emsp; 2. Existe um nó especial chamado de `raiz` da árvore, que é o nó que `não possui pai.`
<br>&emsp;&emsp; 3. Os demais nós possuem `exatamente um pai.`
<br>&emsp;&emsp; 4. Cada nó forma uma árvore com seus filhos, chamada de `subárvore.`


## Conceitos Básicos:
1. `Arestas:` Conexões entre os nós da árvore.
1. `Caminho:` Dizemos que existe um caminho entre dois nós se existir uma `sequência de arestas` que conectam os dois nós. Podemos observar por meio da definição que: `O caminho entre dois nós é único` e `Sempre existe um caminho entre a raiz e qualquer outro nó da árvore.`
3. `Ancestral:` Dizemos que um nó `A` é ancestral de um nó `B` se existe um caminho de `A` até `B`. Se este caminho contiver uma única aresta, dizemos que `A` é pai de `B`.
4. `Descendente:` Dizemos que um nó `A` é descendente de um nó `B` se existe um caminho de `B` até `A`. Se este caminho contiver uma única aresta, dizemos que `A` é filho de `B`.
5. `Irmãos:` Dizemos que dois nós são irmãos se possuem o mesmo pai.
6. `Nós Folha/Terminal:` Nós que não possuem filhos (nós com grau zero). 
7. `Grau:` Número de filhos de um nó. O grau de uma árvore é o `maior grau de seus nós.`
8. `Nível:` Número de arestas entre um nó e a raiz. O nível da raiz é zero. Se um nó está no nível `n`, seus filhos estão no nível `n+1`. O nível de uma árvore é o `maior nível de seus nós.`
9. `Árvore Completa:` Uma árvore de grau G é completa se todos os seus nós possuem exatamente `G filhos` e todas as `folhas estão no mesmo nível.`
10. `Floresta:` Conjunto de árvores. Se removermos a raiz de uma árvore, obtemos uma floresta com cada uma das subárvores da árvore original.
11. `Altura/Profundidade:` Número de arestas entre um nó e a folha mais distante. Uma árvore vazia possui altura -1. 


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
	if (a == NULL) return; // Condição de parada
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
~~~

### `Questão 2:` Escreva uma função que percorre uma árvore binária para determinar sua altura. O protótipo da função deve ser dado por: int altura(PArv a);
~~~c
~~~
