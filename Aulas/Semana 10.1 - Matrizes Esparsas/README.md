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
### `1. Inicialização:`
~~~c
void inicializa(PME matriz) {
	int i;
	for (i = 0; i < MAX_LINHA; i++) matriz[i] = NULL; // inicializa todas as linhas com NULL (vazias)
}
~~~

### `2. Inserção:`
~~~c
PNo criarNo (int valor, int coluna, PNo prox) { // Aloca um novo nó com os valores passados e retorna o endereço
	PNo novo = (PNo)malloc(sizeof(SNo));
	novo->valor = valor;
	novo->coluna = coluna;
	novo->prox = prox;
	return novo;
}
~~~
~~~c
void inserir (PME matriz, int valor, int linha, int coluna) {
	PNo ant, p;
	if (valor == 0 || linha >= MAX_LINHA) return; // Se o valor a ser inserido é zero ou a linha é inválida, não faz nada
	for (ant = NULL, p = matriz[linha]; p != NULL && p->coluna < coluna; ant = p, p = p->prox); // percorre a linha até encontrar a posição correta
	if (p != NULL && p->coluna == coluna) p->valor = valor; // Se já existe um elemento na posição, atualiza o valor
	else if (ant == NULL) matriz[linha] = criarNo(valor, coluna, p); // Inserir no início da linha
	else ant->prox = criarNo(valor, coluna, p); // Inserir no meio ou no final da linha
}
~~~

### `3. Remoção:`
&emsp;&emsp; Uma coisa importante a se notar é que remover um elemento de uma matriz esparsa significa zerar o valor da posição na matriz esparsa, pois se um elemento não está na lista, ele é considerado zero.
~~~c
void remover (PME matriz, int linha, int coluna) {
	PNo ant, p;
	if (linha >= MAX_LINHA) return; // Se a linha é inválida, não faz nada
	for (ant = NULL, p = matriz[linha]; p != NULL && p->coluna < coluna; ant = p, p = p->prox); // percorre a linha até encontrar a posição correta
	if (p != NULL && p->coluna == coluna) { // Se existe um elemento na posição
		if (ant == NULL) matriz[linha] = p->prox; // Se é o primeiro elemento da linha
		else ant->prox = p->prox; // Se é um elemento do meio ou do final da linha
		free(p); // Libera o nó
	}
}
~~~

### `4. Busca:`
&emsp;&emsp; Essa operação é bem simples e permite acessar o valor de uma posição da matriz esparsa como se fosse uma matriz normal. Essa operação não é eficiente para fazer operações que utilizam diversos elementos próximos da matriz, como multiplicação de matrizes ou uma simples impressão da matriz, pois é necessário percorrer a lista até encontrar o elemento desejado toda vez que for acessar um elemento da matriz.
~~~c
int buscar (PME matriz, int linha, int coluna) {
	PNo p;
	if (linha >= MAX_LINHA) return 0; // Se a linha é inválida, retorna 0. O ideal seria retornar um valor que não pode ser um elemento da matriz
	for (p = matriz[linha]; p != NULL && p->coluna < coluna; p = p->prox); // percorre a linha até encontrar a posição correta
	if (p != NULL && p->coluna == coluna) return p->valor; // Se existe um elemento na posição, retorna o valor
	return 0; // Se não existe um elemento na posição, retorna 0
}
~~~

### `5. Impressão:`
~~~c
void imprimir (PME matriz, int colunas) {
	PNo p;
	int i, j;
	for (i = 0; i < MAX_LINHA; i++) {
		for (j = 0, p = matriz[i]; j < colunas; j++) {
			if (p != NULL && p->coluna == j) { // Se existe um elemento na posição
				printf("%d\t", p->valor); // Imprime o valor
				p = p->prox; // Avança para o próximo elemento da linha
			} else printf("0\t"); // Se não existe um elemento na posição, imprime 0
		}
		printf("\n");
	}
}
~~~

### `6. Liberar:`
~~~c
void liberar (PME matriz) {
	PNo p;
	int i;
	for (i = 0; i < MAX_LINHA; i++) {
		for (p = matriz[i]; matriz[i] != NULL; p = matriz[i]) { // Percorre a linha liberando os nós
			matriz[i] = p->prox;
			free(p);
		}
	}
}
~~~



## Exercícios:
### `Questão 1:` Crie uma função que encontra o maior valor em uma matriz esparsa e substituí a primeira ocorrência desse valor por 0.
&emsp;&emsp; Essa questão possui uma pegadinha, pois substituir um elemento por 0 significa remover o elemento da matriz esparsa.

### `Questão 2:` Faça uma função que receba como parâmetros duas matrizes esparsas e retorne uma matriz esparsa que seja a soma das duas matrizes recebidas. Considere que as matrizes recebidas possuem o mesmo número de linhas e colunas.
&emsp;&emsp; Essa questão possui a mesma pegadinha da questão 1, pois a soma de duas matrizes esparsas pode resultar em um elemento igual a zero, ou seja, um elemento que não deve ser inserido na matriz esparsa resposta.
~~~c
void somaMatrizes (PME matriz1, PME matriz2, PME resposta) {
	int i, j, valor; 
	PNo p, q, ant;
	for (i = 0; i < MAX_LINHA; i++) {
		for (ant = NULL, p = matriz1[i], q = matriz2[i], j = 0; j < MAX_LINHA; j++) { // Percorre as duas linhas ao mesmo tempo
			valor = 0;
			if (p != NULL && p->coluna == j) { // Se existe um elemento na posição na primeira matriz, soma e avança
				valor += p->valor;
				p = p->prox;
			} if (q != NULL && q->coluna == j) { // Se existe um elemento na posição na segunda matriz, soma e avança
				valor += q->valor;
				q = q->prox;
			} if (valor != 0) { // Se o resultado da soma é diferente de zero, insere na matriz resposta
				if (ant == NULL) resposta[i] = ant = criarNo(valor, j, NULL); // Se é o primeiro elemento da linha
				else { // Caso contrário
					ant->prox = criarNo(valor, j, NULL); // Insere no final da linha
					ant = ant->prox; // Atualiza o ponteiro para o último elemento da linha
				}
			}
		}
	}
}
~~~