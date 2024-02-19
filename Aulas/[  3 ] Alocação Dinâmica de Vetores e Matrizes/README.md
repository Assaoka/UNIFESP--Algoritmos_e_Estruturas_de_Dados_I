<h1 align="center"> Alocação Dinâmica de Vetores e Matrizes </h1>

# Vetores na Linguagem C:
&emsp;&emsp; Vetores são estruturas de dados que armazenam um conjunto de valores do mesmo tipo. Para a linguagem C, um vetor é um ponteiro para o primeiro elemento do conjunto de valores. A partir do endereço do primeiro elemento, é possível acessar qualquer outro elemento com o uso de aritmética de ponteiros.

&emsp;&emsp; Podemos receber um vetor já existente e acessar seus elementos da seguinte forma:
~~~c
int v[10], *p, i;
p = v; // ou p = &v[0];

for (i = 0; i < 10; i++)
    scanf("%d", &p[i]); // ou scanf("%d", p + i);

for (i = 0; i < 10; i++)
    printf("%d\n", p[i]); // ou printf("%d\n", *(p + i));
~~~

# Combinação dos Operadores ++ e *:
&emsp;&emsp; Esses dois operadores podem ser combinados de diversas formas para operar sobre vetores. Vamos analisar cada uma das expressões, considerando que p aponta para o primeiro elemento de um vetor v.

| `Combinação`      | `Operação`                                                                                                                  | `Resultado`                                                                         |
| ----------------- | --------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------- |
| `*p++` e `*(p++)` | Ambos retornam o valor apontado por p e, em seguida, incrementam o ponteiro para apontar para a próxima posição de memória. | Retorna o valor de v[0], em seguida, passa a apontar para v[1].                     |
| `(*p)++`          | Acessa o valor apontado por p e, em seguida, incrementa esse valor em 1.                                                    | primeiro retorna o valor de v[0] e, em seguida, incrementamos o valor de v[0] em 1. |
| `*++p`            | Anda com o ponteiro para a próxima posição de memória e, em seguida, retorna o valor apontado por p.                        | Avança para v[1] e retorna o valor de v[1].                                         |
| `++*p` e `++(*p)` | Acessa o valor apontado por p, incrementa esse valor em 1 e, em seguida, retorna o valor incrementado.                      | v[0] passa a valer v[0] + 1 e retorna o novo valor de v[0].                         |

`Observação:` Essas expressões podem ser utilizadas apenas com ponteiros. Por mais que um vetor seja um ponteiro, se ele tiver sido declarado como vetor não é possível trocar o seu endereço de memória.

# Alocação Dinâmica:
&emsp;&emsp; As funções abaixo são da biblioteca stdlib.h. Para utilizá-las, é necessário incluir a biblioteca no início do programa.

## Sizeof:
&emsp;&emsp; Essa função retorna o tamanho em bytes de um tipo de dado ou de uma variável. Por exemplo:
~~~c
printf("%d\n", sizeof(int)); // imprime 4, pois um inteiro ocupa 4 bytes de memória.
~~~

## Malloc:
&emsp;&emsp; Essa função recebe como parâmetro o tamanho em bytes e retorna um ponteiro `void` para o início do bloco de memória alocado. Caso não seja possível alocar o bloco de memória, a função retorna NULL (ponteiro nulo).
~~~c
int *p;
p = (int *) malloc(10 * sizeof(int)); // aloca um vetor de 10 inteiros
~~~

&emsp;&emsp; Como a função retorna um ponteiro `void`, é necessário fazer um `cast` para o tipo de ponteiro desejado. Para fazer o `cast`, basta colocar o tipo de ponteiro desejado entre parênteses antes da chamada da função. Após isso, o ponteiro `p` passa a se comportar como um vetor de 10 inteiros.

## Calloc:
&emsp;&emsp; Essa função recebe como parâmetro o número de elementos e o tamanho em bytes de cada elemento e retorna um ponteiro `void` para o início do bloco de memória alocado. Caso não seja possível alocar o bloco de memória, a função também retorna NULL. Além do parâmetro do número de elementos (que pode ser resolvido multiplicando o número de elementos pelo tamanho de cada elemento na função malloc), essa função tem a vantagem de inicializar todos os bytes do bloco de memória alocado com 0 (perde em desempenho por ter que inicializar, mas ganha em segurança).
~~~c
int *p;
p = (int *) calloc(10, sizeof(int)); // aloca um vetor de 10 inteiros
~~~

