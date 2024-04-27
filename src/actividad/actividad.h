#ifndef ACTIVIDA_INCLUDED
	#define ACTIVIDA_INCLUDED
	#define CNT_COL_ACTIVIDA 5
	#define POS_CODIGO_ACT 0
	#define POS_COD_TIPO_ACTIVIDAD_ACT 1
	#define POS_COD_TRANSPORTE_ACT 2
	#define POS_IMPORTE_ACT 3
	#define POS_NIVEL_ACT 4
	//----------------------------------------------------
	typedef struct {
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters
        
	getPropertyIntPtr   getCodigo;        
	getPropertyIntPtr   getCodTipoActividad;        
	getPropertyIntPtr   getCodTransporte;        
	getPropertyFloatPtr getImporte;
	getPropertyIntPtr   getNivel;
	
	    //-- setters
        
	setPropertyIntPtr   setCodigo;        
	setPropertyIntPtr   setCodTipoActividad;        
	setPropertyIntPtr   setCodTransporte;        
	setPropertyFloatPtr setImporte;
	setPropertyIntPtr   setNivel;

// getter de objeto relacionado
        getTipoActividadObjPtr  getTipoActividadObj;
        obj_TipoActividad *tipo_actividad;
        getTransporteObjPtr  getTransporteObj;
        obj_Transporte *transporte;

	}obj_Actividad;
	// funcionalidad publica que se implementa en Actividad.c
	extern obj_Actividad *Actividad_new ();
	// meta data para acceder a las Actividads - definicion de las columnas de la tabla
	static Column cols_Actividad[CNT_COL_ACTIVIDA]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
    
	{"codigo",t_int,sizeof(int),true,true},    
	{"cod_tipo_actividad",t_int,sizeof(int),false,false},    
	{"cod_transporte",t_int,sizeof(int),false,false},    
	{"importe",t_float,sizeof(float),false,false},
	{"nivel",t_int,sizeof(int),false,false},  
	};
	// plantilla para la Actividad.
	static Table table_Actividad={"actividad",CNT_COL_ACTIVIDA,0, cols_Actividad,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto Actividad
	typedef obj_Actividad *(*getActividadObjPtr)(void *self);
#endif
