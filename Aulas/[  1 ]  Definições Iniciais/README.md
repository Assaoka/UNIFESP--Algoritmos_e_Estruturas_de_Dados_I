<h1 align="center"> Definições Iniciais </h1>

# Introdução:
&emsp;&emsp; Um algoritmo corresponde a uma descrição de um padrão de comportamento, representado por uma sequência finita de instruções, que, quando executadas, resolvem um determinado problema.

&emsp;&emsp; Algorítimos e Estruturas de Dados estão intimamente relacionados, pois não faz sentido falar de uma estrutura sem definir como ela será manipulada. Podemos utilizar a mesma struct para representar uma lista duplamente encadeada e uma árvore binária, por exemplo.


# Tipos de Dados:
&emsp;&emsp; O tipo de dado define o conjunto de valores que uma variável pode assumir e as operações que podem ser realizadas sobre esses valores. 
- `Tipos de Dados Simples:` São aqueles que não podem ser decompostos em outros tipos de dados: int, char, float...
- `Tipos Estruturados:` São aqueles que são compostos por outros tipos de dados: vetores, structs, unions...
- `Tipos Abstratos de Dados:` São aqueles que são definidos pelos seus comportamentos e não peça suas propriedades: pilhas, filas, árvores... Esses tipos de dados são o foco desta disciplina.

# Análise de Algoritmos:
&emsp;&emsp; Podem existir vários algorítimos para resolver o mesmo problema, cada um com suas vantagens e desvantagens. Para escolher o 'melhor' algorítimo, podemos analisar diversos aspectos, como: O número de operações que são realizadas e como esse número cresce com o aumento do tamanho da entrada ou a quantidade de memória necessária para executar o algorítimo. Uma observação importante é não confiar no tempo de execução, pois ele pode variar de acordo com o hardware e do compilador utilizado.

&emsp;&emsp; A função de complexidade é uma função que relaciona o tamanho da entrada com o
custo computacional do algorítimo (como o número de operações ou a quantidade de memória necessária). Ela é representada por f(n), onde n é o tamanho da entrada. Por exemplo, se um algorítimo realiza n² + 2n + 1 operações, sua função de complexidade é f(n) = n² + 2n + 1. A função de complexidade é uma ferramenta importante para comparar algorítimos, pois ela nos permite analisar o comportamento do algorítimo para entradas de diferentes tamanhos.

# Desenvolvendo Algorítimos Mais Eficientes: Buscar o Maior e o Menor Valor
&emsp;&emsp; O algorítimo abaixo busca resolver o problema de encontrar o maior e o menor elemento em um vetor de uma maneira mais inteligente e eficiente. Você pode encontrar o código em C após a explicação.

&emsp;&emsp;O algoritmo começa verificando o tamanho do vetor `Tam`. Se o tamanho for ímpar, utilizamos o primeiro elemento `V[0]` para inicializar tanto o `Maior` quanto o `Menor`. Se o tamanho for par, os dois primeiros elementos são comparados, e o maior é atribuído a `Maior`, e o menor é atribuído a `Menor`.

&emsp;&emsp;Em seguida, o algoritmo entra em um loop que percorre o vetor a partir do terceiro elemento. Para cada par de elementos (`V[i]` e `V[i + 1]`), ele realiza as seguintes comparações:
- Se `V[i]` for maior que `V[i + 1]`, ele compara `V[i]` com o valor atual de `Maior` e `V[i + 1]` com o valor atual de `Menor`.
- Se `V[i]` não for maior que `V[i + 1]`, ele compara `V[i + 1]` com o valor atual de `Maior` e `V[i]` com o valor atual de `Menor`.

&emsp;&emsp; Dessa forma, `Maior` e `Menor` são atualizados conforme o algoritmo encontra valores maiores ou menores no vetor.

&emsp;&emsp; Este algoritmo é eficiente, pois reduz o número de comparações necessárias, mesmo para vetores de tamanho grande. Além disso, ele lida adequadamente com vetores de tamanho ímpar, garantindo que o primeiro elemento seja tanto o maior quanto o menor, quando necessário.

