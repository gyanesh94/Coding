package Day6;

class Q {
	int i;
	boolean isProduced;

	public Q() {
		isProduced = false;
	}

	synchronized int consuume() {
		if (!isProduced) {
			try {
				wait();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		isProduced = false;
		System.out.println("Consuming " + i);
		notify();
		return i;
	}

	synchronized void produce(int i) {
		if (isProduced) {
			try {
				wait();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		this.i = i;
		isProduced = true;
		System.out.println("Producing " + i);
		notify();
	}
}

class Producer implements Runnable {
	Q q;

	public Producer(Q q) {
		this.q = q;
		new Thread(this, "Producer").start();
	}

	@Override
	public void run() {
		int i = 0;
		while (true) {
			q.produce(i++);
		}
	}
}

class Consumer implements Runnable {
	Q q;

	public Consumer(Q q) {
		this.q = q;
		new Thread(this, "Consumer").start();
	}

	@Override
	public void run() {
		while (true) {
			q.consuume();
		}
	}
}

public class ProducerConsumerProblem {

	public static void main(String[] args) {
		Q q = new Q();
		new Producer(q);
		new Consumer(q);
	}

}
