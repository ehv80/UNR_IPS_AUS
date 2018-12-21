/* IMPLEMENTACION DE LISTAS DOBLEMENTE ENLAZADAS
 * MEDIANTE PUNTEROS A CELDAS. VERSION SENCILLA 
 * EN LA QUE SE ALMACENAN CARACTERES */

/* ARCHIVOS DE CABECERA */
#include "celdas_doble_enlace.h"

/* IMPLEMENTACION DE LAS FUNCIONES */

/* FUNCION: error
 * ARGUMENTOS:
 * 	cadena de caracteres descriptiva del error.
 * RETORNA:
 * 	void
 */
void error( char * msg )
{
	fprintf(stderr,"\n");
	perror(msg);
	fprintf(stderr,"\n");
}

/* FUNCION: crear_lista
 * ARGUMENTOS:
 * 	void
 * RETORNA:
 * 	puntero a celda raiz CELDA CERO
 *	inicializando a 10 elementos con los valores 
 *	del caracter 'a' y sus sucesores valores 
 *	correspondientes a sumarle uno en cada iteración
 *
 * Ademas se inicializa cantidad en 
 * su valor apropiado correspondiente.
 */
pcelda crear_lista_doble_enlace(void)
{
	pcelda temp = (pcelda)malloc( sizeof( scelda ) );
        temp->elemento = '0';
        temp->siguiente = NULL;
        temp->anterior = NULL;
        cantidad = 0; // CELDA RAIZ NO SE CUENTA
        return temp;				
}

/* FUNCION: busca_celda_previa 
 * ARGUMENTOS:
 * 	puntero a celda inicial
 * RETORNA:
 * PUNTERO A CELDA QUE CORRESPONDE A LA POSICION
 * DE LA CELDA CUYO MIEMBRO siguiente ESTÁ EN LA
 * POSICION pos
 */
pcelda busca_celda_previa( pcelda inicio, int pos )
{
	if(inicio == NULL)
	{
		error("ADVERTENCIA busca_celda_previa: NO HAY LISTA DOBLEMENTE ENLAZADA!");
		return (pcelda)NULL;
	}
	else
	{
		/* HAY LISTA DOBLEMENTE ENLAZADA VACÍA */ 
		if( inicio->siguiente == NULL )
		{
			error("ADVERTENCIA busca_celda_previa: HAY LISTA DOBLEMENTE ENLAZADA VACÍA!");
			return (pcelda)NULL;

		}
		else
		{
			/*HAY LISTA DOBLEMENTE ENLAZADA CON AL MENOS UN ELEMENTO*/
			if( pos < 0 || pos > cantidad )
			{
				error("ADVERTENCIA busca_celda_previa: CELDA NO EXISTE, POSICION INADECUADA!");
				return (pcelda)NULL;
			}
			else
			{
				int posTemp = 0;
				pcelda temp = inicio;
				while( (posTemp <= cantidad) && (temp->siguiente != NULL) )
				{
					if( posTemp == (pos - 1) )
					{
						return temp;
					}
					temp = temp->siguiente;
					posTemp++;
				}
				fprintf(stderr, "\nADVERTENCIA busca_celda_previa: CELDA PREVIA A LA POSICION %d-ÉSIMA INEXISTENTE!\n",pos); 
				return (pcelda)NULL;
			}
		}
	}
}

/* FUNCION: celda_final
 * ARGUMENTOS: 
 * 	puntero a celda inicial
 * RETORNA:
 * 	la celda final
 */	
pcelda celda_final( pcelda inicio )
{
	pcelda previaFinal, final;
	previaFinal = busca_celda_previa( inicio , cantidad );
	if( previaFinal == NULL )
	{
		/*NO HAY CELDA ANTEULTIMA*/
		error("ADVERTENCIA fin: NO HAY CELDA ANTEULTIMA!");
		return (pcelda)NULL;
	}
	else
	{
		if( previaFinal->siguiente == NULL )
		{
			/*ADVERTENCIA fin: NO HAY CELDA ULTIMA */
			error("ADVERTENCIA fin: NO HAY CELDA ULTIMA!");
			return (pcelda)NULL;
		}
		else
		{
			/*HAY CELDA ÚLTIMA*/
			final = previaFinal->siguiente;
			return final;
		}
	}
}

