#include<iostream>
#include<cmath>
#include<vector>
#include <time.h>
#include<stdio.h>     
#include<stdlib.h> 
#include<iomanip>
using namespace std;

//defines new datatype, pair as a pair of ints
//Pair will hold x and y point
typedef pair<int, int> Pair;
typedef pair<double, pair<int, int>> pPair;


//simple queue class with vector operating as list
//template allows list to be of any data type.
template <typename T>
class Queue {
private:
	vector<T> list;
	int count;
public:
	Queue() {
		count = 0;
	}

	void push(T x) {
		list.push_back(x);
		count++;
	}

	T pop() {
		T value = list[0];
		list.erase(list.begin());
		count--;
		return value;
	}

	bool isEmpty() {
		if (list.empty()) {
			return true;
		}
		else {
			return false;
		}
	}
};

//simple stack class with basic functions
//allows for any datatype to be held in list
template <typename T>
class stack {
private:
	vector<T> list;
	int count;
public:
	stack() {
		count = 0;
	}

	void insert(T x) {
		list.push_back(x);
		count++;
	}

	T remove() {
		T value = list[count - 1];
		list.pop_back();
		count--;
		return value;
	}

	bool isEmpty() {
		if (list.empty()) {
			return true;
		}
		else {
			return false;
		}
	}
};

//cell will hold the x and y value in which the path came from
//f, g, and h are used to calculate the best path
class cell {
public:
	int x, y;
	double f, g, h;
	cell() {
	}
};

class grid {
	//gridsize variable will hold the size of the 2D matrix
	//pair variables will hold position of the start and goal
	int gridSize;
	int** matrix;
	Pair start, goal;

public:

	//initialize grid that is x by x size
	//create the matrix and initialize all values in matrix to 1
	//1 indicates open space
	//0 will indicate road block
	grid(int x) {
		gridSize = x;
		matrix = new int * [gridSize];
		for (int i = 0; i < gridSize; i++)
		{
			matrix[i] = new int[gridSize];
		}
		for (int i = 0; i < gridSize; i++) {
			for (int j = 0; j < gridSize; j++) {
				matrix[i][j] = 1;
			}
		}
	}

	//print starting matrix 
	void printMatrix(){
		for (int i = 0; i < gridSize; i++) {
			for (int j = 0; j < gridSize; j++) {
				if (i == goal.first && j == goal.second) {
					cout << "G" << " ";
				} else if (i == start.first && j == start.second) {
					cout << "P" << " ";
				} else if (matrix[i][j] == 2) {
					cout << "*" << " ";
				} else if (matrix[i][j] == 0) {
					cout << "B" << " ";
				} else  {
					cout << "_ ";
				}
			}
			cout << endl;
			
		}
	}

	//Function creates specified number of road blocks randomly throughout board
	void numberOfBlocks(int x) {
		for (int k = 0; k < x; k++) {
			int i = rand() % gridSize;
			int j = rand() % gridSize;
			matrix[i][j] = 0;
		}
	}

	//function adds goal position, assures position is not a road block
	//assigns value to goal position as a pair of ints 
	void addGoal() {
		int i = rand() % gridSize;
		int j = rand() % gridSize;
		while (matrix[i][j] == 0) {
			i = rand() % gridSize;
			j = rand() % gridSize;
		}
		goal = make_pair(i, j);
	}

	//function repeats the method used to add goal point to matrix
	void addStart() {
		int i = rand() % gridSize;
		int j = rand() % gridSize;
		while (matrix[i][j] == 0) {
			i = rand() % gridSize;
			j = rand() % gridSize;
		}
		start = make_pair(i, j);
	}

	//bool function checks if the goal has been reached, input is x and y
	bool goalReached(int x, int y) {
		if (x == goal.first && y == goal.second) {
			return true;
		} else {
			return false;
		}
	}

	//bool confirms x and y are within the grid
	//used in cases where we are traversing near edge of grid
	bool isValid(int x, int y)
	{
		if (x >= 0 && x < gridSize && y >= 0 && y < gridSize) {
			return true;
		}
		return false;
	}

	//isUnBlocked checks whether a given position has a road block
	bool isUnBlocked(int x, int y)
	{
		if (matrix[x][y] == 1) {
			return (true);
		} else {
			return (false);
		}
	}

