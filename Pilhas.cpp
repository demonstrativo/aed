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
	if()
}