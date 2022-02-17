/*
* Programa Cliente de un socket INET, como ejemplo de utilizacion
* de las funciones de sockets
*/
#include <stdio.h>
#include <Socket_Cliente.h>
#include <Socket.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h> // for open sockets
#include <unistd.h> // for close sockets
#include <arpa/inet.h>

int  main ()
{
	/*
	* Descriptor del socket y buffer para datos
	*/
	int Socket_Con_Servidor;
	char cadena[100];
	int longitud_Cadena;
	int castRed;
	/*
	* Se abre la conexion con el servidor, pasando el nombre del ordenador
	* y el servicio solicitado.
	* "localhost" corresponde al nombre de la computadoras en la que
	* estamos ejecutando. Esta dado de alta en /etc/hosts
	* "cpp_java" es un servicio dado de alta en /etc/services
	*/
	Socket_Con_Servidor = Abre_Conexion_Inet ("localhost", "cpp_java");
	if (Socket_Con_Servidor == 1)
	{
		printf ("No puedo establecer conexion con el servidor\n");
		exit (-1);
	}
	
	
	//Se va a enviar una cadena de 6 caracteres, incluido el \0
   	strcpy (cadena, "Hola servidor");
   	longitud_Cadena=strlen(cadena)+1;

   	//Antes de enviar el entero hay que transformalo a formato red
   	castRed = htonl (longitud_Cadena);
   	Escribe_Socket (Socket_Con_Servidor, (char *)&castRed, sizeof(longitud_Cadena));
   	printf ("Longitud de la cadena enviada desde el cliente C:  %d\n\n", longitud_Cadena);

   	//Se envía la cadena
   	Escribe_Socket(Socket_Con_Servidor, cadena, longitud_Cadena);
   	printf ("El cliente C dice: %s\n\n", cadena);
	
	
	
	
	
   	//Se lee un entero con la longitud de la cadena, incluido el \0
   	Lee_Socket(Socket_Con_Servidor,(char *)&castRed,sizeof(int));
   	longitud_Cadena=ntohl(castRed);
   	printf("Se recibio un mensaje con longitud: %d\n\n",longitud_Cadena);

   	//Se lee la cadena de la longitud indicada
   	Lee_Socket(Socket_Con_Servidor, cadena, longitud_Cadena);
   	printf("El mensaje recibido por parte del servidor es: %s\n\n", cadena);



	//Se cierra el socket con el servidor
	close (Socket_Con_Servidor);
	}
