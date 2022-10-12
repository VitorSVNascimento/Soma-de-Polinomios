#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "polinomio.h"
#define BASE_MSG "\nForneça a base (numero inteiro):"
#define EXP_MSG "\nForneça o Expoente (numero natural):"
#define ERRO_POL_MSG "\nErro ao criar a lista de monomios(polinômio)"
int lerInteiro(char *msg){
    int n;
    printf("%s",msg);
    scanf("%d",&n);
    return n;
}

int lerExpoente(char *msg){
    int n;
    do{
        n=lerInteiro(msg);
        if(n<0)
            printf("\nO expoente não pode ser menor que 0");
    } while (n<0);
    return n;
}

polinomio obtemPolinomio(polinomio lpolinomio){
    int s_n,pos;
    TMonomio monomio;
    do{
      
        monomio.base = lerInteiro(BASE_MSG);
        monomio.expoente = lerExpoente(EXP_MSG);
        pos = verficaExpoenteMenor(lpolinomio,monomio.expoente);
        inserePosicao(lpolinomio,monomio,pos);
        
        printf("\nDeseja Fornecer algum outro monomio?");
        printf("\n1-Sim | 2-Não:");
        scanf("%d",&s_n);

    } while (s_n==1);
    
    return lpolinomio;
}

int testarPolinomio(){
    setlocale(LC_ALL,"portuguese");
    polinomio p1 = criaPolinomio(),p2 = criaPolinomio(),r;
    if(p1==NULL || p2==NULL){
        printf(ERRO_POL_MSG);
        return 1;
    }
    printf("\n-------Polinomio 1-------");
    obtemPolinomio(p1);
    printf("\n-------Polinomio 2-------");
    obtemPolinomio(p2);
    system("cls || clear");
    polinomioToString(p1);
    printf("\n+");
    polinomioToString(p2);
    printf("\n-------------------------");
    r = somaPolinomio(p1,p2);
    polinomioToString(r);
    terminaPolinomio(p1);
    terminaPolinomio(p2);
    terminaPolinomio (r);
    return 0;
}


int main(){
    return testarPolinomio();
}
