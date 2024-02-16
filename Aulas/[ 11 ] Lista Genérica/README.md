<h1 align="center"> Lista Genérica </h1>

EM DESNVOLVIMENTO... O restante do conteúdo será adicionado em breve.


&emsp;&emsp; A lista genérica é uma lista encadeada mais flexível, permitindo a criação de listas heterogêneas, ou seja, listas que armazenam elementos de diferentes tipos. Vamos supor que precisamos armazenar dados sobre retângulos, triângulos e círculos na mesma estrutura de dados. Como podemos fazer isso?

&emsp;&emsp; Você deve saber que tipos de dados diferentes ocupam diferentes quantidades de memória, então não podemos criar uma lista que armazena diretamente esses tipos de dados. A solução para esse problema é criar uma lista que armazena o endereço de memória onde esses dados estão armazenados (ponteiros) e não os dados em si. 

&emsp;&emsp; Um ponteiro ocupa sempre ocupa a mesma quantidade de memória, independente do tipo de dado para o qual ele aponta. Criando uma lista que armazena ponteiros genéricos (`void *`), podemos armazenar ponteiros para diferentes tipos de dados na mesma lista. Além disso, precisamos de algo que informe qual o tipo de dado que está sendo apontado. A estrutura abaixo é uma sugestão para uma lista genérica simplesmente encadeada (você pode usar a mesma ideia para as outras estruturas de dados):
~~~c
typedef struct No {
	void *info; // Ponteiro Genérico para a Informação do Elemento
    int tipo; // Tipo de Dado Armazenado (Defina um valor para cada tipo de dado que você quer armazenar)
	struct No *prox; // Ponteiro para o Próximo Elemento
} SNo;
typedef SNo *PNo;
~~~

&emsp;&emsp; Vamos supor que precisamos das informações para calcular a área de cada figura geométrica. Para armazena-las na lista, podemos criar uma estrutura para cada tipo de dado que queremos armazenar. Abaixo estão as estruturas para retângulo, triângulo e círculo:
~~~c
#define RETANGULO 0
#define TRIANGULO 1
#define CIRCULO 2

typedef struct {
    float base;
    float altura;
} SRetangulo;
typedef SRetangulo *PRetangulo;

typedef struct {
    float base;
    float altura;
} STriangulo;
typedef STriangulo *PTriangulo;

typedef struct {
    float raio;
} SCirculo;
typedef SCirculo *PCirculo;
~~~

&emsp;&emsp; Agora que temos as estruturas para cada tipo de dado que queremos armazenar, podemos criar uma função para criar um nó da lista genérica. A função abaixo cria um nó para armazenar um retângulo:
~~~c
PNo criarRet (float base, float altura) {
    PNo novo = (PNo) malloc(sizeof(SNo));
    PRetangulo ret = (PRetangulo) malloc(sizeof(SRetangulo));

    ret->base = base;
    ret->altura = altura;
    novo->info = ret;
    novo->tipo = RETANGULO;
    novo->prox = NULL;
    return novo;
}
~~~

&emsp;&emsp; Depois de criar o nó, podemos inseri-lo com as funções que já conhecemos. Basta alterar o `typedef int tipoElemento;` para `typedef void *tipoElemento;` que a maioria das funções que já conhecemos funcionarão para a lista genérica. A remoção de um nó deve ser alterada para liberar a memória alocada para a informação do nó removido (pois estamos alocando memória para a informação do nó). A função abaixo libera a lista genérica:
~~~c




