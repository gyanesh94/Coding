package Day6;

class BThread implements Runnable { // Runnable is interface which execute task not thread. Since it is a interface other classes can be extended. Since it is task a worker is required to run it as thread

	public BThread() {
//		Thread t = new Thread(this);
//		t.start();
	}
	
	@Override
	public void run() { // It is a task not thread
		int i = 0;
		while (++i < 10) {
			System.out.println("Print in run " + i + " " + Thread.currentThread().getName());
		}
	}
	
}

public class ThreadUsingInterfaceExample {

	public static void main(String[] args) {
//		new BThread();
		
		Thread t = new Thread(new BThread());
		t.start();
		
		Thread t2 = new Thread(new BThread());
		t2.start();
		
		BThread bThread = new BThread();
		Thread t3 = new Thread(bThread);
		t3.start();
		
		Thread t4 = new Thread(bThread);
		t4.start();
	}
}
