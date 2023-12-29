#include "Tree.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct __tnode__{
    void* data;
    tNode *r;
    tNode *l;
} tNode;

tNode *createTree(){
    tNode *newnode = (tNode*) malloc(sizeof (tNode));
    if(newnode!=NULL){
        newnode->data = NULL;
        newnode->l=NULL;
        newnode->r=NULL;
        return newnode;
    }
    return NULL;
}

tNode *InsertTree(tNode *t,void* data, int (*cmp)(void*, void*)){

    if(t!=NULL){
        if(t->data == NULL){
            t->data = data;
            return t;
        }
        if (cmp(data, t->data) < 0) {
            t->l = InsertTree(t->l, data, cmp);
        } else {
            t->r = InsertTree(t->r, data, cmp);
        }
        return t;
    }
    tNode *newnode = (tNode*)malloc(sizeof (tNode));
    if(newnode!=NULL) {
        newnode->data = data;
        newnode->l = NULL;
        newnode->r = NULL;
        return newnode;
    }
    return NULL;
}

void VisitarArvorePreOrdem(tNode *t, void(*visit)(void*)){
    if(t!=NULL && visit!=NULL){
        visit(t->data);
        VisitarArvoreInOrdem(t->l, visit);
        VisitarArvoreInOrdem(t->r, visit);
    }
    return;
}

void VisitarArvoreInOrdem(tNode *t, void(*visit)(void*)){
    if(t!=NULL && visit!=NULL){
        VisitarArvoreInOrdem(t->l, visit);
        visit(t->data);
        VisitarArvoreInOrdem(t->r, visit);
    }
    return;
}

void VisitarArvorePosOrdem(tNode *t, void(*visit)(void*)){
    if(t!=NULL && visit!=NULL){
        VisitarArvoreInOrdem(t->l, visit);
        VisitarArvoreInOrdem(t->r, visit);
        visit(t->data);
    }
    return;
}

int consultarArvore(tNode *t,void* data, int (*cmp)(void*, void*)){
    if(t!=NULL){
        int stat = cmp(data, t->data);
        if(stat==0){
            return TRUE;
        } else if(stat<0){
            return consultarArvore(t->l, data, cmp);
        } else{
            return consultarArvore(t->r, data, cmp);
        }
    }
    return FALSE;
}

tNode* minL(tNode* t){
    if(t!=NULL){
        if(t->r!=NULL){
            minL(t->r);
        }
        return t;
    }
    return NULL;
}

tNode *maxR(tNode *t){
    if(t!=NULL){
        if(t->l!=NULL){
            return maxR(t->l);
        }
        return t;
    }
    return NULL;
}

tNode *removeElm(tNode *t, void* data, int(*cmp)(void*, void*)){
    int stat;
    tNode *temp;
    if(t!=NULL){
        stat = cmp(data, t->data);
        if(stat>0){
            t->r = removeElm(t->r, data, cmp);
            return t;
        }else if(stat<0){
            t->l = removeElm(t->l, data, cmp);
            return t;
        }else{
            if(t->l==NULL && t->r == NULL){
                free(t);
                return NULL;
            } else if(t->l == NULL){
                temp = t->r;
                free(t);
                return temp;
            } else if(t->r == NULL){
                temp = t->l;
                free(t);
                return temp;
            }else {
                temp = maxR(t->r);
                if (temp != NULL) {
                    t->data = temp->data;
                    t->r = removeElm(t->r, temp->data, cmp);
                } else {
                    temp = minL(t->l);
                    t->data = temp->data;
                    t->l = removeElm(t->l, temp->data, cmp);
                }
            }
        }
        return t;
    }
    return NULL;
}

tNode *esvaziarArvore(tNode *t){
    if(t!=NULL){
        if(t->r == NULL && t->l == NULL){
            free(t);
            return NULL;
        } else{
            t->r = esvaziarArvore(t->r);
            t->l = esvaziarArvore(t->l);
        }
    }
    return NULL;
}

void visit(void *data){
    int dado = *(int*) data;
    printf("%d ", dado);
}

int cmpInt(void* a, void* b) {
    int valorA = *((int*)a);
    int valorB = *((int*)b);

    if (valorA < valorB) {
        return -1;
    } else if (valorA > valorB) {
        return 1;
    } else {
        return 0;
    }
}