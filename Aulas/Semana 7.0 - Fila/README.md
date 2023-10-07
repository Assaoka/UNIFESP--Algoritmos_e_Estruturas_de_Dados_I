<h1 align="center"> Semana 7.0 - Fila Encadeada </h1>
 
## Definição de Fila Encadeada:
Uma Fila Encadeada é uma Estrutura de Dados que Segue o Princípio `FIFO` (First In First Out), ou seja, `O Primeiro Elemento a Entrar na Fila é o Primeiro a Sair.`
<br>&emsp;&emsp;1. O `Novo Elemento` Sempre é `Inserido no Final` (Ordem de Chegada);
<br>&emsp;&emsp;2. O `Elemento Removido` é Sempre o que `Chegou há Mais Tempo na Fila`;

<br>Cada `Elemento` é Representado por uma `Estrutura` que Contém um `Ponteiro para o Próximo Elemento` da Fila e o `Valor` do Elemento.
~~~c
typedef int tipoElemento; // Tipo de Dado que a Fila Armazena (Alterar de Acordo com o Problema)
typedef struct No {
	tipoElemento info; // Informação do Elemento
	struct No *prox; // Ponteiro para o Próximo Elemento
} SNo;
typedef SNo *PNo;
~~~

<br>Uma `Fila Encadeada` pode ser Implementada Usando `Outra Estrutura` que Contém um `Ponteiro para o Primeiro Elemento` da Fila e um `Ponteiro para o Último Elemento` da Fila.
~~~c
typedef struct Fila {
	PNo ini; // Primeiro Elemento da Fila
	PNo fim; // Último Elemento da Fila
} SFila;
typedef SFila *PFila;
~~~





## Operações Básicas com Filas Encadeadas:
### `1. Criar uma Fila Vazia:`
~~~c
PFila inicializar () { 
	PFila novo = (PFila) malloc(sizeof(SFila)); // Aloca Espaço para a Fila
	novo->ini = NULL; 
	novo->fim = NULL;
	return novo;
}
~~~

### `2. Inserir Elemento (Insere no Fim):`
~~~c
PNo insere (PFila fila, tipoElemento v) {
	if (fila == NULL) return NULL; // Fila Não Inicializada (Erro)

	PNo novo = (PNo) malloc(sizeof(SNo)); // Aloca Espaço para o Novo Elemento
	novo->info = v; // Insere a Informação no Novo Elemento
	novo->prox = NULL; // O Novo Elemento Aponta para o Antigo Topo
	
	if (fila->ini == NULL) fila->ini = novo; // Fila Vazia (Inicio aponta para o novo elemento)
	else fila->fim->prox = novo; // Fila Não Vazia (O último elemento aponta para o novo elemento)
	
	fila->fim = novo; // Atualiza o Fim da Fila
	return fila->fim; // Retorna o Novo Fim da Fila
}
~~~

### `3. Remover Elemento (Retirar do Início):`
~~~c
PNo remover (PFila fila, tipoElemento *v) {
	if (fila == NULL) return NULL; // Fila Não Inicializada (Erro)

	PNo lixo = fila->ini; // Ponteiro Auxiliar para o Elemento a Ser Removido
	if (fila->ini == NULL) return NULL; // Fila Vazia (Impossível Remover)
	
	*v = lixo->info; // Retorna a Informação do Elemento Removido
	if (fila->ini == fila->fim) fila->fim = NULL; // Fila com Apenas um Elemento (Atualiza o Fim da Fila)
	fila->ini = lixo->prox; // Atualiza o Início da Fila
	
	free(lixo); // Libera o Espaço Alocado do Elemento Removido
	return fila->ini; // Retorna o Novo Início da Fila
}
~~~

### `4. Listar Elementos da Fila:`
A Impressão dos Elementos da Fila pode ser Feita com uma Lógica Semelhante a da Impressão de uma Pilha Encadeada.
~~~c
void listar (PNo ini) {
	PNo aux; // Ponteiro Auxiliar para Percorrer a Fila
	for (aux = ini; aux != NULL; aux = aux->prox) // Percorre a Fila
		printf("%d ", aux->info); // Imprime a Informação do Elemento
	printf("\n");
}
~~~
~~~c
void listarR (PNo ini) {
	if (ini == NULL) { // Fila Vazia OU Fim da Fila
		printf("\n");
		return;
	}   
	printf("%d ", ini->info); // Imprime a Informação do Elemento
	listarR(ini->prox); // Chama a Função para o Próximo Elemento (Recursão)
}
~~~

### `5. Liberar Espaços Alocados:`
~~~c
PFila liberar (PFila fila) {
	PNo aux; // Ponteiro Auxiliar para Percorrer a Fila
	if (fila == NULL) return NULL; // Fila Não Inicializada (Erro)
	for (aux = fila->ini; aux != NULL; aux = fila->ini) { // Percorre a Fila
		fila->ini = aux->prox; // Atualiza o Início da Fila para não Perder a Referência
		free(aux); // Libera o Espaço Alocado do Elemento Removido
	}
	free(fila); // Libera o Espaço Alocado da Fila
	return NULL; // Fila Vazia
}
~~~



