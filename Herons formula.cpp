#include<iostream>
#include<cmath>
using namespace std;

//create bool function to determine if triangle is real
//parameters are in form of double, and they are the three sides
//if else statement used to determine that two sides always equal more than one
//if true, returns true. if false, returns false.
bool realTriangle(double sideA, double sideB, double sideC){
	
	bool isTriangle;
	if (sideA + sideB > sideC && sideA + sideC > sideB && sideB + sideC > sideA){
		isTriangle = true;
	} else {
		isTriangle = false;
	}
	
	return isTriangle;
}

//double function for heron's formula
//parameters are in form of double
//inputs are the three sides
//function, calls the real triangle function to validate the sides make up a triangle
//if else statment to return area of triangle if it is a real triangle
//or return error if it is not a real triangle
double heronsFormula(double sideA, double sideB, double sideC){
	
	double area, semiPerimeter;
	bool isReal = realTriangle(sideA, sideB, sideC);
	
	
	if (isReal == true){
		semiPerimeter = (sideA + sideB + sideC) / 2;
		area = sqrt(semiPerimeter * (semiPerimeter - sideA) * (semiPerimeter - sideB) * (semiPerimeter - sideC));
		cout << "Area of Triangle is ";
		return area;
	} else {
		cout << "Error: This is not a real triangle" << endl;
	
	}
}

int main() {
	cout << fixed;
	cout.precision(3);
	//3 double variables for the sides of the triangle
	double sideA, sideB, sideC;
	//prompt user for the three sides
	cout << "Heron's Formula" << endl;
	cout << "---------------\n" << endl;
	cout << "Enter three sides of a triangle" << endl;
	cout << "Enter side A: ";
	cin >> sideB;
	cout << "Enter side B: ";
	cin >> sideC;
	cout << "Enter side C: ";
	cin >> sideA;
	
	//call the heron's formula function
	//pass the three sides of the triangle as parameters
	cout << heronsFormula(sideA, sideB, sideC) << endl;
	
	return 0;
	
	
}
