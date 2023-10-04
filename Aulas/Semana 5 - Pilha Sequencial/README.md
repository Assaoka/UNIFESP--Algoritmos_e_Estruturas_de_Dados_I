# Semana 5 (11/09/2023) - Pilha Sequencial
## Definição de Pilha: 
Último a Entrar, Primeiro a Sair ("Last In, First Out" -> LIFO)	
<br>&emsp;&emsp;1.  O Novo Elemento é Sempre Inserido no Topo da Pilha
<br>&emsp;&emsp;2. O Elemento Removido é Sempre o que Chegou a Menos Tempo na Pilha
<br>&emsp;&emsp;3. A Consulta Normalmente Retorna o Elemento no Topo da Pilha

~~~c
#define TamanhoPilha 50
typedef struct PilhaVet { 
	int topo; // Índice do Topo da Pilha (Se -1, Pilha Vazia)
	char info[TamanhoPilha];
} SPilhaVet;
typedef SPilhaVet *PPilhaVet; // Ponteiro para Pilha
~~~




## Operações Básicas Sobre Pilhas
### 1. Inicializar Pilha
~~~c
PPilhaVet inicializarPilhaVet() {
	PPilhaVet novo = (PPilhaVet) malloc (sizeof(SPilhaVet)); // Aloca Espaço para a Pilha
	novo->topo = -1; // Inicializa o Topo da Pilha como -1 (Pilha Vazia)
	return novo; // Retorna o Ponteiro para a Pilha
}
~~~

### 2. Empilhar Elemento (Push)
~~~c
int pushVet (PPilhaVet pilha, char info) {
	if (pilha->topo == TamanhoPilha - 1) return -1; // Pilha Cheia

	// se não, insere o elemento no topo da pilha
	pilha->topo += 1; // Incrementa o Topo da Pilha
	pilha->info[pilha->topo] = info; // Insere o Elemento no Topo da Pilha
	return 0; // Sucesso
}
~~~

### 3. Desempilhar Elemento (Pop)
~~~c

~~~

### 4. Consultar Elemento no Topo (Peek)
~~~c
~~~

### 5. Listar Elementos da Pilha
~~~c
~~~

