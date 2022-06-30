import java.io.OutputStream;
import java.net.Socket;
import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.util.Scanner;

public class 实验四客户端 {
    public static void two_client() throws Exception{
        System.out.println("实验四第二题客户端");
        Socket socket=new Socket("127.0.0.1",8000);
        OutputStream OutputStream = socket.getOutputStream();//用于发送数据
        MessageDigest MD=MessageDigest.getInstance("SHA-256");
        while(true){
            System.out.println("输入你要传输的内容：");
            String input=new Scanner(System.in).nextLine();
            MD.update(input.getBytes(StandardCharsets.UTF_8));
            byte[] Hash_message=MD.digest();
            StringBuilder sb=new StringBuilder();
            for(int i=0;i<Hash_message.length;i++){sb.append(Integer.toHexString(Hash_message[i]&0xff));}
            System.out.println("SHA256加密结果："+sb);
            String send_Mes=input+"||"+sb;//用一个分割符
            OutputStream.write(send_Mes.getBytes(StandardCharsets.UTF_8));//发送数据
            OutputStream.write(' ');
            if(1==2)
                break;
        }
        socket.close();

    }
    public static void main(String[] args)throws Exception{
        two_client();
    }
}
