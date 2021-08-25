#include <stdio.h>
#include <string.h>

struct no {
	int info;
	struct no* esquerda;
	struct no* direita;
};
typedef struct no no;

struct no *criarArvore(int num, no *dir, no *esq)
{
	no *raiz;

	raiz = malloc(sizeof(struct no));
	raiz->info = num;
	raiz->esquerda = esq;
	raiz->direita = dir;
	return (raiz);
}


struct no *inserir(int num, no *arvore)
{
	if (arvore == NULL)
		arvore = criarArvore(num, NULL, NULL);
	else {
		if(num <= arvore->info) {
			arvore->esquerda = inserir(num, arvore->esquerda);
		}
		else {
			arvore->direita = inserir(num, arvore->direita);
		}
	}
	return(arvore);
}

void encaminhamentoPreordem(no* x)
{
	if (x != NULL) {
		printf(" %d", x->info);
		encaminhamentoPreordem(x->esquerda);
		encaminhamentoPreordem(x->direita);
	}
}

void encaminhamentoInOrdem (no* x)
{
	if (x != NULL) {
		encaminhamentoInOrdem(x->esquerda);
		printf(" %d", x->info);
		encaminhamentoInOrdem(x->direita);
	}
}

void ecaminhamentoPosOrdem (no* x)
{
	if (x != NULL) {
		ecaminhamentoPosOrdem(x->esquerda);
		ecaminhamentoPosOrdem(x->direita);
		printf(" %d", x->info);
	}
}
int main(void)
{
	no* arvore;
	arvore = NULL;
	int c, n, info, cas = 1, i, r;

	scanf("%d", &c);
	
	while(r < c) {
		arvore = NULL;
		scanf("%d", &n);

		for (i = 0; i < n; i++) {
			scanf("%d", &info);
			arvore = inserir(info, arvore);
		}

		printf("\n");
		printf("Case %d:", cas);
		printf("\n");

		printf("Pre.:");
		encaminhamentoPreordem(arvore);
		printf("\n");

		printf("In..:");
		encaminhamentoInOrdem(arvore);
		printf("\n");

		printf("Post:");
		ecaminhamentoPosOrdem(arvore);
		printf("\n");

		cas += 1;
		r += 1;
	}
	
}
