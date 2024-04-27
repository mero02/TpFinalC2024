//---- Seleccion de datos especifica
int seleccionarPais();
int seleccionarCodP();
void seleccionarTipoActividad(int *codTipo,int *nivel);
void seleccionarTransporte(int *codTransporte,float *importeTransporte);
int seleccionarAgencia();
int seleccionarDni();
int seleccionarTipoPaquete(int *nivel);
int seleccionarPaquete(float *importe);
int seleccionarFormaDePago();
void seleccionarFactura(int *nro, int *serie, char *letra, int dni);
void listarDetalle(int nroF, int serieF,const char *letraF);
void selecionarActividades(int codigoPaquete, int codTipoP);
