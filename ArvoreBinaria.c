#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ArvoreBinaria.h"


 struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
};

/*
    Procedimento para imprimir uma árvore binária
*/
//void imprimir_versao_1(ArvBin *raiz){
//    if(raiz){
//        printf("%d ", raiz->info);
//        imprimir_versao_1(raiz->esq);
//        imprimir_versao_1(raiz->dir);
//    }
//}
ArvBin* cria_ArvBin () { //starta um vetor dinamico de memoria para armazenar a arvore binaria.
    ArvBin *raiz = (ArvBin *) malloc(sizeof(ArvBin));
    if (raiz != NULL)
        *raiz = NULL;
    return raiz;
}


void libera_NO(struct NO* no){ //deleta o valor dentro do NO atual
    if(no==NULL) //Caso o NO ja esteja com o valor NULL, ignore-o.
        return;
    libera_NO(no->esq); //Apaga o NO folha da esq.
    libera_NO(no->dir); //Apaga o NO folha a dir.
    free(no);
    no = NULL;
}
//
//void libera_ArvBinR(ArvBin* raiz) {
//    struct NO *no;
//
//    while (true) {
//        no = *raiz;
//        if (no->esq == NULL && no->dir == NULL) {
//            free(no);
//        }
//    }
//}


void libera_ArvBin(ArvBin* raiz){ // Deleta a arvore completa
    if(raiz == NULL) //Caso a RAIZ ja esteja com o valor NULL, ignore-o.
        return;
    libera_NO(*raiz); //Chama a Funcao libera_NO e apague todos os NO's da arvore
    free(raiz); //libere o vetor
}

int altura_ArvBin(ArvBin *raiz){ // Pega a altura da arvore (desde a raiz até o ultimo grupo de NO's folhas.
    if (raiz == NULL) //caso a RAIZ já tenha o valor NULL, ignore-o;
        return 0;
    if(*raiz == NULL) //Caso o ponteiro da RAIZ esteja apontando para os ultimos NO's folhas, termine a funcao.
        return 0;
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));

    if(alt_esq>alt_dir)
        return(alt_esq + 1);
    else
        return(alt_dir+1);
    }

void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz!= NULL){
        printf("%d\n", (*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&(*raiz)->dir);

    }
}


void emOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz!= NULL){
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("%d\n", (*raiz)->info);
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}


void posOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if (*raiz != NULL){
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&(*raiz)->dir);
        printf("%d\n", (*raiz)-> info);
    }
}

int insere_ArvBin(ArvBin * raiz, int valor){
    if(raiz == NULL) //Caso a RAIZ tenha o valor NULL, ignore-o;
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));

    if(novo == NULL)
        return 0;

    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
       *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual!=NULL){
            ant=atual;
            if(valor == atual->info) {
                free(novo);
                return 0;
            }
            if(valor>atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(valor > ant->info)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}


int consulta_ArvBin(ArvBin * raiz, int valor ){
    if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    while(atual != NULL) {
        if (valor == atual->info)
            return 1;

        if (valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}



int remove_ArvBin(ArvBin *raiz, int valor) {
    if (raiz == NULL) return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while (atual != NULL) {
        if(valor == atual->info){
            if(atual == *raiz)
                *raiz = remove_atual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(valor>atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

struct NO* remove_atual(struct NO* atual){
    struct NO *no1, *no2;
    if(atual ->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }

    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}
int totalNO_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    int alt_dir = totalNO_ArvBin(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}



struct NO* remove_NO_Iterativo(ArvBin * root, int key)
{
    struct NO * curr = root;
    struct NO* prev = NULL;

    // Check if the key is actually
    // present in the BST.
    // the variable prev points to
    // the parent of the key to be deleted.
    while (curr != NULL && curr->info != key) {
        prev = curr;
        if (key < curr->info)
            curr = curr->esq;
        else
            curr = curr->dir;
    }

    if (curr == NULL) {
        printf("Chave:  ", key , " nao encotrada");
        return root;
    }

    // Check if the node to be
    // deleted has atmost one child.
    if (curr->esq == NULL || curr->dir == NULL) {

        // newCurr will replace
        // the node to be deleted.
        struct NO* newCurr;

        // if the left child does not exist.
        if (curr->dir == NULL)
            newCurr = curr->dir;
        else
            newCurr = curr->esq;

        // check if the node to
        // be deleted is the root.
        if (prev == NULL)
            return newCurr;

        // check if the node to be deleted
        // is prev's left or right child
        // and then replace this with newCurr
        if (curr == prev->esq)
            prev->esq = newCurr;
        else
            prev->dir = newCurr;

        // free memory of the
        // node to be deleted.
        free(curr);
    }

        // node to be deleted has
        // two children.
    else {
        struct NO* p = NULL;
        struct NO* temp;

        // Compute the inorder successor
        temp = curr->dir;
        while (temp->esq != NULL) {
            p = temp;
            temp = temp->esq;
        }

        // check if the parent of the inorder
        // successor is the curr or not(i.e. curr=
        // the node which has the same data as
        // the given data by the user to be
        // deleted). if it isn't, then make the
        // the left child of its parent equal to
        // the inorder successor'd right child.
        if (p != NULL)
            p->esq = temp->dir;

            // if the inorder successor was the
            // curr (i.e. curr = the node which has the
            // same data as the given data by the
            // user to be deleted), then make the
            // right child of the node to be
            // deleted equal to the right child of
            // the inorder successor.
        else
            curr->dir = temp->dir;

        curr->info = temp->info;
        free(temp);
    }
    return root;
}


ArvBin* cria_ArvBinR(){ //já esta na forma interaiva
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;


}


bool busca_Iterativa(struct NO* raiz, int valor)
{
    while (raiz != NULL) {
        if (valor > raiz->info) //passe a subarvore a direita como uma nova arvore //
             raiz = raiz->dir;

        else if (valor < raiz->info) // passe a subavore a esquerda como um nova arvore //
            raiz = raiz->esq;
        else
            return 1;
    }
    return 0;
}
