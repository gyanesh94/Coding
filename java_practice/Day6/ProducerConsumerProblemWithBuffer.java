package Day6;

class QWithBuffer {
	int[] arr;
	static int buffer;
	static int currentCount;
	static int minCount;

	public QWithBuffer(int buffer) {
		QWithBuffer.buffer = buffer;
		arr = new int[buffer + 1];
		currentCount = 0;
		minCount = 1;
	}

	synchronized int consume() {
		if (currentCount <= minCount) {
			try {
				wait();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		int i = arr[currentCount--];
		currentCount--;
		System.out.println("Consuming " + i);
		notify();
		return i;
	}

	synchronized void produce(int i) {
		if (currentCount >= buffer) {
			try {
				wait();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		this.arr[++currentCount] = i;
		System.out.println("Producing " + i);
		notify();
	}
}

class ProducerWithBuffer implements Runnable {
	QWithBuffer q;

	public ProducerWithBuffer(QWithBuffer q) {
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

class ConsumerWithBuffer implements Runnable {
	QWithBuffer q;

	public ConsumerWithBuffer(QWithBuffer q) {
		this.q = q;
		new Thread(this, "Consumer").start();
	}

	@Override
	public void run() {
		while (true) {
			q.consume();
		}
	}
}

public class ProducerConsumerProblemWithBuffer {

	public static void main(String[] args) {
		QWithBuffer q = new QWithBuffer(5);
		new ProducerWithBuffer(q);
		new ConsumerWithBuffer(q);
	}

}