/* FUCION: fin
 * ARGUMENTOS:
 * 	void
 * RETORNA:
 * 	un entero que representa la posicion
 * 	relativa de la ultima celda de la lista
 * 	Aquella celda cuyo miembro siguiente
 * 	apunta a NULL 
 */
int fin( void )
{
	return cantidad;
}

/* FUNCION: inserta
 * ARGUMENTOS:
 * 	puntero a celda inicial
 * 	elemento a insertar
 * 	posicion donde insertar
 * RETORNA:
 * 	entero que indica estado de salida
 * 	0  <··> SALIDA EXITOSA
 * 	-1 <··> SALIDA ERRÓNEA
 **/
int inserta( pcelda inicio, int pos, char element )
{
	pcelda nueva;
	if( inicio == NULL )
	{	
		error("ADVERTENCIA inserta: NO HAY LISTA DOBLEMENTE ENLAZADA!");
		return -1;
	}
	if( inicio->siguiente == NULL )
	{
		error("ADVERTENCIA inserta: HAY LISTA DOBLEMENTE ENLAZADA VACIA!");
		/* INSERTA EN PRIMER ELEMENTO NULL QUE ENCUENTRA */
		error("ADVERTENCIA inserta: SE INSERTA EL ELEMENTO EN LA PRIMERA CELDA VACIA!");

		nueva = (pcelda) malloc( sizeof( scelda ) );
		nueva->elemento = element;
		nueva->siguiente = (pcelda)NULL;
		nueva->anterior = inicio;

		inicio->siguiente = nueva;

		cantidad++;

		return 0;
	}
	else
	{
		/* AL MENOS HAY UN ELEMENTO EN LA LISTA */
		pcelda previa = busca_celda_previa( inicio, pos );

		if( previa == NULL )
		{
			fprintf(stderr, "\nADVERTENCIA inserta: NO HAY CELDA ANTERIOR A LA POSICION %d-ESIMA!\n",  pos  );
			error("ADVERTENCIA inserta: SE INSERTA EL ELEMENTO EN LA PRIMER CELDA VACIA!");
			pcelda temp = inicio->siguiente;
			int posTemp = 1;
			while( temp->siguiente != NULL )
			{
				temp = temp->siguiente;
				posTemp++;
			}
			nueva = (pcelda) malloc( sizeof( scelda ) );
	                nueva->elemento = element;
	                nueva->siguiente = (pcelda)NULL;
	                nueva->anterior = temp;

			fprintf(stderr, "\nADVERTENCIA inserta: ELEMENTO INSERTADO EN LA POSICION: %d SATISFACTORIAMENTE!\n",posTemp);

			temp->siguiente = nueva;
	                cantidad++;
			return 0;
		}
		else
		{
			/* PUEDE INSERTAR EN LA POSICION INDICADA SIEMPRE Y CUANDO NO ESTE FUERA DE RANGO */
			if( pos < 0 || pos > cantidad )
			{
				error("ADVERTENCIA inserta: POSICION DE INSERCION INADECUADA FUERA DE RANGO!");
				return -1;
			}

			/* previa->siguiente PUEDE SER O NO SER NULL */
			pcelda sucesora = previa->siguiente;

			/* ALLOCA ESPACIO EN MEMORIA PARA UNA CELDA NUEVA */
			nueva = (pcelda)( malloc( sizeof( scelda ) ) );
			/* INICIALIZA LOS MIEMBROS DE LA CELDA NUEVA */
			nueva->elemento = element;
			nueva->anterior = previa;
			nueva->siguiente= sucesora;

			/*ACOMODA MIEMBRO siguiente DE LA CELDA previa*/
			previa->siguiente = nueva;
			/* previa->anterior NO SUFRE CAMBIOS */

			/*ACOMODA MIEMBRO anterior DE LA CELDA sucesora*/
			sucesora->anterior = nueva;
			/*sucesora->siguiente NO SUFRE CAMBIOS */

			/* AUMENTA LA CUENTA DE CELDAS DOBLE ENLACE */
			cantidad++;
			fprintf(stdout, "\nADVERTENCIA inserta: ELEMENTO INSERTADO EN LA POSICION: %d SATISFACTORIAMENTE!\n",pos);
			return 0;
		}
	}
}

