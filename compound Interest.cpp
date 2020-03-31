#include<iostream>
#include<cmath>
using namespace std;

void printCompoundInterest(float principal, float rate, float time, float compound) //create function to calculate compound interest 
{
	
	float parentheses, power, parenthesesPower, amount; //create float variable and split up formula into 3 small chunks and main formula in order to accuratly grab info
	parentheses = (1 + rate / compound);
	power = time * compound;
	parenthesesPower = pow (parentheses, power);
	amount = principal * parenthesesPower;
	
	cout << amount << endl; 
}

int main(){
	
	
	float investment, interestPercent, interest, time, compound;
	//create four float variables to hold the investment amount, interest rate in percent and interest to convert, time(number of years), compounding rate
	
	cout << "Compound Interest \n \n" << endl;
	
	cout << "Please enter the investment amount: $"; //prompt user for the investment amount and store in investment variable
	cin >> investment;
	
	cout << "Please enter the interest rate: %"; // prompt user for interest rate and convert to decimal
	cin >> interestPercent;
	interest = interestPercent / 100;
	
	cout << "Please enter the number of years: "; //prompt user for length of time
	cin >> time;
	cout << endl;
	
	cout << "value of investment after " << time << " years" << endl;
	cout << "**************************************\n" << endl;
	
	compound = 1; //set compound period to once for the year
	cout << "Compound once a year: $";
	printCompoundInterest(investment, interest, time, compound); //call the printCompoundInterest function with compound set to annual
	
	compound = 2; //set compound period to semi-annual
	cout << "Compound twice a year: $";
	printCompoundInterest(investment, interest, time, compound); //call the printCompoundInterest function with compound set to semi-annual
	
	compound = 12; //set compound period to monthly
	cout << "Compound monthly: $";
	printCompoundInterest(investment, interest, time, compound); //call the printCompoundInterest function with compound set to monthly
	
	compound = 365; //set compound period to daily
	cout << "Compound daily: $";
	printCompoundInterest(investment, interest, time, compound); //call the printCompoundInterest function with compound set to daily
	
	
	
	return 0;
}
