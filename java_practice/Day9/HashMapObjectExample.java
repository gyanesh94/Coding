package Day9;

import java.util.HashMap;
import java.util.Map.Entry;

import Day8.Person;

public class HashMapObjectExample {
	public static void main(String[] args) {
		HashMap<Person, Integer> hm = new HashMap<>();
		
		hm.put(new Person("A", 12), 1);
		hm.put(new Person("C", 11), 3);
		hm.put(new Person("B", 20), 2);
		hm.put(new Person("A", 12), 5);
		
		// Duplicacy is checked through hashcode and equals function in person class and it will be sorteed using hashCode
		for (Entry<Person, Integer> e: hm.entrySet()) {
			System.out.println(e.getValue() + "\t" + e.getKey());
		}
	}
}
