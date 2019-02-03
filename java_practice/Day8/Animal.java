package Day8;

public class Animal {
	private String name;
	private int age;

	public Animal(String name, int age) {
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

	
	// This is done to remove object from arrayList using remove function
	@Override
	public boolean equals(Object obj) {
		System.out.println("Animal");
		if (obj != null && obj instanceof Animal) {
			Animal person = (Animal) obj;
			if (this.name.equals(person.name) && this.age == person.age) {		// "this" represent object passed in remove parameter and "obj" represent ArrayList data
				return true;
			}
		}
		return false;
	}
}
