#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

//parent class point with two data members for x and y.
//getter methods for x and y created as well
//default constructor initializes x and y to 1
//two arg constructor initializes with provided values.
class Point {
protected:
	double x;
	double y;
public:
	Point() {
		x = 1;
		y = 1;
	}

	Point(double _x, double _y) {
		x = _x;
		y = _y;
	}

	double getX() {
		return x;
	}

	double getY() {
		return y;
	}

	//Three overloaded methods for finding the distance between points. 
	//Inputs are either two objects of type point, one object of type point, or a pointer
	double pointDistance(Point point1, Point point2) {
		double distance = pow((point2.x - point1.x), 2.0) + pow((point2.y - point1.y), 2.0);
		distance = sqrt(distance);
		return distance;
	}

	double pointDistance(Point point1) {
		double distance = pow((this->x - point1.x), 2.0) + pow((this->y - point1.y), 2.0);
		distance = sqrt(distance);
		return distance;
	}

	double pointDistance(Point* point1) {
		double distance = pow((this->x - point1->x), 2.0) + pow((this->y - point1->y), 2.0);
		distance = sqrt(distance);
		return distance;
	}
};

//point3D inherits from point class
//a data member for the z value and a getter method for it is created
//default constructor initializes all values to zero
//three arg constructor initializes all data members using input parameters
class Point3D : public Point {
protected:
	double z;
public:
	Point3D() {
		x = 1;
		y = 1;
		z = 1;
	}

	Point3D(double _x, double _y, double _z) {
		x = _x;
		y = _y;
		z = _z;
	}

	double getZ() {
		return z;
	}

	//Three overloaded methods for finding the distance between points. 
	//Inputs are either two objects of type point, one object of type point, or a pointer
	double pointDistance(Point3D point1, Point3D point2) {
		double distance = pow((point2.x - point1.x), 2.0) + pow((point2.y - point1.y), 2.0) + pow((point2.z - point1.z), 2.0);
		distance = sqrt(distance);
		return distance;
	}

	double pointDistance(Point3D point1) {
		double distance = pow((this->x - point1.x), 2.0) + pow((this->y - point1.y), 2.0) + pow((this->z - point1.z), 2.0);
		distance = sqrt(distance);
		return distance;
	}

	double pointDistance(Point3D* point1) {
		double distance = pow((this->x - point1->x), 2.0) + pow((this->y - point1->y), 2.0) + pow((this->z - point1->z), 2.0);
		distance = sqrt(distance);
		return distance;
	}
};

int main() {
	cout << "Point3D" << endl;
	cout << "*******\n\n";

	//creating 3 point objects and 3 point3D objects
	cout << "Constructing 3 2D points with coordinates (1, 1), (3.0, 2.0), and (5.4, 7.2)..." << endl;
	Point default2d;
	Point point1(3.0, 2.0);
	Point point2(5.4, 7.2);
	cout << "Constructing 3 2D points with coordinates (1, 1, 1), (7.2, 5.5, 7.1), and (3.3, 12, 7.5)." << endl << endl;
	Point3D default3d;
	Point3D point3(7.2, 5.5, 7.1);
	Point3D point4(3.3, 12, 7.5);

	//displaying distance method for two object parameters
	cout << "Finding distance between two points using two point objects as parameters in 2D." << endl;
	cout << "The distance between (1, 1) and (3.0, 2.0) is " << default2d.pointDistance(default2d, point1) << endl << endl;
	cout << "Finding distance between two points using two 3Dpoint objects as parameters." << endl;
	cout << "The distance between (1, 1, 1) and (7.2, 5.5, 7.1) is " << default3d.pointDistance(default3d, point3) << endl << endl;

	//displaying distance method for one object parameter
	cout << "Finding distance between two points using one point object as a parameter in 2D." << endl;
	cout << "The distance between (1, 1) and (5.4, 7.2) is " << default2d.pointDistance (point2) << endl << endl;
	cout << "Finding distance between two points using one 3Dpoint object as a parameter." << endl;
	cout << "The distance between (1, 1, 1) and (3.3, 12, 7.5) is " << default3d.pointDistance(point4) << endl << endl;

	//using the distance method with a pointer
	cout << "Finding distance between two points using one pointer point object as a parameter in 2D." << endl;
	cout << "The distance between (1, 1) and (5.4, 7.2) is " << default2d.pointDistance(&point2) << endl << endl;
	cout << "Finding distance between two points using one pointer 3Dpoint object as a parameter." << endl;
	cout << "The distance between (1, 1, 1) and (3.3, 12, 7.5) is " << default3d.pointDistance(&point4) << endl << endl;

	system("pause");
	return 0;
}