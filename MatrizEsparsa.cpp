//Tematica mais pesada da matéria
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

typedef struct s{
	int info;
	int lin;
	int col;
	*s prox;
}NO;

typedef struct {
	NO* inicio;
} MATRIZ;


int valor (NO *p, int i, int j) {
	int resp = -1;
	NO* aux = p;
	while(aux) {
		if(aux->lin == i && aux->col == j)
			return aux->info;
		if(aux->lin > i || (aux->lin == i && aux->col > j))
			return resp;
		aux = aux->prox;
	} 
	return resp;
}

int contarZerosColuna (NO *p, int j) {
	int resp = 0;
	while(p) {
		if(p->col == j)
			resp++;
		p = p->prox;
	}
	return  (MAXLIN - resp);
}	

void exibirDiagonal(NO *p) {
	int ult = 0;
	int i;
	while(p) {
		if(p->lin > ult) {
			//exibir todos os 0 antes de p->lin
		}
		//Pesquisar todos os elementos p->lin
		// se acha i == j exibe
		// se nao exibir 0
		ult = p->lin;
	}
}
	//completar com zeros}

void inserir(MATRIZ *M, int val, int i, int j) {
	NO *ant;
	NO *aux = busca(m->inicio,i,j,&ant);
	if(aux && val!=0) {
		aux->info = val;
		return;
	} else if (aux) {
		if(ant)
			ant->prox = aux->prox;
		else
			m->inicio = aux->prox;
		free(aux);
	}

	// inserção
	if(!aux) {
		aux = (NO*) malloc(sizeof(NO));
		aux->info = val;
		aux->lin = i;
		aux->col = j;
		if(ant) {
			aux->prox = ant->prox;
			ant->prox = aux;
		} else {
			anx->prox = m->inicio;
			m->inicio = aux;
		}
	}
}

// DADAS DUAS MATRIZES M1, M2 VERIFICAR SE LINHA I1 DE M1 É IGUAL À LINHA L2 DE M2
bool linhasIguais(MATRIZ *m1,MATRIZ *m2,int i1,int i2) {
	NO *p1 = m1->inicio;
	NO *p2 = m2->inicio;
	while(p1) {
		if(p1->lin >= i1)
			break;
		p1 = p1->prox;
	}

	if(p1 && p1->lin > i1) 
		p1 = NULL;
	
	while(p2) {
		if(p2->lin >= i2)
			break;
		p2 = p2->prox;
	}
	
	if(p2 && p2->lin > i1)
		p2 = NULL;

	if(!p1 && !p2)
		return true;
	if(!p1 || !p2)
		return false;

	while(p1 && p2) {
		if(p1->info != p2->info ||
			p1->lin != p2->lin   ||
			p1->col != p2->col)
			return false;
		p1 = p1->prox;
		p2 = p2->prox;
		if(p1->lin != p2->lin)
			return false;
		if(p1->lin > i1)
			break;
		if(p2->lin > i2)
			break;
	}

	if(!p1 && !p2) 
		return true;
	if(p1 && p2 && p1->lin > i1 && p2->lin > i2)
		return true;
	else if(p1 && p2)
		return false;
	if(p1 && p1->lin > i1)
		return true;
	if(p2 && p2->lin > i2)
		return true;
	return false;
}

bool ehQuadrada(MATRIZ *m) {
	NO* p = m->inicio;
	int maxLin = 0;
	int maxCol = 0;
	while(p) {
		if(p->lin > maxLin)
			maxLin = p->lin;
		if(p->col > maxCol)
			maxCol = p->col;
		p = p->prox;
	}

	if(maxLin == maxCol)
		return true;
	return false;
}

// FAZER EXCLUSÃO DA DIAGONAL PRINCIPAL
bool excluirDiagonalPrincipal(MATRIZ *m) {
	if(ehQuadrada(m)) {
		NO *ant;
		NO *p = busca(m->inicio,i,j,&ant);
		while(p) {
			if(p->lin == p->col) {
				ant->prox = p->prox;
				free(p);
				p = busca(ant->prox,ant->prox->lin,ant->prox->col,&ant);
			} else {
				p = busca(p->prox,p->lin,p->col,&ant);
			}
		}
		return true;
	} else {
		return false;	
	}
}

// FAZER EXCLUSÃO DA LINHA I INTEIRA
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

// LISTAS CRUZADAS

typedef struct s {
	int info;
	int lin;
	int col;
	*s proxC;
	*s proxL;
}NO;


typedef struct {
	NO * lin[MAXLIN+1];
	NO * col[MAXCOL+1];
}

void inicializar(MATRIZ *m) {
	int i;
	for(int i=1;i<=MAXLIN;i++) {
		m->lin[i] = NULL;
	}
	for(int i=1;i<=MAXCOL;i++) {
		m->col[i] = NULL;
	}
}

int contarElmLinhai(MATRIZ *m,int i) {
	int cont = 0;
	NO *p = m->lin[i];
	while(p) {
		cont++;
		p = p->proxC;
	}
	return cont;
}

int contarZerosDiagonal(MATRIZ *m) {
	int resp = MAXCOL;
	int i;
	for(i = 1;i<=MAXLIN; i++) {
		NO *p = m->lin[i];
		while(p) {
			if(p->l == p->c) {
				resp--;
			}
			p = p->proxC;
		}
	}
	return resp;
}

bool compararLinCol(Matriz *m, int i,int j) {
	NO* p1 = m->lin[i];
	NO *p2 = m->col[j];
	while(p1 & p2) {
		if(p1->info != p2->info ||
			p1->lin != p2->col
			p1>col != p2->lin)
			return false;
		p1 = p1->proxC;
		p2 = p2->proxL;
	}
	if(!p1 && !p2)
		return true;
	return false;
}

NO *busca(MATRIZ *m, int i, int j, NO **esq, NO **acima){
	*esq = NULL;
	*acima = NULL;
	// IMPLEMENTAR
}

void excluir(MATRIZ *m, int i, int j) {
	NO *esq;
	NO *acima;
	NO *atual = busca(m,i,j,&esq,&acima);
	if(!atual)
		return;
	if(esq)
		esq->proxC = atual->proxC;
	else
		m->lin[i] = atual->proxC;
	if(acima)
		acima->proxL = atual->proxL;
	else
		m->col[j] = atual->proxL;
	free(atual);
}

void inserir(MATRIZ *m, int x, int i, int j) {
	NO* esq;
	NO* acima;
	NO *atual = busca(m,i+1,j,&esq,&acima);
	
	if(atual) {
		atual->info = x;
		return;
	}
	atual = (NO*) malloc(sizeof(NO));
	atual->info = x;
	atual->l = i+1;
	atual->c = j;
	if(esq) {
		atual->proxC = esq->proxC;
		esq->proxC = atual;
	} else {
		atual->proxC = m->lin[i+1];
		m->lin[i+1] = atual;
	}
	// falta atualizar colunas

}

// EXERCICIOS
// 1 - Exibir os valores ao redor de x
// 2 - Atribuir valor 1 a estes pontos
// 3 - Descobrir qual a maior distância entre 2 pontos em uma mesma linha retornando os 2 pontos