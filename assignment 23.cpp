#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;




int main () {
	
	int counter = 1;
	while (counter <= 5) {
		cout << counter << endl;
		counter += 1;
		
	}
	int odd = 4;
	odd = odd % 2;
	cout << odd;
	return 0;
}
