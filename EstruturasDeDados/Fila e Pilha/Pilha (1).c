#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct pilha
{
	int valor;
	struct pilha *next;	
};

int main(void)
{
	char option[4];
	int x =0, diferenca;
	struct pilha *head;
	struct pilha *novo;
	struct pilha *percorrer;
		
	while(scanf("%s", option)!= EOF){
		
		int maior = -1, menor = 1001;
		
		if(strcmp(option, "push")==0){
			if (head!= NULL){

				if (x ==0){
					head = malloc(sizeof(struct pilha));
					scanf("%d", &head->valor);
					head->next = NULL;
					x+=1;
				}else{
	
					novo = malloc(sizeof(struct pilha));
					scanf("%d", &novo->valor);
					novo->next = head;
					head = novo;
			
			}
		}else{
		    head = malloc(sizeof(struct pilha));
			scanf("%d", &head->valor);
			head->next = NULL;
		}
		}else if(strcmp(option, "pop")==0){
			if (head!= NULL){

			    percorrer = head;
				head = head->next;
				printf("%d\n", percorrer->valor);
				free(percorrer);
		}
		}else if(strcmp(option, "abs")==0){
			if (head!= NULL){
			
				percorrer = head;
				while(percorrer != NULL)
				{
					if(percorrer->valor > maior){
						maior = percorrer->valor;
				}
					if(percorrer->valor < menor){
						menor = percorrer->valor;
				}
					percorrer = percorrer->next;
		 	}
		 		diferenca = maior- menor;
		 		printf("%d\n", diferenca);
		}
	}
}
	
	
	return 0;
}