/* IMPLEMENTACION DE LISTAS MEDIANTE PUNTEROS A CELDAS: celdas.c 
 * VERSION SENCILLA EN LA QUE SE ALMACENAN CARACTERES */

/* ARCHIVOS DE CABECERA */
#include "celdas.h"

/* IMPLEMENTACION DE LAS FUNCIONES */

/* FUNCION: crear_lista
 * ARGUMENTOS:
 * 	void
 * RETORNA:
 * 	puntero a celda raiz CELDA CERO
 * inicializando sus miembros
 * 		elemento en '0'
 * 		siguiente en NULL
 * 
 * Ademas se inicializa cantidad en 0.
 */
pcelda crear_lista(void)
{
	pcelda temp = (pcelda)malloc( sizeof( scelda ));
	temp->elemento = '0';
	temp->siguiente = NULL;
	cantidad = 0; // CELDA RAIZ NO SE CUENTA
	return temp;
}

/* FUNCION: busca_celda 
 * ARGUMENTOS:
 * 	puntero a celda inicial
 * 	entero posicion
 * RETORNA:
 * PUNTERO A CELDA QUE CORRESPONDE A LA POSICION
 * ES DECIR MIEMBRO SIGUIENTE DE CELDA (pos - 1)
 * 				 POSICION (pos - 1)
 * QUE APUNTA A CELDA pos
 * 		POSICION pos
 */
pcelda busca_celda( pcelda inicio, int pos )
{
	int pos_temp = 0;
	if( inicio == NULL )
	{
		fprintf(stderr, "\nERROR busca_celda: NO HAY LISTA!\n");
		return NULL;
	}
	if( inicio->siguiente == NULL )
	{
		fprintf(stderr, "\nERROR busca_celda: LISTA VACIA!\n");
		return NULL;
	}
	int pos_final = fin( inicio ); // CELDA N <··> POSICION N <··> pos_final
	if( pos < 0 || pos > pos_final )
	{
		fprintf(stderr, "\nERROR busca_celda: POSICION BUSCADA ES INADECUADA!\n");
		return NULL;
	}
	pcelda temp = inicio;           // CELDA 0  <··> POSICION 0
	//while( temp->siguiente != NULL )   ASI SE IGNORA LA ULTIMA CELDA
	while( pos_temp <= cantidad )
	{
		if( pos_temp == pos )
		{
			return temp;
		}
		else
		{
			pos_temp++;
			temp = temp->siguiente;
		}
	}
	return NULL; // PUEDE SER POR SER siguiente NULL o por NO ENCONTRARLO
}

/* FUNCION: fin
 * ARGUMENTOS: 
 * 	puntero a celda inicial, celda raiz
 * RETORNA:
 * 	un entero que representa la posicion
 * 	relativa de la ultima celda de la lista
 * 	Aquella celda cuyo miembro siguiente
 * 	apunta a NULL
 **/	
int fin( pcelda inicio )
{
	int pos = 0; // CELDA CERO <··> POSICION CERO
	if( inicio == NULL )
	{
		fprintf(stderr, "ERROR fin: NO HAY LISTA!\n");
		return -1;
	}
	else
	{
		if( inicio->siguiente == NULL )
		{
			printf("ADVERTENCIA fin: LISTA VACIA!\n");
			return pos; //POSICION CERO <···> CELDA CERO
		}
		pcelda temp = inicio->siguiente; //temp <··> CELDA 1 <··> POSICION 1
		pos++;				 //pos  <··> CELDA 1 <··> POSICION 1
		//while( temp->siguiente != NULL )
		while( pos <= cantidad )
		{
			temp = temp->siguiente;
			//Por cada acceso a siguiente celda pos incrementa uno
			pos++;
		}
		return pos; // si hay N celdas: CERO <= pos <= N 
	}
	return -1;
}

/* FUNCION: inserta
 * ARGUMENTOS:
 * 	puntero a celda raiz inicial
 * 	elemento a insertar
 * 	posicion donde insertar
 * RETORNA:
 * 	void
 **/
