<h1 align="center"> Semana 14 - Árvores Binárias de Busca </h1>

Esse resumo ainda está em produção. Caso encontre algum erro, por favor, entre em contato para que eu possa corrigir.

## Introdução:
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


## Operações Básicas com Árvores Binárias:
### `1. Inserir:`
~~~c
~~~

### `2. Remover:`
~~~c
~~~

### `3. Buscar:`
~~~c
~~~

~~~c
~~~

### `4. Liberar:`
~~~c
~~~


## Exercícios:
### `Questão 1:` Considere uma ABB A de números inteiros contendo todos os números entre 1 e 1000. Dentre as sequências abaixo, indique qual(is) a(s) que pode(m) corresponder a uma sequência de elementos de A visitados em ordem prefixa durante a operação de pesquisa do elemento 363. Para cada uma das sequências não válidas, indique o problema.
`I)` 2, 252, 401, 398, 330, 344, 397, 363

`II)` 924, 220, 911, 244, 898, 258, 362, 363

`III)` 925, 202, 911, 240, 912, 245, 363

`IV)` 2, 399, 387, 219, 266, 382, 381, 278, 363

`V)` 935, 278, 347, 621, 299, 392, 358, 363

### `Questão 2:` Escreva uma função que obtenha o menor valor da árvore. O protótipo da função deve ser dado por: int menor (PArv a);
~~~c
~~~

### `Questão 3:` Escreva uma função que imprime todos os valores dos nós da árvore que sejam menores que x, em ordem crescente. O protótipo da função deve ser dado por: void showmenor (PArv a, int x);
~~~c
~~~

### `Questão 4:` Escreva uma função que receba uma lista encadeada e construa uma ABB com os elementos desta lista. Liberar a lista e retornar a árvore gerada. 
~~~c
~~~

### `Questão 5:` Escreva uma função para verificar se uma árvore binária é ABB. O protótipo da função deve ser dado por: int verificaABB (PArv a);
~~~c
~~~
