package Day5;

import java.util.Scanner;

public class ScannerExample {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int a = sc.nextInt();
		
		String s = sc.next();
		
		String s2 = sc.nextLine();
		
		System.out.println("Entered Value " + a);
		System.out.println(s);
		System.out.println(s2);
		sc.close();
	}

}
