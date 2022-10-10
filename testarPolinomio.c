#include <stdio.h>
#include <locale.h>
#include "polinomio.h"
#define BASE_MSG "Forneça a base: (numero inteiro)"
#define EXP_MSG "Forneça o Expoente: (numero natural)"

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

        printf("\nDeseja Fornecer algum outro monomio?");
        printf("\n1-Sim | 2-Não");
        scanf("%d",&s_n);

    } while (s_n==1);
    

}

int testarPolinomio(){
    setlocale(LC_ALL,"portuguese");

    return 0;
}

int main(){
    return testarPolinomio();
}
