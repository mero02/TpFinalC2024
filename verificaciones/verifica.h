//---- Verificaciones

int verificaAgencia(void *list, int size, char *num);
int verificaPais(void *list, int size,const char *nombre);
int obtenerCodigoPaisPorNombre(void *list, int size, const char *nombre);
int validarFactura(void *list, int size, int nro,int serie,const char *letra);
char *validarTelefono(char *msj_pant);
char *validarCadena(char *msj_pant);
