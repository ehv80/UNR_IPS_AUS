/* IMPLEMENTACION DE LISTAS MEDIANTE ARREGLOS: listas.c */

/* ARCHIVOS DE CABECERA */
#include "listas.h"

/* FUNCION: crear_lista
 * RETORNA: 	puntero a lista
 * 		Se inicializa poisicion ultimo en CERO. 
 * 		Se inicializan algunos elementos.
 * ARGUMENTOS:	
 * 		void
 */
plista crear_lista(void)
{
	int i;
	char car = 'a';
	plista temporal = (plista)malloc( sizeof(slista) );
	temporal->ultimo = 0;
	temporal->elementos[0]='0';
	for( i=1 ; i <= 10 ; i++ )
	{
		temporal->elementos[i] = car;
		temporal->ultimo = (temporal->ultimo + 1);
		car = car + 1;
	}
	return temporal;
}

/* FUNCION: fin
 * RETORNA: el indice del final de la lista
 * 
 * NOTA: "final de la lista" se refiere al 
 * indice siguiente al ultimo indice de la 
 * lista que tiene un elemento caracter
 * 		_________________________
 * indice 0	|'0' indica LISTA VACIA	|
 * 		-------------------------
 * indice 1	|	1º elemento	|
 * 		-------------------------
 * indice 2	|	2º elemento	|
 * 		-------------------------
 * indice 3	|	3º elemento	|
 * 		-------------------------
 * 		·			·
 * 		·			·
 * 		·			·
 * 		-------------------------
 * ultimo	| ultimo elemento	|
 * 		-------------------------
 * ultimo + 1	| FINAL DE LA LISTA	|
 * 		-------------------------
 * 		·			·
 * 		·			·
 * 		·			·
 * 		-------------------------
 * LONG_MAX - 1	|			|
 * 		-------------------------
 * 
 * Debe cumplirse:
 * 	(ultimo + 1 ) <= (LONG_MAX - 1)		
 *
 * ARGUMENTOS: puntero a lista
 */
int fin( plista list )
{
	if( (list->ultimo + 1) > (LONG_MAX - 1) )
	{
		fprintf(stderr, "ERROR fin: posicion ultimo + 1 excede indice maximo!\n");
		return -1;
	}
	else
		return ( list->ultimo + 1 );
}

/* FUNCION: inserta
 * RETORNA: void
 * ARGUMENTOS:
 * 	puntero a lista
 * 	indice en donde insertar
 * 	elemento a insertar, un caracter
 */
void inserta( plista list, int pos, char element )
{
	int i;
	if( list->ultimo > (LONG_MAX - 1) )
		fprintf(stderr, "ERROR inserta: posicion ultimo excede indice maximo!\n");
	else if( list->ultimo == (LONG_MAX - 1) )
		fprintf(stderr, "ERROR inserta: lista llena!\n");
	else if( pos > list->ultimo || pos < 0 )
		fprintf(stderr, "ERROR inserta: posicion INADECUADA!\n");
	else
	{
		printf("DESPLAZANDO CADA ELEMENTO UN INDICE MAS A PARTIR DE INDICE %d ...\n", pos); 
		for( i = list->ultimo ; i >= pos ; i-- )
			list->elementos[i+1] = list->elementos[i];
		list->ultimo = (list->ultimo + 1);
		printf("...INSERTANDO ELEMENTO %c EN INDICE %d...\n", element, pos);
		list->elementos[pos] = element;
		printf("...INSERCION REALIZADA SATISFACTORIAMENTE.\n");
		printf("\n");
	}
}

/* FUNCION: suprime
 * RETORNA:	void
 * ARGUMENTOS:
 * 	puntero a lista
 * 	posicion a eliminar
 */
