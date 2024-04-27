#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h> 
#include <string.h>
#include <malloc.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

#include "../includes/includes.h"

/********************************************************************************************************
|	Que Hace: Realiza un update (actualizacion) sobre los datos de un turista.
|	Pre-condiciones: --
|	Post-condiones: --
********************************************************************************************************/
void actualizarTurista(){
	obj_Turista *turistaLista;
	void *list;
	int size=0,dni;
	
	turistaLista = Turista_new();
	size = turistaLista->findAll(turistaLista,&list,NULL);
	qsort(list,size,sizeof(obj_Turista*),cmpDni);
	fechaActual();
	printf("Actualizacion datos de los turista:\n---------------------------------------\n");
	listar("Turistas cargados en el sistema:",list,size);
	
	dni = leerEntero("\nIngrese el dni:");
	
	if (turistaLista->findbykey(turistaLista,dni) != NOT_FOUND){
        int opc, modifico = 0;
		
		obj_Turista *turista;
		turista = Turista_new();
		turista->findbykey(turista,dni);

		do{
			system("cls");
			printf("Actualizando datos del turista con dni: %d\n---------------------\n",turista->getDni(turista));
			opc = menuModTurista();
			switch(opc){
				case 1:
					turista->setNombre(turista,validarCadena("\nIngrese el nombre:"));
					modifico = 1;
					break;
				case 2:
					turista->setDomicilio(turista,leerCadena("\nIngrese el domicilio:",MAX150));
					modifico = 1;
					break;
				case 3:
					turista->setTelefono(turista,validarTelefono("Ingrese el telefono:"));
					modifico = 1;
					break;
				case 4:
					turista->setCodPais(turista,seleccionarPais());
					modifico = 1;
					break;
				case 5:
					turista->setNombre(turista,validarCadena("\nIngrese el nombre:"));
					turista->setDomicilio(turista,leerCadena("\nIngrese el domicilio:",MAX150));
					turista->setTelefono(turista,validarTelefono("Ingrese el telefono:"));
					turista->setCodPais(turista,seleccionarPais());
					modifico = 1;
					break;
			}
			turista->saveObj(turista);
			system("cls");
		}while(opc != 6);
		
		if(modifico){
			printf("\nSe actualizo un turista.\n");
		}
		destroyObj(turista);
    }else{
    	system("cls");
    	printf("Error: El dni no esta registrado en la base de datos.\n");
	}
	destroyObj(turistaLista);
	destroyObjList(list,size);
	system("PAUSE");
}
/********************************************************************************************************
|	Que Hace: Realiza un update (actualizacion) sobre los datos de una agencia.
|	Pre-condiciones: --
|	Post-condiones: --
********************************************************************************************************/
void actualizarAgencia(){
	obj_Agencia *agenciaLista;
	void *list;
	int size=0,opcMenu = 0, modifico = 0,codAgencia;
	char *nomAge;
	agenciaLista = Agencia_new();
	
	size = agenciaLista->findAll(agenciaLista,&list,NULL);
	qsort(list,size,sizeof(obj_Agencia*),cmpCodAg);
	
	printf("Actualizacion datos de las agencias:\n---------------------------------------\n");
	fechaActual();
	listar("Agencias cargadas en el sistema: ",list,size);
	
    codAgencia = leerEntero("\nIngrese el codigo de la agencia que desea modificar:\n");

   	if(agenciaLista->findbykey(agenciaLista,codAgencia) != NOT_FOUND){
   		obj_Agencia *agencia;
   		agencia = Agencia_new();
   		agencia->findbykey(agencia,codAgencia);
	   	do{
	   		fechaActual();
			printf("Actualizando datos de la agencia: %d\n",agencia->getCodigo(agencia));
	  		opcMenu = menuModAg();
			switch (opcMenu){
				case 1:{
					agencia->setNombre(agencia,leerCadena("\nIngrese el nombre de la agencia:",MAX90));
					modifico = 1;
					break;
				}
				case 2:{
					do{
						nomAge = leerCadena("\nIngrese Numero de agencia:",MAX7);
					}while(verificaAgencia(list,size,nomAge));
					agencia->setNro(agencia,nomAge);
					modifico = 1;
					break;
				}
				case 3:{
					agencia->setCalle(agencia,leerCadena("\nIngrese el nombre de la calle donde se encuentra la agencia:\n",MAX150));
					modifico = 1;
					break;
				}
				case 4:{
					agencia->setCodigoPostal(agencia,seleccionarCodP());
					modifico = 1;
					break;
				}
				case 5:{
					agencia->setDpto(agencia,leerEntero("\nIngrese el numero de departamento: "));
					modifico = 1;
					break;
				}
				case 6:{
					agencia->setPiso(agencia,leerCadena("\nIngrese el piso: ",MAX7));
					modifico = 1;
					break;
				}
				case 7:{
					agencia->setTelefono1(agencia,validarTelefono("Ingrese el telefono 1:"));
					modifico = 1;
					break;
				}
				case 8:{
					agencia->setTelefono2(agencia,validarTelefono("Ingrese el telefono 2:"));
					modifico = 1;
					break;
				}
			}
			agencia->saveObj(agencia);
			
			system("cls");
		}while(opcMenu != 9);
		destroyObj(agencia);
		if (modifico){
			printf("\nSe actualizo una agencia.\n");
		}
	}else{
		system("cls");
		printf("\nEl codigo de agencia que ingreso no se encuentra en la base de datos\n");
	}
	destroyObj(agenciaLista);
	destroyObjList(list,size);
	system("PAUSE");
}
/********************************************************************************************************
|	Que Hace: Realiza un update (actualizacion) sobre los datos de una localidad.
|	Pre-condiciones: --
|	Post-condiones: --
********************************************************************************************************/
void actualizarLocalidad(){
	obj_Localidad *locLista;
	void *list;
	int size=0, sizeEnf=0,codigo;
	
	locLista =Localidad_new();
	size = locLista->findAll(locLista,&list,NULL);
	qsort(list,size,sizeof(obj_Localidad*),cmpCodPais);
	printf("Actualizacion datos de las localidades:\n---------------------------------------\n");
	fechaActual();
	listar("Localidades cargadas en el sistema:",list,size);
	

	codigo = leerEnteroEnRango("Ingrese el Codigo postal de la localidad: ",MINCODPOSTAL,MAXCODPOSTAL);
	if(locLista->findbykey(locLista,codigo)!=NOT_FOUND){
		obj_Localidad *loc;
		loc = Localidad_new();
		loc->findbykey(loc,codigo);
		if(leerEnteroEnRango("\nSeleccione una opcion:\n1. Modificar nombre de localidad.\n2. Modificar codigo postal.\n",1,2)==1){
			loc->setNombre(loc,validarCadena("\nIngrese el nuevo nombre de la localidad: "));
		}else{
			loc->setCodPostal(loc,leerEnteroEnRango("ingrese el nuevo codigo postal: ",MINCODPOSTAL,MAXCODPOSTAL));
		}
		loc->saveObj(loc);
		system("cls");
		printf("se modifico La localidad: %s\n",loc->getNombre(loc));
		destroyObj(loc);
	}else{
		system("cls");
		printf("La localidad que intenta modificar no existe en la base de datos.\n");
	}
	destroyObjList(list,size);
	destroyObj(locLista);
	system("PAUSE");
}
/********************************************************************************************************
|	Que Hace: Realiza un update (actualizacion) sobre los datos de un pais.
|	Pre-condiciones: --
|	Post-condiones: --
********************************************************************************************************/
void actualizarPais(){
	obj_Pais *paisLista;
	void *list;
	int size=0,codigo;
	char *nomPais;
	paisLista = Pais_new();
	
	size = paisLista->findAll(paisLista,&list,NULL);
	qsort(list,size,sizeof(obj_Pais*),cmpCodPais);
	printf("Actualizacion datos de los Paises:\n---------------------------------------\n");
	fechaActual();
	listar("Paises cargados en el sistema:",list,size);
	
	codigo = leerEntero("\nIngrese el numero del pais que desea modificar:");

	if (paisLista->findbykey(paisLista,codigo)!=NOT_FOUND){
		obj_Pais *pais;
		pais = Pais_new();
		pais->findbykey(pais,codigo);
		do{
			nomPais = validarCadena("\nIngrese el nuevo nombre del pais: ");
		}while(verificaPais(list,size,nomPais));
		pais->setNombre(pais,nomPais);
		pais->saveObj(pais);
		system("cls");
		printf("Se actualizo un pais\n");
		destroyObj(pais);
    }else{
    	system("cls");
    	printf("Error: El pais que intentas modificar no existe en la base de datos.\n");
	}
	destroyObj(paisLista);
	destroyObjList(list,size);
	system("PAUSE");
}
/********************************************************************************************************
|	Que Hace: Realiza un update (actualizacion) sobre los datos de una actividad.
|	Pre-condiciones: --
|	Post-condiones: --
********************************************************************************************************/
void actualizarActividad(){
	obj_Actividad *actividadLista;
	void *list;
	int size=0, modifico = 0,codAct;
	
	actividadLista = Actividad_new();
	
	size = actividadLista->findAll(actividadLista,&list,NULL);
	qsort(list,size,sizeof(obj_Actividad*),cmpCodAct);
	printf("Actualizacion datos de los actividades:\n---------------------------------------\n");
	fechaActual();
	listar("actividades cargadas en el sistema:",list,size);
	

	printf("Actualizacion actividad:\n---------------------");
	codAct = leerEntero("\nIngrese el codigo de la actividad:");
	
	if (actividadLista->findbykey(actividadLista,codAct)!=NOT_FOUND){
		int codTipo = 0, codTransporte = 0, nivel, opc;
		float importeTransporte, importe;
		
		obj_Actividad *actividad;
		actividad = Actividad_new();
		actividad->findbykey(actividad,codAct);

		do{
			system("cls");
			printf("Actualizando datos de la actividad: %d\n",actividad->getCodigo(actividad));
			opc = menuModActividad();
			switch(opc){
				case 1:
					seleccionarTipoActividad(&codTipo,&nivel);
					actividad->setCodTipoActividad(actividad,codTipo);
					actividad->setNivel(actividad,nivel);
					modifico = 1;
					break;
				case 2:
					seleccionarTransporte(&codTransporte, &importeTransporte); // traigo codigo e importe del transporte nuevo
					actividad->setCodTransporte(actividad,codTransporte); //seteo codigo nuevo
					actividad->setImporte(actividad, ((actividad->getImporte(actividad)-getImpTransp(actividad->getCodTransporte(actividad)))+importeTransporte)); //seteo importe nuevo
					actividad->saveObj(actividad);
					system("cls");
					modifico = 1;
					break;
				case 3:
					importe = leerFloat("\nIngrese el importe de la actividad:");
					actividad->setImporte(actividad, importe+(getImpTransp(actividad->getCodTransporte(actividad))));
					actividad->saveObj(actividad);
					system("cls");
					modifico = 1;
					break;
			}
			actividad->saveObj(actividad);
			system("cls");
		}while(opc != 4);
		destroyObj(actividad);
		if (modifico){
			printf("\nSe actualizo una actividad.\n");
		}	
	}else{
		system("cls");
		printf("Error: El codigo ingresado no esta registrado en la base de datos.\n");
	}
	destroyObj(actividadLista);
	destroyObjList(list,size);
	
	system("PAUSE");
}
/********************************************************************************************************
|Que Hace: Realiza un update (actualizacion) sobre los datos de un paquete.
|Pre-condiciones: --
|Post-condiones: --
********************************************************************************************************/
void actualizarPaquete(){
	obj_Paquete *paqueteLista;
	void *list;
	int size=0,modifico = 0,codPaq;
	
	paqueteLista = Paquete_new();
	
	size = paqueteLista->findAll(paqueteLista,&list,NULL);
	qsort(list,size,sizeof(obj_Paquete*),cmpPaq);
	printf("Actualizacion datos de los Paquetes:\n---------------------------------------\n");
	fechaActual();
	listar("Paquetes cargados en el sistema:",list,size);
	
	codPaq = leerEntero("\nIngrese el codigo del paquete:");
	
	if (paqueteLista->findbykey(paqueteLista,codPaq)!=NOT_FOUND){
	
		obj_Paquete *paquete;
		paquete = Paquete_new();
		paquete->findbykey(paquete,codPaq);
		
		int nivel,opc,CodAg,CodTp,dni;
		char *fecha;
		
		do{
			fechaActual();
			printf("Actualizando datos del paquete: %d\n",paquete->getCodigo(paquete));
			opc = menuModPaquete();
			switch(opc){
				case 1:
					if(CodTp = seleccionarTipoPaquete(&nivel)){
						paquete->setCodTipoPaquete(paquete,CodTp);
						paquete->setNivel(paquete,nivel);
						modifico = 1;
					}
					break;
				case 2:
					if ( CodAg = seleccionarAgencia()){
						paquete->setCodAgencia(paquete,CodAg);
						modifico = 1;
					}
					break;
				case 3:
					do{
						fecha = leerCadena("Ingrese fecha de tipo 'YYY-MM-DD'",11);
					}while(validarFecha(fecha));
				
					paquete->setFecha(paquete,fecha);
					modifico = 1;
					break;
				case 4:
					if(dni = seleccionarDni()){
					paquete->setDniTurista(paquete,dni);
					modifico = 1;
					}
					break;
			}
		}while(opc != 5);
		if (modifico){
			printf("\nSe actualizo un paquete.\n");
			paquete->saveObj(paquete);
			destroyObj(paquete);
		}
	}else{
		printf("Error: El codigo ingresado no esta registrado en la base de datos.\n");
	}
	destroyObj(paqueteLista);
	destroyObjList(list,size);
	system("PAUSE");
}
