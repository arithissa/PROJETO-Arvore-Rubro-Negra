#include "arvoreRB.h"

arvore *criar(){    //aloca memória para a arvore
    arvore *a = (arvore *) malloc(sizeof(arvore));
    a->raiz = NULL;
    return a;    
}

int vermelho(no *raiz){ //verifica se o nó é vermelho
    return ((raiz) ? (raiz->cor == RED) : (0));
}

void TrocaCor(no *raiz){    //troca as cores dos nós
    raiz->cor = !(raiz->cor);
    raiz->esq->cor = !(raiz->esq->cor);
    raiz->dir->cor = !(raiz->dir->cor);
}

no *RotacionarEsq(no *p){ //faz uma rotação à esquerda
    no *no = p->dir;
    p->dir = no->esq;
    no->esq = p;
    no->cor = p->cor;
    p->cor = RED;
    
    return no;
}

no *RotacionarDir(no *p){ //faz uma rotação à direita
    no *no = p->esq;
    p->esq = no->dir;
    no->dir = p;
    no->cor = p->cor;
    p->cor = RED;
    
    return no;
}

no *NovoNo(no *raiz, elem x, int *flag){    //cria um novo nó
    no *p;

    p = (no *) malloc(sizeof(no));
    if(p == NULL)
        return NULL;

    p->info = x;
    p->flag = *flag;
    p->esq = NULL;
    p->dir = NULL;
    p->cor = RED;

    return p;
}

no *Inserir(no *raiz, elem x, int *flag){    //insere um nó e configura as posições na árvore
    if(raiz == NULL)
      return NovoNo(raiz, x, &x);
    
    if(x == raiz->info) //elemento já existe
      raiz->flag = *flag;
    else if(x < raiz->info)
      raiz->esq = Inserir(raiz->esq, x, flag);
    else
      raiz->dir = Inserir(raiz->dir, x, flag);
    
    if(vermelho(raiz->dir) && !vermelho(raiz->esq))
      raiz = RotacionarEsq(raiz);
    if(vermelho(raiz->esq) && vermelho(raiz->esq->esq))
      raiz = RotacionarDir(raiz);
    if(vermelho(raiz->esq) && vermelho(raiz->dir))
      TrocaCor(raiz);
        
    return raiz;
}

void insere(arvore *a, elem x){ //faz a inserção
    int flag = x;
    a->raiz = Inserir(a->raiz, x, &flag);
    if(a->raiz != NULL)
        a->raiz->cor = BLACK;

    return;
}

int PercorreP(no *raiz, elem x, int *resp){ //percorre a árvore em busca do predecessor de x
    if(raiz != NULL){
        PercorreP(raiz->esq, x, resp);
        if(raiz->info < x)
            *resp = raiz->info;
        PercorreP(raiz->dir, x, resp);
    }

    return *resp;
}

int PercorreS(no *raiz, elem x, int *resp, int *cont){  //percorre a árvore em busca do sucessor de x
    if(raiz != NULL){
        PercorreS(raiz->esq, x, resp, cont);
        if(raiz->info > x && *cont == 0){
            *resp = raiz->info;
            *cont = -1;
        }
        PercorreS(raiz->dir, x, resp, cont);
    }

    return *resp;
}

void predecessor(no *raiz, elem x, int *resp){  //imprime o predecessor de x
    if(raiz != NULL){
        *resp = PercorreP(raiz, x, resp);
        if(*resp == 0)
          printf("erro\n");
        else
          printf("%d\n", *resp);
    } else
        printf("erro\n");

    return;
}

void sucessor(no *raiz, elem x, int *resp){ //imprime o sucessor de x
    if(raiz != NULL){
        int cont = 0;
        *resp = PercorreS(raiz, x, resp, &cont);
        if(*resp == 0)
          printf("erro\n");
        else
          printf("%d\n", *resp);
    } else
        printf("erro\n");

    return;
}

void minimo(no *raiz){  //imprime o menor elemento da árvore LLRB
    if(raiz != NULL){
        while(raiz->esq)
            raiz = raiz->esq;
        printf("%d \n", raiz->info);
    } else
        printf("erro\n");

    return;
}

void maximo(no *raiz){  //imprime o maior elemento da árvore LLRB
    if(raiz != NULL){
        while(raiz->dir)
            raiz = raiz->dir;
        printf("%d \n", raiz->info);
    } else
        printf("erro\n");

    return;
}

void Pre_Ordem(no *raiz){ //impressão em pré ordem
  if(raiz != NULL){
        printf("%d ", raiz->info);
        Pre_Ordem(raiz->esq);
        Pre_Ordem(raiz->dir);
    }
        
    return;
}

void Em_Ordem(no *raiz){  //impressão em ordem
    if(raiz != NULL){
        Em_Ordem(raiz->esq);
        printf("%d ", raiz->info);
        Em_Ordem(raiz->dir);
    }

    return;
}

void Pos_Ordem(no *raiz){   //impressão em pós ordem
    if(raiz != NULL){
        Pos_Ordem(raiz->esq);
        Pos_Ordem(raiz->dir);
        printf("%d ", raiz->info);
    }
        
    return;
}

void liberar(no *raiz){   //libera a memória alocada
    if(raiz != NULL){
        liberar(raiz->esq);
        liberar(raiz->dir);
        free(raiz);
    }

    return;
}
