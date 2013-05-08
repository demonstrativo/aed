
// 1)dada uma matriz esparsa, excluir uma linha inteira

typedef struct s{
	int info;
	int lin;
	int col;
	*s prox;
} NO_LINHAS;

typedef struct {
	NO_LINHAS* inicio;
} MATRIZ_LINHAS;


typedef struct s {
	int info;
	int lin;
	int col;
	*s proxC;
	*s proxL;
} NO_CRUZADAS;

typedef struct {
	NO_CRUZADAS* lin[MAXLIN+1];
	NO_CRUZADAS* col[MAXCOL+1];
} MATRIZ_CRUZADAS;

void excluirLinhaInteira(MATRIZ_LINHAS *m, int linha) {
	NO_LINHAS* p = m->inicio;
	while(p) {
		if(p->lin == linha) {
			NO_LINHAS *aux = p;
			p = p->prox;
			free(aux); // talvez o p = p->prox posso ficar direto no final... mas fiquei com medo de perder a referencia e etc...
		} else if(p->lin > linha) {
			break;
		} else {
			p = p->prox;
		}
	}
}

void excluirLinhaInteira(MATRIZ_CRUZADAS *m, int linha) {
	NO_CRUZADAS* p = m->lin[linha];
	while(p) {
		if(p->lin == linha) {
			NO_LINHAS *aux = p;
			p = p->proxC;
			free(aux); // talvez o p = p->prox posso ficar direto no final... mas fiquei com medo de perder a referencia e etc...
		} else if(p->lin > linha) {
			break;
		} else {
			p = p->prox;
		}
	}
}