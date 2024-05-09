#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h> 
#include <string.h>
#include <malloc.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

#include "../includes/includes.h"

typedef struct {
int codigo;
int cant;
} ParValores;

/********************************************************************************************************
|	Que Hace: Listar el contenido de una lista.
|	Pre-condiciones: m = M; l = L; s = S;
|	Post-condiones: --
********************************************************************************************************/
void listar(char *msj ,void *list, int size){
	int i;
	void *itm;
	printf("%s\n",msj);
	for(i=0;i<size;++i)
	{
		printf("-------------------------------------------------------\n");
	   	itm = ((Object **)list)[i];    
	    ((Object *)itm)->toString(itm);
	}
	printf("-------------------------------------------------------\n");
}
/********************************************************************************************************
|	Que Hace: Limpia pantalla y muestra la fecha actual.
|	Pre-condiciones: --
|	Post-condiones: --
********************************************************************************************************/
void fechaActual(){
	system("cls");
	char* fechaActual = getFecha();
	char* diaActual = getDiaFecha(fechaActual);
	printf("\n----------------------------------\nFecha actual: %s %s\n----------------------------------\n",diaActual,fechaActual);
}
/********************************************************************************************************
|	Que Hace: Cambia un valor por otro.
|	Pre-condiciones: a = A; b = B;
|	Post-condiones: A ahora es B y B ahora es A;
********************************************************************************************************/
void swap(ParValores *a, ParValores *b) {
    ParValores temp = *a;
    *a = *b;
    *b = temp;
}
/********************************************************************************************************
|	Que Hace: Ordena un arreglo de mayor a menor segun la cantidad de apariciones.
|	Pre-condiciones: a[] = A[]; s = S;
|	Post-condiones: a1[] = A1[]; A1[]=A1[]
********************************************************************************************************/
void ordenarArreglo(ParValores arreglo[], int size) {
	int i,j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arreglo[j].cant < arreglo[j + 1].cant) {
                swap(&arreglo[j], &arreglo[j + 1]);
            }
        }
    }
}
/********************************************************************************************************
|	Que Hace: Verifica si la cadena contiene solo dígitos, un único punto decimal o un signo negativo seguido de dígitos
|	Pre-condiciones: c = C;
|	Post-condiones: - Retorna 1 si el digito es un float.
|					- Retorna 0 si el digito no es un float.
********************************************************************************************************/
int esFloat(const char *cadena) {
    int i, puntoCount = 0;
    for (i = 0; cadena[i] != '\0'; i++) {
        if ((cadena[i] < '0' || cadena[i] > '9') && (cadena[i] != '.' || puntoCount > 1) && (i != 0 || cadena[i] != '-')) {
            return 0;
        }
        if(cadena[i] == '.') puntoCount++;
    }
    return 1;
}
/********************************************************************************************************
|	Que Hace: Verifica si la cadena contiene solo dígitos o un signo negativo seguido de dígitos
|	Pre-condiciones: c = C;
|	Post-condiones: - Retorna 1 si el digito es un entero.
|					- Retorna 0 si el digito no es un entero.
********************************************************************************************************/
int esEntero(const char *cadena) {
	int i;
    for (i = 0; cadena[i] != '\0'; i++) {
        if ((cadena[i] < '0' || cadena[i] > '9') && (i != 0 || cadena[i] != '-')) {
            return 0;
        }
    }
    return 1;
}
/********************************************************************************************************
|	Que Hace: Muestra un mensaje y solicita la entrada de un valor tipo entero.
|	Pre-condiciones: m = M;
|	Post-condiones: v = V; Donde V es un valor de tipo entero.
********************************************************************************************************/
int leerEntero(char *msj_pant ){
	int valor;
    char entrada[100]; // Tamaño suficientemente grande para almacenar la entrada del usuario
    do {
        printf("%s\n", msj_pant);
        fflush(stdin);
        fgets(entrada, sizeof(entrada), stdin);
        
        // Remover el salto de línea al final de la cadena
        if (entrada[strlen(entrada) - 1] == '\n') {
            entrada[strlen(entrada) - 1] = '\0';
        }
        // Verificar si la entrada está vacía
        if (strlen(entrada) == 0) {
            printf("Error: No se ha ingresado ningun valor.\n");
            system("PAUSE");
        }else if (!esEntero(entrada)) {
            printf("Error: al leer entrada\nUSO: Debes ingresar un numero entero.\n");
            system("PAUSE");
        } else {
            // Convertir la entrada a un entero
            valor = atoi(entrada);
            return valor;
        }
    } while (1);
}
/********************************************************************************************************
|	Que Hace: Muestra un mensaje y solicita la entrada de un valor tipo entero, delimitado en un rango.
|	Pre-condiciones: m = M; ri = RI; rf = RF;
|	Post-condiones: v = V; Donde V es un valor de tipo entero y esta acotado entre RI y RF.
********************************************************************************************************/
int leerEnteroEnRango(char *msj_pant, int min,int max) {
    int numero;
    char buffer[100]; // Buffer para almacenar la entrada del usuario

    while (1) {
        printf("%s\n", msj_pant);
        fflush(stdin);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &numero) != 1 || buffer[0] == '\n') {
                printf("Error: al leer entrada\nUSO: Debes ingresar un numero entero entre %d y %d.\n", min, max);
                system("PAUSE");
            } else if (numero < min || numero > max) {
                printf("Error: al leer entrada\nUSO: Debes ingresar un numero entero entre %d y %d.\n", min, max);
                system("PAUSE");
            } else {
                return numero;
            }
        } else {
            printf("Error: al leer entrada\nUSO: Debes ingresar un numero entero entre %d y %d.\n", min, max);
            system("PAUSE");
        }
    }
}
/********************************************************************************************************
|	Que Hace: Muestra un mensaje y solicita la entrada de un valor tipo real.
|	Pre-condiciones: m = M;
|	Post-condiones: v = V; Donde V es un valor de tipo real.
********************************************************************************************************/
float leerFloat(char *msj_pant) {
    float valor;
    char entrada[100]; // Tamaño suficientemente grande para almacenar la entrada del usuario
    
    do {
        printf("%s\n", msj_pant);
        fflush(stdin);
        fgets(entrada, sizeof(entrada), stdin);
        
        // Remover el salto de línea al final de la cadena
        if (entrada[strlen(entrada) - 1] == '\n') {
            entrada[strlen(entrada) - 1] = '\0';
        }
        
        // Verificar si la entrada es un número float
        if (!esFloat(entrada)) {
            printf("Error: al leer entrada\nUSO: Debes ingresar un numero real.\n");
            system("PAUSE");
        } else {
            // Convertir la entrada a un float
            valor = atof(entrada);
            return valor;
        }
    } while (true);
}
/********************************************************************************************************
|    Que Hace: Muestra un mensaje y solicita la entrada de un caracter.
|    Pre-condiciones: m = M; mc = MC;
|    Post-condiones: v = V; Donde V es una cadena de texto y esta delimitada por MC.
********************************************************************************************************/
char *leerLetra(char *msj_pant, int lim) {
    char *input = (char *)malloc((lim + 2) * sizeof(char)); // Se reserva memoria para la entrada más el carácter nulo y el de nueva línea
    if (input == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", msj_pant);
    fflush(stdin);
    fgets(input, lim + 2, stdin); // Lee la entrada incluyendo el carácter nulo y el de nueva línea
    
    // Elimina el carácter de nueva línea si está presente
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    } else { // Limpia el buffer de entrada si se excede el límite
        printf("\nError: al leer entrada\nUSO: Debes ingresar un unico caracter.\n");
        system("PAUSE");
        while (getchar() != '\n');
        free(input); // Se libera la memoria antes de salir
        return NULL;
    }


    // Verifica si la entrada tiene más de un caracter
    if (strlen(input) != 1) {
        printf("\nError: al leer entrada\nUSO: Debes ingresar un unico caracter.\n");
        system("PAUSE");
        free(input); // Se libera la memoria antes de salir
        return NULL;
    }

    return input;
}
/********************************************************************************************************
|	Que Hace: Muestra un mensaje y solicita la entrada de una cadena de texto, delimitada por un maximo.
|	Pre-condiciones: m = M; mc = MC;
|	Post-condiones: v = V; Donde V es una cadena de texto y esta delimitada por MC.
********************************************************************************************************/
char *leerCadena(char *msj_pant, int max_cad) {
	int bandera;
	char *valor = (char *)malloc(max_cad * sizeof(char)); // Reserva memoria dinámica

    if (valor == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria.\n");
        exit(EXIT_FAILURE);
    }

    do{
    	bandera = 0;
    	printf("%s\n", msj_pant);
	    fflush(stdin);
		
	    // Leer la cadena con fgets para manejar correctamente los espacios en blanco
	    if (fgets(valor, max_cad, stdin) == NULL) {
	        fprintf(stderr, "Error: al leer entrada\nUSO: Debes ingresar una cadena de texto no vacia.\n");
	        exit(EXIT_FAILURE);
	    }
	
	    // Eliminar el carácter de nueva línea del final, si está presente
	    size_t len = strlen(valor);
	    if (len > 0 && valor[len - 1] == '\n') {
	        valor[len - 1] = '\0';
	    }
		
		// Verificar el tamaño de la cadena
	    if (strlen(valor) < 1) { // Restar 1 para dejar espacio para el carácter nulo
	        printf("Error: al leer entrada\nUSO: Debes ingresar una cadena de texto mayor a 2 caracteres.\n");
	        bandera = 1;
	        system("PAUSE");
	    }
		
	    // Verificar el tamaño de la cadena
	    if (strlen(valor) > max_cad - 1) { // Restar 1 para dejar espacio para el carácter nulo
	        printf("Error: al leer entrada\nUSO: Debes ingresar una cadena de texto menor a %d.\n",max_cad);
	        bandera = 1;
	        system("PAUSE");
	    }
	}while(bandera);

    return valor;
}

