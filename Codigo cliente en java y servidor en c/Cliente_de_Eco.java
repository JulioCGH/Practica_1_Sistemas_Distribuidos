
import java.io.*;
import java.net.*;
import java.util.Scanner;

public class Cliente_de_Eco {
    public int Numero=0;


    public static void main(String[] args) throws IOException {
        
        if (args.length != 2) {
            System.err.println(
                "Uso desde consola: java Cliente_de_Eco <nombre de host (computadora)> <numero puerto>");
            System.exit(1);
        }
        String nombreHost = args[0];
        int numeroPuerto = Integer.parseInt(args[1]);
        new Cliente_de_Eco(numeroPuerto,nombreHost);

    }
    public Cliente_de_Eco(int numeroPuerto, String nombreHost){
        try {

            Scanner lectura= new Scanner(System.in);
            Socket Server= new Socket(nombreHost,numeroPuerto);
            System.out.println ("Esperando conexion del server \n");


            while (true){

                System.out.println ("Ingrese el numero a enviar: ");
                Numero=lectura.nextInt();

                DatoSocket dato=new DatoSocket(Numero);

                DataOutputStream bufferSalida=
                        new DataOutputStream(Server.getOutputStream());

                //Se envia numero
                dato.writeObject(bufferSalida);
                System.out.println ("Numero enviado: "+dato.c);

                //se recibe numero modificado
                DataInputStream bufferEntrada=
                        new DataInputStream(Server.getInputStream());

                DatoSocket aux =new DatoSocket(0);
                aux.readObject(bufferEntrada);
                System.out.println ("Numero recibido por servidor: "+aux.c);

                if(aux.c==1){
                    break;
                }

            }

        Server.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
