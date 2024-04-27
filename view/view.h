int leerEntero(char *msj_pant);
char *leerCadena(char *msj_pant, int max_cad);
float leerFloat(char *msj_pant);
int leerEnteroEnRango(char *msj_pant, int min,int max);
void toLowerCase(char *cadena);
int validarFecha(const char* fecha);
int esEntero(const char *cadena);
int esFloat(const char *cadena);
char *leerLetra(char *msj_pant, int lim);
void fechaActual();
void listar(char *msj ,void *list, int size);
//---- Menu
int menu();
int menuTurista();
int menuAgencia();
int menuPaquete();
int menuFacturacion();
int menuOtros();
int menuListado();
int menuActividad();
int menuPais();
int menuLocalidad();

//---- Switch
void switchTurista(int opc);
void switchAgencia(int opc);
void switchPaquete(int opc);
void switchFacturacion(int opc);
void switchOtros(int opc);
void mostarListado(int opc);
void switchActividad(int opc);
void switchPais(int opc);
void switchLocalidad(int opc);
//---- mostrar listados
void listarTuristas();
void listarPaquetes();

// SubMenu
int menuModAg();
int menuModTurista();
int menuModActividad();
int menuModPaquete();

// otros
float getImpTransp(int codAux);
float getImportesActividades(int codPaquete);
float getImpAct(int codTipoActividad);
int contador(void *list,int size,int cod);
void exportarListaTuristas(void *listT, int sizeT,int codPais);
void exportarListaPaquetes(void *list, int size);
void listarDetalle(int nroF, int serieF,const char *letraF);
