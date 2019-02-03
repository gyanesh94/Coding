package Day3;

/*
 * Used to create singleton class with some restriction like number of objects of class to be 1. It is base for creating Singleton class
*/

class PClass {
	static private PClass singleInstance = new PClass();
	
	private PClass() {
		
	}
	
	static PClass returnObj() {
		return new PClass();
	}
	
	static PClass returnObj2() {		// It will restrict single instance of object
		return singleInstance;
	}
}

public class PrivateConstructorExample {
	public static void main() {
//		PClass pClass = new PClass(); 		// Gives error as constructor is private
		
		PClass p = PClass.returnObj();
	}
}
