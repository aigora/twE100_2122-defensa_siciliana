//DEFENSA SICILIANA 

#include <stdio.h>

// PROTOTIPOS FUNCIONES
void iniciarFigura(char texto[], casilla a[], casilla b[], char letra, char Letra);
void iniciarP(char texto[], _pcasilla a[], _pcasilla b[], char letra, char Letra);
void iniciarKQ(char texto[], casilla *a, casilla *b, char letra, char Letra);

void ALFIL(char x[], casilla alfil[], int turno, int disponible[]);
void REINA(char x[], casilla *reina, int turno, int disponible[]);


// DEFINICION FUNCIONES
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




void ALFIL(char x[], casilla alfil[], int turno, int disponible[])
{
    int i=0, m=0, j=0,inc, error=0, k;
    char sent;
    int l, h;
    printf("Que pieza quieres usar (de 0-1 empezando por la izquierda):\n");
    printf("Hacia donde quieres ir (q - diagonal arriba izquierda, e - diagonal arriba derecha, z - diagonal abajo izquierda, \nc - diagonal abajo derecha):\n");
    printf("Cuantas casillas quieres avanzar:\n");

    do
    {
        if(error == 1)
        {
            error--;
            alfil[j].x = alfil[j].x - k;

        }
        if(error == 2)
        {
            error = 0;
        }
        scanf("%i %c %i",&j,&sent,&inc);
        switch(sent)
        {
            case 'q':
            {
                l = alfil[j].aux;
                alfil[j].x = alfil[j].x + inc * (-72);
                h = -72;
                k = inc * (-72);
                break;
            }
            case 'e':
            {
                l = alfil[j].aux;
                alfil[j].x = alfil[j].x + inc * (-64);
                h = -64;
                k = inc * (-64);
                break;
            }
            case 'z':
            {
                l = alfil[j].aux;
                alfil[j].x = alfil[j].x + inc * 64;
                h = 64;
                k = inc * 64;
                break;
            }
            case 'c':
            {
                l = alfil[j].aux;
                alfil[j].x = alfil[j].x + inc * 72;
                h = 72;
                k = inc * 72;
                break;
            }
            default:
            {
                error = 2;
            }
        }
        if(error == 0)
        {
            error = huecos(alfil[j].x,disponible);
        }
        if(error == 0)
        {
            error = bloqueo(alfil[j].x,l,h,x);
        }
    }
    while(error == 1 || error == 2);


    if(turno == 1)
    {
        i=0;
        while(x[i] != '\0')
            {
                m++;
                if(x[i] == 'A')
                {
                    for(j=0;j<2;j++)
                    {
                        if(alfil[j].x != alfil[j].aux)
                        {
                            i = alfil[j].aux;
                            x[i] = ' ';
                            i= alfil[j].x;
                            x[i] = 'A';
                            alfil[j].aux = alfil[j].x;
                        }
                    }
                }
                i = m;
                i++;
            }
    }
    else
    {
        i=0;
        while(x[i] != '\0')
            {
                m++;
                if(x[i] == 'a')
                {
                    for(j=0;j<2;j++)
                    {
                        if(alfil[j].x != alfil[j].aux)
                        {
                            i = alfil[j].aux;
                            x[i] = ' ';
                            i= alfil[j].x;
                            x[i] = 'a';
                            alfil[j].aux = alfil[j].x;
                        }
                    }
                }
                i = m;
                i++;
            }
    }
}



void REINA(char x[], casilla *reina, int turno, int disponible [])
{
    int i=0, m=0,inc, error=0, k;
    char sent;
    int l, h;
    printf("Hacia donde quieres ir (q - diagonal arriba izquierda, e - diagonal arriba derecha, z - diagonal abajo izquierda, \nc - diagonal abajo derecha,");
    printf(" a - izquierda, d - derecha, w - arriba, s - abajo):\n");
    printf("Cuantas casillas quieres avanzar:\n");



    do
    {
        if(error == 1)
        {
            error--;
            reina->x = reina->x - k;

        }
        if(error == 2)
        {
            error = 0;
        }
        scanf("%c %i",&sent,&inc);
        switch(sent)
        {
            case 'q':
            {
                l = reina->aux;
                reina->x = reina->x + inc * (-72);
                h = -72;
                k = inc * (-72);
                break;
            }
            case 'e':
            {
                l = reina->aux;
                reina->x = reina->x + inc * (-64);
                h = -64;
                k = inc * (-64);
                break;
            }
            case 'z':
            {
                l = reina->aux;
                reina->x = reina->x + inc * 64;
                h = 64;
                k = inc * 64;
                break;
            }
            case 'c':
            {
                l = reina->aux;
                reina->x = reina->x + inc * 72;
                h = 72;
                k = inc * 72;
                break;
            }
            case 'a':
            {
                l = reina->aux;
                reina->x = reina->x + inc * -4;
                h = -4;
                k = inc * -4;
                break;
            }
            case 'd':
            {
                l = reina->aux;
                reina->x = reina->x + inc * 4;
                h = 4;
                k = inc * 4;
                break;
            }
            case 'w':
            {
                l = reina->aux;
                reina->x = reina->x + inc * -68;
                h = -68;
                k = inc * -68;
                break;
            }
            case 's':
            {
                l = reina->aux;
                reina->x = reina->x + inc * 68;
                h = 68;
                k = inc * 68;
                break;
            }
            default:
            {
                error = 2;
            }
        }
        if(error == 0)
        {
            error = huecos(reina->x,disponible);
        }
        if(error == 0)
        {
            error = bloqueo(reina->x,l,h,x);
        }
    }
    while(error == 1 || error == 2);





    if(turno == 1)
    {
        i=0;
        while(x[i] != '\0')
            {
                m++;
                if(x[i] == 'Q' && reina->x != reina->aux)
                {
                    i = reina->aux;
                    x[i] = ' ';
                    i= reina->x;
                    x[i] = 'Q';
                    reina->aux = reina->x;
                }
                i = m;
                i++;
            }
    }
    else
    {
        i=0;
        while(x[i] != '\0')
            {
                m++;
                if(x[i] == 'q' && reina->x != reina->aux)
                {
                    i = reina->aux;
                    x[i] = ' ';
                    i= reina->x;
                    x[i] = 'q';
                    reina->aux = reina->x;
                }
                i = m;
                i++;
            }
    }
}
