#include "../../includes/includelib.h"
//Includes
#include "transporte.h"

THIS(obj_Transporte)// crea definicion de funcion this para este modulo. .. Macro en config.h

//----------------------------------------------------
static void toString_TransporteImpl(void *self)
{
	obj_Transporte *obj=this(self);      
    // version con algunos datos, ver como gestionar la posibilidad de listar mas informacion.
    printf("\nCodigo %d\nDominio: %s\nDescripcion: %s\nImporte: $%.f\n",obj->getCodigo(obj),obj->getDominio(obj),obj->getDescripcion(obj),obj->getImporte(obj)); 
}

static int getCodigoTransporte_Impl(void *self)
{ return  *((int *) getValue(self,POS_CODIGO_TRA));}
//----------------------------------------------------
static char * getDominioTransporte_Impl(void *self)
{ return  (char *) getValue(self,POS_DOMINIO_TRA);}
//----------------------------------------------------
static char * getDescripcionTransporte_Impl(void *self)
{ return  (char *) getValue(self,POS_DESCRIPCION_TRA);}
//----------------------------------------------------
static float getImporteTransporte_Impl(void *self)
{ return  *((float *) getValue(self,POS_IMPORTE_TRA));}
//----------------------------------------------------
static void setCodigoTransporte_Impl(void *self,int val)
{ setValue(self,POS_CODIGO_TRA,&val); }
//----------------------------------------------------
static void setDominioTransporte_Impl(void *self,char * val)
{ setValue(self,POS_DOMINIO_TRA,val); }
//----------------------------------------------------
static void setDescripcionTransporte_Impl(void *self,char * val)
{ setValue(self,POS_DESCRIPCION_TRA,val); }
//----------------------------------------------------
static void setImporteTransporte_Impl(void *self,float val)
{ setValue(self,POS_IMPORTE_TRA,&val); }
//----------------------------------------------------
//----------------------------------------------------
static void destroyInternalTRA_Impl(void *self)
{
	obj_Transporte *obj = this(self);	
	// finalizar cada referencia inicializada - no NULL
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------

//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_Transporte(void *self)
{
  obj_Transporte *obj      = this(self);
  obj->ds  			    = &table_Transporte;
  obj->constructor 	    = Transporte_new;
  obj->sizeObj 		    = sizeof(obj_Transporte*);
  // inicializar cada puntero a una referencia relacionada, para ver cuando se busca por el id..
  
  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_TransporteImpl;
  // Inicializar handlers de getters y setters
  /// getters
    
	obj->getCodigo = getCodigoTransporte_Impl;  
	obj->getDominio = getDominioTransporte_Impl;  
	obj->getDescripcion = getDescripcionTransporte_Impl;  
	obj->getImporte = getImporteTransporte_Impl;

  /// setters  
    
	obj->setCodigo = setCodigoTransporte_Impl;  
	obj->setDominio = setDominioTransporte_Impl;  
	obj->setDescripcion = setDescripcionTransporte_Impl;  
	obj->setImporte = setImporteTransporte_Impl;

  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalTRA_Impl;
  //---- acceso a relaciones  
  
  return obj;
}
//----------------------------------------------------
//constructor de Transporte
obj_Transporte *Transporte_new()
{
  return (obj_Transporte *)init_obj(sizeof(obj_Transporte), init_Transporte);
}
//----------------------------------------------------

