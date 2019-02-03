package Day8;

import java.util.ArrayList;


// Shows On ensuring capacity first it will take less time
public class ArrayListIsertionSpeedExample {

	public static void main(String[] args) {
		ArrayList<Person> a1 = new ArrayList<>();
		a1.ensureCapacity(100);
		long time = System.nanoTime();
		for (int i = 0; i < 100; i++) {
			a1.add(new Person("A " + i, i));
		}
		System.out.println(System.nanoTime() - time);
	}

}
