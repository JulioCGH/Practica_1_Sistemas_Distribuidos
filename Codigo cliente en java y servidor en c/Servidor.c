/*

* Programa Servidor de socket INET, como ejemplo de utilizacion de las
* funciones de sockets.
*/
#include <Socket_Servidor.h>
#include <Socket.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> // for open sockets
#include <unistd.h> // for close sockets
#include <arpa/inet.h>

int main ()
{
	/*
	* Descriptores de socket servidor y de socket con el cliente
	*/
	int Socket_Servidor;
	int Socket_Cliente;
	char Cadena[100];
	int Numero=0;
	int castRed;

	/*
	* Se abre el socket servidor, con el servicio "cpp_java" dado de
	* alta en el archivo de /etc/services.
	*/
	Socket_Servidor = Abre_Socket_Inet ("cpp_java");
	if (Socket_Servidor == -1)
	{
		printf ("No se puede abrir socket servidor\n");
		exit (-1);
	}

	/*
	* Se espera un cliente que quiera conectarse
	*/
	Socket_Cliente = Acepta_Conexion_Cliente (Socket_Servidor);
	if (Socket_Servidor == -1)
	{
		printf ("No se puede abrir socket de cliente\n");
		exit (-1);
	}

	while(1){
				/*
			* Se lee la informacion del cliente, suponiendo que va a enviar 
			* 5 caracteres.
			*/
			Lee_Socket (Socket_Cliente, (char *)&castRed,sizeof(int));
			Numero=ntohl(castRed);

			/*
			* Se escribe en pantalla la informacion que se ha recibido del
			* cliente
			*/
			printf ("Soy Servidor, he recibido : %d\n", Numero);
			Numero=Numero+1;
			/*
			* Se prepara una cadena de texto para enviar al cliente. La longitud
			* de la cadena es 5 letras + \0 al final de la cadena = 6 caracteres
			*/

			castRed=htonl(Numero);
			Escribe_Socket (Socket_Cliente, (char *)&castRed,sizeof(Numero));
			printf ("Soy Servidor, he enviado : %d\n\n", Numero);

			if(Numero==1){
				break;
			}
	}
	

	/*
	* Se cierran los sockets
	*/
	close (Socket_Cliente);
	close (Socket_Servidor);
}