## Exercícios:
### `Questão 1:` Faça uma função que receba 3 filas (f, f_pares e f_impares) e separe todos os valores guardados em f de tal forma que os valores pares sejam movidos para f_pares e os impares, para f_impares. No final, f deve estar vazia. Considere que f_pares e f_impares ainda não existem.
~~~c
// João Victor Assaoka Ribeiro - rn168863
#include <stdio.h>
#include <stdlib.h>

typedef int tipoElemento; // Tipo de Dado que a Fila Armazena (Neste Caso, Inteiros)
typedef struct No {
	tipoElemento info; // Informação do Elemento
	struct No *prox; // Ponteiro para o Próximo Elemento
} SNo;
typedef SNo *PNo;

typedef struct Fila {
	PNo ini; // Primeiro Elemento da Fila
	PNo fim; // Último Elemento da Fila
} SFila;
typedef SFila *PFila;

PFila inicializar () { 
	PFila novo = (PFila) malloc(sizeof(SFila)); // Aloca Espaço para a Fila
	novo->ini = NULL; 
	novo->fim = NULL;
	return novo;
}

PNo insere (PFila fila, tipoElemento v) {
	if (fila == NULL) return NULL; // Fila Não Inicializada (Erro)

	PNo novo = (PNo) malloc(sizeof(SNo)); // Aloca Espaço para o Novo Elemento
	novo->info = v; // Insere a Informação no Novo Elemento
	novo->prox = NULL; // O Novo Elemento Aponta para o Antigo Topo
	
	if (fila->ini == NULL) fila->ini = novo; // Fila Vazia (Inicio aponta para o novo elemento)
	else fila->fim->prox = novo; // Fila Não Vazia (O último elemento aponta para o novo elemento)
	
	fila->fim = novo; // Atualiza o Fim da Fila
	return fila->fim; // Retorna o Novo Fim da Fila
}

PNo remover (PFila fila, tipoElemento *v) {
	if (fila == NULL) return NULL; // Fila Não Inicializada (Erro)

	PNo lixo = fila->ini; // Ponteiro Auxiliar para o Elemento a Ser Removido
	if (fila->ini == NULL) return NULL; // Fila Vazia (Impossível Remover)
	
	*v = lixo->info; // Retorna a Informação do Elemento Removido
	if (fila->ini == fila->fim) fila->fim = NULL; // Fila com Apenas um Elemento (Atualiza o Fim da Fila)
	fila->ini = lixo->prox; // Atualiza o Início da Fila
	
	free(lixo); // Libera o Espaço Alocado do Elemento Removido
	return fila->ini; // Retorna o Novo Início da Fila
}

void listar (PNo ini) {
	PNo aux; // Ponteiro Auxiliar para Percorrer a Fila
	for (aux = ini; aux != NULL; aux = aux->prox) // Percorre a Fila
		printf(" %d", aux->info); // Imprime a Informação do Elemento
	printf("\n");
}

PFila liberar (PFila fila) {
	if (fila == NULL) return NULL; // Fila Não Inicializada (Erro)
	PNo aux; // Ponteiro Auxiliar para Percorrer a Fila
	for (aux = fila->ini; aux != NULL; aux = fila->ini) { // Percorre a Fila
		fila->ini = aux->prox; // Atualiza o Início da Fila para não Perder a Referência
		free(aux); // Libera o Espaço Alocado do Elemento Removido
	}
	free(fila); // Libera o Espaço Alocado da Fila
	return NULL; // Fila Vazia
}

int main () {
	PFila f = inicializar(), f_pares = inicializar(), f_impares = inicializar(); // Inicializa as Filas
	int v, N, i; // v = Valor do Elemento, N = Número de Elementos, i = Contador

	// Leitura dos Elementos da Fila f:
	printf("Numero de Elementos: "), scanf(" %d", &N);
	for (i = 0; i < N; i++) {
		printf("f[%d]: ", i), scanf(" %d", &v);
		f->fim = insere(f, v);
	}

	printf("\nf:"), listar(f->ini);

	// Separação dos Elementos da Fila f: 
	while (f->ini != NULL) {
		f->ini = remover(f, &v);
		if (v % 2 == 0) f_pares->fim = insere(f_pares, v);
		else f_impares->fim = insere(f_impares, v);
	}
	printf("f_pares:"), listar(f_pares->ini);
	printf("f_impares:"), listar(f_impares->ini);

	// Liberação dos Espaços Alocados:
	f = liberar(f);
	f_pares = liberar(f_pares);
	f_impares = liberar(f_impares);
	return 0;
}
~~~
