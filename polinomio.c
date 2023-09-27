#include <stdio.h>
#include <stdlib.h>
#include "polinomio.h"

typedef struct Nodo{
    
    TMonomio info;
    struct Nodo *proximo;

}TNodo;

struct TPolinomio{
 
    TNodo *incio,*fim;
    int tamanho;

};

int tamStructPolinomio(){
    return sizeof(struct TPolinomio);
}

polinomio criaPolinomio(){
    polinomio p = (polinomio)malloc(tamStructPolinomio());
    if(p!=NULL){
        p->incio=NULL;
        p->fim=NULL;
        p->tamanho = 0;
    }
    return p;
}

void terminaPolinomio(polinomio p){

    TNodo *nodo;
    while (p->incio!=NULL){
        nodo = p->incio;
        p->incio = nodo->proximo; 
        free(nodo);
    }
    free (p);
}

int pesquisaPolinomio(polinomio p,int expoente,TMonomio *e){

    TNodo *nodo;
    nodo = p->incio;
    while (nodo!=NULL){
        if(nodo->info.expoente == expoente){
            *e = nodo->info;
            return 1;
        }
    }

    return 0;
}

int insereFinal(polinomio p, TMonomio m){

    TNodo *nodo = (TNodo*)malloc(sizeof(TNodo));
    if(nodo==NULL)
        return 0;
    nodo->info = m;
    nodo->proximo = NULL;
    if(p->incio==NULL)
        p->incio = nodo;
    else
        p->fim->proximo = nodo;//fazendo o proximo do fim deixar de ser NULL para ser o endere�o de nodo
    p->fim = nodo;//marcando o fim com o endere�o de nodo
    p->tamanho++;
    return 1;    
}

int insereInicio(polinomio p, TMonomio m){
    TNodo *nodo = (TNodo*)malloc(sizeof(TNodo));
    if(nodo==NULL)
        return 0;
    nodo->info = m;
    nodo->proximo = p->incio;
    p->incio = nodo;
    p->tamanho ++;
    if(p->tamanho==1)
        p->fim = nodo;
    return 1;
}

int getMonomio(polinomio p, int posicao, TMonomio *m){
    int i;
    TNodo *nodo;
    if(posicao==0 || posicao>p->tamanho)
        return 0;
    nodo=p->incio;
    for(i=1;i<posicao;i++)
        nodo = nodo->proximo;
    *m = nodo->info;
    return 1;
}

int polinomioVazia(polinomio p){
    if(p->incio==NULL)
        return 1;
    return 0;
}

int polinomioCheia(polinomio p){
    TNodo *nodo = (TNodo*)malloc(sizeof(TNodo));
    if(nodo==NULL)
        return 1;
    free(nodo);
    return 0;
}

int tamanhoPolinomio(polinomio p){
    return p->tamanho;
}

int inserePosicao(polinomio p, TMonomio m, int indice){

    if(indice<=0 || indice > p->tamanho+1)
        return 0;
    if(indice==1)
        return insereInicio(p,m);
    else if(indice==p->tamanho+1)    
        return insereFinal(p,m);
    else{
        TNodo *aux,*nodo = (TNodo*)malloc(sizeof(TNodo));
        if(nodo == NULL)
            return 0;
        nodo->info = m;
        aux = p->incio;
        for(int i = 1;i<indice-1;i++)
            aux = aux->proximo;
        nodo->proximo = aux->proximo;
        aux->proximo = nodo;
        p->tamanho++;
        return 1;
    }
}

int verficaExpoenteMenor(polinomio p,int expoente){
    
    int i;
    if(p->incio==NULL)
        return 1;
    TNodo* nodo = (TNodo *)malloc(sizeof(TNodo));

    if(nodo==NULL)
        return 0;
    i=1;
    nodo = p->incio;
    while (nodo!=NULL){
        
        if(nodo->info.expoente<expoente)
            break;
        nodo=nodo->proximo;
        i++;
    }
    return i;
}

polinomio somaPolinomio(polinomio poli1, polinomio poli2){
    polinomio resultado = criaPolinomio();
    TNodo *n1,*n2;
    TMonomio mono;

    n1 = poli1->incio;
    n2 = poli2->incio;
    while (n1!=NULL && n2!=NULL){
        if(n1->info.expoente == n2->info.expoente){
            mono.base = n1->info.base + n2->info.base;
            mono.expoente = n1->info.expoente;
            n1 = n1->proximo;   
            n2 = n2->proximo;
            insereFinal(resultado,mono);   
        }else if(n1->info.expoente > n2->info.expoente){
            mono.base = n1->info.base;
            mono.expoente = n1->info.expoente;
            n1=n1->proximo;
            insereFinal(resultado,mono);
        }else{
            mono.base = n2->info.base;
            mono.expoente = n2->info.expoente;
            n2=n2->proximo;
            insereFinal(resultado,mono);
        }
    }

    while (n1!=NULL){
        mono.base = n1->info.base;
        mono.expoente = n1->info.expoente;
        insereFinal(resultado,mono);
        n1=n1->proximo;        
    }

    while (n2!=NULL){
        mono.base = n2->info.base;
        mono.expoente = n2->info.expoente;
        insereFinal(resultado,mono);
        n2=n2->proximo;        
    }

    return resultado;
    
}

void polinomioToString(polinomio poli){
    TNodo *nodo;
    nodo = poli->incio;
    printf("\n\t");
    while (nodo->proximo!=NULL){
        printf("%dx^%d ",nodo->info.base,nodo->info.expoente);
        if(nodo->proximo->info.base>=0)
            printf(" + ");
        nodo = nodo->proximo;
    }
    printf("%dx^%d",nodo->info.base,nodo->info.expoente);

    return;
}