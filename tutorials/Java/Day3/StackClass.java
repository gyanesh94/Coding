package Day3;

class stack {
	
	private int[] st;
	private int top;
	private int size;
	
	public stack(int size) {
		this.size = size;
		st = new int[size];
		top = -1;
	}
	
	public int pop() {
		if (top == -1) {
			System.out.println("No element in stack");
			return -1;
		}
		int topElement = st[top--];
		
		return topElement;
	}
	
	public void push(int element) {
		if (top == size - 1) {
			System.out.println("Stack is full");
		} else {
			st[++top] = element;
		}
	}
	
	public boolean isEmpty() {
		if (top == -1) {
			return true;
		} else {
			return false;
		}
	}
}

public class StackClass {

	public static void main(String[] args) {
		stack s = new stack(4);
		System.out.println("isEmpty= " + s.isEmpty());
		System.out.println("Push Element 6");
		s.push(6);
		System.out.println("Push Element 10");
		s.push(10);
		System.out.println("Pop Element= " + s.pop());
		System.out.println("Push Element 14");
		s.push(14);
		System.out.println("isEmpty= " + s.isEmpty());
		System.out.println("Push Element 124");
		s.push(124);
		System.out.println("Push Element 25");
		s.push(25);
		System.out.println("Pop Element= " + s.pop());
		System.out.println("Pop Element= " + s.pop());
		System.out.println("Pop Element= " + s.pop());
		System.out.println("Pop Element= " + s.pop());
		System.out.println("Pop Element= " + s.pop());
		System.out.println("isEmpty= " + s.isEmpty());
		
	}

}
