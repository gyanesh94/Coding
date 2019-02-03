package Day3;


class Static {
	static int a;
	int b;
	
	public Static() {
		this.b = 0;
	}
	
	void show() {
		System.out.println(a + " show " + b);		// non-static can access both types
	}
	
	static void staticShow() {						// Static method can access static things only. To call non-static create obj
		System.out.println(a + " staticShow");
		Static obj = new Static();
		System.out.println(a + " static calling non-static " + obj.b);
	}
	
	void increment() {
		a++;
		b++;
	}
}


public class StaticExample {

	public static void main(String[] args) {
		System.out.println(Static.a);
		
		Static.staticShow();
		
		Static s = new Static();
		s.show();
		System.out.println(s.b);

		Static f = new Static();
		s.increment();
		f.increment();
		s.show();
		f.show();
	}

}
