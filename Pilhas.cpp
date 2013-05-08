#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

#define MAX 500;
typedef int TIPOCHAVE;

/* 
PILHA ESTRUTURA DO TIPO
FILO
FIRST IN LAST OUT

*/

typedef struct s {
	TIPOCHAVE chave;
	s *prox;
} NO;

typedef struct {
	NO* topo;
} PILHA;

void inicializar(PILHA *p) {
	p->topo = NULL;
}

void push(PILHA *p, TIPOCHAVE ch) {
	NO *novo = (NO*) malloc(sizeof(NO));
	novo->chave = ch;
	if(p->topo)
		novo->prox = p->topo;
	}
	p->topo = novo;
}

TIPOCHAVE pop (PILHA *p) {
	TIPOCHAVE resp = -1;
	if(!p->topo)
		return resp;
	resp = p->topo->chave;
	NO *aux = p->topo;
	p-topo = p->topo->prox;
	free(aux);
	return resp;
}

typedef struct {
	int topo;
	TIPOCHAVE A[MAX];
};

void inicializar(PILHA *p) {
	p->topo = -1;
}

bool push (PILHA *p, TIPOCHAVE ch) {
	if(pilhaCheia(&p))
		return false; //OVERFLOW
	p->topo = p->topo + 1;
	p->A[p->topo] = ch;
	return true;
}

TIPOCHAVE pop(PILHA *p) {
	TIPOCHAVE resp = -1;
	if(p->topo != -1) {
		resp = p->A[p->topo];
		p->topo--;
	}
	return resp;
}

// Pilhas multiplas... aqui começa uma pequena parte do inferno :)

typedef struct {
	TIPOCHAVE A[MAX];
	int topo1;
	int topo2;
} DUASPILHAS;

void inicializar(DUASPILHAS *p) {
	p->topo1 = -1;
	p->topo2 = MAX;

	// DO LIMITE INFERIOR AO SUPERIOR
}

bool pilhaCheia (DUASPILHAS *p) {
	if((p->topo1 + 1)>= p->topo2) {
		return true;
	}
	return false;
}

bool push(DUASPILHAS *p, TIPOCHAVE ch, int k) {
	if(pilhaCheia(*p)) {
		return false; //OVERFLOW
	}
	if(k==1) {
		p->topo1 = p->topo1 + 1;
		p->A[p->topo1] = ch;
	} else {
		p->topo2 = p->topo2 - 1;
		p->A[topo2] = ch;
	}
	return true;
}

TIPOCHAVE pop(DUASPILHAS *p. int k) {
	TIPOCHAVE resp = -1;
	if(k == 1) {
		if(p->topo1 >= 0) {
			resp = p->A[p->topo1];
			p->topo1 = p->topo1 - 1;
		}
	} else if (k == 2) {
		if(p->topo2 < MAX) {
			resp = p->A[p->topo2];
			p->topo2 = p->topo2 + 1;
		}
	}
	return resp;
}

// PILHA NP PILHA PARTE DA MATÉRIA QUE AO LADO DE MATRIZES ESPARSAS É CAMPEÃ EM F@#$ OS ALUNOS

#define NP 5
#define MAX 15

typedef struct {
	TIPOCHAVE A[MAX];
	int topo[NP+1];
	int base[NP+1];
} NPPILHAS;

void inicializar(NPPILHAS *p) {
	int i;
	for(i =0; i<NP; i++) {
		p->base[i] = ((MAX/NP) * i) - 1; // FATIANDO O BOLO
		p->topo[i] = p->base[i];
	}
}

bool pilhaKCheia(NPPILHAS *p, int k) {
	if(p->topo[k] == p->base[k+1])
		return true;
	else 
		return false;
}

TIPOCHAVE popK(NPPILHAS *p, int k) {
	TIPOCHAVE resp = -1;
	if(!(p->base[k] == p->topo[k])) {
		resp = p->topo[k];
		p->topo[k]--;
	}	
	return resp;
}

void deslocarKparaDireita(NPPILHAS *p, int k) {
	if(k < 1 || k > (NP+1))
		return;
	if(pilhaKCheia(p,k))
		return;
	int i;
	for(i = p->topo[k]; i>p->base[k]; i--) {
		p[i+1] = p->A[i];
	}
	p->topo[k]++;
	p->base[k]++;
}

bool pushK(TIPOCHAVE ch, PILHAS *p, int k) { 
	int j; 
	if( (pilhaKcheia(*p, k)) && (k < NP-1) ) 
	 // desloca p/direita todas as pilhas de [k+1..NP-1] em ordem reversa 
		for( j = NP-1; j > k; j--) 
			deslocarKparaDireita(p, j); 
	if( (pilhaKcheia(*p, k)) && (k > 0)) 
	 // desloca p/esquerda todas as pilhas de [1..k] (mas não a pilha 0) 
		for( j = 1; j <= k; j++) 
			deslocarKparaEsquerda(p, j); 
	if(pilhaKcheia(*p, k)) 
		return(false); 
	p->topo[k]++; 
	p->A[p->topo[k]] = ch; 
	return(true); 
}