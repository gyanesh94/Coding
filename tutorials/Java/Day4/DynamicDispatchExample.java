package Day4;

class One {
	int num = 10;
	
	void show() {
		System.out.println(num);
	}
}


class Alpha extends One {
	int s = 11;
	
	void show() {
		System.out.println(s);
	}
	
	void show1() {
		System.out.println(s);
	}
}


class Beta extends One {
	int l = 12;
	
	void show() {
		System.out.println(l);
	}
	
	void show1() {
		System.out.println(l);
	}
}

public class DynamicDispatchExample {

	public static void main(String[] args) {
		One o;
		Alpha a = new Alpha();
		Beta b = new Beta();
		
		o = a;
		o.show();
//		o.show1();	Show error because it is not present in parent class 
		
		o = b;
		o.show();
//		o.show1();	Show error because it is not present in parent class

	}

}
