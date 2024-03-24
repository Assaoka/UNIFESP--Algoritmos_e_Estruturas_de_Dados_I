<h1 align="center"> Árvores Binárias de Busca <br>
  <a href="../[ 16 ] Árvores de Expressão/"><img src="https://img.shields.io/badge/Anterior-Árvores de Expressão-215a36" alt="Anterior"></a>
</h1>



# Definição de Árvore Binária de Busca:
&emsp;&emsp; Imagine que você tem uma lista de números e deseja encontrar um valor específico nessa lista. O método convencional seria percorrer a lista de maneira sequencial, de casa em casa, até encontrar o valor desejado. No entanto, `mesmo que a lista esteja ordenada,` esse método pode se tornar `ineficiente conforme a lista cresce.`

&emsp;&emsp; Uma alternativa seria `dividir a lista ordenada em duas partes` (uma parte com os valores menores e outra com os valores maiores) e verificar em qual das duas partes o valor desejado se encontra. Se o valor desejado for menor que o valor do meio da lista, então o valor desejado só pode estar na primeira metade da lista. Caso contrário, o valor desejado só pode estar na segunda metade da lista. `Esse método é conhecido como busca binária.`

&emsp;&emsp; Agora, imagine que seus dados estejam `armazenados de forma dinâmica.` Como poderíamos aplicar a busca binária nesse caso? `Usando uma lista, isso não seria possível,` pois não teríamos como acessar o meio de um intervalo.

&emsp;&emsp; E é aí que entram as árvores binárias. Podemos aproveitar a estrutura hierárquica das árvores para armazenar valores de forma dinâmica e sem perder a capacidade de acessar o `"meio"` de um intervalo. Para isso, podemos `colocar valores menores que a raiz na subárvore esquerda e valores maiores que a raiz na subárvore direita.` A estrutura resultante é conhecida como `Árvore Binária de Busca (ABB).`

&emsp;&emsp; Vale destacar que, `caso a árvore não esteja balanceada,` não estaremos necessariamente acessando o meio do intervalo, o que pode comprometer a eficiência da busca em relação à busca binária. No entanto, mesmo nesse caso, `ainda teremos uma busca mais eficiente do que a busca sequencial.` Esse problema pode ser resolvido com o uso de árvores balanceadas, como as `árvores AVL e as árvores rubro-negras.`

~~~c
typedef struct ArvoreBinaria {
	int chave; // Informação do nó
	struct ArvoreBinaria *esq; // Ponteiro para o no da esquerda (menor)
	struct ArvoreBinaria *dir; // Ponteiro para o no da direita (maior)
} SArv;
typedef SArv *PArv;
~~~


# Operações Básicas com Árvores Binárias de Busca:
## `1. Inserir:`
### `| Passo a passo:`
1. Se a árvore é `vazia, o novo nó é a raiz.` Caso contrário, continue.
2. Se a `chave` do novo elemento é `menor que a raiz` da subárvore, `insere na subárvore esquerda.` Caso contrário, insere na subárvore direita.
3. Caso o `local de inserção já esteja ocupado, repete` o processo a partir do passo 2.
### `| Função auxiliar para criar um novo nó:`
~~~c
PArv cria (int chave) {
	PArv novo = (PArv)malloc(sizeof(SArv)); // Aloca memória para o novo nó
	novo->esq = novo->dir = NULL; // Inicializa os ponteiros com NULL
	novo->chave = chave; // Atribui a chave ao novo nó
	return novo; // Retorna o novo nó
}
~~~
### `| Inserção na forma recursiva:`
~~~c
PArv inserir_R (PArv a, int chave) {
	if (a == NULL) return cria(chave); // Se a subárvore estiver vazia, cria o nó e retorna
	if (chave < a->chave) a->esq = inserir_R(a->esq, chave); // Se a chave for menor, o filho a esquerda do nó atual recebe a subárvore da esquerda. Se for vazia, recebe o novo nó. Caso contrário, vai receber o próprio filho a esquerda.
	else a->dir = inserir_R(a->dir, chave); // Se a chave for maior, o filho a direita do nó atual recebe a subárvore a direita. Mesmo caso anterior (só que a direita).
	return a; // Retorna o nó atual
}
~~~
### `| Inserção na forma iterativa:`
~~~c
PArv inserir_I (PArv a, int chave) {
	PArv p, ant;
	if (a == NULL) return cria(chave); // Se a árvore estiver vazia, cria o nó e retorna
	for (ant = NULL, p = a; p != NULL;) { // Percorre a árvore até encontrar um nó vazio
		ant = p; // Guarda o nó anterior
		if (chave < p->chave) p = p->esq; // Se a chave for menor, vai para a esquerda
		else p = p->dir; // Se a chave for maior, vai para a direita
	}
	if (chave < ant->chave) ant->esq = cria(chave); // Se a chave for menor, insere na esquerda
	else ant->dir = cria(chave); // Se a chave for maior, insere na direita
	return a; // Retorna a árvore
}
~~~

