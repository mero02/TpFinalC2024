#ifndef TRANSPOR_INCLUDED
	#define TRANSPOR_INCLUDED
	#define CNT_COL_TRANSPOR 4
	#define POS_CODIGO_TRA 0
	#define POS_DOMINIO_TRA 1
	#define POS_DESCRIPCION_TRA 2
	#define POS_IMPORTE_TRA 3

	//----------------------------------------------------
	typedef struct {
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters
        
	getPropertyIntPtr   getCodigo;        
	getPropertyCharPtr   getDominio;        
	getPropertyCharPtr   getDescripcion;        
	getPropertyFloatPtr   getImporte;

	    //-- setters
        
	setPropertyIntPtr   setCodigo;        
	setPropertyCharPtr   setDominio;        
	setPropertyCharPtr   setDescripcion;        
	setPropertyFloatPtr   setImporte;

// getter de objeto relacionado

	}obj_Transporte;
	// funcionalidad publica que se implementa en Transporte.c
	extern obj_Transporte *Transporte_new ();
	// meta data para acceder a las Transportes - definicion de las columnas de la tabla
	static Column cols_Transporte[CNT_COL_TRANSPOR]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
    
	{"codigo",t_int,sizeof(int),true,true},    
	{"dominio",t_varchar,(sizeof(char)*MAX15)+1,false,false},    
	{"descripcion",t_varchar,(sizeof(char)*MAX150)+1,false,false},    
	{"importe",t_float,sizeof(float),false,false},
	};
	// plantilla para la Transporte.
	static Table table_Transporte={"transporte",CNT_COL_TRANSPOR,0, cols_Transporte,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto Transporte
	typedef obj_Transporte *(*getTransporteObjPtr)(void *self);
#endif
