#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<cctype>
#include<ctime>
#include<cstdlib>
using namespace std;

//void function prints a header to the display screen(ascii)
void printHeader(){
	cout << "H   H     A     N   N GGGGG MMMMMMMMMMM     A     N   N" << endl;
	cout << "H   H    A A    NN  N G     M    M    M    A A    NN  N" << endl;
	cout << "HHHHH   AAAAA   N N N G GGG M    M    M   AAAAA   N N N" << endl;
	cout << "H   H  A     A  N  NN G   G M    M    M  A     A  N  NN" << endl;
	cout << "H   H A       A N   N GGGGG M    M    M A       A N   N" << endl;
	
	
}

//void function holds ASCII that prints the hangman art for zero wrong guesses
void printHangman0(){
	cout << "+--------" << endl;
	cout << "+       |" << endl;
	cout << "+       |" << endl;
	cout << "+      " << endl;
	cout << "+     " << endl;
	cout << "+      " << endl;
	cout << "+     " << endl;
	cout << "+" << endl;
	cout << "+" << endl;
	cout << "________________" << endl;
}

//void function holds ASCII that prints the hangman art for one wrong guesses
void printHangman1(){
	cout << "+--------" << endl;
	cout << "+       |" << endl;
	cout << "+       |" << endl;
	cout << "+       O" << endl;
	cout << "+      " << endl;
	cout << "+       " << endl;
	cout << "+      " << endl;
	cout << "+" << endl;
	cout << "+" << endl;
	cout << "________________" << endl;
}

//void function holds ASCII that prints the hangman art for two wrong guesses
void printHangman2(){
	cout << "+--------" << endl;
	cout << "+       |" << endl;
	cout << "+       |" << endl;
	cout << "+       O" << endl;
	cout << "+       |" << endl;
	cout << "+       |" << endl;
	cout << "+      " << endl;
	cout << "+" << endl;
	cout << "+" << endl;
	cout << "________________" << endl;
}

//void function holds ASCII that prints the hangman art for three wrong guesses
void printHangman3(){
	cout << "+--------" << endl;
	cout << "+       |" << endl;
	cout << "+       |" << endl;
	cout << "+       O" << endl;
	cout << "+       |" << endl;
	cout << "+       |" << endl;
	cout << "+        \\" << endl;
	cout << "+" << endl;
	cout << "+" << endl;
	cout << "________________" << endl;
}

//void function holds ASCII that prints the hangman art for four wrong guesses
void printHangman4(){
	cout << "+--------" << endl;
	cout << "+       |" << endl;
	cout << "+       |" << endl;
	cout << "+       O" << endl;
	cout << "+       |" << endl;
	cout << "+       |" << endl;
	cout << "+      / \\" << endl;
	cout << "+" << endl;
	cout << "+" << endl;
	cout << "________________" << endl;
}

//void function holds ASCII that prints the hangman art for five wrong guesses
void printHangman5(){
	cout << "+--------" << endl;
	cout << "+       |" << endl;
	cout << "+       |" << endl;
	cout << "+       O" << endl;
	cout << "+      /|" << endl;
	cout << "+       |" << endl;
	cout << "+      / \\" << endl;
	cout << "+" << endl;
	cout << "+" << endl;
	cout << "________________" << endl;
}

//void function holds ASCII that prints the hangman art for six wrong guesses
void printHangman6(){
	cout << "+--------" << endl;
	cout << "+       |" << endl;
	cout << "+       |" << endl;
	cout << "+       O" << endl;
	cout << "+      /|\\" << endl;
	cout << "+       |" << endl;
	cout << "+      / \\" << endl;
	cout << "+" << endl;
	cout << "+" << endl;
	cout << "________________" << endl;
}

//struct that holds the values needed for each game
struct game {
	string word; //string variable holds the word or phrase to be guessed
	string dashedWord; //string variable holds the dashed version of the word to be guessed
	vector<char> wrongLetters; //string vector holds the incorrect words that have been tried
	vector<char> rightLetters; //string vector holds the correct letters that have been tried
	int guessCount; //int variable holds the number of guesses attempted 
};

