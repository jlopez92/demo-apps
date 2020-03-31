#include<iostream>
#include<string>
#include<vector>
using namespace std;

//recycled and updated Date class from previous assignment
//data members are year, month, day
//if incorrect date is entered, program exits with error message
//cin.ignore(numeric_limits<streamsize>::max(), '\n'); used after cin >> to avoid affecting getline function
class Date {
	//int variables for day month and year
	//vector to hold the days in each month
	//vector to hold the month names
	int year, month, day;
	vector<int> daysInMonth{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	vector<string> monthName{ "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

	//function member prints the date
	void printDate() {
		cout << month << "/" << day << "/" << year << endl;
	}

public:
	//constructor takes in day, month, and year
	//error checks the month and the day
	Date() {
		//int _month, _day, _year;
		cout << "Month: ";
		cin >> month;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Day: ";
		cin >> day;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Year: ";
		cin >> year;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (month <= 0 || month >= 13) {
			cout << "The month must be between 1 and 12" << endl;
			exit(0);
		}

		if (day <= 0 || day > daysInMonth[month - 1]) {
			cout << "Sorry, only " << daysInMonth[month - 1] << " days in " << monthName[month - 1] << "." << endl;
			exit(0);
		}

	}



};

//person class created that holds name, address, and email
//default constructor prompts user for values to be stored
class Person {
protected:
	string name;
	string address;
	string email;

public:
	Person() {
		cout << "Name: ";
		getline(cin, name);
		cout << "Address: ";
		getline(cin, address);
		cout << "email: ";
		cin >> email;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	void print() {
		cout << "Person Class. Name of person: " << name << endl;
	}
};

//employee class inherits from person
//expands by adding office number, hire date, and salary
//default constructor prompts user for values to be stored
class Employee : public Person {
protected: 
	string officeNumber;
	Date hireDate;
	double salary;
public:
	Employee() {
		
		cout << "Office phone number: ";
		cin >> officeNumber;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "salary(per year): $";
		cin >> salary;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	void print() {
		cout << "Employee Class. Name of person: " << name << endl;
	}
};

//student class inherits from person and adds class status
//default constructor prompts user for values to be stored
class Student : public Person {
private:
	string status;
public:
	Student() {
		cout << "Class status: ";
		cin >> status;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	void print() {
		cout << "Student Class. Name of person: " << name << endl;
	}

};

//staff class inherits from Employee and adds a title 
//default constructor prompts user for values to be stored
class Staff : public Employee {
private:
	string title;
public:
	Staff() {
		cout << "Title: ";
		cin >> title;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	void print() {
		cout << "Staff Class. Name of person: " << name << endl;
	}
};

//Faculty class inherits from Employee and adds office hours and tenure data members
//default constructor prompts user for values to be stored
class Faculty : public Employee {
private:
	string officeHours;
	string Tenure;
public:
	Faculty() {
		cout << "office Hours: ";
		getline(cin, officeHours);
		cout << "Tenure: ";
		cin >> Tenure;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	void print() {
		cout << "Faculty Class. Name of person: " << Person::name << endl;
	}
};

int main() {
	cout << "Subclasses of person" << endl;
	cout << "********************" << endl;

	//creating objects of each type of class
	cout << "Creating person." << endl;
	Person person;
	cout << "\n\nCreating Employee." << endl;
	Employee employee;
	cout << "\n\nCreating Creating student." << endl;
	Student student;
	cout << "\n\nCreating Staff." << endl;
	Staff staff;
	cout << "\n\nCreating Faculty" << endl;
	Faculty faculty;

	//displaying the print method for each type of class
	cout << "displaying print method for each object created" << endl;
	person.print();
	employee.print();
	student.print();
	staff.print();
	faculty.print();

	system("pause");
	return 0;

}