package Day6;

class Printer {
	
	// Method 1 Synchronized Method - whole method is synchronized over various thread
//	synchronized static void print(String s) { // Synchronized keyword is used to synchronize the output. It should be used on object doing work. If object is same then they are synchronized. for different object it is not synchronized
										// to synchronize different object make object static
	void print(String s) {
		System.out.print("[");
		try {
			Thread.sleep(1000);
			System.out.print(s);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		System.out.println("]");
	}
}

class Employee implements Runnable {
	Printer p;
	String s;
	
	public Employee(Printer p, String s) {
		this.p = p;
		this.s = s;
		new Thread(this).start();
	}
	
	@Override
	public void run() {
		// Method 2 Synchronized block - the work done in the block on multiple threads are synchronized.
//		synchronized (p) {
//			p.print(s);	
//		}
		
		// If different object of same class is used
//		synchronized (Printer.class) {
//			p.print(s);	
//		}
		
		
		// For Method 1
//		p.print(s);	// Without using static but different objects of Printer will not be synchronized for same object
//		Printer.print(s); // on using static communication done through class. For different object
	}
}

public class SynchronizationExample {
	public static void main(String[] args) {
		Printer p = new Printer();
		
		new Employee(p, "Employee 1");
		new Employee(p, "Employee 2");
		
		Printer p2 = new Printer();
		
		new Employee(p2, "Employee 3");
		new Employee(p2, "Employee 4");
	}
}
