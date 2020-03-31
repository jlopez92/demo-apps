#include<iostream>
using namespace std;

/*int operator - (EvenNumber & n1, EvenNumber & n2)
{
	return n1.getValue() - n2.getValue();
}
*/
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
	int getValue() {
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

	int operator + (EvenNumber const& E2)
	{
		int sumOfNumbers = this->number + E2.number;
		return sumOfNumbers;
	}

	int operator * (EvenNumber const& E2)
	{
		int numberMultiplied = this->number * E2.number;
		return numberMultiplied;
	}
};

int main() {
	cout << "*******Overloading Even Number class*****\n\n";

	cout << "Creating a set of even number objects..." << endl;
	EvenNumber test1(62);
	EvenNumber test2(98);
	EvenNumber test3(18);

	cout << "first even object number created is " << test1.getValue() << "." << endl;
	cout << "second even object number created is " << test2.getValue() << "." << endl;
	cout << "third even object number created is " << test3.getValue() << "." << endl;
	cout << test1 + test2 << endl;
	cout << test3 * test2 << endl;

	system("pause");
	return 0;
}