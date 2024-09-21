#pragma once
#include<iostream>
#include<stack>
#include<string>
using namespace std;

string inputString(string prompt, bool spaces);

class TranslationArithmetic 
{
private:
	
	stack<char> validExpression;
	stack<char> trackOperator;
	string expression;

public:

	//default constructor
	TranslationArithmetic();

	//Accesors)
	string getExpression() const;
	//Mutators)
	void setExpression(string newExpression);

	//member functions
	bool checkParenethesis(string expression);
	string infixToPostfix(string infix);
	void menuInformation();
};