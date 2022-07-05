//DEFENSA SICILIANA

#include <stdio.h>

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


// PROTOTIPOS FUNCIONES
void iniciarFigura(char texto[], casilla a[], casilla b[], char letra, char Letra);
void iniciarP(char texto[], _pcasilla a[], _pcasilla b[], char letra, char Letra);
void iniciarKQ(char texto[], casilla *a, casilla *b, char letra, char Letra);


void ALFIL(char x[], casilla alfil[], int turno, int disponible[]);
void TORRE(char x[], casilla torre[], int turno, int disponible[]);
void CABALLO(char x[], casilla caballo[], int turno, int disponible[]);
void PEON(char x[], _pcasilla peon[], int turno, int disponible[]);
void REINA(char x[], casilla *reina, int turno, int disponible[]);
void REY(char x[], casilla *rey, int turno, int disponible[]);


int huecos(int q, int w[]);
int bloqueo(int m, int n, int b, char texto[]);
int bloqueoC(int m, int n, char texto[]);
int bloqueoComerP(int m, int n, char texto[]);


int main()
{
    char texto[1000];
    _pcasilla peon[8], Peon[8];
    casilla torre[2], Torre[2], caballo[2], Caballo[2];
    casilla alfil[2], Alfil[2], reina, Reina, rey, Rey;
    int disponible[64] = {36,40,44,48,52,56,60,64,104,108,112,116,120,124,128,132,172,176,180,184,188,192,196,200,240,244,248,252,256,260,264,268,308,312,316,320,324,328,332,336,376,380,384,388,392,396,400,404,444,448,452,456,460,464,468,472,512,516,520,524,528,532,536,540};
    FILE *pf, *pg;
    char pieza;
    int turno; //turno = 1 B; turno = 0 N
    jaque mate; // K = B; k = N
    int i=0,j=0,m=0;
    pf = fopen("Tablero.txt","r");
    if(pf == NULL)
    {
        printf("Error fichero tablero");
    }
    while(fscanf(pf,"%c",&texto[i]) != EOF)
    {
        i++;
    }
    texto[i] = '\0';



    iniciarFigura(texto,torre,Torre,'t','T');
    iniciarFigura(texto,caballo,Caballo,'c','C');
    iniciarFigura(texto,alfil,Alfil,'a','A');
    iniciarP(texto,peon,Peon,'p','P');
    iniciarKQ(texto,&reina,&Reina,'q','Q');
    iniciarKQ(texto,&rey,&Rey,'k','K');



    turno = 1;
    do
    {
        mate.K = 1;
        mate.k = 1;
        printf("%s",texto);
        fflush(stdin);
        printf("\nQue pieza mueves:");
        scanf("%c",&pieza);
        switch(pieza)
        {
            case 'T':
                {
                    if(turno == 1)
                    {
                        TORRE(texto,Torre,turno,disponible);
                    }
                    break;
                }
            case 'C':
                {
                    if(turno == 1)
                    {
                        CABALLO(texto,Caballo,turno,disponible);
                    }
                    break;
                }
            case 'A':
                {
                    if(turno == 1)
                    {
                        ALFIL(texto,Alfil,turno,disponible);
                    }
                    break;
                }
            case 'K':
                {
                    if(turno == 1)
                    {
                        REY(texto,&Rey,turno,disponible);
                    }
                    break;
                }
            case 'Q':
                {
                    if(turno == 1)
                    {
                        REINA(texto,&Reina,turno,disponible);
                    }
                    break;
                }
            case 'P':
                {
                    if(turno == 1)
                    {
                        PEON(texto,Peon,turno,disponible);
                    }
                    break;
                }
            case 't':
                {
                    if(turno == 0)
                    {
                        TORRE(texto,torre,turno,disponible);
                    }
                    break;
                }
            case 'c':
                {
                    if(turno == 0)
                    {
                        CABALLO(texto,caballo,turno,disponible);
                    }
                    break;
                }
            case 'a':
                {
                    if(turno == 0)
                    {
                        ALFIL(texto,alfil,turno,disponible);
                    }
                    break;
                }
            case 'k':
                {
                    if(turno == 0)
                    {
                        REY(texto,&rey,turno,disponible);
                    }
                    break;
                }
            case 'q':
                {
                    if(turno == 0)
                    {
                        REINA(texto,&reina,turno,disponible);
                    }
                    break;
                }
            case 'p':
                {
                    if(turno == 0)
                    {
                        PEON(texto,peon,turno,disponible);
                    }
                    break;
                }
        }
        if(turno == 1)
        {
            turno = turno -1;
        }
        else
        {
            turno = turno +1;
        }
        i=0;
        while(texto[i] != '\0')
        {
            if(texto[i] == 'K')
            {
                mate.K = 0;
            }
            if(texto[i] == 'k')
            {
                mate.k = 0;
            }
            i++;
        }
    }
    while((pieza != 'f' && pieza != 'F') && (mate.K == 0 && mate.k == 0));
    if(mate.K == 1 || mate.k == 1)
    {
        printf("\n\nJaque mate!!!\n");
    }
    printf("%s",texto);
    pg = fopen("FinTablero.txt","w");
    fprintf(pg,"%s",texto);
    fclose(pf);
    fclose(pg);
    return 0;
}






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





