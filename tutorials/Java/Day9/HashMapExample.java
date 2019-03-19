package Day9;

import java.util.Map.Entry;
import java.util.HashMap;

/**
 * 
 * @author gyanesh.m
 * 
 * Map can take null once
 * It will sort key in ascending order
 * Duplicate key will overwrite
 * 
 */
public class HashMapExample {

	public static void main(String[] args) {
		HashMap<Integer, String> hm = new HashMap<>();

		hm.put(1, "One");
		hm.put(3, "Four");
		hm.put(3, "Three");
		hm.put(null, "Five");
		hm.put(2, "Two");

		System.out.println("Using Key");
		for (Integer i: hm.keySet()) {
			System.out.println(hm.get(i) + "\t" + i);
		}
		
		System.out.println("Using Entry");
		for (Entry<Integer, String> e: hm.entrySet()) {
			System.out.println(e.getValue() + "\t" + e.getKey());
		}
	}

}
