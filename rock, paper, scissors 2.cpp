#include<iostream>
#include<string>
#include<cctype>
#include<ctime>
#include<cstdlib>
using namespace std;

//int function to determine outcome of rock paper scissors game
int whoWon(string player1, string computer){
	
		if (player1 == computer){ 
		return 3;
		//return 3, for tie, 2, for computer win, 1 for player win
	} else if ( player1 == "rock" && computer == "paper"){
		return 2;
	} else if ( player1 == "rock" && computer == "scissors"){
		return 1;
	} else if ( player1 == "paper" && computer == "rock"){
		return 1;
	} else if ( player1 == "paper" && computer == "scissors"){
		return 2;
	} else if ( player1 == "scissors" && computer == "rock"){
		return 2;
	} else if ( player1 == "scissors" && computer == "paper"){
		return 1;
	}
}

//int function used to determine a random outcome for the computer entry
int randomDieRoll() {
	
	int result = rand();
	result = result % 3;
	result = result + 1;
	return result;
	
}

int main(){
	
	cout << "rock, paper, scissors\n" << "-------------------\n\n\n" << endl;
	
	//create two variables for the entry of player and computer, store user entry 
	string player1, computer; //create string variable for the choices of player 1 and 2
	cout << "Enter q to quit: \n";
	cout << "Enter player's choice: "; //prompt user for player 1 choice
	cin >> player1; //enter user input into player1 variable
	
	//randomize the rand function
	srand(time(0));
	
	//use outcome of the randomdieroll function to determine whether compuer is rock, paper, or scissors
	int computerChoice = randomDieRoll();
	if (computerChoice == 1){
		computer = "rock";
	} else if(computerChoice == 2) {
		computer = "paper"; 
	} else {
		computer = "scissors";
	}
	
//create variables to store result of game
	double win = 0;
	double lose = 0;
	double tie = 0;
	int count = 0;
	
	//while function to create sentinal loop, determines outcome of game
	//displays result
	//displays game stats 
	//random computer generator function is used again
	//repeat until player hits q
	while(player1 != "q" ) {
	
	int result = whoWon(player1, computer);
	if (result == 1){
		cout << "Computer chose " << computer << ", Player wins!" << endl;
		win = win + 1;
	} else if (result == 2){
			cout << "Computer chose " << computer << ", Computer wins!" << endl;
		lose = lose + 1;
	} else {
		cout << "Computer chose " << computer << ", It's a tie" << endl;
		tie = tie + 1;	
	}
	count++ ;
	cout << "\nWins: " << win <<": " << (win / count) * 100 <<  "%     loses: " << lose <<": " << (lose / (count)) * 100 << "%     ties: " << tie <<": " << (tie / (count)) * 100 << "%" << endl;
	
	computerChoice = randomDieRoll();
	if (computerChoice == 1){
		computer = "rock";
	} else if(computerChoice == 2) {
		computer = "paper"; 
	} else {
		computer = "scissors";
	}
	cout << "\n Enter player's choice: "; //prompt user for player 1 choice
	cin >> player1;
		
	}

	
	return 0;
}