void inserta( pcelda inicio, int pos, char element )
{
	int pos_final = fin( inicio );
	// pos_final <··> POSICION N <··> CELDA N
	if( pos_final < 0 )
		fprintf(stderr, "\nERROR inserta: POSICION DE ULTIMA CELDA NEGATIVA!\n");
	/* NO PUEDE INSERTAR
	 * 	EN POSICION (-1)	<···>   EN CELDA (-1)
	 * 
	 * SI PUEDE INSERTAR EN 
	 * 	EN POSICION 0		<···> 	EN CELDA 0
	 * 	·
	 * 	·
	 * 	· 	
	 * 	EN POSICION N		<···> 	EN CELDA N 
	 * 	
	 *	EN POSICION (N + 1) 	<···> 	EN CELDA (N + 1)
	 *				  	PORQUE ES NULL Y PUEDE INSERTAR AL FINAL
	 * PERO NO PUEDE INSERTAR
	 *	EN POSICION (N + 2) 	<···> 	EN CELDA (N + 2) 
	 *				  	PORQUE NO SE PUEDE ACCEDER DESDE MIEMBRO
	 *				  	SIGUIENTE DE CELDA(N + 1) <··> POSICION(N + 1)
	 *				  	QUE ES NULL
	 */	
	if( pos < 0 || pos > (pos_final + 1)  )
		fprintf(stderr,"\nERROR inserta: POSICION DE INSERCION INADECUADA!\n");
	else
	{
		/* pcelda previa = busca_celda( inicio, (pos - 1) );
		 * PARA INSERTAR NO PUEDO USAR busca_celda		*/
		
		/* pcelda celda_pos = busca_celda( inicio, pos ); 
		 * PARA INSERTAR NO PUEDO USAR busca_celda		*/

		if( inicio == NULL )
			fprintf(stderr,"\nERROR inserta: NO HAY LISTA!\n");
		
		int pos_temp = 0; // pos_temp <··> CELDA 0 <··> POSICION 0
		pcelda temp = inicio; // temp <··> CELDA 0 <··> POSICION 0
		
		while( pos_temp < pos )
		{
			if( temp->siguiente == NULL )
			{
				fprintf(stderr,"\nADVERTENCIA inserta: CELDA SIGUIENTE ES NULL! \n");
				pos_temp = (pos + 1); //PARA QUE SALGA DEL BUCLE
			}
			else
			{
				temp = temp->siguiente;
				pos_temp++;
			}
		}
		
		// GUARDA CELDA siguiente a temp
		pcelda siguiente_a_temp = temp->siguiente; // AUNQUE SEA NULL
		
		// ALLOCA MEMORIA PARA LA NUEVA CELDA
		pcelda nueva = (pcelda)malloc( sizeof( scelda ));
		
		// INICIALIZA CELDA NUEVA
		nueva->elemento = element;
		nueva->siguiente = siguiente_a_temp; //AUNQUE SEA NULL

		/* RE-ENLAZA MIEMBRO SIGUIENTE DE CELDA previa PARA QUE APUNTE A
		 * CELDA NUEVA
		 */
		temp->siguiente = nueva;
		
		cantidad++; //aumenta la cuenta
	}
}

/* FUNCION: suprime
 * ARGUMENTOS:
 * 	puntero a celda inicial CELDA CERO
 * RETORNA:
 * 	void
 */
void suprime( pcelda inicio, int pos )
{
	pcelda previa, aborrar;
	int pos_final = fin( inicio ); // pos_final <··> CELDA N <··> POSICION N
	if( pos_final < 0 )
		fprintf(stderr, "\nERROR suprime: POSICION DE ULTIMA CELDA NEGATIVA!\n");
	if( pos < 0 || pos > pos_final )
		fprintf(stderr,"\nERROR suprime: POSICION A ELIMINAR INADECUADA!\n");
	else
	{
		previa = busca_celda( inicio, (pos - 1) );
		aborrar = busca_celda( inicio, pos );
		
		/* ELIMINA HACIENDO QUE MIEMBRO siguiente DE CELDA previa APUNTE
		 * A LA CELDA APUNTADA POR EL MIEMBRO siguiente de la CELDA aborrar
		 */ 
		previa->siguiente = aborrar->siguiente;
		cantidad--; // decrece la cuenta
		free(aborrar); //¿QUE SUCEDE?
	}
}

/* FUNCION: localiza
 * ARGUMENTOS:
 * 	puntero a celda inicio
 * 	char elemento a buscar
 * RETORNA:
 * 	posicion correspondiente a celda
 * 	que tiene como miembro element
 * 	al char buscado
 */
int localiza( pcelda inicio, char element )
{
	int pos = 0;
	if( inicio == NULL )
	{	
		fprintf(stderr,"\nERROR localiza: NO HAY LISTA!\n");
		return -1;
	}
	if( inicio->siguiente == NULL )
	{
		fprintf(stderr,"\nERROR localiza: LISTA VACIA!\n");
		return -1;
	}
	else
	{
		pcelda temp = inicio->siguiente; // temp <··> CELDA 1 <··> POSICION 1
		pos++;				 // POSICION 1	
		if( temp->elemento == element )
			return pos;
		//while( temp->siguiente != NULL )
		while( pos <= cantidad )
		{
			if( temp->elemento == element )
				return pos;
			else
			{
				temp = temp->siguiente;
				pos++;
			}
		}
		return -1; //NO LO ENCONTRO o siguiente estaba en NULL
	}
	return -1;
}

