#include <stdio.h>

int main () { // Manipulação de Arquivos
/* Abrindo um Arquivo: fopen()
.       Para abrir um arquivo, utilizamos a função `fopen()`, que recebe dois parâmetros: o nome do arquivo e o modo de abertura. Os modos de abertura estão explicados na tabela do README.md.

`Arquivo texto`: Um Arquivo que armazenam caracteres que podem ser lidos e editados diretamente por um editor de texto simples.

`Arquivo binário`: Um Arquivo que armazena uma sequência de bytes que representam alguma informação segundo as regras do programa que o criou. Consequentemente, um arquivo binário não pode ser lido diretamente por um editor de texto simples.

.       A função `fopen()` retorna um ponteiro para o arquivo aberto, ou `NULL` se ocorrer algum erro. O ponteiro retornado é do tipo `FILE *`, que é um ponteiro para uma estrutura de dados do tipo `FILE`, definida na biblioteca `stdio.h`. O ponteiro retornado é utilizado nas demais funções de manipulação de arquivos.

.       Exemplo de uso da função `fopen()`:         */

    FILE *arq;
    arq = fopen("arquivo.txt", "w+"); // fopen("nome_arquivo.txt", "modo");
    if (arq == NULL) {
        printf("Erro na abertura do arquivo");
        // Tratamento de erro
    }


/* Escrevendo em um Arquivo: fprintf()
.       A função `fprintf()` recebe como parâmetros o ponteiro para o arquivo e uma string de formatação, igual à utilizada na função `printf()`, porém, ela não imprime na tela, e sim escreve no arquivo.

.       Podemos escrever o nome e a idade de uma pessoa em um arquivo da seguinte forma:  */

    // Abertura do arquivo e tratamento de erro...
    fprintf(arq, "%d %s", 18, "Assaoka");


/* Lendo um Arquivo: fscanf() e getc()
fscanf()
.       A função `fscanf()` é utilizada para ler dados de um arquivo. Ela recebe como parâmetros o ponteiro para o arquivo e uma string de formatação, igual à utilizada na função `scanf()`. Retorna o número de itens lidos com sucesso, ou `EOF` (End Of File) se algum erro ocorrer.

.        Exemplo de uso da função `fscanf()`:       */
    int idade;
    char nome[50];
    // Abertura do arquivo e tratamento de erro...
    fscanf(arq, "%d %s", &idade, nome);


/* getc()
.       A função `getc()` é utilizada para ler um caractere de um arquivo. Ela recebe como parâmetro o ponteiro para o arquivo. A função `getc()` retorna o caractere lido, ou a constante `EOF` (End Of File) se o final do arquivo for atingido.

.       Podemos utilizar a função `getc()` para ler um arquivo caractere por caractere, até o final do arquivo. Exemplo de uso da função `getc()`:  */
    rewind(arq); // Não está presente no resumo, mas é nessário para o exemplo. Pois estamos lendo o arquivo duas vezes.

    char c;
    // Abertura do arquivo e tratamento de erro...
    while ((c = getc(arq)) != EOF) {
        printf("%c", c);
    }


/* Recolocando o Ponteiro no Início do Arquivo: rewind()
.       Quando um arquivo é aberto, um ponteiro é criado para indicar a posição atual do arquivo. Sempre que uma operação é realizada, o ponteiro é atualizado (Isso pode ser visualizado facilmente com a função `getc()`). 

.       A função `rewind()` recebe como parâmetro o ponteiro para o arquivo e recoloca o ponteiro no início do arquivo. Essa função é útil quando queremos ler o arquivo novamente, após já ter lido todo o arquivo.

.       Exemplo de uso da função `rewind()`:        */

    // Utilização do arquivo...
    rewind(arq);
    // Utilização do arquivo novamente...


/* Fechando um Arquivo: fclose()
.       A função `fclose()` recebe como parâmetro o ponteiro para o arquivo e fecha o arquivo. Fechar um arquivo após utilizá-lo é uma boa prática de programação, pois protege os seus dados, garante que atualizações feitas serão salvas e libera o arquivo para outros usuários ou programas poderem utilizá-lo.

.       Exemplo de uso da função `fclose()`:            */

    // Utilização do arquivo...
    fclose(arq);


// Fim do Resumo
    return 0;
}
