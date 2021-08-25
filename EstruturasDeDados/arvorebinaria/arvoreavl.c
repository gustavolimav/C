#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct no
{
	int info;
	struct no* esquerda;
	struct no* direita;
	int altura;
};

int altura(struct no *no)
{
	if (no == NULL) {
		return 0;
	} else {
		return no->altura;
	}
}

void alturaatualizada (struct no *no)
{
	int altdir, altesq;

	if (no != NULL) {
		altdir = altura(no->direita);
		altesq = altura(no->esquerda);
		no->altura = maximo(altdir, altesq) + 1;
	}
}
int maximo(int altdir, int altesq) {
	int m;
	
	if (altdir > altesq)
		m = altdir;
	else
		m = altesq;
	
	return m;
}
struct no *rotesq(struct no *raiz)
{
	struct no *aux;
	
	aux = malloc(sizeof(struct no));
	aux = raiz->direita;
	raiz->direita = aux->esquerda;
	aux->esquerda = raiz;
	alturaatualizada(raiz->esquerda);
	alturaatualizada(raiz);
	return (aux);
}

struct no *rotdir(struct no *raiz)
{
	struct no *aux;

	aux = malloc(sizeof(struct no));
	aux = raiz->esquerda;
	raiz->esquerda = aux->direita;
	aux->direita = raiz;
	alturaatualizada(raiz->direita);
	alturaatualizada(raiz);
	return (aux);
}

struct no *rotduplaesq (struct no *raiz)
{
 struct no *resultado;

 resultado = malloc(sizeof(struct no));
 raiz->direita = rotdir(raiz->direita);
 resultado = rotesq(raiz);
 return (resultado);   
}

struct no *rotdupladir (struct no *raiz)
{
 struct no *resultado;

 resultado = malloc(sizeof(struct no));
 raiz->esquerda = rotesq(raiz->esquerda);
 resultado = rotdir(raiz);
 return (resultado);   
}
void imprimir(struct no *x)
{
	if (x) {
		printf("   ( %d ", x->info);
		imprimir(x->esquerda);
		imprimir(x->direita);
		printf(") ");
	} else {
		printf(" () ");
	}
	return;
}
struct no *inserirAVL (int valor, struct no *raiz)
{
	if (raiz == NULL) {
		raiz = malloc(sizeof(struct no));
		raiz->info = valor;
		raiz->esquerda = NULL;
		raiz->direita = NULL;
		raiz->altura = 1;
		printf("Continuou AVL...\n");
	} else {
		if (valor < raiz->info) {
			raiz->esquerda = inserirAVL(valor, raiz->esquerda);
			if ((altura(raiz->esquerda)) - (altura(raiz->direita)) == 2) {
				printf("Antes de ajustar balanceamento...\n");
				imprimir(raiz);
				if (valor < raiz->esquerda->info) {
					raiz = rotdir(raiz);

				} else {
					raiz = rotdupladir(raiz);
				}
				printf("Depois de ajustar balanceamento...\n");
			}
		} else {
			raiz->direita = inserirAVL(valor, raiz->direita);
			if ((altura(raiz->direita)) - (altura(raiz->esquerda)) == 2) {
				printf("Antes de ajustar balanceamento...\n");
				imprimir(raiz);
				if (valor >= raiz->direita->info) {
					raiz = rotesq(raiz);
					
				} else {
					raiz = rotduplaesq(raiz);
				}
				printf("Depois de ajustar balanceamento...\n");
			}
		}
		alturaatualizada(raiz);
	}
	return raiz;
}

int main () {
	struct no *no = NULL;
	int valor;

	while (scanf("%d", &valor) == 1) {
		printf("----\nAdicionando %d\n", valor);
		no = inserirAVL(valor, no);
		imprimir(no);
	}
	return 0;
}

//  printf("Antes de ajustar balanceamento...\n");
// 	printf("Depois de ajustar balanceamento...\n");
// 	printf("Continuou AVL...\n");
