package Day6;

class TaskPriority implements Runnable {
	static boolean b;
	int i;
	Thread t;

	public TaskPriority() {
	}

	@Override
	public void run() {
		while (b) {
			i++;
		}
	}

	void startThread(int p) {
		b = true;
		i = 0;
		t = new Thread(this);
		t.setPriority(p);
		t.start();
	}

	@SuppressWarnings("deprecation")
	void stopThread() {
		b = false;
		t.stop();
		System.out.println("Value of I " + i + " with priority " + t.getPriority());
	}
}

public class ThreadPriorityExample {

	public static void main(String[] args) {
		TaskPriority p = new TaskPriority();
		p.startThread(Thread.MAX_PRIORITY);	// To inc write as Thread.NORM_PRIORITY + 4. Max is 10
		TaskPriority p2 = new TaskPriority();
		p2.startThread(Thread.MIN_PRIORITY);
		
		try {
			Thread.sleep(1000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		
		p.stopThread();
		p2.stopThread();
	}

}
