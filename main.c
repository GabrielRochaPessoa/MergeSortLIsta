#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/time.h>
#include"mergelista.h"
/* Função Main   */
void main(){

	struct Node* a = NULL;
	int  dado=0, i=0;
	clock_t Ticks[2];
	double Tempo;
	long int valores;

	printf("Digite a quantidade de valoresa alocar\n");
	scanf("%ld", &valores);

	srand(time(NULL));

	/* Loop de geração de n números aleatórios   */

	for(i=0; i<valores;i++){
		construct(&a, rand() % 999999);
	}

	/* Impressão de lista desordenada */

	printf("\n\nLista Desordenada: \n");
	mostraLista(a);

	/* Contagem de tempo e chamada da função MergeSort*/
	Ticks[0] = clock();
	MergeSort(&a);
	Ticks[1] = clock();
	Tempo = (Ticks[1] - Ticks[0])* 1000/CLOCKS_PER_SEC;
    
    /* Impressão de lista Ordenada  */                
	printf("\n\nLista Ordenada: \n");
	mostraLista(a);
	/* Função de geração de n números aleatórios   */
	printf("\n\nTempo Gasto: %g Milissegundos.", Tempo);
	printf("\nMovimentacao: %d ", aumentaMov()-1);
	printf("\nComparacao: %d ", aumentaComp()-1);

	/* Função de clear da lista */
	a = limpar(a);

}
        