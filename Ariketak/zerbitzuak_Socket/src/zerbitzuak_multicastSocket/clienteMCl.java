package zerbitzuak_multicastSocket;

import java.io.*;
import java.net.*;

/**
 *
 * @author elorza.karmele
 */
public class clienteMCl {

    public static void main(String args[]) throws Exception {
//Se crea el socket multicast
        int Puerto = 12345;//Puerto multicast
        MulticastSocket ms = new MulticastSocket(Puerto);
        InetAddress grupo = InetAddress.getByName("225.0.0.1");//Grupo
//Nos unimos al grupo
        ms.joinGroup(grupo);
        String msg = "";
        byte[] buf = new byte[1000];

        while (!msg.trim().equals("*")) {
//Recibe el paquete del servidor multicast
            DatagramPacket paquete = new DatagramPacket(buf, buf.length);
            ms.receive(paquete);
            msg = new String(paquete.getData());
            System.out.println("Recibo: " + msg.trim());
        }

        ms.leaveGroup(grupo); //abandonamos grupo Sims .close (); //cierra socket 

        System.out.println("Socket cerrado...");
    }

}
