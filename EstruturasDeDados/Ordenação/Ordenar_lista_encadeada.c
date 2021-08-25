#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct list
{
	int numero;
	struct list *next;
};
void imprimir(struct list *head)
{
	while(head != NULL){
		printf("%d ", head->numero);
		head = head->next;		
	}
}	

struct list *ordemCrescente(struct list *p) {

    struct list *aux = p;
    struct list *t;
    int c;

    if (p == NULL || p->next == NULL)
        return NULL;

    while (aux != NULL) {
        t = aux->next;
        while (t != NULL) {
            if (aux->numero > t->numero) {
                c = aux->numero;
                aux->numero = t->numero;
                t->numero = c;
            }
            t = t->next;
        }
        aux = aux->next;
    }

    return p;
}

int main(void) {

	int entrada, i = 1;
	struct list *head = NULL;
	struct list *current = NULL;
	struct list *save, *save2;
	
	while (scanf("%d", &entrada) != EOF) {
		if (head == NULL) {

			head = malloc(sizeof(struct list));
			head->numero = entrada;
			current = head;
			head->next = NULL;

		} else {
			save = current;
			current->next = malloc(sizeof(struct list));
			current = current->next;
			current->next = NULL;
			current->numero = entrada;
		}
	}

	head = ordemCrescente(head);
	imprimir(head);
	
	return 0;
}	
