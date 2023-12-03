<h1 align="center"> Semana 10 - Matrizes Esparsas </h1>

## Introdução:
&emsp;&emsp; Matrizes esparsas são matrizes que possuem a maioria de seus elementos iguais a zero. Para economizar espaço, é possível armazenar apenas os elementos diferentes de zero e suas respectivas posições.

&emsp;&emsp; Existem diversas formas de se implementar uma matriz esparsa, vamos utilizar um vetor de listas encadeadas para armazenar os elementos diferentes de zero e suas posições.
~~~c
#define MAX_LINHA 10
typedef struct no {
    int valor, coluna; // valor e coluna do elemento
    struct no *prox; // ponteiro para o próximo elemento da linha
} SNo;
typedef SNo *PNo; // ponteiro para SNo
typedef PNo PME[MAX_LINHA]; // Vetor de ponteiros para guardar o endereço do primeiro nó de cada linha
~~~

## Operações Básicas com Matrizes Esparsas:
### `Inicialização:`
~~~c
void inicializa(PME matriz) {
    int i;
    for (i = 0; i < MAX_LINHA; i++) matriz[i] = NULL;
}
~~~

### `Inserção:`

### `Remoção:`

### `Busca:`

### `Impressão:`





## Exercícios:
### `Questão 1:`