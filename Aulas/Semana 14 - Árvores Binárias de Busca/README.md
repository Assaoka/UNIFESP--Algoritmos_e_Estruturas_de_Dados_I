<h1 align="center"> Semana 14 - Árvores Binárias de Busca </h1>

Esse resumo ainda está em produção. Caso encontre algum erro, por favor, entre em contato para que eu possa corrigir.

## Introdução:
&emsp;&emsp; Imagine que você tem uma `lista de números e deseja encontrar um valor específico nessa lista.` O método convencional seria percorrer a lista de maneira sequencial, de casa em casa, até encontrar o valor desejado. No entanto, `mesmo que a lista esteja ordenada,` esse método pode se tornar `ineficiente conforme a lista cresce.`
&emsp;&emsp; Uma alternativa seria `dividir a lista ordenada em duas partes (uma parte com os valores menores e outra com os valores maiores) e verificar em qual das duas partes o valor desejado se encontra.` Se o valor desejado for menor que o valor do meio da lista, então o valor desejado só pode estar na primeira metade da lista. Caso contrário, o valor desejado só pode estar na segunda metade da lista. `Esse método é conhecido como busca binária.`
&emsp;&emsp;


&emsp;&emsp; Estrutura:
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
### `Questão 1:` ...
~~~c
~~~

### `Questão 2:` ...
~~~c
~~~
