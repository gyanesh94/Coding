package Day4;

class NoStudy {
	boolean currentWorking;
	int time;
	
	public NoStudy(boolean currentWorking, int time) {
		this.time = time;
		this.currentWorking = currentWorking;
	}
	
	void supermethod() {
		System.out.println("Super Method");
	}
}

class Neo2 extends NoStudy {
	boolean currentWorking;
	int time;
	
	public Neo2(boolean currentWorking, int time) {
		super(true, 10);
		this.time = time;
		this.currentWorking = currentWorking;
		supermethod();
		super.supermethod();
	}
	
	boolean areWeStudying() {
		System.out.println("studying at " + time);
		System.out.println("is super studying " + super.currentWorking);
		System.out.println("super is studying at " + super.time);
		return currentWorking;
	}
}

public class SuperExample {

	public static void main(String[] args) {
		Neo2 n  = new Neo2(false, -123123);
		System.out.println(n.areWeStudying());
	}

}
