#ifndef PAIS_INCLUDED
	#define PAIS_INCLUDED
	#define CNT_COL_PAIS 2
	#define POS_CODIGO_PAI 0
	#define POS_NOMBRE_PAI 1

	//----------------------------------------------------
	typedef struct {
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters
        
	getPropertyIntPtr   getCodigo;        
	getPropertyCharPtr   getNombre;

	    //-- setters
        
	setPropertyIntPtr   setCodigo;        
	setPropertyCharPtr   setNombre;

// getter de objeto relacionado

	}obj_Pais;
	// funcionalidad publica que se implementa en Pais.c
	extern obj_Pais *Pais_new ();
	// meta data para acceder a las Paiss - definicion de las columnas de la tabla
	static Column cols_Pais[CNT_COL_PAIS]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
    
	{"codigo",t_int,sizeof(int),true,true},    
	{"nombre",t_varchar,(sizeof(char)*MAX60)+1,false,false},
	};
	// plantilla para la Pais.
	static Table table_Pais={"pais",CNT_COL_PAIS,0, cols_Pais,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto Pais
	typedef obj_Pais *(*getPaisObjPtr)(void *self);
#endif
