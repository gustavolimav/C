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

void limpar(struct lista *aux)
{
	struct lista *del;

	while (aux != NULL) {
		del = aux;
		aux = aux->next;
		free(del);
	}
	free(aux);
}
int main(void)
{
		struct lista *head;
		struct lista *current;
		struct lista *aux;
		struct lista *del;
		int cont = 0, entrada = 0, saida = 0, ter;
		char str[80], strr[80];
		char *token;

		head = malloc(sizeof(struct lista));
		current = head;
		head->next = NULL;
		fgets(str, 100000, stdin);

		token = strtok(str, " ");

		while (token != NULL) {
			if (head->next == NULL) {
				head->valor = token;
				head->next = malloc(sizeof(struct lista));
			} else {
				current->next = malloc(sizeof(struct lista));
				current = current->next;
				current->valor = token;
				current->next = NULL;
			}
			entrada += 1;
			token = strtok(NULL, " ");
		}
		token = strtok(str, " ");
		if (token == NULL) {
			printf("Fila de entrada vazia");
			free(head);
			free(current);
			return 0;
		}

		fgets(strr, 100000, stdin);

		token = strtok(strr, " ");
		while (token != NULL) {
			saida += 1;
			aux = head;
			del = head;
			ter = 0;
			while (aux != NULL) {
				if (strcmp(aux->valor, token) == 0) {
					ter = 1;
					if (aux == head) {
						head = aux->next;
						free(aux);
						break;
					} else if (aux != head) {
						aux = aux->next;
						del->next = aux;
						break;
					}
				}
				del = aux;
				aux = aux->next;
			}
			token = strtok(NULL, " ");
		}
		if (saida > entrada) {
			printf("Fila de saida maior que a de entrada");
			limpar(head);
			free(head);
			free(current);
			return 0;
		}
		if (ter == 0) {
			printf("Impossivel tirar pessoa inexistente da fila");
			limpar(head);
			free(head);
			free(current);
			return 0;
		}
		aux = head;
		while (aux != NULL) {
			printf("%s ", aux->valor);
			aux = aux->next;
		}
		limpar(head);
		free(head);
		free(current);
		return 0;
}