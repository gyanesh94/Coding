package Day8;

import java.util.ArrayList;
import java.util.Iterator;

public class ArrayListExample {

	public static void main(String[] args) {
		ArrayList<String> a1 = new ArrayList<>();
		
		a1.add("One");
		a1.add("Two");
		a1.add("Three");
		a1.add("Four");
		a1.add("One");
		a1.add("Two");
		a1.add("Three");
		
		
		System.out.println();
		System.out.println("Using Foreach");
		for(String s: a1) {
			System.out.println(s);
		}
		
		
		System.out.println();
		System.out.println("Using For");
		int size = a1.size();
		for (int i = 0; i < size; i++) {
			System.out.println(a1.get(i));
		}
		
		
		System.out.println();
		System.out.println("Using Iterator");
		
		Iterator<String> itr = a1.iterator();
		while(itr.hasNext()){
			System.out.println(itr.next());
		}
		
		System.out.println();
		System.out.println("Specials for collections");
		a1.forEach(temp -> {
			System.out.println(temp);
		});
	}

}
