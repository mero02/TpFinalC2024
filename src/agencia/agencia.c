#include "../../includes/includelib.h"
//Includes
#include "../localidad/localidad.h"
#include "agencia.h"

THIS(obj_Agencia)// crea definicion de funcion this para este modulo. .. Macro en config.h

//----------------------------------------------------
static void toString_AgenciaImpl(void *self)
{
     obj_Agencia *obj=this(self);      
     // version con algunos datos, ver como gestionar la posibilidad de listar mas informacion.
     obj_Localidad *l = obj->getLocalidadObj(obj);
     printf("\nCod: %d\nAgencia: %s - %s",obj->getCodigo(obj),obj->getNombre(obj),obj->getNro(obj));
	 printf("\nSe encuentra en:\nLocalidad: %s - %d",l->getNombre(l),obj->getCodigoPostal(obj));
	 printf("\nCalle: %s\nDpto: %d\nPiso: %s",obj->getCalle(obj),obj->getDpto(obj),obj->getPiso(obj));
	 printf("\nTelefonos: %s - %s\n",obj->getTelefono1(obj),obj->getTelefono2(obj));
}
//----------------------------------------------------
static int getCodigoAgencia_Impl(void *self)
{ return  *((int *) getValue(self,POS_CODIGO_AGE));}
//----------------------------------------------------
static char * getNombreAgencia_Impl(void *self)
{ return  (char *) getValue(self,POS_NOMBRE_AGE);}
//----------------------------------------------------
static char * getCalleAgencia_Impl(void *self)
{ return  (char *) getValue(self,POS_CALLE_AGE);}
//----------------------------------------------------
static char * getNroAgencia_Impl(void *self)
{ return  (char *) getValue(self,POS_NRO_AGE);}
//----------------------------------------------------
static char * getPisoAgencia_Impl(void *self)
{ return  (char *) getValue(self,POS_PISO_AGE);}
//----------------------------------------------------
static int getDptoAgencia_Impl(void *self)
{ return  *((int *) getValue(self,POS_DPTO_AGE));}
//----------------------------------------------------
static int getCodigoPostalAgencia_Impl(void *self)
{ return  *((int *) getValue(self,POS_CODIGO_POSTAL_AGE));}
//----------------------------------------------------
static char * getTelefono1Agencia_Impl(void *self)
{ return  (char *) getValue(self,POS_TEL1_AGE);}
//----------------------------------------------------
static char * getTelefono2Agencia_Impl(void *self)
{ return  (char *) getValue(self,POS_TEL2_AGE);}
//----------------------------------------------------

static void setCodigoAgencia_Impl(void *self,int val)
{ setValue(self,POS_CODIGO_AGE,&val); }
//----------------------------------------------------
static void setNombreAgencia_Impl(void *self,char * val)
{ setValue(self,POS_NOMBRE_AGE,val); }
//----------------------------------------------------
static void setCalleAgencia_Impl(void *self,char * val)
{ setValue(self,POS_CALLE_AGE,val); }
//----------------------------------------------------
static void setNroAgencia_Impl(void *self,char * val)
{ setValue(self,POS_NRO_AGE,val); }
//----------------------------------------------------
static void setPisoAgencia_Impl(void *self,char * val)
{ setValue(self,POS_PISO_AGE,val); }
//----------------------------------------------------
static void setDptoAgencia_Impl(void *self,int val)
{ setValue(self,POS_DPTO_AGE,&val); }
//----------------------------------------------------
static void setCodigoPostalAgencia_Impl(void *self,int val)
{ setValue(self,POS_CODIGO_POSTAL_AGE,&val); }
//----------------------------------------------------
static void setTelefono1Agencia_Impl(void *self,char * val)
{ setValue(self,POS_TEL1_AGE,val); }
//----------------------------------------------------
static void setTelefono2Agencia_Impl(void *self,char * val)
{ setValue(self,POS_TEL2_AGE,val); }
//----------------------------------------------------
//----------------------------------------------------
static void destroyInternalAGE_Impl(void *self)
{
	obj_Agencia *obj = this(self);	
	// finalizar cada referencia inicializada - no NULL
	
	if(obj->localidad!=NULL)
	{
		destroyObj(obj->localidad);
		obj->localidad =  NULL;			
	}
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------
obj_Localidad *getAgencia_LocalidadObj_Impl(void *self)
{
 obj_Agencia *obj = this(self);        //acceso a la informacion relacionada   return NULL;
 
 if(obj->localidad==NULL && obj->getCodigoPostal(obj)!=0)
 {
 	obj->localidad = (obj_Localidad *)  Localidad_new();
 	if(obj->localidad->findbykey(obj->localidad,obj->getCodigoPostal(obj))!=NOT_FOUND)
 	  return obj->localidad;
 }
 return obj->localidad;
}
//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_Agencia(void *self)
{
  obj_Agencia *obj      = this(self);
  obj->ds  			    = &table_Agencia;
  obj->constructor 	    = Agencia_new;
  obj->sizeObj 		    = sizeof(obj_Agencia*);
  // inicializar cada puntero a una referencia relacionada, para ver cuando se busca por el id..
    obj->localidad   = NULL;

  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_AgenciaImpl;
  // Inicializar handlers de getters y setters
  /// getters
    
	obj->getCodigo = getCodigoAgencia_Impl;  
	obj->getNombre = getNombreAgencia_Impl;  
	obj->getCalle = getCalleAgencia_Impl;  
	obj->getNro = getNroAgencia_Impl;  
	obj->getPiso = getPisoAgencia_Impl;  
	obj->getDpto = getDptoAgencia_Impl;  
	obj->getCodigoPostal = getCodigoPostalAgencia_Impl;
	obj->getTelefono1 = getTelefono1Agencia_Impl;
	obj->getTelefono2 = getTelefono2Agencia_Impl;

  /// setters  
    
	obj->setCodigo = setCodigoAgencia_Impl;  
	obj->setNombre = setNombreAgencia_Impl;  
	obj->setCalle = setCalleAgencia_Impl;  
	obj->setNro = setNroAgencia_Impl;  
	obj->setPiso = setPisoAgencia_Impl;  
	obj->setDpto = setDptoAgencia_Impl;  
	obj->setCodigoPostal = setCodigoPostalAgencia_Impl;
	obj->setTelefono1 = setTelefono1Agencia_Impl;
	obj->setTelefono2 = setTelefono2Agencia_Impl;

  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalAGE_Impl;
  //---- acceso a relaciones  
    obj->getLocalidadObj  = getAgencia_LocalidadObj_Impl;
  return obj;
}
//----------------------------------------------------
//constructor de Agencia
obj_Agencia *Agencia_new()
{
  return (obj_Agencia *)init_obj(sizeof(obj_Agencia), init_Agencia);
}
//----------------------------------------------------

