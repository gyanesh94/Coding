package Day3;

public class VarArgsExample {

	public static void main(String[] args) {
		show(1);
		show(1, 2);
		show(1, 2, 3);

		show(); // When ... for int and string will be present it will show
				// error because it will cause ambiguity. to resolve it create a
				// empty show function
		show(1, 2, 3, 4);
	}

	static void show() {
		System.out.println("Empty");
	}

	static void show(int a, int b) {
		System.out.println("Two Parameter");
	}

	static void show(int a, int b, int c) {
		System.out.println("Three Parameter");
	}

	static void show(int... a) { // All above 3 is equivalent to this
									// definition. argument can be 0 or more
		for (int i : a) {
			System.out.println(i);
		}
	}

	static void show(String... a) {
		for (String i : a) {
			System.out.println(i);
		}
	}

}
