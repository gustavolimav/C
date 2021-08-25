// struct no {
//     int valor;
//     struct no *esquerda;
//     struct no *direita;
//     struct no *pai;
// };

// struct no criarArvore (int valor, struct no *esq, struct no *dir)
// {
//     struct no raiz;
//     raiz <- aloque(no); // raiz = malloc(sizeof(struct no));
//     raiz->info <- info;// raiz->info = info
//     raiz->esquerda <- esq;
//     raiz->direita <- dir;

//     return (raiz);
// }

// struct no inserir(int valor, struct no arvore)
// {
//     if (arvore == NULL)
//         arvore <-criarArvore(info, NULL, NULL);
//     else {
//         if (valor <= arvore->info){
//             arvore->esquerda = inserir(valor, arvore->esquerda)
//             arvore->esquerda->pai = arvore
//         } else {
//             arvore->direita = inserir(valor, arvore->direita)
//             arvore->direita->pai = arvore
//         }
//     }
//     return(arvore)
// }


