package zerbitzuak_socket_UDP;
import java.net.DatagramPacket; 
import java.net.DatagramSocket; 
import java.net.InetAddress;
/**
 *
 * @author elorza.karmele
 */
public class clienteUDP {

    public static void main(String[] argv) throws Exception {
        InetAddress destino = InetAddress.getLocalHost();
        int port = 12345; //puerto al que envió el datagrama 
        byte[] mensaje = new byte[1024];
        String Saludo = "Enviando Saludos !!";
        mensaje = Saludo.getBytes(); //codifico String a bytes
//CONSTRUYO EL DATAGRAMA A ENVIAR
        DatagramPacket envio = new DatagramPacket(mensaje, mensaje.length, destino, port);
        DatagramSocket socket = new DatagramSocket(34567);//Puerto local 
        System.out.println("Enviando Datagrama de longitud: "
                + mensaje.length);
        System.out.println("Host destino : " + destino.getHostName());
        System.out.println("IP Destino : " + destino.getHostAddress());
        System.out.println("Puerto local del socket: "
                + socket.getLocalPort());
        System.out.println("Puerto al que envio: " + envio.getPort());
//ENVIO DATAGRAMA
        socket.send(envio);
        socket.close(); //cierro el socket
    }
}
