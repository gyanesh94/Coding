package Day9;

public class Mixer {
	
	<T extends Liquid, V> void mix(T liquid, V anotherLiquid) {
		System.out.println(liquid + "\t" + anotherLiquid);
		liquid.taste();			// Taste() is found because we have told T extends Liquid which defines it will always have taste function
//		anotherLiquid.taste(); // It shows error because V is general and no taste() is defined there.
	}
}