/* FUNCION: suprime
 * ARGUMENTOS:
 * 	puntero a celda inicial CELDA CERO
 * RETORNA:
 * 	entero que indica estado de salida
 * 	0  <--> ESTADO DE SALIDA EXITOSO
 * 	-1 <--> SALIDA ERRÓNEA
 */
int suprime( pcelda inicio, int pos )
{
	if( pos < 0 || pos > cantidad )
	{
		error("ADVERTENCIA suprime: POSICION DE ELIMINACION INADECUADA!");
		return -1;
	}
	/* CELDA PREVIA NO DEBE DESAPARECER */
	pcelda previa = busca_celda_previa( inicio, pos );
	if( previa == NULL )
	{
		error("ADVERTENCIA suprime: CELDA PREVIA A ELIMINAR INEXISTENTE!");
		return -1;
	}

	/* CELDA aborrar ES LA QUE SE ELIMINA */
	pcelda aborrar = previa->siguiente;

	/* CELDA sucesora NO DEBE DESAPARECER */
	pcelda sucesora = aborrar->siguiente;

	/* HAY QUE ACOMODAR MIEMBRO siguiente DE CELDA previa */
	previa->siguiente = sucesora;
	/* MIEMBRO anterior DE CELDA previa QUEDA INTACTO */

	/* HAY QUE ACOMODAR MIEMBRO anterior DE CELDA sucesora */
	sucesora->anterior = previa;
	/* MIEMBRO siguiente DE CELDA sucesora QUEDA INTACTO */

	/*HAY QUE LIBERAR LA MEMORIA OCUPADA POR CELDA aborrar*/
	free(aborrar);

	error("ADVERTENCIA suprime: CELDA ELIMINADA SATIFACTORIAMENTE!");

	/* HAY QUE DECREMENTAR LA CUENTA DE CELDAS DOBLE ENLACE */
	cantidad--;
	return 0;
}

/* FUNCION: localiza_posicion
 * ARGUMENTOS:
 * 	puntero a celda inicio
 * 	char elemento a buscar
 * RETORNA:
 * 	posicion correspondiente a celda
 * 	que tiene como miembro elemento
 * 	al char buscado
 * 	en otro caso 
 * 	-1 si hay un error
 */
int localiza_posicion( pcelda inicio, char element )
{
	if( inicio == NULL )
	{
		error("ADVERTENCIA localiza_posicion: NO HAY LISTA DOBLEMENTE ENLAZADA!");
		return -1;
	}
	else
	{
		if( inicio->siguiente == NULL )
		{
			error("ADVERTENCIA localiza_posicion: HAY LISTA DOBLEMENTE ENLAZADA VACIA!");
			return -1;
		}
		else
		{
			int pos = 0;
			pcelda buscada = inicio;
			while( buscada->siguiente != NULL )
			{
				if( buscada->elemento == element )
				{
					return pos;
				}
				else
				{
					buscada = buscada->siguiente;
					pos++;
				}
			}
			error("ADVERTENCIA localiza_posicion: ELEMENTO NO ENCONTRADO!");
			return -1;
		}
	}
}

/* FUNCION: primero
 * ARGUMENTOS:
 * 	puntero a celda inicial
 * RETORNA:
 * 	el miembro elemento de la  primera celda
 */
char primero( pcelda inicio )
{
	char primero;
	if( inicio == NULL )
	{
		error("ADVERTENCIA primero: NO HAY LISTA DOBLEMENTE ENLAZADA!");
		return (char)NULL;
	}
	if( inicio->siguiente == NULL )
	{
		error("ADVERTENCIA primero: PRIMER ELEMENTO INEXSITENTE!");
		return (char)NULL;
	}
	primero = inicio->siguiente->elemento;
	return primero;
}

/* FUNCION: elemento_siguiente
 * ARGUMENTOS:
 * 	puntero a la celda inicial de la lista
 * 	entero que representa la posicion a partir
 * 	de la cual debe acceder a la celda siguiente
 * RETORNA:
 * 	el miembro elemento de la celda siguiente a 
 * 	la que posee poision pos
 */