void PEON(char x[], _pcasilla peon[], int turno, int disponible[])
{
    int i=0, m=0, j=0,inc, error=0, k;
    char sent;
    int l, h, comer, g;
    printf("Que pieza quieres usar(de 0-7 empezando por la izquierda):\n");
    printf("Hacia donde quieres ir(w - arriba, s - abajo, q - diagional arriba izquierda, e - diagonal arriba derecha, \nz - diagonal abajo izquierda, c - diagonal abajo derecha):\n");
    printf("Cuantas casillas quieres avanzar:");
    do
    {
        if(error == 1)
        {
            error--;
            peon[j].x = peon[j].x - k;

        }
        if(error == 2)
        {
            error = 0;
        }
        scanf("%i %c %i",&j,&sent,&inc);
        switch(sent)
        {
            case 'w':
                {
                    l = peon[j].aux;
                    peon[j].x = peon[j].x + inc * (-68);
                    g = peon[j].x;
                    h = -68;
                    k = inc * (-68);
                    if(turno != 1 || x[g] != ' ')
                    {
                        error = 1;
                    }
                    break;
                }
            case 's':
                {
                    l = peon[j].aux;
                    peon[j].x = peon[j].x + inc * 68;
                    g = peon[j].x;
                    h = 68;
                    k = inc * 68;
                    if (turno != 0 || x[g] != ' ')
                    {
                        error = 1;
                    }
                    break;
                }
            case 'q':
                {
                    l = peon[j].aux;
                    peon[j].x = peon[j].x + inc * (-72);
                    h = -72;
                    k = inc * (-72);
                    comer = bloqueoComerP(peon[j].x,l,x);
                    if(turno != 1 || comer == 1)
                    {
                        error = 1;
                    }
                    break;
                }
            case 'e':
                {
                    l = peon[j].aux;
                    peon[j].x = peon[j].x + inc * (-64);
                    h = -64;
                    k = inc * (-64);
                    comer = bloqueoComerP(peon[j].x,l,x);
                    if(turno != 1 || comer == 1 )
                    {
                        error = 1;
                    }
                    break;
                }
            case 'z':
                {
                    l = peon[j].aux;
                    peon[j].x = peon[j].x + inc * 64;
                    h = 64;
                    k = inc * 64;
                    comer = bloqueoComerP(peon[j].x,l,x);
                    if(turno != 0 || comer == 1)
                    {
                        error = 1;
                    }
                    break;
                }
            case 'c':
                {
                    l = peon[j].aux;
                    peon[j].x = peon[j].x + inc * 72;
                    h = 72;
                    k = inc * 72;
                    comer = bloqueoComerP(peon[j].x,l,x);
                    if(turno != 0 || comer == 1)
                    {
                        error = 1;
                    }
                    break;
                }
            default:
                {
                    error = 2;
                }
        }
        if(inc == 2 && peon[j].uso !=0)
        {
            error = 1;
        }
        if(inc < 1 || inc > 2)
        {
            error = 1;
        }
        if(error == 0)
        {
            error = huecos(peon[j].x,disponible);
        }
        if(error == 0)
        {
            error = bloqueo(peon[j].x,l,h,x);
        }
        if(error == 1)
        {
            printf("Intentalo de nuevo");
        }
    }
    while(error == 1 || error == 2);








    if(turno == 1)
    {
        i=0;
        while(x[i] != '\0')
            {
                m++;
                if(x[i] == 'P')
                {
                    for(j=0;j<8;j++)
                    {
                        if(peon[j].x != peon[j].aux)
                        {
                            peon[j].uso = peon[j].uso + 1;
                            i = peon[j].aux;
                            x[i] = ' ';
                            i= peon[j].x;
                            x[i] = 'P';
                            peon[j].aux = peon[j].x;
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
                if(x[i] == 'p')
                {
                    for(j=0;j<8;j++)
                    {
                        if(peon[j].x != peon[j].aux)
                        {
                            peon[j].uso = peon[j].uso + 1;
                            i = peon[j].aux;
                            x[i] = ' ';
                            i= peon[j].x;
                            x[i] = 'p';
                            peon[j].aux = peon[j].x;
                        }
                    }
                }
                i = m;
                i++;
            }
    }
}






void TORRE(char x[], casilla torre[], int turno,int disponible [])
{
    int i=0, m=0, j=0,inc, error=0, k;
    char sent;
    int l, h;
    printf("Que pieza quieres usar (de 0-1 empezando por la izquierda):\n");
    printf("Hacia donde quieres ir (a - izquierda, d - derecha, w - arriba, s - abajo):\n");
    printf("Cuantas casillas quieres avanzar:\n");

    do
    {
        if(error == 1)
        {
            error--;
            torre[j].x = torre[j].x - k;

        }
        if(error == 2)
        {
            error = 0;
        }
        scanf("%i %c %i",&j,&sent,&inc);
        switch(sent)
        {
            case 'a':
                {
                    l = torre[j].aux;
                    torre[j].x = torre[j].x + inc * -4;
                    h = -4;
                    k = inc * -4;
                    break;
                }
            case 'd':
                {
                    l = torre[j].aux;
                    torre[j].x = torre[j].x + inc * 4;
                    h = 4;
                    k = inc * 4;
                    break;
                }
            case 'w':
                {
                    l = torre[j].aux;
                    torre[j].x = torre[j].x + inc * -68;
                    h = -68;
                    k = inc * -68;
                    break;
                }
            case 's':
                {
                    l = torre[j].aux;
                    torre[j].x = torre[j].x + inc * 68;
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
            error = huecos(torre[j].x,disponible);
        }
        if(error == 0)
        {
            error = bloqueo(torre[j].x,l,h,x);
        }
    }
    while(error == 1 || error == 2);


    if(turno == 1)
    {
        i=0;
        while(x[i] != '\0')
            {
                m++;
                if(x[i] == 'T')
                {
                    for(j=0;j<2;j++)
                    {
                        if(torre[j].x != torre[j].aux)
                        {
                            i = torre[j].aux;
                            x[i] = ' ';
                            i= torre[j].x;
                            x[i] = 'T';
                            torre[j].aux = torre[j].x;
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
                if(x[i] == 't')
                {
                    for(j=0;j<2;j++)
                    {
                        if(torre[j].x != torre[j].aux)
                        {
                            i = torre[j].aux;
                            x[i] = ' ';
                            i= torre[j].x;
                            x[i] = 't';
                            torre[j].aux = torre[j].x;
                        }
                    }
                }
                i = m;
                i++;
            }
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





void CABALLO(char x[], casilla caballo[], int turno, int disponible[])
{
    int i=0, m=0, j=0, inch, incv, error=0, k;
    char senth,sentv;
    int l, Ih, Iv;


    printf("Que pieza quieres usar (de 0-1 empezando por la izquierda):\n");
    printf("Hacia donde quieres ir horizontalmente (a - izquierda, d - derecha):\n");
    printf("Cuantas casillas quieres avanzar:\n");
    printf("Hacia donde quieres ir verticalmente (w - arriba, s - abajo):\n");
    printf("Cuantas casillas quieres avanzar:\n");


    do
    {
        if(error == 1)
        {
            error--;
            caballo[j].x = caballo[j].x - Ih - Iv;

        }
        if(error == 2)
        {
            error = 0;
        }
        scanf("%i %c %i %c %i",&j,&senth,&inch,&sentv,&incv);
        switch(senth)
        {
            case 'a':
                {
                    l = caballo[j].aux;
                    Ih = inch * -4;
                    break;
                }
            case 'd':
                {
                    l = caballo[j].aux;
                    Ih = inch * 4;
                    break;
                }
            default:
                {
                    error = 2;
                }
        }
        switch(sentv)
        {
            case 'w':
            {
                l = caballo[j].aux;
                Iv = incv * -68;
                break;
            }
            case 's':
            {
                l = caballo[j].aux;
                Iv = incv * 68;
                break;
            }
            default:
            {
                error = 2;
            }
        }
        caballo[j].x = caballo[j].x + Ih + Iv;
        if((inch < 1 && inch > 2) && (incv < 1 && incv > 2))
        {
            error = 1;
        }
        if(inch == incv)
        {
            error = 1;
        }
        if(error == 0)
        {
            error = huecos(caballo[j].x,disponible);
        }
        if(error == 0)
        {
            error = bloqueoC(caballo[j].x,l,x);
        }
    }
    while(error == 1 || error == 2);









    if(turno == 1)
    {
        i=0;
        while(x[i] != '\0')
            {
                m++;
                if(x[i] == 'C')
                {
                    for(j=0;j<2;j++)
                    {
                        if(caballo[j].x != caballo[j].aux)
                        {
                            i = caballo[j].aux;
                            x[i] = ' ';
                            i= caballo[j].x;
                            x[i] = 'C';
                            caballo[j].aux = caballo[j].x;
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
                if(x[i] == 'c')
                {
                    for(j=0;j<2;j++)
                    {
                        if(caballo[j].x != caballo[j].aux)
                        {
                            i = caballo[j].aux;
                            x[i] = ' ';
                            i= caballo[j].x;
                            x[i] = 'c';
                            caballo[j].aux = caballo[j].x;
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







void REY(char x[], casilla *rey, int turno, int disponible[])
{
    int i=0, m=0,inc=1, error=0, k;
    char sent;
    int l, h;
    printf("Hacia donde quieres ir (q - diagonal arriba izquierda, e - diagonal arriba derecha, z - diagonal abajo izquierda, \nc - diagonal abajo derecha,");
    printf(" a - izquierda, d - derecha, w - arriba, s - abajo):\n");
    printf("Avanza 1 casilla:\n");



    do
    {
        if(error == 1)
        {
            error--;
            rey->x = rey->x - k;

        }
        if(error == 2)
        {
            error = 0;
        }
        scanf("%c",&sent);
        switch(sent)
        {
            case 'q':
            {
                l = rey->aux;
                rey->x = rey->x + inc * (-72);
                h = -72;
                k = inc * (-72);
                break;
            }
            case 'e':
            {
                l = rey->aux;
                rey->x = rey->x + inc * (-64);
                h = -64;
                k = inc * (-64);
                break;
            }
            case 'z':
            {
                l = rey->aux;
                rey->x = rey->x + inc * 64;
                h = 64;
                k = inc * 64;
                break;
            }
            case 'c':
            {
                l = rey->aux;
                rey->x = rey->x + inc * 72;
                h = 72;
                k = inc * 72;
                break;
            }
            case 'a':
            {
                l = rey->aux;
                rey->x = rey->x + inc * -4;
                h = -4;
                k = inc * -4;
                break;
            }
            case 'd':
            {
                l = rey->aux;
                rey->x = rey->x + inc * 4;
                h = 4;
                k = inc * 4;
                break;
            }
            case 'w':
            {
                l = rey->aux;
                rey->x = rey->x + inc * -68;
                h = -68;
                k = inc * -68;
                break;
            }
            case 's':
            {
                l = rey->aux;
                rey->x = rey->x + inc * 68;
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
            error = huecos(rey->x,disponible);
        }
        if(error == 0)
        {
            error = bloqueo(rey->x,l,h,x);
        }
    }
    while(error == 1 || error == 2);






    if(turno == 1)
    {
        i=0;
        while(x[i] != '\0')
            {
                m++;
                if(x[i] == 'K' && rey->x != rey->aux)
                {
                    i = rey->aux;
                    x[i] = ' ';
                    i= rey->x;
                    x[i] = 'K';
                    rey->aux = rey->x;
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
                if(x[i] == 'k' && rey->x != rey->aux)
                {
                    i = rey->aux;
                    x[i] = ' ';
                    i= rey->x;
                    x[i] = 'k';
                    rey->aux = rey->x;
                }
                i = m;
                i++;
            }
    }
}







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







/*
scanf("%i %c %c %i",&j, &sent, &inc);
        switch(sent)
        {
        case 'w':
            {
                if(acc == 'M')
                {
                    if(peon[j].uso == 0)
                    {
                        peon[j].x = peon[j].x - 68 * inc;
                    }
                    else if(peon[j].uso != 0 && inc == 1)
                    {
                        peon[j].x = peon[j].x - 68;
                    }
                    else
                    {
                        error = 1;
                    }
                }
                else
                {
                    error = 1;
                }
            }
        case 's':
            {
                if(acc == 'M')
                {
                    if(peon[j].uso == 0)
                    {
                        peon[j].x = peon[j].x + inc * 68;
                    }
                    else if(peon[j].uso != 0 && inc == 1)
                    {
                        peon[j].x = peon[j].x + 68;
                    }
                    else
                    {
                        error = 1;
                    }
                }
                else
                {
                    error = 1;
                }
            }
        case 'q':
            {
                if(acc == 'C' && inc == 1)
                {
                    peon[j].x = copia[j].x - 72;
                    i = peon[j].x;
                    if(x[i] == ' ')
                       {
                           error = 1;
                       }
                }
                else
                {
                    error = 1;
                }
            }
        case 'e':
            {
                if(acc == 'C' && inc == 1)
                {
                    peon[j].x = peon[j].x - 64;
                    i = peon[j].x;
                    if(x[i] == ' ')
                       {
                           error = 1;
                       }
                }
                else
                {
                    error = 1;
                }
            }
        case 'z':
            {
                if(acc == 'C' && inc == 1)
                {
                    peon[j].x = peon[j].x + 64;
                    i = peon[j].x;
                    if(x[i] == ' ')
                       {
                           error = 1;
                       }
                }
                else
                {
                    error = 1;
                }
            }
        case 'c':
            {
                if(acc == 'C' && inc == 1)
                {
                    peon[j].x = peon[j].x + 72;
                    i = peon[j].x;
                    if(x[i] == ' ')
                       {
                           error = 1;
                       }
                }
                else
                {
                    error = 1;
                }
            }
        }
    }
    while(error != 1);*/










    /*peon[14].x = 500;
    i=0;
    while(texto[i] != '\0')
    {
        m++;
        if(texto[i] == 'P')
        {
            for(j=0;j<16;j++)
            {
                if(peon[j].x != peon[j].aux)
                {
                    i = peon[j].aux;
                    texto[i] = ' ';
                    i= peon[j].x;
                    texto[i] = 'P';
                    peon[j].aux = peon[j].x;
                }
            }
        }
        i = m;
        i++;
    }
    */





        /*
    i=0;
    while(texto[i] != '\0')
    {
        if(texto[i] == 'p')
        {
            peon[j].x = i;
            peon[j].aux = i;
            j= j+1;
        }
        if(texto[i] == 'P')
        {
            Peon[m].x = i;
            Peon[m].aux = i;
            m= m+1;
        }
        i++;
    }
    i=0;
    j=0;
    m=0;
    while(texto[i] != '\0')
    {
        if(texto[i] == 't')
        {
            torre[j].x = i;
            torre[j].aux = i;
            j=j+1;
        }
        if(texto[i] == 'T')
        {
            Torre[m].x = i;
            Torre[m].aux = i;
            m=m+1;
        }
        i++;
    }
    i=0;
    j=0;
    m=0;
    while(texto[i] != '\0')
    {
        if(texto[i] == 'c')
        {
            caballo[j].x = i;
            caballo[j].aux = i;
            j= j+1;
        }
        if(texto[i] == 'C')
        {
            Caballo[m].x = i;
            Caballo[m].aux = i;
            m= m+1;
        }
        i++;
    }
    */
