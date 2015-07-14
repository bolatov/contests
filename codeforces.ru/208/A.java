import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		str = str.replaceAll("WUB", " ");
		String[] split = str.split(" ");
		for (String s : split) {
			System.out.print(s + " ");
		}
		System.out.println();
	}
}