import javax.net.ssl.SSLServerSocket;
import java.io.FileInputStream;
import java.math.BigInteger;
import java.net.ServerSocket;
import java.security.PublicKey;
import java.security.cert.Certificate;
import java.security.cert.CertificateFactory;
import java.security.cert.X509Certificate;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

public class 实验五 {
    public static void one() throws Exception{
        System.out.println("java实验五第一题");
        CertificateFactory cf=CertificateFactory.getInstance("X.509");
        FileInputStream in=new FileInputStream("mytest.cer");
        java.security.cert.Certificate c=cf.generateCertificate(in);
        in.close();
        X509Certificate t=(X509Certificate) c;
        System.out.println("版本号 "+t.getVersion());
        System.out.println("序列号 "+t.getSerialNumber().toString(16));
        System.out.println("全名 "+t.getSubjectDN());
        System.out.println("签发者全名n"+t.getIssuerDN());
        System.out.println("有效期起始日 "+t.getNotBefore());
        System.out.println("有效期截至日 "+t.getNotAfter());
        System.out.println("签名算法 "+t.getSigAlgName());
        byte[] sig=t.getSignature();
        System.out.println("签名n"+new BigInteger(sig).toString(16));
    }
    public static void two() throws Exception{
        System.out.println("java实验五第二题");
        CertificateFactory cf=CertificateFactory.getInstance("X.509");
        FileInputStream in=new FileInputStream("mytest.cer");
        java.security.cert.Certificate c=cf.generateCertificate(in);
        in.close();
        X509Certificate t=(X509Certificate) c;
        System.out.println("输入年月日如2022-03-24");
        String input=new Scanner(System.in).nextLine();
        SimpleDateFormat simpleDateFormat=new SimpleDateFormat("yyyy-mm-dd");
        Date input_Date=simpleDateFormat.parse(input);
        System.out.println("有效期起始日 "+t.getNotBefore());
        Date date=t.getNotBefore();
        if(-1==date.compareTo(input_Date)){
            System.out.println("符合使用时间！");
        }else{
            System.out.println("不符合使用时间");
        }
        System.out.println("有效期截至日 "+t.getNotAfter());
        if(1==t.getNotAfter().compareTo(input_Date)){
            System.out.println("符合截止时间！");
        }else{
            System.out.println("不符合截止时间！");
        }
    }
    public static void three() throws Exception{
        SSLServerSocket sslServerSocket= (SSLServerSocket) new ServerSocket(8000);

    }
    public static void main(String[] args) throws Exception{
        //one();
        while(true)
        two();
    }
}
