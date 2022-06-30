import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import javax.crypto.SecretKeyFactory;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.PBEKeySpec;
import javax.crypto.spec.PBEParameterSpec;
import javax.crypto.spec.SecretKeySpec;
import java.io.*;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.security.*;
import java.util.Base64;
import java.util.Scanner;

public class 实验三 {
    public static void one_Decry() throws Exception{
        String key="1234567890123456";
        Cipher c=Cipher.getInstance("AES/CBC/PKCS5Padding");
        String IV="1234567890123456";//设置初始向量，128bit
        c.init(Cipher.DECRYPT_MODE,new SecretKeySpec(key.getBytes(),"AES"),new IvParameterSpec(IV.getBytes()));//设置解密模式
        DataInputStream dos=new DataInputStream(new FileInputStream("./cipher.txt"));
        StringBuilder sb=new StringBuilder();
        for(int i=0;0<dos.available();i++){
            sb.append((char)dos.read());
        }
        System.out.println("加密结果"+sb.toString());
        //base64解码
        byte[] cipher_Byte=Base64.getDecoder().decode(sb.toString());
        byte[] m=c.doFinal(cipher_Byte);
        System.out.println("解密出来的明文："+new String(m));
    }
    public static void one_Encry() throws Exception{
        System.out.println("实验三第一题");
        /*（1）编写一个 Java 程序，实现对命令行输入的信息进行加解密处理，具体实现以下功能：
        1) Java XXX ENC 文件名 1 文件名 2
        加密“文件名 1”对应的文件，并将结果存储到“文件名 2 ”对应的文件
        2) Java XXX DEC 文件名 1 文件名 2
        解密“文件名 1”对应的文件，并将结果存储到“文件名 2 ”对应的文件
        其中：
        1) 加密算法：AES
        2) 加密模式：CBC
        3) 填充方式：PKCS5Padding/NoPaddin*/
        String key="1234567890123456";
        Cipher c=Cipher.getInstance("AES/CBC/PKCS5Padding");
        String IV="1234567890123456";//设置初始向量，128bit
        c.init(Cipher.ENCRYPT_MODE,new SecretKeySpec(key.getBytes(),"AES"),new IvParameterSpec(IV.getBytes()));//设置加密模式
        System.out.println("输入要加密的明文：");
        String plaintext=new Scanner(System.in).nextLine();
        DataOutputStream dos=new DataOutputStream(new FileOutputStream("./plaintext.txt"));
        dos.writeBytes(plaintext);

        byte[] plaintext_Byte=plaintext.getBytes(StandardCharsets.UTF_8);
        //最终加密
        byte[] cipher_Byte=c.doFinal(plaintext_Byte);
        //转换为base64
        String cipher_Base64=Base64.getEncoder().encodeToString(cipher_Byte);

        //写在cipher.txt里面去
        DataOutputStream dos2=new DataOutputStream(new FileOutputStream("./cipher.txt"));
        dos2.writeBytes(cipher_Base64);
        System.out.println("加密完成，明文：plaintext.txt里面，密文在cipher.txt里面");
    }
    public static void two() throws Exception{
        System.out.println("Java实验三第二题");
        /**编写一个 Java 程序，实现 PBE 算法加解密功能，具体实现以下功能：
1) Java XXX ENC 口令 文件名 1 文件名 2
加密“文件名 1”对应的文件，并将结果存储到“文件名 2 ”对应的文件
2) Java XXX DEC 口令 文件名 1 文件名 2
解密“文件名 1”对应的文件，并将结果存储到“文件名 2 ”对应的文件
其中：
1) 加密算法：PBEWithMD5AndDES
2) 迭代次数：1000*/
        PBEKeySpec keySpec=new PBEKeySpec("abs".toCharArray());
        SecretKeyFactory keyFactory=SecretKeyFactory.getInstance("PBEWithMD5AndDES");
        SecretKey sk=keyFactory.generateSecret(keySpec);
        Key key=sk;
        Cipher cipher=Cipher.getInstance("PBEWithMD5AndDES");
        SecureRandom random=new SecureRandom();//盐 设定随机
        byte[] salt=random.generateSeed(8);
        PBEParameterSpec PBEPS=new PBEParameterSpec(salt,1000);
        cipher.init(Cipher.ENCRYPT_MODE,key,PBEPS);
        System.out.println("输入明文以加密：");
        String input=new Scanner(System.in).nextLine();
        byte[] C=cipher.doFinal(input.getBytes());
        System.out.println("密文："+new String(C));
        //解密
        cipher.init(Cipher.DECRYPT_MODE,key,PBEPS);
        byte[] M=cipher.doFinal(C);
        System.out.println("解密结果："+new String(M));
    }
    public static void three_Server() throws Exception{
        System.out.println("java实验三第三题Server端");
        /**编写一个 Java 程序，实现客户端/服务器之间的数据加密通信（假设客户端和服务器之
         间已经共享了一个密钥数据），具体满足以下要求：
         1) 客户端对命令行输入的字符串进行加密，将结果传送至服务器并显示
         2) 加密算法采用分组对称算法
         3) 每次通信采用不同的密钥对数据进行加密
         4) 通信过程需要保证用户数据和加密密钥的机密性*/
        ServerSocket sS=new ServerSocket(8000);
        Socket socket=sS.accept();
        InputStream iS = socket.getInputStream();//用于接受数据
        StringBuilder sb=new StringBuilder();
        //解析输入流，遇到空格结束，该输入流来自客户端
        for(int i=iS.read();i!=' ';i=iS.read()){sb.append((char)i);}
        System.out.println(sb);
        //base64解码
        byte[] cipher_Byte=Base64.getDecoder().decode(sb.toString());

        //解密
        String key="1234567890123456";//同样的密钥
        Cipher c=Cipher.getInstance("AES/CBC/PKCS5Padding");
        String IV="1234567890123456";//设置初始向量，128bit
        c.init(Cipher.DECRYPT_MODE,new SecretKeySpec(key.getBytes(),"AES"),new IvParameterSpec(IV.getBytes()));//设置解密模式

        byte[] plaintext_Byte=c.doFinal(cipher_Byte);
        String plaintext=new String(plaintext_Byte);
        System.out.println("message from client:"+plaintext);
        OutputStream oS=socket.getOutputStream();
        oS.write(plaintext_Byte);
        iS.close();
        oS.close();
        socket.close();
        sS.close();
    }
    public static void four() throws Exception{
        System.out.print("java实验三第四题\n"+"输入明文：");
        String plaintext=new Scanner(System.in).nextLine();
        KeyPairGenerator generator = KeyPairGenerator.getInstance("RSA");
        generator.initialize(1024);
        KeyPair pair = generator.generateKeyPair();
        PrivateKey privateKey=pair.getPrivate();
        PublicKey publicKey=pair.getPublic();
        Cipher cipher=Cipher.getInstance("RSA");
        cipher.init(Cipher.ENCRYPT_MODE,publicKey);
        byte[] cipher_Text_Byte=cipher.doFinal(plaintext.getBytes(StandardCharsets.UTF_8));
        System.out.println("加密结果："+new String(cipher_Text_Byte));
        //解密
        cipher.init(Cipher.DECRYPT_MODE,privateKey);
        byte[] plaintext_Byte=cipher.doFinal(cipher_Text_Byte);
        System.out.println("解密结果："+new String(plaintext_Byte));
    }
    public static void five(){
        //todo
        System.out.println("todo-----");
    }
    public static void main(String[] args) throws Exception{
//        one_Encry();
//        one_Decry();
        //two();
        //three_Server();
        //four();
    }
}
