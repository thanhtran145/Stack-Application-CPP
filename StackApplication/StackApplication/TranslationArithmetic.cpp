#include "TranslationArithmetic.h"

//precondition: going to call the default constructor class
//postcondition: going to then intialize the expression 
TranslationArithmetic::TranslationArithmetic() :expression("") {}

//precondition: going to get the expression 
//postcondition: going to return the private expression
string TranslationArithmetic::getExpression() const {
	return expression;
}
//precondition: going to get the new expression
//postcondition: going to set the private expression with the new expression member
void TranslationArithmetic::setExpression(string newExpression) {
	expression = newExpression;
}

//precondition: going to pass in a string expression as our parameter
//postcondition: going to return value indicates that the parenthesis in the given expression are balanced, if not then return value is false
bool TranslationArithmetic::checkParenethesis(string expression) {
	//getting size of the expression;
	int length = expression.size();
	bool failed = false;
	//loop through the string expression
	for (int i = 0; i < length; i++) {
		//if the expression[index] is equal to the left parenthesis, push it to the stack EX: expression[3] has '(' then its eqaul to left parenthesis
		if (expression[i] == '(') {
			//will push everytime there is a left parenthesis
			validExpression.push(expression[i]);
		}
		//else if the expression[index] finds a right parenthesis and the stack is not empty (meaning there is a '(') , pop it  
		else if (expression[i] == ')' && !validExpression.empty()) {
			//if statement that checks if the top() of the stack is left parenthesis '('
			if (validExpression.top() == '(') {
				//will pop the left parenthesis off the stack since there is a right parenthesis
				validExpression.pop();
			}
		}
		//else if there is no '(' in the stack (stack is empty) but there is a ')' then error
		else if (expression[i] == ')' && validExpression.empty()) {
			failed = true;
		}
	}
	//if there is an '(' (left parenthesis) left over in the stack (stack is not empty) because there is a left parenthesis that does not match
	if (!validExpression.empty()) {
		//flag this to true, meaning its an error
		failed = true;
	}
	return failed;
}
//precondition: going to pass in a string that is my expression
//postcondition: going to then return the postfix of the infix using stack and push and pop
string TranslationArithmetic::infixToPostfix(string infix){
	//to hold the postfix 
	string postfix = "";
	//size of the infix expression (input)
	int length = infix.size();

	for (int i = 0; i < length; i++) {
		//if the infix expression is an alphanumeric (letter) or if its a digit (number) or a decimal
		if (isalnum(infix[i]) || isdigit(infix[i]) || infix[i] == '.') {
			//add it to the postfix
			postfix += infix[i];
		}
		else if (infix[i] == '(') {
			trackOperator.push(infix[i]);
		}
		else if (infix[i] == ')') {
			//while the stack is not empty and the stack does not have '(' on top then run this
			while (!trackOperator.empty() && trackOperator.top() != '(') {
				//add the top to the postfix 
				postfix += trackOperator.top();
				//pop it right away so its not in the stack
				trackOperator.pop();
			}
			//if its not empty and left parenthesis is on top then pop it since there is a right parenthesis (they match)
			if (!trackOperator.empty() && trackOperator.top() == '(') {
				trackOperator.pop();
			}
		}
		//else if it has these operators ^, *, / , +, -
		else if (infix[i] == '^' || infix[i] == '*' || infix[i] == '/' || infix[i] == '+' || infix[i] == '-') {
			while (!trackOperator.empty() && trackOperator.top() != '(') {
				//add the operator to the postfix
				postfix += trackOperator.top();
				//pop it so it does not stay
				trackOperator.pop();
			}
			trackOperator.push(infix[i]);
		}
		//else if there is a blank space, add the top()
		else if (infix[i] == ' ') {
			//check that the stack is not empty at first and it does not equal to left parenthesis (don't add it)
			if (!trackOperator.empty() && trackOperator.top() != '(') {
				//add the top() to the postfix 
				postfix += trackOperator.top();
				//pop it right away so it is not there
				trackOperator.pop();
			}
		}
	}
	//loop as long as there are '(' or ')' or any operators in the loop
	while (!trackOperator.empty()) {
		//add it to the postfix
		postfix += trackOperator.top();
		//pop() it so then it can now be empty
		trackOperator.pop();
	}
	return postfix;
}
//precondition: going to print the information
//postcondition: going to create a menu that accepts an infix expressions and checks if the parentheses are balanced
void TranslationArithmetic::menuInformation() {
	system("cls");
	cout << "\n\t2> Translation of Arithmetic Expression";
	cout << "\n\t" << string(82, char(205)) << "\n";
	string express = inputString("\n\tEnter an Infix Expression: ", true);
	//set the expression with the new string
	setExpression(express);
	//if true (pass in the getter that has the expression, its a string)
	if (checkParenethesis(getExpression())) {
		cout << "\n\t\tInfix expression: " << express;
		cout << "\n\t\tPostfix expression: ERROR: inbalanced parentheses.";
	}
	else {
		cout << "\n\t\tInfix expression: " << express;
		cout << "\n\t\tPostfix expression: " << infixToPostfix(express);
	}
	cout << "\n";
}