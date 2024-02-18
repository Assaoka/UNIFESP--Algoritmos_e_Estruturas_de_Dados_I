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
## `Questão 1:` Transforme as expressões a seguir em árvores de expressão e escreva as outras duas formas de notação.

<details><summary><h3> A) 5 + 3 * 2</h3></summary>

&emsp;&emsp; Devemos resolver a expressão da seguinte forma: `(5 + (3 * 2))`
~~~mermaid
graph TD
    op1((+)) --> n1(5)
    op1 --> op2((*))
        op2 --> n2(3)
        op2 --> n3(2)
~~~
**Pré-Fixada:** `+ 5 * 3 2`
<br>**Pós-Fixada:** `5 3 2 * +`
</details>


<details><summary><h3> B) 15 - 4 * 2 + 3</h3></summary>

&emsp;&emsp; Devemos resolver a expressão da seguinte forma: `((15 - (4 * 2)) + 3)`
~~~mermaid
graph TD
    op1((+)) --> op2(("-"))
        op2 --> n1(15)
        op2 --> op3((*))
            op3 --> n2(4)
            op3 --> n3(2)
    op1 --> n4(3)
~~~
**Pré-fixada:** `+ - 15 * 4 2 3`
<br>**Pós-fixada:** `15 4 2 * - 3 +`
</details>


<details><summary><h3> C) 30 / (3 * 2) - 4 + 8</h3></summary>

&emsp;&emsp; Devemos resolver a expressão da seguinte forma: `(((30 / (3 * 2)) - 4) + 8)`
~~~mermaid
graph TD
    op1((+)) --> op2(("-"))
        op2 --> op3(("/"))
            op3--> n1(30)
            op3 --> op4((*))
                op4 --> n2(3)
                op4 --> n3(2)
        op2 --> n4(4)
    op1 --> n5(8)
~~~
**Pré-fixada:** `+ - / 30 * 3 2 4 8`
<br>**Pós-fixada:** `30 3 2 * / 4 - 8 +`
</details>


## `Questão 2:` Transforme as expressões na forma pré-fixada a seguir em árvores de expressão e escreva as outras duas formas de notação.

<details><summary><h3> A) * - 4 2 6 </h3></summary>

~~~mermaid
graph TD
    op1((*)) --> op2(("-"))
        op2 --> n1(4)
        op2 --> n2(2)
    op1 --> n3(6)
~~~
**Infixa:** `((4 - 2) * 6)`
<br>**Pós-fixada:** `4 2 - 6 *`
</details>


<details><summary><h3> B) - / 20 + 4 1 2 </h3></summary>

~~~mermaid
graph TD
    op1(("-")) --> op2(("/"))
        op2 --> n1(20)
        op2 --> op3(("+"))
            op3 --> n2(4)
            op3 --> n3(1)
    op1 --> n4(2)
~~~
**Infixa:** `((20 / (4 + 1)) - 2)`
<br>**Pós-fixada:** `20 4 1 + / 2 -`
</details>


<details><summary><h3> C) - + / 25 5 3 1 </h3></summary>

~~~mermaid
graph TD
    op1(("-")) --> op2(("+"))
        op2 --> op3(("/"))
            op3 --> n1(25)
            op3 --> n2(5)
        op2 --> n3(3)
    op1 --> n4(1)
~~~
**Infixa:** `(((25 / 5) + 3) - 1)`
<br>**Pós-fixada:** `25 5 / 3 + 1 -`
</details>


