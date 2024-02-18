<h1 align="center"> Árvores de Expressão </h1>

Os exercícios estão em desenvolvimento. Provavelmente, serão postados ainda nesta madrugada.

# Definição:
&emsp;&emsp; Árvores de expressão são estruturas de dados que permitem representar e avaliar expressões matemáticas de forma hierárquica. Elas são compostas por nós, que podem ser operadores (como +, -, *, /) ou operandos (números ou variáveis).

&emsp;&emsp; Essas árvores são úteis em linguagens de programação para representar expressões matemáticas de forma mais clara e para facilitar a avaliação computacional dessas expressões.


&emsp;&emsp; A estrutura básica de uma árvore de expressão consiste em um nó raiz, que representa o operador principal da expressão, e dois subnós, que podem ser operadores ou operandos, representando os argumentos do operador principal. Essa estrutura pode se ramificar conforme a complexidade da expressão, formando uma hierarquia. 

&emsp;&emsp; Em uma árvore de expressão, os operadores sempre são nós internos, enquanto os operandos são nós folha.

&emsp;&emsp; A avaliação de uma expressão representada por uma árvore é feita de forma recursiva, começando pelos nós mais baixos da árvore e subindo até o nó raiz. Cada nó operador é avaliado com base nos valores dos seus subnós, e assim por diante, até que toda a expressão seja avaliada.



# Exemplo:
&emsp;&emsp; A expressão `matemática 3 + 4 * 2` pode ser representada pela seguinte árvore:
~~~mermaid
graph TD
    op1((+)) --> n1(3)
    op1 --> op2((*))
        op2 --> n2(4)
        op2 --> n3(2)    
~~~



# Formas de Impressão da Árvore:
&emsp;&emsp; A árvore de expressão pode ser impressa de três formas diferentes, que correspondem a três formas de notação de expressões matemáticas:

## `1. Pré-fixada:` Notação Polonesa
&emsp;&emsp; Imprime o operador antes dos operandos (raiz, esquerda, direita). **Resultado:** `+ 3 * 4 2`

## `2. Pós-fixada:` Notação Polonesa Reversa
&emsp;&emsp; Imprime o operador depois dos operandos (esquerda, direita, raiz). **Resultado:** `3 4 2 * +`

## `3. Infixa:` Notação Convencional
&emsp;&emsp; Imprime o operador entre os operandos (esquerda, raiz, direita). **Resultado:** `3 + 4 * 2`



# Exercícios:
## `Questão 1:` Transforme as expressões a seguir em árvores de expressão e imprima-as nas três formas de notação.
### `a)` 5 + 3 * 2
### `b)` (4 - 2) * 6
### `c)` 10 / 2 + 7

## `Questão 2:` Transforme as expressões na forma pré-fixada a seguir em árvores de expressão e imprima-as nas três formas de notação.
### `a)` - 15 * 4 2
<details><summary>Resposta</summary>

~~~mermaid
graph TD
    op1(("-")) --> n1(15)
    op1 --> op2((*))
        op2 --> n2(4)
        op2 --> n3(2)
~~~
pós: 15 4 2 * -

infixa: 15 - 4 * 2
</details>

### `b)` / 20 + 4 1

<details><summary>Resposta</summary>

~~~mermaid
graph TD
    op1(("/")) --> n1(20)
    op1 --> op2(("+"))
        op2 --> n2(4)
        op2 --> n3(1)
~~~
pós: 20 4 1 + /

infixa: 20 / 4 + 1
</details>


</details>
<br>
<br>
<br>
<br>
<br>
<br>
8 * 3 - 4

25 / 5 + 3

(6 + 2) * 4

30 / (3 * 2)