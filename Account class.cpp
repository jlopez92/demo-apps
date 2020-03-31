#include<iostream>
#include<string>
using namespace std;

//create an Account class
class Account {
private:
	int id;
	double balance;
	double AnnualInterestRate;

public:
	//no argument constructor
	Account() {
		id = 0;
		balance = 0;
		AnnualInterestRate = 0;
	}

	//three argument constructor
	Account(int _id, double _balance, double _AnnualInterestRate) {
		setId(_id);
		setBalance(_balance);
		setAnnualInterestRate(_AnnualInterestRate);

	}

	//returns the id of the account
	int getId() {
		return id;
	}

	//returns the balance of the account
	double getBalance() {
		return balance;
	}

	//returns annual interest rate of the account
	double getAnnualInterestRate() {
		return AnnualInterestRate;
	}

	//sets id
	void setId(int _id) {
		id = _id;
	}

	//sets balance
	void setBalance(double _balance) {
		balance = _balance;
	}

	//sets interest rate
	void setAnnualInterestRate(double _AnnualInterestRate) {
		AnnualInterestRate = _AnnualInterestRate;
	}

	//finds the monthly interest rate
	double getMonthlyInterestRate() {
		return AnnualInterestRate / 12.0;
	}

	//finds the monthly interest
	double getMonthlyInterest() {
		return balance * getMonthlyInterestRate();
	}

	//function to withdraw from account, error checks for enough funds
	void withdraw(double amount) {
		if (amount < balance) {
			balance = balance - amount;
		}
		else {
			cout << "Insufficient funds!\n" << endl;
		}
	}

	//function to deposit money into account
	void deposit(double amount) {
		balance = balance + amount;
	}

};

int main() {

	//create an account with no arguments
	Account person1;

	//displays account 1 info
	cout << "Creating default account object." << endl;
	cout << "details for account 0" << endl;
	cout << "ID: " << person1.getId() << endl;
	cout << "Balance: " << person1.getBalance() << endl;
	cout << "Annual Interest Rate: " << person1.getAnnualInterestRate() << endl;
	cout << "Monthly Interest Rate: " << person1.getMonthlyInterestRate() << endl;
	cout << "Monthly Interest: " << person1.getMonthlyInterest() << endl << endl;

	//user created account
	int id;
	double balance, AnnualInterestRate;
	cout << "You will create the next Account object..." << endl;
	cout << "Enter id: ";
	cin >> id;

	cout << "Enter balance: ";
	cin >> balance;

	cout << "Enter annual interest rate: ";
	cin >> AnnualInterestRate;

	Account person2(id, balance, AnnualInterestRate);

	cout << "\nDetails for your account..." << endl << endl;
	cout << "ID: " << person2.getId() << endl;
	cout << "Balance: " << person2.getBalance() << endl;
	cout << "Annual Interest Rate: " << person2.getAnnualInterestRate() << endl;
	cout << "Monthly Interest Rate: " << person2.getMonthlyInterestRate() << endl;
	cout << "Monthly Interest: " << person2.getMonthlyInterest() << endl;

	//deposit 500 into account
	cout << "\nDepositing $500 into bank account...\n" << endl;
	person2.deposit(500);

	//attempt to overwithdraw
	cout << "Attempting to withdraw $10,000 from bank account." << endl;
	person2.withdraw(10000);

	//attempt to withdraw small amount
	cout << "Attempting to withdraw 300 from bank account...\n" << endl;
	person2.withdraw(300);

	//display account 2 details
	cout << "\nDetails for your account..." << endl;
	cout << "ID: " << person2.getId() << endl;
	cout << "Balance: " << person2.getBalance() << endl;
	cout << "Annual Interest Rate: " << person2.getAnnualInterestRate() << endl;
	cout << "Monthly Interest Rate: " << person2.getMonthlyInterestRate() << endl;
	cout << "Monthly Interest: " << person2.getMonthlyInterest() << endl;

	system("pause");
	return 0;
}