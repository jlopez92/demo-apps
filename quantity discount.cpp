#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//function for discount formula that returns the price in dollars as double
double discountFormula(int quantity, double price){
	double discount;
	
	//if else if to determine the quantity of items, and the given 
	//discount for that quantity
	if(quantity > 0 && quantity < 10){
		discount = 0;
	} else if(quantity >= 10 && quantity < 20){
		discount = price * 0.85;
	} else if(quantity >= 20 && quantity < 30){
		discount = price * 0.8;
	} else if(quantity >= 30){
		discount = price * 0.75;
	}
	
	return discount;
}
int main() {
	
	cout << fixed;
	cout.precision(2); //two decimal places
	
	//int variable for quantity
	int quantity;
	//double variable for price
	double price;
	
	//prompt user for quantity of items
	//place input into quantity variable
	cout << "Enter the quantity of items: ";
	cin >> quantity;
	
	//prompt user for price of item
	//place input into price variable
	cout << "Enter the item price: $";
	cin >> price;
	
	//find whether both qunatity and price are positive numbers
	//if one is 0 or negative, return error
	//else calculate the discount amount using the discountFormulat function 
	//and display final bill
	if (quantity <= 0 || price <= 0){
		cout << "Error, inputs must be positive numbers" << endl;
	} else {
		cout << "Cost before discount: $" << price << endl;
		double discount = discountFormula(quantity, price);
		cout << "     discount amount:  $" << discount << endl;
		cout << "          Final Cost:  $" << price - discount << endl;
	}
	
	return 0;
}
