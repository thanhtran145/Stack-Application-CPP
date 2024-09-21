#pragma once
#include <stack>
#include "BoardSpaces.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int inputInteger(string prompt, int startRange, int endRange);

class n_Queens : public BoardSpaces{
private:
	//STL that calls the BoardSpaces Class
	stack <BoardSpaces> filledSpaces;
	char shiftDirection;
	int firstColumnPermutaions;
	int filled;
	int boardSize;
	bool gameWon;

public:
	//Default constructor
	n_Queens();
	
	//Mutators
	void setBoardSize(int newBoardSize);
	void setFilled(int newFilledAmount);
	//Accessors
	int getBoardSize() const;
	int getFilled() const;
	
	//member function to fill in the board
	void fillBoard();
	//member function to display the board
	void displayBoard(stack<BoardSpaces> filledSpaces) const;

	//member function to get the menu
	void n_QueensMenu();
};