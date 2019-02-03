package Day8;

//public class Person implements Comparable<Person> {
	public class Person {
	private String name;
	private int age;

	public Person(String name, int age) {
		this.setAge(age);
		this.setName(name);
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getAge() {
		return age;
	}

	public void setAge(int age) {
		this.age = age;
	}
	
	@Override
	public int hashCode() {
		System.out.println("HashCode");
		return (this.name + this.age).hashCode();  // String make its own hashCode function. Convert string to int hash
	}

	
	// This is done to remove object from arrayList using remove function
	@Override
	public boolean equals(Object obj) {
		System.out.println("Person");
		if (obj != null && obj instanceof Person) {
			Person person = (Person) obj;
			if (this.name.equals(person.name) && this.age == person.age) {		// "this" represent object passed in remove parameter and "obj" represent ArrayList data
				return true;
			}
		}
		return false;
	}
	
	@Override
	public String toString() {
		return ("Name: " + this.name + "\tAge: " + this.age);
		
	}

	
	// Comparable Interface Example
//	@Override
//	public int compareTo(Person o) {
//		// for Age
//		if (this.age > o.age) {
//			return 1;
//		} else if (this.age < o.age) {
//			return -1;
//		} else {
//			return 0;
//		}
//		
//		// for name
////		return this.name.compareTo(o.name);
//		
//	}
}
