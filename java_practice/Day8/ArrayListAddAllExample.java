package Day8;

import java.util.ArrayList;
import java.util.Iterator;

public class ArrayListAddAllExample {
	public static void main(String[] args) {
		ArrayList<String> a1 = new ArrayList<>();
		
		a1.add("One");
		
		ArrayList<String> cal = new ArrayList<>();
		cal.add("Two");
		cal.add("Three");
		a1.addAll(cal);
		a1.add("Four");
		a1.add("Five");
		
		Iterator<String> itr;
		
		System.out.println();
		System.out.println("Add all Example");
		itr = a1.iterator();
		while(itr.hasNext()){
			System.out.println(itr.next());
		}
		
		System.out.println();
		System.out.println("Remove using index");
		a1.remove(3);
		itr = a1.iterator();
		while(itr.hasNext()){
			System.out.println(itr.next());
		}
		
		System.out.println();
		System.out.println("Remove using Object means value");
		a1.remove("Five");
		itr = a1.iterator();
		while(itr.hasNext()){
			System.out.println(itr.next());
		}
		
		System.out.println();
		System.out.println("Remove All Example");
		a1.removeAll(cal);
		itr = a1.iterator();
		while(itr.hasNext()){
			System.out.println(itr.next());
		}
		
	}
}
