<h1 align="center"> Árvores Genéricas </h1>

EM DESENVOLVIMENTO...

&emsp;&emsp; Árvores genéricas são árvores que possuem um número variável de filhos por nó. A árvore genérica é uma generalização da árvore binária, onde cada nó pode ter um número arbitrário de filhos. A árvore genérica é uma estrutura de dados que é usada para representar hierarquias mais complexas, como a estrutura de um arquivo em um sistema operacional ou a árvore genealógica de uma família.

&emsp;&emsp; Não confunda o genérica de Árvores e a genérica de Listas. A genérica de Listas é uma lista que pode conter qualquer tipo de dado, enquanto a genérica de Árvores é uma árvore que pode ter qualquer número de filhos por nó.

&emsp;&emsp; Essa estrutura de dados utiliza uma `lista de filhos` e uma `lista de irmãos`. O primeiro é um ponteiro para o primeiro filho do nó, para acessar os outros filhos percorremos a lista de irmãos. Podemos definir uma árvore genérica da seguinte forma:
~~~c
typedef int tipoElemento; // Tipo de Dado que o Nó Armazena (Alterar de Acordo com o Problema)
typedef struct ArvoreGenerica {
    tipoElemento info;
    struct ArvoreGen *prim; // Ponteiro para o primeiro filho (Esquerda)
    struct ArvoreGen *prox; // Ponteiro para o próximo irmão (Direita)
} SArv;
typedef SArv *PArv;
~~~

# Representação:
&emsp;&emsp; Note que mesmo possuindo um número variável de filhos, a árvore genérica possui apenas dois ponteiros. Dessa forma, podemos representar graficamente a árvore genérica de duas formas:

## `1. Árvore Genérica:`
&emsp;&emsp; Essa forma é mais fácil de entender, pois representa o que queremos realmente. Nele, o pai se liga para todos os seus filhos (se repetindo para cada filho).

~~~mermaid
graph TD;
    s(Setores); 
        s-->A(Informática);
            A-->a1(Suporte);
            A-->a2(Desenvolvimento);
        s-->B(Recursos Humanos);
        s-->C(Financeiro);
            C-->c1(Contas a Pagar);
            C-->c2(Contas a Receber);
        s-->D(Comercial);
            D-->d1(Mercado Nacional);
            D-->d2(Mercado Internacional);
~~~

## `2. Árvore Binária:`
&emsp;&emsp; Essa forma é mais fácil de implementar, pois é como armazenamos a árvore genérica. Nela, o pai se liga para o primeiro filho e o primeiro filho se liga para o próximo irmão.
~~~mermaid
graph TD;
    s(Setores);
        s-- Filho -->A(Informática);
            A-- Filho -->a1(Suporte);
            a1-- Filho -->i1((Fim));
            a1-- Irmão -->a2(Desenvolvimento);
                a2-- Filho -->i2((Fim));
                a2-- Irmão -->i3((Fim));

            A-- Irmão -->B(Recursos Humanos);
                B-- Filho -->i4((Fim));
                B-- Irmão -->C(Financeiro);
                    C-- Filho -->c1(Contas a Pagar);
                        c1-- Irmão -->i5((Fim));
                        c1-- Irmão -->c2(Contas a Receber);
                            c2-- Filho -->i6((Fim));
                            c2-- Irmão -->i7((Fim));
                    C-- Irmão -->D(Comercial);
                        D-- Filho -->d1(Mercado Nacional);
                            d1-- Filho -->i8((Fim));
                            d1-- Irmão -->d2(Mercado Internacional);
                                d2-- Filho -->i9((Fim));
                                d2-- Irmão -->i10((Fim));
                        D-- Irmão -->i11((Fim));
~~~



# Operações Básicas:
&emsp;&emsp; Vamos implementar apenas a criação de um nó, a adição de um filho, a impressão da árvore genérica e a liberação da memória. A remoção de um filho é uma operação que depende do problema, por isso não será implementada.
## `1. Criar Nó:`
~~~c
PArv cria (tipoElemento x, PArv prim, PArv prox) {
    PArv p = (PArv) malloc(sizeof(SArv)); // Alocando Memória
    p->info = x; // Atribuindo o Valor
    p->prim = prim; // Atribuindo o Primeiro Filho
    p->prox = prox; // Atribuindo o Próximo Irmão
    return p; // Retornando o Nó
}
~~~

## `2. Adicionar Filho:`
~~~c
void adicionaFilho (PArv pai, tipoElemento x) {
    PArv novo = cria(x, NULL, pai->prim); // Criando o Novo Nó
    pai->prim = novo; // Adicionando o Novo Nó
}
~~~

## `3. Imprimir:`
~~~c
void imprime (PArv a) {
    if (a == NULL) return; // Condição de Parada
    printf("%d\n", a->info); // Imprimindo o Nó
    imprime(a->prim); // Imprimindo os Filhos
    imprime(a->prox); // Imprimindo os Irmãos
}
~~~

&emsp;&emsp; Caso queira imprimir a árvore de forma hierárquica, podemos adicionar um parâmetro `nivel` que indica a profundidade do nó. Dessa forma, podemos adicionar espaços para indicar a hierarquia.
~~~c
void imprime (PArv a, int nivel) {
    if (a == NULL) return; // Condição de Parada
    for (int i = 0; i < nivel; i++) printf("  "); // Adicionando Hierarquia
    printf("%d\n", a->info); // Imprimindo o Nó
    imprime(a->prim, nivel + 1); // Imprimindo os Filhos
    imprime(a->prox, nivel); // Imprimindo os Irmãos
}
~~~

## `4. Liberação de Memória:`
~~~c
PArv libera (PArv a) {
    if (a == NULL) return; // Condição de Parada
    a->prim = libera(a->prim); // Liberando os Filhos
    a->prox = libera(a->prox); // Liberando os Irmãos
    free(a); // Liberando o Nó
    return NULL; // Retornando NULL
}
~~~



# Exercícios:
 