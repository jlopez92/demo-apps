#include<iostream>
#include<string>
using namespace std;

//create a called rectangle
class Rectangle {
private: //all private members stored here
	double width, height; //create double variables for height and width

public: //all public members stored here
	//zero argument constructor
	Rectangle() {
		width = 1;
		height = 1;
	}

	//constructor that sets height and width by calling setwidth and setheight functions
	Rectangle(double _height, double _width) {
		setWidth(_width);
		setHeight(_height);
	}

	//function returns height 
	double getHeight() {
		return height;
	}

	//function returns width
	double getWidth() {
		return width;
	}

	//function error checks and sets height, exits app if error found
	void setHeight(double _height) {
		if (_height > 0) {
			height = _height;
		}
		else {
			cout << "Error, height and width must both be positive" << endl;
			exit(0);
		}
	}

	//function error checks and sets width, exits app if error found
	void setWidth(double _width) {
		if (_width > 0) {
			width = _width;
		}
		else {
			cout << "Error, height and width must both be positive" << endl;
			exit(0);
		}
	}

	//calculates area
	double area() {
		return width * height;
	}

	//calculates perimeter
	double perimeter() {
		return width * 2 + height * 2;
	}
};

int main() {
	//test zero argument constructor for rectangle, and height, width constructor as well
	Rectangle rectangle1;
	Rectangle rectangle2(5, 10);

	//displays info for rectangle 1
	cout << "Rectangle 1" << endl;
	cout << "width: " << rectangle1.getWidth() << endl;
	cout << "height: " << rectangle1.getHeight() << endl;
	cout << "area: " << rectangle1.area() << endl;
	cout << "perimeter: " << rectangle1.perimeter() << endl << endl;

	//displays info for rectangle 2
	cout << "Rectangle 2" << endl;
	cout << "width: " << rectangle2.getWidth() << endl;
	cout << "height: " << rectangle2.getHeight() << endl;
	cout << "area: " << rectangle2.area() << endl;
	cout << "perimeter: " << rectangle2.perimeter() << endl << endl;

	//grab info from user to create third rectangle
	double width, height;
	cout << "Enter the width and height seperated by a space: ";
	cin >> width;
	cin >> height;
	Rectangle rectangle3(height, width);
	cout << "Rectangle 3" << endl;
	cout << "width: " << rectangle3.getWidth() << endl;
	cout << "height: " << rectangle3.getHeight() << endl;
	cout << "area: " << rectangle3.area() << endl;
	cout << "perimeter: " << rectangle3.perimeter() << endl << endl;



	return 0;
}