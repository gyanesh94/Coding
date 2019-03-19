package Day9;


public class GenericsExample {

	public static void main(String[] args) {
		Glass<Coffee> g = new Glass<Coffee>();
		Coffee c = new Coffee();
		g.liquid = c;
		g.liquid.typeOfLiquid();
		
//		Glass<Water> gw = new Glass<>(); 	// Shows error because it doesn't implements SuperLiquidInterface interface and extends SuperLiquidClass
//		Water w = new Water();
//		gw.liquid = w;
//		gw.liquid.typeOfLiquid();
		
		
		// It is syntactically correct but not true. So if we have define number type
//		Cake ck = new Cake();
//		Glass<Cake> gck = new Glass<>();	// Shows error because it doesn't implements Liquid, SuperLiquidInterface interface and extends SuperLiquidClass
//		gck.liquid = ck;
	}

}
