/* 	celdas.h
 * IMPLEMENTACION DE LISTAS MEDIANTE PUNTEROS A
 * UNA ESTRUCTURA celda QUE REPRESENTA A CADA 
 * ELEMENTO DE LA LISTA.
 * CADA celda contiene:
 * 	elemento
 * 	puntero a la celda siguiente
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
#include <string.h>

/* VARIABLES GLOBALES */
//mantiene la cantidad de elementos
static int cantidad;

/* ESTRUCTURAS DE DATOS */

/* ESTRUCTURA:	celda	
 *
 * MIEMBROS:
 * 	elemento	
 * 	puntero a celda siguiente
 */
struct celda
{
	char 	elemento;
	struct celda * siguiente;
};
	
/* DEFINICIONES DE TIPOS: SINONIMOS */
typedef struct celda scelda;
typedef scelda * pcelda;

/* PROTOTIPOS DE LAS FUNCIONES QUE IMPLEMENTAN LOS ALGORITMOS */
pcelda crear_lista( void );
pcelda busca_celda( pcelda inicio, int pos );
int fin( pcelda );
void inserta( pcelda inicio, int pos, char element );
void suprime( pcelda inicio, int pos );
int localiza( pcelda inicio, char element );
char primero( pcelda );
char siguiente( pcelda inicio, int pos );
char anterior( pcelda inicio, int pos );
void purga( pcelda inicio );
void muestra( pcelda );

/* ACLARACIONES:
 * ------------
 * CONCEPTO DE POSICION AQUÍ ES DISTINTO DEL CONCEPTO DE INDICE
 * DE UN ARREGLO.
 *
 * INICIO 	<···>	CELDA CERO <···> POSICION CERO 
 * 			(SE SUPONE QUE MIEMBRO ELEMENTO VALE '0' 
 * 			PARA EL CASO DE ALMACENAR CARACTERES.)
 * 
 * POSICION i	<···>	CELDA i
 * 			PUNTERO A LA CELDA i
 * 			MIEMBRO SIGUIENTE DE CELDA i-1
 * 			 		
 *  CELDA 0	  CELDA 1	CELDA 2		CELDA N	     "CELDA N+1"
 *  POS 0         POS 1         POS 2           POS N	     "POS N+1"
 *  -------- 	  --------	--------	--------
 *  |0 |<>·|····> |  |<>·|···>	|  |<>·|··>..··>|  |<>·|···> NULL 
 *  --------	  --------	--------	--------
 *  INICIO
 *                /	 \ 
 *        elemento        siguiente     
 *
 * EJEMPLO:
 * POSICION 2	<···>	MIEMBRO SIGUIENTE DE CELDA 1 QUE APUNTA A CELDA 2
 * 					     POSICION 1 	  POSICION 2
 *
 * SE VA A NECESITAR EN CADA FUNCION QUE USE EL CONCEPTO DE POSICION
 * UNA VARIABLE QUE REPRESENTE ESTA RELACION
 */
