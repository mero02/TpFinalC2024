#ifndef TIPO_PAQ_TACINCLUDED
	#define TIPO_PAQ_TACINCLUDED
	#define CNT_COL_TIPO_PAQTAC 2
	#define POS_COD_TIPO_PAQUETE_TIP 0
	#define POS_COD_TIPO_ACTIVIDAD_TIP 1

	//----------------------------------------------------
	typedef struct {
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters
        
	getPropertyIntPtr   getCodTipoPaquete;        
	getPropertyIntPtr   getCodTipoActividad;

	    //-- setters
        
	setPropertyIntPtr   setCodTipoPaquete;        
	setPropertyIntPtr   setCodTipoActividad;

// getter de objeto relacionado
        getTipoPaqueteObjPtr  getTipoPaqueteObj;
        obj_TipoPaquete *tipo_paquete;
        getTipoActividadObjPtr  getTipoActividadObj;
        obj_TipoActividad *tipo_actividad;

	}obj_TipoPaqueteTipoActividad;
	// funcionalidad publica que se implementa en TipoPaqueteTipoActividad.c
	extern obj_TipoPaqueteTipoActividad *TipoPaqueteTipoActividad_new ();
	// meta data para acceder a las TipoPaqueteTipoActividads - definicion de las columnas de la tabla
	static Column cols_TipoPaqueteTipoActividad[CNT_COL_TIPO_PAQTAC]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
    
	{"cod_tipo_paquete",t_int,sizeof(int),true,false},    
	{"cod_tipo_actividad",t_int,sizeof(int),true,false},
	};
	// plantilla para la TipoPaqueteTipoActividad.
	static Table table_TipoPaqueteTipoActividad={"tipo_paquete_tipo_actividad",CNT_COL_TIPO_PAQTAC,0, cols_TipoPaqueteTipoActividad,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto TipoPaqueteTipoActividad
	typedef obj_TipoPaqueteTipoActividad *(*getTipoPaqueteTipoActividadObjPtr)(void *self);
#endif
