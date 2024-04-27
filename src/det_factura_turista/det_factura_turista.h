#ifndef DET_FACT_INCLUDED
	#define DET_FACT_INCLUDED
	#define CNT_COL_DET_FACT 6
	#define POS_NRO_FACT_DET 0
	#define POS_SERIE_FACT_DET 1
	#define POS_LETRA_FACT_DET 2
	#define POS_NRO_RENGLON_DET 3
	#define POS_COD_PAQUETE_DET 4
	#define POS_IMPORTE_DET 5

	//----------------------------------------------------
	typedef struct {
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters
        
	getPropertyIntPtr   getNroFact;        
	getPropertyIntPtr   getSerieFact;        
	getPropertyCharPtr   getLetraFact;        
	getPropertyIntPtr   getNroRenglon;        
	getPropertyIntPtr   getCodPaquete;        
	getPropertyFloatPtr   getImporte;

	    //-- setters
        
	setPropertyIntPtr   setNroFact;        
	setPropertyIntPtr   setSerieFact;        
	setPropertyCharPtr   setLetraFact;        
	setPropertyIntPtr   setNroRenglon;        
	setPropertyIntPtr   setCodPaquete;        
	setPropertyFloatPtr   setImporte;

// getter de objeto relacionado
        getFacturaTuristaObjPtr  getFacturaTuristaObj;
        obj_FacturaTurista *factura_turista;
        getPaqueteObjPtr  getPaqueteObj;
        obj_Paquete *paquete;

	}obj_DetFacturaTurista;
	// funcionalidad publica que se implementa en DetFacturaTurista.c
	extern obj_DetFacturaTurista *DetFacturaTurista_new ();
	// meta data para acceder a las DetFacturaTuristas - definicion de las columnas de la tabla
	static Column cols_DetFacturaTurista[CNT_COL_DET_FACT]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
    
	{"nro_fact",t_int,sizeof(int),true,false},    
	{"serie_fact",t_int,sizeof(int),true,false},    
	{"letra_fact",t_varchar,(sizeof(char)*MAX1)+1,true,false},    
	{"nro_renglon",t_int,sizeof(int),true,false},    
	{"cod_paquete",t_int,sizeof(int),false,false},    
	{"importe",t_float,sizeof(float),false,false},
	};
	// plantilla para la DetFacturaTurista.
	static Table table_DetFacturaTurista={"det_factura_turista",CNT_COL_DET_FACT,0, cols_DetFacturaTurista,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto DetFacturaTurista
	typedef obj_DetFacturaTurista *(*getDetFacturaTuristaObjPtr)(void *self);
#endif
