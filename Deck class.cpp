#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;

//playing card class
class PlayingCard {
private:
	//initialize rank and suit, as well as value of the card
	string rank;
	string suit;
	int value;

public:
	//0 arg constructor grabs a random card 
	PlayingCard() {
		const vector<string> rankVec{ "Ace", "2", "3", "4", "5" ,"6", "7", "8", "9", "10", "Jack", "Queen", "king" };
		const vector<string> suitVec{ "Hearts", "Spades", "Clubs", "Diamonds" };
		const vector<int> valueVec{ 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };
		int randomValue = rand() % 13;
		rank = rankVec[randomValue];
		value = valueVec[randomValue];
		randomValue = rand() % 4;
		suit = suitVec[randomValue];
	}

	//two arg constructor, makes the card of rank and suit declared 
	PlayingCard(string _rank, string _suit) {
		const vector<string> rankVec{ "Ace", "2", "3", "4", "5" ,"6", "7", "8", "9", "10", "Jack", "Queen", "king" };
		const vector<int> valueVec{ 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };
		rank = _rank;
		suit = _suit;
		int index = 0;
		while (_rank != rankVec[index]) {
			index++;
		}
		value = valueVec[index];
	}

	//getter functions
	//returns the rank of the card
	string getRank() {
		return rank;
	}

	//returns the suit of the card
	string getSuit() {
		return suit;
	}

	//return value of the car
	int getValue() {
		return value;
	}
};

//create a class named deck
class Deck {
private:
	//initialize a int variable and an array of size 52
	PlayingCard cards[52];
	int count = 51;

public:
	//0 arg constructor
	//creates an entire deck of cards using the playingCard class
	Deck() {
		const vector<string> rankVec{ "Ace", "2", "3", "4", "5" ,"6", "7", "8", "9", "10", "Jack", "Queen", "king" };
		const vector<string> suitVec{ "Hearts", "Spades", "Clubs", "Diamonds" };
		int counter = 0;
		for (int i = 0; i < 3; i++) {
	
			for (int j = 0; j < 12; j++) {
				cards[counter] = PlayingCard(rankVec[j], suitVec[i]);
				counter++;
			}
			counter++;
		}
	}

	//shuffle deck, randomily grabs two card from the array of playing cards and swaps them. repeats 1000 times
	void shuffleDeck() {
		for (int i = 0; i < 1000; i++) {
			int card1, card2;
			card1 = rand() % count + 1;
			card2 = rand() % count + 1;
			PlayingCard tempCard = cards[card1];
			cards[card1] = cards[card2];
			cards[card2] = tempCard;
		}
	}

	//drawcard member function returns the first card in the deck
	//also displays the card that was drawn
	//if all cards were drawn, then the deck is reset.
	PlayingCard drawCard() {
		PlayingCard tempCard = cards[count];
		cout << "You Drew a " << cards[count].getRank() << " of " << cards[count].getSuit() << endl;
		count = count - 1;

		if (count == 0) {
			cout << "All cards have been drawn, resetting the deck!" << endl;
			resetDeck();
		}

		return tempCard;
	}

	//resets deck and shuffles deck
	void resetDeck() {
		count = 51;
		shuffleDeck();
	}
};

int main() {
	//create the deck of cards and name it playingDeck
	Deck playingDeck;
	//shuffle deck
	playingDeck.shuffleDeck();
	//create int to hold userInput for what to do next
	int userInput;

	cout << "Are you ready to play BlackJack?" << endl << endl;
	cout << "Enter 1 to play, 2 to shuffle deck.(0 to quit) ";
	cin >> userInput;
	
	/*
	while loop continues until user quits by entering 0.
	If variable checks whether input is 1 or 2.
	If 1, two cards are drawn and another if loop checks
	for the score of the two cards to be 21. 
	If 2 is entered, the deck is reshuffled at that point.
	*/

	while (userInput != 0) {
		if (userInput == 1) {
			PlayingCard card1 = playingDeck.drawCard();
			PlayingCard card2 = playingDeck.drawCard();
			int score = card1.getValue() + card2.getValue();
			cout << "The score of your cards is " << score << endl;
			if (score == 21) {
				cout << "****You got blackJack***" << endl << endl;
			} else {
				cout << "You did not get black jack" << endl << endl;
			}
		} else if (userInput == 2) {
			playingDeck.shuffleDeck();
		} else {
			cout << "invalid input. Please try again." << endl;
		}
		cout << "Enter 1 to play again, 2 to shuffle deck:(0 to quit) " << endl;
		cin >> userInput;

	}

	system("pause");
	return 0;
}