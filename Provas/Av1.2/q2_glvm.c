// SPDX-License-Identifier: BSD-3-Clause
// Copyright (c) 2015-2017, ARM Limited and Contributors. All rights reserved.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct lista {
	char *valor;
	struct lista *next;
};
struct a {
	struct lista *head;
	struct lista *current;
};
void adicionar(struct a *aux, char *token)
{
		struct lista *atual = malloc(sizeof(struct lista));
		struct lista *ver;

		atual->valor = token;
		ver = aux->head;
		if (aux->head != NULL) {
			while (ver != NULL) {
				if (strcmp(ver->valor, token) == 0)
					return 0;
				ver = ver->next;
		}	}
		if (aux->head == NULL) {
			aux->head = atual;
			aux->current = atual;
			aux->current->next = NULL;
		} else {
			aux->current->next = malloc(sizeof(struct lista));
			aux->current->next = atual;
			aux->current = atual;
			aux->current->next = NULL;
		}
}
void imprimir(struct a *aux)
{
		struct lista *atual;

		atual = aux->head;
		printf("\n");
		while ((atual != NULL) && (atual->next != NULL)) {
			printf("%s ", atual->valor);
			atual = atual->next;
		}
		printf("%s", atual->valor);
}
void deleta(struct lista *head)
{
		struct lista *del, *aux;

		aux = head;
		while (aux != NULL) {
			del = aux->next;
			free(aux);
			aux = del;
		}
}
void ordenar(struct lista **l)
{
		struct lista *aux = *l;
		struct lista *a;
		char *s;

		while (aux != NULL) {
			a = aux->next;
			while (a != NULL) {
				if (strcmp(aux->valor, a->valor) > 0) {
					s = aux->valor;
					aux->valor = a->valor;
					a->valor = s;
			}
			a = a->next;
		}
		aux = aux->next;
		}
}
int main(void)
{
		struct a *aux;
		char text[10000];
		char *token;
		int i = 0, n;
		struct lista *list_aux;

		scanf("%d", &n);
		while (i <= n) {
			aux = malloc(sizeof(struct a));
			aux->head = NULL;
			aux->current = NULL;
			list_aux = aux->head;
			fgets(text, 10000, stdin);
			token = strtok(text, " ");
			while (token != NULL) {
				token[strcspn(token, "\n")] = 0;
				adicionar(aux, token);
				token = strtok(NULL, " ");
			}
			ordenar(aux);
			imprimir(aux);
			deleta(aux);
			free(token);
			i += 1;
		}
}
