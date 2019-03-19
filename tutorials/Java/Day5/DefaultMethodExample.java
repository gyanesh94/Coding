package Day5;

import java.awt.DisplayMode;

interface Default {
	void show();
	default void DisplayMode() {
		System.out.println("Display");
	}
}

class DefaultClass implements Default {
	@Override
	public void show() {
		System.out.println("Show");
	}
	
	
}
public class DefaultMethodExample {

	public static void main(String[] args) {

	}

}
