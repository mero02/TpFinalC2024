#include "../../includes/includelib.h"
//Includes
#include "../tipo_paquete/tipo_paquete.h"
#include "../pais/pais.h"
#include "../turista/turista.h"
#include "../paquete/paquete.h"
#include "../tipo_actividad/tipo_actividad.h"
#include "../transporte/transporte.h"
#include "../actividad/actividad.h"
#include "paquete_actividad.h"

THIS(obj_PaqueteActividad)// crea definicion de funcion this para este modulo. .. Macro en config.h

//----------------------------------------------------
static void toString_PaqueteActividadImpl(void *self)
{
     obj_PaqueteActividad *obj=this(self);     
     // version con algunos datos, ver como gestionar la posibilidad de listar mas informacion.
     printf("\nCodPaq: %d - CodAct: %d\nDetalle: %s\nFecha Desde: %s - Hasta %s",obj->getCodPaquete(obj),obj->getCodActividad(obj),obj->getDetalle(obj),obj->getFechaHoraDesde(obj),obj->getFechaHoraHasta(obj));
	 printf("\nImporte: $%.2f\n",obj->getImporte(obj)); 
}

static int getCodPaquetePaqueteActividad_Impl(void *self)
{ return  *((int *) getValue(self,POS_COD_PAQUETE_PAQ));}
//----------------------------------------------------
static int getCodActividadPaqueteActividad_Impl(void *self)
{ return  *((int *) getValue(self,POS_COD_ACTIVIDAD_PAQ));}
//----------------------------------------------------
static float getImportePaqueteActividad_Impl(void *self)
{ return  *((float *) getValue(self,POS_IMPORTE_PAQ));}
//----------------------------------------------------
static char * getFechaHoraDesdePaqueteActividad_Impl(void *self)
{ return  (char *) getValue(self,POS_FECHA_HORA_DESDE_PAQ);}
//----------------------------------------------------
static char * getFechaHoraHastaPaqueteActividad_Impl(void *self)
{ return  (char *) getValue(self,POS_FECHA_HORA_HASTA_PAQ);}
//----------------------------------------------------
static char * getDetallePaqueteActividad_Impl(void *self)
{ return  (char *) getValue(self,POS_DETALLE_PAQ);}
//----------------------------------------------------
static void setCodPaquetePaqueteActividad_Impl(void *self,int val)
{ setValue(self,POS_COD_PAQUETE_PAQ,&val); }
//----------------------------------------------------
static void setCodActividadPaqueteActividad_Impl(void *self,int val)
{ setValue(self,POS_COD_ACTIVIDAD_PAQ,&val); }
//----------------------------------------------------
static void setImportePaqueteActividad_Impl(void *self,float val)
{ setValue(self,POS_IMPORTE_PAQ,&val); }
//----------------------------------------------------
static void setFechaHoraDesdePaqueteActividad_Impl(void *self,char * val)
{ setValue(self,POS_FECHA_HORA_DESDE_PAQ,val); }
//----------------------------------------------------
static void setFechaHoraHastaPaqueteActividad_Impl(void *self,char * val)
{ setValue(self,POS_FECHA_HORA_HASTA_PAQ,val); }
//----------------------------------------------------
static void setDetallePaqueteActividad_Impl(void *self,char * val)
{ setValue(self,POS_DETALLE_PAQ,val); }
//----------------------------------------------------
//----------------------------------------------------
static void destroyInternalPAQ_Impl(void *self)
{
	obj_PaqueteActividad *obj = this(self);	
	// finalizar cada referencia inicializada - no NULL
	
	if(obj->paquete!=NULL)
	{
		destroyObj(obj->paquete);
		obj->paquete =  NULL;			
	}
	
	if(obj->actividad!=NULL)
	{
		destroyObj(obj->actividad);
		obj->actividad =  NULL;			
	}
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------
obj_Paquete *getPaqueteActividad_PaqueteObj_Impl(void *self)
{
 obj_PaqueteActividad *obj = this(self);        //acceso a la informacion relacionada   return NULL;
 
 if(obj->paquete==NULL && obj->getCodPaquete(obj)!=0)
 {
 	obj->paquete = (obj_Paquete *)  Paquete_new();
 	if(obj->paquete->findbykey(obj->paquete,obj->getCodPaquete(obj))!=NOT_FOUND)
 	  return obj->paquete;
 }
 return obj->paquete;
}
//----------------------------------------------------
obj_Actividad *getPaqueteActividad_ActividadObj_Impl(void *self)
{
 obj_PaqueteActividad *obj = this(self);        //acceso a la informacion relacionada   return NULL;
 
 if(obj->actividad==NULL && obj->getCodActividad(obj)!=0)
 {
 	obj->actividad = (obj_Actividad *)  Actividad_new();
 	if(obj->actividad->findbykey(obj->actividad,obj->getCodActividad(obj))!=NOT_FOUND)
 	  return obj->actividad;
 }
 return obj->actividad;
}
//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_PaqueteActividad(void *self)
{
  obj_PaqueteActividad *obj      = this(self);
  obj->ds  			    = &table_PaqueteActividad;
  obj->constructor 	    = PaqueteActividad_new;
  obj->sizeObj 		    = sizeof(obj_PaqueteActividad*);
  // inicializar cada puntero a una referencia relacionada, para ver cuando se busca por el id..
    obj->paquete   = NULL;
  obj->actividad   = NULL;

  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_PaqueteActividadImpl;
  // Inicializar handlers de getters y setters
  /// getters
    
	obj->getCodPaquete = getCodPaquetePaqueteActividad_Impl;  
	obj->getCodActividad = getCodActividadPaqueteActividad_Impl;  
	obj->getImporte = getImportePaqueteActividad_Impl;  
	obj->getFechaHoraDesde = getFechaHoraDesdePaqueteActividad_Impl;  
	obj->getFechaHoraHasta = getFechaHoraHastaPaqueteActividad_Impl;  
	obj->getDetalle = getDetallePaqueteActividad_Impl;

  /// setters  
    
	obj->setCodPaquete = setCodPaquetePaqueteActividad_Impl;  
	obj->setCodActividad = setCodActividadPaqueteActividad_Impl;  
	obj->setImporte = setImportePaqueteActividad_Impl;  
	obj->setFechaHoraDesde = setFechaHoraDesdePaqueteActividad_Impl;  
	obj->setFechaHoraHasta = setFechaHoraHastaPaqueteActividad_Impl;  
	obj->setDetalle = setDetallePaqueteActividad_Impl;

  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalPAQ_Impl;
  //---- acceso a relaciones  
    obj->getPaqueteObj  = getPaqueteActividad_PaqueteObj_Impl;  
	obj->getActividadObj  = getPaqueteActividad_ActividadObj_Impl;
  return obj;
}
//----------------------------------------------------
//constructor de PaqueteActividad
obj_PaqueteActividad *PaqueteActividad_new()
{
  return (obj_PaqueteActividad *)init_obj(sizeof(obj_PaqueteActividad), init_PaqueteActividad);
}
//----------------------------------------------------