/* FUNCION: primero
 * ARGUMENTOS:
 * 	puntero a celda inicial
 * RETORNA:
 * 	el miembro elemento de la  primera celda
 */
char primero( pcelda inicio )
{
	if( inicio == NULL )
	{
		fprintf(stderr,"ERROR primero: NO HAY LISTA!\n");
		return (char)NULL;
	}
	if( inicio->siguiente == NULL )
	{
		fprintf(stderr,"ERROR primero: LISTA VACIA!\n");
		return (char)NULL;
	}
	else
	{
		//char primero;
		pcelda uno = inicio->siguiente;
		if( uno->elemento == (char)NULL )
		{
			fprintf(stderr,"ERROR primero: ES NULL!\n");
			return (char)NULL;
		}
		else
		{
			//primero = uno->elemento;
			return uno->elemento;
		}
	}
	return (char)NULL;
}

/* FUNCION: siguiente
 * ARGUMENTOS:
 * 	puntero a la celda inicial de la lista
 * 	entero que representa la posicion a partir
 * 	de la cual debe acceder a la celda siguiente
 * RETORNA:
 * 	el miembro elemento de la celda siguiente a 
 * 	la que posee poision pos
 */
char siguiente( pcelda inicio, int pos )
{
	pcelda temp = busca_celda( inicio, pos );
	if( temp == NULL )
	{
		fprintf(stderr,"ERROR siguiente: CELDA EN ESA POSICION ES NULL!\n");
		return (char)NULL;
	}
	if( temp->siguiente == NULL )
	{
		fprintf(stderr,"ERROR siguiente: CELDA SIGUIENTE A ESA POSICION ES NULL!\n");
		return (char)NULL;
	}
	else
	{
		pcelda siguiente_a_temp = temp->siguiente;
		if( siguiente_a_temp->elemento == (char)NULL )
		{
			fprintf(stderr,"ERROR siguiente: ELEMENTO EN CELDA SIGUIENTE A ESA POSICION ES NULL!\n");
			return (char)NULL;
		}
		else
		{
			return siguiente_a_temp->elemento;
		}
	}
	return (char)NULL;
}

/* FUNCION: anterior
 * ARGUMENTOS:
 * 	puntero a celda inicial de la lista
 * 	entero posicion
 * RETORNA:
 * 	miembro elemento de la celda anterior
 * 	a la celda con posicion pos.
 */
char anterior( pcelda inicio, int pos )
{
	pcelda temp = busca_celda( inicio, (pos - 1) );
	if( temp == NULL )
	{
		fprintf(stderr,"ERROR anterior: CELDA ANTERIOR A ESA POSICION ES NULL!\n");
		return (char)NULL;
	}
	if( temp->elemento == (char)NULL )
	{
		fprintf(stderr,"ERROR anterior: ELEMENTO EN CELDA ANTERIOR A ESA POSICION ES NULL!\n");
		return (char)NULL;
	}
	else
	{
		return temp->elemento;
	}
	return (char)NULL;
}

/* FUNCION: purga
 * AGUMENTOS:
 * 	puntero a celda inicial de la lista
 * RETORNA:
 * 	void
 */
void purga( pcelda inicio )
{
	if( inicio == NULL )
		fprintf(stderr,"ERROR purga: NO HAY LISTA !\n");
	if( inicio->siguiente == NULL )
		fprintf(stderr,"ERROR purga: LISTA VACIA !\n");
	int i,j;
	pcelda temp_i, temp_j;
	temp_i = inicio->siguiente;
	temp_j = busca_celda( inicio, cantidad );
	for( i = 1; i <= cantidad ; i++ )
	{
		for( j = cantidad; j > i ; j-- )
		{
			if( strcmp( &(temp_i->elemento), &(temp_j->elemento) ) == 0 )
			{
				suprime( inicio, j );
				printf("\nADVERTENCIA purga: PURGANDO ELEMENTOS DUPLICADOS...\n");
				printf("ADVERTENCIA purga: LA CELDA %d HA SIDO ELIMINADA SATISFACTORIAMENTE!\n", j);
				printf("\nADVERTENCIA purga: ELEMENTOS DUPLICADOS ELIMINADOS SATISFACTORIAMENTE!\n", j);
			}
			temp_j = busca_celda( inicio, j-1);
		}
		temp_i = temp_i->siguiente;
	}
}

