import java.io.*;
import java.net.*;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class 实验2 {
    public static void one(){
        System.out.println("实验2第一题：");
        Thread a_Thead=new Thread(new Runnable() {
            @Override
            public void run() {
                int i=30;
                while(i>0){
                    i--;
                    try {
                        Thread.sleep(300);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                    System.out.print(Thread.currentThread().getName()+" ");
                }
            }
        });
        a_Thead.start();
    }
    public static void two_UDPserver() throws Exception{
        DatagramSocket socket=new DatagramSocket(8000);
        byte[] data =new byte[1024];//创建字节数组，指定接收的数据包的大小
        DatagramPacket packet=new DatagramPacket(data, data.length);
        //接收客户端发送的数据
        System.out.println("服务器端已经启动，等待客户端发送数据");
        String info="";
        while(!info.equals("bye")){
            socket.receive(packet);//此方法在接收到数据报之前会一直阻塞
            info=new String(data, 0, packet.getLength());
            System.out.println("client："+info);
        }
        socket.close();
    }
    public static void two() throws Exception{
        System.out.println("java实验2第二题服务端");
        two_UDPserver();
    }
    public static void three() throws Exception{
        System.out.println("实验二第三题服务端");
        Thread thread=new Thread(new Runnable(){
            @Override
            public void run(){
                try{
                    ServerSocket sS=new ServerSocket(8000);
                    Socket socket=sS.accept();
                    InputStream iS = socket.getInputStream();//用于接受数据
                    StringBuilder sb=new StringBuilder();
                    //解析输入流，遇到空格结束，该输入流来自客户端
                    for(int i=iS.read();i!=' ';i=iS.read()){sb.append((char)i);}
                    System.out.println("message from client:"+sb);
                    byte[] send_Mes=new byte[sb.length()];
                    for(int i=0;i<send_Mes.length;i++){
                        send_Mes[i]=(byte)sb.charAt(send_Mes.length-i-1);
                    }
                    OutputStream oS=socket.getOutputStream();
                    oS.write(send_Mes);
                    iS.close();
                    oS.close();
                    socket.close();
                    sS.close();
                }catch (IOException e){
                    e.printStackTrace();
                }
            }
        });
        thread.start();
    }
    public static void four() throws Exception{
        System.out.println("java第二次实验第四题后端");
        ServerSocket sS=new ServerSocket(8000);
        System.out.println(sS.getLocalSocketAddress());
        Socket socket=sS.accept();
        InputStream iS = socket.getInputStream();//用于接受数据
        //传输都用{}包裹
        StringBuilder sb=new StringBuilder();
        for(int c=iS.read();c!='}';c=iS.read()){
            sb.append((char)c);
        }
        sb.append('}');
        OutputStream oS=socket.getOutputStream();//反馈结果
        System.out.println("from client: "+sb);
        if(sb.toString().equals("{user:admin,pwd:admin}")){
            byte[] mes="Correct".getBytes(StandardCharsets.UTF_8);
            oS.write(mes);
        }else{
            byte[] mes="Wrong".getBytes(StandardCharsets.UTF_8);
            oS.write(mes);
        }
        oS.close();
        iS.close();
        sS.close();
    }
    public static void five() throws Exception{
        System.out.println("java第二次实验第五题");
        double[] data1={19.99,9.99,15.99,3.99,4.99};
        int[] data2={12, 8, 13, 29, 50 };
        String[] data3={"Java T-shirt", "Java Mug", "Duke Juggling Dolls", "Java Pin","Java Key Chain"};
        DataOutputStream dos=new DataOutputStream(new FileOutputStream("./data.txt"));
        for(int i=0;i<data1.length;i++){dos.writeDouble(data1[i]);}
        for(int i=0;i<data2.length;i++){dos.writeInt(data2[i]);}
        for(int i=0;i<data3.length;i++){dos.writeBytes(data3[i]);}
        dos.flush();
        dos.close();
        //读取文件
        System.out.println("读取文件");
        DataInputStream dos2=new DataInputStream(new FileInputStream("./data.txt"));
        for(int i=0;i<data1.length;i++){System.out.print(dos2.readDouble()+" ");}
        for(int i=0;i<data2.length;i++){System.out.print(dos2.readInt()+" ");}
        for(int i=0;dos2.available()>0;i++){System.out.print((char)dos2.readByte());}
    }
    public static void seven() throws Exception{
        System.out.println("实验二第七题");
        int[] data={300,301,302,303,304,305};
        DataOutputStream dos=new DataOutputStream(new FileOutputStream("./Dest.txt"));
        for(int i=data.length-1;i>=0;i--){
            dos.writeInt(data[i]);
        }
        //读取
        DataInputStream dos2=new DataInputStream(new FileInputStream("./Dest.txt"));
        for(int i=0;dos2.available()>0;i++){
            System.out.println(dos2.readInt());
        }
        dos.flush();
        dos.close();
    }
    public static void main(String[] args) throws Exception{
        //one();
        //two();
        //three();
//        while(true){
//            four();
//        }
        //five();
        seven();
    }
}