void suprime( plista list, int pos )
{
	int i;
	if( list->ultimo < 0 )
		fprintf(stderr, "ERROR suprime: posicion ultimo menor que indice minimo!\n");
	else if( list->ultimo == 0 )
		fprintf(stderr, "ERROR suprime: lista vacia!\n");
	else if( list->ultimo > (LONG_MAX - 1) )
		fprintf(stderr, "ERROR suprime: posicion ultimo excede indice maximo!\n");
	else if( pos > list->ultimo || pos < 0 )
		fprintf(stderr, "ERROR suprime: posicion a suprimir inadecuada!\n");
	else
	{
		list->ultimo = (list->ultimo - 1);
		printf("DESPLAZANDO CADA ELEMENTO UN INDICE MENOS HASTA EL INDICE %d...\n", pos);
		for( i = pos ; i <= list->ultimo ; i++ )
			list->elementos[i] = list->elementos[i+1];
		printf("...ELEMENTO EN INDICE %d ELIMINADO SATISFACTORIAMENTE\n", pos);
		printf("\n");
	}
}

/* FUNCION: localiza
 * RETORNA:	indice del primer elemento igual al pasado
 * 		como argumento: element	
 * ARGUMENTOS:
 * 	puntero a lista
 * 	elemento a localizar
 */
int localiza( plista list, char element )
{
	int i;
	if( list->ultimo < 0 )
		fprintf(stderr, "ERROR localiza: posicion ultimo es menor que indice minimo!\n");
	else if( list->ultimo == 0)
		fprintf(stderr, "ERROR localiza: lista vacia!\n");		
	else if( list->ultimo > (LONG_MAX - 1) )
		fprintf(stderr, "ERROR localiza: posicion ultimo excede indice maximo!\n");
	else
	{
		printf("LOCALIZANDO PRIMER APARICION DEL ELEMENTO: %c \n", element);
		for( i=0 ; i <= list->ultimo ; i++ )
		{
			if( list->elementos[i] == element )
			{
				printf("ELEMENTO %c ENCONTRADO EN INDICE: %d \n", element, i );
				return i;
			}
		}/* Si recorrio todos los elementos sin encontrarlo */
		printf("ELEMENTO %c NO ENCONTRADO\n", element );
		return -1;
	}
	printf("ELEMENTO %c NO ENCONTRADO\n", element );
	printf("\n");
	return -1;
}

/* FUNCION: primero
 * RETORNA:	primer elemento si la lista no esta vacia	
 * ARGUMENTOS:
 * 	puntero a lista
 */
char primero( plista list )
{
	if( list->ultimo < 0 )
		fprintf(stderr, "ERROR primero: posicion ultimo es menor que indice minimo!\n");
	else if( list->ultimo == 0 )
		fprintf(stderr, "ERROR primero: lista vacia!\n");
	else if( list->ultimo > (LONG_MAX - 1) )
		fprintf(stderr, "ERROR primero: posicion ultimo excede indice maximo!\n");
	else if( list->ultimo > 0)
		return (list->elementos[1]);
	else
		return (list->elementos[0]);
	return (list->elementos[0]);
}

/* FUNCION: siguiente
 * RETORNA:	el siguiente elemento al indice pasado como argumento	
 * ARGUMENTOS:
 * 	puntero a lista
 * 	posicion
 */
char siguiente( plista list, int pos )
{
	if( list->ultimo < 0 )
	{
		fprintf(stderr, "ERROR siguiente: posicion ultimo es menor que indice minimo!\n");
		return (list->elementos[0]);
	}
	else if( list->ultimo == 0)
	{
		fprintf(stderr, "ERROR siguiente: lista vacia!\n");
		return (list->elementos[0]);
	}
	else if( list->ultimo > (LONG_MAX - 1) )
	{
		fprintf(stderr, "ERROR siguiente: posicion ultimo excede indice maximo!\n");
		return (list->elementos[0]);
	}
	else if( pos > 0 && pos < list->ultimo )
		return (list->elementos[pos+1]);
	else
		return (list->elementos[0]);
}

