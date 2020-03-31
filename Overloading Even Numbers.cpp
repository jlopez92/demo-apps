#include<iostream>
using namespace std;



class EvenNumber {
private:
	int number;

public:
	//even number default constructor
	EvenNumber() {
		number = 0;
	}

	//one argument constructor
	EvenNumber(int _number) {
		number = _number;
	}

	//return the value of the number
	int getValue() const{
		return number;
	}

	//set the next even number
	void setNext() {
		number = number + 2;
	}

	//set the previous even number
	void setPrevious() {
		number = number - 2;
	}

	//overloading addition inside class
	int operator + (EvenNumber const& E2)
	{
		int sumOfNumbers = this->number + E2.number;
		return sumOfNumbers;
	}

	//overloading mutiplication inside class
	int operator * (EvenNumber const& E2)
	{
		int numberMultiplied = this->number * E2.number;
		return numberMultiplied;
	}
};

//overloading subtraction  outside of a class
static int operator-(EvenNumber const& n1, EvenNumber const& n2)
{
	return n1.getValue() - n2.getValue();
}

int main() {
	cout << "*******Overloading Even Number class*****\n\n";

	cout << "Creating a set of even number objects..." << endl;
	EvenNumber object1(62);
	EvenNumber object2(98);
	EvenNumber object3(18);

	cout << "first even object number created is " << object1.getValue() << "." << endl;
	cout << "second even object number created is " << object2.getValue() << "." << endl;
	cout << "third even object number created is " << object3.getValue() << "." << endl;
	cout << "\n\n Testing overloading" << endl << endl;
	cout << "Adding object 1: " << object1.getValue() << " to object 2: " << object2.getValue() << " using overloading." << endl;
	cout << object1 + object2 << endl << endl;
	cout << "multiplying object 3: " << object3.getValue() << " to object 2: " << object2.getValue() << " using overloading." << endl;
	cout << object3 * object2 << endl << endl;
	cout << "subtracting object 1: " << object1.getValue() << " to object 3: " << object3.getValue() << " using overloading." << endl;
	cout << object1 - object3 << endl;

	system("pause");
	return 0;
}