#include "../../includes/includelib.h"
//Includes
#include "../pais/pais.h"
#include "../forma_pago/forma_pago.h"
#include "../turista/turista.h"
#include "../factura_turista/factura_turista.h"
#include "../tipo_paquete/tipo_paquete.h"
#include "../paquete/paquete.h"
#include "det_factura_turista.h"

THIS(obj_DetFacturaTurista)// crea definicion de funcion this para este modulo. .. Macro en config.h

//----------------------------------------------------
static void toString_DetFacturaTuristaImpl(void *self)
{
     obj_DetFacturaTurista *obj=this(self);
	 obj_FacturaTurista *fT = obj->getFacturaTuristaObj(obj);
	 obj_Paquete *P = obj->getPaqueteObj(obj);      
     // version con algunos datos, ver como gestionar la posibilidad de listar mas informacion.
     printf("Numero Renglon: %d - Codigo Paquete: %d - Importe: %.2f",obj->getNroRenglon(obj),obj->getCodPaquete(obj),obj->getImporte(obj));

}

static int getNroFactDetFacturaTurista_Impl(void *self)
{ return  *((int *) getValue(self,POS_NRO_FACT_DET));}
//----------------------------------------------------
static int getSerieFactDetFacturaTurista_Impl(void *self)
{ return  *((int *) getValue(self,POS_SERIE_FACT_DET));}
//----------------------------------------------------
static char * getLetraFactDetFacturaTurista_Impl(void *self)
{ return  (char *) getValue(self,POS_LETRA_FACT_DET);}
//----------------------------------------------------
static int getNroRenglonDetFacturaTurista_Impl(void *self)
{ return  *((int *) getValue(self,POS_NRO_RENGLON_DET));}
//----------------------------------------------------
static int getCodPaqueteDetFacturaTurista_Impl(void *self)
{ return  *((int *) getValue(self,POS_COD_PAQUETE_DET));}
//----------------------------------------------------
static float getImporteDetFacturaTurista_Impl(void *self)
{ return  *((float *) getValue(self,POS_IMPORTE_DET));}
//----------------------------------------------------
static void setNroFactDetFacturaTurista_Impl(void *self,int val)
{ setValue(self,POS_NRO_FACT_DET,&val); }
//----------------------------------------------------
static void setSerieFactDetFacturaTurista_Impl(void *self,int val)
{ setValue(self,POS_SERIE_FACT_DET,&val); }
//----------------------------------------------------
static void setLetraFactDetFacturaTurista_Impl(void *self,char * val)
{ setValue(self,POS_LETRA_FACT_DET,val); }//el codigo original estaba asi &val
//----------------------------------------------------
static void setNroRenglonDetFacturaTurista_Impl(void *self,int val)
{ setValue(self,POS_NRO_RENGLON_DET,&val); }
//----------------------------------------------------
static void setCodPaqueteDetFacturaTurista_Impl(void *self,int val)
{ setValue(self,POS_COD_PAQUETE_DET,&val); }
//----------------------------------------------------
static void setImporteDetFacturaTurista_Impl(void *self,float val)
{ setValue(self,POS_IMPORTE_DET,&val); }
//----------------------------------------------------
static void destroyInternalDET_Impl(void *self)
{
	obj_DetFacturaTurista *obj = this(self);	
	// finalizar cada referencia inicializada - no NULL
	
	if(obj->paquete!=NULL)
	{
		destroyObj(obj->paquete);
		obj->paquete =  NULL;			
	}
	
	if(obj->factura_turista!=NULL)
	{
		destroyObj(obj->factura_turista);
		obj->factura_turista =  NULL;			
	}
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------
obj_FacturaTurista *getDetFacturaTurista_FacturaTuristaObj_Impl(void *self)
{
 obj_DetFacturaTurista *obj = this(self);        //acceso a la informacion relacionada   return NULL;
 
 if(obj->factura_turista==NULL && obj->getNroFact(obj)!=0)
 {
 	obj->factura_turista = (obj_FacturaTurista *)  FacturaTurista_new();
 	if(obj->factura_turista->findbykey(obj->factura_turista,obj->getNroFact(obj))!=NOT_FOUND)
 	  return obj->factura_turista;
 }
 return obj->factura_turista;
}
//----------------------------------------------------
obj_Paquete *getDetFacturaTurista_PaqueteObj_Impl(void *self)
{
 obj_DetFacturaTurista *obj = this(self);        //acceso a la informacion relacionada   return NULL;
 
 if(obj->paquete==NULL && obj->getCodPaquete(obj)!=0)
 {
 	obj->paquete = (obj_Paquete *)  Paquete_new();
 	if(obj->paquete->findbykey(obj->paquete,obj->getCodPaquete(obj))!=NOT_FOUND)
 	  return obj->paquete;
 }
 return obj->paquete;
}
//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_DetFacturaTurista(void *self)
{
  obj_DetFacturaTurista *obj      = this(self);
  obj->ds  			    = &table_DetFacturaTurista;
  obj->constructor 	    = DetFacturaTurista_new;
  obj->sizeObj 		    = sizeof(obj_DetFacturaTurista*);
  // inicializar cada puntero a una referencia relacionada, para ver cuando se busca por el id..
    obj->factura_turista   = NULL;
  obj->paquete   = NULL;

  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_DetFacturaTuristaImpl;
  // Inicializar handlers de getters y setters
  /// getters
    
	obj->getNroFact = getNroFactDetFacturaTurista_Impl;  
	obj->getSerieFact = getSerieFactDetFacturaTurista_Impl;  
	obj->getLetraFact = getLetraFactDetFacturaTurista_Impl;  
	obj->getNroRenglon = getNroRenglonDetFacturaTurista_Impl;  
	obj->getCodPaquete = getCodPaqueteDetFacturaTurista_Impl;  
	obj->getImporte = getImporteDetFacturaTurista_Impl;

  /// setters  
    
	obj->setNroFact = setNroFactDetFacturaTurista_Impl;  
	obj->setSerieFact = setSerieFactDetFacturaTurista_Impl;  
	obj->setLetraFact = setLetraFactDetFacturaTurista_Impl;  
	obj->setNroRenglon = setNroRenglonDetFacturaTurista_Impl;  
	obj->setCodPaquete = setCodPaqueteDetFacturaTurista_Impl;  
	obj->setImporte = setImporteDetFacturaTurista_Impl;

  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalDET_Impl;
  //---- acceso a relaciones  
    obj->getFacturaTuristaObj  = getDetFacturaTurista_FacturaTuristaObj_Impl;  
	obj->getPaqueteObj  = getDetFacturaTurista_PaqueteObj_Impl;
  return obj;
}
//----------------------------------------------------
//constructor de DetFacturaTurista
obj_DetFacturaTurista *DetFacturaTurista_new()
{
  return (obj_DetFacturaTurista *)init_obj(sizeof(obj_DetFacturaTurista), init_DetFacturaTurista);
}
//----------------------------------------------------

