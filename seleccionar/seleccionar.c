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
|	Que Hace: Muestra una lista de paises cargados en la base de datos y permite seleccionar un pais dentro de la misma.
|	Pre-condiciones: --
|	Post-condiones: - cp = CP; Retorna CP; CP es uno de los codigos de paises cargados en la base de datos.
********************************************************************************************************/
int seleccionarPais(){
	obj_Pais *paisLista;
	void *list;
	int i=0,size=0, bandera,codPais;

	paisLista = Pais_new();
	
	size = paisLista->findAll(paisLista,&list,NULL);
	qsort(list,size,sizeof(obj_Pais*),cmpCodPais);
	destroyObj(paisLista);
	do{
		fechaActual();
		listar("Paises cargados en el sistema:",list,size);
		bandera = 1;
		obj_Pais **paises = (obj_Pais**)list;
		codPais = leerEntero("Ingrese un numero para seleccionar un pais: ");
	    for (i = 0; i < size; i++) {
	        obj_Pais *pais = paises[i];
	        
	        if (pais->getCodigo(pais) == codPais) {
	        	bandera = 0;
	        	destroyObjList(list,size);
	            return codPais; // País encontrado
	        }
	    }
	    if (bandera){
	    	system("cls");
	    	printf("El pais seleccionado no esta en la lista.\n");
	    	system("PAUSE");
		}
	}while(bandera == 1);
}
/********************************************************************************************************
|	Que Hace: Muestra una lista de localidades cargados en la base de datos y permite seleccionar una localidad dentro de la misma.
|	Pre-condiciones: --
|	Post-condiones: - cp = CP; Retorna CP; CP es uno de los codigos postales de una localidad cargados en la base de datos.
********************************************************************************************************/
int seleccionarCodP(){
	obj_Localidad *locLista;
	void *list;
	int i=0,size=0, sizeEnf=0, bandera,codPos;
	
	locLista = Localidad_new();
	
	size = locLista->findAll(locLista,&list,NULL);
	qsort(list,size,sizeof(obj_Localidad*),cmpNomLoc);
	destroyObj(locLista);
	do{
		fechaActual();
		listar("Localidades cargados en el sistema:",list,size);
		bandera = 1;
		obj_Localidad **locs = (obj_Localidad**)list;
		codPos = leerEntero("Ingrese un codigo postal para seleccionar la localidad: ");
	    for (i = 0; i < size; i++) {
	        obj_Localidad *loc = locs[i];
	        
	        if (loc->getCodPostal(loc) == codPos) {
	        	bandera = 0;
	        	destroyObjList(list,size);
	            return codPos; // Localidad encontrada
	        }
	    }
	    if (bandera){
	    	system("cls");
	    	printf("La localidad seleccionada no esta en la lista.\n");
	    	system("PAUSE");
		}
	}while(bandera == 1);
}
/********************************************************************************************************
|	Que Hace: Muestra una lista de tipo de actividades cargados en la base de datos y permite seleccionar un tipo de actividad dentro de la misma.
|	Pre-condiciones: --
|	Post-condiones: - ct = CT; Retorna CT; CT es uno de los codigos de un tipo de actividad cargados en la base de datos.
********************************************************************************************************/
void seleccionarTipoActividad(int *codTipo,int *nivel){
	obj_TipoActividad *tActividadLista;
	void *list;
	int i=0,size=0, bandera;
	
	tActividadLista = TipoActividad_new();
	
	size = tActividadLista->findAll(tActividadLista,&list,NULL);
	qsort(list,size,sizeof(obj_TipoActividad*),cmpCodTipo);
	
	destroyObj(tActividadLista);
	do{
		fechaActual();
		listar("Tipos de Actividades cargados en el sistema:",list,size);
		bandera = 1;
		obj_TipoActividad **actividades = (obj_TipoActividad**)list;
		*codTipo = leerEntero("Seleccione el codigo del tipo de actividad: ");
		for (i = 0; i < size; i++) {
		    obj_TipoActividad *actividad = actividades[i];
		        
		    if (actividad->getCodigo(actividad) == *codTipo) {
		        bandera = 0;
		        *nivel = actividad->getNivel(actividad);
		        break;
		    }
		}
		if (bandera){
		    system("cls");
		    printf("El tipo de actividad seleccionado no esta en la lista.\n");
		    system("PAUSE");
		}
	}while(bandera == 1);
	destroyObjList(list,size);
}
/********************************************************************************************************
|	Que Hace: Muestra una lista de transportes cargados en la base de datos y permite seleccionar un transporte dentro de la misma.
|	Pre-condiciones: --
|	Post-condiones: - ct = CT; Retorna CT; CT es uno de los codigos de un transporte cargados en la base de datos.
********************************************************************************************************/
void seleccionarTransporte(int *codTransporte,float *importeTransporte){
	obj_Transporte *transporteLista;
	void *list;
	int i=0,size=0,bandera;
	transporteLista = Transporte_new();
	size = transporteLista->findAll(transporteLista,&list,NULL);
	qsort(list,size,sizeof(obj_Transporte*),cmpCodTrans);
	destroyObj(transporteLista);
	do{
		fechaActual();
		listar("Transportes cargados en el sistema:",list,size);
		bandera = 1;
		obj_Transporte **transportes = (obj_Transporte**)list;
		*codTransporte = leerEntero("Seleccione el codigo del transporte: ");
		for (i = 0; i < size; i++) {
		    obj_Transporte *transporte = transportes[i];
		    if (transporte->getCodigo(transporte) == *codTransporte) {
		        bandera = 0;
		        *importeTransporte = transporte->getImporte(transporte);
		        break;
		    }
		}
		if (bandera){
		    system("cls");
		    printf("El transporte seleccionado no esta en la lista.\n");
		    system("PAUSE");
		}
	}while(bandera == 1);
	destroyObjList(list,size);
}
/********************************************************************************************************
|	Que Hace: Muestra una lista de agencias cargados en la base de datos y permite seleccionar una agencia dentro de la misma.
|	Pre-condiciones: --
|	Post-condiones: - ct = CT; Retorna CT; CT es uno de los codigos de una agencia cargados en la base de datos.
********************************************************************************************************/
int seleccionarAgencia(){
	obj_Agencia *agenciaLista;
	void *list;
	int size=0,cod;
	agenciaLista = Agencia_new();
	size = agenciaLista->findAll(agenciaLista,&list,NULL);
	qsort(list,size,sizeof(obj_Agencia*),cmpCodAg);
	fechaActual();
	listar("Agencias cargadas en el sistema:",list,size);
	cod = leerEntero("\nIngrese el codigo de la Agencia");
	if(agenciaLista->findbykey(agenciaLista,cod)==NOT_FOUND){
		system("cls");
		printf("El codigo %d no se encuentra en la base de datos.\n",cod);
		system("PAUSE");
		return 0;
	}
	destroyObj(agenciaLista);
	destroyObjList(list,size);
	return cod;
}
/********************************************************************************************************
|	Que Hace: Muestra una lista de los turistas cargados en la base de datos y permite seleccionar uno dentro de la misma.
|	Pre-condiciones: --
|	Post-condiones: - ct = CT; Retorna CT; CT es uno de los dni de un turista cargados en la base de datos.
********************************************************************************************************/
int seleccionarDni(){
	obj_Turista *turistaLista;
	void *list;
	int size=0,dni= 0;
	turistaLista = Turista_new();
	size = turistaLista->findAll(turistaLista,&list,NULL);
	qsort(list,size,sizeof(obj_Turista*),cmpDni);
	fechaActual();
	listar("Turistas cargados en el sistema:",list,size);
	dni = leerEntero("\nIngrese el dni del turista: ");
	if(turistaLista->findbykey(turistaLista,dni)==NOT_FOUND){
		system("cls");
		printf("El DNI %d no se encuentra en la base de datos.\n",dni);
		system("PAUSE");
		return 0;
	}
	destroyObj(turistaLista);
	destroyObjList(list,size);
	system("cls");
	return dni;
}
/********************************************************************************************************
|	Que Hace: Muestra una lista de los tipos de paquetes cargados en la base de datos y permite seleccionar una dentro de la misma.
|	Pre-condiciones: --
|	Post-condiones: - ct = CT; Retorna CT; CT es uno de los codigos de un tipo de paquete cargados en la base de datos.
********************************************************************************************************/
int seleccionarTipoPaquete(int *nivel){
	obj_TipoPaquete *tipoPaqLista;
	void *list;
	int size=0,cod;
	tipoPaqLista = TipoPaquete_new();
	size = tipoPaqLista->findAll(tipoPaqLista,&list,NULL);
	qsort(list,size,sizeof(obj_TipoPaquete*),cmpTipoPaq);
	fechaActual();
	listar("Tipos de paquetes cargados en el sistema:",list,size);
	cod = leerEntero("Ingrese el codigo del tipo Paquete: ");
	if(tipoPaqLista->findbykey(tipoPaqLista,cod)==NOT_FOUND){
		system("cls");
		printf("El codigo %d no se encuentra en la base de datos.\n",cod);
		system("PAUSE");
		return 0;
	}
	destroyObj(tipoPaqLista);
	obj_TipoPaquete *tipoPaq;
	tipoPaq = TipoPaquete_new();
	tipoPaq->findbykey(tipoPaq,cod);
	*nivel = tipoPaq->getNivel(tipoPaq);
	destroyObj(tipoPaq);
	destroyObjList(list,size);
	return cod;
}
/********************************************************************************************************
|	Que Hace: Muestra una lista de los tipos de paquetes cargados en la base de datos y permite seleccionar una dentro de la misma.
|	Pre-condiciones: --
|	Post-condiones: - ct = CT; Retorna CT; CT es uno de los codigos de un tipo de paquete cargados en la base de datos.
********************************************************************************************************/
int seleccionarPaquete(float *importe){
	obj_Paquete *paquete;
	void *list;
	int size=0,i;

	paquete = Paquete_new();
	size = paquete->findAll(paquete,&list,NULL);
	qsort(list,size,sizeof(obj_Paquete*),cmpPaq);
			
	int codigoPaquete, codTipoPaquete;
	fechaActual();
	listar("Paquetes cargados en el sistema:",list,size);
	codigoPaquete = leerEntero("Ingrese el codigo del paquete: ");
	if(paquete->findbykey(paquete,codigoPaquete)!=NOT_FOUND){
		*importe = getImportesActividades(codigoPaquete);
		return codigoPaquete;
	}else{
		system("cls");
		printf("El paquete seleccionado no esta cargado en la base de datos.\n");
		system("PAUSE");
	}
	destroyObj(paquete);
	destroyObjList(list, size);
}
/********************************************************************************************************
|	Que Hace: Muestra una lista de los tipos de pago cargados en la base de datos y permite seleccionar una dentro de la misma.
|	Pre-condiciones: --
|	Post-condiones: - ct = CT; Retorna CT; CT es uno de los codigos de un tipo de paquete cargados en la base de datos.
********************************************************************************************************/
int seleccionarFormaDePago(){
	obj_FormaPago *formaPago;
	void *list;
	int size=0,i, formaEle;

	formaPago = FormaPago_new();
	size = formaPago->findAll(formaPago,&list,NULL);
	qsort(list,size,sizeof(obj_FormaPago*),cmpFormaPago);
	fechaActual();
	listar("Formas de pago cargados en el sistema:",list,size);
	formaEle = leerEnteroEnRango("Seleccione una forma de pago ingresando un numero: ",1,size);
	return formaEle;
}		
/********************************************************************************************************
|	Que Hace: Muestra una lista de las facturas cargadas en la base de datos y permite seleccionar una dentro de la misma.
|	Pre-condiciones: --
|	Post-condiones: - ct = CT; Retorna CT; CT es uno de los codigos de un tipo de paquete cargados en la base de datos.
********************************************************************************************************/
void seleccionarFactura(int *nro, int *serie, char *letra, int dni){
	void *list,*itm;
	int i=0,size=0;

	obj_FacturaTurista *facturaLista;

	facturaLista = FacturaTurista_new();
	size = facturaLista->findAll(facturaLista,&list,NULL);

	obj_FacturaTurista **facTuristas = (obj_FacturaTurista**)list;
	for (i = 0; i < size; i++) {
        obj_FacturaTurista *facTur = facTuristas[i];
        if (facTur->getDniTurista(facTur) == dni) {
        	printf("\n----------------------------------------------------------------------------\n");
            itm = ((Object **)list)[i];    
	    	((Object *)itm)->toString(itm);
	    	listarDetalle(facTur->getNro(facTur),facTur->getSerie(facTur),facTur->getLetra(facTur));
        }
    }
    printf("\n----------------------------------------------------------------------------\n");
    system("PAUSE");
    
    destroyObj(facturaLista);
    destroyObjList(list,size);
}
/********************************************************************************************************
|	Que Hace: Muestra una lista de los detalles de factura cargados en la base de datos.
|	Pre-condiciones: --
|	Post-condiones: - ct = CT; Retorna CT; CT es uno de los codigos de un tipo de paquete cargados en la base de datos.
********************************************************************************************************/
void listarDetalle(int nroF, int serieF,const char *letraF){
	void *list,*itm;
	int i=0,size=0;
	obj_DetFacturaTurista *detalle;

	detalle = DetFacturaTurista_new();
	size = detalle->findAll(detalle,&list,NULL);
	obj_DetFacturaTurista **detFacTuristas = (obj_DetFacturaTurista**)list;
	for (i = 0; i < size; i++) {
        obj_DetFacturaTurista *detFacTur = detFacTuristas[i];
		if ((detFacTur->getNroFact(detFacTur)==nroF)&&(detFacTur->getSerieFact(detFacTur)==serieF )) { //
            itm = ((Object **)list)[i];    
	    	((Object *)itm)->toString(itm);
        }
    }
    destroyObj(detalle);
    destroyObjList(list,size);
}
/********************************************************************************************************
|	Que Hace: Muestra una lista de los detalles de factura cargados en la base de datos.
|	Pre-condiciones: --
|	Post-condiones: - ct = CT; Retorna CT; CT es uno de los codigos de un tipo de paquete cargados en la base de datos.
********************************************************************************************************/
void selecionarActividades(int codigoPaquete,int codTipoP){
	obj_Actividad *actividad;
	void *list,*itm;
	int i=0,size=0, codAct, bandera, codTipoA, flag;
	char *fechaDesde, *fechaHasta;
	float importe;
	actividad = Actividad_new();
	
	size = actividad->findAll(actividad,&list,NULL);
	
	do{
		fechaActual();
		listar("Actividades cargados en el sistema:" ,list, size);
		codAct = leerEntero("Seleccione el codigo de la actividad:");
		
		if (actividad->findbykey(actividad,codAct)!=NOT_FOUND){
			obj_TipoPaqueteTipoActividad *t_PaqAct;
			t_PaqAct = TipoPaqueteTipoActividad_new(); //aca enlazamos los tipos
			
			actividad->findbykey(actividad,codAct);
			
			importe = actividad->getImporte(actividad);
			
			obj_PaqueteActividad *paqAct = PaqueteActividad_new();
			
			paqAct->setCodPaquete(paqAct,codigoPaquete);
			paqAct->setCodActividad(paqAct,codAct);
			paqAct->setImporte(paqAct,importe);
			
			do {
                fechaDesde = leerCadena("Ingrese la fecha de comienzo de la actividad: ", MAX20);
            } while (validarFecha(fechaDesde));

			do {
				flag = 1;
                fechaHasta = leerCadena("Ingrese la fecha de fin de actividad: ",MAX20);
                if(!validarFecha(fechaHasta))
	                if(strcmp(fechaDesde,fechaHasta) < 0)
	                	flag = 0;
                else{
	                printf("La fecha hasta es menor que a la fecha desde, debe ingresar una fecha mayor\n");
	                system("pause");
	                system("cls");
                }
            } while (flag);
			
			paqAct->setFechaHoraDesde(paqAct,fechaDesde);
			paqAct->setFechaHoraHasta(paqAct,fechaHasta);
			
			paqAct->setDetalle(paqAct,leerCadena("Ingrese detalle: ",MAX120));
			
			paqAct->saveObj(paqAct);
			
			//Enlace de tipo_paquete_tipo_actividad
			codTipoA = actividad->getCodTipoActividad(actividad);
			t_PaqAct->setCodTipoPaquete(t_PaqAct,codTipoP);
			t_PaqAct->setCodTipoActividad(t_PaqAct,codTipoA);
			t_PaqAct->saveObj(t_PaqAct);
			destroyObj(paqAct);
			destroyObj(t_PaqAct);
			
			if(leerEnteroEnRango("\nDesea agregar otra actividad?\n1.Si\n2.No\n",1,2)==1){
				bandera = 1;
			}else{
				bandera = 0;
			}
		}else{
			system("cls");
			printf("\nLa Actividad seleccionada no se encuenta en la base de datos.\n");
			bandera = 1;
		}
	}while(bandera);
	destroyObjList(list,size);
	destroyObj(actividad);
	system("PAUSE");
}
