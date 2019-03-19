package Day4;

class Bottle {
	int volume;
	String brand;
	
	int getVolume() {
		return volume;
	}
	
	String getBrand() {
		return brand;
	}
	
	void setValues(int volume, String brand) {
		this.volume = volume;
		this.brand = brand;
	}
}

class WaterBottle extends Bottle {
	String liquidType;
	
	String getLiquidType() {
		return liquidType;
	}
	
	void initBottleValyes(String liquidType) {
		this.liquidType = liquidType;
	}
}

public class InheritanceExample {

	public static void main(String[] args) {
		
		WaterBottle wb = new WaterBottle();
		
//		wb.volume = 100;
//		wb.brand = "Aquafina";
//		wb.liquidType = "Water";
		
		wb.setValues(100, "Aquafina");
		wb.initBottleValyes("Water");
		
		System.out.println(wb.getBrand());
		System.out.println(wb.getVolume());
		System.out.println(wb.getLiquidType());

	}

}
