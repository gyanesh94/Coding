package Day3;


class Duster2 {
	int length;
	int height;
	int width;
	
	Duster2() {
		length = 13;
		height = 4;
		width = 10;
	}
	
	Duster2(int length, int height, int width) {
		this.length = length;
		this.height = height;
		this.width = width;
	}
	
	@Override
	protected void finalize() throws Throwable {
		System.out.println("Object no more!!");
		super.finalize();
	}
	
	@Override
	public String toString() {
		System.out.println("this is toString");
		return ("This object has length " + this.length);
//		return super.toString();
	}
}


public class ConstructorExample {

	public static void main(String[] args) {
		Duster2 d = new Duster2();
		
		System.out.println("length " + d.length);
		System.out.println("Width " + d.width);
		System.out.println("Height " + d.height);
		System.out.println();
		
		Duster2 d2 = new Duster2(19, 15, 17);
		
		System.out.println("d2 Object");
		System.out.println("length " + d2.length);
		System.out.println("Width " + d2.width);
		System.out.println("Height " + d2.height);
		
		System.out.println(d2);
		
//		d = null;
//		System.gc();
	}

}
