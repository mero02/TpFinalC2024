#include "../../includes/includelib.h"
//Includes
#include "../pais/pais.h"
#include "../forma_pago/forma_pago.h"
#include "../turista/turista.h"
#include "factura_turista.h"

#include <string.h>

THIS(obj_FacturaTurista)// crea definicion de funcion this para este modulo. .. Macro en config.h

//----------------------------------------------------
static void toString_FacturaTuristaImpl(void *self)
{
     obj_FacturaTurista *obj=this(self);
	 obj_FormaPago *t = obj->getFormaPagoObj(obj);     
     // version con algunos datos, ver como gestionar la posibilidad de listar mas informacion.
     printf("Nro: %d - Serie: %d - Letra: %s\nFecha: %s\nForma de pago: %s\nDetalle: %s\n", obj->getNro(obj), obj->getSerie(obj), obj->getLetra(obj),obj->getFecha(obj),t->getForma(t), obj->getDetPago(obj)); 
}

static int getNroFacturaTurista_Impl(void *self)
{ return  *((int *) getValue(self,POS_NRO_FAC));}
//----------------------------------------------------
static int getSerieFacturaTurista_Impl(void *self)
{ return  *((int *) getValue(self,POS_SERIE_FAC));}
//----------------------------------------------------
static char * getLetraFacturaTurista_Impl(void *self)
{ return  (char *) getValue(self,POS_LETRA_FAC);}
//----------------------------------------------------
static char * getFechaFacturaTurista_Impl(void *self)
{ return  (char *) getValue(self,POS_FECHA_FAC);}
//----------------------------------------------------
static int getDniTuristaFacturaTurista_Impl(void *self)
{ return  *((int *) getValue(self,POS_DNI_TURISTA_FAC));}
//----------------------------------------------------
static int getCodFormaPagoFacturaTurista_Impl(void *self)
{ return  *((int *) getValue(self,POS_COD_FORMA_PAGO_FAC));}
//----------------------------------------------------
static char * getDetPagoFacturaTurista_Impl(void *self)
{ return  (char *) getValue(self,POS_DET_PAGO_FAC);}
//----------------------------------------------------
static void setNroFacturaTurista_Impl(void *self,int val)
{ setValue(self,POS_NRO_FAC,&val); }
//----------------------------------------------------
static void setSerieFacturaTurista_Impl(void *self,int val)
{ setValue(self,POS_SERIE_FAC,&val); }
//----------------------------------------------------
static void setLetraFacturaTurista_Impl(void *self,char * val)
{ setValue(self,POS_LETRA_FAC,val); }
//----------------------------------------------------
static void setFechaFacturaTurista_Impl(void *self,char * val)
{ setValue(self,POS_FECHA_FAC,val); }
//----------------------------------------------------
static void setDniTuristaFacturaTurista_Impl(void *self,int val)
{ setValue(self,POS_DNI_TURISTA_FAC,&val); }
//----------------------------------------------------
static void setCodFormaPagoFacturaTurista_Impl(void *self,int val)
{ setValue(self,POS_COD_FORMA_PAGO_FAC,&val); }
//----------------------------------------------------
static void setDetPagoFacturaTurista_Impl(void *self,char * val)
{ setValue(self,POS_DET_PAGO_FAC,val); }
//----------------------------------------------------

