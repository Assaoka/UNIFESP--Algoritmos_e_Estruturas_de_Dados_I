<h1 align="center"> Semana 5 - Pilha Sequencial </h1>
 
## Definição de Pilha Sequencial: 
`Último a Entrar, Primeiro a Sair` ("Last In, First Out" -> `LIFO`)	
<br>&emsp;&emsp;1.  O `Novo Elemento` é Sempre Inserido no `Topo da Pilha`
<br>&emsp;&emsp;2. O `Elemento Removido` é Sempre o que `Chegou a Menos Tempo na Pilha`
<br>&emsp;&emsp;3. A `Consulta` Normalmente Retorna o Elemento no `Topo da Pilha`

~~~c
#define TamanhoPilha 50
typedef struct PilhaVet { 
	int topo; // Índice do Topo da Pilha (Se -1, Pilha Vazia)
	char info[TamanhoPilha];
} SPilhaVet;
typedef SPilhaVet *PPilhaVet; // Ponteiro para Pilha
~~~



## Operações Básicas com Pilhas Sequências:
### `1. Inicializar Pilha:`
~~~c
PPilhaVet inicializarPilhaVet() {
	PPilhaVet novo = (PPilhaVet) malloc (sizeof(SPilhaVet)); // Aloca Espaço para a Pilha
	novo->topo = -1; // Inicializa o Topo da Pilha como -1 (Pilha Vazia)
	return novo; // Retorna o Ponteiro para a Pilha
}
~~~

### `2. Empilhar Elemento:` Push
~~~c
int pushVet (PPilhaVet pilha, char info) {
	if (pilha->topo == TamanhoPilha - 1) return -1; // Pilha Cheia

	// se não, insere o elemento no topo da pilha
	pilha->topo += 1; // Incrementa o Topo da Pilha
	pilha->info[pilha->topo] = info; // Insere o Elemento no Topo da Pilha
	return 0; // Sucesso
}
~~~

### `3. Desempilhar Elemento:` Pop
~~~c
int popVet(PPilhaVet pilha, char *info) {
	if (pilha->topo == -1) return -1; // Pilha Vazia

	// se não, remove o elemento do topo da pilha
	*info = pilha->info[pilha->topo]; // Retorna o Elemento do Topo da Pilha
	pilha->topo -= 1; // Decrementa o Topo da Pilha
	return 0; // Sucesso
}
~~~

### `4. Consultar Elemento no Topo:` Peek
~~~c
int peekVet (PPilhaVet pilha, char *info) {
	if (pilha->topo == -1) return -1; // Pilha Vazia

	// se não, retorna o elemento do topo da pilha
	*info = pilha->info[pilha->topo]; // Retorna o Elemento do Topo da Pilha (Sem Remover)
	return 0; // Sucesso
}
~~~

### `5. Listar Elementos da Pilha:`
~~~c
void listar (PPilhaVet pilha) {
	int i;
	for (i = 0; i <= pilha->topo; i++) {
		printf("%c\n", pilha->info[i]);
	}
}
~~~




## Exercícios:
### `Questão 1:` Faça um Programa que Use uma Pilha para Inverter a Ordem das Letras de Uma Frase.
~~~c
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
~~~
