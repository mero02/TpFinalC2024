#ifndef TIPO_ACT_INCLUDED
	#define TIPO_ACT_INCLUDED
	#define CNT_COL_TIPO_ACT 5
	#define POS_CODIGO_TIPACT 0
	#define POS_NOMBRE_TIPACT 1
	#define POS_DESCRIPCION_TIPACT 2
	#define POS_DURACION_TIPACT 3
	#define POS_NIVEL_TIPACT 4

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

	}obj_TipoActividad;
	// funcionalidad publica que se implementa en TipoActividad.c
	extern obj_TipoActividad *TipoActividad_new ();
	// meta data para acceder a las TipoActividads - definicion de las columnas de la tabla
	static Column cols_TipoActividad[CNT_COL_TIPO_ACT]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
    
	{"codigo",t_int,sizeof(int),true,true},    
	{"nombre",t_varchar,(sizeof(char)*MAX60)+1,false,false},    
	{"descripcion",t_varchar,(sizeof(char)*MAX250)+1,false,false},    
	{"duracion",t_varchar,(sizeof(char)*MAX5)+1,false,false},
	{"nivel",t_int,sizeof(int),false,false},  
	};
	// plantilla para la TipoActividad.
	static Table table_TipoActividad={"tipo_actividad",CNT_COL_TIPO_ACT,0, cols_TipoActividad,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto TipoActividad
	typedef obj_TipoActividad *(*getTipoActividadObjPtr)(void *self);
#endif
