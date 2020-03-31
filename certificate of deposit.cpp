#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;


void printCdTable(float initialDeposit, float interestRate, float maturityPeriod){
		int initialTime = 0;
	while (initialTime < maturityPeriod){
		
		initialDeposit = initialDeposit + (initialDeposit * interestRate);
		initialTime = initialTime + 1;
		cout << initialTime << setw(15) << initialDeposit << endl;
	}
}

int main () {
	cout << fixed;
	cout.precision(2);
	
	float initialDeposit, interestRate, maturityPeriod;
	cout << "Enter initial deposit: ";
	cin >> initialDeposit;
	
	cout << "Enter the annual interest rate(%): ";
	cin >> interestRate;
	interestRate = interestRate / 100;
	cout << "Enter the maturity period(months): ";
	cin >> maturityPeriod;
	if (initialDeposit > 0 && interestRate > 0 && maturityPeriod > 0){
		cout << "Month" << setw(10) << "CD Value" << endl;
		printCdTable(initialDeposit, interestRate, maturityPeriod);
	}
	

	return 0;
}
