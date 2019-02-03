package Day10;

public class TestClass {
	int a;
	private String s;

	public TestClass() {
		System.out.println("This is Constructor");
	}

	void methodOne() {
		System.out.println("Method One " + a);
	}

	void methodTwo(int a) {
		System.out.println("Method Two " + a);
	}

	private void methodThree() {
		System.out.println("Private Method Three " + s);
	}
}
