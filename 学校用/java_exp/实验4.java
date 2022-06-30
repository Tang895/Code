import jdk.jfr.Unsigned;

import javax.crypto.Cipher;
import java.io.DataOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.charset.StandardCharsets;
import java.security.*;
import java.util.HexFormat;
import java.util.Scanner;

public class 实验4 {
    public static void test() throws Exception{
        DataOutputStream dos=new DataOutputStream(new FileOutputStream("./test.txt"));
        dos.writeBytes("China");

        byte[] a="China".getBytes(StandardCharsets.UTF_8);
        for(int i=0;i<a.length;i++){
            System.out.println(a[i]);
        }
        dos.close();
    }
    public static void one() throws Exception{
        System.out.println("java实验四第一题");//sha256
        MessageDigest MD=MessageDigest.getInstance("SHA-256");
        System.out.println("输入你要加密的内容");
        String input=new Scanner(System.in).nextLine();
        MD.update(input.getBytes(StandardCharsets.UTF_8));
        byte[] Hash_message=MD.digest();
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<Hash_message.length;i++){sb.append(Integer.toHexString(Hash_message[i]&0xff));}
        System.out.println("加密结果："+sb);
    }
    public static void two_server() throws Exception{
        System.out.println("java实验四第二题服务端");//sha256
        ServerSocket sS=new ServerSocket(8000);
        Socket socket=sS.accept();
        InputStream iS=socket.getInputStream();
        StringBuilder sb=new StringBuilder();
        for(int i=iS.read();i!=' ';i=iS.read()){sb.append((char)i);}
        int at=sb.indexOf("||");
        String mes=sb.substring(0,at);
        String hash=sb.substring(at+2,sb.length());
        System.out.println("MES:"+mes+"\n"+"HASH:"+hash);
    }
    public static void three() throws Exception{
        System.out.println("java实验四第三题\n"+"输入要认证的信息");
        String plaintext=new Scanner(System.in).nextLine();//输入要认证的消息
        KeyPairGenerator generator = KeyPairGenerator.getInstance("RSA");
        generator.initialize(1024);
        KeyPair pair = generator.generateKeyPair();
        PrivateKey privateKey=pair.getPrivate();
        PublicKey publicKey=pair.getPublic();
        Cipher cipher=Cipher.getInstance("RSA");
        cipher.init(Cipher.ENCRYPT_MODE,privateKey);
        byte[] cipher_Text_Byte=cipher.doFinal(plaintext.getBytes(StandardCharsets.UTF_8));
        System.out.println("认证信息："+new String(cipher_Text_Byte));
        //认证
        cipher.init(Cipher.DECRYPT_MODE,publicKey);
        byte[] plaintext_Byte=cipher.doFinal(cipher_Text_Byte);
        System.out.println("认证信息解密结果："+new String(plaintext_Byte));
    }
    public static void six(){
        System.out.print("java第四次实验第六题\n"+"输入：");
        while(true){
            String input=new Scanner(System.in).nextLine();
            int judge=1;
            for(int i=0;i<input.length()/2;i++){
                if(input.charAt(i)!=input.charAt(input.length()-i-1)){
                    judge=0;
                    System.out.println("这不是回文");
                    break;
                }
            }
            if(judge==1){
                System.out.println("这是回文");
            }
        }
    }
    public static void main(String[] args)throws Exception{
        //one();
        //test();
        //two_server();
        //six();
        three();
    }
}
