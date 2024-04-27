#include "../../includes/includelib.h"
//Includes
#include "localidad.h"

THIS(obj_Localidad)// crea definicion de funcion this para este modulo. .. Macro en config.h

//----------------------------------------------------
static void toString_LocalidadImpl(void *self)
{
     obj_Localidad *obj=this(self);      
     // version con algunos datos, ver como gestionar la posibilidad de listar mas informacion.
     printf("%d - %s\n",obj->getCodPostal(obj),obj->getNombre(obj)); 
}

static int getCodPostalLocalidad_Impl(void *self)
{ return  *((int *) getValue(self,POS_COD_POSTAL_LOC));}
//----------------------------------------------------
static char * getNombreLocalidad_Impl(void *self)
{ return  (char *) getValue(self,POS_NOMBRE_LOC);}
//----------------------------------------------------
static void setCodPostalLocalidad_Impl(void *self,int val)
{ setValue(self,POS_COD_POSTAL_LOC,&val); }
//----------------------------------------------------
static void setNombreLocalidad_Impl(void *self,char * val)
{ setValue(self,POS_NOMBRE_LOC,val); }
//----------------------------------------------------
//----------------------------------------------------
static void destroyInternalLOC_Impl(void *self)
{
	obj_Localidad *obj = this(self);	
	// finalizar cada referencia inicializada - no NULL
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------

//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_Localidad(void *self)
{
  obj_Localidad *obj      = this(self);
  obj->ds  			    = &table_Localidad;
  obj->constructor 	    = Localidad_new;
  obj->sizeObj 		    = sizeof(obj_Localidad*);
  // inicializar cada puntero a una referencia relacionada, para ver cuando se busca por el id..
  
  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_LocalidadImpl;
  // Inicializar handlers de getters y setters
  /// getters
    
	obj->getCodPostal = getCodPostalLocalidad_Impl;  
	obj->getNombre = getNombreLocalidad_Impl;

  /// setters  
    
	obj->setCodPostal = setCodPostalLocalidad_Impl;  
	obj->setNombre = setNombreLocalidad_Impl;

  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalLOC_Impl;
  //---- acceso a relaciones  
  
  return obj;
}
//----------------------------------------------------
//constructor de Localidad
obj_Localidad *Localidad_new()
{
  return (obj_Localidad *)init_obj(sizeof(obj_Localidad), init_Localidad);
}
//----------------------------------------------------

