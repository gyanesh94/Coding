package Day9;

public class GenericsMixerExample {
	public static void main(String[] args) {
		Juicer j = new Juicer();
		Coffee c = new Coffee();
		Water w = new Water();
		Mixer m = new Mixer();
		m.mix(w,j);		// It allows to take Juice since we didn't mentioned type
//		m.<Coffee, Water> mix(j, w);	// It shows error because we have defined the type of object it must take therefore enhancing type safety
		m.<Coffee, Water> mix(c, w);
	}
}
