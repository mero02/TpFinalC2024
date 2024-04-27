#include "../../includes/includelib.h"
//Includes
#include "../localidad/localidad.h"
#include "../agencia/agencia.h"
#include "../tipo_paquete/tipo_paquete.h"
#include "agencia_t_paquete.h"

THIS(obj_AgenciaTPaquete)// crea definicion de funcion this para este modulo. .. Macro en config.h

//----------------------------------------------------
static void toString_AgenciaTPaqueteImpl(void *self)
{
     obj_AgenciaTPaquete *obj=this(self);      
     // version con algunos datos, ver como gestionar la posibilidad de listar mas informacion.
     printf("\n"); 
}

static int getCodAgenciaAgenciaTPaquete_Impl(void *self)
{ return  *((int *) getValue(self,POS_COD_GENCIA_TPAG));}
//----------------------------------------------------
static int getCodTipoPaqueteAgenciaTPaquete_Impl(void *self)
{ return  *((int *) getValue(self,POS_COD_TIP_PAQUETE_TPAG));}
//----------------------------------------------------

static void setCodAgenciaAgenciaTPaquete_Impl(void *self,int val)
{ setValue(self,POS_COD_GENCIA_TPAG,&val); }
//----------------------------------------------------
static void setCodTipoPaqueteAgenciaTPaquete_Impl(void *self,int val)
{ setValue(self,POS_COD_TIP_PAQUETE_TPAG,&val); }
//----------------------------------------------------
//----------------------------------------------------
static void destroyInternalTIP_Impl(void *self)
{
	obj_AgenciaTPaquete *obj = this(self);	
	// finalizar cada referencia inicializada - no NULL
	
	if(obj->agencia!=NULL)
	{
		destroyObj(obj->agencia);
		obj->agencia =  NULL;			
	}
	
	if(obj->tipo_paquete!=NULL)
	{
		destroyObj(obj->tipo_paquete);
		obj->tipo_paquete =  NULL;			
	}
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------
obj_Agencia *getAgenciaTPaquete_AgenciaObj_Impl(void *self)
{
 obj_AgenciaTPaquete *obj = this(self);        //acceso a la informacion relacionada   return NULL;
 
 if(obj->agencia==NULL && obj->getCodAgencia(obj)!=0)
 {
 	obj->agencia = (obj_Agencia *)  Agencia_new();
 	if(obj->agencia->findbykey(obj->agencia,obj->getCodAgencia(obj))!=NOT_FOUND)
 	  return obj->agencia;
 }
 return obj->agencia;
}
//----------------------------------------------------
obj_TipoPaquete *getAgenciaTPaquete_TipoPaqueteObj_Impl(void *self)
{
 obj_AgenciaTPaquete *obj = this(self);        //acceso a la informacion relacionada   return NULL;
 
 if(obj->tipo_paquete==NULL && obj->getCodTipoPaquete(obj)!=0)
 {
 	obj->tipo_paquete = (obj_TipoPaquete *)  TipoPaquete_new();
 	if(obj->tipo_paquete->findbykey(obj->tipo_paquete,obj->getCodTipoPaquete(obj))!=NOT_FOUND)
 	  return obj->tipo_paquete;
 }
 return obj->tipo_paquete;
}
//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_AgenciaTPaquete(void *self)
{
  obj_AgenciaTPaquete *obj      = this(self);
  obj->ds  			    = &table_AgenciaTPaquete;
  obj->constructor 	    = AgenciaTPaquete_new;
  obj->sizeObj 		    = sizeof(obj_AgenciaTPaquete*);
  // inicializar cada puntero a una referencia relacionada, para ver cuando se busca por el id..
  obj->agencia   		= NULL;
  obj->tipo_paquete   	= NULL;  

  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_AgenciaTPaqueteImpl;
  // Inicializar handlers de getters y setters
  /// getters
    
	obj->getCodAgencia = getCodAgenciaAgenciaTPaquete_Impl;
	obj->getCodTipoPaquete = getCodTipoPaqueteAgenciaTPaquete_Impl;  	

  /// setters  
    
	obj->setCodAgencia = setCodAgenciaAgenciaTPaquete_Impl;
	obj->setCodTipoPaquete = setCodTipoPaqueteAgenciaTPaquete_Impl;  
	
  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalTIP_Impl;
  //---- acceso a relaciones  
    obj->getAgenciaObj  = getAgenciaTPaquete_AgenciaObj_Impl;
	obj->getTipoPaqueteObj  = getAgenciaTPaquete_TipoPaqueteObj_Impl;  
	
  return obj;
}
//----------------------------------------------------
//constructor de AgenciaTPaquete
obj_AgenciaTPaquete *AgenciaTPaquete_new()
{
  return (obj_AgenciaTPaquete *)init_obj(sizeof(obj_AgenciaTPaquete), init_AgenciaTPaquete);
}
//----------------------------------------------------

