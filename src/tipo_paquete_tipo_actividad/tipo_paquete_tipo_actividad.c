#include "../../includes/includelib.h"
//Includes
#include "../tipo_paquete/tipo_paquete.h"
#include "../tipo_actividad/tipo_actividad.h"
#include "tipo_paquete_tipo_actividad.h"

THIS(obj_TipoPaqueteTipoActividad)// crea definicion de funcion this para este modulo. .. Macro en config.h

//----------------------------------------------------
static void toString_TipoPaqueteTipoActividadImpl(void *self)
{
     obj_TipoPaqueteTipoActividad *obj=this(self);      
     // version con algunos datos, ver como gestionar la posibilidad de listar mas informacion.
     printf("\n"); 
}

static int getCodTipoPaqueteTipoPaqueteTipoActividad_Impl(void *self)
{ return  *((int *) getValue(self,POS_COD_TIPO_PAQUETE_TIP));}
//----------------------------------------------------
static int getCodTipoActividadTipoPaqueteTipoActividad_Impl(void *self)
{ return  *((int *) getValue(self,POS_COD_TIPO_ACTIVIDAD_TIP));}
//----------------------------------------------------
static void setCodTipoPaqueteTipoPaqueteTipoActividad_Impl(void *self,int val)
{ setValue(self,POS_COD_TIPO_PAQUETE_TIP,&val); }
//----------------------------------------------------
static void setCodTipoActividadTipoPaqueteTipoActividad_Impl(void *self,int val)
{ setValue(self,POS_COD_TIPO_ACTIVIDAD_TIP,&val); }
//----------------------------------------------------
//----------------------------------------------------
static void destroyInternalTIP_Impl(void *self)
{
	obj_TipoPaqueteTipoActividad *obj = this(self);	
	// finalizar cada referencia inicializada - no NULL
	
	if(obj->tipo_paquete!=NULL)
	{
		destroyObj(obj->tipo_paquete);
		obj->tipo_paquete =  NULL;			
	}
	
	if(obj->tipo_actividad!=NULL)
	{
		destroyObj(obj->tipo_actividad);
		obj->tipo_actividad =  NULL;			
	}
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------
obj_TipoPaquete *getTipoPaqueteTipoActividad_TipoPaqueteObj_Impl(void *self)
{
 obj_TipoPaqueteTipoActividad *obj = this(self);        //acceso a la informacion relacionada   return NULL;
 
 if(obj->tipo_paquete==NULL && obj->getCodTipoPaquete(obj)!=0)
 {
 	obj->tipo_paquete = (obj_TipoPaquete *)  TipoPaquete_new();
 	if(obj->tipo_paquete->findbykey(obj->tipo_paquete,obj->getCodTipoPaquete(obj))!=NOT_FOUND)
 	  return obj->tipo_paquete;
 }
 return obj->tipo_paquete;
}
//----------------------------------------------------
obj_TipoActividad *getTipoPaqueteTipoActividad_TipoActividadObj_Impl(void *self)
{
 obj_TipoPaqueteTipoActividad *obj = this(self);        //acceso a la informacion relacionada   return NULL;
 
 if(obj->tipo_actividad==NULL && obj->getCodTipoActividad(obj)!=0)
 {
 	obj->tipo_actividad = (obj_TipoActividad *)  TipoActividad_new();
 	if(obj->tipo_actividad->findbykey(obj->tipo_actividad,obj->getCodTipoActividad(obj))!=NOT_FOUND)
 	  return obj->tipo_actividad;
 }
 return obj->tipo_actividad;
}
//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_TipoPaqueteTipoActividad(void *self)
{
  obj_TipoPaqueteTipoActividad *obj      = this(self);
  obj->ds  			    = &table_TipoPaqueteTipoActividad;
  obj->constructor 	    = TipoPaqueteTipoActividad_new;
  obj->sizeObj 		    = sizeof(obj_TipoPaqueteTipoActividad*);
  // inicializar cada puntero a una referencia relacionada, para ver cuando se busca por el id..
    obj->tipo_paquete   = NULL;
  obj->tipo_actividad   = NULL;

  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_TipoPaqueteTipoActividadImpl;
  // Inicializar handlers de getters y setters
  /// getters
    
	obj->getCodTipoPaquete = getCodTipoPaqueteTipoPaqueteTipoActividad_Impl;  
	obj->getCodTipoActividad = getCodTipoActividadTipoPaqueteTipoActividad_Impl;

  /// setters  
    
	obj->setCodTipoPaquete = setCodTipoPaqueteTipoPaqueteTipoActividad_Impl;  
	obj->setCodTipoActividad = setCodTipoActividadTipoPaqueteTipoActividad_Impl;

  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalTIP_Impl;
  //---- acceso a relaciones  
    obj->getTipoPaqueteObj  = getTipoPaqueteTipoActividad_TipoPaqueteObj_Impl;  
	obj->getTipoActividadObj  = getTipoPaqueteTipoActividad_TipoActividadObj_Impl;
  return obj;
}
//----------------------------------------------------
//constructor de TipoPaqueteTipoActividad
obj_TipoPaqueteTipoActividad *TipoPaqueteTipoActividad_new()
{
  return (obj_TipoPaqueteTipoActividad *)init_obj(sizeof(obj_TipoPaqueteTipoActividad), init_TipoPaqueteTipoActividad);
}
//----------------------------------------------------

