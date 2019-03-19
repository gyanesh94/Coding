package Day8;

import java.util.HashSet;
import java.util.Iterator;

public class HashSetObjectExample {

	public static void main(String[] args) {
		HashSet<Person> p = new HashSet<>();		// HashSet uses hashCode function to create hashCode for each objects of class and 
														// compares them. When hashCode matches of two objects then equals function of class will be called to match them equal

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

}
