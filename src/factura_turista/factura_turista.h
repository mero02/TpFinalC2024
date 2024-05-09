#ifndef FACTURA__INCLUDED
	#define FACTURA__INCLUDED
	#define CNT_COL_FACTURA_ 7
	#define POS_NRO_FAC 0
	#define POS_SERIE_FAC 1
	#define POS_LETRA_FAC 2
	#define POS_FECHA_FAC 3
	#define POS_DNI_TURISTA_FAC 4
	#define POS_COD_FORMA_PAGO_FAC 5
	#define POS_DET_PAGO_FAC 6

	//----------------------------------------------------
	typedef struct {
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters
        
	getPropertyIntPtr   getNro;        
	getPropertyIntPtr   getSerie;        
	getPropertyCharPtr   getLetra;        
	getPropertyCharPtr   getFecha;        
	getPropertyIntPtr   getDniTurista;        
	getPropertyIntPtr   getCodFormaPago;        
	getPropertyCharPtr   getDetPago;

	    //-- setters
        
	setPropertyIntPtr   setNro;        
	setPropertyIntPtr   setSerie;        
	setPropertyCharPtr   setLetra;        
	setPropertyCharPtr   setFecha;        
	setPropertyIntPtr   setDniTurista;        
	setPropertyIntPtr   setCodFormaPago;        
	setPropertyCharPtr   setDetPago;

// getter de objeto relacionado
        getFormaPagoObjPtr  getFormaPagoObj;
        obj_FormaPago *forma_pago;
        getTuristaObjPtr  getTuristaObj;
        obj_Turista *turista;

	}obj_FacturaTurista;
	// funcionalidad publica que se implementa en FacturaTurista.c
	extern obj_FacturaTurista *FacturaTurista_new_Letra_Serie(char *letra);
	extern obj_FacturaTurista *FacturaTurista_new ();
	
	// meta data para acceder a las FacturaTuristas - definicion de las columnas de la tabla
	static Column cols_FacturaTurista[CNT_COL_FACTURA_]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
    
	{"nro",t_int,sizeof(int),true,false},    
	{"serie",t_int,sizeof(int),true,false},    
	{"letra",t_varchar,(sizeof(char)*MAX1)+1,true,false},    
	{"fecha",t_varchar,(sizeof(char)*MAX10)+1,false,false},    
	{"dni_turista",t_int,sizeof(int),false,false},    
	{"cod_forma_pago",t_int,sizeof(int),false,false},    
	{"det_pago",t_varchar,(sizeof(char)*MAX90)+1,false,false},
	};
	// plantilla para la FacturaTurista.
	static Table table_FacturaTurista={"factura_turista",CNT_COL_FACTURA_,0, cols_FacturaTurista,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto FacturaTurista
	typedef obj_FacturaTurista *(*getFacturaTuristaObjPtr)(void *self);
#endif
