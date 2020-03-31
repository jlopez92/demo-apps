#include<iostream>
#include<cmath>
using namespace std;

void quadraticEquation(double coefficientA, double coefficientB, double coefficientC) {
	float discriminant, r1, r2; //create float for the two real roots and the discriminant
	//discriminant will determine whether their is one, two, or no real roots
	discriminant = pow(coefficientB, 2) - (4 * coefficientA * coefficientC);
	//calculate discriminant of the equation
	
	//begin if else statement  to determine number of roots
	if (discriminant < 0) { //if no real roots
		cout << "There are no real roots" << endl;
	} else if (discriminant == 0 ) { //if one real root
		cout << "There is one real root" << endl;
		r1 = (- coefficientB)/(2 * coefficientA);
		cout << "x = " << r1 << endl;
	} else if (discriminant > 0) { //if two real roots
		cout << "There are two real root" << endl;
		r1 = (- coefficientB + (sqrt(discriminant)))/(2 * coefficientA);
		r2 = (- coefficientB - (sqrt(discriminant)))/(2 * coefficientA) ;
		cout << "x = " << r1 << " and x = " << r2 << endl;
	} else {
		cout << "error" << endl;
	}
}


int main(){
	
	cout << fixed;
	cout.precision(2);
	cout << "QUADRATIC EQUATION SOLVER" << endl;
	cout << "************************* \n\n" << endl;
	double coefficientA, coefficientB, coefficientC;
	//create three double variables for coefficients A, B, and C
	cout << "Please enter coefficient A: "; //prompt user for coefficient A
	cin >> coefficientA; //place user input into coefficientA variable
	//repeat for coefficientB and C
	
	cout << "Please enter coefficient B: ";
	cin >> coefficientB;
	
	cout << "Please enter coefficient C: ";
	cin >> coefficientC;
	
	quadraticEquation(coefficientA, coefficientB, coefficientC); //call quadratic equation function
	
	return 0;
}
