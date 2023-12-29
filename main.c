#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

int main() {
    tNode *arvore = NULL;
    int escolha;
    do {
        printf("-----------------------------------------------------\n");
        printf("1. iniciar uma árvore\n");
        printf("2. inserir elemento na árvore\n");
        printf("3. consultar elemento na árvore\n");
        printf("4. remover elemento da árvore\n");
        printf("5. listar elementos da árvore\n");
        printf("6. esvaziar árvore e destruir árvore\n");
        printf("-----------------------------------------------------\n");
        printf("escolha sua operacao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                arvore = createTree();
                if (arvore != NULL) {
                    printf("árvore iniciada com sucesso!\n");
                } else {
                    printf("falha ao iniciar a árvore!\n");
                }
                break;

            case 2:
                if (arvore != NULL) {
                    int dado = 0;
                    printf("digite o dado: ");
                    scanf("%d", &dado);

                    int *dadoAlocado = (int *)malloc(sizeof(int));
                    if (dadoAlocado != NULL) {
                        *dadoAlocado = dado;
                        void *dadoCast = (void *)dadoAlocado;

                        if (InsertTree(arvore, dadoCast, cmpInt) != NULL) {
                            printf("dado inserido com sucesso!!!\n");
                        } else {
                            printf("falha ao inserir o dado!\n");
                        }
                    } else {
                        printf("falha ao alocar memória para o dado!\n");
                    }
                } else {
                    printf("árvore ainda não iniciada!\n");
                }
                break;

            case 3:
                if (arvore != NULL) {
                    int dadoPesq = 0;
                    printf("digite o dado a ser pesquisado: ");
                    scanf("%d", &dadoPesq);
    
                    // Não é necessário alocar memória extra para dadoPesq
                    if (consultarArvore(arvore, &dadoPesq, cmpInt) == TRUE) {
                        printf("dado presente na árvore!\n");
                    } else {
                        printf("dado não presente na árvore\n");
                    }
                } else {
                    printf("árvore não criada!!!\n");
                }
                break;


            case 4:
                if (arvore != NULL) {
                    int dadoRem = 0;
                    printf("digite o elemento a ser removido: ");
                    scanf("%d", &dadoRem);

                    if ((arvore = removeElm(arvore, (void*)&dadoRem, cmpInt)) != NULL) {
                        printf("dado removido com sucesso!!!\n");
                    } else {
                        printf("falha ao remover o dado!\n");
                    }
                } else {
                    printf("árvore não criada\n");
                }
                break;

            case 5:
                if (arvore != NULL) {
                    printf("elementos visitados pre-ordem: ");
                    VisitarArvorePreOrdem(arvore, visit);
                    printf("\n");

                    printf("elementos visitados in-ordem: ");
                    VisitarArvoreInOrdem(arvore, visit);
                    printf("\n");

                    printf("elementos visitados pos-ordem: ");
                    VisitarArvorePosOrdem(arvore, visit);
                    printf("\n");
                } else {
                    printf("árvore não criada!\n");
                }
                break;

            case 6:
                arvore = esvaziarArvore(arvore);
                if (arvore == NULL) {
                    printf("árvore esvaziada e destruída com sucesso!\n");
                } else {
                    printf("falha ao esvaziar e destruir a árvore!\n");
                }
                break;
        }

    } while (TRUE);

    return 0;
}
