package Day6;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

class TaskPool implements Runnable {
	@Override
	public void run() {
		System.out.println(Thread.currentThread().getName());
	}
}

public class ThreadPoolExample {

	public static void main(String[] args) {
		ExecutorService exec = Executors.newFixedThreadPool(5);

		for (int i = 0; i < 10; i++) {
			exec.execute(new TaskPool());
		}
	}

}