/********************************************************************************************************
|	Que Hace: Muestra un mensaje y solicita la entrada de una cadena de texto, delimitada por un maximo.
|	Pre-condiciones: m = M; mc = MC;
|	Post-condiones: v = V; Donde V es una cadena de texto y esta delimitada por MC.
********************************************************************************************************/
char *leerCadenaNoObligatorio(char *msj_pant, int max_cad) {
	int bandera;
	char *valor = (char *)malloc(max_cad * sizeof(char)); // Reserva memoria dinámica

    if (valor == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria.\n");
        exit(EXIT_FAILURE);
    }

    do{
    	bandera = 0;
    	printf("%s\n", msj_pant);
	    fflush(stdin);
		
	    // Leer la cadena con fgets para manejar correctamente los espacios en blanco
	    if (fgets(valor, max_cad, stdin) == NULL) {
	        fprintf(stderr, "Error: al leer entrada\nUSO: Debes ingresar una cadena de texto no vacia.\n");
	        exit(EXIT_FAILURE);
	    }
	
	    // Eliminar el carácter de nueva línea del final, si está presente
	    size_t len = strlen(valor);
	    if (len > 0 && valor[len - 1] == '\n') {
	        valor[len - 1] = '\0';
	    }
		
		// Verificar el tamaño de la cadena
	    if (strlen(valor) < 1) { // Restar 1 para dejar espacio para el carácter nulo
	        strcpy(valor,"00");
	    }
		
	    // Verificar el tamaño de la cadena
	    if (strlen(valor) > max_cad - 1) { // Restar 1 para dejar espacio para el carácter nulo
	        printf("Error: al leer entrada\nUSO: Debes ingresar una cadena de texto menor a %d.\n",max_cad);
	        bandera = 1;
	        system("PAUSE");
	    }
	}while(bandera);

    return valor;
}
/********************************************************************************************************
|	Que Hace: Muestre un menu general y permite seleccionar una opcion ingresando un valor de tipo entero.
|	Pre-condiciones: --
|	Post-condiones: o = O; Retorna O; Donde O es una de las opciones dentro del menu.
********************************************************************************************************/
int menu(){
	int opc;
	do{
		fechaActual();
		printf("|\tMenu Principal\t\t\t\t|\n");
		printf("|\t1. Alta y Modificacion de Turistas\t|\n");
		printf("|\t2. Alta y Modificacion de Agencias\t|\n");
		printf("|\t3. Paquetes\t\t\t\t|\n");
        printf("|\t4. Facturacion\t\t\t\t|\n");
        printf("|\t5. Otras Altas y Bajas\t\t\t|\n");
		printf("|\t6. Listados\t\t\t\t|\n");
		printf("|\t7. Salir\t\t\t\t|\n");
		opc = leerEntero("Ingrese una opcion: ");
	}while((opc > 7 )&&(opc < 1));
	return opc;
}
/********************************************************************************************************
|	Que Hace: Muestre el menu personalizado y permite seleccionar una opcion ingresando un valor de tipo entero.
|	Pre-condiciones: --
|	Post-condiones: o = O; Retorna O; Donde O es una de las opciones dentro del menu.
********************************************************************************************************/
int menuTurista(){
	int opc;
	do{
		fechaActual();
		printf("|\tMenu Turistas\t\t\t|\n");
		printf("|\t1 - Ingresar Turista\t\t|\n");
		printf("|\t2 - Actualizar Turista\t\t|\n");
		printf("|\t3 - Volver al menu principal\t|\n");
		opc = leerEntero("Ingrese una opcion: ");
	}while((opc > 3 )||(opc < 1));
	
	return opc;
}
/********************************************************************************************************
|	Que Hace: Muestre un menu personalizado y permite seleccionar una opcion ingresando un valor de tipo entero.
|	Pre-condiciones: --
|	Post-condiones: o = O; Retorna O; Donde O es una de las opciones dentro del menu.
********************************************************************************************************/
int menuAgencia(){
	int opc;
	do{
		fechaActual();
		printf("|\tMenu Agencias\t\t\t|\n");
		printf("|\t1 - Ingresar Agencia\t\t|\n");
		printf("|\t2 - Actualizar Agencia\t\t|\n");
		printf("|\t3 - Volver al menu principal\t|\n");
		opc = leerEntero("Ingrese una opcion: ");
	}while((opc > 3 )||(opc < 1));
	
	return opc;
}
/********************************************************************************************************
|	Que Hace: Muestre un menu personalizado y permite seleccionar una opcion ingresando un valor de tipo entero.
|	Pre-condiciones: --
|	Post-condiones: o = O; Retorna O; Donde O es una de las opciones dentro del menu.
********************************************************************************************************/
int menuPaquete(){
	int opc;
	do{
		fechaActual();
		printf("|\tMenu Paquetes\t\t\t|\n");
		printf("|\t1 - Ingresar Paquete\t\t|\n");
		printf("|\t2 - Actualizar Paquete\t\t|\n");
		printf("|\t3 - Volver al menu principal\t|\n");
		opc = leerEntero("Ingrese una opcion: ");
	}while((opc > 3 )||(opc < 1));
	
	return opc;
}
/********************************************************************************************************
|	Que Hace: Muestre un menu personalizado y permite seleccionar una opcion ingresando un valor de tipo entero.
|	Pre-condiciones: --
|	Post-condiones: o = O; Retorna O; Donde O es una de las opciones dentro del menu.
********************************************************************************************************/
int menuFacturacion(){
	int opc;
	do{
		fechaActual();
		printf("|\tMenu Facturacion\t\t|\n");
		printf("|\t1. Crear Factura\t\t|\n");
		printf("|\t2. Volver al menu principal\t|\n");
		opc = leerEntero("Ingrese una opcion: ");
	}while((opc > 2 )||(opc < 1));
	
	return opc;
}
/********************************************************************************************************
|	Que Hace: Muestre un menu personalizado y permite seleccionar una opcion ingresando un valor de tipo entero.
|	Pre-condiciones: --
|	Post-condiones: o = O; Retorna O; Donde O es una de las opciones dentro del menu.
********************************************************************************************************/
int menuOtros(){
	int opc;
	do{
		fechaActual();
		printf("|\tMenu de gestion\t\t\t\t|\n");
		printf("|\t1. Alta y Modificacion de Actividades\t|\n");
		printf("|\t2. Alta y Modificacion de Paises\t|\n");
		printf("|\t3. Alta y Modificacion de Localidades\t|\n");
		printf("|\t4. Volver al menu principal\t\t|\n");
		opc = leerEntero("Ingrese una opcion: ");
	}while((opc > 4 )||(opc < 1));
	
	return opc;
}
/********************************************************************************************************
|	Que Hace: Muestre un menu personalizado y permite seleccionar una opcion ingresando un valor de tipo entero.
|	Pre-condiciones: --
|	Post-condiones: o = O; Retorna O; Donde O es una de las opciones dentro del menu.
********************************************************************************************************/
int menuListado(){
	int opc;
	do{
		fechaActual();
		printf("|\tMenu de listas\t\t\t\t\t|\n");
		printf("|\t1 - Listar Turistas de un determinado pais\t|\n");
		printf("|\t2 - Listar Paquetes mas consumidos\t\t|\n");
		printf("|\t3 - Volver al menu principal\t\t\t|\n");
		opc = leerEntero("Ingrese una opcion: ");
	}while ((opc > 3 )||(opc < 1));
	
	return opc;
}
/********************************************************************************************************
|	Que Hace: Muestre un menu personalizado y permite seleccionar una opcion ingresando un valor de tipo entero.
|	Pre-condiciones: --
|	Post-condiones: o = O; Retorna O; Donde O es una de las opciones dentro del menu.
********************************************************************************************************/
int menuActividad(){
	int opc;
	do{
		fechaActual();
		printf("|\tMenu Actividades\t\t|\n");
		printf("|\t1. Insertar Actividad\t\t|\n");
		printf("|\t2. Actualizar Actividad\t\t|\n");
		printf("|\t3. Volver al menu anterior\t|\n");
		opc = leerEntero("Ingrese una opcion: ");
	}while((opc > 3 )||(opc < 1));
	
	return opc;
}
/********************************************************************************************************
|	Que Hace: Muestre un menu personalizado y permite seleccionar una opcion ingresando un valor de tipo entero.
|	Pre-condiciones: --
|	Post-condiones: o = O; Retorna O; Donde O es una de las opciones dentro del menu.
********************************************************************************************************/
int menuPais(){
	int opc;
	do{
		fechaActual();
		printf("|\tMenu Pais\t\t\t|\n");
		printf("|\t1. Insertar Pais\t\t|\n");
		printf("|\t2. Actualizar Pais\t\t|\n");
		printf("|\t3. Volver al menu anterior\t|\n");
		opc = leerEntero("Ingrese una opcion: ");
	}while((opc > 3 )||(opc < 1));
	
	return opc;
}
/********************************************************************************************************
|	Que Hace: Muestre un menu personalizado y permite seleccionar una opcion ingresando un valor de tipo entero.
|	Pre-condiciones: --
|	Post-condiones: o = O; Retorna O; Donde O es una de las opciones dentro del menu.
********************************************************************************************************/
int menuLocalidad(){
	int opc;
	do{
		fechaActual();
		printf("|\tMenu Localidad\t\t\t|\n");
		printf("|\t1. Insertar Localidad\t\t|\n");
		printf("|\t2. Actualizar Localidad\t\t|\n");
		printf("|\t3. Volver al menu anterior\t|\n");
		opc = leerEntero("Ingrese una opcion: ");
	}while((opc > 3 )||(opc < 1));
	
	return opc;
}
/********************************************************************************************************
|	Que Hace: ejecuta diferentes funciones del menu turista segun un valor dado.
|	Pre-condiciones: o = O;
|	Post-condiones: -- 
********************************************************************************************************/
void switchTurista(int opc){
	switch (opc){
		case 1:
			insertarTurista();
			break;
		case 2:
			actualizarTurista();
			break;
	}
}
/********************************************************************************************************
|	Que Hace: ejecuta diferentes funciones del menu agencia segun un valor dado.
|	Pre-condiciones: o = O;
|	Post-condiones: -- 
********************************************************************************************************/
void switchAgencia(int opc){
	switch (opc){
		case 1:
			insertarAgencia();
			break;
		case 2:
			actualizarAgencia();
			break;
	}
}
/********************************************************************************************************
|	Que Hace: ejecuta diferentes funciones del menu paquete segun un valor dado.
|	Pre-condiciones: o = O;
|	Post-condiones: -- 
********************************************************************************************************/
void switchPaquete(int opc){
	switch (opc){
		case 1:
			insertarPaquete();
			break;
		case 2:
			actualizarPaquete();
			break;
	}
}
/********************************************************************************************************
|	Que Hace: ejecuta diferentes funciones del menu facturacion segun un valor dado.
|	Pre-condiciones: o = O;
|	Post-condiones: -- 
********************************************************************************************************/
void switchFacturacion(int opc){
	switch (opc){
		case 1:
			crearFactura();
			break;
	}
}
/********************************************************************************************************
|	Que Hace: ejecuta diferentes funciones del menu otros segun un valor dado.
|	Pre-condiciones: o = O;
|	Post-condiones: -- 
********************************************************************************************************/
void switchOtros(int opc){
	int opcSubMenu;
	switch (opc){
		case 1:
			do{
				opcSubMenu = menuActividad();
				switchActividad(opcSubMenu);
			}while(opcSubMenu != 3);
			break;
		case 2:
			do{
				opcSubMenu = menuPais();
				switchPais(opcSubMenu);
			}while(opcSubMenu != 3);
			break;
		case 3:
			do{
				opcSubMenu = menuLocalidad();
				switchLocalidad(opcSubMenu);
			}while(opcSubMenu != 3);
			break;
	}
}
/********************************************************************************************************
|	Que Hace: ejecuta diferentes funciones del menu actividades segun un valor dado.
|	Pre-condiciones: o = O;
|	Post-condiones: -- 
********************************************************************************************************/
void switchActividad(int opc){
	switch (opc){
		case 1:
			insertarActividad();
			break;
		case 2:
			actualizarActividad();
			break;
	}
}
/********************************************************************************************************
|	Que Hace: ejecuta diferentes funciones del menu paises segun un valor dado.
|	Pre-condiciones: o = O;
|	Post-condiones: -- 
********************************************************************************************************/
void switchPais(int opc){
	switch (opc){
		case 1:
			insertarPais();
			break;
		case 2:
			actualizarPais();
			break;
	}
}
/********************************************************************************************************
|	Que Hace: ejecuta diferentes funciones del menu localidades segun un valor dado.
|	Pre-condiciones: o = O;
|	Post-condiones: -- 
********************************************************************************************************/
void switchLocalidad(int opc){
	switch (opc){
		case 1:
			insertarLocalidad();
			break;
		case 2:
			actualizarLocalidad();
			break;
	}
}
/********************************************************************************************************
|	Que Hace: ejecuta diferentes funciones de listado de datos en función de un  valor dado.
|	Pre-condiciones: o = O;
|	Post-condiones: -- 
********************************************************************************************************/
void mostarListado(int opc){
	switch (opc){
		case 1:
			listarTuristas();
			break;
		case 2:
			listarPaquetes();
			break;
	}
}

