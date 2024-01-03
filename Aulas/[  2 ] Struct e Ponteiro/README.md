<h1 align="center"> Struct e Ponteiro </h1>

# Struct:
&emsp;&emsp; Structs são tipos de dados estruturados que permitem agrupar diferentes tipos de dados (inclusive outros structs) em uma única variável. Por exemplo, podemos criar uma struct para representar um aluno, que contém o nome, a matrícula e a nota do aluno. A struct abaixo representa um aluno:
~~~c
typedef struct Aluno {
	char nome[50];
	int matricula;
	float nota;
} SAluno;
~~~

&emsp;&emsp; Para acessar os campos de uma struct, utilizamos o nome da variável seguido de um ponto (.) e o nome do campo. Poderíamos, por exemplo, criar uma variável do tipo SAluno, atribuir valores aos seus campos e imprimir esses valores da seguinte forma: 
~~~c
int main() {
	SAluno aluno;
	printf("Digite o nome do aluno: "), scanf("%s", aluno.nome);
	printf("Digite a matricula do aluno: "), scanf("%d", &aluno.matricula);
	printf("Digite a nota do aluno: "), scanf("%f", &aluno.nota);
	
	printf("Nome: %s\n", aluno.nome);
	printf("Matricula: %d\n", aluno.matricula);
	printf("Nota: %.2f\n", aluno.nota);
	
	return 0;
}
~~~

# Ponteiro:
&emsp;&emsp; Ponteiros são variáveis que armazenam endereços de memória. Elas podem ser declaradas adicionando um asterisco (*) antes do nome da variável. Antes de utilizar um ponteiro, é necessário inicializá-lo.

&emsp;&emsp; Não fazer isso é perigoso, pois o ponteiro (preenchido com lixo) pode apontar para algum endereço de memória que não pertence ao programa. Para inicializar um ponteiro, podemos atribuir a ele o valor NULL, que é um valor especial que indica que o ponteiro não aponta para nenhum endereço de memória. Podemos criar um ponteiro para um inteiro e inicializá-lo da seguinte forma:
~~~c
int *p; // Podemos inicializar ele como NULL aqui mesmo com: int *p = NULL;
p = NULL; 
~~~

&emsp;&emsp; Existem dois operadores que podem ser utilizados com ponteiros: o operador de endereço (&) e o operador "vai para" (*). O operador & retorna o endereço de memória de uma variável. Já o operador * retorna o valor encontrado no endereço de memória. Podemos criar um ponteiro para um inteiro x e utilizar esses operadores da seguinte forma:
~~~c
int x = 10, *p;
p = &x; // p recebe o endereço de memória de x
printf("%d\n", *p); // Imprime o valor encontrado no endereço de memória de x, ou seja, 10
*p = 20; // Altera o valor encontrado no endereço de memória de x para 20
printf("%d\n", x); // Imprime o valor de x, que agora é 20
~~~


# Ponteiro para Struct:
&emsp;&emsp; Podemos criar ponteiros para structs da mesma forma que criamos ponteiros para outros tipos de dados. É uma prática comum nomear ponteiros para structs com outro nome. Podemos criar um ponteiro para um aluno e utiliza-lo da seguinte forma:

~~~c
typedef SAluno *PAluno;

int main() {
	SAluno aluno1;
	PAluno aluno = &aluno1;

	printf("Digite o nome do aluno: "), scanf("%s", aluno->nome);
	printf("Digite a matricula do aluno: "), scanf("%d", &aluno->matricula);
	printf("Digite a nota do aluno: "), scanf("%f", &aluno->nota);
	
	printf("Nome: %s\n", aluno->nome);
	printf("Matricula: %d\n", aluno->matricula);
	printf("Nota: %.2f\n", aluno->nota);
	
	return 0;
}
~~~

&emsp;&emsp; Você pode observar que, para acessar os campos de uma struct através de seu endereço, utilizamos o operador pointer (->) ao invés do operador ponto. Na verdade, esse operador é apenas uma abreviação, pois a expressão aluno->nome é equivalente a (*aluno).nome. 
