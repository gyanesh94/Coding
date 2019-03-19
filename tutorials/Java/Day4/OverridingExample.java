package Day4;

class SuperA {
	void behaviousA() {
		System.out.println("This is in Super A");
	}
	
	void behaviourB() {
		System.out.println("This is in Super B");
	}
}

class Child extends SuperA {
	@Override
	void behaviousA() {
		System.out.println("in child behaviour A");
		super.behaviousA();
	}
	
	@Override
	void behaviourB() {
		super.behaviourB();
		System.out.println("in child behaviour B");
	}
}

public class OverridingExample {

	public static void main(String[] args) {
		Child c = new Child();
		
		c.behaviousA();
		c.behaviourB();

	}

}
