#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std; 

#include "PlayingCard.h"

int main() {
	cout << "Playing card war" << endl;
	cout << "****************\n" << endl;

	//initialize two int variables with zero values to hold player and computer score
	int computer = 0;
	int player = 0;

	//initialize two int variables to hold current card values
	int cardValue, card2Value;
	cout << "Press any key to draw a card ";
	system("pause");

	//while loop to iterate through game rounds until one player gets 100 points
	while (computer < 100 && player < 100) {
		//create a card object and display info
		PlayingCard card;
		cout << "\nYou drew a " << card.getRank() << " of " << card.getSuit() << "." << endl;
		cout << "Card value: " << card.getValue() << endl;
		cardValue = card.getValue();

		//create second card object and display info
		PlayingCard card2;
		cout << "\nComputer drew a " << card2.getRank() << " of " << card2.getSuit() << "." << endl;
		cout << "Card value: " << card2.getValue() << endl;
		card2Value = card2.getValue();
		
		//if state to see if player or computer won round, add points to winners total
		if (cardValue > card2Value) {
			cout << "******Player 1 wins round*******" << endl;
			player = player + cardValue + card2Value;
		}
		else if (cardValue == card2Value) {
			cout << "*****Tie*****" << endl;
			player = player + cardValue;
			computer = computer + card2Value;
		}
		else {
			cout << "*****Computer wins round******" << endl;
			computer = computer + cardValue + card2Value;
		}

		//display current scores
		cout << "Scores...." << endl;
		cout << "Player: " << player << endl;
		cout << "Computer:" << computer << endl;
		system("pause");
	}
	//display winner after a player hits 100
	if (player > computer) {
		cout << "*******Player has won*******" << endl;
	}
	else {
		cout << "******Computer has won*******" << endl;
	}
	system("pause");
	return 0;
}