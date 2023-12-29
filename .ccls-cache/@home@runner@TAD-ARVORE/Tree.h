#ifndef IMPLEMENTACAO4_TREE_H
#define IMPLEMENTACAO4_TREE_H

#define TRUE 1
#define FALSE 0

typedef struct __tnode__ tNode;

tNode *createTree();

tNode *InsertTree(tNode *t,void* data, int (*cmp)(void*, void*));
void VisitarArvorePreOrdem(tNode *t, void(*visit)(void*));
void VisitarArvoreInOrdem(tNode *t, void(*visit)(void*));
void VisitarArvorePosOrdem(tNode *t, void(*visit)(void*));
int consultarArvore(tNode *t,void* data, int (*cmp)(void*, void*));
tNode *removeElm(tNode *t, void* data, int(*cmp)(void*, void*));
tNode* minR(tNode *t);
tNode* maxL(tNode *t);
tNode* esvaziarArvore(tNode *t);

void visit(void *);
int cmpInt(void *a, void *b);

#endif
