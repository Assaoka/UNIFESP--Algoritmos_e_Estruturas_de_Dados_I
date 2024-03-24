<h1 align="center"> Árvores Genéricas <br>
  <a href="../[ 14 ] Introdução a Árvores Binárias/"><img src="https://img.shields.io/badge/Anterior-Introdução a Árvores Binárias-215a36" alt="Anterior"></a>
  <a href="../[ 16 ] Árvores de Expressão/"><img src="https://img.shields.io/badge/Próximo-Árvores de Expressão-215a36" alt="Próximo"></a>
</h1>

# Definição de Árvore Genérica:
&emsp;&emsp; Árvores genéricas são árvores que possuem um número variável de filhos por nó. A árvore genérica é uma generalização da árvore binária, onde cada nó pode ter um número arbitrário de filhos. A árvore genérica é uma estrutura de dados que é usada para representar hierarquias mais complexas, como a estrutura de um diretório de arquivos.


&emsp;&emsp; Não confunda a generalização em árvores com a generalização em listas. A generalização em listas refere-se a uma lista que pode conter qualquer tipo de dado, enquanto a generalização em árvores diz respeito a uma árvore que pode ter qualquer número de filhos por nó.

&emsp;&emsp; Essa estrutura de dados utiliza uma `lista de filhos` e uma `lista de irmãos`. O primeiro é um ponteiro para o primeiro filho do nó, para acessar os outros filhos percorremos a lista de irmãos do primeiro filho. Podemos definir uma árvore genérica da seguinte forma:
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
&emsp;&emsp; Essa forma é mais fácil de entender, pois representa o que queremos realmente. Nele, o pai se liga para todos os seus filhos (essa regra é recursiva, se repetindo para cada filho).

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
&emsp;&emsp; Essa forma é mais fácil de implementar, pois é assim que nossa estrutura de dados guarda a árvore. Nessa representação, o pai se liga para o primeiro filho e cada filho se liga para o próximo irmão. Observação: As bolinhas vazias tem valor NULL.

~~~mermaid
graph TD;
    s(Setores);
        s-- Filho -->A(Informática);
            A-- Filho -->a1(Suporte);
            a1-- Filho -->i1(( ));
            a1-- Irmão -->a2(Desenvolvimento);
                a2-- Filho -->i2(( ));
                a2-- Irmão -->i3(( ));

            A-- Irmão -->B(Recursos Humanos);
                B-- Filho -->i4(( ));
                B-- Irmão -->C(Financeiro);
                    C-- Filho -->c1(Contas a Pagar);
                        c1-- Irmão -->i5(( ));
                        c1-- Irmão -->c2(Contas a Receber);
                            c2-- Filho -->i6(( ));
                            c2-- Irmão -->i7(( ));
                    C-- Irmão -->D(Comercial);
                        D-- Filho -->d1(Mercado Nacional);
                            d1-- Filho -->i8(( ));
                            d1-- Irmão -->d2(Mercado Internacional);
                                d2-- Filho -->i9(( ));
                                d2-- Irmão -->i10(( ));
                        D-- Irmão -->i11(( ));
    s-- Irmão -->i12(( ));
~~~

## `3. Floresta:`
&emsp;&emsp; Uma floresta é um conjunto de árvores. Observe então que se a raiz de uma árvore genérica possui irmãos, então temos uma floresta. Vamos supos que temos as seguintes árvores genéricas separadas:
~~~mermaid
graph TD;
    A(A)-->B(B);
    A-->C(C);
    A-->D(D);

    E(E)-->F(F);

    G(G)-->H(H);
    G-->I(I);
~~~

&emsp;&emsp; Transformando cada árvore em uma árvore binária, temos:
~~~mermaid
graph TD;
    A(A) -- Filho --> B(B);
        B -- Filho --> i2(( ));
        B -- Irmão --> C(C);
            C -- Filho --> i3(( ));
            C -- Irmão --> D(D);
                D -- Filho --> i4(( ));
                D -- Irmão --> i5(( ));
    A -- Irmão --> i1(( ));

    E(E) -- Filho --> F(F);
    E -- Irmão --> i6(( ));

    G(G) -- Filho --> H(H);
        H -- Filho --> i8(( ));
        H -- Irmão --> I(I);
            I -- Filho --> i9(( ));
            I -- Irmão --> i10(( ));
    G -- Irmão --> i7(( ));
~~~

&emsp;&emsp; Por fim, podemos combinar todas as árvores em uma floresta (colocando A, E e G como irmãos):
~~~mermaid
graph TD;
    A(A) -- Filho --> B(B);
        B -- Filho --> i2(( ));
        B -- Irmão --> C(C);
            C -- Filho --> i3(( ));
            C -- Irmão --> D(D);
                D -- Filho --> i4(( ));
                D -- Irmão --> i5(( ));
    A -- Irmão --> E(E);
        E -- Filho --> F(F);
        E -- Irmão --> G(G);
            G -- Filho --> H(H);
                H -- Filho --> i8(( ));
                H -- Irmão --> I(I);
                    I -- Filho --> i9(( ));
                    I -- Irmão --> i10(( ));
            G -- Irmão --> i7(( ));
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
## `Questão 1:` Desenhe as duas árvores genéricas abaixo em uma floresta:
Crie uma arvore diferente do exemplo, faça elas mais profundas

~~~mermaid
graph TD;
    A(A)-->B(B);
        B-->E(E);
    A-->C(C);
    A-->D(D);
        D-->F(F);
        D-->G(G);

    H(H)-->I(I);
        I-->J(J);
        I-->K(K);
        I-->L(L);
~~~


## `Questão 2:` Crie uma função que busca um nó por seu valor e imprime o valor de todos os seus filhos.
~~~c
void busca (PArv a, tipoElemento x) {
    if (a == NULL) return; // Condição de Parada
    if (a->info == x) { // Se Encontrou o Nó
        PArv p = a->prim; // Ponteiro para os Filhos
        while (p != NULL) { // Percorrendo os Filhos (como uma lista encadeada)
            printf("%d\n", p->info); // Imprimindo o Filho
            p = p->prox; // Próximo Irmão
        }
        printf("\n");
        return;
    }
    busca(a->prim, x); // Buscando nos Filhos
    busca(a->prox, x); // Buscando nos Irmãos
}
~~~



## `Questão 3:` Faça um programa que leia n nomes e coloque os nomes em diferentes níveis dependendo da inicial do nome. No final, exiba a lista de nomes, agrupadas de acordo com a letra inicial do nome (os grupos devem estar em ordem alfabética).
### | Entrada:
~~~
11
João
Andrey
Lucas
José
Gabrieli
Thomas
Ana
Gustavo
Miguel
Júlia
Maria
~~~
### | Saída:
~~~
A
    Andrey
    Ana
G
    Gabrieli
    Gustavo
J
    João
    José
    Júlia
L
    Lucas
M
    Miguel
    Maria
T
    Thomas
~~~

---
