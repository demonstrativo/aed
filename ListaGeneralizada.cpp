#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>



/*
"O" indica subLista.

A -> B -> O -> H -> I -> J -> K -> L -> M
		  |								|
		  |								|
		   ->C->D-> O					 -> T -> R -> O
		  	   	    |                                 |
		  	   	    |                                 |
		  	   	     ->E->F->G                         -> X -> Y -> Z


*/
enum {elemLista, inicioLista} IDENT;

typedef struct s {
	s* prox;
	IDENT tag;
	union {
		int info;
		s* subLista;
	}
} NO;

int contarChaves(NO *p) {
	int resp = 0;
	while(p) {
		if(p->tag == elemLista)
			resp++;
		else 
			resp = resp + contarChaves(p->subLista);
		p = p->prox;
	}
	return resp;
}

int contarListas (NO *p) {
	int resp = 0;
	while (p) {
		if(p->tag == inicioLista) {
			resp++;
			resp = resp + contarListas(p->subLista);
		}
		p = p->prox;
	}
	return resp;
}

bool comparar(NO *p1,NO *p2) {
	bool ok;
	if(!p1 && !p2)
		return true;
	if(!p1 || !p2)
		return false;
	if(p1->tag != p2-> tag)
		return false;
	if(p1->tag == elemLista)
		ok = (p1->info == p2->info);
	else
		ok = comparar(p1->subLista, p2->subLista);
	if(!ok)
		return false;
	else
		return (comparar(p1->prox,p2->prox));
}

NO* copiar(NO *p) {
	if(!p)
		return NULL;
	NO* novo = (NO*) malloc(sizeof(NO));
	novo->tag = p->tag;
	novo->prox = copiar(p->prox);
	if(p->tag == elemLista) {
		novo->info = p->info;
	} else {
		novo->subLista = copiar(p->subLista);
	}
	return novo;
}

// REIMPLEMENTAR
int profundidadeMaxima(NO* p) {
	if(!p)
		return false;
	int max = 1;
	int resp;
	while(p) {
		resp = 1;
		if(p->tag = inicioLista)
			resp = resp + pofundidadeMaxima(p->subLista);
		if(	resp > max)
			max = resp;
		p = p->prox;
	}
	return max+1;
}