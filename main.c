#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h> 
#include <string.h>
#include <malloc.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "includes/includes.h"

/********************************************************************************************************
 *	Proyecto: tpfinalTMPL
 *	Grupo: 4
 * 	Autores: Gonzalo Bustamante, Maximiliano Ruiz, Mauro San Pedro
 * 	Versión: 1.0
 * 	Año: 2024
 * 	Descripción: El programa permite gestionar los datos de las agencias turísticas y los paquetes turísticos que ofrecen.
********************************************************************************************************/

int main(int argc, char *argv[])
{  
	
	if(!init_config(argv[POS_CONFIG]))
		exit(-1);  

	int opcMenu;
	int opcSubMenu;
	do{
		opcMenu = menu();
		switch (opcMenu){
			case 1:
				do{
					opcSubMenu = menuTurista();
					switchTurista(opcSubMenu);
				}while(opcSubMenu != 3);
				break;
			case 2:
				do{
					opcSubMenu = menuAgencia();
					switchAgencia(opcSubMenu);
				}while(opcSubMenu != 3);
				break;
			case 3:
				do{
					opcSubMenu = menuPaquete();
					switchPaquete(opcSubMenu);
				}while(opcSubMenu != 3);
				break;	
			case 4:
				do{
					opcSubMenu = menuFacturacion();
					switchFacturacion(opcSubMenu);
				}while(opcSubMenu != 2);
				break;
			case 5:
				do{
					opcSubMenu = menuOtros();
					switchOtros(opcSubMenu);
				}while(opcSubMenu != 4);
				break;
			case 6:
				do{
					opcSubMenu = menuListado();
					mostarListado(opcSubMenu);
				}while(opcSubMenu != 3);
				break;
			case 7:
				printf("\nApagando el sistema..\n");  
  				system("PAUSE");
				break;
			default:
				printf("\nValor incorrecto. intente nuevamente.\n");
				system("PAUSE");
				break;
		}
		system("cls");
	}while(opcMenu != 7);

  return 0;
}




