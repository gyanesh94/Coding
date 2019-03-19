package Day5;

import java.util.InputMismatchException;
import java.util.Scanner;

/**
 * 
 * @author gyanesh.m Class which handles exception and maintains count a
 *         particular exception is handled
 * 
 */
@SuppressWarnings("serial")
class AtmException extends Exception {
	private int count;
	private int maxRetries;
	private String message;

	public AtmException(String message) {
		this.message = message;
		this.count = 0;
		this.maxRetries = 1;
	}

	public AtmException(String message, int maxRetries) {
		this.message = message;
		this.maxRetries = maxRetries;
		this.count = 0;
	}

	String getExceptionMessage() {
		count++;
		return message;
	}

	void resetCount() {
		count = 0;
	}

	boolean checkRetriesExceeded() {
		return count < maxRetries;
	}
}

class Atm {
	final static private int cardNumber = 123;
	final static private int pinNumber = 123;
	private int contactNumber = 123124;
	static private int totalAmount;

	private Atm() {
	}

	static Atm validateCardAndPin(int cardNumber, int pinNumber, AtmException cardValidationException) throws AtmException {
		if (Atm.cardNumber == cardNumber && Atm.pinNumber == pinNumber) {
			Atm atm = new Atm();
			return atm;
		} else {
			throw cardValidationException;
		}
	}

	void withdrawAmount(int amount) throws AtmException {
		if (amount < Atm.totalAmount) {
			Atm.totalAmount -= amount;
			System.out.println(amount + " is withdrawn. Remaining amount is " + Atm.totalAmount);
		} else {
			throw new AtmException("WithDraw amount exceeded total amount");
		}
	}

	boolean depositAmount() {
		int retries = 3;

		while (retries > 0) {
			System.out.print("Enter Amount to be deposited (min amount 1): ");
			int amount = AtmQuestion.getValidInput();
			if (amount <= 0) {
				System.out.println("Enter Valid Amount");
			} else {
				deposit(amount);
				return true;
			}
			retries--;
		}
		System.out.println("Maximum retries for depositing amount is exceeded!!");
		return false;
	}

	private void deposit(int amount) {
		totalAmount += amount;
		System.out.println("Current Balance " + totalAmount);
	}

	void balanceCheck() {
		System.out.println("Total Amount is " + totalAmount);
	}

	void contactUs() {
		System.out.println(contactNumber);
	}
}

public class AtmQuestion {

	public static void main(String[] args) {
		AtmException cardValidationException = new AtmException("Invalid Card Number or Pin", 3);
		Atm atm = null;

		while (cardValidationException.checkRetriesExceeded()) {
			System.out.print("Enter Card Number: ");
			int cardNumber = getValidInput();
			System.out.print("Enter Pin: ");
			int pin = getValidInput();
			try {
				atm = Atm.validateCardAndPin(cardNumber, pin, cardValidationException);
				break;
			} catch (AtmException e) {
				System.out.println(e.getExceptionMessage());
			}
		}
		if (!cardValidationException.checkRetriesExceeded()) {
			System.out.println("Maximum retries exceeded");
			return;
		}
		System.out.println("Welcome!!");

		AtmException choiceValidation = new AtmException("Print Valid Input", 3);
		giveChoice(atm, choiceValidation);
		System.out.println("Session Ended");
		if (scanner != null) {
			scanner.close();
		}
	}

	private static Scanner scanner;

	static int getValidInput() {
		if (scanner == null) {
			scanner = new Scanner(System.in);
		}
		try {
			int temp = scanner.nextInt();
			return temp;
		} catch (InputMismatchException e) {
			scanner.nextLine();
			return -1;
		}
	}

	static void giveChoice(Atm atm, AtmException choiceValidation) {

		System.out.println("Choose any below options");
		System.out.println("1. Withdraw");
		System.out.println("2. Balance Check");
		System.out.println("3. Deposit");
		System.out.println("4. Contact Us");
		System.out.println("5. Exit");

		int choice = getValidInput();

		switch (choice) {
		case 1:
			AtmException invalidAmountException = new AtmException("Invalid Amount", 3);
			int amount = 0;
			while (invalidAmountException.checkRetriesExceeded()) {
				try {
					System.out.print("Enter amount to be withdrawn= ");
					amount = getValidInput();
					if (amount < 1) {
						throw invalidAmountException;
					}
					break;
				} catch (AtmException e) {
					System.out.println(e.getExceptionMessage());
				}
			}
			if (invalidAmountException.checkRetriesExceeded()) {
				try {
					atm.withdrawAmount(amount);
					giveChoice(atm, choiceValidation);
				} catch (AtmException e) {
					System.out.println(e.getExceptionMessage());
					System.out.println("To deposit more amount press 1 else 2 to quit");
					int depositChoice = getValidInput();
					if (depositChoice == 1) {
						if (atm.depositAmount()) {
							giveChoice(atm, choiceValidation);
						}
					}
				}
			} else {
				System.out.println("Maximum Retries are over. Login again to Use");
			}
			break;
		case 2:
			choiceValidation.resetCount();
			atm.balanceCheck();
			giveChoice(atm, choiceValidation);
			break;
		case 3:
			choiceValidation.resetCount();
			if (atm.depositAmount()) {
				giveChoice(atm, choiceValidation);
			}
			break;
		case 4:
			atm.contactUs();
			break;
		case 5:
			break;
		default:
			if (choiceValidation.checkRetriesExceeded()) {
				System.out.println(choiceValidation.getExceptionMessage());
				giveChoice(atm, choiceValidation);
			} else {
				System.out.println("Maximum Retries are over. Login again to Use");
			}
			break;
		}
	}

}
