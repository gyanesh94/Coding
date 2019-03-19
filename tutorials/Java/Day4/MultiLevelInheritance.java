package Day4;


class A {
	int a;
	
	void printA() {
		System.out.println(a);
	}
}

class B extends A {
	int b;
	
	void printB() {
		System.out.println(b);
	}
}

class C extends B {
	int c;
	
	void printC() {
		System.out.println(c);
	}
}


public class MultiLevelInheritance {
	public static void main(String[] args) {
		C c = new C();
		c.a = 10;
		c.b = 12;
		c.c = 14;
		
		c.printA();
		c.printB();
		c.printC();
	}
}
