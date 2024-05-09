#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h> 
#include <string.h>
#include <malloc.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

#include "../includes/includes.h"

/********************************************************************************************************
|	Que Hace: Verifica si el numero de agencia ingresado estan dentro de la lista agencia.
|	Pre-condiciones: l = L; s = S; n = N;
|	Post-condiones: - Retorna 1 si N esta en L;
|					- Retorna 0 si N No esta en L;
********************************************************************************************************/
int verificaAgencia(void *list, int size, char *num) {
    obj_Agencia **agencias = (obj_Agencia**)list;
    int i;
    for (i = 0; i < size; i++) {
        obj_Agencia *agencia = agencias[i];
        
        if ((strcmp(agencia->getNro(agencia),num)==0)) {
            return 1;
        }
    }
    return 0;
}
/********************************************************************************************************
|	Que Hace: Verifica si el nombre del pais ingresado esta dentro de la lista paises.
|	Pre-condiciones: l = L; s = S; n = N;
|	Post-condiones: - Retorna 1 si N esta en L;
|					- Retorna 0 si N No esta en L;
********************************************************************************************************/
int verificaPais(void *list, int size, const char *nombre) {
    obj_Pais **paises = (obj_Pais**)list;
    int i;
    for (i = 0; i < size; i++) {
        obj_Pais *pais = paises[i];
        if ((strcmp(pais->getNombre(pais),nombre)==0)) {
            return 1; 
        }
    }
    return 0;
}
/********************************************************************************************************
|	Que Hace: Valida una fecha ingresada.
|	Pre-condiciones: --
|	Post-condiones: - Retorna 1 si la fecha es incorrecta;
|					- Retorna 0 si la decha es correcta;
********************************************************************************************************/
int validarFecha(const char* fecha) {
    // Verificar longitud de la cadena
    size_t len = strlen(fecha);
    if (len != 10) {
    	system("cls");
    	printf("Longitud incorrecta");
        return 1; // Longitud incorrecta
    }

    // Verificar el formato exacto 'YYYY-MM-DD'
    if (fecha[4] != '-' || fecha[7] != '-') {
    	system("cls");
    	printf("Formato incorrecto"); 
        return 1; // Formato incorrecto
    }

    // Extraer componentes de la fecha
    char strAnio[5], strMes[3], strDia[3];
    strncpy(strAnio, fecha, 4);
    strAnio[4] = '\0'; // Terminar con nulo para formar un string
    strncpy(strMes, fecha + 5, 2);
    strMes[2] = '\0';
    strncpy(strDia, fecha + 8, 2);
    strDia[2] = '\0';

    // Convertir componentes a enteros
    int anio = atoi(strAnio);
    int mes = atoi(strMes);
    int dia = atoi(strDia);

    // Verificar rangos válidos
    if (anio < 1 || mes < 1 || mes > 12 || dia < 1 || dia > 31) {
    	system("cls");
    	printf("Valores fuera de rango"); 
        return 1; // Valores fuera de rango
    }

    // Verificar días válidos para cada mes
    int diasEnMes[] = {31, 28 + (anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0)), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (dia > diasEnMes[mes - 1]) {
    	system("cls");
    	printf("Día inválido para este mes"); 
        return 1; // Día inválido para este mes
    }

    // Si pasa todas las validaciones, es una fecha válida
    return 0;
}
/********************************************************************************************************
|	Que Hace: Valida que sea la unica combinacion de nro, serie y letra dentro de las facturas cargadas en la base de datos.
|	Pre-condiciones: l = L; s = S; ca = CA;
|	Post-condiones: - Retorna 1 si CA esta en L;
|					- Retorna 0 si CA No esta en L;
********************************************************************************************************/
int validarFactura(void *list, int size, int nro,int serie,const char *letra){
	obj_FacturaTurista **facturas = (obj_FacturaTurista**)list;
    int i;
    for (i = 0; i < size; i++) {
        obj_FacturaTurista *factura = facturas[i];
        if ((factura->getNro(factura)==nro) && (factura->getSerie(factura)==serie) && (strcmp(factura->getLetra(factura),letra)==0)) {
            return 1; 
        }
    }
    return 0;
}
/********************************************************************************************************
|	Que Hace: Devuelve el codigo de un pais, si se encuentra en la base de datos.
|	Pre-condiciones: l = L; s = S; ca = CA;
|	Post-condiones: - Retorna 1 si CA esta en L;
|					- Retorna 0 si CA No esta en L;
********************************************************************************************************/
int obtenerCodigoPaisPorNombre(void *list, int size, const char *nombre) {
    obj_Pais **paises = (obj_Pais **)list;
    int i;
    for (i = 0; i < size; i++) {
        obj_Pais *pais = paises[i];
        if (strcmp(pais->getNombre(pais), nombre) == 0) {
            return pais->getCodigo(pais);
        }
    }
    return -1;  
}
/********************************************************************************************************
|	Que Hace: verifica que se este ingresando numero enteros en los datos de un telefono.
|	Pre-condiciones: m = M;
|	Post-condiones: - Retorna t = T; T es el telefono validado como entero enviado en char *T
********************************************************************************************************/
char *validarTelefono(char *msj_pant){
	int flag;
	char *telefono;
	do{
		telefono = leerCadenaNoObligatorio(msj_pant,MAX50);
		if (!esEntero(telefono)) {
			system("cls");
	        printf("Error: Por favor, ingrese un numero de telefono valido.\n");
	        system("PAUSE");
	        system("cls");
	        flag=1;
	    } else {
	        flag=0;
	    }
	}while(flag);
	return telefono;
}
/********************************************************************************************************
|	Que Hace: verifica que se este ingresando numero enteros en los datos de un telefono.
|	Pre-condiciones: m = M;
|	Post-condiones: - Retorna t = T; T es el telefono validado como entero enviado en char *T
********************************************************************************************************/
char *validarCadena(char *msj_pant){
	int flag;
	char *cadena;
	do{
		cadena = leerCadena(msj_pant,MAX50);
		if (esEntero(cadena)) {
			system("cls");
	        printf("Error: Por favor, ingrese un nombre valido.\n");
	        system("PAUSE");
	        system("cls");
	        flag=1;
	    } else {
	        flag=0;
	    }
	}while(flag);
	return cadena;
}
