#include "../../includes/includelib.h"
//Includes
#include "../tipo_paquete/tipo_paquete.h"
#include "../pais/pais.h"
#include "../turista/turista.h"
#include "paquete.h"

THIS(obj_Paquete)// crea definicion de funcion this para este modulo. .. Macro en config.h

//----------------------------------------------------
static void toString_PaqueteImpl(void *self)
{
    obj_Paquete *obj=this(self);      
    obj_Turista *t = obj->getTuristaObj(obj);
    obj_TipoPaquete *tP = obj->getTipoPaqueteObj(obj);
    // version con algunos datos, ver como gestionar la posibilidad de listar mas informacion.
    printf("\nCodigo paquete: %d - Nivel: %d",obj->getCodigo(obj), obj->getNivel(obj));
    printf(" - Nombre paquete: %s\nDescripcion Tipo Paquete: %s\nDuracion: %s - ",tP->getNombre(tP), tP->getDescripcion(tP), obj->getFecha(obj));
	printf("Codigo de Agencia: %d\n",obj->getCodAgencia(obj)); 
    printf("Nombre Turista: %s - Dni: %d\n",t->getNombre(t), t->getDni(t)); 
}

static int getCodigoPaquete_Impl(void *self)
{ return  *((int *) getValue(self,POS_CODIGO_PAQ));}
//----------------------------------------------------
static int getCodTipoPaquetePaquete_Impl(void *self)
{ return  *((int *) getValue(self,POS_COD_TIPO_PAQUETE_PAQ));}
//----------------------------------------------------
static int getCodAgenciaPaquete_Impl(void *self)
{ return  *((int *) getValue(self,POS_COD_AGENCIA_PAQ));}
//----------------------------------------------------
static char * getFechaPaquete_Impl(void *self)
{ return  (char *) getValue(self,POS_FECHA_PAQ);}
//----------------------------------------------------
static int getDniTuristaPaquete_Impl(void *self)
{ return  *((int *) getValue(self,POS_DNI_TURISTA_PAQ));}
//----------------------------------------------------
static int getNivelPaquete_Impl(void *self)
{ return  *((int *) getValue(self,POS_NIVEL_PAQ));}
//----------------------------------------------------

static void setCodigoPaquete_Impl(void *self,int val)
{ setValue(self,POS_CODIGO_PAQ,&val); }
//----------------------------------------------------
static void setCodTipoPaquetePaquete_Impl(void *self,int val)
{ setValue(self,POS_COD_TIPO_PAQUETE_PAQ,&val); }
//----------------------------------------------------
static void setCodAgenciaPaquete_Impl(void *self,int val)
{ setValue(self,POS_COD_AGENCIA_PAQ,&val); }
//----------------------------------------------------
static void setFechaPaquete_Impl(void *self,char * val)
{ setValue(self,POS_FECHA_PAQ,val); }
//----------------------------------------------------
static void setDniTuristaPaquete_Impl(void *self,int val)
{ setValue(self,POS_DNI_TURISTA_PAQ,&val); }
//----------------------------------------------------
static void setNivelPaquete_Impl(void *self,int val)
{ setValue(self,POS_NIVEL_PAQ,&val); }
//----------------------------------------------------
//----------------------------------------------------
static void destroyInternalPAQ_Impl(void *self)
{
	obj_Paquete *obj = this(self);	
	// finalizar cada referencia inicializada - no NULL
		
	if(obj->tipo_paquete!=NULL)
	{
		destroyObj(obj->tipo_paquete);
		obj->tipo_paquete =  NULL;			
	}
	
	if(obj->turista!=NULL)
	{
		destroyObj(obj->turista);
		obj->turista =  NULL;			
	}
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------
obj_TipoPaquete *getPaquete_TipoPaqueteObj_Impl(void *self)
{
 obj_Paquete *obj = this(self);        //acceso a la informacion relacionada   return NULL;
 
 if(obj->tipo_paquete==NULL && obj->getCodTipoPaquete(obj)!=0)
 {
 	obj->tipo_paquete = (obj_TipoPaquete *)  TipoPaquete_new();
 	if(obj->tipo_paquete->findbykey(obj->tipo_paquete,obj->getCodTipoPaquete(obj))!=NOT_FOUND)
 	  return obj->tipo_paquete;
 }
 return obj->tipo_paquete;
}
//----------------------------------------------------
obj_Turista *getPaquete_TuristaObj_Impl(void *self)
{
 obj_Paquete *obj = this(self);        //acceso a la informacion relacionada   return NULL;
 
 if(obj->turista==NULL && obj->getDniTurista(obj)!=0)
 {
 	obj->turista = (obj_Turista *)  Turista_new();
 	if(obj->turista->findbykey(obj->turista,obj->getDniTurista(obj))!=NOT_FOUND)
 	  return obj->turista;
 }
 return obj->turista;
}
//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_Paquete(void *self)
{
  obj_Paquete *obj      = this(self);
  obj->ds  			    = &table_Paquete;
  obj->constructor 	    = Paquete_new;
  obj->sizeObj 		    = sizeof(obj_Paquete*);
  // inicializar cada puntero a una referencia relacionada, para ver cuando se busca por el id..
    obj->tipo_paquete   = NULL;
  obj->turista   = NULL;

  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_PaqueteImpl;
  // Inicializar handlers de getters y setters
  /// getters
    
	obj->getCodigo = getCodigoPaquete_Impl;  
	obj->getCodTipoPaquete = getCodTipoPaquetePaquete_Impl;  
	obj->getCodAgencia = getCodAgenciaPaquete_Impl;  
	obj->getFecha = getFechaPaquete_Impl;  
	obj->getDniTurista = getDniTuristaPaquete_Impl;
	obj->getNivel = getNivelPaquete_Impl;

  /// setters  
    
	obj->setCodigo = setCodigoPaquete_Impl;  
	obj->setCodTipoPaquete = setCodTipoPaquetePaquete_Impl;  
	obj->setCodAgencia = setCodAgenciaPaquete_Impl;  
	obj->setFecha = setFechaPaquete_Impl;  
	obj->setDniTurista = setDniTuristaPaquete_Impl;
	obj->setNivel = setNivelPaquete_Impl;

  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalPAQ_Impl;
  //---- acceso a relaciones  
    obj->getTipoPaqueteObj  = getPaquete_TipoPaqueteObj_Impl;  
	obj->getTuristaObj  = getPaquete_TuristaObj_Impl;
  return obj;
}
//----------------------------------------------------
//constructor de Paquete
obj_Paquete *Paquete_new()
{
  return (obj_Paquete *)init_obj(sizeof(obj_Paquete), init_Paquete);
}
//----------------------------------------------------

