#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>


#define MAX 50
typedef int TIPOCHAVE;

/*

A -> B -> C -> D

ISSO É UMA FILA!


  
	  ->   ->   ->  ->
	A    B    C   D
<-	  <-   <-   <- 

Isso é um deque com inicio1 = A e inicio 2 = D
*/


typedef struct estrutura
{
	TIPOCHAVE chave;
	estrutura *prox;
} NO;

typedef struct 
{
	NO *inicio1;
	NO *inicio2;
} DEQUE;

void inicializar(DEQUE *d) {
	d->inicio1 = NULL;
	d->inicio2 = NULL;
}

TIPOCHAVE sairInicio1 (DEQUE *d) {
	TIPOCHAVE resp = -1;
	if(!d->inicio1)
		return resp;
	resp = d->inicio1->chave;
	NO * aux = d->inicio1;
	d->inicio1 = d->inicio1->prox;
	free(aux);
	if(!d->inicio1)
		d->inicio2 = NULL;
	else
		d->inicio1->ant = NULL;
	return resp;
}

void entrarInicio1(DEQUE *d, TIPOCHAVE ch) {
	NO *novo =(NO*) malloc(sizeof(NO));
	novo->chave = ch;
	novo->ant = NULL;
	novo->prox = d->inicio1;
	if(!d->inicio1)
		d->inicio2 = novo;
	else
		d->inicio1->ant = novo;
	d->inicio1 = novo;
}

TIPOCHAVE sairInicio2 (DEQUE *d) {
	TIPOCHAVE resp = -1;
	if(!d->inicio1)
		return resp;
	resp = d->inicio2->chave;
	NO * aux = d->inicio2;
	d->inicio2 = d->inicio2->ant;
	free(aux);
	if(!d->inicio2)
		d->inicio2 = NULL;
	else
		d->inicio2->prox = NULL;
	return resp;
}

void entrarInicio2(DEQUE *d, TIPOCHAVE ch) {
	NO *novo =(NO*) malloc(sizeof(NO));
	novo->chave = ch;
	novo->ant = d->inicio2;
	novo->prox = NULL;
	if(!d->inicio2)
		d->inicio1 = novo;
	else
		d->inicio2->prox = novo;
	d->inicio2 = novo;
}

void destruirDeque(DEQUE *d) {
	while(d->inicio1) {
		sairInicio1(d);
	}
}