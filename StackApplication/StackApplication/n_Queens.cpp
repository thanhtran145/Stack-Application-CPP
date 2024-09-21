#include "n_Queens.h"

//precondition:
//postcondition:
bool checkIfConflict(int boardSize, stack<BoardSpaces> filledSpaces, BoardSpaces currentSpace);

//precondition: going to call the default constructor class
//postcondition: going to then intialize the privates variables
n_Queens::n_Queens():shiftDirection('R'),firstColumnPermutaions(0),boardSize(0),filled(0),gameWon(false){}

//precondition: going to get the new boardSize
//postcondition: going to set the private boardSize with the new boardSize member
void n_Queens::setBoardSize(int newBoardSize){
	boardSize = newBoardSize;
}
//precondition: going to get the new filled
//postcondition: going to set the private filled with the new filled member
void n_Queens::setFilled(int newFilledAmount){
	filled = newFilledAmount;
}
//precondition: going to get the boardSize 
//postcondition: going to return the private boardSize
int n_Queens::getBoardSize() const{
	return boardSize;
}
//precondition: going to get the filled 
//postcondition: going to return the private filled
int n_Queens::getFilled() const{
	return filled;
}
//precondition: going to be passing in the boardSize, filledSpaces (the stack)
//postcondition: going to do if statements checking if the board is filled, if not return the position of that row and column
void n_Queens::fillBoard(){
	BoardSpaces currentSpace;
	boardSize = inputInteger("\n\tEnter a number(1..100) of queens: ", 1, 100);
	BoardSpaces userDefinedSpace;
	userDefinedSpace.setRow(1);
	userDefinedSpace.setColumn(inputInteger("\tEnter the column to place the first queen : ", 1, boardSize));
	filledSpaces.push(userDefinedSpace);

	// Move on to the next row after placing the first queen
	currentSpace.setRow(2);
	currentSpace.setColumn(1);

	while (currentSpace.getRow() <= boardSize) {
		if (checkIfConflict(boardSize, filledSpaces, currentSpace)) { // Conflict found
			if (currentSpace.getColumn() < boardSize) { // If not in the last column, try next column
				currentSpace.setColumn(currentSpace.getColumn() + 1);
			}
			else { // If in the last column, backtrack
				do {
					if (filledSpaces.empty()) {
						cout << "\n\tNo Solution Found. " << endl;
						return;
					}
					currentSpace = filledSpaces.top();
					filledSpaces.pop();
				} while (currentSpace.getColumn() == boardSize);

				// Try next column for the queen we backtracked to
				currentSpace.setColumn(currentSpace.getColumn() + 1);
			}
		}
		else { // No conflict
			filledSpaces.push(currentSpace);
			currentSpace.setRow(currentSpace.getRow() + 1);
			currentSpace.setColumn(1);
		}
	}

	displayBoard(filledSpaces);
}
//precondition: going to pass in a stack as a parameter
//postcondition: going to then return the board when it is filled up
void n_Queens::displayBoard(stack<BoardSpaces> filledSpaces) const{
	stack<BoardSpaces> reversedStack;
	stack<BoardSpaces> auxStack;

	// Reverse the filledSpaces stack
	while (!filledSpaces.empty()) {
		reversedStack.push(filledSpaces.top());
		filledSpaces.pop();
	}

	cout << endl << "\t" << boardSize << "-Queens Soulution." << endl;

	// Top border
	cout << "\t" << std::string(1, char(201));
	cout << string(boardSize * 2 + 1, char(205));
	cout << string(1, char(187)) << endl;

	// Display the board
	for (int index = 0; index < boardSize; index++){
		cout << "\t" << string(1, char(186)) << " ";
		for (int j = 0; j < boardSize; j++){
			if (reversedStack.top().getColumn() == (j + 1)){
				cout << 'Q';
			}
			else{
				cout << '-';
			}
			if (j < boardSize - 1){
				cout << string(1, char(179));
			}
		}
		cout << " " << string(1, char(186)) << endl;
		reversedStack.pop();
	}

	// Bottom border
	cout << "\t" << std::string(1, char(200));
	cout << string(boardSize * 2 + 1, char(205));
	cout << string(1, char(188)) << endl;

	// Restore filledSpaces using auxStack
	while (!auxStack.empty()) {
		filledSpaces.push(auxStack.top());
		auxStack.pop();
	}
}
//precondition: going to pass in two stacks as the parameters
//postcondition: going to then return a boolean checking if they are conflict, if not then keep looping through the loop
bool checkIfConflict(int boardSize, stack<BoardSpaces> filledSpaces, BoardSpaces currentSpace){
	stack<BoardSpaces> copyStack = filledSpaces;

	while (!copyStack.empty()) {
		BoardSpaces placedSpace = copyStack.top();

		// Check for column conflict
		if (placedSpace.getColumn() == currentSpace.getColumn()) {
			return true;
		}

		// Check for diagonal conflict
		if (abs(placedSpace.getColumn() - currentSpace.getColumn()) ==
			abs(placedSpace.getRow() - currentSpace.getRow())) {
			return true;
		}

		copyStack.pop();
	}

	return false;
}
//precondition: going to print the information
//postcondition: going to create a menu that shows if the N-Queens board is filled
void n_Queens::n_QueensMenu(){
	system("cls");
	cout << "\n\t3> n_Queens Problem";
	cout << "\n\t" << string(82, char(205)) << "\n";
	fillBoard();
}