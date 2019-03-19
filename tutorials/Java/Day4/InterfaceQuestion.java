package Day4;

interface IOne {
	int i1 = 1;
	void showI1();
}

interface ITwo {
	int i2 = 2;
	void showI2();
}

class SuperClass {
	int s;
	
	void display() {
		System.out.println("Super Class");
	}
}

class ChildClass extends SuperClass implements IOne, ITwo {
	@Override
	public void showI1() {
		System.out.println("Show I1 " + i1);
	}
	
	@Override
	public void showI2() {
		System.out.println("Show I2 " + i2);
	}
	
	@Override
	void display() {
		super.display();
		System.out.println("Super Display in Child Class " + super.s);
		System.out.println("Show I1 " + IOne.i1);
		System.out.println("Show I2 " + ITwo.i2);
	}
	
}

public class InterfaceQuestion {

	public static void main(String[] args) {
		ChildClass c = new ChildClass();
		c.s = 8;
		c.showI1();
		c.showI2();
		c.display();
	}

}
