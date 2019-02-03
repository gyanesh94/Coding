package Day8;

import java.util.ArrayList;
import java.util.Iterator;

public class ArrayListWithObjectExample {

	public static void main(String[] args) {
		ArrayList<Person> a1 = new ArrayList<>();
		a1.add(new Person("A", 10));
		a1.add(new Person("B", 13));
		a1.add(new Person("C", 40));
		a1.add(new Person("D", 38));
		a1.add(new Person("E", 5));

		Iterator<Person> itr;
		itr = a1.iterator();
		while (itr.hasNext()) {
			Person temp = itr.next();
			System.out.println(temp.getName() + " " + temp.getAge());
		}
		
		System.out.println();
		System.out.println("Remove");
		a1.remove(new Person("B", 13));	// Here person is not removed (If equals function is not override). Because arrayList stores address of the object but
											// on removing we create new object which will have different address so it will not be removed.
											// So we to make something so that it checks internal content. "equals" class has been override with our own function
											// This is because remove is used it will check for equals function of the type of object/variable passed as parameter (in this case its "object" which checks
											// object address by default. So to check for equals so we have to override function "object passed in parameter" to check for equality of internal values)
		itr = a1.iterator();
		while (itr.hasNext()) {
			Person temp = itr.next();
			System.out.println(temp.getName() + " " + temp.getAge());
		}
		
		
		System.out.println();
		System.out.println("Proofs Passed Parameter Object is called");
		a1.remove(new Animal("C", 40));	
		itr = a1.iterator();
		while (itr.hasNext()) {
			Person temp = itr.next();
			System.out.println(temp.getName() + " " + temp.getAge());
		}
	}

}
