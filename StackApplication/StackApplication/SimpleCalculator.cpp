#include "SimpleCalculator.h"

//precondition: going to call the ZeroDenominator class
//postcondition: going to put it as a default constructor
SimpleCalculator::DivisionByZero::DivisionByZero() {}
//precondition: going to pass in the SimleCalculator class to give you access to the toString() function
//postcondition: going to then now set the rational which is the ZeroDenominator private = to the toString()
SimpleCalculator::DivisionByZero::DivisionByZero(SimpleCalculator r) {
	checking = r.toString();
}
//precondition: going to call the toString() function
//postcondition: going to return the rational (string)
string SimpleCalculator::DivisionByZero::toString() {
	return checking;
}

//Default Constructor
//Precondition: NA
//PostCondition: NA
SimpleCalculator::SimpleCalculator(){}

//precondition: going to turn the variables to a string since they are int
//postcondition: going to return a double checking if its 0
string SimpleCalculator::toString() {
	double num2 = 0.0;
	return to_string(num2);
}
//Precondition: NA
//Postcondition: Displays Calculator Menu
void SimpleCalculator::calculatorMenu(){
	stack<double> numbers;
	double answer;
	string fileName;

	system("cls");
	cout << "\n\t1> Simple Calculator\n";
	cout << string(100, char(196)) << endl;

	cout << "Enter file name for the postfix expression to be stored: ";
	cin >> fileName;
	cout << endl << endl;

	fileName = fileName + ".txt";


	try {
		cout << "Type a parenthesized or non parenthesized arithmetic expression with postive integers or doubles:\n\n";
		// Clear input buffer
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		//call the displayCalculation function to process the input expression.
		displayCalculation(numbers, cin, answer, fileName);
	}
	//catch the DivisionByZero exception.
	catch (DivisionByZero) {
		cout << "\n\tERROR: Division by zero cannot be done.\n";
	}
}
//Precondition: A stack of doubles, user input with numbers that are positive, a double answer
//Postcondition: Displays expression result
void SimpleCalculator::displayCalculation(stack<double>& numbers, istream& ins, double& answer, string fileName){
	const char RIGHT_PARENTHESIS = ')';
	const char LEFT_PARENTHESIS = '(';
	const char DECIMAL = '.';
	double number;
	char operation;
	char parenthesis;
	stack<char> convert;
	stack<double> storage;
	ofstream outFile;
	int errorCtr = 0;
	int specialError = 0;
	//open an output file stream to write to "Store.txt".
	outFile.open(fileName);

	if (!outFile)
	{
		cout << "ERROR: File did not open\n";
		return;
	}
	//loop through the input stream until a newline character is encountered.
	while (ins && ins.peek() != '\n'){
		//check if the next character is a left parenthesis.
		if (ins.peek() == LEFT_PARENTHESIS){
			ins >> parenthesis;
			//push the left parenthesis onto the 'convert' stack.
			convert.push(parenthesis);
		}
		//else if the next character is a space.
		else if (ins.peek() == ' '){
			ins.ignore();
		}
		//else if the next character is a digit or a decimal point.
		else if (isdigit(ins.peek()) || ins.peek() == DECIMAL){
			ins >> number;
			//push the number onto the 'storage' stack.
			storage.push(number);
			outFile << number << endl;

		}
		//else if the next character is an arithmetic operation.
		else if (ins.peek() == '+' || ins.peek() == '-' || ins.peek() == '*' || ins.peek() == '/' || ins.peek() == '^'){
			ins >> operation;
			//pop operators from 'convert' stack and write to the output file based on precedence.
			while (!convert.empty() && convert.top() != LEFT_PARENTHESIS && getPrecendence(convert.top()) >= getPrecendence(operation)){
				outFile << convert.top() << endl;
				convert.pop();
			}
			//push the current operation onto the 'convert' stack.
			convert.push(operation);

		}
		//else if the next character is a right parenthesis.
		else if (ins.peek() == RIGHT_PARENTHESIS && !convert.empty()){
			ins.ignore();
			//pop operators from 'convert' stack and write to the output file until a left parenthesis is encountered.
			while (!convert.empty() && convert.top() != LEFT_PARENTHESIS){
				operation = convert.top();
				outFile << operation << endl;
				convert.pop();
			}
			//check if there is a matching left parenthesis.
			if (convert.empty()){
				cout << "\n\tERROR: Unbalanced Parenthesis\n";
				++errorCtr;
			}
			else{
				//pop the left parenthesis.
				convert.pop();
			}
		}
		//handle other cases (invalid characters).
		else{
			cout << "\n\tERROR: Incorrect Expression Input\n";
			++errorCtr;
			++specialError;
			//ignore the rest of the line.
			while (ins.peek() != '\n'){
				ins.ignore();
			}
			break;
		}
	}
	//pop any remaining operators from 'convert' stack and write to the output file.
	while (!convert.empty() && convert.top() != LEFT_PARENTHESIS && specialError == 0){
		operation = convert.top();
		outFile << operation << endl;
		convert.pop();
	}
	//if for errors related to unbalanced parentheses.
	if (!convert.empty() && specialError == 0){
		cout << "\n\tERROR: Unbalanced Parenthesis\n";
		++errorCtr;
	}
	//if for errors related to incorrect expression input.
	if (storage.size() <= 1 && specialError == 0){
		cout << "\n\tERROR: Incorrect Expression Input\n";
		++errorCtr;
	}
	//if no errors occurred, evaluate the expression and display the result.
	if (errorCtr >= 1){
	}
	else{
		evaluateExpression(numbers, errorCtr, fileName);
		if (errorCtr >= 1) {
			return;
		}
		else {
			answer = numbers.top();
			cout << "\n\tThe Expression Evaluates to: " << answer << endl;
		}
	}
	//closing file
	outFile.close();
}
//Precondition:A stack of doubles for numbers
//Postcondition: evaluates expression
void SimpleCalculator::evaluateExpression(stack<double>& numbers, int& errorCtr, string fileName){
	double num1;
	double num2;
	double answer;
	double storeNum;
	char storeOp;
	// Create an input file stream to read from "Store.txt".
	ifstream inFile;
	inFile.open(fileName);

	if (!inFile)
	{
		cout << "ERROR: File did not open\n";
		return;
	}

	//continue reading until the end of the file (EOF) is reached.
	while (!inFile.eof()){
		//if the next character in the file is a digit.
		if (isdigit(inFile.peek())){
			inFile >> storeNum;
			numbers.push(storeNum);
		}
		//else if the next character in the file is a newline character.
		else if (inFile.peek() == '\n'){
			inFile.ignore();
		}
		//else if the next character in the file is an addition operator ('+').
		else if (inFile.peek() == '+' && numbers.size() >= 2){
			inFile >> storeOp;

			num2 = numbers.top();
			numbers.pop();
			num1 = numbers.top();
			numbers.pop();
			numbers.push(num1 + num2);

		}
		//else if the next character in the file is a subtraction operator ('-'
		else if (inFile.peek() == '-' && numbers.size() >= 2){
			inFile >> storeOp;

			num2 = numbers.top();
			numbers.pop();
			num1 = numbers.top();
			numbers.pop();
			numbers.push(num1 - num2);
		}
		//else if the next character in the file is a subtraction operator ('*')
		else if (inFile.peek() == '*' && numbers.size() >= 2){
			inFile >> storeOp;

			num2 = numbers.top();
			numbers.pop();
			num1 = numbers.top();
			numbers.pop();
			numbers.push(num1 * num2);
		}
		//else if the next character in the file is a subtraction operator ('/')
		else if (inFile.peek() == '/' && numbers.size() >= 2){
			inFile >> storeOp;

			num2 = numbers.top();
			numbers.pop();
			num1 = numbers.top();
			numbers.pop();
			//if number 2 is not 0 run this
			if (num2 != 0) {
				numbers.push(num1 / num2);
			}
			//else if its 0, then error
			else {
				//throw the error
				throw DivisionByZero(*this);
			}
			
		}
		//else if the next character in the file is a subtraction operator ('^')
		else if (inFile.peek() == '^' && numbers.size() >= 2){
			inFile >> storeOp;

			num2 = numbers.top();
			numbers.pop();
			num1 = numbers.top();
			numbers.pop();
			numbers.push(pow(num1, num2));
		}
		//else if if there are less than two numbers on the stack while the file is not at the end.
		else if (numbers.size() < 2 && !inFile.eof()){
			cout << "\n\tERROR: Cannot be a negative number.\n";
			++errorCtr;
			break;
		}
	}
	//closing the file
	inFile.close();
}
//Precondition: a char operator
//Postcondition: returns precendence value;
int SimpleCalculator::getPrecendence(char operation){
	switch (operation){
	case '+': return 1;
		break;
	case '-': return 1;
		break;
	case '*': return 2;
		break;
	case '/': return 2;
		break;
	case '^': return 3;
	}
}