#ifndef POLINOMIO_H_INCLUDED
#define POLINOMIO_H_INCLUDED

typedef struct {
    int base;
    int expoente;

}TMonomio;

typedef struct TPolinomio* polinomio;

polinomio criaPolinomio();
void terminaPolinomio(polinomio p);
int pesquisaPolinomio(polinomio p,int exp,TMonomio *m);
int insereFinal(polinomio p,TMonomio m);
int insereInicio(polinomio p, TMonomio m);
int getMonomio(polinomio p, int posicao, TMonomio *m);
int polinomioVazia(polinomio p);
int polinomioCheia(polinomio p);
int tamanhoPolinomio(polinomio p);
int inserePosicao(polinomio p, TMonomio m, int indice);
/*
Verefica o indice do primeiro expoente menor que o expoente passado por parametro
Parametros: l (lista de monomios), expoente a ser comparado com outros expoentes da lista
Retorno: O indice do expoente menor que o passado por parametro na lista, caso n�o consiga alocar mem�ria retorna 0 
*/
int verficaExpoenteMenor(polinomio p,int expoente);

polinomio somaPolinomio(polinomio poli1, polinomio poli2);
void polinomioToString(polinomio poli);

#endif