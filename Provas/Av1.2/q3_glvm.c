// SPDX-License-Identifier: BSD-3-Clause
// Copyright (c) 2015-2017, ARM Limited and Contributors. All rights reserved.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct lista {
		int valor;
		struct lista *prox;
};

struct fila {
		struct lista *head;
		struct lista *current;
};

void empilhar(struct fila *aux, int data)
{
		struct lista *atual = malloc(sizeof(struct lista));

		atual->valor = data;
		if (aux->head == NULL) {
			aux->head = atual;
			aux->current = atual;
			aux->current->prox = NULL;
		} else {
			atual->prox = aux->head;
			aux->head = atual;
		}
}

void desempilhar(struct fila *aux, int data)
{
		struct lista *atual;
		struct lista *anterior, *auxiliar;

		anterior = aux->head;
		atual = anterior->prox;
		int flag = 0;

		if (anterior->valor == data) {
			aux->head = anterior->prox;
			free(anterior);
			flag = 1;
		}
		if (flag != 1) {
			while (atual->valor != data) {
				anterior = anterior->prox;
				atual = atual->prox;
			}
			auxiliar = atual;
			atual = atual->prox;
			free(auxiliar);
			free(atual);
			auxiliar->prox = NULL;
		}
}

void imprimir(struct fila *aux)
{
		struct lista *atual;

		atual = aux->head;
		while ((atual != NULL) && (atual->prox != NULL)) {
			printf("%d ", atual->valor);
			atual = atual->prox;
		}
		printf("%d\n", atual->valor);
}
void desalocar(struct fila *aux)
{
		struct lista *atual;
		struct lista *anterior;

		while (aux->head != NULL) {
			anterior = aux->head;
			aux->head = anterior->prox;
			free(anterior);
		}
}
int main(void)
{
		struct fila *aux;
		int valor;
		char option[11];
		struct lista *list_aux;

		list_aux = aux->head;
		aux = malloc(sizeof(struct fila));
		aux->head = NULL;
		aux->current = NULL;

		for (; ;) {
			scanf("%s", option);
			if (strcmp(option, "Finalizar") == 0) {
				desalocar(aux);
				free(aux);
				return 0;
			} else if (strcmp(option, "Desempilhar") == 0) {
				list_aux = aux->head;
				desempilhar(aux, list_aux->valor);
			} else if (strcmp(option, "Imprimir") == 0) {
				imprimir(aux);
			} else if (strcmp(option, "Empilhar") == 0) {
				scanf("%d", &valor);
				empilhar(aux, valor);
			}
		}
}
