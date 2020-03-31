#include<iostream>
#include<cmath>
using namespace std;

int main()
{

	
	cout << "Points in a circle calculator" << endl;
	cout << "*****************************\n" << endl;
	float circleCenterX, circleCenterY, radius, testX, testY; 
	//create float variables for radius, circle center coordinates, and the test coordinates
	
	
	//prompt user for all neccessary coordinates and plug into variables accordingly
	cout << "Enter the X coordinate of the circle center: ";
	cin >> circleCenterX;
	
	cout << "Enter the Y coordinate of the circle center: ";
	cin >> circleCenterY;
	
	cout << "Enter the radius of the circle: ";
	cin >> radius;

	cout << "Enter the X coordinate of a point: ";
	cin >> testX;
	
	cout << "Enter the Y coordinate of a point: ";
	cin >> testY;

	//distance variable to store the distance from the point, to the circle center	
	float distance; 
	//calculate the distance between the points using the distance formula
	distance = sqrt((pow((testX - circleCenterX),2)) + (pow((testY - circleCenterY),2))); //distance formula 
	
	
	//begin if, else statement
	if (distance > radius){ //if distance is greater than radius, point is outside circle
		cout << "The point (" << testX << ", " << testY << ") is outside the circle" << endl;
	} else if(distance <= radius){//else if distance is less than or equal to radius, point is inside circle
		cout << "The point (" << testX << ", " << testY << ") is inside the circle" << endl;
	}
	
	
	return 0;
}
