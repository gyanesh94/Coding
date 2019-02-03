package Day9;

public class Coffee extends SuperLiquidClass implements Liquid, SuperLiquidInterFace {

	void typeOfLiquid() {
		System.out.println("Coffee");
	}

	@Override
	public void taste() {
		System.out.println("Coffee taste");
	}
}
