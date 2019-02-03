package Day9;

public class Water implements Liquid {
	
	void typeOfLiquid() {
		System.out.println("Water");
	}
	
	@Override
	public void taste() {
		System.out.println("Water taste");
	}
}
