#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;


bool pointInCircle(double xDistance, double yDistance, double width, double height){
//bool function that takes in the deltaX, deltaY of test point from center of circle
//also takes in the height and width of the rectangle
	if (xDistance <= width && yDistance <=height){
		return true;
	} else {
		return false;
	}
	//if else statement to determine whether point is inside or outside circle
}
int main() {
	
	cout << boolalpha;
	// turn on true / false in the print out
	
	double centerX, centerY, width, height, testX, testY;
	//double variables for all neccessary data from user 
	//prompt user for variable inputs
	cout << "Enter the center position of a rectangle." << endl;
	cout << "Center X coordinate: ";
	cin >> centerX;
	cout << "Center Y coordinate: ";
	cin >> centerY;
	cout << "Enter the dimensions of the rectangle." << endl;
	cout << "width: ";
	cin >> width;
	cout << "Height: ";
	cin >> height;
	cout << "Enter a point to test." << endl;
	cout << "Point X Coordinate: ";
	cin >> testX;
	cout << "Point y coordinate: ";
	cin >> testY;
	
	//find the distance from test point to center of circle
	//enter results in double variable 
	double xDistance, yDistance;
	xDistance = abs(centerX - testX);
	yDistance = abs(centerY - testY);
	width = width / 2.0;
	height = height / 2.0;
	//take half width and half height to test the test point
	cout << "Is the Point inside the circle?" << endl;
	//call the bool function to determine whether point is inside or outside the function.
	cout << pointInCircle(xDistance, yDistance, width, height) << endl;
	return 0;
}
