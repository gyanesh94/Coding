package Day5;

public class MultipleCatchExamlpe {

	public static void main(String[] args) {
		multiCatch();
	}

	static void multiCatch() {
		try {
			int a = 10 / 0;
		} catch (ArithmeticException | NumberFormatException e) {
			e.printStackTrace();
		} finally {

		}
	}

}
