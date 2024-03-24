<h1 align="center"> Introdução a Grafos <br>
  <a href="../[ 12 ] Matrizes Esparsas/"><img src="https://img.shields.io/badge/Anterior-Matrizes Esparsas-215a36" alt="Anterior"></a>
  <a href="../[ 14 ] Introdução a Árvores Binárias/"><img src="https://img.shields.io/badge/Próximo-Introdução a Árvores Binárias-215a36" alt="Próximo"></a>
</h1>

# Terminologia:
| `Termo:`                    | `Significado:`                                                                                                                                                               |
| --------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `Grafo`                     | Conjunto de vértices e arestas.                                                                                                                                              |
| `Vértice`                   | Um nó que guarda informações. Pode ser utilizado para representar uma cidade, uma pessoa, uma máquina...                                                                     |
| `Aresta`                    | Uma ligação entre dois vértices. Podem indicar também a distância entre os dois vértices, direção...                                                                         |
| `Grafo Direcionado`         | Grafo em que as arestas possuem direção. Uma aresta que sai do vértice A e chega no vértice B, não é a mesma coisa que uma aresta que sai do vértice B e chega no vértice A. |
| `Grafo Não Direcionado`     | Grafo em que as arestas não possuem direção. As arestas são representadas como um par ordenado, onde a ordem não importa.                                                    |
| `Passeio`                   | Sequência de vértices. Ex: A -> B -> C -> B -> C                                                                                                                             |
| `Caminho`                   | Passeio em que não há repetição de vértices. Ex: A -> B -> C                                                                                                                 |
| `Comprimento de um Passeio` | Número de arestas do passeio.                                                                                                                                                |
| `Grau`                      | Número de arestas que incidem em um vértice. No caso de grafos direcionados, o grau é dividido em grau de entrada e grau de saída.                                           |
| `Ordem`                     | Número de vértices do grafo.                                                                                                                                                 |
| `Vértice Adjacente`         | Vértice que possui uma aresta que o liga a outro vértice. Caso exista uma aresta A - B, A e B são adjacentes.                                                                |
| `Sucessor`                  | Se um vértice possui uma aresta que sai dele e chega em outro vértice, o outro vértice é sucessor do primeiro. Caso exista uma aresta A -> B, B é sucessor de A.             |
| `Predecessor`               | Se um vértice possui uma aresta que sai de outro vértice e chega nele, o outro vértice é predecessor do primeiro. Caso exista uma aresta A -> B, A é predecessor de B.       |
| `Ciclo`                     | Passeio que começa e termina no mesmo vértice.                                                                                                                               |
| `Árvore`                    | Grafo sem ciclos.                                                                                                                                                            |
| `Folha`                     | Vértice que possui grau 1. Ou seja, possui apenas uma aresta.                                                                                                                |
| `Sub-Grafo`                 | Grafo que possui um subconjunto de vértices e arestas de um grafo maior.                                                                                                     |
| `Completo`                  | Grafo em que todos os vértices são adjacentes entre si. Ou seja, todos os vértices possuem arestas que os ligam a todos os outros vértices.                                  |



# Matriz de Adjacência:
&emsp;&emsp; Essa é a primeira representação que vamos ver. Ela é uma matriz quadrada de ordem n, sendo n o número de vértices, onde cada posição representa uma aresta do grafo.

&emsp;&emsp; Caso exista uma aresta que sai do vértice i e chega no vértice j, a posição linha i coluna j da matriz recebe o valor 1. Caso contrário, recebe o valor 0.

&emsp;&emsp; Apropriada para grafos mais densos (com muitas arestas) e para casos em que é necessário verificar se existe uma aresta entre dois vértices rapidamente.

## `| Exemplo:`
![Alt text](image.png)
|     | `1` | `2` | `3` | `4` | `5` | `6` |
| --- | --- | --- | --- | --- | --- | --- |
| `1` | 0   | 1   | 0   | 1   | 0   | 0   |
| `2` | 0   | 0   | 1   | 0   | 0   | 0   |
| `3` | 1   | 0   | 1   | 1   | 0   | 0   |
| `4` | 1   | 0   | 0   | 0   | 0   | 0   |
| `5` | 0   | 0   | 0   | 0   | 0   | 0   |
| `6` | 0   | 0   | 0   | 0   | 1   | 0   |

Dos 36 espaços da matriz, apenas 8 são preenchidos. Ou seja, apenas 22% da matriz é utilizada nesse caso.

## `| Vantagens e Desvantagens:`
| `Vantagens:`                                                  | `Desvantagens:`                                                                                                |
| ------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------- |
| Acesso rápido a existência de uma aresta entre dois vértices. | Ocupa uma quantidade de memória proporcional a n². Não é apropriada para grafos esparsos (com poucas arestas). |
| Adição e remoção de arestas é simples.                        | A simples inicialização da matriz pode ser dominante na execução global do algoritmo.                          |
| Fácil evitar a existência de arestas paralelas.               | Pode sequer ser possível inicializar a matriz se o número de vértices for muito grande.                        |
| Arranjo bidimensional de booleanos.                           |                                                                                                                |


## `Lista de Adjacência:`
&emsp;&emsp; Essa representação é basicamente uma versão compacta da matriz de adjacência. Cada vértice é uma lista encadeada que guarda os vértices adjacentes a ele, ou seja, temos uma matriz esparsa.

&emsp;&emsp; Apropriada para grafos mais esparsos (com poucas arestas) e para casos em que é necessário percorrer todos os vértices adjacentes a um vértice rapidamente.



# Matriz de Incidência:
&emsp;&emsp; Uma matriz de ordem n x m, sendo n o número de vértices e m o número de arestas, onde cada posição representa se uma aresta está ligada a um vértice.

&emsp;&emsp; Caso exista uma aresta que sai do vértice i e chega no vértice j, a linha i coluna ij da matriz recebe o valor 1. Caso exista uma aresta que sai de j e chega em i, a linha i coluna ij recebe o valor -1. Caso contrário, recebe o valor 0. Caso seja um grafo não direcionado, a matriz possui apenas valores 0 e 1.


## `| Exemplo:`
![Alt text](image.png)
|     | `1,2` | `1,3` | `1,4` | `2,3` | `3,3` | `3,4` | `5,6` |
| --- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| `1` | 1     | -1    | 1     | 0     | 0     | 0     | 0     |
| `2` | -1    | 0     | 0     | 1     | 0     | 0     | 0     |
| `3` | 0     | 1     | 0     | -1    | 1     | 1     | 0     |
| `4` | 0     | 0     | 1     | 0     | 0     | -1    | 0     |
| `5` | 0     | 0     | 0     | 0     | 0     | 0     | -1    |
| `6` | 0     | 0     | 0     | 0     | 1     | 0     | 1     |

---
