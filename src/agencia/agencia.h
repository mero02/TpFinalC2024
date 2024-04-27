#ifndef AGENCIA_INCLUDED
	#define AGENCIA_INCLUDED
	#define CNT_COL_AGENCIA 9
	#define POS_CODIGO_AGE 0
	#define POS_NOMBRE_AGE 1
	#define POS_CALLE_AGE 2
	#define POS_NRO_AGE 3
	#define POS_PISO_AGE 4
	#define POS_DPTO_AGE 5
	#define POS_CODIGO_POSTAL_AGE 6
	#define POS_TEL1_AGE 7
	#define POS_TEL2_AGE 8

	//----------------------------------------------------
	typedef struct {
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters
        
	getPropertyIntPtr   getCodigo;        
	getPropertyCharPtr  getNombre;        
	getPropertyCharPtr  getCalle;        
	getPropertyCharPtr  getNro;        
	getPropertyCharPtr  getPiso;        
	getPropertyIntPtr   getDpto;        
	getPropertyIntPtr   getCodigoPostal;
	getPropertyCharPtr  getTelefono1;
	getPropertyCharPtr  getTelefono2;

	    //-- setters
        
	setPropertyIntPtr   setCodigo;        
	setPropertyCharPtr  setNombre;        
	setPropertyCharPtr  setCalle;        
	setPropertyCharPtr  setNro;        
	setPropertyCharPtr  setPiso;        
	setPropertyIntPtr   setDpto;        
	setPropertyIntPtr   setCodigoPostal;
	setPropertyCharPtr  setTelefono1;
	setPropertyCharPtr  setTelefono2;

// getter de objeto relacionado
        getLocalidadObjPtr  getLocalidadObj;
        obj_Localidad *localidad;

	}obj_Agencia;
	// funcionalidad publica que se implementa en Agencia.c
	extern obj_Agencia *Agencia_new ();
	// meta data para acceder a las Agencias - definicion de las columnas de la tabla
	static Column cols_Agencia[CNT_COL_AGENCIA]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
    
	{"codigo",t_int,sizeof(int),true,true},    
	{"nombre",t_varchar,(sizeof(char)*MAX90)+1,false,false},    
	{"calle",t_varchar,(sizeof(char)*MAX150)+1,false,false},    
	{"nro",t_varchar,(sizeof(char)*MAX7)+1,false,false},    
	{"piso",t_varchar,(sizeof(char)*MAX7)+1,false,false},    
	{"dpto",t_int,sizeof(int),false,false},    
	{"codigo_postal",t_int,sizeof(int),false,false},
	{"telefono1",t_varchar,(sizeof(char)*MAX20)+1,false,false},    
	{"telefono2",t_varchar,(sizeof(char)*MAX20)+1,false,false},    
	};
	// plantilla para la Agencia.
	static Table table_Agencia={"agencia",CNT_COL_AGENCIA,0, cols_Agencia,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto Agencia
	typedef obj_Agencia *(*getAgenciaObjPtr)(void *self);
#endif
