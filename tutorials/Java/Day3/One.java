package Day3;

class Duster {
	int length;
	int height;
	int width;
	String color;
	
	void setValues() {
		length = 12;
		height = 13;
		width = 3;
		color = "Red";
	}
	
	void setValuesWithParameter(int l, int h, int w, String c) {
		length = l;
		height = h;
		width = w;
		color = c;
	}
}


public class One {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Duster d = new Duster();
		
		d.length = 10;
		d.height = 10;
		d.width = 2;
		d.color = "Black";
		
		System.out.println("length " + d.length);
		System.out.println("Width " + d.width);
		System.out.println("Height " + d.height);
		System.out.println("Color " + d.color);
		
		Duster d2 = new Duster();
		d2.length = 15;
		
		System.out.println(d2.length);
		d2 = d;
		System.out.println(d2.length);
		d.length = 5;
		System.out.println(d2.length);
		
		Duster d3 = new Duster();
		d3.setValues();
		System.out.println("d3 Object");
		System.out.println("length " + d3.length);
		System.out.println("Width " + d3.width);
		System.out.println("Height " + d3.height);
		System.out.println("Color " + d3.color);
		System.out.println();
		
		Duster d4 = new Duster();
		d4.setValuesWithParameter(20, 23, 5, "White");
		System.out.println("d4 Object");
		System.out.println("length " + d4.length);
		System.out.println("Width " + d4.width);
		System.out.println("Height " + d4.height);
		System.out.println("Color " + d4.color);
	}

}