/********************************************************************************************************
|	Que Hace: Lista a los turistas de un determinado pais, segun una opcion dada.
|	Pre-condiciones: --
|	Post-condiones: --
********************************************************************************************************/
void listarTuristas(){
	obj_Pais *pais;
	obj_Turista *turista;
	
	void *list,*listT,*itm;
	int size=0,i,sizeT;
	char *nombre,*nombrePais;
	int codigo,codigoPais,opc,opcion;

	turista = Turista_new();
	pais = Pais_new();
	size = pais->findAll(pais,&list,NULL);
	sizeT = turista->findAll(turista,&listT,NULL); 
	fechaActual();
	opc = leerEnteroEnRango("1: Ordenar por DNI \n2: Ordenar por nombre \nIngrese un numero: ",1,2);
	if(opc==1){
		qsort(listT,sizeT,sizeof(obj_Turista*),cmpDni);
	}else{
		qsort(listT,sizeT,sizeof(obj_Turista*),cmpNombreTurista);
	}
	int codPais = seleccionarPais();
	pais->findbykey(pais,codPais);
	fechaActual();
	printf("\nTuristas de %s:\n",pais->getNombre(pais));
	for (i = 0; i < sizeT; i++) {
		obj_Turista *turista = ((obj_Turista **)listT)[i];        
		if (turista->getCodPais(turista) == codPais) {
			printf("-------------------------------------------------------\n");
	    	turista->toString(turista);
	    }
	}
	printf("-------------------------------------------------------\n");
	opcion = leerEnteroEnRango("1: Crear un archivo\n2: No crear un archivo\nIngrese un numero: ",1,2);
	if(opcion==1){
	    exportarListaTuristas(listT,sizeT,codPais);
	}
	destroyObj(pais);
	destroyObj(turista);
	destroyObjList(list,size);
	destroyObjList(listT,sizeT);
    system("PAUSE");
}
/********************************************************************************************************
|	Que Hace: Lista los paquetes mas consumidos.
|	Pre-condiciones: --
|	Post-condiones: --
********************************************************************************************************/
void listarPaquetes(){
	obj_DetFacturaTurista *detalle;
	obj_Paquete *paq;  
	void *list, *listP;
	int size=0, sizeP = 0, cod,i,j,indice = 0,opcion; 
	
	detalle = DetFacturaTurista_new();
	size = detalle->findAll(detalle,&list,NULL);
	paq = Paquete_new();
	sizeP = paq->findAll(paq,&listP,NULL);
	    
	ParValores arreglo[sizeP];
	    
	qsort(list,size,sizeof(obj_DetFacturaTurista*),cmpDetPaq);
	qsort(listP,sizeP,sizeof(obj_Paquete*),cmpPaq);
	
	obj_Paquete **paquetes = (obj_Paquete**)listP;
	
	for (i = 0; i < sizeP; i++) {
	    obj_Paquete *paquete = paquetes[i];
	    cod = paquete->getCodigo(paquete);
	    arreglo[i].codigo = cod;
	    arreglo[i].cant = contador(list,size,cod);
	}  

    ordenarArreglo(arreglo, sizeP);
	fechaActual();
	printf("\nPaquetes mas consumidos:\n");
	for(j = 0 ; j < sizeP; j++){
		printf("-------------------------------------------------------\n");
	    printf("Codigo del paquete: %d - Cantidad que se consumio: %d\n",arreglo[j].codigo,arreglo[j].cant);
	}
	printf("-------------------------------------------------------\n");
	opcion = leerEnteroEnRango("\n1: Crear un archivo\n2: No crear un archivo",1,2);
	if(opcion==1){
	    exportarListaPaquetes(listP,sizeP);
	}
	
	destroyObjList(list,size);
	destroyObjList(listP,sizeP);
	destroyObj(detalle);
	destroyObj(paq);
	
	system("PAUSE");
}
/********************************************************************************************************
|	Que Hace: Muestre un menu y permite seleccionar una opcion ingresando un valor de tipo entero.
|	Pre-condiciones: --
|	Post-condiones: o = O; Retorna O; Donde O es una de las opciones dentro del menu.
********************************************************************************************************/
int menuModTurista(){
	int opc;
	do{
		fechaActual();
		printf("|\tMenu de Modificacion Turista\t|\n");
		printf("|\t1 - Modificar Nombre\t\t|\n");
		printf("|\t2 - Modificar Domicilio\t\t|\n");
		printf("|\t3 - Modificar Telefono\t\t|\n");
		printf("|\t4 - Modificar Pais\t\t|\n");
		printf("|\t5 - Modificar Todo\t\t|\n");
		printf("|\t6 - Volver al menu anterior\t|\n");
		opc = leerEntero("Ingrese una opcion: ");
	}while((opc > 6 )||(opc < 1));
	return opc;
}
/********************************************************************************************************
|	Que Hace: Muestre un menu y permite seleccionar una opcion ingresando un valor de tipo entero.
|	Pre-condiciones: --
|	Post-condiones: o = O; Retorna O; Donde O es una de las opciones dentro del menu.
********************************************************************************************************/
int menuModAg(){
	int opc;
	do{
		fechaActual();
		printf("|\tMenu de Modificacion de Agencia\t|\n");
		printf("|\t1 - Modificar Nombre\t\t|\n");
		printf("|\t2 - Modificar numero de Agencia\t|\n");
		printf("|\t3 - Modificar Calle\t\t|\n");
		printf("|\t4 - Modificar Codigo Postal\t|\n");
		printf("|\t5 - Modificar Depto\t\t|\n");
		printf("|\t6 - Modificar Piso\t\t|\n");
		printf("|\t7 - Modificar Telefono 1\t|\n");
		printf("|\t8 - Modificar Telefono 2\t|\n");
		printf("|\t9 - Volver al menu anterior\t|\n");
		opc = leerEntero("Ingrese una opcion: ");
	}while((opc > 9 )||(opc < 1));
	return opc;
}
/********************************************************************************************************
|	Que Hace: Muestre un menu y permite seleccionar una opcion ingresando un valor de tipo entero.
|	Pre-condiciones: --
|	Post-condiones: o = O; Retorna O; Donde O es una de las opciones dentro del menu.
********************************************************************************************************/
int menuModActividad(){
	int opc;
	do{
		fechaActual();
		printf("|\tMenu de Modificacion de Actividad\t|\n");
		printf("|\t1 - Modificar Tipo de actividad\t\t|\n");
		printf("|\t2 - Modificar Transporte\t\t|\n");
		printf("|\t3 - Modificar Importe\t\t\t|\n");
		printf("|\t4 - Volver al menu anterior\t\t|\n");
		opc = leerEntero("Ingrese una opcion: ");
	}while((opc > 4 )||(opc < 1));
	return opc;
}
/********************************************************************************************************
|	Que Hace: Muestre un menu y permite seleccionar una opcion ingresando un valor de tipo entero.
|	Pre-condiciones: --
|	Post-condiones: o = O; Retorna O; Donde O es una de las opciones dentro del menu.
********************************************************************************************************/
int menuModPaquete(){
	int opc;
    do{
    	fechaActual();
        printf("|\tMenu de Modificacion de Paquete\t\t\t|\n");
        printf("|\t1 - Modificar Codigo de tipo paquete y nivel\t|\n");
        printf("|\t2 - Modificar Codigo de agencia\t\t\t|\n");
        printf("|\t3 - Modificar fecha\t\t\t\t|\n");
        printf("|\t4 - Modificar DNI del turista\t\t\t|\n");
        printf("|\t5 - Volver al menu anterior\t\t\t|\n");
        opc = leerEntero("Ingrese una opcion: ");
    }while((opc > 5 )||(opc < 1));
    return opc;
}
/********************************************************************************************************
|	Que Hace: Devuelve el importe de un transporte especifico.
|	Pre-condiciones: --
|	Post-condiones: - Retorna el importe de un transporte.
********************************************************************************************************/
float getImpTransp(int codAux){
	obj_Transporte *transporteLista;
	void *list,*itm;
	int i=0,size=0;
	float importeTransporte;
	
	transporteLista = Transporte_new();
	
	size = transporteLista->findAll(transporteLista,&list,NULL);
	qsort(list,size,sizeof(obj_Transporte*),cmpCodTrans);
	
	destroyObj(transporteLista);
	
	obj_Transporte **transportes = (obj_Transporte**)list;

	for (i = 0; i < size; i++) {
		obj_Transporte *transporte = transportes[i];
		        
		if (transporte->getCodigo(transporte) == codAux) {
		    importeTransporte = transporte->getImporte(transporte);
		    break;
		}
	}
	
	destroyObjList(list,size);
	return importeTransporte;
}
/********************************************************************************************************
|	Que Hace: Devuelve el importe de varias actividades listadas en un paquete.
|	Pre-condiciones: --
|	Post-condiones: - Retorna importeTotal
********************************************************************************************************/
float getImportesActividades(int codPaquete){
	int codTipoActividad;
    float importeTotal = 0;
    void *list,*itm;
    int i=0,size=0;

    obj_PaqueteActividad *PaqAct;

    PaqAct = PaqueteActividad_new();

    size = PaqAct->findAll(PaqAct,&list,NULL);

    obj_PaqueteActividad **actividades = (obj_PaqueteActividad**)list;
    for (i = 0; i < size; i++) {
        obj_PaqueteActividad *actividad = actividades[i];
        if (actividad->getCodPaquete(actividad) == codPaquete) {
            importeTotal += actividad->getImporte(actividad);
        }
    }

    destroyObj(PaqAct);
    destroyObjList(list,size);
    return importeTotal;
}
/********************************************************************************************************
|	Que Hace: Cuenta la cantidad de veces que aparece un mismo paquete dentro de una lista de facturas.
|	Pre-condiciones: --
|	Post-condiones: - Retorna importeTotal
********************************************************************************************************/
int contador(void *list,int size,int cod){
	obj_DetFacturaTurista **detalles = (obj_DetFacturaTurista**)list;
	int cont = 0, i;
	    for (i = 0; i < size; i++) {
	        obj_DetFacturaTurista *detalle = detalles[i];
	        if (detalle->getCodPaquete(detalle) == cod) {
	            cont += 1;
	        }
	    }
	    return cont;
}
/********************************************************************************************************
|	Que Hace: Exporta informacion del sistema a un archivo.
|	Pre-condiciones: --
|	Post-condiones: --
********************************************************************************************************/
void exportarListaTuristas(void *listT, int sizeT, int codPais) {
    char nombreArchivo[100];
    FILE *archivo;
    int i;
    
    // Solicitar al usuario el nombre del archivo
    fechaActual();
    printf("Ingrese el nombre del archivo para exportar los turistas: ");
    scanf("%99s", nombreArchivo);
    
    // Abrir el archivo para escritura
    archivo = fopen(nombreArchivo, "w");
    
    if (archivo == NULL) {
    	system("cls");
        printf("Error al abrir el archivo %s para escritura.\n", nombreArchivo);
        system("PAUSE");
        return;
    }
    
    // Iterar a través de la lista de turistas
    for (i = 0; i < sizeT; i++) {
        obj_Turista *turista = ((obj_Turista **)listT)[i];
        
        // Obtener los datos del turista
        char *nombre = turista->getNombre(turista);
        int dni = turista->getDni(turista);
        obj_Pais *pais = turista->getPaisObj(turista);
        char *nombrePais = pais->getNombre(pais); // Obtener el nombre del país del objeto `obj_Pais`
        
        if(pais->getCodigo(pais)==codPais){
        	// Escribir los datos en el archivo utilizando `fprintf` y los especificadores de formato adecuados
	        fprintf(archivo, "Nombre: %s\n", nombre);
	        fprintf(archivo, "DNI: %d\n", dni);
	        fprintf(archivo, "País: %s\n", nombrePais);
	        fprintf(archivo, "\n"); // Separar cada turista con una línea vacía
		}
    }
    
    // Cerrar el archivo
    fclose(archivo);
    
    printf("Exportación completada. Los datos han sido guardados en %s.\n", nombreArchivo);
}
/********************************************************************************************************
|	Que Hace: Exporta informacion del sistema a un archivo.
|	Pre-condiciones: --
|	Post-condiones: --
********************************************************************************************************/
void exportarListaPaquetes(void *list, int size) {
    char nombreArchivo[100];
    FILE *archivo;
    int i;
    
    // Solicitar al usuario el nombre del archivo
    fechaActual();
    printf("Ingrese el nombre del archivo para exportar los paquetes: ");
    scanf("%99s", nombreArchivo);
    
    // Abrir el archivo para escritura
    archivo = fopen(nombreArchivo, "w");
    
    if (archivo == NULL) {
    	system("cls");
        printf("Error al abrir el archivo %s para escritura.\n", nombreArchivo);
        system("PAUSE");
        return;
    }
    
    // Iterar a través de la lista de turistas
    for (i = 0; i < size; i++) {
	    obj_Paquete *paquete = ((obj_Paquete **)list)[i];
	    int codAgencia = paquete->getCodAgencia(paquete);
	    int codpaquete = paquete->getCodTipoPaquete(paquete);
	    char *fecha = paquete->getFecha(paquete);
	    int nivel = paquete->getNivel(paquete);
        // Escribir los datos en el archivo utilizando `fprintf` y los especificadores de formato adecuados
        fprintf(archivo, "Codigo agencia: %d\n", codAgencia);
	    fprintf(archivo, "Codigo paquete: %d\n", codpaquete);
	    fprintf(archivo, "Fecha de adquisicion: %s\n", fecha);
	    fprintf(archivo, "Nivel: %d\n", nivel);
	    fprintf(archivo, "\n"); // Separar con una línea vacía
    }
    
    // Cerrar el archivo
    fclose(archivo);
    
    printf("Exportación completada. Los datos han sido guardados en %s.\n", nombreArchivo);
}
