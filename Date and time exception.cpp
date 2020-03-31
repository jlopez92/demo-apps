#include<iostream>
#include<cmath>
#include<string>
#include <sstream>
#include<exception>
using namespace std;

class DateTimeException : public exception {
private:
	string message;
public:
	DateTimeException(string _custom) {
		message = _custom;
		cout << message << endl;
	}
	const char* what() const throw () {
		return message.c_str();
	}
};

class DateTimeHandler {
private:
	string date;
	string time;
public:
	DateTimeHandler(string dateTime) {
		int month, day, year, hour, minute, second;
		stringstream s(dateTime);
		s >> month >> day >> year >> hour >> minute >> second;
		if (dateTime.length() > 22) {
			throw DateTimeException("input string too long");
		}
		else if (dateTime.length() < 22) {
			DateTimeException("input string too short");
		}
		else if (!isdigit(dateTime[0]) || !isdigit(dateTime[1])) {
			DateTimeException("No digit where digit is supposed to be");
		}
		else if (!isdigit(dateTime[0]) || !isdigit(dateTime[1])) {
			DateTimeException("No digit where digit is supposed to be");
		}
		else if (!isdigit(dateTime[3]) || !isdigit(dateTime[4])) {
			DateTimeException("No digit where digit is supposed to be");
		}
		else if (!isdigit(dateTime[6]) || !isdigit(dateTime[7]) || !isdigit(dateTime[8]) || !isdigit(dateTime[9])) {
			DateTimeException("No digit where digit is supposed to be");
		}
		else if (!isdigit(dateTime[11]) || !isdigit(dateTime[12])) {
			DateTimeException("No digit where digit is supposed to be");
		}
		else if (!isdigit(dateTime[14]) || !isdigit(dateTime[15])) {
			DateTimeException("No digit where digit is supposed to be");
		}
		else if (!isdigit(dateTime[17]) || !isdigit(dateTime[18])) {
			DateTimeException("No digit where digit is supposed to be");
		}
		else if (month > 12) {
			DateTimeException("only 12 months in a year");
		}
		else if (day > 31) {
			DateTimeException("only 31 days in a month");
		}
		else if (hour > 12) {
			DateTimeException("hours can not exceed 12 in standard time");
		}
		else if (minute > 60) {
			DateTimeException("Only 60 minutes in an hour");
		}
		else if (minute > 60) {
			DateTimeException("Only 60 seconds in a minute");
		}
		else {
			date = dateTime.substr(0, 10);
			time = dateTime.substr(12, 20);
		}
	}

	string getDate() {
		return date;
	}

	string getTime() {
		return time;
	}
};


int main() {
	cout << "Date Time Exception" << endl;
	cout << "**************************\n" << endl;
	cout << "Input date/time in standard format: ";
	string userInput;
	getline(cin, userInput);


	while (userInput != "q") {
		try
		{
			DateTimeHandler newDay(userInput);
			if (newDay.getDate() != "") {
				cout << "Date: " << newDay.getDate() << endl;
				cout << "Time: " << newDay.getTime() << endl;
			}
		}
		catch (DateTimeException exceptObj)
		{
			cout << "custom: " << exceptObj.what() << endl;
		}
		cout << "Input date/time in standard format(q to quit): ";
		getline(cin, userInput);
	}



	cout << endl;
	system("pause");
	return 0;
}