import javax.crypto.Cipher;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;
import java.io.DataOutputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.*;
import java.nio.charset.StandardCharsets;
import java.util.Base64;
import java.util.Scanner;

public class 实验三客户端 {
    public static void three_Client() throws Exception{
        System.out.println("实验三第三题客户端");
        Socket socket=new Socket("127.0.0.1",8000);
        OutputStream OutputStream = socket.getOutputStream();//用于发送数据
        while(true){
            String mes=new Scanner(System.in).nextLine();

            //加密
            String key="1234567890123456";
            Cipher c=Cipher.getInstance("AES/CBC/PKCS5Padding");
            String IV="1234567890123456";//设置初始向量，128bit
            c.init(Cipher.ENCRYPT_MODE,new SecretKeySpec(key.getBytes(),"AES"),new IvParameterSpec(IV.getBytes()));//设置加密模式
            byte[] data=c.doFinal(mes.getBytes(StandardCharsets.UTF_8));
            //base64加密
            byte[] cipher_Byte=Base64.getEncoder().encode(data);
            System.out.println(new String(cipher_Byte));
            //byte[] data=mes.getBytes(StandardCharsets.UTF_8);
            OutputStream.write(cipher_Byte);
            OutputStream.write(' ');
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
    public static void main(String[] args) throws Exception{
        //System.out.println(123);
        three_Client();
    }

}
