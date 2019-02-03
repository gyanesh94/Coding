package Day5;

interface Communicate {
	String speak();
	void listen(String chat);
}

class PersonA implements Communicate {
	String chat;
	
	public PersonA(String chat) {
		this.chat = chat;
	}
	
	@Override
	public String speak() {
		return chat;
	}
	
	@Override
	public void listen(String chat) {
		System.out.println("listen: " + chat);
	}
}

class PersonB implements Communicate {
	String chat;
	
	public PersonB(String chat) {
		this.chat = chat;
	}
	
	@Override
	public String speak() {
		return chat;
	}
	
	@Override
	public void listen(String chat) {
		System.out.println("listen: " + chat);
	}
}


public class CommunicatonUSingleInterface {

	public static void main(String[] args) {
		PersonA a = new PersonA("Hello Person B");
		
		PersonB b = new PersonB("Hello Person A");
		
		channel(a, b);
	}

	static void channel(Communicate A, Communicate B) {
		A.listen(B.speak());
	}
}
