#include "../../includes/includelib.h"
//Includes
#include "tipo_actividad.h"

THIS(obj_TipoActividad)// crea definicion de funcion this para este modulo. .. Macro en config.h

//----------------------------------------------------
static void toString_TipoActividadImpl(void *self)
{
    obj_TipoActividad *obj=this(self);      
    // version con algunos datos, ver como gestionar la posibilidad de listar mas informacion.
    printf("\nCod: %d\nTipo Actividad: %s \nDescripcion: %s\nNivel: %d\nDuracion: %s\n",obj->getCodigo(obj),obj->getNombre(obj),obj->getDescripcion(obj),obj->getNivel(obj),obj->getDuracion(obj)); 
}

static int getCodigoTipoActividad_Impl(void *self)
{ return  *((int *) getValue(self,POS_CODIGO_TIPACT));}
//----------------------------------------------------
static char * getNombreTipoActividad_Impl(void *self)
{ return  (char *) getValue(self,POS_NOMBRE_TIPACT);}
//----------------------------------------------------
static char * getDescripcionTipoActividad_Impl(void *self)
{ return  (char *) getValue(self,POS_DESCRIPCION_TIPACT);}
//----------------------------------------------------
static char * getDuracionTipoActividad_Impl(void *self)
{ return  (char *) getValue(self,POS_DURACION_TIPACT);}
//----------------------------------------------------
static int getNivelTipoActividad_Impl(void *self)
{ return  *((int *) getValue(self,POS_NIVEL_TIPACT));}
//----------------------------------------------------

static void setCodigoTipoActividad_Impl(void *self,int val)
{ setValue(self,POS_CODIGO_TIPACT,&val); }
//----------------------------------------------------
static void setNombreTipoActividad_Impl(void *self,char * val)
{ setValue(self,POS_NOMBRE_TIPACT,val); }
//----------------------------------------------------
static void setDescripcionTipoActividad_Impl(void *self,char * val)
{ setValue(self,POS_DESCRIPCION_TIPACT,val); }
//----------------------------------------------------
static void setDuracionTipoActividad_Impl(void *self,char * val)
{ setValue(self,POS_DURACION_TIPACT,val); }
//----------------------------------------------------
static void setNivelTipoActividad_Impl(void *self,int val)
{ setValue(self,POS_NIVEL_TIPACT,&val); }
//----------------------------------------------------
//----------------------------------------------------
static void destroyInternalTIP_Impl(void *self)
{
	obj_TipoActividad *obj = this(self);	
	// finalizar cada referencia inicializada - no NULL
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------

//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_TipoActividad(void *self)
{
  obj_TipoActividad *obj      = this(self);
  obj->ds  			    = &table_TipoActividad;
  obj->constructor 	    = TipoActividad_new;
  obj->sizeObj 		    = sizeof(obj_TipoActividad*);
  // inicializar cada puntero a una referencia relacionada, para ver cuando se busca por el id..
  
  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_TipoActividadImpl;
  // Inicializar handlers de getters y setters
  /// getters
    
	obj->getCodigo = getCodigoTipoActividad_Impl;  
	obj->getNombre = getNombreTipoActividad_Impl;  
	obj->getDescripcion = getDescripcionTipoActividad_Impl;  
	obj->getDuracion = getDuracionTipoActividad_Impl;
	obj->getNivel = getNivelTipoActividad_Impl;

  /// setters  
    
	obj->setCodigo = setCodigoTipoActividad_Impl;  
	obj->setNombre = setNombreTipoActividad_Impl;  
	obj->setDescripcion = setDescripcionTipoActividad_Impl;  
	obj->setDuracion = setDuracionTipoActividad_Impl;
	obj->setNivel = setNivelTipoActividad_Impl;

  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalTIP_Impl;
  //---- acceso a relaciones  
  
  return obj;
}
//----------------------------------------------------
//constructor de TipoActividad
obj_TipoActividad *TipoActividad_new()
{
  return (obj_TipoActividad *)init_obj(sizeof(obj_TipoActividad), init_TipoActividad);
}
//----------------------------------------------------

