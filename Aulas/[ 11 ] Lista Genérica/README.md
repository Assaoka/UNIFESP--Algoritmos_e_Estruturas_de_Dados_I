<h1 align="center"> Lista Genérica </h1>

# Definição de Lista Genérica:
&emsp;&emsp; A lista genérica é uma `lista encadeada mais flexível,` ela permite a criação de listas heterogêneas, ou seja, listas que `armazenam elementos de diferentes tipos.` Vamos supor que precisamos armazenar dados sobre retângulos, triângulos e círculos na mesma estrutura de dados. Como podemos fazer isso?

&emsp;&emsp; Você deve saber que `tipos de dados diferentes ocupam diferentes quantidades de memória,` então não podemos criar uma lista que armazena diretamente esses tipos de dados. A solução para esse problema é `criar uma lista que armazena o endereço de memória onde esses dados estão` armazenados (ponteiros) e não os dados em si. 

&emsp;&emsp; `Um ponteiro ocupa sempre ocupa a mesma quantidade de memória,` independente do tipo de dado para o qual ele aponta. Criando uma lista que armazena ponteiros genéricos (`void *`), podemos armazenar ponteiros para diferentes tipos de dados na mesma lista. Além disso, `precisamos de algo que informe qual o tipo de dado que está sendo apontado.` A estrutura abaixo é uma sugestão para uma lista genérica simplesmente encadeada:
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

# Operações Básicas:
## `1. Criar Nó:`
&emsp;&emsp; Agora que temos as estruturas para cada tipo de dado que queremos armazenar, podemos criar uma função para criar um nó da lista genérica. A função abaixo cria um nó para armazenar um retângulo:
~~~c
PNo criarRet (float base, float altura) {
    PNo novo = (PNo) malloc(sizeof(SNo)); // Alocamos o Nó
    PRetangulo ret = (PRetangulo) malloc(sizeof(SRetangulo)); // Alocamos a Informação do Nó

    ret->base = base;
    ret->altura = altura;
    novo->info = (void *) ret; // Recebendo o Endereço da Informação.
    novo->tipo = RETANGULO; // Definindo o Identificador
    novo->prox = NULL;
    return novo;
}
~~~

&emsp;&emsp; O exemplo acima aloca o nó para deixar mais claro que `estamos fazendo duas alocações de memória` (uma para o nó e outra para a informação do nó). Abaixo temos uma outra função que cria um retângulo, porém sem alocar o nó, apenas retornando o endereço da informação do nó:
~~~c
PRetangulo criarRet (float base, float altura) {
    PRetangulo ret = (PRetangulo) malloc(sizeof(SRetangulo));
    ret->base = base;
    ret->altura = altura;
    return ret;
}
~~~

## `2. Acesso e Liberação:`
&emsp;&emsp; Depois de criar o nó, podemos utilizar as funções que já conhecemos para a maioria das operações (basta alterar o `typedef int tipoElemento;` para `typedef void *tipoElemento;`). Podemos, por exemplo, enviar a função `criarRet` (fazendo a conversão de tipo: `(void *) criarRet(base, altura)`) como a informação do nó para alguma função de inserção que já conhecemos.

&emsp;&emsp; Porém devemos tomar cuidado com o `acesso a informação` do nó (pois estamos lidando com ponteiros genéricos) e com a `liberação da lista` (pois estamos alocando o nó e a informação do nó).

### `| Listar:`
~~~c
void listar (PNo lista) {
	PNo aux;
    PRetangulo ret;
    PCirculo cir;
    PTriangulo tri;

    for (aux = lista; aux != NULL; aux = aux->prox) {
        switch (aux->tipo) { // Trocamos o printf por um switch case para imprimir a informação corretamente.
            case RETANGULO: // Observe que definir uma constante para cada tipo de dado é uma boa prática
                ret = (PRetangulo) aux->info; // IMPORTANTE: É essencial fazer o cast para o tipo de dado correto
                printf("Retangulo: Base = %.2f, Altura = %.2f\n", ret->base, ret->altura);
                break;
            case TRIANGULO:
                tri = (PTriangulo) aux->info;
                printf("Triangulo: Base = %.2f, Altura = %.2f\n", tri->base, tri->altura);
                break;
            case CIRCULO:
                cir = (PCirculo) aux->info;
                printf("Circulo: Raio = %.2f\n", cir->raio);
                break;
        }
    }
}
~~~
### `| Liberar:`
~~~c
PNo liberar (PNo lista) {
	PNo aux;
	for (aux = lista; aux != NULL; aux = lista) {
		lista = lista->prox;
		free(aux->info); // Única Alteração em Relação a Função de Liberação de uma Lista Encadeada Simples. Basta Liberar a Informação Antes de Liberar o Nó.
        free(aux);
	}
	return NULL;
}
~~~

#
