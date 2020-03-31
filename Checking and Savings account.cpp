#include<iostream>
#include<string>
using namespace std;

//create a parent Account class
//data members are account id, balance, and annual interest rate
//getter and setter methods used, and some other methods we won't need here
//default constructor sets all data members to zero.
//thre arg constructor takes in provided values for data members
class Account {
protected:
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



	void toString() {
		cout << "Account ID: " << id << endl;
		cout << "balance: $" << balance << endl;
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

//savings account inherits from account class
//a minimum balance of 100 is used 
//toString method displays information of the account
//void method assess $10 fee if balance drops below minimum balance after withdrawal
class SavingsAccount : public Account {
	double minimumBalance;

public:
	SavingsAccount() {
		minimumBalance = 100;
	}

	SavingsAccount(int _id, double _balance, double _AnnualInterestRate) {
		minimumBalance = 100;
		setId(_id);
		setBalance(_balance);
		setAnnualInterestRate(_AnnualInterestRate);
	}

	void toString() {
		cout << "Account ID: " << id << endl;
		cout << "balance: $" << balance << endl;
		cout << "minumum balance needed in account: " << minimumBalance << endl;
	}

	//function to withdraw from account, error checks for enough funds
	void withdraw(double amount) {
		if (amount + minimumBalance < balance ) {
			balance = balance - amount;
		}
		else {
			cout << "Your savings account has dropped below the minimum balance of " << minimumBalance << ". A $10 fee will be assessed." << endl;
			balance = balance - amount - 10;
		}
	}
};

//checkingAccount class inherits from Accout
//an overdraft limit of 100 has been added as a data member
//toString method returns info on account
//Withdraw method allows a withdrawal of greater than 100 dollars of account balance
class CheckingAccount : public Account {
private:
	double overdraftLimit = 100;

public:
	CheckingAccount() {
		overdraftLimit = 100;
	}

	CheckingAccount(int _id, double _balance, double _AnnualInterestRate) {
		overdraftLimit = 100;
		setId(_id);
		setBalance(_balance);
		setAnnualInterestRate(_AnnualInterestRate);
	}

	void toString() {
		cout << "Account ID: " << id << endl;
		cout << "balance: $" << balance << endl;
		cout << "overdraft limit: " << overdraftLimit << endl;
	}

	//function to withdraw from account, error checks for enough funds
	void withdraw(double amount) {
		if (amount < balance + overdraftLimit) {
			balance = balance - amount;
		}
		else {
			cout << "Attempting to withdraw more than $100 past your balance" << endl;
			cout << "Insufficient funds!" << endl;
		}
	}
};

int main() {

	//create objects for each type of account
	Account Spiderman;
	Account Batman(10, 780, .07);
	SavingsAccount IronMan(11, 20800, .06);
	CheckingAccount JoseLopez(11, 9850, .09);

	//The following is simply testing out various methods across all the accounts created
	cout << "Creating default account object for spiderman." << endl;
	cout << "ID: " << Spiderman.getId() << endl;
	cout << "Balance: $" << Spiderman.getBalance() << endl;
	cout << "Annual Interest Rate: " << Spiderman.getAnnualInterestRate() << endl;
	cout << "Monthly Interest Rate: " << Spiderman.getMonthlyInterestRate() << endl;
	cout << "Monthly Interest: $" << Spiderman.getMonthlyInterest() << endl << endl;

	
	cout << "Spiderman stole $500, depositing into his account..." << endl;
	Spiderman.deposit(500);
	cout << "Spidermans account info..." << endl;
	Spiderman.toString();
	cout << "\nSpiderman ripped his suit, needs to withdraw $550 to repair" << endl;
	Spiderman.withdraw(550);
	Spiderman.toString();

	cout << "********************************************************" << endl;
	cout << "\nCreating a savings account object for Iron Man." << endl;
	cout << "ID: " << IronMan.getId() << endl;
	cout << "Balance: $" << IronMan.getBalance() << endl;
	cout << "Annual Interest Rate: " << IronMan.getAnnualInterestRate() << endl;
	cout << "Monthly Interest Rate: " << IronMan.getMonthlyInterestRate() << endl;
	cout << "Monthly Interest: $" << IronMan.getMonthlyInterest() << endl << endl;
	
	cout << "Iron Man was awarded $250 for saving a granny, depositing into his account..." << endl;
	IronMan.deposit(250);
	cout << "Iron Man account info..." << endl;
	IronMan.toString();
	cout << "Iron Man just bought a new Toyota Camry, withdrawing $21000 from his account" << endl;
	IronMan.withdraw(21100);
	cout << "Iron Man account info..." << endl;
	IronMan.toString();

	cout << "********************************************************" << endl;
	cout << "\nCreating a Checking account object for Jose Lopez." << endl;
	cout << "ID: " << JoseLopez.getId() << endl;
	cout << "Balance: $" << JoseLopez.getBalance() << endl;
	cout << "Annual Interest Rate: " << JoseLopez.getAnnualInterestRate() << endl;
	cout << "Monthly Interest Rate: " << JoseLopez.getMonthlyInterestRate() << endl;
	cout << "Monthly Interest: $" << JoseLopez.getMonthlyInterest() << endl << endl;

	cout << "Jose Lopez invented a new workout app, depositing $700 into his account" << endl;
	JoseLopez.deposit(700);
	cout << "Jose Lopez account info:" << endl;
	JoseLopez.toString();
	cout << "Jose Lopez needs $10700 for a house downpayment. Withdrawing from his account." << endl;
	JoseLopez.withdraw(10700);
	cout << "Jose Lopez found $100 in a wallet on the ground, only needs to withdraw $10600 now. Withdrawing from his account." << endl;
	JoseLopez.withdraw(10600);
	cout << "Jose Lopez account info:" << endl;
	JoseLopez.toString();



	system("pause");
	return 0;
}