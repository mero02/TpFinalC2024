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
|	Que Hace: Compara dos objetos de tipo obj_Localidad basándose en sus nombres.
|	Pre-condiciones: l1 = L1; l2 = L2;
|	Post-condiones: - Retorna -1 si el nombre de L1 es "menor" que el nombre de L2.
|					- Retorna 0 si los nombres de L1 y L2 son iguales.
|					- Retorna 1 si el nombre de L1 es "mayor" que el nombre de L2.
********************************************************************************************************/
int cmpNomLoc(const void * l1,const void * l2){
	obj_Localidad * loc1 = *(obj_Localidad **) l1; 
	obj_Localidad * loc2 = *(obj_Localidad **) l2;
	return strcmp(loc1->getNombre(loc1),loc2->getNombre(loc2));
}
/********************************************************************************************************
|	Que Hace: Compara dos objetos de tipo obj_Pais basándose en sus codigos.
|	Pre-condiciones: p1 = P1; p2 = P2;
|	Post-condiones: - Retorna -1 si el codigo de P1 es "menor" que el codigo de P2.
|					- Retorna 0 si los codigos de P1 y P2 son iguales.
|					- Retorna 1 si el codigo de P1 es "mayor" que el codigo de P2.
********************************************************************************************************/
int cmpCodPais(const void * p1,const void * p2){
	obj_Pais * pais1 = *(obj_Pais **) p1; 
	obj_Pais * pais2 = *(obj_Pais **) p2;
	return (pais1->getCodigo(pais1) - pais2->getCodigo(pais2));
}
/********************************************************************************************************
|	Que Hace: Compara dos objetos de tipo obj_Turista basándose en sus codigos(dni).
|	Pre-condiciones: d1 = D1; d2 = D2;
|	Post-condiones: - Retorna -1 si el codigo de D1 es "menor" que el codigo de D2.
|					- Retorna 0 si los codigos de D1 y D2 son iguales.
|					- Retorna 1 si el codigo de D1 es "mayor" que el codigo de D2.
********************************************************************************************************/
int cmpDni (const void *d1, const void *d2){
	obj_Turista * turista1 = *(obj_Turista **) d1;
	obj_Turista * turista2 = *(obj_Turista **) d2;
	return (turista1->getDni(turista1) - turista2->getDni(turista2));
}
/********************************************************************************************************
|	Que Hace: Compara dos objetos de tipo obj_Agencia basándose en sus codigos.
|	Pre-condiciones: p1 = P1; p2 = P2;
|	Post-condiones: - Retorna -1 si el codigo de P1 es "menor" que el codigo de P2.
|					- Retorna 0 si los codigos de P1 y P2 son iguales.
|					- Retorna 1 si el codigo de P1 es "mayor" que el codigo de P2.
********************************************************************************************************/
int cmpCodAg(const void * p1,const void * p2){
	obj_Agencia * ag1 = *(obj_Agencia **) p1; 
	obj_Agencia * ag2 = *(obj_Agencia **) p2;
	return (ag1->getCodigo(ag1) - ag2->getCodigo(ag2));
}
/********************************************************************************************************
|	Que Hace: Compara dos objetos de tipo obj_Actividad basándose en sus codigos.
|	Pre-condiciones: a1 = A1; a2 = A2;
|	Post-condiones: - Retorna -1 si el codigo de A1 es "menor" que el codigo de A2.
|					- Retorna 0 si los codigos de A1 y A2 son iguales.
|					- Retorna 1 si el codigo de A1 es "mayor" que el codigo de A2.
********************************************************************************************************/
int cmpCodAct(const void *a1, const void *a2){
	obj_Actividad *act1 = *(obj_Actividad **) a1;
	obj_Actividad *act2 = *(obj_Actividad **) a2;
	return (act1->getCodigo(act1) - act2->getCodigo(act2));
}
/********************************************************************************************************
|	Que Hace: Compara dos objetos de tipo obj_TipoActividad basándose en sus codigos.
|	Pre-condiciones: t1 = T1; t2 = T2;
|	Post-condiones: - Retorna -1 si el codigo de T1 es "menor" que el codigo de T2.
|					- Retorna 0 si los codigos de T1 y T2 son iguales.
|					- Retorna 1 si el codigo de T1 es "mayor" que el codigo de T2.
********************************************************************************************************/
int cmpCodTipo(const void * t1,const void * t2){
	obj_TipoActividad *act1 = *(obj_TipoActividad **) t1;
	obj_TipoActividad *act2 = *(obj_TipoActividad **) t2;
	return (act1->getCodigo(act1) - act2->getCodigo(act2));
}
/********************************************************************************************************
|	Que Hace: Compara dos objetos de tipo obj_Transporte basándose en sus codigos.
|	Pre-condiciones: t1 = T1; t2 = T2;
|	Post-condiones: - Retorna -1 si el codigo de T1 es "menor" que el codigo de T2.
|					- Retorna 0 si los codigos de T1 y T2 son iguales.
|					- Retorna 1 si el codigo de T1 es "mayor" que el codigo de T2.
********************************************************************************************************/
int cmpCodTrans(const void * t1,const void * t2){
	obj_Transporte *act1 = *(obj_Transporte **) t1;
	obj_Transporte *act2 = *(obj_Transporte **) t2;
	return (act1->getCodigo(act1) - act2->getCodigo(act2));
}
/********************************************************************************************************
|	Que Hace: Compara dos objetos de tipo obj_TipoPaquete basándose en sus codigos.
|	Pre-condiciones: t1 = T1; t2 = T2;
|	Post-condiones: - Retorna -1 si el codigo de T1 es "menor" que el codigo de T2.
|					- Retorna 0 si los codigos de T1 y T2 son iguales.
|					- Retorna 1 si el codigo de T1 es "mayor" que el codigo de T2.
********************************************************************************************************/
int cmpTipoPaq(const void * t1,const void * t2){
	obj_TipoPaquete *act1 = *(obj_TipoPaquete **) t1;
	obj_TipoPaquete *act2 = *(obj_TipoPaquete **) t2;
	return (act1->getCodigo(act1) - act2->getCodigo(act2));
}
/********************************************************************************************************
|	Que Hace: Compara dos objetos de tipo obj_Paquete basándose en sus codigos.
|	Pre-condiciones: t1 = T1; t2 = T2;
|	Post-condiones: - Retorna -1 si el codigo de T1 es "menor" que el codigo de T2.
|					- Retorna 0 si los codigos de T1 y T2 son iguales.
|					- Retorna 1 si el codigo de T1 es "mayor" que el codigo de T2.
********************************************************************************************************/
int cmpPaq(const void * t1,const void * t2){
	obj_Paquete *act1 = *(obj_Paquete **) t1;
	obj_Paquete *act2 = *(obj_Paquete **) t2;
	return (act1->getCodigo(act1) - act2->getCodigo(act2));
}
/********************************************************************************************************
|	Que Hace: Compara dos objetos de tipo obj_Turista basándose en sus nombres.
|	Pre-condiciones: d1 = D1; d2 = D2;
|	Post-condiones: - Retorna -1 si el codigo de D1 es "menor" que el codigo de D2.
|					- Retorna 0 si los codigos de D1 y D2 son iguales.
|					- Retorna 1 si el codigo de D1 es "mayor" que el codigo de D2.
********************************************************************************************************/
int cmpNombreTurista(const void *d1, const void *d2){
	obj_Turista * turista1 = *(obj_Turista **) d1;
	obj_Turista * turista2 = *(obj_Turista **) d2;
	return (strcmp(turista1->getNombre(turista1), turista2->getNombre(turista2)));
}
/********************************************************************************************************
|	Que Hace: Compara dos objetos de tipo obj_FormaPago basándose en sus nombres.
|	Pre-condiciones: d1 = D1; d2 = D2;
|	Post-condiones: - Retorna -1 si el codigo de D1 es "menor" que el codigo de D2.
|					- Retorna 0 si los codigos de D1 y D2 son iguales.
|					- Retorna 1 si el codigo de D1 es "mayor" que el codigo de D2.
********************************************************************************************************/
int cmpFormaPago(const void *d1, const void *d2){
	obj_FormaPago * forr1 = *(obj_FormaPago **) d1;
	obj_FormaPago * forr2 = *(obj_FormaPago **) d2;
	return (forr1->getCodigo(forr1) - forr2->getCodigo(forr2));
}
/********************************************************************************************************
|	Que Hace: Compara dos objetos de tipo obj_FacturaTurista basándose en sus nombres.
|	Pre-condiciones: d1 = D1; d2 = D2;
|	Post-condiones: - Retorna -1 si el codigo de D1 es "menor" que el codigo de D2.
|					- Retorna 0 si los codigos de D1 y D2 son iguales.
|					- Retorna 1 si el codigo de D1 es "mayor" que el codigo de D2.
********************************************************************************************************/
int cmpCodFactura(const void *d1, const void *d2){
	obj_FacturaTurista * forr1 = *(obj_FacturaTurista **) d1;
	obj_FacturaTurista * forr2 = *(obj_FacturaTurista **) d2;
	return (forr1->getNro(forr1) - forr2->getNro(forr2));
}
/********************************************************************************************************
|	Que Hace: Compara dos objetos de tipo obj_DetFacturaTurista basándose en los codigos de los paquetes.
|	Pre-condiciones: d1 = D1; d2 = D2;
|	Post-condiones: - Retorna -1 si el codigo de D1 es "menor" que el codigo de D2.
|					- Retorna 0 si los codigos de D1 y D2 son iguales.
|					- Retorna 1 si el codigo de D1 es "mayor" que el codigo de D2.
********************************************************************************************************/
int cmpDetPaq(const void *d1, const void *d2){
	obj_DetFacturaTurista * forr1 = *(obj_DetFacturaTurista **) d1;
	obj_DetFacturaTurista * forr2 = *(obj_DetFacturaTurista **) d2;
	return (forr1->getCodPaquete(forr1) - forr2->getCodPaquete(forr2));
}