/* FUNCION: anterior
 * RETORNA:	el elemento anterior al indice pasado como argumento
 * ARGUMENTOS:
 * 	puntero a lista
 * 	posicion
 */
char anterior( plista list, int pos )
{
	if( list->ultimo < 0 )
	{
		fprintf(stderr, "ERROR anterior: posicion ultimo es menor que indice minimo!\n");
		return (list->elementos[0]);
	}
	else if( list->ultimo == 0)
	{
		fprintf(stderr, "ERROR anterior: lista vacia!\n");
		return (list->elementos[0]);
	}
	else if( list->ultimo > (LONG_MAX - 1) )
	{
		fprintf(stderr, "ERROR siguiente: posicion ultimo excede indice maximo!\n");
		return (list->elementos[0]);
	}
	if( pos > 1 && pos < list->ultimo )
		return (list->elementos[pos-1]);
	else
		return (list->elementos[0]);
}

/* FUNCION: muestra
 * RETORNA:	void
 * ARGUMENTOS:
 * 	puntero a lista
 */
void muestra( plista list )
{
	if( list->ultimo < 0 )
		fprintf(stderr, "ERROR muestra: posicion ultimo es menor que indice minimo!\n");
	else if( list->ultimo == 0)
		fprintf(stderr, "ERROR muestra: lista vacia!\n");
	else if( list->ultimo > (LONG_MAX - 1) )
		fprintf(stderr, "ERROR muestra: posicion ultimo excede indice maximo!\n");
	else
	{
		printf("MOSTRANDO ELEMENTOS...\n");
		int i ;
		for( i=1 ; i <= list->ultimo ; i++ )
			printf("ELEMENTO %d-esimo es: %c \n", i , list->elementos[i] );
		printf("...ELEMENTOS MOSTRADOS SATISFACTORIAMENTE.\n");
		printf("\n");
	}
}

/* FUNCION: purga
 * RETORNA:	void
 * ARGUMENTOS:
 * 	puntero a lista
 */
void purga( plista list )
{
	if( list->ultimo < 0 )
		fprintf(stderr, "ERROR purga: posicion ultimo es menor que indice minimo!\n");
	else if( list->ultimo == 0)
		fprintf(stderr, "ERROR purga: lista vacia!\n");
	else if( list->ultimo > (LONG_MAX - 1) )
		fprintf(stderr, "ERROR purga: posicion ultimo excede indice maximo!\n");
	else
	{
		printf("ELIMINANDO ELEMENTOS DUPLICADOS... \n");
		int i,j;
		for( i = 1; i <= list->ultimo ; i++)
		{
			for(j = list->ultimo ; j > i ; j--)
			{
				if( list->elementos[i] == list->elementos[j] )
					suprime( list, j );
			}
		}
		printf(" ...ELEMENTOS DUPLICADOS ELIMINADOS SATISFACTORIAMENTE.\n");
		printf("\n");
	}
}

/* FUNCION PRINCIPAL EJECUTABLE */
int main()
{
	//PRUEBA DE EJECUCION
	
	//1º Crea la lista con algunos elementos
	plista listita = crear_lista();

	//2º Muestra la lista
	muestra( listita );
	
	//2º Inserta 10 elementos mas
	int i;
	char temp='0';
	printf("INGRESE LOS 10 ELEMENTOS A INSERTAR Y LUEGO PRESIONE [ENTER]\n ");
	for( i = 1; i < 11 ; i++ )
	{
		scanf("%c", &temp);
		//inserta( listita, 4 , temp);
		inserta( listita, i , temp);
	}
	
	//3º Muestra lista
	muestra( listita );
	sleep(5);

	//4º Suprime el caracter con indice 4
	suprime( listita, 4 );
	sleep(5);

	//5º Muestra lista
	muestra( listita );
	sleep(5);
	
	//6º Purga la lista, elimina duplicados
	purga( listita );
	sleep(5);

	//7º Muestra la lista
	muestra( listita );
	sleep(5);
	
	return 0;
}
