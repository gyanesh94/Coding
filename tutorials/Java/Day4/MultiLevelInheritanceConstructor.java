package Day4;

import java.applet.Applet;

class Fruit {
	String taste;
	String color;
	
	public Fruit(String taste, String color) {
		this.taste = taste;
		this.color = color;
	}
	
	String getTaste() {
		return taste;
	}
	
	String getColor() {
		return color;
	}
}

class Apple extends Fruit {
	int price;
	
	public Apple(String taste, String color, int price) {
		super(taste, color);
		this.price = price;
	}
	
	int getPrice() {
		return price;
	}
}

class KashmiriApple extends Apple {
	String location;
	
	public KashmiriApple(String location, String taste, String color, int price) {
		super(taste, color, price);
		this.location = location;
	}
}

public class MultiLevelInheritanceConstructor {

	public static void main(String[] args) {
		Apple a = new Apple("SourNSweet", "Red", 100);
		
		System.out.println(a.taste);
		System.out.println(a.color);
		System.out.println(a.price);
	}

}
