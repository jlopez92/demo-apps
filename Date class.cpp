#include<iostream>
#include<string>
#include<vector>
using namespace std;

//create a class for the date
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
	Date(int _day, int _month, int _year) {
		if (_month <= 0 || _month >= 13) {
			cout << "The month must be between 1 and 12" << endl;
			exit(0);
		}

		if (_day <= 0 || _day > daysInMonth[_month - 1]) {
			cout << "Sorry, only " << daysInMonth[_month - 1] << " days in " << monthName[_month - 1] << "." << endl;
			exit(0);
		}

		year = _year;
		month = _month;
		day = _day;
	}

	int getDay() {
		return day;
	}

	int getMonth() {
		return month;
	}

	int getYear() {
		return year;
	}

	//compares two dates and orders in chronological order
	void compareDates(Date& _date) {
		if (_date.getYear() > year&& _date.getMonth() > month&& _date.getDay() > day) {
			_date.printDate();
			printDate();
		}
		else {
			printDate();
			_date.printDate();
		}
	}

};

int main() {
	//create two vectors to hold the user dates 
	vector<int> input1(3, 0);
	vector<int> input2(3, 0);

	cout << "Enter first day, month, year seperated by spaces: ";
	cin >> input1[0];
	cin >> input1[1];
	cin >> input1[2];

	cout << "Enter second day, month, year seperated by spaces: ";
	cin >> input2[0];
	cin >> input2[1];
	cin >> input2[2];

	//create two date objects from user inputs
	Date date1(input1[0], input1[1], input1[2]);
	Date date2(input2[0], input2[1], input2[2]);

	cout << "\nHere are the dates in chronological order." << endl;
	date1.compareDates(date2);

	return 0;
}