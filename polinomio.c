#include <stdio.h>
#include <stdlib.h>
#include "polinomio.h"

typedef struct Nodo{
    
    TMonomio info;
    struct Nodo *proximo;

}TNodo;

typedef struct TPolinomio{
 
    TNodo *incio,*fim;
    int tamanho;

};

int tamStructPolinomio(){
    return sizeof(struct TPolinomio);
}

polinomio criaPolinomio(){
    polinomio p = (polinomio)kalloc(tamStructPolinomio());
    if(p!=NULL){
        p->incio=NULL;
        p->fim=NULL;
        p->tamanho = 0;
    }
    return p;
}

