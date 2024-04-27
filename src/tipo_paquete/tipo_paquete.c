#include "../../includes/includelib.h"
//Includes
#include "tipo_paquete.h"

THIS(obj_TipoPaquete)// crea definicion de funcion this para este modulo. .. Macro en config.h

//----------------------------------------------------
static void toString_TipoPaqueteImpl(void *self)
{
     obj_TipoPaquete *obj=this(self);      
     // version con algunos datos, ver como gestionar la posibilidad de listar mas informacion.
     printf("Codigo: %d\nNombre: %s\nDescripcion: %s\nDuracion: %s\nNivel: %d\n", obj->getCodigo(obj),obj->getNombre(obj),obj->getDescripcion(obj),obj->getDuracion(obj),obj->getNivel(obj)); 
}

static int getCodigoTipoPaquete_Impl(void *self)
{ return  *((int *) getValue(self,POS_CODIGO_TIPPQ));}
//----------------------------------------------------
static char * getNombreTipoPaquete_Impl(void *self)
{ return  (char *) getValue(self,POS_NOMBRE_TIPPQ);}
//----------------------------------------------------
static char * getDescripcionTipoPaquete_Impl(void *self)
{ return  (char *) getValue(self,POS_DESCRIPCION_TIPPQ);}
//----------------------------------------------------
static char * getDuracionTipoPaquete_Impl(void *self)
{ return  (char *) getValue(self,POS_DURACION_TIPPQ);}
//----------------------------------------------------
static int getNivelTipoPaquete_Impl(void *self)
{ return  *((int *) getValue(self,POS_NIVEL_TIPPQ));}
//----------------------------------------------------

static void setCodigoTipoPaquete_Impl(void *self,int val)
{ setValue(self,POS_CODIGO_TIPPQ,&val); }
//----------------------------------------------------
static void setNombreTipoPaquete_Impl(void *self,char * val)
{ setValue(self,POS_NOMBRE_TIPPQ,val); }
//----------------------------------------------------
static void setDescripcionTipoPaquete_Impl(void *self,char * val)
{ setValue(self,POS_DESCRIPCION_TIPPQ,val); }
//----------------------------------------------------
static void setDuracionTipoPaquete_Impl(void *self,char * val)
{ setValue(self,POS_DURACION_TIPPQ,val); }
//----------------------------------------------------
static void setNivelTipoPaquete_Impl(void *self,int val)
{ setValue(self,POS_NIVEL_TIPPQ,&val); }
//----------------------------------------------------
//----------------------------------------------------
static void destroyInternalTIP_Impl(void *self)
{
	obj_TipoPaquete *obj = this(self);	
	// finalizar cada referencia inicializada - no NULL
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------

//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_TipoPaquete(void *self)
{
  obj_TipoPaquete *obj      = this(self);
  obj->ds  			    = &table_TipoPaquete;
  obj->constructor 	    = TipoPaquete_new;
  obj->sizeObj 		    = sizeof(obj_TipoPaquete*);
  // inicializar cada puntero a una referencia relacionada, para ver cuando se busca por el id..
  
  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_TipoPaqueteImpl;
  // Inicializar handlers de getters y setters
  /// getters
    
	obj->getCodigo = getCodigoTipoPaquete_Impl;  
	obj->getNombre = getNombreTipoPaquete_Impl;  
	obj->getDescripcion = getDescripcionTipoPaquete_Impl;  
	obj->getDuracion = getDuracionTipoPaquete_Impl;
	obj->getNivel = getNivelTipoPaquete_Impl;  

  /// setters  
    
	obj->setCodigo = setCodigoTipoPaquete_Impl;  
	obj->setNombre = setNombreTipoPaquete_Impl;  
	obj->setDescripcion = setDescripcionTipoPaquete_Impl;  
	obj->setDuracion = setDuracionTipoPaquete_Impl;
	obj->setNivel = setNivelTipoPaquete_Impl;  

  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalTIP_Impl;
  //---- acceso a relaciones  
  
  return obj;
}
//----------------------------------------------------
//constructor de TipoPaquete
obj_TipoPaquete *TipoPaquete_new()
{
  return (obj_TipoPaquete *)init_obj(sizeof(obj_TipoPaquete), init_TipoPaquete);
}
//----------------------------------------------------

