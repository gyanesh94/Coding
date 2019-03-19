package Day4;

interface I {
	void show(); // Every method in interface is converted to public in jvm

	// int a; // Gives error since jvm understands this variable as final so it
	// must be initialized
	int a = 10;
}

interface I2 {
	void display();
	int b = 12;
}

interface I3 extends I { // interface can extend each other but can't implement
	void display();
	int b = 12;
}

class XYZ implements I, I2 {
	@Override
	public void show() {
//		a += a; // Error because 'a' variable is considered final
		
		System.out.println("show() " + I.a); // I.a shows that 'a' var is made static by jvm
 	}
	
	@Override
	public void display() {
		System.out.println("display " + b);
		System.out.println("show() " + I.a);
	}
}

public class InterfaceExample {

	public static void main(String[] args) {
		XYZ x = new XYZ();
		x.show();
		x.display();
		
		I i = new XYZ();
		i.show();
	}

}
