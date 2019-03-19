package Day5;

interface Anonymous { // Contract to make anonymous class
	void display();
}

class Outer {
	int a;

	void display() {
		// System.out.println(b); // Gives Error Since Inner class var is not
		// shown to Outer class
		Inner i = new Inner(12);
		System.out.println(i.b);
	}

	public Outer(int a) {
		this.a = a;
	}

	class Inner {
		int b;

		public Inner(int b) {
			this.b = b;

		}

		void show() {
			System.out.println(a);
		}
	}

	static class Inner1 {
		int b;

		void show() {
			System.out.println("Inner Accesss");
		}
	}

}

public class InnerClassExample {

	public static void main(String[] args) {
		Outer o = new Outer(10);
		Outer.Inner i = o.new Inner(23);

		System.out.println(i.b);

		// Outer.Inner1 i1 = o.new Inner1(); // It gives error since Inner1 is
		// static

		Outer.Inner1 i1 = new Outer.Inner1();
		i1.show();

		Method();
	}

	static void Method() {
		class LocalInner {
			int a;

			void show() {
				System.out.println("A big Show!");
			}
		}

		LocalInner li = new LocalInner();
		li.show();

		Anonymous a = new Anonymous() { // Example for anonymous class

			@Override
			public void display() {
				System.out.println("Anonymous Class");
			}
		};

		a.display();
		
		CalledUsingInnerArg(new Anonymous() {
			
			@Override
			public void display() {
				System.out.println("Called Using Inner Arg Anonymous");
			}
		});
	}

	static void CalledUsingInnerArg(Anonymous e) {
		e.display();
	}

}
