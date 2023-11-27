#include <stdio.h>
#include <stdlib.h>

#define TamanhoPilha 50
typedef struct PilhaVet { 
	int topo; // Índice do Topo da Pilha (Se -1, Pilha Vazia)
	char info[TamanhoPilha];
} SPilhaVet;
typedef SPilhaVet *PPilhaVet; // Ponteiro para Pilha

PPilhaVet inicializarPilhaVet() {
	PPilhaVet novo = (PPilhaVet) malloc (sizeof(SPilhaVet)); // Aloca Espaço para a Pilha
	novo->topo = -1; // Inicializa o Topo da Pilha como -1 (Pilha Vazia)
	return novo; // Retorna o Ponteiro para a Pilha
}

int pushVet (PPilhaVet pilha, char info) {
	if (pilha->topo == TamanhoPilha - 1) return -1; // Pilha Cheia

	// se não, insere o elemento no topo da pilha
	pilha->topo += 1; // Incrementa o Topo da Pilha
	pilha->info[pilha->topo] = info; // Insere o Elemento no Topo da Pilha
	return 0; // Sucesso
}

int popVet(PPilhaVet pilha, char *info) {
	if (pilha->topo == -1) return -1; // Pilha Vazia

	// se não, remove o elemento do topo da pilha
	*info = pilha->info[pilha->topo]; // Retorna o Elemento do Topo da Pilha
	pilha->topo -= 1; // Decrementa o Topo da Pilha
	return 0; // Sucesso
}

int peekVet (PPilhaVet pilha, char *info) {
	if (pilha->topo == -1) return -1; // Pilha Vazia

	// se não, retorna o elemento do topo da pilha
	*info = pilha->info[pilha->topo]; // Retorna o Elemento do Topo da Pilha (Sem Remover)
	return 0; // Sucesso
}

void listar (PPilhaVet pilha) {
	int i;
	for (i = 0; i <= pilha->topo; i++) {
		printf("%c\n", pilha->info[i]);
	}
}

void inverter () {
	PPilhaVet pilha = inicializarPilhaVet(); // Inicializa a Pilha
	char txt[TamanhoPilha], letra;
	int i;

	scanf("%[^\n]", txt); // Lê a Frase
	for (i = 0; txt[i] != '\0'; i++) pushVet(pilha, txt[i]); // Empilha as Letras da Frase
	while (pilha->topo != -1) {
		popVet(pilha, &letra); // Desempilha as Letras da Frase
		printf("%c", letra);
	}

	free(pilha); // Libera a Memória Alocada para a Pilha
}

int main () {
	inverter();
	return 0;
}
