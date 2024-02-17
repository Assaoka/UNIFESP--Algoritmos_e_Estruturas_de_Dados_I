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