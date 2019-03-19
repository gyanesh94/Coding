package Day8;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;

public class SortingExample {

	public static void main(String[] args) {
		ArrayList<String> a1 = new ArrayList<>();
		a1.add("cabd");
		a1.add("scfd");
		a1.add("asd");
		a1.add("yas");
		Collections.sort(a1);

		Iterator<String> itr;
		itr = a1.iterator();
		while (itr.hasNext()) {
			System.out.println(itr.next());
		}
	}

}
