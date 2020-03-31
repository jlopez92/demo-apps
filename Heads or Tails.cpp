#include<iostream>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<time.h>
using namespace std;

//struct to hold results of the heads or tails game
struct results{
	int heads;
	int tails;
	
};

//void used to input the results of the game into coinToss
void printResults(const results& coinToss){
	double total = coinToss.heads + coinToss.tails;
	cout << setw(5) << "\nTotal Tosses: " << setw(7) << coinToss.heads + coinToss.tails << endl;
	cout << setw(5) << "Total Heads: " << setw(7) << coinToss.heads <<  endl;
	cout << setw(5) << "Total Tails: " << setw(7) << coinToss.tails << endl;
	cout << setw(5) << "percent Heads: " << setw(7) << coinToss.heads / total << endl;
	cout << setw(5) << "percent Tails: " << setw(7) << coinToss.tails / total << endl << endl;	
	
}

int main(){
	//set decimal places to 6
	cout << fixed;
	cout.precision(6);
	
	//randomize results
	srand(15);
	
	//start out with a userChar of y to enter the game
	char userChar = 'y';
	int userCoinToss; 
	int headsOrTails;
	results coinToss = { 0, 0}; //create a coinToss struct and initialize values with 0
	cout << "The Coin Toss Game!!\n**********************\n" << endl;
	
	//while loop to hold whether player wants to continue playing after each turn
	while(userChar == 'y'){
		cout << "How many coin tosses would you like to perform?: ";
		cin >> userCoinToss;	
		//for loop to iterate through number of games the user wants to play
		for(int index = 0; index < userCoinToss; index++){
			headsOrTails = rand() % 2;
			if (headsOrTails == 0){
				coinToss.heads = coinToss.heads + 1;
			} else {
				coinToss.tails = coinToss.tails + 1;
			}
		}
		
		printResults(coinToss); //call function to print the stats of the games 

		cout << "Would you like to flip again(y or n)?: ";
		cin >> userChar;
		
	}
	

	
	
	
	return 0;
}
