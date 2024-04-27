typedef struct
{
	char *t;//nombre de la tabla donde aplica el criterio
	char *al; //alias a usar para reducir codigo sql
	char *sql; // sentencia sql a enviar al motor.
	char *fList; // listado de Resultados de la Consulta SQL(del SELECT)
	char *joins; // listado de tablas con los que realiza Join
	char *whereOpt; 
	void (*toList)(void* q,char *cr);
	void (*addAnd)(void* q,char *cr); // agregar al Where un And y un criterio
	void (*addOr)(void* q,char *cr); //  agregar al Where un Or y un criterio
	char *(*getSQL)(void *q);
} obj_Query;

extern obj_Query *Query_new(char *);

