#include<iostream>
#include <ctime>
#include <time.h>
#include<string>
using namespace std;

//create a class for stopwatch
class Stopwatch {
private:
	double startTime, stopTime;

public:
	//returns the start time
	double getStartTime() {
		return startTime;
	}

	//returns the stop time
	double getStopTime() {
		return stopTime;
	}

	//stopwatch constructor with no arguments
	Stopwatch() {
		startTime = time(NULL);
		stopTime = time(NULL);
	}

	//grab initial time 
	void start() {
		startTime = time(NULL);
	}

	//grab final time 
	void stop() {
		stopTime = time(NULL);
	}

	//calculate the time in seconds
	double getElapsedTime() {
		return stopTime - startTime;
	}
};

int main() {
	//create an object for stopwatch
	Stopwatch stopwatch1;

	//wait for user input to start watch
	cout << "Start the watch: ";
	system("pause");
	stopwatch1.start();
	cout << "..........\nstopwatch is running\n..............." << endl;

	//wait for user input to stop watch
	cout << "Stop the watch: ";
	system("pause");
	stopwatch1.stop();

	//display stopwatch time
	cout << "The stopwatch time is: " << stopwatch1.getElapsedTime() << " seconds" << endl;

	system("pause");
	return 0;
}