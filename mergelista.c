#include <stdlib.h>
#include <stdio.h>
#include "mergelista.h"

/* Nó da Lista */
struct Node{
	int valor;
	struct Node* prox;};
        
        int comp =0;
        int mov =0;

int aumentaComp(){
    comp = comp+1;
    return comp;}

int aumentaMov(){
    mov = mov+1;
    return mov;}
        
/*Classifica o nó da lista encadeada trocando os ponteiros */
void MergeSort(struct Node** headRef){
struct Node* head = *headRef;
struct Node* a;
struct Node* b;

if ((head == NULL) || (head->prox == NULL)){
	return;}//Caso base, se head ==NULL e head->prox for NULL também, então não há mais nós para serem verificados

/* Divide os elementos em A e B recebidos como parâmetro da função  */
particiona(head, &a, &b); 

/* Recursivamente ordena as sublistas */
MergeSort(&a);
MergeSort(&b);

/* Mescla as duas sublistas  */
*headRef = integra(a, b);}

struct Node* integra(struct Node* a, struct Node* b){
struct Node* result = NULL;
/* Casos Base*/
if (a == NULL)
	return(b);

else if (b==NULL)
	return(a);

/* escolhe a ou b e chamaa função recursiva */
if (a->valor <= b->valor){
        result = a;
	result->prox = integra(a->prox, b);}

else{
        result = b;
	result->prox = integra(a, b->prox);}

return(result);}



/* Divide os nos da lista dada em metades da frente e de trás,
e retorne as duas listas usando os parâmetros de referência.
Se o comprimento for ímpar, o número extra deve entrar na lista da frente. */

void particiona(struct Node* no, struct Node** frente, struct Node** pos){
	struct Node* lebre;
	struct Node* tarta;
	tarta = no;
	lebre = no->prox;

	/* Avança 'lebre' dois nós, e avança 'tarta' um nó */
	while (lebre != NULL){
	lebre = lebre->prox;
	if (lebre != NULL){
		tarta = tarta->prox;
		lebre = lebre->prox;}}

	/* 'tarta' é antes do ponteiro do meio da lista, e vai dividí-lo em dois
	no mesmo ponto. */
	*frente = no;
	*pos = tarta->prox;
	tarta->prox = NULL;}

/* Função de imprimir nós de uma lista encadeada */
void mostraLista(struct Node *no){
    while(no!=NULL){
    printf("%d ", no->valor);
    no = no->prox;}}

/* Função de inserir nó no começo da lista encadeada  */
void construct(struct Node** antigo, int valor){
/* aloca o nó */
struct Node* novo = (struct Node*) malloc(sizeof(struct Node));

/* Aloca o valor */
novo->valor = valor;

/* Linka a lista antiga ao novo */
novo->prox = (*antigo); 

/* move a referencia do antigo nó para o novo*/
(*antigo) = novo;} 

Node * limpar(Node *a){
    Node *aux;
    while (a != NULL)
    {
        aux = a;
        a = a->prox;
        free (aux);
    }
    
return a = NULL;}
