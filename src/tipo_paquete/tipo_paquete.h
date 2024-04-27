#ifndef TIPO_PAQ_INCLUDED
	#define TIPO_PAQ_INCLUDED
	#define CNT_COL_TIPO_PAQ 5
	#define POS_CODIGO_TIPPQ 0
	#define POS_NOMBRE_TIPPQ 1
	#define POS_DESCRIPCION_TIPPQ 2
	#define POS_DURACION_TIPPQ 3
	#define POS_NIVEL_TIPPQ 4

	//----------------------------------------------------
	typedef struct {
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters
        
	getPropertyIntPtr    getCodigo;
	getPropertyCharPtr   getNombre;        
	getPropertyCharPtr   getDescripcion;        
	getPropertyCharPtr   getDuracion;
	getPropertyIntPtr    getNivel;

	    //-- setters
        
	setPropertyIntPtr    setCodigo;        
	setPropertyCharPtr   setNombre;        
	setPropertyCharPtr   setDescripcion;        
	setPropertyCharPtr   setDuracion;
	setPropertyIntPtr    setNivel;

// getter de objeto relacionado

	}obj_TipoPaquete;
	// funcionalidad publica que se implementa en TipoPaquete.c
	extern obj_TipoPaquete *TipoPaquete_new ();
	// meta data para acceder a las TipoPaquetes - definicion de las columnas de la tabla
	static Column cols_TipoPaquete[CNT_COL_TIPO_PAQ]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
    
	{"codigo",t_int,sizeof(int),true,true},    
	{"nombre",t_varchar,(sizeof(char)*MAX60)+1,false,false},    
	{"descripcion",t_varchar,(sizeof(char)*MAX250)+1,false,false},    
	{"duracion",t_varchar,(sizeof(char)*MAX17)+1,false,false},
	{"nivel",t_int,sizeof(int),false,false},  
	};
	// plantilla para la TipoPaquete.
	static Table table_TipoPaquete={"tipo_paquete",CNT_COL_TIPO_PAQ,0, cols_TipoPaquete,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto TipoPaquete
	typedef obj_TipoPaquete *(*getTipoPaqueteObjPtr)(void *self);
#endif
