<h1 align="center" style="text-decoration: underline; font-weight: bold;"> Manipulação de Arquivos </h1>


# Abrindo um Arquivo: fopen()
&emsp;&emsp; Para abrir um arquivo, utilizamos a função `fopen()`, que recebe dois parâmetros: o nome do arquivo e o modo de abertura. O modo de abertura pode ser:

| `Modo`     | `Descrição` |
| ---------- | ----------- |
| **"r"**    | Abre um arquivo texto para leitura. O arquivo deve existir antes de ser aberto. |
| **"w"**    | Abrir um arquivo texto para gravação. Se o arquivo não existir, ele será criado. Se já existir, o conteúdo anterior será destruído. |
| **"a"**    | Abrir um arquivo texto para gravação. Os dados serão adicionados no fim do arquivo ("append"), se ele já existir, ou um novo arquivo será criado, no caso de arquivo não existente anteriormente. |
| **"rb"**   | Abre um arquivo binário para leitura. Igual ao modo "r" anterior, só que o arquivo é binário. |
| **"wb"**   | Cria um arquivo binário para escrita, como no modo "w" anterior, só que o arquivo é binário. |
| **"ab"**   | Acrescenta dados binários no fim do arquivo, como no modo "a" anterior, só que o arquivo é binário. |
| **"r+"**   | Abre um arquivo texto para leitura e gravação. O arquivo deve existir e pode ser modificado. |
| **"w+"**   | Cria um arquivo texto para leitura e gravação. Se o arquivo existir, o conteúdo anterior será destruído. Se não existir, será criado. |
| **"a+"**   | Abre um arquivo texto para gravação e leitura. Os dados serão adicionados no fim do arquivo se ele já existir, ou um novo arquivo será criado, no caso de arquivo não existente anteriormente. |
| **"r+b"**  | Abre um arquivo binário para leitura e escrita. O mesmo que "r+" acima, só que o arquivo é binário. |
| **"w+b"**  | Cria um arquivo binário para leitura e escrita. O mesmo que "w+" acima, só que o arquivo é binário. |
| **"a+b"**  | Acrescenta dados ou cria uma arquivo binário para leitura e escrita. O mesmo que "a+" acima, só que o arquivo é binário. |

`Arquivo texto`: Um Arquivo que armazenam caracteres que podem ser lidos e editados diretamente por um editor de texto simples.

`Arquivo binário`: Um Arquivo que armazena uma sequência de bytes que representam alguma informação segundo as regras do programa que o criou. Consequentemente, um arquivo binário não pode ser lido diretamente por um editor de texto simples.

&emsp;&emsp; A função `fopen()` retorna um ponteiro para o arquivo aberto, ou `NULL` se ocorrer algum erro. O ponteiro retornado é do tipo `FILE *`, que é um ponteiro para uma estrutura de dados do tipo `FILE`, definida na biblioteca `stdio.h`. O ponteiro retornado é utilizado nas demais funções de manipulação de arquivos.

&emsp;&emsp; Exemplo de uso da função `fopen()`:
~~~c
FILE *arq;
arq = fopen("arquivo.txt", "w+"); // fopen("nome_arquivo.txt", "modo");
if (arq == NULL) {
    printf("Erro na abertura do arquivo");
    // Tratamento de erro
}
~~~



# Escrevendo em um Arquivo: fprintf()
&emsp;&emsp; A função `fprintf()` recebe como parâmetros o ponteiro para o arquivo e uma string de formatação, igual à utilizada na função `printf()`, porém, ela não imprime na tela, e sim escreve no arquivo.

&emsp;&emsp; Podemos escrever o nome e a idade de uma pessoa em um arquivo da seguinte forma:
~~~c
// Abertura do arquivo e tratamento de erro...
fprintf(arq, "%d %s", 18, "Assaoka");
~~~



# Lendo um Arquivo: fscanf() e getc()
## fscanf()
&emsp;&emsp; A função `fscanf()` é utilizada para ler dados de um arquivo. Ela recebe como parâmetros o ponteiro para o arquivo e uma string de formatação, igual à utilizada na função `scanf()`. Retorna o número de itens lidos com sucesso, ou `EOF` (End Of File) se algum erro ocorrer.

&emsp;&emsp; Exemplo de uso da função `fscanf()`:
~~~c
int idade;
char nome[50];
// Abertura do arquivo e tratamento de erro...
fscanf(arq, "%d %s", &idade, nome);
~~~

## getc()
&emsp;&emsp; A função `getc()` é utilizada para ler um caractere de um arquivo. Ela recebe como parâmetro o ponteiro para o arquivo. A função `getc()` retorna o caractere lido, ou a constante `EOF` (End Of File) se o final do arquivo for atingido.

&emsp;&emsp; Podemos utilizar a função `getc()` para ler um arquivo caractere por caractere, até o final do arquivo. Exemplo de uso da função `getc()`:
~~~c
char c;
// Abertura do arquivo e tratamento de erro...
while ((c = getc(arq)) != EOF) {
    printf("%c", c);
}
~~~



# Recolocando o Ponteiro no Início do Arquivo: rewind()
&emsp;&emsp; Quando um arquivo é aberto, um ponteiro é criado para indicar a posição atual do arquivo. Sempre que uma operação é realizada, o ponteiro é atualizado (Isso pode ser visualizado facilmente com a função `getc()`). 

&emsp;&emsp; A função `rewind()` recebe como parâmetro o ponteiro para o arquivo e recoloca o ponteiro no início do arquivo. Essa função é útil quando queremos ler o arquivo novamente, após já ter lido todo o arquivo.

&emsp;&emsp; Exemplo de uso da função `rewind()`:
~~~c
// Utilização do arquivo...
rewind(arq);
// Utilização do arquivo novamente...
~~~



# Fechando um Arquivo: fclose()
&emsp;&emsp; A função `fclose()` recebe como parâmetro o ponteiro para o arquivo e fecha o arquivo. Fechar um arquivo após utilizá-lo é uma boa prática de programação, pois protege os seus dados, garante que atualizações feitas serão salvas e libera o arquivo para outros usuários ou programas poderem utilizá-lo.

&emsp;&emsp; Exemplo de uso da função `fclose()`:
~~~c
// Utilização do arquivo...
fclose(arq);
~~~

#