## Realloc:
&emsp;&emsp; Essa função recebe como parâmetro um ponteiro para um bloco de memória já alocado e o novo tamanho em bytes desejado para esse bloco. A função retorna um ponteiro `void` para o início do bloco de memória realocado. Caso não seja possível realocar o bloco de memória, a função retorna NULL. Essa função é útil quando precisamos aumentar ou diminuir o tamanho de um bloco de memória já alocado.
~~~c
int *p;
p = (int *) malloc(10 * sizeof(int)); // aloca um vetor de 10 inteiros
p = (int *) realloc(p, 20 * sizeof(int)); // realoca o vetor para 20 inteiros
~~~

`Observações:`
1. Os valores antigos do vetor são mantidos na realocação.
2. Caso o novo tamanho seja menor que o tamanho original, os valores excedentes do final são perdidos.
3. Caso o novo tamanho seja maior que o original, é necessário inicializar os novos valores manualmente.

## Free:
&emsp;&emsp; Essa função recebe como parâmetro um ponteiro para um bloco de memória alocado e libera esse bloco de memória. 

&emsp;&emsp; Essa função é muito importante para evitar vazamento de memória, pois o espaço alocado dinamicamente não é liberado automaticamente pelo sistema operacional.

&emsp;&emsp; Após a chamada da função, o ponteiro passa a apontar para um endereço inválido, então é uma boa prática atribuir NULL ao ponteiro após a chamada da função.

~~~c
int *p;
p = (int *) malloc(10 * sizeof(int)); // aloca um vetor de 10 inteiros
free(p); // libera o vetor
p = NULL; // atribui NULL ao ponteiro
~~~

# Alocação Dinâmica de Matrizes:
&emsp;&emsp; Para alocar uma matriz, vamos utilizar um vetor de ponteiros para o tipo de dado desejado. E cada posição desse vetor vai apontar para um vetor de elementos do tipo desejado. Caso a matriz tenha mais dimensões, basta repetir o processo para cada dimensão.

~~~c
int **m, i;
m = (int **) malloc(10 * sizeof(int *)); // aloca um vetor de 10 ponteiros para inteiros
for (i = 0; i < 10; i++)
    m[i] = (int *) malloc(10 * sizeof(int)); // aloca um vetor de 10 inteiros para cada posição do vetor de ponteiros
~~~

`Observação:` Para cada alocação dinâmica, é necessário utilizar a função free para liberar a memória alocada. Então, para liberar uma matriz, é necessário liberar cada vetor de inteiros e, em seguida, liberar o vetor de ponteiros.

~~~c
int **m, i;

// Criando e Utilizando a Matriz...

for (i = 0; i < 10; i++)
    free(m[i]); // libera cada vetor de inteiros
free(m); // libera o vetor de ponteiros
~~~

# JUDGE:
## `| Corrida Maluca:`
&emsp;&emsp; A corrida maluca sempre foi disputada por 11 carros, com a participação de Dick Vigarista e sua turma. As corridas são sempre marcadas por muitas reviravoltas, o que tornaram essas corridas muito famosas mundialmente. Isso atraiu a atenção de muitas pessoas, que se interessaram em aderir à competição. Porém, para que uma grande quantidade de carros possa disputar a prova, seria preciso também a adoção de um sistema automático para acompanhar o progresso da prova, pois uma prova geralmente tem muitas ultrapassagens. 

&emsp;&emsp; Com o advento de novas tecnologias digitais em categorias profissionais de automobilismo, a organização da corrida maluca decidiu implantar um sistema informatizado que recebe informações em tempo-real do andamento da prova. Esse sistema, envia dados à central, informando cada ultrapassagem realizada durante a prova. Porém, o fornecedor deste sistema não forneceu nenhum software para gerenciar essas informações. A sua tarefa, portanto, é escrever um programa que processe as informações de ultrapassagens na prova e determine os três primeiros colocados no final da corrida.

&emsp;&emsp; Você deverá criar uma estrutura de dados para guardar o nome e o número de um corredor, que será alocada dinamicamente conforme for utilizá-la. Deverá também utilizar alocação dinâmica para vetor que armazenará os dados dos corredores. Atenção: o exercício só terá validade se for utilizado alocação dinâmica para qualquer vetor utilizado e para cada estrutura que for utilizada!!

