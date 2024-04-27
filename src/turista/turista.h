#ifndef TURISTA_INCLUDED
	#define TURISTA_INCLUDED
	#define CNT_COL_TURISTA 5
	#define POS_DNI_TUR 0
	#define POS_NOMBRE_TUR 1
	#define POS_DOMICILIO_TUR 2
	#define POS_TELEFONO_TUR 3
	#define POS_COD_PAIS_TUR 4

	//----------------------------------------------------
	typedef struct {
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters
        
	getPropertyIntPtr   getDni;        
	getPropertyCharPtr   getNombre;        
	getPropertyCharPtr   getDomicilio;        
	getPropertyCharPtr   getTelefono;        
	getPropertyIntPtr   getCodPais;

	    //-- setters
        
	setPropertyIntPtr   setDni;        
	setPropertyCharPtr   setNombre;        
	setPropertyCharPtr   setDomicilio;        
	setPropertyCharPtr   setTelefono;        
	setPropertyIntPtr   setCodPais;

// getter de objeto relacionado
        getPaisObjPtr  getPaisObj;
        obj_Pais *pais;

	}obj_Turista;
	// funcionalidad publica que se implementa en Turista.c
	extern obj_Turista *Turista_new ();
	// meta data para acceder a las Turistas - definicion de las columnas de la tabla
	static Column cols_Turista[CNT_COL_TURISTA]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
    
	{"dni",t_int,sizeof(int),true,false},    
	{"nombre",t_varchar,(sizeof(char)*MAX90)+1,false,false},    
	{"domicilio",t_varchar,(sizeof(char)*MAX150)+1,false,false},    
	{"telefono",t_varchar,(sizeof(char)*MAX50)+1,false,false},    
	{"cod_pais",t_int,sizeof(int),false,false},
	};
	// plantilla para la Turista.
	static Table table_Turista={"turista",CNT_COL_TURISTA,0, cols_Turista,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto Turista
	typedef obj_Turista *(*getTuristaObjPtr)(void *self);
#endif
