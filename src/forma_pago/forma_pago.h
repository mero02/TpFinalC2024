#ifndef FORMA_PA_INCLUDED
	#define FORMA_PA_INCLUDED
	#define CNT_COL_FORMA_PA 2
	#define POS_CODIGO_FOR 0
	#define POS_FORMA_FOR 1

	//----------------------------------------------------
	typedef struct {
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters
        
	getPropertyIntPtr   getCodigo;        
	getPropertyCharPtr   getForma;

	    //-- setters
        
	setPropertyIntPtr   setCodigo;        
	setPropertyCharPtr   setForma;

// getter de objeto relacionado

	}obj_FormaPago;
	// funcionalidad publica que se implementa en FormaPago.c
	extern obj_FormaPago *FormaPago_new ();
	// meta data para acceder a las FormaPagos - definicion de las columnas de la tabla
	static Column cols_FormaPago[CNT_COL_FORMA_PA]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
    
	{"codigo",t_int,sizeof(int),true,true},    
	{"forma",t_varchar,(sizeof(char)*MAX50)+1,false,false},
	};
	// plantilla para la FormaPago.
	static Table table_FormaPago={"forma_pago",CNT_COL_FORMA_PA,0, cols_FormaPago,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto FormaPago
	typedef obj_FormaPago *(*getFormaPagoObjPtr)(void *self);
#endif
