package Day5;

public class ExceptionClass {

	public static void main(String[] args) {
		int a = 10;
//		divideA(a);
//		System.out.println(divideB(a));
//		System.out.println(divideC(a));
//		System.out.println(divideD(a));
		System.out.println(divideE(a));
	}

	static void divideA(int i) {
		try {
			System.out.println(i / 0);
		} catch (ArithmeticException e) {
			System.out.println("OMG!! Exception is here!");
		} finally {
			System.out.println("Finally is called here");
		}

		System.out.println("Ending of Method");

		try {
			System.out.println(i / 0);
//		} catch (ArithmeticException e) {
//			System.out.println("OMG!! Exception is here!");
		} finally {
			System.out.println("Finally is called here");
		}
		// Since Catch is commented ie not written error persist and not caught raises exception in prg
		System.out.println("Ending of Method 2");
	}
	
	static int divideB(int i) {
		try {
			System.out.println(i / 0);
		} catch (ArithmeticException e) {
			System.out.println("OMG!! Exception is here!");
			return 1;
		} finally {							// finally is always called even though error is thrown catch stmt caught it and contains return
			System.out.println("Finally is called here");
			return 2;
		}
	}
	
	static int divideC(int i) {		// here finally called first then return stmt in ctch block is executed
		try {
			System.out.println(i / 0);
		} catch (ArithmeticException e) {
			System.out.println("OMG!! Exception is here!");
			return 1;
		} finally {
			System.out.println("Finally is called here");
		}
		
		return 2;
	}
	
	static int divideD(int i) {
		try {
			System.out.println(i / 0);
		} catch (ArithmeticException e) {
			System.out.println("OMG!! Exception is here!");
			if (true) return 1;
			System.out.println("in Catch");
		} finally {
			System.out.println("Finally is called here");
		}
		
		return 2;
	}
	
	static int divideE(int i) {
		try {
			System.out.println(i / 0);
			return 0;
		} catch (ArithmeticException e) {
			System.out.println("OMG!! Exception is here!");
			return 1;
		} finally {
			System.out.println("Finally is called here");
		}
//		return 2; // Unreachable code
	}
}
