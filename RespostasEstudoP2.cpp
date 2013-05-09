
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>


// 1)dada uma matriz esparsa, excluir uma linha inteira

typedef struct s{
	int info;
	int lin;
	int col;
	*s prox;
} NO;

typedef struct {
	NO* inicio;
} MATRIZ;


void excluirLinhaInteira(MATRIZ *m, int linha) {
	NO* p = m->inicio;
	while(p) {
		if(p->lin == linha) {
			NO *aux = p;
			p = p->prox;
			free(aux); // talvez o p = p->prox posso ficar direto no final... mas fiquei com medo de perder a referencia e etc...
		} else if(p->lin > linha) {
			break;
		} else {
			p = p->prox;
		}
	}
}

typedef struct s {
	int info;
	int lin;
	int col;
	*s proxC;
	*s proxL;
} NO;

typedef struct {
	NO* lin[MAXLIN+1];
	NO* col[MAXCOL+1];
} MATRIZ;

void excluirLinhaI(MATRIZ *m, int i) {
	NO *ant;
	NO *p = busca(m->inicio,i,j,&ant);
	while(p) {
		if(p->lin == i) {
				ant->prox = p->prox;
				free(p);
				p = busca(ant->prox,ant->prox->lin,ant->prox->col,&ant);
			} else {
				p = busca(p->prox,p->lin,p->col,&ant);
			}
		}
	}
}

void excluirLinhaInteira(MATRIZ *m, int i) {
	for(int j = 1; j <= MAXCOL; j++) {
		NO* p = m->col[j];
		NO* ant = NULL;
		while(p) {
			if(p->lin > i) 
				break;
			if(p->lin == i) {
				if(ant)
					ant->proxC = p->proxL;
				else 
					m->col[j] = p->proxL;
				free(p);
				break;
				ant = p;
				p = p->prox;
			}
		}
		m->lin[i] = null;
	}
}


//2 a)transformar uma pilha dinâmica em uma fila.
//  b)dada uma fila, converter em pilha;

typedef struct s {
	TIPOCHAVE chave;
	s *prox;
} NO;

typedef struct {
	NO* topo;
} PILHA;

typedef struct 
{
	NO *inicio;
	NO *fim;
} FILA;

FILA pilhaParaFila(PILHA *p) {
	FILA* f = (FILA*) malloc(sizeOf(FILA));
	f->inicio = p->topo;
	f->inicio->prox = f->fim;
	f->fim = p->topo;
	f->fim->prox = NULL;
	while(p->topo) {
		NO *aux = pop(p->topo);
		f->fim->prox = aux;
		f->fim = aux;
	}

	NO *n = f->inicio;
}



//5)Criar um algoritmo FuraFila para fila dinâmica
//a)Fácil - criando um novo elemento
//b)Movendo o elemento P.

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

void furaFila(Fila *f, TIPOCHAVE chave) {
	NO* ant = f->inicio;
	NO* p = ant->prox
	while(p) {
		if(p->chave == chave) {
			NO *aux = 
		}
	}
	entrarFila(f,chave);
	NO* novo = (NO*) malloc(sizeof(NO));
	novo->chave = chave;
}


// 3)inserir todas chaves de uma lista generalizada no inicio2 de um deque vazio

typedef struct 
{
	NO *inicio1;
	NO *inicio2;
} DEQUE;

enum {elemLista, inicioLista} IDENT;

typedef struct s {
	s* prox;
	IDENT tag;
	union {
		int info;
		s* subLista;
	}
} NO_G;

void entrarInicio2(DEQUE *d, TIPOCHAVE ch) {
	NO *novo =(NO*) malloc(sizeof(NO));
	novo->chave = ch;
	novo->ant = NULL;
	novo->prox = NULL;
	if(!d->inicio1)
		d->inicio1 = novo;
	else
		d->inicio2->ant = novo;
	d->inicio2 = novo;
}

void listaGeneralizadaParaDeque(DEQUE *d, NO_G *no) {
	while(no) {
		if (no->tag == elemLista) {
			entrarInicio2(d,no->info); 
		} else {
			listaGeneralizadaParaDeque(d,no->sublista);
		}
		no = no->prox;
	}
}
