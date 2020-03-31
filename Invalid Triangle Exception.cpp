#include<iostream>
#include<cmath>
#include<string>
#include<exception>
using namespace std;

//class that throws an exception for an invalid traingle
class InvalidTriangleException : public exception {
public:
	const char* what() const throw () {
		return "That is not a valid triangle";
	}
};

//triangle class validates sides before creating triangle
//throws exception if triangle is not real
//functions return area and perimeter
class Triangle {
private:
	double sideA, sideB, sideC;
public:
	Triangle(double _sideA, double _sideB, double _sideC) {
		if (_sideA + _sideB > _sideC&& _sideA + _sideC > _sideB&& _sideB + _sideC > _sideA) {
			sideA = _sideA;
			sideB = _sideB;
			sideC = _sideC;
		}
		else {
			InvalidTriangleException error;
			throw error;
		}
	}

	double area() {
		double area, p;
		p = perimeter() / 2;
		area = p * (p - sideA) * (p - sideB) * (p - sideC);
		area = sqrt(area);
		return area;
	}
	double perimeter() {
		double perimeter;
		perimeter = sideA + sideB + sideC;
		return perimeter;
	}
};

int main() {
	cout << "The invalid triangle class" << endl;
	cout << "**************************\n" << endl;
	double sideA, sideB, sideC;
	cout << "Enter the sides of a triangle seperated by spaces: ";
	cin >> sideA >> sideB >> sideC;

	//testing creating a custom triangle 
	try
	{
		Triangle customTriangle(sideA, sideB, sideC);
		cout << "     Area: " << customTriangle.area() << endl;
		cout << "Perimeter: " << customTriangle.perimeter() << endl;
	}
	catch (InvalidTriangleException exceptObj)
	{
		cout << "custom: " << exceptObj.what() << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}