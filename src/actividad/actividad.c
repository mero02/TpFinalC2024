#include "../../includes/includelib.h"
//Includes
#include "../tipo_actividad/tipo_actividad.h"
#include "../transporte/transporte.h"
#include "actividad.h"

THIS(obj_Actividad)// crea definicion de funcion this para este modulo. .. Macro en config.h
//----------------------------------------------------
static void toString_ActividadImpl(void *self)
{
    obj_Actividad *obj=this(self); 
	obj_TipoActividad *tA = obj->getTipoActividadObj(obj);
	obj_Transporte *t = obj->getTransporteObj(obj); 
     // version con algunos datos, ver como gestionar la posibilidad de listar mas informacion.
     printf("\nCodigo actividad: %d\nNombre: %s \nDescripcion: %s\n",obj->getCodigo(obj),tA->getNombre(tA), tA->getDescripcion(tA)); 
     printf("Duracion: %s\nNivel: %d\n", tA->getDuracion(tA),obj->getNivel(obj));
     printf("Dominio: %s\nDescripcion Transporte: %s\nImporte: $%.2f\n", t->getDominio(t),t->getDescripcion(t),(obj->getImporte(obj)));
}
static int getCodigoActividad_Impl(void *self)
{ return  *((int *) getValue(self,POS_CODIGO_ACT));}
//----------------------------------------------------
static int getCodTipoActividadActividad_Impl(void *self)
{ return  *((int *) getValue(self,POS_COD_TIPO_ACTIVIDAD_ACT));}
//----------------------------------------------------
static int getCodTransporteActividad_Impl(void *self)
{ return  *((int *) getValue(self,POS_COD_TRANSPORTE_ACT));}
//----------------------------------------------------
static float getImporteActividad_Impl(void *self)
{ return  *((float *) getValue(self,POS_IMPORTE_ACT));}
//----------------------------------------------------
static int getNivelActividad_Impl(void *self)
{ return  *((int *) getValue(self,POS_NIVEL_ACT));}
//----------------------------------------------------
static void setCodigoActividad_Impl(void *self,int val)
{ setValue(self,POS_CODIGO_ACT,&val); }
//----------------------------------------------------
static void setCodTipoActividadActividad_Impl(void *self,int val)
{ setValue(self,POS_COD_TIPO_ACTIVIDAD_ACT,&val); }
//----------------------------------------------------
static void setCodTransporteActividad_Impl(void *self,int val)
{ setValue(self,POS_COD_TRANSPORTE_ACT,&val); }
//----------------------------------------------------
static void setImporteActividad_Impl(void *self,float val)
{ setValue(self,POS_IMPORTE_ACT,&val); }
//----------------------------------------------------
static void setNivelActividad_Impl(void *self,int val)
{ setValue(self,POS_NIVEL_ACT,&val); }
//----------------------------------------------------
//----------------------------------------------------
static void destroyInternalACT_Impl(void *self)
{
	obj_Actividad *obj = this(self);	
	// finalizar cada referencia inicializada - no NULL
	if(obj->tipo_actividad!=NULL)
	{
		destroyObj(obj->tipo_actividad);
		obj->tipo_actividad =  NULL;			
	}
	
	if(obj->transporte!=NULL)
	{
		destroyObj(obj->transporte);
		obj->transporte =  NULL;			
	}
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------
 
obj_TipoActividad *getActividad_TipoActividadObj_Impl(void *self)
{
 obj_Actividad *obj = this(self);        //acceso a la informacion relacionada   return NULL;
 
 if(obj->tipo_actividad==NULL && obj->getCodTipoActividad(obj)!=0)
 {
 	obj->tipo_actividad = (obj_TipoActividad *)  TipoActividad_new();
 	if(obj->tipo_actividad->findbykey(obj->tipo_actividad,obj->getCodTipoActividad(obj))!=NOT_FOUND)
 	  return obj->tipo_actividad;
 }
 return obj->tipo_actividad;
}
//----------------------------------------------------
obj_Transporte *getActividad_TransporteObj_Impl(void *self)
{
 obj_Actividad *obj = this(self);        //acceso a la informacion relacionada   return NULL;
 
 if(obj->transporte==NULL && obj->getCodTransporte(obj)!=0)
 {
 	obj->transporte = (obj_Transporte *)  Transporte_new();
 	if(obj->transporte->findbykey(obj->transporte,obj->getCodTransporte(obj))!=NOT_FOUND)
 	  return obj->transporte;
 }
 return obj->transporte;
}
//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_Actividad(void *self)
{
  obj_Actividad *obj      = this(self);
  obj->ds  			    = &table_Actividad;
  obj->constructor 	    = Actividad_new;
  obj->sizeObj 		    = sizeof(obj_Actividad*);
  // inicializar cada puntero a una referencia relacionada, para ver cuando se busca por el id..
    obj->tipo_actividad   = NULL;
  obj->transporte   = NULL;

  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_ActividadImpl;
  // Inicializar handlers de getters y setters
  /// getters
    
	obj->getCodigo = getCodigoActividad_Impl;  
	obj->getCodTipoActividad = getCodTipoActividadActividad_Impl;  
	obj->getCodTransporte = getCodTransporteActividad_Impl;  
	obj->getImporte = getImporteActividad_Impl;
    obj->getNivel = getNivelActividad_Impl;
  /// setters  
    
	obj->setCodigo = setCodigoActividad_Impl;  
	obj->setCodTipoActividad = setCodTipoActividadActividad_Impl;  
	obj->setCodTransporte = setCodTransporteActividad_Impl;  
	obj->setImporte = setImporteActividad_Impl;
	obj->setNivel = setNivelActividad_Impl;

  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalACT_Impl;
  //---- acceso a relaciones  
    obj->getTipoActividadObj  = getActividad_TipoActividadObj_Impl;  obj->getTransporteObj  = getActividad_TransporteObj_Impl;
  return obj;
}
//----------------------------------------------------
//constructor de Actividad
obj_Actividad *Actividad_new()
{
  return (obj_Actividad *)init_obj(sizeof(obj_Actividad), init_Actividad);
}
//----------------------------------------------------

