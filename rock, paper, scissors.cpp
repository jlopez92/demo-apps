#include<iostream>
using namespace std;


int main(){
	
	string player1, player2; //create string variable for the choices of player 1 and 2
	
	cout << "Enter player 1's choice: "; //prompt user for player 1 choice
	cin >> player1; //enter user input into player1 variable
	
	cout << "Enter player 2's choice: "; //prompt user for player 2 choice
	cin >> player2; //enter user input into player2 variable
	
	//begin if else statement
	if (player1 == player2){ //if both players chose the same, 
		cout << "Player 1's choice was " << player1;
		cout << ", player 2's choice was " << player2 << endl;
		//display player choices
		cout << "\n The game is a tie.";
		//display outcome of game
		//repeat for every possible outcome
	} else if ( player1 == "rock" && player2 == "paper"){
		cout << "Player 1's choice was " << player1;
		cout << ", player 2's choice was " << player2 << endl;
		cout << "\n Player 2 Wins" << endl;
	} else if ( player1 == "rock" && player2 == "scissors"){
		cout << "Player 1's choice was " << player1;
		cout << ", player 2's choice was " << player2 << endl;
		cout << "\n Player 1 Wins" << endl;
	} else if ( player1 == "paper" && player2 == "rock"){
		cout << "Player 1's choice was " << player1;
		cout << ", player 2's choice was " << player2 << endl;
		cout << "\n Player 1 Wins" << endl;
	} else if ( player1 == "paper" && player2 == "scissors"){
		cout << "Player 1's choice was " << player1;
		cout << ", player 2's choice was " << player2 << endl;
		cout << "\n Player 2 Wins" << endl;
	} else if ( player1 == "scissors" && player2 == "rock"){
		cout << "Player 1's choice was " << player1;
		cout << ", player 2's choice was " << player2 << endl;
		cout << "\n Player 2 Wins" << endl;
	} else if ( player1 == "scissors" && player2 == "paper"){
		cout << "Player 1's choice was " << player1;
		cout << ", player 2's choice was " << player2 << endl;
		cout << "\n Player 1 Wins" << endl;
	}
	return 0;
}
