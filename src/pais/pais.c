#include "../../includes/includelib.h"
//Includes
#include "pais.h"

THIS(obj_Pais)// crea definicion de funcion this para este modulo. .. Macro en config.h

//----------------------------------------------------
static void toString_PaisImpl(void *self)
{
     obj_Pais *obj=this(self);      
     // version con algunos datos, ver como gestionar la posibilidad de listar mas informacion.
     printf("%d - %s\n",obj->getCodigo(obj),obj->getNombre(obj)); 
}

static int getCodigoPais_Impl(void *self)
{ return  *((int *) getValue(self,POS_CODIGO_PAI));}
//----------------------------------------------------
static char * getNombrePais_Impl(void *self)
{ return  (char *) getValue(self,POS_NOMBRE_PAI);}
//----------------------------------------------------
static void setCodigoPais_Impl(void *self,int val)
{ setValue(self,POS_CODIGO_PAI,&val); }
//----------------------------------------------------
static void setNombrePais_Impl(void *self,char * val)
{ setValue(self,POS_NOMBRE_PAI,val); }
//----------------------------------------------------
//----------------------------------------------------
static void destroyInternalPAI_Impl(void *self)
{
	obj_Pais *obj = this(self);	
	// finalizar cada referencia inicializada - no NULL
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------

//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_Pais(void *self)
{
  obj_Pais *obj      = this(self);
  obj->ds  			    = &table_Pais;
  obj->constructor 	    = Pais_new;
  obj->sizeObj 		    = sizeof(obj_Pais*);
  // inicializar cada puntero a una referencia relacionada, para ver cuando se busca por el id..
  
  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_PaisImpl;
  // Inicializar handlers de getters y setters
  /// getters
    
	obj->getCodigo = getCodigoPais_Impl;  
	obj->getNombre = getNombrePais_Impl;

  /// setters  
    
	obj->setCodigo = setCodigoPais_Impl;  
	obj->setNombre = setNombrePais_Impl;

  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalPAI_Impl;
  //---- acceso a relaciones  
  
  return obj;
}
//----------------------------------------------------
//constructor de Pais
obj_Pais *Pais_new()
{
  return (obj_Pais *)init_obj(sizeof(obj_Pais), init_Pais);
}
//----------------------------------------------------

