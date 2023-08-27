// João Victor Assaoka Ribeiro - rn168863
#include <stdio.h>
#include <string.h>

int main(void)
{
	// Primeira parte: Lê uma string e checa se ela cumpre a regra (tamanho < 256)
	char txt[300];
	scanf("%[^\n]", txt);
	int tamStr = strlen(txt);
	if (tamStr > 256) // Encerra o código se for maior que o limite
		return 0;

	// Segunda parte: Aqui iremos utilizar um vetor para guardar quantas ocorrências de cada letra (Pensando no que vimos em aula, dediquei um tempo para otimizar o algoritmo. Tive a ideia de usar o número da letra em ASCII para atribuir a posição no vetor. Isso faz que em vez de fazer 25 comparações no pior caso, faremos no máximo 2 comparações)
	int i = 0, aux, letras[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	do
	{
		if ((txt[i] >= 'A') && (txt[i] <= 'Z'))
		{
			aux = txt[i] - 'A'; // Aux receberá um número de 0 a 25, correspondente a letra(ex: A = 0, B = 1 ... Z = 25)
			letras[aux] += 1;
		}
		else if ((txt[i] >= 'a') && (txt[i] <= 'z'))
		{
			aux = txt[i] - 'a'; // Aux receberá um número de 0 a 25, correspondente a letra(ex: a = 0, b = 1 ... z = 25)
			letras[aux] += 1;
		}
	} while (txt[++i] != '\0');

	i = 0;
	do
	{
		if (letras[i] > 0)
			printf("%c %d\n\n", i + 'A', letras[i]);
	} while (++i < 26);

	return 0;
}