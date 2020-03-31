#include<iostream>
#include<cmath>
using namespace std;

void printDistance(float x1, float x2, float y1, float y2){ 
//created a function named "printDistance", that requires four inputs which are all floats	
	
	float deltaX, deltaY; // create two variable floats for delta x(x2-x1) and delta y	
	deltaX = x2 - x1; // calculate deltaX
	deltaY = y2 - y1; // calculate deltaY
	
	deltaX = pow (deltaX, 2); //use the pow function to square delta x
	deltaY = pow (deltaY, 2); //use the pow function to square delta y
	float Distance; //create float variable for distance
	Distance = deltaX + deltaY; // add deltaX and deltaY per distance equation 
	Distance = sqrt(Distance); //get the sqaure root of the distance per distance equation
	
	cout << "The distance is: " << Distance << endl; // display simple output with your distance
}

int main ()
{
	cout.fixed;
	cout.precision(4); // have four decimal places
	
	float x1, x2, y1, y2; //create four variables for the x's and y's
	
	cout << "enter the first x: "; //prompt user for first x
	cin >> x1; //store first x in x1, repeat for the other three data points
	cout << "enter the first y: ";
	cin >> y1;
	cout << "enter the second x: ";
	cin >> x2;
	cout << "enter the second y: ";
	cin >> y2;
	
	printDistance(x1, x2, y1, y2); //call function using the variables provided by the user
	
	
	return 0;	
}
