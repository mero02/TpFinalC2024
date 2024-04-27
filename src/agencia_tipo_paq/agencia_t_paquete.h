#ifndef PAQUETE_AG_INCLUDED
	#define PAQUETE_AG_INCLUDED
	#define CNT_COL_AG_TPPAQUETE_ 2
	#define POS_COD_GENCIA_TPAG 0
	#define POS_COD_TIP_PAQUETE_TPAG 1
	
	//----------------------------------------------------
	typedef struct {
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters
    getPropertyIntPtr   getCodAgencia;        	    
	getPropertyIntPtr   getCodTipoPaquete;        	

	    //-- setters
        
	setPropertyIntPtr   setCodAgencia;        	
	setPropertyIntPtr   setCodTipoPaquete;       
	

// getter de objeto relacionado
        getAgenciaObjPtr  getAgenciaObj;
        obj_Agencia *agencia;
		getTipoPaqueteObjPtr  getTipoPaqueteObj;
        obj_TipoPaquete *tipo_paquete;        

	}obj_AgenciaTPaquete;
	// funcionalidad publica que se implementa en AgenciaTPaquete.c
	extern obj_AgenciaTPaquete *AgenciaTPaquete_new ();
	// meta data para acceder a las AgenciaTPaquetes - definicion de las columnas de la tabla
	static Column cols_AgenciaTPaquete[CNT_COL_AG_TPPAQUETE_]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
    
	{"cod_agencia",t_int,sizeof(int),true,false},    
	{"cod_tipo_paquete",t_int,sizeof(int),true,false},    	
	};
	// plantilla para la AgenciaTPaquete.
	//static Table table_AgenciaTPaquete={"paquete_actividad",CNT_COL_AG_TPPAQUETE_,0, cols_AgenciaTPaquete,NULL};
	static Table table_AgenciaTPaquete={"agencia_tipo_paquete",CNT_COL_AG_TPPAQUETE_,0, cols_AgenciaTPaquete,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto AgenciaTPaquete
	typedef obj_AgenciaTPaquete *(*getAgenciaTPaqueteObjPtr)(void *self);
#endif
