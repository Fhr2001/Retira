#include <stdio.h>
#include <stdlib.h>

typedef struct lista2 {
    int num;
    //ponteiros para o valor anterior e o próximo
    struct lista2 *ant, *prox; 
} Lista2;

Lista2* Insere (Lista2* ini, int val);

Lista2* Localiza (Lista2* ini, int remov);

Lista2* Remove (Lista2* ini, int remov);

Lista2* lst2_busca (Lista2* lst, int val);

int main (){

    int op, aux;
    Lista2* lst = (Lista2*) malloc(sizeof(Lista2));
    do
    {
        printf ("Digite 1 para inserir um termo\n");
        printf ("Digite 2 para remover um termo\n");
        printf ("Digite 0 para interromper o programa\n");

        scanf ("%d", &op);

        switch (op){
        case 1:

            printf ("Insira o numero inteiro\n");
            scanf ("%d", &aux);

            Insere (lst, aux);
            
            break;
        
        case 2:

            printf ("Qual número você quer remover?\n");
            scanf ("%d", &aux);

            Remove (lst, aux);

            break;
        }
    } while (op);
    
}

Lista2* Cria (void){
    return NULL;
}

Lista2* Insere (Lista2* ini, int val){

    Lista2* temp = (Lista2*) malloc (sizeof(Lista2));

    temp -> num = val;
    temp -> prox = ini;
    temp -> ant = NULL;

    //se não for vazio, ele procede (NULL == 0 == false)
    if (ini != NULL)
        ini -> ant = temp;

    return temp;
}

Lista2* Localiza (Lista2* ini, int remov) {

    Lista2* P = ini;

    while (P != NULL){

        if (P -> num == remov){
            return P;
        }

        P = P -> prox;
    }

    return NULL;
  }

/*Lista2* lst2_busca (Lista2* lst, int val){

    Lista2* p;

    for (p=lst; p!=NULL; p=p->prox){

        if (p->num == val){
        return p;
        }
        
    }

    return NULL;
    /* não achou o elemento */
}*/

Lista2* Remove (Lista2* ini, int remov){

    Lista2* P = Localiza (ini, remov);

    if (!P) return ini;

    if (ini == P)
        ini = P -> prox;

    else
        P -> ant -> prox = P -> prox; 

    if ((P -> prox) != NULL) 
        P -> prox -> ant = P -> ant;
    
    free(P);
    
    return ini;
}
