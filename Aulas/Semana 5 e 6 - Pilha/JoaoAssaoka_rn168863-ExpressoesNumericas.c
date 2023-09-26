// João Victor Assaoka Ribeiro - rn168863
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Pilha {
	int info;
    struct Pilha *prox;
} TPilha;
typedef TPilha *PPilha;

PPilha inicializar() {
    return NULL; // inicializa a pilha (cria uma pilha vazia).
}

PPilha pop (PPilha topo, int *X) {
    PPilha aux = topo; // Cria um ponteiro que aponta para o topo da pilha. Isso é feito para que possamos acessar o elemento que será removido.
    *X = aux->info; // X armazena o valor do elemento no topo da pilha.
    topo = topo->prox; // Atualiza o ponteiro topo para apontar para o próximo elemento da pilha.
    free(aux); //  Libera a memória ocupada pelo elemento que foi removido.
    return topo; 
}

PPilha push (PPilha topo, int X) {
    PPilha novo = (PPilha)malloc(sizeof(TPilha));
    if (novo == NULL) exit(1); // Erro na Alocação

    novo->prox = topo; // O novo elemento aponta para o topo da pilha.
    novo->info = X; // O novo elemento guarda o valor X.
    return novo;
}

void esvaziar (PPilha topo) {
    if (topo != NULL) {
        esvaziar(topo->prox);
        free(topo);
    }
}

int calcular (char op, int X, int Y) {
    switch (op) {
        case '+': return X + Y;
        case '-': return X - Y;
        case '*': return X * Y;
    } // Se não for +, - ou *, assume divisão.
    return X / Y; // "Todos os casos de teste válidos irão gerar resultados que são números inteiros. Mesmo na ocorrência de uma divisão."
}

int main () {
    PPilha topo = inicializar();
    char expressao[1025]; // 1024 + 1 ('\0').
    int i, tam, X, Y; // tam armazena o numero de elementos empilhados.

    // "A entrada para cada teste inicia-se informado a string da expressão numérica na forma Postfix (RPN). O tamanho máximo da string correspondente a entrada é N, onde (1 ≤ N ≤ 1024). A string NÃO DEVE possuir espaços em branco."
    scanf("%s", expressao);

    for (i = 0, tam = 0; expressao[i] != '\0'; i++) {
        if (isdigit(expressao[i])){ // "Cada dígito (valor numérico) encontrado deve ser empilhado." 
            // "Quando for calcular a expressão, deve-se observar que a mesma é lida como um string, mas as operações com RPN são realizadas com números inteiros. O programa deve tratar essa conversão, portanto."
            topo = push(topo, expressao[i] - '0');
            tam++; // Atualiza o tamanho da pilha
        } else if ((expressao[i] == '+')||(expressao[i] == '-')||(expressao[i] == '*')||(expressao[i] == '/')) { // "Para cada operador encontrado na expressão deve-se desempilhar dois dígitos e efetuar a operação numérica correspondente, o resultado da operação deve ser armazenado na mesma pilha novamente, para uso futuro."
            if (tam >= 2) { // "Os operadores devem ser binários, ou seja, exigem a existência de dois dígitos para realização de uma operação matemática."
                topo = pop(topo, &Y); // Desempilha o segundo operando.
                topo = pop(topo, &X); // Desempilha o primeiro operando.
                topo = push(topo, calcular(expressao[i], X, Y)); // Realiza a operação correspondente e empilha o resultado.
                tam--; // // Atualiza o tamanho da pilha (retira 2 e coloca 1).
            } else { // Operação faltando operandos: "Caso a expressão de entrada seja invalida deve-se exibir: Invalid Expression"
                printf("Invalid Expression");
                return 1;
            }
        }
    }
    
    // "A saída do programa deve ser mostrada em uma linha a qual mostra o resultado da expressão numérica. Caso a expressão de entrada seja invalida deve-se exibir: Invalid Expression"
    if (tam == 1) printf("%d", topo->info);
    else printf("Invalid Expression"); // Ficaram 2 ou mais valores na pilha.
    esvaziar (topo); // Libera a memória da pilha.

    return 0;
}
