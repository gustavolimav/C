#include <stdio.h>
#include <string.h>

struct no {
    int info;
    struct no* esquerda;
    struct no* direita;
};
typedef struct no no;

int criarArvore(int num, no *dir, no *esq)
{
    no *raiz;

    raiz = malloc(sizeof(no));
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
        printf("%d", x);
        encaminhamentoPreordem(x->esquerda);
        encaminhamentoPreordem(x->direita);
    }
}

void encaminhamentoInOrdem (no* x)
{
    if (x != NULL) {
        encaminhamentoInOrdem(x->esquerda);
        printf("%d", &x);
        encaminhamentoInOrdem(x->direita);
    }
}

void ecaminhamentoPosOrdem (no* x)
{
    if (x != NULL) {
        ecaminhamentoPosOrdem(x->esquerda);
        ecaminhamentoPosOrdem(x->direita);
        printf("%d", &x);
    }
}

// int buscar_no(no* arvore, int valor)
// {
//     if (arvore == NULL) {
//         return(NULL);
//     } else {
//         if (valor == arvore->info) {
//             return(arvore);
//         }
//         if (valor < arvore->info) {
//             return(buscar_no(arvore->esquerda, valor));
//         } else {
//             return(buscar_no(arvore->direita, valor));
//         }
//     }
// }

// no *maiordireita(no *no)
// {
//     if(no->direita != NULL){
//         return maiordireita(no->direita);
//     } else {
//         no *aux = no;

//         if (no->esquerda != NULL){
//             no = no->esquerda;
//         } else {
//             no = NULL;
//             return aux;
//         }
//     }
// }

// no *menoresquerda(no *no)
// {
//      if(no->esquerda != NULL) {
//        return MenorEsquerda(no->esquerda);
//     }
//     else
//     {
//         No *aux = no; 
//         if(no->direita != NULL) {
//           no = no->direita;
//         } else {
//           no = NULL;
//         }
//         return aux;
//     }
// }
// void remove(no* raiz, int x)
// {
//     no* no;
//     no* aux;
//     aux = raiz;
//     no = buscar_no(arvore, x);
//     if (no == NULL)
//         return;
//     if (numero < raiz->info)
//         remove(raiz->esquerda, x);
//     else 
//         if(numero > raiz->info)
//             remove(raiz->direita, x);
//         else {
//             if ((raiz->esquerda == NULL) && (raiz->direita == NULL)) {
//                 free(aux);
//                 raiz = NULL;
//             }
//             else {
//                 if (raiz->esquerda == NULL) {
//                     raiz = raiz->direita;
//                 }
//             }
//         }
        
//     }
// }
int main(void)
{
    no* arvore;
    int n, info, cas = 1, i;

    
    scanf("%d", &n);
    for (i = 0; i <= n; i++) {
        scanf("%d", &info);
        inserir(info, arvore);
    }
    printf("Case ", cas);
    printf("Pre.: ");
    printf("\n");
    encaminhamentoPreordem(arvore);
    printf("In..: ");
    printf("\n");
    encaminhamentoInOrdem(arvore);
    printf("Post:");
    printf("\n");
    ecaminhamentoPosOrdem(arvore);

    cas += 1;
}
