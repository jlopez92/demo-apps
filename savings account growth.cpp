#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	
	cout << fixed;
	cout.precision(2);  //two decimal places
	
	float initialDeposit; //float variable to store initial deposit
	float interestRate; //float variable to store annual interest rate
	float monthlyDeposit; //float variable to store monthly recurring deposit
	float balance; //float variable to store balance 
	
	cout << "Please enter the initial deposit: $"; //promt user for initial deposit amount
	cin >> initialDeposit; //store user input into initial deposit variable
	balance = initialDeposit; //set balance to initial deposit. to be used later
	
	cout << "Please enter the annual interest rate: %"; //prompt user to enter the annual interest rate(percent)
	cin >> interestRate; //store user input into interest rate variable 
	
	cout << "Please enter the recurring monthly deposit: $"; //prompt user to enter recurring monthly deposit
	cin >> monthlyDeposit; // store user input into monthly deposit variable 
	
	float monthlyInterestRate; //float variable to store monthly interest rate 
	monthlyInterestRate = ((interestRate / 100) / 12); //calculate monthly interest rate based on annual interest rate percent
	
	
	float interestAccrued; //create interest accrued variable to calculate interest of balance 
	interestAccrued = balance * monthlyInterestRate;//calculate interest accrued by multiplying balance by monthly interest rate
	
	cout << "--------------------------------\n \n" << endl;
	
	cout << setw(8) << "Type" << setw(20) << "Deposit" << setw(17) << "Balance" << endl; //create output for type of desposit, deposit amount, and balance
	cout << "------------------------------------------------" << endl;
	cout << "initial" << setw(15) << "$" << initialDeposit << setw(15) << "$" << balance << endl; //output initial balance
	interestAccrued = balance * monthlyInterestRate; //calculate interest accrued on balance 
	balance = balance + interestAccrued; //calculate new balance 
	cout << "interest" << setw(16) << "$" << interestAccrued << setw(15) << "$" << balance << endl; //output new balance after interest accrued
	balance = balance + monthlyDeposit; // calculate new balance after monthly deposit
	cout << "recurring" << setw(15) << "$" << monthlyDeposit << setw(15) << "$" << balance << endl; // output new balance after monthly deposit
	interestAccrued = balance * monthlyInterestRate; //repeat
	balance = balance + interestAccrued;
	cout << "interest" << setw(16) << "$" << interestAccrued << setw(15) << "$" << balance << endl;
	balance = balance + monthlyDeposit;
	cout << "recurring" << setw(15) << "$" << monthlyDeposit << setw(15) << "$" << balance << endl;
	interestAccrued = balance * monthlyInterestRate;
	balance = balance + interestAccrued;
	cout << "interest" << setw(16) << "$" << interestAccrued << setw(15) << "$" << balance << endl;
	balance = balance + monthlyDeposit;
	cout << "recurring" << setw(15) << "$" << monthlyDeposit << setw(15) << "$" << balance << endl;
	interestAccrued = balance * monthlyInterestRate;
	balance = balance + interestAccrued;
	cout << "interest" << setw(16) << "$" << interestAccrued << setw(15) << "$" << balance << endl;
	balance = balance + monthlyDeposit;
	cout << "recurring" << setw(15) << "$" << monthlyDeposit << setw(15) << "$" << balance << endl;
	
	
	
	
	return 0;
	
}