//----------------------------------------------------
static void destroyInternalFAC_Impl(void *self)
{
	obj_FacturaTurista *obj = this(self);	
	// finalizar cada referencia inicializada - no NULL
	
	if(obj->turista!=NULL)
	{
		destroyObj(obj->turista);
		obj->turista =  NULL;			
	}
	
	if(obj->forma_pago!=NULL)
	{
		destroyObj(obj->forma_pago);
		obj->forma_pago =  NULL;			
	}
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------
obj_FormaPago *getFacturaTurista_FormaPagoObj_Impl(void *self)
{
 obj_FacturaTurista *obj = this(self);        //acceso a la informacion relacionada   return NULL;
 
 if(obj->forma_pago==NULL && obj->getCodFormaPago(obj)!=0)
 {
 	obj->forma_pago = (obj_FormaPago *)  FormaPago_new();
 	if(obj->forma_pago->findbykey(obj->forma_pago,obj->getCodFormaPago(obj))!=NOT_FOUND)
 	  return obj->forma_pago;
 }
 return obj->forma_pago;
}
//----------------------------------------------------
obj_Turista *getFacturaTurista_TuristaObj_Impl(void *self)
{
 obj_FacturaTurista *obj = this(self);        //acceso a la informacion relacionada   return NULL;
 
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
static void *init_FacturaTurista(void *self)
{
  obj_FacturaTurista *obj      = this(self);
  obj->ds  			    = &table_FacturaTurista;
  obj->constructor 	    = FacturaTurista_new;
  obj->sizeObj 		    = sizeof(obj_FacturaTurista*);
  // inicializar cada puntero a una referencia relacionada, para ver cuando se busca por el id..
    obj->forma_pago   = NULL;
  obj->turista   = NULL;

  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_FacturaTuristaImpl;
  // Inicializar handlers de getters y setters
  /// getters
    
	obj->getNro = getNroFacturaTurista_Impl;  
	obj->getSerie = getSerieFacturaTurista_Impl;  
	obj->getLetra = getLetraFacturaTurista_Impl;  
	obj->getFecha = getFechaFacturaTurista_Impl;  
	obj->getDniTurista = getDniTuristaFacturaTurista_Impl;  
	obj->getCodFormaPago = getCodFormaPagoFacturaTurista_Impl;  
	obj->getDetPago = getDetPagoFacturaTurista_Impl;

  /// setters  
    
	obj->setNro = setNroFacturaTurista_Impl;  
	obj->setSerie = setSerieFacturaTurista_Impl;  
	obj->setLetra = setLetraFacturaTurista_Impl;  
	obj->setFecha = setFechaFacturaTurista_Impl;  
	obj->setDniTurista = setDniTuristaFacturaTurista_Impl;  
	obj->setCodFormaPago = setCodFormaPagoFacturaTurista_Impl;  
	obj->setDetPago = setDetPagoFacturaTurista_Impl;

  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalFAC_Impl;
  //---- acceso a relaciones  
    obj->getFormaPagoObj  = getFacturaTurista_FormaPagoObj_Impl;  
	obj->getTuristaObj  = getFacturaTurista_TuristaObj_Impl;
  return obj;
}

obj_FacturaTurista *FacturaTurista_new_Letra_Serie(char *letra)
{
	obj_FacturaTurista *rta,*obj = FacturaTurista_new(),*itm;
	char sql[MAX_SQL];
	void *list;
	int i, size;
	memset(sql,'\0',MAX_SQL);
	sprintf(sql,"letra='%s' order by nro desc,serie desc",letra);
	size = obj->findAll(obj,&list,sql);
	if(size>0)
	{  
		itm = ((obj_FacturaTurista **)list)[0];
	 	rta= FacturaTurista_new();
	 	rta->setLetra(rta,letra);
	 	rta->setSerie(rta,itm->getSerie(itm));
	 	rta->setNro(rta,itm->getNro(itm)+1);
	 	//Si se desea manejar un incremento de la serie dada una numeracion de facturas, se puede incrementar
	 	// o sea si Nro > un MAX, se avanza a nueva Serie y Nro comienza en 1 de nuevo en esa letra
	 	/* //opcional
	 	  if(itm->getNro(itm)+1>MAX_NRO_FACT_LETRA)
	 	    {
	 	    	rta->setNro(rta,1);
	 	    	rta->setSerie(rta,rta->getSerie(rta)+1);
	 		}
	 	*/
	 	destroyObjList(list,size);
	 	destroyObj(obj);
		return rta;
	}
	else
	{
		rta= FacturaTurista_new();
	 	rta->setLetra(rta,letra);
	 	rta->setSerie(rta,1);
	 	rta->setNro(rta,1);
	 	destroyObj(obj);
		return rta;
	}
}


//----------------------------------------------------
//constructor de FacturaTurista
obj_FacturaTurista *FacturaTurista_new()
{
  return (obj_FacturaTurista *)init_obj(sizeof(obj_FacturaTurista), init_FacturaTurista);
}
//----------------------------------------------------

