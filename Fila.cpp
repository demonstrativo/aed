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

*/


typedef struct estrutura
{
	TIPOCHAVE chave;
	estrutura *prox;
} NO;

typedef struct 
{
	NO *inicio;
	NO *fim;
} FILA;

void inicializar(FILA *f) {
	f->inicio = NULL;
	f->fim = NULL;
}

void entrarFila(FILA *f, TIPOCHAVE ch) {
	NO *novo = (NO*) malloc(sizeof(NO));
	novo->chave = ch;
	novo->prox = NULL;
	if(!f->fim) // se não tem fim a fila ta vazia!
		f->inicio = novo;
	else
		f->fim->prox = novo;
	f->fim = novo; // atualizando final
}

TIPOCHAVE sairFila(FILA *f) {
	TIPOCHAVE resp = -1;
	if(!f->fim)
		return resp;
	resp = f->inicio->chave;
	NO *aux = f->inicio;
	f->inicio = f->inicio->prox;
	free(aux);
	if(!f->inicio)
		f->fim = NULL;
	return resp;
}

int contar(FILA *f) {
	int resp = 0;
	if(!f->fim)
		return resp;
	NO *p = f->inicio;
	while(p) {
		resp++;
		p = p->prox;
	}
	return resp;
}

typedef struct {
	TIPOCHAVE A[MAX];
	int inicio;
	int fim;
} FILA_EST;

void inicializar(FILA_EST *f) {
	f->inicio = -1;
	f->fim = -1;
}

TIPOCHAVE sairFila(FILA_EST *f) {
	TIPOCHAVE resp = -1;
	if(f->fim == -1)
		return resp;
	resp = f->A[f->inicio];
	if(f->inicio == f->fim) {
		f->inicio = -1:
		f->fim = -1; // CASO PARA FILA COM 1 ELEMENTO
	} else {
		f->inicio = (f->inicio + 1) % MAX; // caso de fila para ele ser circular e etc...
		// tipo se o inicio é 1 o novo valor vai ser o resto de f->inicio + 1 dividido por MAX
		// EXEMPLO MAX = 4 ... inicio +1 = 2;
		// 2 % 4 = 2; entao ok... 
		// Se for por exemplo 5 % 4 = 1
		// ou seja o inicio vira 1
	}
	return resp;
}

bool entrarFila(FILA_EST *f, TIPOCHAVE ch) {
	if(vetorCheio(&f))
		return false;
	if(f->fim == -1) {
		f->inicio = 0;
		f->fim = 0;
	} else {
		f->fim = (f->fim + 1) % MAX; // mesmo esquema do outro ...
		// pqp vou ter que desenhar no papel... merda
	}
	f->A[f->fim] = ch;
	return true;
}