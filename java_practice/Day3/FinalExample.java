package Day3;

public class FinalExample {

	final static int a = 10;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		final int b = 10;
		// b += 10; 		// Error since final b value can't be changed
		
		System.out.println(a);
	}

}
