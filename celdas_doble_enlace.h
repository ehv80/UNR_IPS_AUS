/* IMPLEMENTACION DE LISTAS DOBLEMENTE ENLAZADAS MEDIANTE PUNTEROS
 * UNA ESTRUCTURA celda REPRESENTA A CADA ELEMENTO DE LA LISTA.
 * CADA celda contiene:
 * 	elemento
 * 	puntero a la celda siguiente
 * 	puntero a la celda anterior
 * 	
 * ARCHIVO DE CABECERA "HEADER" POSEE 
 * 	DESCRIPCION DE LIBRERIAS INCLUIDAS
 * 	DESCRIPCION DE ESTRUCTURAS DE DATOS
 * 	PROTOTIPO DE FUNCIONES DEFINIDAS
 * 	VARIABLES GLOBALES
 */

/* ARCHIVOS DE CABECERA */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include <string.h>

/* VARIABLES GLOBALES */
static int cantidad;

/* ESTRUCTURAS DE DATOS */

/* ESTRUCTURA:	celda	
 *
 * MIEMBROS:
 * 	elemento	
 * 	puntero a celda siguiente
 * 	puntero a celda anterior
 */
struct celda
{
	char elemento;
	struct celda * siguiente;
	struct celda * anterior;
};
	
/* DEFINICIONES DE TIPOS: SINONIMOS */
typedef struct celda scelda;
typedef scelda * pcelda;

/* PROTOTIPOS DE LAS FUNCIONES QUE IMPLEMENTAN LOS ALGORITMOS */
void error( char * );
pcelda crear_lista_doble_enlace( void );
pcelda busca_celda_previa( pcelda inicio, int pos );
pcelda celda_final( pcelda );
int fin( void );
int inserta( pcelda inicio, int pos, char element );
int suprime( pcelda inicio, int pos );
int localiza_posicion( pcelda inicio, char element );
char primero( pcelda );
char elemento_siguiente( pcelda inicio, int pos );
char elemento_anterior( pcelda inicio, int pos );
int purga( pcelda inicio );
void muestra( pcelda );