## `2. Remover:`
### `| Passo a passo:`
1. Encontre o nó a ser removido.
2. Se o nó a ser removido é `uma folha, basta removê-lo.` Caso contrário, continue.
3. Caso o nó a ser removido `possua apenas um filho,` basta `substituir o nó a ser removido pelo seu filho.` Caso contrário, continue.
4. Caso o nó a ser removido `possua dois filhos,` substitua o nó a ser removido pelo `maior nó da subárvore da esquerda.`
### `| Função de Remoção:`
~~~c
PArv remover (PArv a, int chave) {
	PArv ant, p;
	if (a == NULL) return NULL; // Condição de parada (não encontrou)
	if (chave < a->chave) a->esq = remover(a->esq, chave); // Se a chave for menor, procura na subárvore da esquerda
	else if (chave > a->chave) a->dir = remover(a->dir, chave); // Se a chave for maior, procura na subárvore da direita
	else { // Encontrou o nó 
		if (a->esq == NULL && a->dir == NULL) { // Nó folha
			free(a);
			return NULL;
		} else if (a->dir == NULL) { // Filho a esquerda apenas
			p = a->esq;
			free(a);
			return p;
		} else if (a->esq == NULL) { // Filho a direita apenas
			p = a->dir;
			free (a);
			return p;
		} else { // Dois filhos
			for (ant = a, p = a->esq; p->dir != NULL; ant = p, p = p->dir); // Procura o maior nó da subárvore da esquerda
			a->chave = p->chave; // Atribui a chave do maior nó ao nó atual
			if (ant == a) a->esq = p->esq; // Se o maior nó for o filho a esquerda do nó atual, o filho do filho a esquerda vai ser o filho a esquerda do nó atual
			else ant->dir = p->esq; // Caso contrário, o pai do maior nó recebe a subárvore da esquerda do maior nó
			free(p);
		}
	}
	return a; // Retorna o nó atual (Sofrendo alterações ou não)
}
~~~

## `3. Buscar:`
### `| Busca na forma recursiva:`
~~~c
PArv buscar_R (PArv a, int chave) {
	if (a == NULL || a->chave == chave) return a; // Condição de parada (não encontrou ou encontrou, respectivamente)
	if (chave < a->chave) return buscar_R(a->esq, chave); // Se a chave for menor, procura na subárvore da esquerda
	else return buscar_R(a->dir, chave); // Se a chave for maior, procura na subárvore da direita
}
~~~
### `| Busca na forma iterativa:`
~~~c
PArv buscar (PArv a, int chave) {
	PArv p;
	for (p = a; p != NULL && p->chave != chave;) // Percorre a árvore até encontrar a chave ou um nó vazio (Não encontrou)
		if (chave < p->chave) p = p->esq; // Se a chave for menor, vai para a esquerda
		else p = p->dir; // Se a chave for maior, vai para a direita
	return p;
}
~~~

## `4. Imprimir:`
&emsp;&emsp; De acordo com a definição de árvore binária de busca, todo valor na subárvore esquerda de um nó é menor que o valor do nó e todo valor na subárvore direita de um nó é maior que o valor do nó, respectivamente. Dessa forma, podemos imprimir os valores da árvore em ordem crescente ou decrescente de forma simples.
### `| Ordem crescente:`
~~~c
void imprimir_C (PArv a) {
	if (a == NULL) return; // Condição de parada
	imprimir_C(a->esq); // Imprime a subárvore da esquerda
	printf("%d ", a->chave); // Imprime a raiz
	imprimir_C(a->dir); // Imprime a subárvore da direita
}
~~~
### `| Ordem decrescente:`
~~~c
void imprimir_D (PArv a) {
	if (a == NULL) return; // Condição de parada
	imprimir_D(a->dir); // Imprime a subárvore da direita
	printf("%d ", a->chave); // Imprime a raiz
	imprimir_D(a->esq); // Imprime a subárvore da esquerda
}
~~~


