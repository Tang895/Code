import java.io.InputStream;
import java.io.OutputStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.Socket;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class 实验2客户端 {
    //实验二第三题客户端
    public static void three_clientSocket() throws Exception{
        System.out.println("实验2第三题客户端");
        Socket socket=new Socket("127.0.0.1",8000);
        OutputStream OutputStream = socket.getOutputStream();//用于发送数据
        Scanner input=new Scanner(System.in);
        String mes;
        while(true){
            mes=input.nextLine();
            byte[] data=mes.getBytes(StandardCharsets.UTF_8);
            OutputStream.write(data);
            if(!mes.equals("bye")){
                break;
            }
        }
        InputStream iS=socket.getInputStream();
        StringBuilder receiveMsg=new StringBuilder();
        for (int c = iS.read(); c !=-1; c = iS.read()) {
            if(c ==-1)
                break;
            receiveMsg.append((char)c);
        }
        System.out.println("get message from server: " + receiveMsg);
        iS.close();
        OutputStream.close();
    }
    public static void two_client_Scoket() throws Exception{
        //向服务器端发送数据
        InetAddress address=InetAddress.getByName("127.0.0.1");
        int port=8000;
        while(true){
            Scanner input=new Scanner(System.in);
            String mes=input.nextLine();
            byte[] data=mes.getBytes();
            DatagramPacket packet=new DatagramPacket(data, data.length, address, port);
            DatagramSocket socket=new DatagramSocket();
            socket.send(packet);
            if(!mes.equals("bye"))
                continue;
            //关闭资源
            socket.close();
            break;
        }
    }
    public static void four_client() throws Exception{
        System.out.println("实验二第四题客户端：");
        Socket socket=new Socket("127.0.0.1",8000);
        InputStream iS=socket.getInputStream();
        OutputStream oS=socket.getOutputStream();
        System.out.println("Input your name and pwd");
        Scanner input=new Scanner(System.in);
        String user=input.next();
        String pwd=input.next();
        String send_Mes="{user:"+user+",pwd:"+pwd+"}";
        byte[] send_mes=send_Mes.getBytes(StandardCharsets.UTF_8);
        oS.write(send_mes);
        StringBuilder sb=new StringBuilder();
        for(int c=iS.read();c!=-1;c=iS.read()){
            sb.append((char)c);
        }
        System.out.println(sb);
        iS.close();
        oS.close();
        socket.close();
    }
    public static void main(String[] args) throws  Exception{
//        while (true){
//            four_client();
//        }
        //two_client_Scoket();
        //three_clientSocket();
    }
}
