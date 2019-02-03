package Day5;

class CustomizeException extends Exception {
	String s;
	
	public CustomizeException(String s) {
		this.s = s;
	}
	
	String whatIsException() {
		return s;
	}
}

class Bank {
	static int amount;
	
	public Bank() {
	
	}
	
	void deposit(int amount){
		Bank.amount += amount;
		System.out.println("Your Balance is " + Bank.amount);
	}
	
	void withDraw(int amount) {
		if (amount < Bank.amount) {
			Bank.amount -= amount;
			System.out.println("Withdraw is Successful");
		} else {
			try {
				throw new CustomizeException("Sorry! insufficient Balance!!");
			} catch (CustomizeException e) {
				System.out.println(e.whatIsException());
			}	
		}
	}
}

public class CustomiedExceptionExample {

	public static void main(String[] args) {
		
		Bank b = new Bank();
		
		b.deposit(10000);
		b.withDraw(9000);
		b.deposit(4000);
		b.withDraw(6000);
		
		System.out.println("Transaction Completed");
	}

}
