package Day6;

class TaskC implements Runnable {
	public TaskC() {
	}

	@Override
	public void run() {
		int i = 0;
		while (++i < 10) {
			System.out.println("Print in TaskC " + i + " " + Thread.currentThread().getName());
		}
	}
}

public class AliveJoinExample {
	public static void main(String[] args) {
		TaskC c = new TaskC();
		Thread t = new Thread(c);

		System.out.println("Before Start of Thread");

		t.start();

		// Method 1
		try {
			t.join();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		System.out.println("After Thread Join");
		
		// Method 2
//		boolean flag = true;
//		while (flag) {
//			if (!t.isAlive()) {
//				System.out.println("After Thread Alive");
//				flag = false;
//			}
//		}
		
		System.out.println("Final");

	}
}
