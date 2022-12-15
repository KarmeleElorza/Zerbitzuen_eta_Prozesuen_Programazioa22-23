/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package zerbitzuak_socket_TCP;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.InetAddress;
import java.net.Socket;

/**
 *
 * @author elorza.karmele
 */
public class Cliente_Calc {
    public static void main(String[] args) throws IOException {
        String Host = "localhost";
        int Puerto = 6000;//puerto remoto
        Socket Cliente = new Socket(Host, Puerto);
        InetAddress i = Cliente.getInetAddress();
        System.out.println("Puerto Local: " + Cliente.getLocalPort());
        System.out.println("Puerto Remoto: " + Cliente.getPort());
        System.out.println("Host Remoto: " + i.getHostName().toString());
        System.out.println("IP Host Remoto: " + i.getHostAddress().toString());
        System.out.println("PROGRAMA CLIENTE INICIADO....");
  // CREO FLUJO DE SALIDA AL SERVIDOR
        OutputStream salida = null;
        salida = Cliente.getOutputStream();
        DataOutputStream flujoSalida = new DataOutputStream(salida);
        // ENVIO AL SERVIDOR
        flujoSalida.writeUTF("7 * 9");
        // CREO FLUJO DE ENTRADA AL SERVIDOR
        InputStream entrada = null;
        entrada = Cliente.getInputStream();
        DataInputStream flujoEntrada = new DataInputStream(entrada);
         // EL SERVIDOR ME ENVIA UN MENSAJE
        System.out.println("Recibiendo del Servidor: \n\t" + flujoEntrada.readUTF());
        // CERRAR STREAMS Y SOCKETS
        salida.close();
        flujoSalida.close();
        
        entrada.close();
        flujoEntrada.close();
        Cliente.close();
    }
}