char elemento_siguiente( pcelda inicio, int pos )
{
	if( pos < 0 || pos > cantidad )
	{
		error("ADVERTENCIA elemento_siguiente: POSICION INADECUADA!");
		return (char)NULL;
	}
	pcelda previaPos = busca_celda_previa( inicio, pos );
	pcelda celdaPos, sucesoraPos;
	if( previaPos == NULL )
	{
		fprintf(stderr, "\nADVERTENCIA elemento_siguiente: CELDA %d-ESIMA INEXISTENTE!\n", pos-1);
		return (char)NULL;
	}
	else
	{
		if( previaPos->siguiente == NULL )
		{
			fprintf(stderr, "\nADVERTENCIA elemento_siguiente: CELDA %d-ESIMA INEXSITENTE!\n", pos);
			return (char)NULL;
		}
		else
		{
			celdaPos = previaPos->siguiente;
			if( celdaPos->siguiente == NULL )
			{
				fprintf(stderr, "\nADVERTENCIA elemento_siguiente: CELDA %d-ESIMA INEXSITENTE!\n", pos+1);
				return (char)NULL;
			}
			else
			{
				sucesoraPos = celdaPos->siguiente;
				return sucesoraPos->elemento;
			}
		}
	}
}

/* FUNCION: elemento_anterior
 * ARGUMENTOS:
 * 	puntero a celda inicial de la lista
 * 	entero posicion
 * RETORNA:
 * 	miembro elemento de la celda anterior
 * 	a la celda con posicion pos.
 */
char elemento_anterior( pcelda inicio, int pos )
{
	pcelda previa = busca_celda_previa( inicio, pos );
	if( previa == NULL )
	{
		fprintf(stderr,"\nADVERTENCIA elemento_anterior: CELDA %d-ESIMA INEXISTENTE!\n", pos-1);
		return (char)NULL;
	}
	return previa->elemento;
}

/* FUNCION: purga
 * AGUMENTOS:
 * 	puntero a celda inicial de la lista
 * RETORNA:
 * 	entero que indica estado de salida
 * 	0:  salida exitosa
 * 	-1: salida errónea
 */
