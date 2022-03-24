#include <stdio.h>
#include <stdlib.h>

typedef struct lista2 {
    int num;
    //ponteiros para o valor anterior e o próximo
    struct lista2 *ant, *prox; 
} Lista2:

Lista2* Insere (Lista* ini, int val);

Lista2* Localiza (Lista2* ini, int remov);

Lista2* Remove (Lista2* ini, int remov);



int main (){


}

Lista2* Insere (Lista* ini, int val){

    Lista2* temp = (Lista2*) malloc (sizeof(Lista2));

    temp -> num = val;
    temp -> prox = ini;
    temp -> ant = NULL;

    //se não for vazio, ele procede (NULL == 0 == false)
    if (lst)
        lst->ant = temp;

    return temp;
}

Lista2* Localiza (Lista2* ini, int remov) {

    List* P = ini;

    while (p != NULL){

        if (P -> num == remov) return P;

        P = P -> prox;
    }
    return NULL;
  }

  Lista2* Remove (Lista2* ini, int remov){

    Lista2* P = Localiza (ini, remov);

    if (!P) return ini;

    if (ini == P)
        ini = P -> prox;

    else
        P -> ant -> prox = P -> prox; 

    if ((P -> prox) != NULL) 
        P -> prox -> ant = p->ant;
    
    free(P);
    
    return ini;
}