	//printPath prints the path traversed by a_star_search
	//denotes visited positions with a *
	void printPath( bool** closedList) {
		//creating a temp matrix, copying matrix values over
		//adding positions visited from closedList
		int** tempMatrix;
		tempMatrix = new int* [gridSize];
		for (int i = 0; i < gridSize; i++)
		{
			tempMatrix[i] = new int[gridSize];
		}
		for (int i = 0; i < gridSize; i++) {
			for (int j = 0; j < gridSize; j++) {
				tempMatrix[i][j] = matrix[i][j];
			}
		}
		for (int i = 0; i < gridSize; i++) {
			for (int j = 0; j < gridSize; j++) {
				if (closedList[i][j] == true) {
					tempMatrix[i][j] = 2;
				}
			}
		}

		//printing resulting tempMatrix
		cout << endl << "Printing visited locations on matrix denoted by *" << endl;
		for (int i = 0; i < gridSize; i++) {
			for (int j = 0; j < gridSize; j++) {
				if (i == goal.first && j == goal.second) {
					cout << "G" << " ";
				}
				else if (i == start.first && j == start.second) {
					cout << "P" << " ";
				}
				else if (tempMatrix[i][j] == 2) {
					cout << "*" << " ";
				}
				else if (tempMatrix[i][j] == 0) {
					cout << "B" << " ";
				}
				else {
					cout << "_ ";
				}
			}
			cout << endl;
		}
		cout << endl;
	}

	//printBestPath prints the matrix, with the best path to goal
	//denoted using *'s
	void printBestPath(stack<Pair> Path){
		int** tempMatrix;
		printMatrix();
		tempMatrix = matrix;

		while (!Path.isEmpty())
		{
			pair<int, int> p = Path.remove();
			tempMatrix[p.first][p.second] = 2;
		}

		cout << endl << "Displaying best path denoted by *." << endl;
		for (int i = 0; i < gridSize; i++) {
			for (int j = 0; j < gridSize; j++) {
				if (i == goal.first && j == goal.second) {
					cout << "G" << " ";
				} else if (i == start.first && j == start.second) {
					cout << "P" << " ";
				} else if (tempMatrix[i][j] == 2) {
					cout << "*" << " ";
				} else if (tempMatrix[i][j] == 0) {
					cout << "B" << " ";
				} else {
					cout << "_ ";
				}
			}
			cout << endl;
		}
	}

	//tracePath uses the cellDetails array to print the best path to the goal
	//additional information is printed in multiple 2D matrices
	void tracePath(cell** cellDetails)
	{
		//printing out each .x and .y position for every cell in 2D matrix
		cout << "Printing matrix of parent cell locations" << endl;
		for (int i = 0; i < gridSize; i++) {
			for (int j = 0; j < gridSize; j++) {
				cout << "(" << cellDetails[i][j].x << "," << cellDetails[i][j].y << ")" << " ";
			}
			cout << endl;
		}
		cout << endl;

		//printing the f values for every cell
		cout << "Printing f value for each cell" << endl;
		for (int i = 0; i < gridSize; i++) {
			for (int j = 0; j < gridSize; j++) {
				cout << cellDetails[i][j].f << " ";
			}
			cout << endl;
		}
		cout << endl;

		int row = goal.first;
		int col = goal.second;

		//creating the best path based on info from cellDetails matrix
		stack<Pair> Path;
		while ((start.first != row || start.second != col))
		{
			Path.insert(make_pair(row, col));
			int temp_row = cellDetails[row][col].x;
			int temp_col = cellDetails[row][col].y;
			row = temp_row;
			col = temp_col;
		}
		Path.insert(make_pair(row, col));

		//use printBestPath to show matrix
		printBestPath(Path);

		//print each individual location of path taken
		cout << "\nThe best path is: " << endl;
		while (!Path.isEmpty())
		{
			pair<int, int> p = Path.remove();
			cout << "( " << p.first << ", " << p.second << ")" << endl; 
		}

		return;
	}

	//calculating the H value which is based on distance from cell position to goal
	//distance formula used
	double calculateHValue(int x, int y)
	{
		double h_Value = ((double)sqrt((x - goal.first) * (x - goal.first) + (y - goal.second) * (y - goal.second)));
		return h_Value;
	}

