package Day5;

import java.io.IOException;

public class ThrowsExample {

	public static void main(String[] args) throws IOException { // on using throws at main function the Exception  will go to JVM and it will handle it. 2nd println will not be called until Exception is not handled
		System.out.println("Main 1");
		cal_A();
		System.out.println("Main 2");
	}

	private static void cal_A() throws IOException {
		System.out.println("A 1");
		cal_B();
		System.out.println("A 2");
	}

	private static void cal_B() throws IOException {
		System.out.println("B 1");
		cal_C();
		System.out.println("B 2");
	}

	private static void cal_C() throws IOException {
		System.out.println("C 1");
		throw new IOException(); // Can do two things either we can use try
									// catch block here or pass it on to calling
									// function using throws IOException
									//		System.out.println("C 2");
	}
}
