package Day7;

public enum EnumExample {

	//	enum ENUM{A, B, C};

	LAPTOP(1234, 1000), MOBILE(3242, 10000), TV(2341, 40000);

	int model;
	int value;
	
	static {
		System.out.println("Initializer");
	}

	EnumExample(int model, int value) {
		System.out.println("In Constructor");
		this.model = model;
		this.value = value;
	}

	public static void main(String[] args) {
		System.out.println("in Main");
		
		//		for(ENUM e: ENUM.values()) {
		//			System.out.println(e.ordinal() + "\t" + e + "\t" + e.name());
		//		}

		for (EnumExample e: EnumExample.values()) {
			System.out.println(e.ordinal() + "\t" + e + "\t" + e.name() + "\t" + e.model + "\t" + e.value);
		}
		
		System.out.println("Main Last");
	}

}
