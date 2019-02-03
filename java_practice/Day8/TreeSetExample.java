package Day8;

import java.util.Iterator;
import java.util.TreeSet;

public class TreeSetExample {

	public static void main(String[] args) {
		TreeSet<String> ts = new TreeSet<>();

		ts.add("A");
		ts.add("B");
		ts.add("D");
		ts.add("e");
		ts.add("E");
		ts.add("A");
		ts.add("C");
		ts.add("B");

		Iterator<String> itr;
		itr = ts.iterator();
		while (itr.hasNext()) {
			System.out.println(itr.next());
		}
	}

}
