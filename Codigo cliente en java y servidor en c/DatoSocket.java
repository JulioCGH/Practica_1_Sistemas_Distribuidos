
import java.io.*;


public class DatoSocket implements Serializable
 {

/** Primer atributo, un int */
   public int c = 0;

   public DatoSocket (int numero)
   {
         c = numero;
   }
     
   /** Método para devolver un String en el que se represente el valor de
    * todos los atributos. */

 
   public void writeObject(java.io.DataOutputStream out)
         throws IOException
     {
         // Se envía la longitud de la cadena + 1 por el \0 necesario en C
         out.writeInt (c);
     }
    
      /**
      * Método que lee los atributos de esta clase de un DataInputStream tal cual nos los
      * envía un programa en C.
      * Este método no contempla el caso de que se envíe una cadena "", es decir, un
      * único \0.
      */
     public void readObject(java.io.DataInputStream in)
     throws IOException
     {
         // Se lee la longitud de la cadena y se le resta 1 para eliminar el \0 que
         // nos envía C.
         c = in.readInt() ;

     }
}
