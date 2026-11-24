#include <stdio.h>
#include <string.h>

#include "zoologico.h"

int main(void)
{
	int tp=0;
	Panda poblacion[10];
	Panda *p=NULL;
	int op;
	int i;
	p=poblacion;
	//variables para buscar
	char buscar[20];
	Panda *encontrar_panda=NULL;
	while (1){
	printf("\t\t\tZOOLOGICO\n");
	printf("\t\tMENU\n");
	printf("1.Reistro de pandas\n");
	printf("2.Imprimir datos\n");
	printf("3.Buscar ejemplar\n");
	printf("4.Salir\n");
	printf("Elige una opcion del menu:");
	scanf("%d",&op);
	limpiar_buffer();


		switch (op)
		{
		case 1:
			printf("\n\t\tRegistro de pandas al sistema\n");
			printf("DATOS DEL PANDA\n");

				agregar_panda(poblacion,tp);

			//incrementa a los pandas
			tp++;
			break;
		case 2:

			imprime_panda(p,tp);
			break;
		case 3:
			printf("\n");
			bus_panda(poblacion,tp);
			break;
		case 4:
			liberar_memoria(poblacion, tp);
			return 0;
			break;
		default:
			printf("Opcion invalida, ingresa una opcion del menu\n");
		}//switch

	}//while



	




return 0;

}
