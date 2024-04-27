#include "../../includes/includelib.h"
//Includes
#include "../pais/pais.h"
#include "turista.h"

THIS(obj_Turista)// crea definicion de funcion this para este modulo. .. Macro en config.h

//----------------------------------------------------
static void toString_TuristaImpl(void *self)
{
     obj_Turista *obj=this(self);      
     obj_Pais *p = obj->getPaisObj(obj);
     // version con algunos datos, ver como gestionar la posibilidad de listar mas informacion.
     printf("Turista: %d - %s - pais:%s\n",obj->getDni(obj),obj->getNombre(obj),p->getNombre(p));
}

static int getDniTurista_Impl(void *self)
{ return  *((int *) getValue(self,POS_DNI_TUR));}
//----------------------------------------------------
static char * getNombreTurista_Impl(void *self)
{ return  (char *) getValue(self,POS_NOMBRE_TUR);}
//----------------------------------------------------
static char * getDomicilioTurista_Impl(void *self)
{ return  (char *) getValue(self,POS_DOMICILIO_TUR);}
//----------------------------------------------------
static char * getTelefonoTurista_Impl(void *self)
{ return  (char *) getValue(self,POS_TELEFONO_TUR);}
//----------------------------------------------------
static int getCodPaisTurista_Impl(void *self)
{ return  *((int *) getValue(self,POS_COD_PAIS_TUR));}
//----------------------------------------------------
static void setDniTurista_Impl(void *self,int val)
{ setValue(self,POS_DNI_TUR,&val); }
//----------------------------------------------------
static void setNombreTurista_Impl(void *self,char * val)
{ setValue(self,POS_NOMBRE_TUR,val); }
//----------------------------------------------------
static void setDomicilioTurista_Impl(void *self,char * val)
{ setValue(self,POS_DOMICILIO_TUR,val); }
//----------------------------------------------------
static void setTelefonoTurista_Impl(void *self,char * val)
{ setValue(self,POS_TELEFONO_TUR,val); }
//----------------------------------------------------
static void setCodPaisTurista_Impl(void *self,int val)
{ setValue(self,POS_COD_PAIS_TUR,&val); }
//----------------------------------------------------
//----------------------------------------------------
static void destroyInternalTUR_Impl(void *self)
{
	obj_Turista *obj = this(self);	
	if(obj->pais!=NULL)
	{
		destroyObj(obj->pais);
		obj->pais =  NULL;			
	}
	// finalizar cada referencia inicializada - no NULL
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------
obj_Pais *getTurista_PaisObj_Impl(void *self)
{
 obj_Turista *obj = this(self);        //acceso a la informacion relacionada   return NULL;
 if(obj->pais==NULL && obj->getCodPais(obj)!=0)
 {
 	obj->pais = (obj_Pais *)  Pais_new();
 	if(obj->pais->findbykey(obj->pais,obj->getCodPais(obj))!=NOT_FOUND)
 	  return obj->pais;
 }
 return obj->pais;
}
//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_Turista(void *self)
{
  obj_Turista *obj      = this(self);
  obj->ds  			    = &table_Turista;
  obj->constructor 	    = Turista_new;
  obj->sizeObj 		    = sizeof(obj_Turista*);
  // inicializar cada puntero a una referencia relacionada, para ver cuando se busca por el id..
  obj->pais   = NULL;

  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_TuristaImpl;
  // Inicializar handlers de getters y setters
  /// getters
    
	obj->getDni = getDniTurista_Impl;  
	obj->getNombre = getNombreTurista_Impl;  
	obj->getDomicilio = getDomicilioTurista_Impl;  
	obj->getTelefono = getTelefonoTurista_Impl;  
	obj->getCodPais = getCodPaisTurista_Impl;

  /// setters  
    
	obj->setDni = setDniTurista_Impl;  
	obj->setNombre = setNombreTurista_Impl;  
	obj->setDomicilio = setDomicilioTurista_Impl;  
	obj->setTelefono = setTelefonoTurista_Impl;  
	obj->setCodPais = setCodPaisTurista_Impl;

  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalTUR_Impl;
  //---- acceso a relaciones  
    obj->getPaisObj  = getTurista_PaisObj_Impl;
  return obj;
}
//----------------------------------------------------
//constructor de Turista
obj_Turista *Turista_new()
{
  return (obj_Turista *)init_obj(sizeof(obj_Turista), init_Turista);
}
//----------------------------------------------------

