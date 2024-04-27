#ifndef PAQUETE_INCLUDED
	#define PAQUETE_INCLUDED
	#define CNT_COL_PAQUETE 6
	#define POS_CODIGO_PAQ 0
	#define POS_COD_TIPO_PAQUETE_PAQ 1
	#define POS_COD_AGENCIA_PAQ 2
	#define POS_FECHA_PAQ 3
	#define POS_DNI_TURISTA_PAQ 4
	#define POS_NIVEL_PAQ 5

	//----------------------------------------------------
	typedef struct {
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters
        
	getPropertyIntPtr   getCodigo;        
	getPropertyIntPtr   getCodTipoPaquete;        
	getPropertyIntPtr   getCodAgencia;        
	getPropertyCharPtr  getFecha;        
	getPropertyIntPtr   getDniTurista;
	getPropertyIntPtr   getNivel;

	    //-- setters
        
	setPropertyIntPtr   setCodigo;        
	setPropertyIntPtr   setCodTipoPaquete;        
	setPropertyIntPtr   setCodAgencia;        
	setPropertyCharPtr  setFecha;        
	setPropertyIntPtr   setDniTurista;
	setPropertyIntPtr   setNivel;

// getter de objeto relacionado
        getTipoPaqueteObjPtr  getTipoPaqueteObj;
        obj_TipoPaquete *tipo_paquete;
        getTuristaObjPtr  getTuristaObj;
        obj_Turista *turista;

	}obj_Paquete;
	// funcionalidad publica que se implementa en Paquete.c
	extern obj_Paquete *Paquete_new ();
	// meta data para acceder a las Paquetes - definicion de las columnas de la tabla
	static Column cols_Paquete[CNT_COL_PAQUETE]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
    
	{"codigo",t_int,sizeof(int),true,true},    
	{"cod_tipo_paquete",t_int,sizeof(int),false,false},    
	{"cod_agencia",t_int,sizeof(int),false,false},    
	{"fecha",t_varchar,(sizeof(char)*MAX10)+1,false,false},    
	{"dni_turista",t_int,sizeof(int),false,false},
	{"nivel",t_int,sizeof(int),false,false},  
	};
	// plantilla para la Paquete.
	static Table table_Paquete={"paquete",CNT_COL_PAQUETE,0, cols_Paquete,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto Paquete
	typedef obj_Paquete *(*getPaqueteObjPtr)(void *self);
#endif
