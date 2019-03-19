package Day8;

import java.util.HashSet;
import java.util.Iterator;

public class HashSetExample {
	public static void main(String[] args) {
		HashSet<String> hs = new HashSet<>();		// HashSet Ascending order and unique

		hs.add("A");
		hs.add("B");
		hs.add("D");
		hs.add("e");
		hs.add("E");
		hs.add("A");
		hs.add("C");
		hs.add("B");

		Iterator<String> itr;
		itr = hs.iterator();
		while (itr.hasNext()) {
			System.out.println(itr.next());
		}
	}
}