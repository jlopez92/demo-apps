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
	
	vector<PlayingCard *> cards;
	int count = 52;

public:
	//0 arg constructor
	//creates an entire deck of cards using the playingCard class
	Deck() {
		const vector<string> rankVec{ "Ace", "2", "3", "4", "5" ,"6", "7", "8", "9", "10", "Jack", "Queen", "king" };
		const vector<string> suitVec{ "Hearts", "Spades", "Clubs", "Diamonds" };
		int counter = 0;
		for (int i = 0; i < 4; i++) {

			for (int j = 0; j < 13; j++) {
				cards.push_back(new PlayingCard(rankVec[j], suitVec[i]));
				counter++;
			}
			counter++;
		}
		count = cards.size();
	}

	//shuffle deck, randomily grabs two card from the array of playing cards and swaps them. repeats 1000 times
	void shuffleDeck() {
		for (int i = 0; i < 1000; i++) {
			int card1, card2;
			card1 = rand() % count;
			card2 = rand() % count;
			PlayingCard* tempCard = cards[card1];
			cards[card1] = cards[card2];
			cards[card2] = tempCard;
		}
	}

	//drawcard member function returns the first card in the deck
	//also displays the card that was drawn
	//if all cards were drawn, then the deck is reset.
	PlayingCard drawCard() {
		PlayingCard *tempCard = cards.back();
		cout << "You Drew a " << cards.back()->getRank() << " of " << cards.back()->getSuit() << endl;
		cards.pop_back();
		count--;
		if (count == 0) {
			cout << "All cards have been drawn, resetting the deck!" << endl;
			
		}

		return *tempCard;
	}

	void returnCard(PlayingCard* _return) {
		cards.push_back(_return);
		shuffleDeck();
	}


};

class Hand {
private:
	vector<PlayingCard*> yourCards;
	int count;
public:
	Hand() {
		//yourCards.push_back(_newCard);
		count = yourCards.size();
		cout << "empty hand created" << endl;
	}

	void addCard(PlayingCard* _newCard) {
		yourCards.push_back(_newCard);
	
	}

	void removeCard(Deck yourDeck, int _card) {
		yourDeck.returnCard(yourCards[_card]);
		yourCards.erase(yourCards.begin() + _card);
	}

	void removeAllCards(Deck yourDeck) {
		for (int i = 0; i < count; i++) {
			yourDeck.returnCard(yourCards.back());
			yourCards.pop_back();
		}
	}

	void displayHand() {
		cout << "Your Cards" << yourCards.size() << endl;
		for (int i = 0; i < count; i++) {
			cout << "Card " << i << " is a " << &yourCards[i]->getRank() << " of " << &yourCards[i]->getSuit() << endl;
		}
	}

};

int main() {
	//create the deck of cards and name it playingDeck

	Deck playingDeck;

	//shuffle deck
	playingDeck.shuffleDeck();
	Hand Hand;
	
	//create int to hold userInput for what to do next
	for (int i = 0; i < 7; i++) {
		PlayingCard card = playingDeck.drawCard();
		PlayingCard* ptr = new PlayingCard(card);
		Hand.addCard(ptr);
	}
	int userInput;

	cout << "menu: 1 to draw a card		 2:shuffle deck		3:return card		4: return all cards		5: display hand		0: quit) " << endl;
	cout << "What would you like to do?" << endl;
	cin >> userInput;

	while (userInput != 0) {
		if (userInput == 1) {
			PlayingCard card = playingDeck.drawCard();
			PlayingCard* ptr = new PlayingCard(card);
			Hand.addCard(ptr);

		}
		else if (userInput == 2) {
			playingDeck.shuffleDeck();
		}
		else if (userInput == 3) {
			Hand.displayHand();
			cout << "Which card would you like to remove? ";
			int remove;
			cin >> remove;
			Hand.removeCard(playingDeck, remove);
		}
		else if (userInput == 4) {
			Hand.removeAllCards(playingDeck);
		}
		else if (userInput == 5) {
			Hand.displayHand();
		}
		else {
			cout << "invalid input. Please try again." << endl;
		}
		cout << "menu: 1 to draw a card		 2:shuffle deck		3:return card		4: return all cards		5: display hand		0: quit) " << endl;
		cout << "What would you like to do?" << endl;
		cin >> userInput;

	}

	system("pause");
	return 0;
}