import java.util.Scanner;
import java.math.BigInteger;
public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int i = sc.nextInt();
        BigInteger r = new BigInteger("2").pow(i);
        System.out.println(r.toString());
    }
}