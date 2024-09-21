#include "BoardSpaces.h"

//precondition: going to call the default constructor class to call the privates
//postcondition: going to then intialize the row and column  
BoardSpaces::BoardSpaces() :row(1), column(0) {};

//precondition: going to get the new row
//postcondition: going to set the private row with the new row member
void BoardSpaces::setRow(int newRow){
	row = newRow;
}
//precondition: going to get the new column
//postcondition: going to set the private column with the new column member
void BoardSpaces::setColumn(int newColumn){
	column = newColumn;
}
//precondition: going to get the row 
//postcondition: going to return the private row
int BoardSpaces::getRow() const{
	return row;
}
//precondition: going to get the column 
//postcondition: going to return the private column
int BoardSpaces::getColumn() const{
	return column;
}