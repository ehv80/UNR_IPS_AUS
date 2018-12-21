/* IMPLEMENTACION DE LISTAS MEDIANTE ARREGLOS 
 * ARCHIVO DE CABECERA "HEADER":  listas.h 
 * POSEE 
 * 	DESCRIPCION DE LIBRERIAS INCLUIDAS
 * 	PROTOTIPO DE FUNCIONES DEFINIDAS
 * 	VARIABLES GLOBALES
 */

/* ARCHIVOS DE CABECERA */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

/* DEFINICIONES DE CONSTANTES SIMBOLICAS */
#define LONG_MAX 1024

/* ESTRUCTURAS DE DATOS */

/* ESTRUCTURA:	lista	
 * implementada como un arreglo de 1024 caracteres.
 * 0 <= indice <= (LONG_MAX - 1)
 *
 * MIEMBROS:
 * 	elementos	el arreglo
 * 	ultimo		indice del ultimo elemento
 */
struct lista
{
	char 	elementos[LONG_MAX];
	int	ultimo;
};
	
/* DEFINICIONES DE TIPOS: SINONIMOS */
typedef struct lista slista;
typedef struct lista * plista;

/* ALGORITMOS QUE MANIPULAN LA ESTRUCTURA DE DATOS LISTA */
/* PROTOTIPOS DE LAS FUNCIONES QUE IMPLEMENTAN LOS ALGORITMOS */
plista crear_lista();
int fin( plista );
void inserta( plista list, int pos, char element );
void suprime( plista list, int pos );
int localiza( plista list, char element );
char primero( plista );
char siguiente( plista list, int pos );
char anterior( plista list, int pos );
void purga( plista );
void muestra( plista );
