<h1 align="center"> Semana 6 (17/09/2023) - Pilha Encadeada </h1>
 
## Definição de Pilha: 
`Último a Entrar, Primeiro a Sair` ("Last In, First Out" -> `LIFO`)	
<br>&emsp;&emsp;1.  O `Novo Elemento` é Sempre Inserido no `Topo da Pilha`
<br>&emsp;&emsp;2. O `Elemento Removido` é Sempre o que `Chegou a Menos Tempo na Pilha`

~~~c
typedef struct Pilha {
    int info; // Informação do Elemento
    struct Pilha *prox; // Ponteiro para o Próximo Elemento
} SPilha;
typedef SPilha *PPilha;
~~~




## Operações Básicas Sobre Pilhas:
### `1. Empilhar Elemento:` Push
~~~c
PPilha push (PPilha topo, int v) {
    PPilha novo = (PPilha)malloc(sizeof(SPilha)); // Aloca Espaço para o Novo Elemento
    novo->info = v; // Insere a Informação no Novo Elemento
    novo->prox = topo; // O Novo Elemento Aponta para o Antigo Topo
    return novo; // Retorna o Novo Topo da Pilha
}
~~~

### `2. Desempilhar Elemento:` Pop
~~~c
~~~


### `3. Listar Elementos da Pilha:`
~~~c
~~~


### `4. Liberar Espaços Alocados:`
~~~c
~~~



## Exercícios:
### `Questão 1:` ???
~~~c
~~~
