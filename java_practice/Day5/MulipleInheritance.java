package Day5;

interface Swimming {
	void swim();
}

interface Walking {
	void walk();
}

class Crocodile implements Swimming, Walking {
	
	@Override
	public void walk() {
	}
	
	@Override
	public void swim() {
	}
}

public class MulipleInheritance {

	public static void main(String[] args) {

	}

}
