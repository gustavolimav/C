#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct fila1
{
	int id;
	int idade;
	struct fila1 *next;
};
int i;

struct fila2
{
	int id;
	int idade;
	struct fila2 *next;
};

int main(void)
{
	struct fila1 *head;
	struct fila1 *current;
	struct fila1 *volta;
	
	struct fila2 *head2;
	struct fila2 *current2;
	
	head = NULL;
	head2 = NULL;
	
	char option[1];
	int id, idade, x = 0, x2 = 0, contador = 0, y = 1;
	int n;
	i = 0;
	scanf("%d", &n);
	
	while(y != 0){
		
		scanf("%s", &option);
		y = strcmp(option, "f");
		if(strcmp(option, "a")== 0){
			
			scanf("%d %d", &id, &idade);

			if (idade > 60){
				if (head == NULL){
					head = malloc(sizeof(struct fila1));
					current = head;				
					head->id = id;
					head->idade = idade;
					head->next = malloc(sizeof(struct fila1));
					head->next = NULL;
				
				}else{
					current->next = malloc(sizeof(struct fila1));
					current = current->next;
					current->next = NULL;
		
					current->id = id;
					current->idade = idade;
				}
				
			}else{
		
				if (head2 == NULL){
					head2 = malloc(sizeof(struct fila2));
					current2 = head2;
					head2->id = id;
					head2->idade = idade;
					head2->next = malloc(sizeof(struct fila2));
					head2->next = NULL;
					
				}else{
					current2->next = malloc(sizeof(struct fila2));
					current2 = current2->next;
					current2->next = NULL;
		
					current2->id = id;
					current2->idade = idade;
				
			}

			}			
			
		}else if(strcmp(option, "r")== 0){
			if((contador < n ) && (head != NULL)){
				volta = head;
				head = head->next;
				free(volta);
				contador += 1;
			}else{
				if(head2 != NULL){
					volta = head2;
					head2 = head2->next;
					free(volta);
					contador = 0;
				}
		}
		
		
		}else if(strcmp(option, "i")== 0){
			
			imprimir1(head, head2);
		}
	}
	
	return 0;
}


void imprimir1(struct fila1 *head, struct fila2 *head2)
{
	printf("fila de idosos:\n");
	if(head == NULL){
		printf("fila vazia!\n");
	}
	while (head != NULL){
		printf("ID: %d IDADE: %d\n", head->id, head->idade);
		head = head->next;
	}
	printf("fila de nao-idosos:\n");	
	if(head2 == NULL){
		printf("fila vazia!\n");
	}
	while (head2 != NULL){
		if(head2->idade <= 60){
			printf("ID: %d IDADE: %d\n", head2->id, head2->idade);
		}
		head2 = head2->next;
	}
	printf("----------\n\n");
}