#include <stdio.h>


void blacas_negras ();
void menu_principal ();



int main () 
{
	
	menu_principal();
	
	return 0;
}

void blacas_negras ()
{
	int opcion;	
	do
    {
    	printf("Seleccione una opcion:\n");
            printf("(1), BLANCAS\n(2), NEGRAS\n(3) MENU\n");
            printf("Teclee opcion:");
            scanf ("%d",&opcion);
        switch(opcion)
        {
	         case 1:
		        printf("EMPIEZAS TU, JUGADOR 1.\n");
	            break;
	        case 2:
	        	printf("EMPIEZA JUGADOR 1.\n");
	            break;
	        case 3:
	            break;
	        default:
	            printf("OPCION INVALIDA\n");
	            break;
	    }
	}
	while (1 && opcion !=3);
}

void menu_principal ()
{
	int opcion=0;
	
    printf ("############AJEDREZ############\n\tDEFENSA SICILIANA\n\n");
    printf (">>>>>>>>MENU PRINCIPAL<<<<<<<<<\n\n");
    printf ("BIENVENIDO.\n");

    do
    {
        printf("Seleccione una opcion:\n");
        printf("(1), EMPEZAR PARTIDA\n(2), SALIR DEL JUEGO\n");
        printf("Teclee opcion:");
        scanf ("%d",&opcion);
        switch(opcion)
        {
	        case 1:
	        	
	       	    printf("Estas dentro.\n");
	       	    blacas_negras ();
	       	    
	        	break;
	        case 2:
	            printf("GRACIAS.\n");
	            break;
	        default:
	            printf("OPCION INVALIDA\n");
		        break;
        }
    }
    while(1 && opcion!=2);
}





