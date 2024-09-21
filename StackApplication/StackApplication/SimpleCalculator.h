#pragma once
#include<iostream>
#include<stack>
#include<string>
#include<fstream>
using namespace std;

string inputString(string prompt, bool spaces);

class SimpleCalculator
{
public:
	//Exceptions Class (Throw execption for division with zero)
	class DivisionByZero {
	private:
		string checking;
	public:
		//default constructor
		DivisionByZero();
		//constructor
		DivisionByZero(SimpleCalculator r);
		string toString();
	};
	//default constructor 
	SimpleCalculator();
	string toString();
	void calculatorMenu();
	void displayCalculation(stack<double>& numbers, istream& ins, double& answer, string fileName);
	void evaluateExpression(stack<double>& numbers, int& errorCtr, string fileName);
	int getPrecendence(char operation);
};