/* FUNCION: muestra
 * ARGUMENTOS:
 * 	puntero a celda inicial de la lista
 * RETORNA:
 * 	void
 */
void muestra( pcelda inicio )
{
	int indice = 0;
	if( inicio == NULL )
		fprintf(stderr,"\nERROR muestra: NO HAY LISTA!\n");
	if( inicio->siguiente == NULL )
		fprintf(stderr,"\nERROR muestra: LISTA VACIA!\n");
	pcelda temp = inicio->siguiente; // temp <··> CELDA 1 <··> POSICION 1
	indice++;			 // POSCION 1
	if( temp->elemento == (char)NULL )
		fprintf(stderr,"\nERROR muestra: MIEMBRO ELEMENTO DE CELDA CON POSICION %d ES NULL!\n", indice);
	//while( temp->siguiente != NULL && indice <= cantidad )
	for( indice = 1 ; indice <= cantidad ; indice++ )
	{
		if( temp->elemento == (char)NULL )
			fprintf(stderr,"\nERROR muestra: MIEMBRO ELEMENTO ES NULL!\n");
		else
			printf("\nADVERTENCIA muestra: MIEMBRO ELEMENTO DE CELDA %d ES: %c \n", indice, temp->elemento );
		temp = temp->siguiente;
		//indice++;
	}
	//while( temp->siguiente != NULL && indice <= cantidad );
}

/* FUNCION PRINCIPAL MAIN EJECUTABLE */
int main()
{
	//1º CREA UNA LISTA
	pcelda lista = crear_lista();

	//2º INSERTA ELEMENTOS EN LA LISTA
	int i;
	char car;
	printf("\nINTRODUZCA LOS 10 CARACTERES SEGUIDOS y LUEGO UN ENTER: ");
	for( i = 1; i <= 10 ; i++ )
	{
		//printf("\nINTRODUZCA UN CARACTER: ");
		//scanf("%c", &car[i]);
		//gets( &car, 2, stdin );
		//car = (char)fgetc( stdin );
		//read( stdin, &car, 1 );
		car = getchar();
		//printf("\n");
		inserta( lista, i, car );
	}

	//3º MUESTRA LA LISTA
	printf("\n");
	muestra( lista );
	printf("\n");
	
	//4º BORRA ELEMENTO DE ALGUNA POSICION
	int pos;
	printf("\nINTRODUZCA LA POSICION DE LA CELDA A ELIMINAR: \n");
	scanf("%d", &pos );
	suprime( lista, pos );
	
	//5º MUESTRA LA LISTA NUEVAMENTE
	printf("\n");
	muestra( lista );
	printf("\n");
	
	//6º PURGA LA LISTA
	purga( lista );
	
	//7º MUESTRA LA LISTA NUEVAMENTE
	printf("\n");
	muestra( lista );
	printf("\n");
	
	//8º BUSCA UN CARACTER
	int pos_localiza = localiza( lista, 'a'  );
	if( pos_localiza <  0 )
	{
		fprintf(stderr, "ERROR: CARACTER 'a' NO SE ENCUENTRA!\n");
	}
	else
	{
		printf("\nLA PRIMERA APARICION DEL CARACTER %c SUCEDE EN LA CELDA %d \n", 'a', pos_localiza);
	}

	//9º MUESTRA EL PRIMER CARACTER
	char primer = primero( lista );
	if( primer == (char)NULL )
		fprintf(stderr, "\nERROR: EL PRIMER CARACTER DE LA LISTA ES NULL!\n");
	else
		printf("\nEL PRIMER CARACTER DE LA LISTA ES: %c \n", primer);
	
	//10º MUESTRA UN CARACTER EN ALGUNA POSICION
	int alguna_pos;
	printf("\nINTRODUZCA ALGUNA POSICION ENTRE 1 Y %d :\n", cantidad );
	scanf("%d", &alguna_pos );
	pcelda temp = busca_celda( lista, alguna_pos );
	printf("\nCARACTER DE CELDA %d ES: %c \n", alguna_pos, temp->elemento);
	printf("\nY EL CARACTER DE LA CELDA ANTERIOR ES: %c \n", anterior( lista, alguna_pos ));
	printf("\nY EL CARACTER DE LA CELDA POSTERIOR ES: %c \n", siguiente( lista, alguna_pos));
	
	//11º IMPRIME LA POSICION FINAL
	int final = fin( lista );
	printf("\nLA POSICION FINAL ES: %d", final);

	//12º MUESTRA LA LISTA 
	printf("\n");
	muestra( lista );

	return 0;
}
