package Day6;

class AThread extends Thread { // Thread is a class so no other class can be extended
	public AThread() { // Always run on main threads

	}

	@Override
	public void run() { // it runs on different thread
		super.run();
		int i = 0;
		while (++i < 10) {
			System.out.println("Print in run " + i + " " + Thread.currentThread().getName());

		}
	}

	@Override
	public synchronized void start() { // it also run on main thread
		super.start(); // If it is commented run method will not run

//		run(); // If super is commented and this line is executed then run will be executed sequentially on Main Thread

	}
}

public class ThreadUsingClassExample {

	public static void main(String[] args) {
		// To change main thread name
		Thread curr = Thread.currentThread();
		curr.setName("Initial Thread");

		AThread aThread = new AThread();
		aThread.setName("New Thread"); // To change thread name
		aThread.start();

		int i = 0;
		while (++i < 10) {
			System.out.println("Print in Main " + i + " " + Thread.currentThread().getName());

		}
		
//		aThread.start(); // it gives error. start() can't be used again. This implies thread terminates after running
	}

}
