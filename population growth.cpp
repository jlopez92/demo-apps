#include<iostream>
#include<iomanip>
using namespace std;

int main() 
{
	cout << fixed; //avoid exponential notation
	cout.precision(2); //prints decimal places to the hundreds
	
	int population; //declare population variable as an int(use int as people can't be fractions)
	float births; //declare birth variable as a float
	float deaths; //declare death variable as a float
	float immigrants; //declare immigrants variable as a float
	int PopGrowth; //declare intager popgrowth for new population size(use int as people can't be fractions)
	
	births = (365 * 24 * 60 *60)/8.0; //birth occurs every 8 seconds so find births per year
	//find seconds in a year year(365 days * 24 hours per day * 60 minutes per hour * 60 seconds per minute)
	//divide seconds by 8, as birth rate is one birth per 8 seconds
	
	deaths = (365 * 24 * 60 *60)/11.0; //death occurs every 11 seconds, need deaths per year
	//find seconds in a year(365 days * 24 hours per day * 60 minutes per hour * 60 seconds per minute)
	//divide seconds by 11, as death rate is one death per 11 seconds
	
	immigrants = (365 * 24 * 60 *60)/33.0; //immigrants arrive every 33 seconds, need migrants per year
	//find seconds in a year(365 days * 24 hours per day * 60 minutes per hour * 60 seconds per minute)
	//divide seconds by 33, as immigration rate is one immigrant per 33 seconds
	
	population = 328231337;
	cout << "US Population on January, 1 2019 is: " << population << endl; //display population on january, 1 2019
	cout << "The US will have an estimated " << births << " births in the year 2019." << endl; //display births in 2019
	cout << "The US will have an estimated " << deaths << " deaths in the year 2019." << endl; //display deaths in 2019
	cout << "The US will have an estimated " << immigrants << " new immigrants in the year 2019." << endl;	//display new immigrant total in 2019

	PopGrowth= population + births + immigrants - deaths;  //population change after one year
	cout << "The US will have an estimated population size of " << PopGrowth << " after one year(365 days)." << endl;
	
	
	return 0;
	
	
	
}
