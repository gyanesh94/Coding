package Day3;

class Area {
	int a;
	
	Area() {
		a = 10;
	}
	
	Area(int a) {
		this.a = a;
	}
	
	Area(int a, int b) {
		this.a = a + b;
	}
	
	void compareObject(Area obj) {
		System.out.println(obj.a);
	}
	
	void changeValues(int i, int j) {
		i += i;
		j += j;
		System.out.println("Changed i & j: " + i + " & " + j);
	}
	
	void changeValues(Area obj) {
		obj.a += obj.a;
		System.out.println("Changed obj: " + obj.a);
	}
}


public class OverloadingExample {

	public static void main(String[] args) {
//		show(1);
//		show(2l);
		
		Area a = new Area(10);
		Area b = new Area(15);
		
//		a.compareObject(b);
		
		int i = 10, j = 15;
		
		a.changeValues(i, j);
		System.out.println("Main i & j: " + i + " & " + j);
		a.changeValues(b);
		System.out.println("Main obj: " + b.a);
	}
	
	static void show() {
		System.out.println("Show 1");
	}
	
	static void show(int a) {
		System.out.println("Show int: " + a);
	}
	
	static int show(long b) {
		System.out.println("Show long: " + b);
		return 1;
	}

}