~~~c
void MaiorMenorEficiente (int V[], int Tam, int *Maior, int *Menor) {
	int i = 2;
	if (Tam % 2 == 1) { // Se for impar, maior e menor viram V[0]
		*Maior = *Menor = V[0];
		i = 1;
	} else { // Se for par, o Maior recebe o maior dos dois primeiros e o Menor o menor
		if (V[0] > V[1]) *Maior = V[0], *Menor = V[1];
		else *Maior = V[1], *Menor = V[0];
	}

	while (i < Tam) {
		if (V[i] > V[i + 1]) { // Analisa o Maior com o maior e o Menor com o Menor.
			if (V[i] > *Maior) *Maior = V[i];
			if (V[i + 1] < *Menor) *Menor = V[i + 1];
		} else {
			if (V[i + 1] > *Maior) *Maior = V[i + 1];
			if (V[i] < *Menor) *Menor = V[i];
		}
		i += 2; // Anda para as duas próximas casas
	}
}

void LerVetor (int V[], int Tam) {
	int i = -1;
	while (++i < Tam)
		printf("V[%d] = ", i), scanf(" %d", &V[i]);
}

int main() {
	int Tam;
	printf("Digite o tamanho do vetor: "), scanf("%d", &Tam);
	
	int V[Tam];
	LerVetor(V, Tam);

	int Maior, Menor;
	MaiorMenorEficiente(V, Tam, &Maior, &Menor);
	printf("\nMaior: %d\nMenor: %d\n", Maior, Menor);

	return 0;
}
~~~


# Atividade 1: Contagem de Letras em Strings
&emsp;&emsp;A contagem de letras consiste em saber quantas vezes determinadas letras são encontradas na string. Deve-se escrever um programa que aborde essa característica, ou seja, escreva um programa que recebe uma string de comprimento N da entrada padrão e contabiliza a quantidade de cada letra do alfabeto presente de forma case insensitive (desconsiderando maiúsculas e minúsculas).

## Entrada:
&emsp;&emsp;Uma string de N caracteres (supondo tamanho máximo 256 caracteres).

## Saída:
&emsp;&emsp;Exibir uma lista de caracteres presentes em ordem lexicográfica crescente e suas respectivas frequências.

## Dicas:
1. Lembrar que toda string em C ou C++ contem o caractere especial ‘\0’ para demarcar o término do string. Deve-se levar este fato em consideração na alocação do vetor de caracteres, e nas manipulações para determinação de tamanhos e cópias.
2. O programa deve estar preparado para leituras de texto contendo espaços em branco, números e caracteres especiais, porém, somente as letras serão contabilizadas.

## Exemplo:
| `Entrada`    | `Saída`                                             |
| ------------ | --------------------------------------------------- |
| Hello world! | D 1<br> E 1<br> H 1<br> L 3<br> O 2<br> R 1<br> W 1 |


## Solução: 
~~~c
#include <stdio.h>
#include <string.h>

int main() {
	// Primeira parte: Lê uma string e checa se ela cumpre a regra (tamanho < 256)
	char txt[300];
	scanf("%[^\n]", txt);
	int tamStr = strlen(txt);
	if (tamStr > 256) // Encerra o código se for maior que o limite
		return 0;

	// Segunda parte: Aqui iremos utilizar um vetor para guardar quantas ocorrências de cada letra (Pensando no que vimos em aula, dediquei um tempo para otimizar o algoritmo. Tive a ideia de usar o número da letra em ASCII para atribuir a posição no vetor. Isso faz que em vez de fazer 25 comparações no pior caso, faremos no máximo 2 comparações)
	int i = 0, aux, letras[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	do {
		if ((txt[i] >= 'A') && (txt[i] <= 'Z')) {
			aux = txt[i] - 'A'; // Aux receberá um número de 0 a 25, correspondente a letra(ex: A = 0, B = 1 ... Z = 25)
			letras[aux] += 1;
		} else if ((txt[i] >= 'a') && (txt[i] <= 'z')) {
			aux = txt[i] - 'a'; // Aux receberá um número de 0 a 25, correspondente a letra(ex: a = 0, b = 1 ... z = 25)
			letras[aux] += 1;
		}
	} while (txt[++i] != '\0');

	i = 0;
	do {
		if (letras[i] > 0)
			printf("%c %d\n\n", i + 'A', letras[i]);
	} while (++i < 26);

	return 0;
}
~~~