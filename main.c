#include "arvoreRB.h"

int main(){
    int n, op, x, num = 0;
    arvore *LLRB = criar();

    scanf("%d", &n);    //quantidade de operações

    for(int i = 0; i < n; i++){
        scanf("%d", &op);   //lê as operações
        if(op == 1 || op == 2 || op == 3)
            scanf("%d", &x);

    switch(op){     //realiza cada operação
      case 1:
        insere(LLRB, x);
        break;

      case 2:
        sucessor(LLRB->raiz, x, &num);
        num = 0;
        break;

      case 3:
        predecessor(LLRB->raiz, x, &num);
        num = 0;
        break;

      case 4:
        maximo(LLRB->raiz);
        break;

      case 5:
        minimo(LLRB->raiz);
        break;

      case 6:
        Pre_Ordem(LLRB->raiz);
        if(LLRB->raiz == NULL)
          printf("erro\n");
        else
          printf("\n");
        break;

      case 7:
        Em_Ordem(LLRB->raiz);
        if(LLRB->raiz == NULL)
          printf("erro\n");
        else
          printf("\n");
        break;

      case 8:
        Pos_Ordem(LLRB->raiz);
        if(LLRB->raiz == NULL)
          printf("erro\n");
        else
          printf("\n");
        break;
    }
  }

    liberar(LLRB->raiz);    //libera a árvore LLRB

    return 0;
}
