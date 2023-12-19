<h1 align="center"> Notação Assintótica </h1>

## Explicação do Conteúdo 
Em Breve ...


## Problema 1 - Contagem de Letras em Strings
&emsp;&emsp;A contagem de letras consiste em saber quantas vezes determinadas letras são encontradas na string. Deve-se escrever um programa que aborde essa característica, ou seja, escreva um programa que recebe uma string de comprimento N da entrada padrão e contabiliza a quantidade de cada letra do alfabeto presente de forma case insensitive (desconsiderando maiúsculas e minúsculas).

`Entrada:` Uma string de N caracteres (supondo tamanho máximo 256 caracteres).
<br>`Saída:` Exibir uma lista de caracteres presentes em ordem lexicográfica crescente e suas respectivas frequências.
<br>`Dicas:`
<br>&emsp;⚙ Lembrar que toda string em C ou C++ contem o caractere especial ‘\0’ para demarcar o término do string. Deve-se levar este fato em consideração na alocação do vetor de caracteres, e nas manipulações para determinação de tamanhos e cópias.
<br>&emsp;⚙ O programa deve estar preparado para leituras de texto contendo espaços em branco, números e caracteres especiais, porém, somente as letras serão contabilizadas.

| Exemplo de Entrada | Exemplo de Saída |
|--|--|
| Hello world! | D 1<br> E 1<br> H 1<br> L 3<br> O 2<br> R 1<br> W 1 |

<br>🔹 Você pode encontrar a Minha Resolução em C neste [link](./JoaoAssaoka_rn168863-AP1.c).


## Buscar o Maior e o Menor Valor de Forma Eficiente
&emsp;&emsp;Este algoritmo em C resolve o problema de encontrar o maior e o menor elemento em um vetor de inteiros de uma maneira mais inteligente e eficiente. Você pode encontrar o código em C neste [link](./MaiorMenor_Eficiente.c). Espero que esta explicação ajude a compreender como o algoritmo funciona.

&emsp;&emsp;O algoritmo começa verificando o tamanho do vetor `Tam`. Se o tamanho for ímpar, utilizamos o primeiro elemento `V[0]` para inicializar tanto o `Maior` quanto o `Menor`. Se o tamanho for par, os dois primeiros elementos são comparados, e o maior é atribuído a `Maior`, e o menor é atribuído a `Menor`.

&emsp;&emsp;Em seguida, o algoritmo entra em um loop que percorre o vetor a partir do terceiro elemento. Para cada par de elementos (`V[i]` e `V[i + 1]`), ele realiza as seguintes comparações:
- Se `V[i]` for maior que `V[i + 1]`, ele compara `V[i]` com o valor atual de `Maior` e `V[i + 1]` com o valor atual de `Menor`.
- Se `V[i]` não for maior que `V[i + 1]`, ele compara `V[i + 1]` com o valor atual de `Maior` e `V[i]` com o valor atual de `Menor`.

Dessa forma, `Maior` e `Menor` são atualizados conforme o algoritmo encontra valores maiores ou menores no vetor.

Este algoritmo é eficiente, pois reduz o número de comparações necessárias, mesmo para vetores de tamanho grande. Além disso, ele lida adequadamente com vetores de tamanho ímpar, garantindo que o primeiro elemento seja tanto o maior quanto o menor, quando necessário.
