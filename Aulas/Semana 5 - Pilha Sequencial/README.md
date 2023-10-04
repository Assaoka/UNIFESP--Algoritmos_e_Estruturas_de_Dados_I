# Semana 5 (11/09/2023) - Pilha Sequencial
## Definição de Pilha: 
Último a Entrar, Primeiro a Sair ("Last In, First Out" -> LIFO)	
<br>&emsp;&emsp;1.  O Novo Elemento é Sempre Inserido no Topo da Pilha
<br>&emsp;&emsp;2. O Elemento Removido é Sempre o que Chegou a Menos Tempo na Pilha
<br>&emsp;&emsp;3. A Consulta Normalmente Retorna o Elemento no Topo da Pilha

	#define TamanhoPilha 50 // Tamanho Máximo da Pilha
	typedef struct PilhaVet { 
    	int topo; // Índice do Topo da Pilha (Se -1, Pilha Vazia)
    	char info[TamanhoPilha];
    } SPilhaVet;
    typedef SPilhaVet *PPilhaVet; // Ponteiro para Pilha



## Operações Básicas Sobre Pilhas
### 1. Inicializar Pilha
	PPilhaVet inicializarPilhaVet() {
		PPilhaVet novo = (PPilhaVet) malloc (sizeof(SPilhaVet)); // Aloca Espaço para a Pilha
		novo->topo = -1; // Inicializa o Topo da Pilha como -1 (Pilha Vazia)
		return novo; // Retorna o Ponteiro para a Pilha
	}

### 2. Empilhar Elemento (Push)

### 3. Desempilhar Elemento (Pop)

### 4. Consultar Elemento no Topo (Peek)

### 5. Listar Elementos da Pilha