int purga( pcelda inicio )
{
	
	if( inicio == NULL )
	{
		error("ADVERTENCIA purga: NO HAY LISTA DOBLEMENTE ENLAZADA!");
		return -1;
	}
	else
	{
		if( inicio->siguiente == NULL )
		{
			error("ADVERTENCIA purga: HAY LISTA DOBLEMENTE ENLAZADA VACIA!");
			return -1;
		}
		int posIzq, posDer, resultadoSuprime;
		pcelda celIzq = inicio->siguiente;
		pcelda celDer = celda_final( inicio ); 
		if( celDer == NULL )
		{
			error("ADVERTENCIA purga: NO HAY CELDA FINAL!");
			return -1;
		}
		else
		{
			for( posIzq = 1 ; posIzq <= cantidad; posIzq++ )
			{
				for( posDer = cantidad ; posDer > posIzq ; posDer-- )
				{
					if( strcmp( &(celIzq->elemento), &(celDer->elemento) ) == 0 )
					{
						error("ADVERTENCIA purga: ELIMINANDO ELEMENTO DUPLICADO DE LA LISTA...");
						resultadoSuprime = suprime( inicio , posDer );
						if( resultadoSuprime != 0 )
						{
							error("ADEVERTENCIA purga: ERROR AL ELIMINAR ELEMENTO DUPLICADO!");
							return -1;
						}
						fprintf(stdout, "\nADVERTENCIA purga: ELEMENTO %d-ESIMO ELIMINADO SATISFACTORIAMENTE!\n", posDer);
					}
					else
					{
						celDer = busca_celda_previa( inicio, posDer );
						/* celDer = celDer->anterior; VIOLA EL SEGMENTO */
					}
				}
				celIzq = celIzq->siguiente; 
			}
			/* SI LLEGA ACA ES QUE NO HAY DUPLICADOS, AUN ASI NO SE CONSIDERA ERROR */
			fprintf(stderr, "\nADVERTENCIA purga: NO SE ENCONTRARON ELEMENTOS DUPLICADOS EN LA LISTA DOBLEMENTE ENLAZADA!\n");
			return 0;
		}
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
	if( inicio == NULL )
		fprintf(stderr,"\nADVERTENCIA muestra: NO HAY LISTA DOBLEMENTE ENLAZADA!\n");
	if( inicio->siguiente == NULL )
		fprintf(stderr, "\nADVERTENCIA muestra: HAY LISTA DOBLEMENTE ENLAZADA VACIA!\n");
	int pos = 1;
	pcelda temp = inicio->siguiente;

	printf("\n");
	while( pos <= cantidad )
	{
		fprintf(stdout, "\nADVERTENCIA muestra: ELEMENTO %d-esimo es: %c \n", pos, temp->elemento );
		temp = temp->siguiente;
		pos++;
	}
	printf("\n");
}

/* FUNCION PRINCIPAL MAIN EJECUTABLE */
int main()
{
	//1º CREA UNA LISTA
	pcelda lista = crear_lista_doble_enlace();

	if( lista == NULL ) 
		return 1;

	//2º INSERTA ELEMENTOS EN LA LISTA
	int i, resultadoInserta;
	char car[20]; /* 1 <= i <= 10 */
	fprintf(stdout, "\nINTRODUZCA LOS 10 CARACTERES SEGUIDOS y LUEGO UN ENTER: ");
	for( i = 1; i < 11 ; i++ )
	{
		scanf("%c", &car[i]);
		resultadoInserta = inserta( lista, i, car[i] );
		if( resultadoInserta != 0 )
		{
			fprintf(stderr, "\nADEVERTENCIA EN TIEMPO DE EJECUCION: ERROR AL INSERTA ELEMENTO!\n");
			return 4;
		}
	}

	//3º MUESTRA LA LISTA
	muestra( lista );
	
	//4º BORRA ELEMENTO DE ALGUNA POSICION
	int pos;
	fprintf(stdout, "\nINTRODUZCA LA POSICION DE LA CELDA A ELIMINAR: \n");
	scanf("%d", &pos );
	int resultadoSuprime = suprime( lista, pos );
	if( resultadoSuprime != 0 )
	{
		fprintf(stderr, "\nERROR AL SUPRIMIR ELEMENTO EN TIEMPO DE EJECUCIÓN!\n");
		return 2;
	}

	//5º MUESTRA LA LISTA NUEVAMENTE
	printf("\n");
	muestra( lista );
	printf("\n");
	
	//6º PURGA LA LISTA
	int resultadoPurga = purga( lista );
	if( resultadoPurga != 0 )
	{
		fprintf(stderr,"\nERROR AL PURGAR EN TIEMPO DE EJECUCIÓN!\n");
		return 3;
	}
	
	//7º MUESTRA LA LISTA NUEVAMENTE
	printf("\n");
	muestra( lista );
	printf("\n");
	
	//8º BUSCA UN CARACTER
	int posLocaliza = localiza_posicion( lista, 'a'  );

	if( posLocaliza <  0 )
	{
		fprintf(stderr, "ERROR: CARACTER 'a' NO SE ENCUENTRA!\n");
	}
	else
	{
		printf("\nLA PRIMERA APARICION DEL CARACTER %c SUCEDE EN LA CELDA %d \n", 'a', posLocaliza);
	}

	//9º MUESTRA EL PRIMER CARACTER
	char primer = primero( lista );
	if( primer == (char)NULL )
	{
		fprintf(stderr, "\nERROR: EL PRIMER CARACTER DE LA LISTA ES NULL!\n");
		return 4;
	}
	else
		printf("\nEL PRIMER CARACTER DE LA LISTA ES: %c \n", primer);
	
	//10º MUESTRA UN CARACTER EN ALGUNA POSICION
	int algunaPos;
	printf("\nINTRODUZCA ALGUNA POSICION ENTRE 1 Y %d :\n", cantidad );
	scanf("%d", &algunaPos );
	pcelda tempPrevia = busca_celda_previa( lista, algunaPos );
	pcelda temp = tempPrevia->siguiente;
	if( temp == NULL )
		error("ERROR EN TIEMPO DE EJECUCION: POSICION INADECUADA!");
	else
	{
		printf("\nCARACTER DE CELDA %d ES: %c \n", algunaPos, temp->elemento);
		printf("\nY EL CARACTER DE LA CELDA ANTERIOR ES: %c \n", elemento_anterior( lista, algunaPos ));
		printf("\nY EL CARACTER DE LA CELDA POSTERIOR ES: %c \n", elemento_siguiente( lista, algunaPos));
	}
	
	//11º IMPRIME LA POSICION FINAL
	int final = fin();
	printf("\nLA POSICION FINAL ES: %d", final);

	//12º MUESTRA LA LISTA 
	printf("\n");
	muestra( lista );

	return 0;
}
