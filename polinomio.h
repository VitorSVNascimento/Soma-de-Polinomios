#ifndef POLINOMIO_H_INCLUDED
#define POLINOMIO_H_INCLUDED

typedef struct {
    int base;
    int expoente;

}TMonomio;

typedef struct TPolinomio *polinomio;

polinomio criaPolinomio();
void terminaPolinomio(polinomio l);
int pesquisaPolinomio(polinomio l,int exp,TMonomio *e);
int insereFinal(polinomio l,TMonomio e);
int getMonomio(polinomio l, int posicao, TMonomio *e);
int polinomioVazia(polinomio l);
int polinomioCheia(polinomio l);
int tamanhoPolinomio(polinomio l);
int insereInicio(polinomio l, TMonomio e);
int inserePosicao(polinomio l, TMonomio e, int indice);
/*
Verefica o indice do primeiro expoente menor que o expoente passado por parametro
Parametros: l (lista de monomios), expoente a ser comparado com outros expoentes da lista
Retorno: O indice do expoente menor que o passado por parametro na lista, caso ele seja o menor retorna 0 
*/
int verficaExpoenteMenor(polinomio l,int expoente);


#endif