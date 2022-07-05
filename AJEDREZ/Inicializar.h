#ifndef INICIALIZAR_H_INCLUDED
#define INICIALIZAR_H_INCLUDED


typedef struct
{
    int x, aux;
}casilla;

typedef struct
{
    int x, aux, uso;
}_pcasilla;

typedef struct
{
    int k, K;
}jaque;


void iniciarFigura(char texto[], casilla a[], casilla b[], char letra, char Letra);
void iniciarP(char texto[], _pcasilla a[], _pcasilla b[], char letra, char Letra);
void iniciarKQ(char texto[], casilla *a, casilla *b, char letra, char Letra);


int huecos(int q, int w[]);
int bloqueo(int m, int n, int b, char texto[]);
int bloqueoC(int m, int n, char texto[]);
int bloqueoComerP(int m, int n, char texto[]);


#endif // INICIALIZAR_H_INCLUDED
