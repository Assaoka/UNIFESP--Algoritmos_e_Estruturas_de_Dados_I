#include <stdio.h>
#include <stdlib.h>

// ############################## Estrutura ###############################
typedef struct ArvoreBinaria {
	int chave; // Informação do nó
	struct ArvoreBinaria *esq; // Ponteiro para o no da esquerda (menor)
	struct ArvoreBinaria *dir; // Ponteiro para o no da direita (maior)
} SArv;
typedef SArv *PArv;

// ############################## Funções #################################
// ############################## 1. Inserir ##############################
PArv cria (int chave) {
	PArv novo = (PArv)malloc(sizeof(SArv)); // Aloca memória para o novo nó
	novo->esq = novo->dir = NULL; // Inicializa os ponteiros com NULL
	novo->chave = chave; // Atribui a chave ao novo nó
	return novo; // Retorna o novo nó
}

PArv inserir_I (PArv a, int chave) {
	PArv p, ant; // Ponteiros para percorrer a árvore
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

PArv inserir_R (PArv a, int chave) {
	if (a == NULL) return cria(chave); // Se a subárvore estiver vazia, cria o nó e retorna
	if (chave < a->chave) a->esq = inserir_R(a->esq, chave); // Se a chave for menor, o filho a esquerda do nó atual recebe a subárvore da esquerda. Se for vazia, recebe o novo nó. Caso contrário, vai receber o próprio filho a esquerda.
	else a->dir = inserir_R(a->dir, chave); // Se a chave for maior, o filho a direita do nó atual recebe a subárvore a direita. Mesmo caso anterior (só que a direita).
	return a; // Retorna o nó atual
}

// ########################################################################
// ############################## 2. Remover ##############################
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

// ########################################################################
// ############################## 3. Buscar ###############################
PArv buscar_R (PArv a, int chave) {
	if (a == NULL || a->chave == chave) return a; // Condição de parada (não encontrou ou encontrou, respectivamente)
	if (chave < a->chave) return buscar_R(a->esq, chave); // Se a chave for menor, procura na subárvore da esquerda
	else return buscar_R(a->dir, chave); // Se a chave for maior, procura na subárvore da direita
}


PArv buscar_I (PArv a, int chave) {
	PArv p;
	for (p = a; p != NULL && p->chave != chave;) // Percorre a árvore até encontrar a chave ou um nó vazio (Não encontrou)
		if (chave < p->chave) p = p->esq; // Se a chave for menor, vai para a esquerda
		else p = p->dir; // Se a chave for maior, vai para a direita
	return p;
}

// ########################################################################
// ############################## 4. Imprimir #############################
void imprimir_C (PArv a) {
	if (a == NULL) return; // Condição de parada
	imprimir_C(a->esq); // Imprime a subárvore da esquerda
	printf("%d ", a->chave); // Imprime a raiz
	imprimir_C(a->dir); // Imprime a subárvore da direita
}

void imprimir_D (PArv a) {
	if (a == NULL) return; // Condição de parada
	imprimir_D(a->dir); // Imprime a subárvore da direita
	printf("%d ", a->chave); // Imprime a raiz
	imprimir_D(a->esq); // Imprime a subárvore da esquerda
}


// ########################################################################
// Questão 2: Escreva uma função que obtenha o menor valor da árvore. 
int menor (PArv a) {
	PArv p;
	for (p = a; p->esq != NULL; p = p->esq); // Encontra o nó mais a esquerda (menor por definição)
	return p->chave; // Retorna a chave do nó
}

// ########################################################################
// Questão 3: Escreva uma função que imprime todos os valores dos nós da árvore que sejam menores que x, em ordem crescente.
void showmenor (PArv a, int x) {
	if (a == NULL) return; // Condição de parada
	showmenor(a->esq, x); // Tenta imprimir a subárvore da esquerda
	if (a->chave < x) { // Se a chave for menor que x, imprime
		printf("%d ", a->chave);
		showmenor(a->dir, x);
	}
}

// ########################################################################
// Questão 4: Escreva uma função que receba uma lista encadeada e construa uma ABB com os elementos desta lista. Liberar a lista e retornar a árvore gerada.
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

// ########################################################################
// Questão 5: Escreva uma função para verificar se uma árvore binária é ABB.
int verificaABB (PArv a) {
	if (a == NULL) return 1; // Condição de parada
	if (a->esq != NULL && a->esq->chave > a->chave) return 0; // Se o filho a esquerda for maior que o pai, não é ABB
	if (a->dir != NULL && a->dir->chave < a->chave) return 0; // Se o filho a direita for menor que o pai, não é ABB
	return verificaABB(a->esq) && verificaABB(a->dir); // Verifica se as subárvores são ABB
}

// Provisório (para testar as funções)
void imprimirP (PArv a, int i) {
	if (a == NULL) return; // Condição de parada
	for (int j = 0; j < i; j++) printf("\t"); // Imprime os tabs de acordo com o nível do nó atual (paragrafação)
	printf("%d\n", a->chave); // Imprime a chave do nó atual
	imprimirP(a->esq, i + 1); // Imprime a subárvore da esquerda
	imprimirP(a->dir, i + 1); // Imprime a subárvore da direita
}

PArv liberar (PArv a) {
	if (a == NULL) return NULL; // Condição de parada
	liberar(a->esq); // Libera a subárvore da esquerda
	liberar(a->dir); // Libera a subárvore da direita
	free(a); // Libera o nó atual
	return NULL; // Retorna NULL
}

int main () {
	PArv a = NULL;
	a = inserir_R(a, 90);
	a = inserir_R(a, 30);
	a = inserir_R(a, 100);
	a = inserir_R(a, 150);
	a = inserir_R(a, 20);
	a = inserir_R(a, 10);
	a = inserir_R(a, 15);
	a = inserir_R(a, 50);
	a = inserir_R(a, 40);
	a = inserir_R(a, 70);
	a = inserir_R(a, 60);
	a = inserir_R(a, 80);
	a = inserir_R(a, 65);
	
	showmenor(a, 500);
	printf("\n");
	showmenor(a, 50);
	a = liberar(a);
	return 0;
}
