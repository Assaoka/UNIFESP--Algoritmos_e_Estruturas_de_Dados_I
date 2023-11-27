<h1 align="center"> Semana 12 - Árvores Binárias </h1>

## Introdução a Árvores:
Sendo uma das `classes de estruturas de dados mais importantes,` as árvores são estruturas de dados que `permitem representar dados com hierarquias,` o que é muito útil para representar alguns tipos de dados como:
<br>&emsp;&emsp; 1. Um sistema de arquivos de um computador.
<br>&emsp;&emsp; 2. O organograma de uma empresa.
<br>&emsp;&emsp; 3. A divisão de um livro em capítulos, seções, tópicos...
<br>&emsp;&emsp; 4. A árvore genealógica de uma pessoa.

`Formalmente,` uma árvore é um conjunto `finito` de nós, onde:
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
&emsp;&emsp; Dentro da variedade de árvores, as árvores binárias são as mais usadas. Elas são um tipo especial onde `cada nó pode ter no máximo dois filhos.`
<br>&emsp;&emsp; As subárvores de uma árvore binária são chamadas de `subárvore esquerda` e `subárvore direita.` A ordem entre os filhos é importante, `um filho à esquerda é diferente de um filho à direita.` Se trocarmos a ordem dos filhos de um nó obtemos outra árvore.

~~~c
typedef int tipoElemento; // Tipo de dado que o nó armazena (alterar de acordo com o problema)
typedef struct ArvoreBinaria {
	tipoElemento info; // Informação do nó
	struct ArvoreBinaria *esq; // Ponteiro para o no da esquerda
	struct ArvoreBinaria *dir; // Ponteiro para o no da direita
} SArv;
typedef SArv *PArv;
~~~


Continua...
