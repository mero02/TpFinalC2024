#include "../../includes/includelib.h"
//Includes
#include "forma_pago.h"

THIS(obj_FormaPago)// crea definicion de funcion this para este modulo. .. Macro en config.h

//----------------------------------------------------
static void toString_FormaPagoImpl(void *self)
{
     obj_FormaPago *obj=this(self);      
     // version con algunos datos, ver como gestionar la posibilidad de listar mas informacion.
     printf("%d - %s\n",obj->getCodigo(obj),obj->getForma(obj)); 
}

static int getCodigoFormaPago_Impl(void *self)
{ return  *((int *) getValue(self,POS_CODIGO_FOR));}
//----------------------------------------------------

static char * getFormaFormaPago_Impl(void *self)
{ return  (char *) getValue(self,POS_FORMA_FOR);}
//----------------------------------------------------
static void setCodigoFormaPago_Impl(void *self,int val)
{ setValue(self,POS_CODIGO_FOR,&val); }
//----------------------------------------------------
static void setFormaFormaPago_Impl(void *self,char * val)
{ setValue(self,POS_FORMA_FOR,val); }
//----------------------------------------------------
//----------------------------------------------------
static void destroyInternalFOR_Impl(void *self)
{
	obj_FormaPago *obj = this(self);	
	// finalizar cada referencia inicializada - no NULL
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------

//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_FormaPago(void *self)
{
  obj_FormaPago *obj      = this(self);
  obj->ds  			    = &table_FormaPago;
  obj->constructor 	    = FormaPago_new;
  obj->sizeObj 		    = sizeof(obj_FormaPago*);
  // inicializar cada puntero a una referencia relacionada, para ver cuando se busca por el id..
  
  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_FormaPagoImpl;
  // Inicializar handlers de getters y setters
  /// getters
    
	obj->getCodigo = getCodigoFormaPago_Impl;  
	obj->getForma = getFormaFormaPago_Impl;

  /// setters  
    
	obj->setCodigo = setCodigoFormaPago_Impl;  
	obj->setForma = setFormaFormaPago_Impl;

  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalFOR_Impl;
  //---- acceso a relaciones  
  
  return obj;
}
//----------------------------------------------------
//constructor de FormaPago
obj_FormaPago *FormaPago_new()
{
  return (obj_FormaPago *)init_obj(sizeof(obj_FormaPago), init_FormaPago);
}
//----------------------------------------------------

