
import javax.crypto.KeyGenerator;
import java.io.FileInputStream;
import java.math.BigInteger;
import java.security.*;
import java.util.Scanner;

public class 实验1 {
    public static void one(){
        System.out.println("实验1第一题");
        //编写一个 Java 程序，判断 101-200 之间有多少个素数，并输出所有素数
        int sum=0;
        System.out.println("test");
        for(int i=101;i<=200;i++){
            int judge=1;
            for(int j=2;j<=Math.sqrt(i);j++){
                if(i%j==0){
                    judge=0;
                    break;
                }
            }
            if(judge==1){
                System.out.print(i+" ");
                sum++;
            }
        }
        System.out.printf("一共有%d个\n",sum);
    }
    public static String two_func(String a,String b){
        return a+b;
    }
    public static int two_func(int a,int b){
        return a+b;
    }
    public static double two_func(double a,double b){
        return a+b;
    }
    public static void two() throws Exception{
        System.out.println("实验二第二题:");
        /*
        * 编写一个 Java 应用程序，从键盘读取用户输入两个字符串，并重载 3 个函数分别实现
        这两个字符串的拼接、整数相加和浮点数相加。要进行异常处理，对输入的不符合要求的字
        符串提示给用户，不能使程序崩溃*/
        Scanner sc=new Scanner(System.in);
        String a=sc.next();
        String b=sc.next();
        System.out.println(two_func(a,b));
        System.out.println(two_func(Double.valueOf(a),Double.valueOf(b)));
        System.out.println(two_func(Integer.valueOf(a),Integer.valueOf(b)));
    }
    public static void three(){
        //编写一个 Java 程序，对于输入的英文字符串，实现凯撒密码的加解密功能。
        System.out.println("实验1第三题:");
        Scanner sc=new Scanner(System.in);
        System.out.println("输入plaintext:");
        String plaintext=sc.nextLine();
        System.out.println("输入x,x<26:");
        int x=sc.nextInt();
        x=x%26;
        String cipher="";
        for(int i=0;i<plaintext.length();i++){
            if(plaintext.charAt(i)==' '){
                cipher+=" ";
                continue;
            }
            cipher+=String.valueOf((char)((plaintext.charAt(i)+x)%97+97));//只考虑小写的情况
        }
        System.out.printf("密文：%s\n",cipher);
    }
    public static void four(){
        System.out.println("java实验1第四题");
        /*
        * （4）编写一个 Java 程序，使用二维数组对用户输入的 14 个英文字符实现置换密码功能，
        其中：
        1）加密密钥为：key={6,3,0,4,5,1,2}。(明文按照每 7 个字符分割为一组，每组字符均
        按照此加密规则)
        2）将加密和解密后的结果显示在屏幕上。*/
        int[] key={6,3,0,4,5,1,2};
        System.out.println("输入plaintext:");
        Scanner sc=new Scanner(System.in);
        String plaintext=sc.nextLine();
        if(plaintext.length()!=14) {
            System.out.println("输入的字符数量不对");
            return;
        }
        String cipher="";
        for(int i=0;i<plaintext.length();i++){
            cipher+=String.valueOf((char)plaintext.charAt(key[i%7]+(7*(i/7))));
        }
        System.out.printf("加密密文：%s\n",cipher);
    }
    public static void five() throws Exception{
        System.out.println("实验1第五题:");
        //应用 FileInputStream 类，编写应用程序，从磁盘上读取一个 Java 程序，并将源程序代
        //码显示在屏幕上。（被读取的文件路径为：C:/myjava/Hello.java）。
        FileInputStream java_source_file=new FileInputStream("c:/myjava/Hello.java");
        while(java_source_file.available()!=0){
            System.out.print((char)java_source_file.read());
        }
    }
    public static void six() throws Exception{
        //编写一个 Java 程序，生成一对 RSA 公私密钥对（模长：512），并将公私密钥对以字
        //节形式分别保存在 2 个文件中，并将密钥值显示在屏幕上。
        System.out.println("实验1第六题：");
        KeyPairGenerator kpg = KeyPairGenerator.getInstance("RSA");
        kpg.initialize(512);
        KeyPair k_pair=kpg.genKeyPair();
        PublicKey pk=k_pair.getPublic();
        PrivateKey sk=k_pair.getPrivate();
        byte[] skk=sk.getEncoded();
        System.out.printf("私钥：%s\n",sk.toString());
        byte[] pkk=pk.getEncoded();
        System.out.printf("公钥：%s\n",pk.toString());
    }
    public static void seven() throws Exception{
        System.out.println("实验一第七题");
        //编写一个 Java 程序，生成 256 位 AES 密钥，并将该密钥以对象的形式存储在文件中，
        //并将文件信息读取至程序中，在屏幕上显示出具体的密钥值。
        KeyGenerator aes_key=KeyGenerator.getInstance("AES");
        aes_key.init(256);
        Key mykey=aes_key.generateKey();
        System.out.printf("密钥：%s\n",mykey.toString());
    }
    public static void main(String[] args) throws Exception{
        //seven();
        //six();
        //five();
        //four();
        //three();
        //two();
        one();
        two();
        three();
        four();
        five();
        six();
        seven();
    }
}
