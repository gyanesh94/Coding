package Day8;

import java.util.Comparator;
import java.util.Iterator;
import java.util.TreeSet;

public class TreeSetObjectExample {

	public static void main(String[] args) {
		NameCompare nc = new NameCompare(); // after using comparator hashCode will not be used
		TreeSet<Person> p = new TreeSet<>(nc);

		p.add(new Person("H", 1));
		p.add(new Person("F", 12));
		p.add(new Person("A", 112));
		p.add(new Person("H", 1));
		p.add(new Person("A", 112));
		p.add(new Person("D", 76));
		p.add(new Person("D", 75));

		Iterator<Person> itr;
		itr = p.iterator();
		while (itr.hasNext()) {
			Person o = itr.next();
			System.out.println(o.getName() + "\t" + o.getAge());
		}
	}
	
	static class NameCompare implements Comparator<Person> {
		@Override
		public int compare(Person o1, Person o2) {
			return o1.getName().compareTo(o2.getName());
		}
	}

}
