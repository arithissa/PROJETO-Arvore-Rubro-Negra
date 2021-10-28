#include <stdio.h>
#include <stdlib.h>
#define RED 1
#define BLACK 0

typedef int elem;
typedef struct No_LLRB no;
typedef struct Arvore_LLRB arvore;

struct Arvore_LLRB{     //estrutura da árvore LLRB
    no *raiz;
};

struct No_LLRB{     //estrutura do nó da árvore LLRB
    no *esq, *dir;
    elem info;
    int cor, flag;
};

arvore *criar();
void insere(arvore *a, elem x);
void predecessor(no *raiz, elem x, int *resp);
void sucessor(no *raiz, elem x, int *resp);
void minimo(no *raiz);
void maximo(no *raiz);
void Pre_Ordem(no *raiz);
void Em_Ordem(no *raiz);
void Pos_Ordem(no *raiz);
void liberar(no *raiz);
