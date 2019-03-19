package Day6;

class TaskA implements Runnable {
	public TaskA() {
	}

	@Override
	public void run() {
		int i = 0;
		while (++i < 10) {
			try {
				Thread.sleep(500);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			System.out.println("Print in TaskA " + i + " " + Thread.currentThread().getName());
		}
	}
}

class TaskB implements Runnable {
	public TaskB() {
	}

	@Override
	public void run() {
		int i = 50;
		while (--i > 0) {
			System.out.println("Print in TaskB " + i + " " + Thread.currentThread().getName());
		}
	}
}

public class MultiThreadExample {

	public static void main(String[] args) {
//		try {	// It will cause deadlock since it will tell that main should be complete before executing other statement but main contains two thread which needs to be executed but they will not be able to execute
//			Thread.currentThread().join();
//		} catch (InterruptedException e1) {
//			e1.printStackTrace();
//		}
		
		TaskA a = new TaskA();
		TaskB b = new TaskB();
		
		Thread t = new Thread(a);
		Thread t2 = new Thread(b);
		
		// Both start ad setName order in 2 thread are same. As even if setName is written after start() it is same because start() doesn't mean it will start exactly at that moment 
		t.start();
		t.setName("Thread A");
		t2.setName("Thread B");
		t2.start();
		
		try {
			t.join();	// Join thread to main thread
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		
//		try { // This will also cause deadlock. Why??????
//			Thread.currentThread().join();
//		} catch (InterruptedException e1) {
//			e1.printStackTrace();
//		}

		
		int i  = 0;
		while (i++ < 15) {
			System.out.println("Main " + i + " " + Thread.currentThread().getName());
		}
	}

}