	//a_star_search algorithm
	void a_Star_Search() {
		
		//checks if the goal and start position are the same, if so we are done
		if (goalReached(start.first, start.second)) {
			cout << "The start point is already at the goal." << endl;
			return;
		}

		//creating a closedList matrix which holds the positions visited
		//this is a bool, all values initially set to false
		int row = gridSize;
		int col = gridSize;
		bool** closedList;
		closedList = new bool* [row];
		for (int i = 0; i < gridSize; i++)
		{
			closedList[i] = new bool[col];
		}
		for (int i = 0; i < gridSize; i++) {
			for (int j = 0; j < gridSize; j++) {
				closedList[i][j] = false;
			}
		}

		//creating a cellDetails matrix that will hold info from every cell position
		cell** cellDetails;
		cellDetails = new cell * [row];
		for (int i = 0; i < gridSize; i++)
		{
			cellDetails[i] = new cell[col];
		}

		//adding starting info for every cell
		//f, g, and h values all set to max value
		//this will allow cost of road block to be too high, resulting in bad path
		//x and y will be set to -1 for positions not visited in path
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cellDetails[i][j].f = FLT_MAX;
				cellDetails[i][j].g = FLT_MAX;
				cellDetails[i][j].h = FLT_MAX;
				cellDetails[i][j].x = -1;
				cellDetails[i][j].y = -1;
			}
		}

		int i, j;
		// updating the start cell position, initial f is 0
		i = start.first, j = start.second;
		cellDetails[i][j].f = 0.0;
		cellDetails[i][j].g = 0.0;
		cellDetails[i][j].h = 0.0;
		cellDetails[i][j].x = i;
		cellDetails[i][j].y = j;

		//queue list will hold a list pair of a double for the f value 
		//and a pair of positions for the new positions current
		Queue<pPair> openList;
		openList.push(make_pair(0.0, make_pair(i, j)));

		//a bool function set to false until path is found
		bool goalAchieved = false;
		
		//while values are in the openList, the while function will keep operating
		while (!openList.isEmpty()) {

			//popping the openlist value
			pPair p = openList.pop();
			i = p.second.first;
			j = p.second.second;

			//setting the position of the popped location into the closed visited list
			closedList[i][j] = true;

			//variables to update cell values 
			double gNew, hNew, fNew;
			
			//if position north of current value is available, enter if statement
			if (isValid(i - 1, j)) {

				//check goalReached function
				if (goalReached(i - 1, j))
				{
					//if goal reached, update values in goal cell
					gNew = cellDetails[i][j].g + 1.0;
					hNew = calculateHValue(i - 1, j);
					fNew = gNew + hNew;
					cellDetails[i - 1][j].f = fNew + 1;
					cellDetails[i - 1][j].g = gNew;
					cellDetails[i - 1][j].h = hNew;\
					cellDetails[i - 1][j].x = i;
					cellDetails[i - 1][j].y = j;
					cout << "Goal achieved!" << endl;
					//print the paths along with info on how it was achieved
					printPath(closedList);
					tracePath(cellDetails);
					goalAchieved = true;
					return;
				}
				//else check if position hasn't already been visited 
				//and whether it is not a road block
				else if (closedList[i - 1][j] == false && isUnBlocked(i - 1, j) == true)
				{ 
					//calculate g, h, and f values
					gNew = cellDetails[i][j].g + 1.0;
					hNew = calculateHValue(i - 1, j);
					fNew = gNew + hNew;

					//update openlist if value is not their by checking f value
					if (cellDetails[i - 1][j].f == FLT_MAX || cellDetails[i - 1][j].f > fNew)
					{
						//push new f value and the location to openList 
						// Update cell details
						openList.push(make_pair(fNew, make_pair(i - 1, j)));
						cellDetails[i - 1][j].f = fNew;
						cellDetails[i - 1][j].g = gNew;
						cellDetails[i - 1][j].h = hNew;
						cellDetails[i - 1][j].x = i;
						cellDetails[i - 1][j].y = j;
					}
				}
			}
			//************repeat same as above for south location***************
			if (isValid(i + 1, j)) {
				if (goalReached(i + 1, j))
				{
					gNew = cellDetails[i][j].g + 1.0;
					hNew = calculateHValue(i + 1, j);
					fNew = gNew + hNew;
					cellDetails[i + 1][j].f = fNew + 1;
					cellDetails[i + 1][j].g = gNew;
					cellDetails[i + 1][j].h = hNew;
					cellDetails[i + 1][j].x = i;
					cellDetails[i + 1][j].y = j;
					printf("The destination cell is found\n");
					printPath(closedList);
					tracePath(cellDetails);
					goalAchieved = true;
					return;
				}
				else if (closedList[i + 1][j] == false && isUnBlocked(i + 1, j) == true)
				{
					gNew = cellDetails[i][j].g + 1.0;
					hNew = calculateHValue(i + 1, j);
					fNew = gNew + hNew;
					if (cellDetails[i + 1][j].f == FLT_MAX || cellDetails[i + 1][j].f > fNew)
					{
						openList.push(make_pair(fNew, make_pair(i + 1, j)));
						cellDetails[i + 1][j].f = fNew;
						cellDetails[i + 1][j].g = gNew;
						cellDetails[i + 1][j].h = hNew;
						cellDetails[i + 1][j].x = i;
						cellDetails[i + 1][j].y = j;
					}
				}
			}
			//************repeat same as above for east location***************
			if (isValid(i, j + 1)) {
				if (goalReached(i, j + 1))
				{
					gNew = cellDetails[i][j].g + 1.0;
					hNew = calculateHValue(i, j + 1);
					fNew = gNew + hNew;
					cellDetails[i][j + 1].f = fNew + 1;
					cellDetails[i][j + 1].g = gNew;
					cellDetails[i][j + 1].h = hNew;
					cellDetails[i][j + 1].x = i;
					cellDetails[i][j + 1].y = j;
					printf("The destination cell is found\n");
					printPath(closedList);
					tracePath(cellDetails);
					goalAchieved = true;
					return;
				}
				else if (closedList[i][j + 1] == false && isUnBlocked(i, j + 1) == true)
				{
					gNew = cellDetails[i][j].g + 1.0;
					hNew = calculateHValue(i, j + 1);
					fNew = gNew + hNew;
					if (cellDetails[i][j + 1].f == FLT_MAX || cellDetails[i][j + 1].f > fNew)
					{
						openList.push(make_pair(fNew, make_pair(i, j + 1)));
						cellDetails[i][j + 1].f = fNew;
						cellDetails[i][j + 1].g = gNew;
						cellDetails[i][j + 1].h = hNew;
						cellDetails[i][j + 1].x = i;
						cellDetails[i][j + 1].y = j;
					}
				}
			}
			//************repeat same as above for west location***************
			if (isValid(i, j - 1)) {
				if (goalReached(i, j - 1))
				{
					gNew = cellDetails[i][j].g + 1.0;
					hNew = calculateHValue(i, j - 1);
					fNew = gNew + hNew;
					cellDetails[i][j - 1].f = fNew + 1;
					cellDetails[i][j - 1].g = gNew;
					cellDetails[i][j - 1].h = hNew;
					cellDetails[i][j - 1].x = i;
					cellDetails[i][j - 1].y = j;
					printf("The destination cell is found\n");
					printPath(closedList);
					tracePath(cellDetails);
					goalAchieved = true;
					return;
				}
				else if (closedList[i][j - 1] == false && isUnBlocked(i, j - 1) == true)
				{ 
					gNew = cellDetails[i][j].g + 1.0;
					hNew = calculateHValue(i, j - 1);
					fNew = gNew + hNew;
					if (cellDetails[i][j - 1].f == FLT_MAX || cellDetails[i][j - 1].f > fNew)
					{
						openList.push(make_pair(fNew, make_pair(i, j - 1)));
						cellDetails[i][j - 1].f = fNew;
						cellDetails[i][j - 1].g = gNew;
						cellDetails[i][j - 1].h = hNew;
						cellDetails[i][j - 1].x = i;
						cellDetails[i][j - 1].y = j;
					}
				}
			}
		}

		//if goal is not reached, print matrix along with visited matrix
		printMatrix();
		cout << endl;
		printPath(closedList);
		cout << endl;
		if (goalAchieved == false) {
			cout << "Goal was not reached" << endl;
		}
	}
};

int main() {
	//randomize seed
	srand(time(NULL));
	cout << setprecision(4);

	//create an instance of the game field
	cout << "do you want to create a new field? ";
	string userInput;
	cin >> userInput;
	while (userInput == "yes") {
		int gridSize, numberOfBlocks;
		cout << "Enter the size of the grid: ";
		cin >> gridSize;
		cout << "Enter the number of road blocks you want in the grid: ";
		cin >> numberOfBlocks;

		//creating 2D matrix, adding road blocks, a goal and start point
		grid gameField(gridSize);
		gameField.numberOfBlocks(numberOfBlocks);
		gameField.addGoal();
		gameField.addStart();
		
		//printing matrix
		cout << endl;
		gameField.printMatrix();

		//running a star search on matrix
		cout << endl << "running a* search on matrix..." << endl;
		gameField.a_Star_Search();
		cout << "do you want to create a new field?";
		cin >> userInput;
	}

	cout << "Thanks for checking out my program." << endl;
	cout << "Credit to redblobsgame and geeks for geeks for assistance with this program" << endl;

	return 0;
}