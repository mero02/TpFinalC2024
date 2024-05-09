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
|	Que Hace: Inserta un nuevo turista a la base de datos.
|	Pre-condiciones: --
|	Post-condiones: --
********************************************************************************************************/
void insertarTurista(){
	obj_Turista *turistaLista;
	void *list;
	int size=0;
	turistaLista = Turista_new();
	
	size = turistaLista->findAll(turistaLista,&list,NULL);
	qsort(list,size,sizeof(obj_Turista*),cmpDni);
	
	int dni;
	fechaActual();
	printf("Ingrese datos del turista:\n---------------------");
	dni = leerEntero("\nIngrese el dni: *");
	
	if (turistaLista->findbykey(turistaLista,dni) != NOT_FOUND){
		system("cls");
        printf("Error: El Dni que intentas ingresar ya existe en la base de datos.\n");
    }else{   	
    	obj_Turista *turista;
		turista = Turista_new();
		turista->setDni(turista, dni);
		turista->setNombre(turista,validarCadena("\nIngrese el nombre: *"));
		turista->setDomicilio(turista,leerCadena("\nIngrese el domicilio: *",MAX150));
		turista->setTelefono(turista,validarTelefono("Ingrese el telefono: "));
		turista->setCodPais(turista,seleccionarPais());
		turista->saveObj(turista);
		system("cls");
		printf("\nIngreso un nuevo turista.\n");
		destroyObj(turista);
	}
	destroyObj(turistaLista);
	destroyObjList(list,size);
	system("PAUSE");
}
/********************************************************************************************************
|	Que Hace: Inserta una nueva agencia a la base de datos.
|	Pre-condiciones: --
|	Post-condiones: 
********************************************************************************************************/
void insertarAgencia(){
	obj_Agencia *agenciaLista;
	void *list;
	int size=0;

	agenciaLista = Agencia_new();
	
	size = agenciaLista->findAll(agenciaLista,&list,NULL);
	qsort(list,size,sizeof(obj_Agencia*),cmpCodAg);
	
	destroyObj(agenciaLista);
	fechaActual();
	printf("Ingrese datos de la Agencia:\n---------------------");
	char *NroAg; 
	NroAg = leerCadena("\nIngrese Numero de agencia: *",MAX7);

	if (verificaAgencia(list,size,NroAg)){
		system("cls");
        printf("Error: El numero de Agencia ya existe.\n");
    }else{
    	obj_Agencia *agencia;
		agencia = Agencia_new();
		
		agencia->setNombre(agencia,leerCadena("\nIngrese el nombre de la agencia *",MAX90));
		agencia->setNro(agencia,NroAg);
		agencia->setCalle(agencia,leerCadena("\nIngrese el nombre de la calle donde se encuntra la agencia *",MAX150));
		agencia->setCodigoPostal(agencia,seleccionarCodP());
		agencia->setDpto(agencia,leerEntero("\nIngrese el numero de departamento *"));
		agencia->setPiso(agencia,leerCadena("\nIngrese el piso *",MAX7));
		agencia->setTelefono1(agencia,validarTelefono("Ingrese el telefono 1:"));
		agencia->setTelefono2(agencia,validarTelefono("Ingrese el telefono 2:"));
		agencia->saveObj(agencia);
		
		system("cls");
		printf("Ingreso una nueva Agencia.\n");
		destroyObj(agencia);
	}
	
	destroyObjList(list,size);
	
	system("PAUSE");
	system("cls");
}
/********************************************************************************************************
|	Que Hace: Inserta una nueva localidad a la base de datos.
|	Pre-condiciones: --
|	Post-condiones: --
********************************************************************************************************/
void insertarLocalidad(){
	obj_Localidad *loc;
	void *list,*itm;
	int i=0,size=0, sizeEnf=0;
	int codigo;
	
	loc =Localidad_new();
	size = loc->findAll(loc,&list,NULL);
	
	qsort(list,size,sizeof(obj_Localidad*),cmpNomLoc);
	fechaActual();
	listar("Localidades en el sistema: " ,list,size);
	codigo = leerEnteroEnRango("\nIngrese el codigo postal de la localidad: *",MINCODPOSTAL,MAXCODPOSTAL);

	if (loc->findbykey(loc,codigo)!= NOT_FOUND){       
		system("cls");
        printf("Error: La localidad que intentas ingresar ya existe en la base de datos.\n");
    }
	else{
    	obj_Localidad *loc;
    	loc = Localidad_new();
    	loc->setNombre(loc,validarCadena("\nIngrese el nombre de la localidad: *"));
    	loc->setCodPostal(loc,codigo);
    	loc->saveObj(loc);
    	destroyObj(loc);
    	
    	system("cls");
    	printf("Ingreso una nueva localidad.\n");
	}	
	destroyObj(loc);
	destroyObjList(list,size);
	system("PAUSE");
}
/********************************************************************************************************
|	Que Hace: Inserta un nuevo pais a la base de datos.
|	Pre-condiciones: --
|	Post-condiones: --
********************************************************************************************************/
void insertarPais(){
	obj_Pais *paisLista;
	void *list,*itm;
	int i=0,size=0;
	char *nombre;
	paisLista = Pais_new();
	size = paisLista->findAll(paisLista,&list,NULL);
	
	qsort(list,size,sizeof(obj_Pais*),cmpCodPais);
	fechaActual();
	listar("Paises cargados en el sistema:",list,size);
	nombre = validarCadena("\nIngrese el nombre del pais: *");

	if (verificaPais(list,size,nombre)){
		system("cls");
        printf("Error: El pais que intentas ingresar ya existe en la base de datos.\n");
    }else{
    	obj_Pais *pais;
		pais = Pais_new();
		pais->setNombre(pais,nombre);
		pais->saveObj(pais);
		destroyObj(pais);
		
		system("cls");
		printf("Ingreso un nuevo pais.\n");
	}
	destroyObj(paisLista);
	destroyObjList(list,size);
	
	system("PAUSE");
}
/********************************************************************************************************
|	Que Hace: Inserta una nueva actividad a la base de datos.
|	Pre-condiciones: --
|	Post-condiones: 
********************************************************************************************************/
void insertarActividad(){
	obj_Actividad *actividadLista;
	void *list,*itm;
	int i=0,size=0,codTipo = 0, codTransporte = 0, nivel;
	float importeTransporte;
	actividadLista = Actividad_new();
	
	size = actividadLista->findAll(actividadLista,&list,NULL);
	destroyObj(actividadLista);
	qsort(list,size,sizeof(obj_Actividad*),cmpCodAct);
	fechaActual();
	listar("Actividades cargados en el sistema:",list,size);
	system("PAUSE");
	fechaActual();
	seleccionarTipoActividad(&codTipo,&nivel); 
	fechaActual();
	seleccionarTransporte(&codTransporte, &importeTransporte);
	fechaActual();
	obj_Actividad *actividad;
	actividad = Actividad_new();
	actividad->setCodTipoActividad(actividad,codTipo);
	actividad->setCodTransporte(actividad,codTransporte);
	actividad->setImporte(actividad, ((leerFloat("\nIngrese el importe de la actividad:"))+importeTransporte));
	actividad->setNivel(actividad,nivel);
	
	actividad->saveObj(actividad);
	destroyObj(actividad);
	destroyObjList(list,size);
	system("cls");
	printf("\nIngreso una nueva actividad.\n");
	
	system("PAUSE");
}
/********************************************************************************************************
|	Que Hace: Inserta un nuevo paquete a la base de datos.
|	Pre-condiciones: --
|	Post-condiones: 
********************************************************************************************************/
void insertarPaquete(){
	int CodTipPaq,CodAg,dni,nivel, codigoPaquete;
	char *fecha;
	
	obj_Paquete *paquete;
	paquete = Paquete_new();
	fechaActual();
	if((CodTipPaq = seleccionarTipoPaquete(&nivel)) &&  (CodAg = seleccionarAgencia()) && (dni = seleccionarDni())){
		enlazoAgenciaTipoPaq(CodAg,CodTipPaq);
		paquete->setCodTipoPaquete(paquete,CodTipPaq);
		paquete->setCodAgencia(paquete,CodAg);
		do{
			fecha = leerCadena("\nIngrese una fecha del tipo 'YYYY-MM-DD'",11);
		}while(validarFecha(fecha));
		paquete->setFecha(paquete,fecha);
		paquete->setDniTurista(paquete,dni);
		paquete->setNivel(paquete,nivel);
		saveObjImpl(paquete);
		codigoPaquete = paquete->getCodigo(paquete);
		destroyObj(paquete);
		
		selecionarActividades(codigoPaquete,CodTipPaq);
		
		system("cls");
		printf("\nIngreso un nuevo paquete.\n");
	}else{
		printf("\nNo se pudo realizar la creacion del paquete\n");
	}
	
	system("PAUSE");
}
/********************************************************************************************************
|	Que Hace: Vincula un nuevo detalle a una factura y la inserta a la base de datos.
|	Pre-condiciones: n = N; s = S; l = L;
|	Post-condiones: --
********************************************************************************************************/
void insertarDetalleFactura(int nro,int serie, char *letra){
	int nroRenglon=0,codigoPaquete = 0;
	
	do{
		fechaActual();
		float importe = 0;
		obj_DetFacturaTurista *detalleFactura;

		nroRenglon++;//Aumenta cada vez que se agrega un detalle a la factura.
		
		codigoPaquete = seleccionarPaquete(&importe);
		
		detalleFactura = DetFacturaTurista_new();
		
		detalleFactura->setNroFact(detalleFactura,nro);
		detalleFactura->setSerieFact(detalleFactura,serie);
		detalleFactura->setLetraFact(detalleFactura,letra);
		detalleFactura->setNroRenglon(detalleFactura,nroRenglon);
		detalleFactura->setImporte(detalleFactura,importe);
		detalleFactura->setCodPaquete(detalleFactura,codigoPaquete);
		detalleFactura->saveObj(detalleFactura);
		destroyObj(detalleFactura);
	}while(leerEnteroEnRango("Desea agregar otro paquete?\n1.Si\n2.No\n",1,2)==1);
}
/********************************************************************************************************
|	Que Hace: Crea una nueva factura y la guarda en la base de datos.
|	Pre-condiciones: --
|	Post-condiones: --
********************************************************************************************************/
void crearFactura() {
    int sizeTur = 0, bandera = 0, size = 0, i = 0;
    void *listTur, *list;
    int codigoPaquete, serie, nro, dni;
    float importe, importeTotal = 0;
    char *fecha, *letra;
    
    do {
        obj_Turista *turistaLista;
        turistaLista = Turista_new();

        sizeTur = turistaLista->findAll(turistaLista, &listTur, NULL);
        qsort(listTur, sizeTur, sizeof(obj_Turista*), cmpDni);
        
        fechaActual();
        printf("Crear factura:\n______________\nIngrese datos del turista:\n---------------------");
        dni = leerEntero("\nIngrese el DNI: *");

        if (turistaLista->findbykey(turistaLista,dni) != NOT_FOUND) {

            obj_FacturaTurista *factura;
            
            factura = FacturaTurista_new_Letra_Serie (leerLetra("\nIngrese la letra de la factura:", MAX1));
            factura->setFecha(factura, getFechaHora());
            factura->setDniTurista(factura, dni);
            factura->setCodFormaPago(factura, seleccionarFormaDePago());
            factura->setDetPago(factura, leerCadena("\nAgregue un detalle a la factura:", MAX90));
            factura->saveObj(factura);

            printf("\nSe creo la factura.\n");
			
            insertarDetalleFactura(factura->getNro(factura), factura->getSerie(factura), factura->getLetra(factura));
            destroyObj(factura);
            bandera = 0;
        } else {
            system("cls");
            printf("Error: El DNI que intentas ingresar no existe en la base de datos.\n");
            if (leerEnteroEnRango("¿Desea ingresar un nuevo turista?\n1.Si\n2.No\n", 1, 2) == 1) {
                insertarTurista();
                bandera = 1;
            } else {
                system("cls");
                printf("No puedes crear una factura si el turista no está en la base de datos.\n");
            }
        }
        destroyObj(turistaLista);
        destroyObjList(list, size);
        destroyObjList(listTur, sizeTur);
    } while (bandera);

    system("PAUSE");
}
/********************************************************************************************************
|	Que Hace: Enlaza el tipo paquete con la agencia.
|	Pre-condiciones: --
|	Post-condiones: --
********************************************************************************************************/
void enlazoAgenciaTipoPaq(int CodAg,int CodTipPaq){
	obj_AgenciaTPaquete *agenciaTpaquete;
	agenciaTpaquete = AgenciaTPaquete_new();
	agenciaTpaquete->setCodAgencia(agenciaTpaquete,CodAg);
	agenciaTpaquete->setCodTipoPaquete(agenciaTpaquete,CodTipPaq);
	agenciaTpaquete->saveObj(agenciaTpaquete);
	destroyObj(agenciaTpaquete);
}

