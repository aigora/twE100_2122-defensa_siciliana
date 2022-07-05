#include "Inicializar.h"


//FUNCIONES INICIAR FIGURAS

void iniciarFigura(char texto[], casilla a[], casilla b[], char letra, char Letra)
{
    int i=0, j=0, m=0;
    while(texto[i] != '\0')
    {
        if(texto[i] == letra)
        {
            a[j].x = i;
            a[j].aux = i;
            j=j+1;
        }
        if(texto[i] == Letra)
        {
            b[m].x = i;
            b[m].aux = i;
            m=m+1;
        }
        i++;
    }
}



void iniciarKQ(char texto[], casilla *a, casilla *b, char letra, char Letra)
{
    int i=0;
    while(texto[i] != '\0')
    {
        if(texto[i] == letra)
        {
            a->x = i;
            a->aux = i;
        }
        if(texto[i] == Letra)
        {
            b->x = i;
            b->aux = i;
        }
        i++;
    }
}



void iniciarP(char texto[], _pcasilla a[], _pcasilla b[], char letra, char Letra)
{
    int i=0, j=0, m=0;
    while(texto[i] != '\0')
    {
        if(texto[i] == letra)
        {
            a[j].x = i;
            a[j].aux = i;
            a[j].uso = 0;
            j=j+1;
        }
        if(texto[i] == Letra)
        {
            b[m].x = i;
            b[m].aux = i;
            b[m].uso = 0;
            m=m+1;
        }
        i++;
    }
}






//FUNCIONES RESTRICTIVAS MOVIMIENTOS FIGURAS

int huecos(int q, int w[])
{
    int i;
    for(i=0;i<64;i++)
    {
        if(w[i] == q)
        {
            return 0;
        }
    }
    return 1;
}








int bloqueo(int m, int n, int b, char texto[])
{
    int i, aux;
    if(m < n)
    {
        aux = 0;
        i = n;
        n=n+b;
        while(n >= m)
        {
            if(texto[n] != ' ')
            {
                if((texto[n] >= 65 && texto[n] <= 90) && (texto[i] >= 65 && texto[i] <= 90))
                {
                    return 1;
                }
                else if((texto[n] >= 97 && texto[n] <= 122) && (texto[i] >= 97 && texto[i] <= 122))
                {
                    return 1;
                }
                else
                {
                    if(n != m)
                    {
                        aux = 1;
                    }
                }
            }
            n=n+b;
        }
        if(aux == 1)
        {
            return 1;
        }
        return 0;
    }
    if(n < m)
    {
        aux = 0;
        i = n;
        n=n+b;
        while(n <= m)
        {
            if(texto[n] != ' ')
            {
                if((texto[n] >= 65 && texto[n] <= 90) && (texto[i] >= 65 && texto[i] <= 90))
                {
                    return 1;
                }
                else if((texto[n] >= 97 && texto[n] <= 122) && (texto[i] >= 97 && texto[i] <= 122))
                {
                    return 1;
                }
                else
                {
                    if(n != m)
                    {
                        aux = 1;
                    }
                }
            }
            n=n+b;
        }
        if (aux == 1)
        {
            return 1;
        }
        return 0;
    }
}






int bloqueoC(int m, int n, char texto[])
{
    if(texto[m] != ' ')
    {
        if((texto[m] >= 65 && texto[m] <= 90) && (texto[n] >= 65 && texto[n] <= 90))
        {
            return 1;
        }
        if((texto[m] >= 97 && texto[m] <= 122) && (texto[n] >= 97 && texto[n] <= 122))
        {
            return 1;
        }
    }
    return 0;
}




int bloqueoComerP(int m, int n, char texto[])
{
    if(texto[m] != ' ')
    {
        if((texto[m] >= 65 && texto[m] <= 90) && (texto[n] >= 65 && texto[n] <= 90))
        {
            return 1;
        }
        else if((texto[m] >= 97 && texto[m] <= 122) && (texto[n] >= 97 && texto[n] <= 122))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
