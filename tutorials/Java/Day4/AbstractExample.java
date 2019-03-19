package Day4;

abstract class Abst {
	abstract void show();
	int a;
	
	void display() {
		System.out.println("This is defined!");
	}
}

final class Another {		// final keyword class can't be extended
	int a;
	void show() {
		System.out.println("Another Class");
	}
}

class AbstChild extends Abst {

	@Override
	void show() {
		System.out.println("Abstraction Exammple");
		a = 10;
		System.out.println(a);
	}
	
}

public class AbstractExample {

	public static void main(String[] args) {
		AbstChild a = new AbstChild();
		
		a.show();
		a.display(); 
	}

}
