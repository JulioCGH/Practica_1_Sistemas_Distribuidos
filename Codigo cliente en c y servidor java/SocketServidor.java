

import java.net.*;
import java.io.*;

public class SocketServidor
{    
    public static void main (String [] args)
    {
     
        new SocketServidor();
    }
    
     /**
      * Constructor por defecto. Hace todo lo que hace el ejemplo.
      */
    public SocketServidor()
    {
        try
        {
     
            ServerSocket socket = new ServerSocket (15557);
            
     
            System.out.println ("Esperando conexion del cliente \n");
            Socket cliente = socket.accept();
            System.out.println ("Conectado con cliente de " + cliente.getInetAddress());
   	    System.out.println ("\nPuerto de Conexion: 15557\n");
            cliente.setSoLinger (true, 10);

            // Se prepara un dato para enviar.
            DatoSocket dato = new DatoSocket("Hola Cliente");

            // Se prepara un flujo de salida de datos, es decir, la clase encargada
            // de escribir datos en el socket.
            DataOutputStream bufferSalida = 
                new DataOutputStream (cliente.getOutputStream());
            
            // Se envía el dato.
            dato.writeObject (bufferSalida);
            System.out.println ("\nMensaje a enviar al cliente y su longitud: " + dato.toString());

            // Se prepara el flujo de entrada de datos, es decir, la clase encargada
            // de leer datos del socket.
            DataInputStream bufferEntrada =
               new DataInputStream (cliente.getInputStream());

            // Se crea un dato a leer y se le dice que se rellene con el flujo de
            // entrada de datos.
            DatoSocket aux = new DatoSocket("");
            aux.readObject (bufferEntrada);
            System.out.println ("\nMensaje recibido por parte del cliente y su longitud: " + aux.toString());
            
       
            cliente.close();
            
   
            socket.close();
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
    }
}