### Entrada:
&emsp;&emsp; A primeira linha da entrada contém o número N (3≤N≤1000) de participantes da corrida.

&emsp;&emsp; As próximas N linhas contêm os seguintes dados dos competidores: número do carro e nome. O número do carro é um inteiro positivo e único. O nome é um nome simples (sem espaço) de até 20 caracteres. 

&emsp;&emsp; Na linha seguinte, são passados N números separados por espaços, correspondendo aos números dos carros em ordem de largada, do primeiro ao último carro. 

&emsp;&emsp; Nas linhas seguintes, são apresentadas as ultrapassagens. Cada uma dessas linhas contém o número do carro que faz a ultrapassagem sobre o carro a sua frente. A última linha contém o número -1, indicando o final da entrada. Na implementação, sempre verifique se a ultrapassagem indicada é válida. Só execute ultrapassagens válidas. Se for digitada ultrapassagem inválida, ignore-a

### Saída:
&emsp;&emsp; Você deve imprimir a lista com o número e o nome dos três primeiros colocados da corrida, sendo um participante por linha, do primeiro para o terceiro lugar. 

### Exemplos:
| `Entrada`                                                                                              | `Saída`                         |
| ------------------------------------------------------------------------------------------------------ | ------------------------------- |
| 3<br>1 Rufus<br>2 Penelope<br>3 Dick<br>1 2 3<br>3<br>3<br>1<br>-1                                     | 1 Rufus<br>3 Dick<br>2 Penelope |
| 5<br>1 Zorzi<br>2 Coston<br>3 Vos<br>4 Kokubun<br>5 Nobles<br>2 5 4 1 3<br>5<br>2<br>1<br>3<br>1<br>-1 | 2 Coston<br>1 Zorzi<br>5 Nobles |

### Solução:
~~~c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nome[21]; // 20 Caracteres + '/0'
	int num;
} CARRO;

int main() {
	int N, i, j, Aux_Num, Aux_Controle; // 3 ≤ N ≤ 1000
	CARRO **carros, *Troca_Struct;

	// "A primeira linha da entrada contém o número N (3≤N≤1000) de participantes da corrida."
	scanf(" %d", &N);
	if ((N < 3) || (N > 1000)) return 0;

	// "As próximas N linhas contêm os seguintes dados dos competidores: número do carro e nome. O número do carro é um inteiro positivo e único. O nome é um nome simples (sem espaço) de até 20 caracteres."
	carros = (CARRO **)malloc(N * sizeof(CARRO *));
	if (carros == NULL) exit(1); // Erro na Alocação
	for (i = 0; i < N; i++) {
		carros[i] = (CARRO *)malloc(sizeof(CARRO));
		if (carros[i] == NULL) exit(1); // Erro na Alocação
		scanf(" %d %s", &carros[i]->num, carros[i]->nome);
	}

	// "Na linha seguinte, são passados N números separados por espaços, correspondendo aos números dos carros em ordem de largada, do primeiro ao último carro."
	for (i = 0; i < N; i++)	{
		scanf(" %d", &Aux_Num);
		for (j = i; j < N; j++) {
			if (carros[j]->num == Aux_Num) {
				Troca_Struct = carros[j];
				carros[j] = carros[i];
				carros[i] = Troca_Struct;
			}
		}
	}

	// "Nas linhas seguintes, são apresentadas as ultrapassagens. Cada uma dessas linhas contém o  número do carro que faz a ultrapassagem sobre o carro a sua frente. A última linha contém o número -1, indicando o final da entrada."
	do {
		scanf(" %d", &Aux_Controle);
		if (Aux_Controle != -1) {
			if (carros[0]->num != Aux_Controle) {
				for (i = 1; i < N; i++) {
					if (carros[i]->num == Aux_Controle) {					
						Troca_Struct = carros[i];
						carros[i] = carros[i - 1];
						carros[i - 1] = Troca_Struct;
					}
				}
			}
		}
	} while (Aux_Controle != -1);

	// Você deve imprimir a lista com o número e o nome dos três primeiros colocados da corrida, sendo um participante por linha, do primeiro para o terceiro lugar.
	for (i = 0; i < 3; i++)	{
		printf("%d %s\n", carros[i]->num, carros[i]->nome);
	}

	// Libera a Memoria Alocada
	for (i = 0; i < N; i++)
		free(carros[i]);
	free(carros);
	return 0;
}
~~~