//string function grabs the hangman words from a file
//stores all words or phrases into a string vector
//randomily chooses a word from the vector and returns the word as a string
string hangmanWords(){
	vector<string> hangmanWords; //create vector to store hangman words
	ifstream inFile("file.txt"); //open and read file.txt file which holds hangman words
	string word;//string variable that holds each word
	while(getline(inFile, word)) { 	//geline grabs each line from the file and stores it in the word variable
		hangmanWords.push_back(word); //the word is added to the hangmanWords vector
	}
	srand(time(0)); //seed randomization
	int random = rand() % hangmanWords.size(); // int variable that grabs a random integer, between 1 and hangman words vector size
	word = hangmanWords[random - 1]; // grab a random word from the vector(random - 1 used for index = 0) and stores in word variable
	return word; //return the word as a string
}

//string function to convert the word or phrase into dashes and returns the dashed word
//the input parameter is a string 
string makeDashes(string word){ 
	string dashedWord = "-"; //declare and initiate the dashed word variable with a -
	for(int index = 1; index < word.length(); index++){ //iterate through the word length and begin at index = 1, first dash already done at initialization
		//if statement to check whether value in word is alphabetic or a space
		if(isalpha(word[index])){ 
			dashedWord = dashedWord + "-";//if alphabetic, a dash is added to dashed word
		} else {
			dashedWord = dashedWord + " ";//if not, a space is added to dashed word
		}
	}
	
	return dashedWord;//return dashedword as a string
}

//void function for each letter guess
//parameters are an instance of the game struct and a character
void letterGuess(game& startGame, char guess){
	string word = startGame.word; //string variable holds the word to guess
	string oldDashed = startGame.dashedWord;//string variable holds the dashedword before the attempt is tested
	
	for(int index = 0; index < word.length(); index++) { //iterate through each character in the word, test against guess
		if (tolower(word[index]) == tolower(guess)){ //checks the guess to the word index, all changed to lowercase for test.
			startGame.dashedWord[index] = word[index];	//if the word index is the same as the guess character, the dash is replaced by correct letter guess
		} 
	}

	//check if old dashed is equal to new dashed
	//if true, then the user guessed an incorrect value
	//if correct, the user guessed a correct value
	if(oldDashed == startGame.dashedWord){ 
		startGame.guessCount++; //each incorrect guess, increases guess count
		cout << "\nThat is incorrect, your current wrong guesses are: " << startGame.guessCount << endl << endl;//display incorrect guesses
		startGame.wrongLetters.push_back(guess);
	} else {
		cout << "\nCorrect\n" << endl;
		startGame.rightLetters.push_back(guess);
	}
}

//void function for a word guess
//parameters are an instance of the game and a string with the guess
void wordGuess(game& startGame, string guess){
	int incorrect = 0; // int variable changes if any characters in guess are wrong
	for(int index = 1; index < startGame.word.length(); index++){ //for statement loops through the characters in the word
		if(tolower(startGame.word[index]) != tolower(guess[index])){ //if statement compares each character in the word to the guessed phrase. (lowercases the letters)
			incorrect = incorrect + 1; //if a character does not match up to the word character, incorrect counter increases by 1
		} 
	}
	if(incorrect != 0){ //if statement checks no errors were in guessed phrase.
		startGame.guessCount = startGame.guessCount + 1; //if errors are present, guess count increases by 1
		cout << "\n-That is incorrect, your current wrong guesses are: " << startGame.guessCount << endl<< endl;
	} else {
			startGame.dashedWord = startGame.word; //if no errors in guess, dashed word is replaced by the word or phrase
		}
}

//bool function is used to test the the dashed word to the guessed word
//parameter is an instance of game
bool wordTest(game startGame){
	if(startGame.word == startGame.dashedWord){//if statement tests word with dashed for equality
		return true; //if equal return true
	}
	return false;//if not equal return false
}

