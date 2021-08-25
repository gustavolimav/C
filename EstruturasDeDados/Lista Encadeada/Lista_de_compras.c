#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct nod
	{
		char *nome;
		float preco;
		int quantidade;
		struct nod *next;
	};
typedef struct nod no;

void consulta(no *current) 
{
	float preco_soma = 0;
	
	while(current !=NULL){
		preco_soma = (current->preco) * (current->quantidade) + preco_soma;
		current = current->next;
		}
	printf("\nAtualmente a lista esta em R$%.1f\n", preco_soma);
}
void procurar(no *current, char nome[20])
{
    int x = 0;
	while(current != NULL){
		if (strcmp(current->nome, nome)== 0){
		    if (current->quantidade == 0){
		    printf("\n%s nao foi encontrado.\n", nome);
		    x = 1;
	        }
	        else{
			    printf("\n%s\n", current->nome);
			    printf("- %.1f\n", current->preco);
			    printf("- %d\n", current->quantidade);
			    x= 1;
	        }
		}
		current = current->next;
	}
	if(x == 0){
	    printf("\n%s nao foi encontrado.\n", nome);
	}
}
void remover(no *current, char nome[20], int quant)
{
	while(current != NULL){
		if(strcmp(current->nome, nome)==0){
				current->quantidade = current->quantidade - quant;
		}
		current = current->next;
	}

}
void removergrupo(no *current, float preco) 
{
	while (current != NULL){
		if(current->preco > preco){
			current->quantidade = 0;
		}
		current = current->next;
	}
}
int main(void){	
	
	int x= 1, y, quantidade;
	char words[20], nome[20];
	no *head;
	no *current;
	
	head = malloc(sizeof(no));
	current = head;

	while(scanf("%s", words) != EOF)
	{
		if (strcmp(words, "INSERIR")== 0)
		{
			if(x == 1){
				
				head->nome = malloc(sizeof(char*));
				scanf("%s", head->nome);
				
				scanf("%f", &head->preco);
				
				scanf("%d", &head->quantidade);
				
				x += 1;
				
			}else{
				
				current->next = malloc(sizeof(no));
				current = current->next;
				current->next = NULL;

				current->nome = malloc(sizeof(char*));
				scanf("%s", current->nome);

    			scanf("%f", &current->preco);
    			
    			scanf("%d", &current->quantidade);
			 
			}
		}else if (strcmp(words, "CONSULTAR")== 0){
			
			consulta(head);
			
		}else if (strcmp(words, "PROCURAR")== 0){
			
			scanf("%s", &nome);
			procurar(head, nome);
			
		}else if (strcmp(words, "REMOVER")==0){
			
			
			scanf("%s", &nome);
			
			scanf("%d", &quantidade);
			
			remover(head, nome, quantidade);
			
		}else if(strcmp(words, "REMOVERGRUPO")==0){
			
			scanf("%d", &quantidade);
			removergrupo(head, quantidade);
		}
	}
	return 0;
}