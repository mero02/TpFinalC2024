#ifndef PAQUETE__INCLUDED
	#define PAQUETE__INCLUDED
	#define CNT_COL_PAQUETE_ 6
	#define POS_COD_PAQUETE_PAQ 0
	#define POS_COD_ACTIVIDAD_PAQ 1
	#define POS_IMPORTE_PAQ 2
	#define POS_FECHA_HORA_DESDE_PAQ 3
	#define POS_FECHA_HORA_HASTA_PAQ 4
	#define POS_DETALLE_PAQ 5

	//----------------------------------------------------
	typedef struct {
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters
        
	getPropertyIntPtr   getCodPaquete;        
	getPropertyIntPtr   getCodActividad;        
	getPropertyFloatPtr   getImporte;        
	getPropertyCharPtr   getFechaHoraDesde;        
	getPropertyCharPtr   getFechaHoraHasta;        
	getPropertyCharPtr   getDetalle;

	    //-- setters
        
	setPropertyIntPtr   setCodPaquete;        
	setPropertyIntPtr   setCodActividad;        
	setPropertyFloatPtr   setImporte;        
	setPropertyCharPtr   setFechaHoraDesde;        
	setPropertyCharPtr   setFechaHoraHasta;        
	setPropertyCharPtr   setDetalle;

// getter de objeto relacionado
        getPaqueteObjPtr  getPaqueteObj;
        obj_Paquete *paquete;
        getActividadObjPtr  getActividadObj;
        obj_Actividad *actividad;

	}obj_PaqueteActividad;
	// funcionalidad publica que se implementa en PaqueteActividad.c
	extern obj_PaqueteActividad *PaqueteActividad_new ();
	// meta data para acceder a las PaqueteActividads - definicion de las columnas de la tabla
	static Column cols_PaqueteActividad[CNT_COL_PAQUETE_]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
    
	{"cod_paquete",t_int,sizeof(int),true,false},    
	{"cod_actividad",t_int,sizeof(int),true,false},    
	{"importe",t_float,sizeof(float),false,false},    
	{"fecha_hora_desde",t_varchar,(sizeof(char)*MAX17)+1,false,false},    
	{"fecha_hora_hasta",t_varchar,(sizeof(char)*MAX17)+1,false,false},    
	{"detalle",t_varchar,(sizeof(char)*MAX120)+1,false,false},
	};
	// plantilla para la PaqueteActividad.
	static Table table_PaqueteActividad={"paquete_actividad",CNT_COL_PAQUETE_,0, cols_PaqueteActividad,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto PaqueteActividad
	typedef obj_PaqueteActividad *(*getPaqueteActividadObjPtr)(void *self);
#endif