//bool function creates a new game
//calls function to grab a word and stores all information in a struct 
//iterates through guesses and checks until all guesses are used or the word is guessed
//if win, returns true, else returns false
bool newGame(){
	game startGame;//initiate a new instance of game called start game
	startGame.word = hangmanWords(); //calls function to grab new word, stores in the startGame struct 
	startGame.dashedWord = makeDashes(startGame.word); //calls function to make word into dashed word, stores in struct
	startGame.guessCount = 0; //set guess count = 0
	char attempt; //char attempt used to hold a users guessed letter
	string wordAttempt;//holds the word guess attempt
	while(startGame.guessCount < 6){ //while statment loops until guess count is equal to 6
		string userInput; //userInput variable to hold whether user wants to guess letter or word
		if(startGame.guessCount == 0){ //if statment to find the appropriate hangman ascii based on the guess count
			printHangman0();
		} else if(startGame.guessCount == 1){
			printHangman1();
		} else if(startGame.guessCount == 2){
			printHangman2();
		} else if(startGame.guessCount == 3){
			printHangman3();
		} else if(startGame.guessCount == 4){
			printHangman4();
		} else if(startGame.guessCount == 5){
			printHangman5();
		} else {
			printHangman6();
		}
		
		cout << "\nThe phrase or word is:              " << startGame.dashedWord << endl;
		cout << "\nIncorrect letters: ";
		for(int index = 0; index < startGame.wrongLetters.size(); index++){ //for statement loops and outputs the incorrect letters guessed
			cout << startGame.wrongLetters[index] << ", ";
		}
		cout << "\nCorrect letters: ";
		for(int index = 0; index < startGame.rightLetters.size(); index++){ //for statement loops and outputs the correct letters guessed
			cout << startGame.rightLetters[index] << ", ";
		}
		cout << endl;
		cout << "\nWould you like to guess a letter, or guess the phrase?(letter or phrase): "; //prompt user for letter or phrase guess
		cin >> userInput; //store in userinput
		if(userInput == "letter"){ //if letter chosen
			cout << startGame.dashedWord << endl;
			cout << "letter guess: "; //prompt user for letter guess
			cin >> attempt; //store in attempt
			letterGuess(startGame, attempt); //pass to function to check for correct letter guessed
		} else if(userInput == "phrase"){ //if phrase chosen
			cout << startGame.dashedWord << endl;
			cout << "word or phrase guess: "; //prompt user for phrase or word
			cin.ignore(); //ignore to be able to store phrase
			getline(cin, wordAttempt); //stores phrase in wordAttempt
			wordGuess(startGame, wordAttempt);	//pass	to wordGuess function to check the guess vs answer	
		} else {
			cout << "That is not a correct entry, input either phrase or letter" << endl;//error handling if user did not input either letter or phrase when prompted
		}
	
		if (wordTest(startGame)){//test the word function
		cout << "The word was: " << startGame.word << endl;
			return true; //if true, returns true
		}
	
	}
	
	printHangman6();
	cout << "You lost, the word was: " << startGame.word << endl;
	return false; //returns false once all guesses have been attempted in while statement above
}


int main(){
	//print the logo for the game, followed but a new line
	printHeader();
	cout << endl;

	
	cout << "Time to play Hangman!!!\n*********************\n" << endl;
	cout << "Are you ready to start playing hangman?(enter yes or no) ";//prompt user if he wants to play or not
	string userInput;
	cin >> userInput;//store answer in variable
	int wins = 0; //declare and initiate a win variable 
	int losses = 0; //declare and initiate a lose variable
	
	while(userInput != "no" && userInput != "No"){ //while the user does not input no, the loop will continue
		if(userInput == "yes" || userInput == "Yes"){ //if user says yes, game will initiate
			cout << "\n*****Time to Play!\n" << endl;
			bool result = newGame(); //call newgame function store return in result
			if(result == true){ //if game was won
				cout << "You won\n" << endl;
				wins++; //wins is increased by 1
			} else { //else losses is increased by 1
				losses++;
			}
		} else { //if user did not enter yes or no, loop repeats to gather correct input
			cout << "You entered an invalid answer! Please type Yes or No to play hangman" << endl;
		}
		cout << "wins: " << wins << "\nLosses: " << losses << endl << endl; //display wins and losses
		cout << "Do you want to play hangman? "; //prompt user for whether they want to play again
		cin >> userInput;
	}
	
	
	
	return 0;
}
