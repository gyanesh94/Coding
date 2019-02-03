package Day3;

class Initializer {
	{
		System.out.println("inside initializer");
	}

	public Initializer() {
		System.out.println("inside constructor");
	}

	void method() {
		System.out.println("inside method");
	}
	
	{
		System.out.println("inside initializer2");
	}
	
	static {
		System.out.println("inside static initializer");
	}
}

public class InitializerExample {

	public static void main(String[] args) {

		Initializer i = new Initializer();
		i.method();

	}

}
