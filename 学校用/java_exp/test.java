import java.nio.charset.StandardCharsets;
import java.util.Base64;

public class test {
    public static void main(String[] args){
        String encode=Base64.getEncoder().encodeToString("?".getBytes(StandardCharsets.UTF_8));
        System.out.println(encode);

        byte[] decode_Byte=Base64.getDecoder().decode(encode);
        System.out.println(new String(decode_Byte));
    }
}