# Exercícios:
## `Questão 1:` Considere uma ABB A de números inteiros contendo todos os números entre 1 e 1000. Dentre as sequências abaixo, indique qual(is) a(s) que pode(m) corresponder a uma sequência de elementos de A visitados em ordem prefixa durante a operação de pesquisa do elemento 363. Para cada uma das sequências não válidas, indique o problema.
&emsp;&emsp; Para resolver essa questão, basta lembrar que se um elemento está a esquerda da raiz, ele é menor que a raiz. Se ele está a direita da raiz, ele é maior que a raiz.

&emsp;&emsp; Utilizando essa definição é fácil checar se uma sequência é válida ou não. Basta olhar a cada operação os próximos elementos, caso o elemento atual seja menor que o procurado, devemos procurar na subárvore da direita (logo todos os elementos devem ser maiores que dois).

`I)` 2, 252, 401, 398, 330, 344, 397, 363

&emsp;&emsp;Essa sequência é valida, pois: O elemento que buscamos é maior que dois e todos os seguintes são maiores. Depois vamos para o 256 que é menor que o procurado (todos maiores). 401 é maior que o que queremos (próximos menores). 398 é maior... 

`II)` 924, 220, 911, 244, 898, 258, 362, 363 

`III)` 925, 202, 911, 240, 912, 245, 363

`IV)` 2, 399, 387, 219, 266, 382, 381, 278, 363

`V)` 935, 278, 347, 621, 299, 392, 358, 363

`Gabarito:` I - Verdadeiro, II - Verdadeiro, III - Falso (911 -> 912), IV - Verdadeiro, V - Falso (347 -> 299)


## `Questão 2:` Escreva uma função que obtenha o menor valor da árvore. O protótipo da função deve ser dado por: int menor (PArv a);
~~~c
int menor (PArv a) {
	PArv p;
	for (p = a; p->esq != NULL; p = p->esq); // Encontra o nó mais a esquerda (menor por definição)
	return p->chave; // Retorna a chave do nó
}
~~~
`Obs:` Para encontrar o maior valor, basta substituir `p->esq` por `p->dir`. Por definição o nó mais a direita é sempre o maior nó.

## `Questão 3:` Escreva uma função que imprime todos os valores dos nós da árvore que sejam menores que x, em ordem crescente. O protótipo da função deve ser dado por: void showmenor (PArv a, int x);
~~~c
void showmenor (PArv a, int x) {
	if (a == NULL) return; // Condição de parada
	showmenor(a->esq, x); // Tenta imprimir a subárvore da esquerda
	if (a->chave < x) { // Se a chave for menor que x, imprime
		printf("%d ", a->chave);
		showmenor(a->dir, x);
	}
}
~~~

## `Questão 4:` Escreva uma função que receba uma lista encadeada e construa uma ABB com os elementos desta lista. Liberar a lista e retornar a árvore gerada. 
&emsp;&emsp; Essa função foi escolhida para mostrar como poderíamos resolver o problema apresentado na introdução, pois podemos transformar uma lista (ordenada ou não) em uma ABB e dessa forma poderíamos usar a busca binária para encontrar elementos de forma eficiente. Claro que construir uma ABB vai ter um custo, mas se a lista for grande e a busca for frequente, esse custo pode ser compensado. Outra observação importante é que, caso a lista esteja ordenada e não seja um tipo de árvore balanceada, a árvore resultante vai ser árvore degenerada, ou seja, uma lista (ou seja, a busca vai ter o mesmo custo de antes).
~~~c
typedef struct No { // Lista Encadeada
	int info; // Informação do Elemento
	struct No *prox; // Ponteiro para o Próximo Elemento
} SNo;
typedef SNo *PNo;

PArv listaParaABB (PNo lista) {
	PArv a; // Árvore
	PNo p; // Ponteiro para percorrer a lista
	for (a = NULL, p = lista; lista != NULL; p = lista) { // Percorre a lista
		lista = lista->prox; // Avança na lista
		a = inserir_R(a, p->info); // Insere o elemento na árvore
		free(p); // Libera o elemento da lista
	}
	return a; // Retorna a árvore
}
~~~

## `Questão 5:` Escreva uma função para verificar se uma árvore binária é ABB. O protótipo da função deve ser dado por: int verificaABB (PArv a);
~~~c
int verificaABB (PArv a) {
	if (a == NULL) return 1; // Condição de parada
	if (a->esq != NULL && a->esq->chave > a->chave) return 0; // Se o filho a esquerda for maior que o pai, não é ABB
	if (a->dir != NULL && a->dir->chave < a->chave) return 0; // Se o filho a direita for menor que o pai, não é ABB
	return verificaABB(a->esq) && verificaABB(a->dir); // Verifica se as subárvores são ABB
}
~~~

---
