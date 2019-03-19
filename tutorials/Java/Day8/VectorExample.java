package Day8;

import java.util.Iterator;
import java.util.ListIterator;
import java.util.Vector;

public class VectorExample {

	public static void main(String[] args) {
		Vector<Person> v = new Vector<>(); // Vectors are synchronized therefore they are slow
		
		v.add(new Person("A", 1));
		v.add(new Person("B", 2));
		v.add(new Person("C", 3));
		v.add(new Person("D", 4));
		v.add(new Person("E", 5));
		
		Iterator<Person> itr;
		itr = v.iterator();
		while (itr.hasNext()) {
			Person temp = itr.next();
			System.out.println(temp.getName() + " " + temp.getAge());
		}
		
		ListIterator<Person> litr = v.listIterator();
		while(litr.hasNext()) {
			System.out.println(litr.next().getName());
			System.out.println(litr.previous().getAge());
			litr.next();
		}
	}

}
