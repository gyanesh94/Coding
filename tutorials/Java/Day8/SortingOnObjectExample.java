package Day8;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Iterator;

public class SortingOnObjectExample {

	public static void main(String[] args) {
		ArrayList<Person> p = new ArrayList<>();

		p.add(new Person("H", 1));
		p.add(new Person("F", 12));
		p.add(new Person("G", 31));
		p.add(new Person("K", 433));
		p.add(new Person("A", 112));
		p.add(new Person("S", 65));
		p.add(new Person("D", 76));
		p.add(new Person("B", 89));
		p.add(new Person("U", 56));

		// Comparable interface Example not workable if we want to sort both string and int at same time
//		Collections.sort(p); // It doesn't sort. To do it Person must implements comparable

		// Comparator Example. For having sorting on various format
		NameCompare n = new NameCompare();
		AgeCompare a = new AgeCompare();
//		Collections.sort(p, n);
		Collections.sort(p, a);
		p.sort(n);
		p.sort(a);
		Iterator<Person> itr;
		itr = p.iterator();
		while (itr.hasNext()) {
			Person o = itr.next();
			System.out.println(o.getName() + "\t" + o.getAge());
		}
	}
	
	// Name Comparator Example
	static class NameCompare implements Comparator<Person> {
		@Override
		public int compare(Person o1, Person o2) {
			return o1.getName().compareTo(o2.getName());
		}
	}
	
	// Age Comparator Example
		static class AgeCompare implements Comparator<Person> {
			@Override
			public int compare(Person o1, Person o2) {
				return o1.getAge() - o2.getAge();
			}
		}
}