// Input Header file contains functions which is useful for validating input value.
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//return an input char
char inputChar(string prompt, char yes, char no)
{
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR-1A: Invalid input. Must be a character type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (tolower(input) != tolower(yes) && tolower(input) != tolower(no))
			cout << "ERROR-2A: Invalid input. Must be a '" << static_cast<char>(toupper(yes)) << "' or '" << static_cast<char>(toupper(no)) << "' character.\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

char inputChar(string prompt, string lookup)
{
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR-1A: Invalid input. Must be a character type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else
		{
			for ( int i = 0; i < lookup.length(); i++)
				if (toupper(input) == toupper(lookup[i]))
				{
					cin.clear();
					cin.ignore(999, '\n');
					return input;
				}
			cout << "ERROR-1A: Invalid input. Must be \"" + lookup +"\".\n";
			continue;
			cin.clear();
			cin.ignore(999, '\n');
		}
		break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

//return an input char
char inputChar(string prompt, bool alphaOrDigit)
{
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR-1A: Invalid input. Must be a character type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (alphaOrDigit && !isalpha(input))
			cout << "ERROR-2A: Invalid input. Must be an alphabet character.\n";
		else if (!alphaOrDigit && !isdigit(input))
			cout << "ERROR-2A: Invalid input. Must be a digit character.\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

//return an input char
char inputChar(string prompt)
{
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR-1A: Invalid input. Must be a character type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

//return an input interger
int inputInteger(string prompt)
{
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR-1A: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else
			break;
	} while (true);
	return input;
}

//return an integer where posNeg is positive (true) or negative (false)
int inputInteger(string prompt, bool posNeg)
{
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR-2A: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (posNeg && input <= 0)
			cout << "ERROR-2A: Invalid input. Must be a positive number.\n";
		else if (!posNeg && input >= 0)
			cout << "ERROR-2A: Invalid input. Must be a negative number.\n";
		else
			break;
	} while (true);
	return input;
}

//return an integer where posNeg is positive (true) or negative (false)
int inputInteger(string prompt, int start, bool greater)
{
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR-2A: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (greater && input < start)
			cout << "ERROR-2A: Invalid input. Must be a greater than or equal to " << start << ".\n";
		else if (!greater && input > 0)
			cout << "ERROR-2A: Invalid input. Must be a lesser than or equal to " << start << ".\n";
		else
			break;
	} while (true);
	return input;
}

//return an input integer within range ,start and end
int inputInteger(string prompt, int startRange, int endRange)
{

	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR-3A: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (!(input >= min(startRange, endRange) && input <= max(startRange, endRange)))
			cout << "ERROR-3A: Invalid input. Must be from " << startRange << ".." << endRange << ".\n";
		else
			break;
	} while (true);
	return input;
}

//return an input double
double inputDouble(string prompt)
{
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR-1B: Invalid input. Must be a double type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else
			break;
	} while (true);
	return input;
}

//return a double where posNeg is positive (true) or negative (false)
double inputDouble(string prompt, bool posNeg)
{
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR-2B: Invalid input. Must be a double type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (posNeg && input <= 0.0)
			cout << "ERROR-2B: Invalid input. Must be a positive number.\n";
		else if (!posNeg && input >= 0.0)
			cout << "ERROR-2B: Invalid input. Must be a negative number.\n";
		else
			break;
	} while (true);
	return input;
}

double inputDouble(string prompt, double start, bool posNeg)
{
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR-2B: Invalid input. Must be a double type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (posNeg && input <= start)
			cout << "ERROR-2B: Invalid input. Must be greater than or equal to " << start << ".\n";
		else if (!posNeg && input >= start)
			cout << "ERROR-2B: Invalid input. Must be lesser than or equal to " << start << ".\n";
		else
			break;
	} while (true);
	return input;
}
//return an input double within range ,start and end
double inputDouble(string prompt, double startRange, double endRange)
{
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR-3A: Invalid input. Must be a double type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (!(input >= min(startRange, endRange) && input <= max(startRange, endRange)))
			cout << "ERROR-3A: Invalid input. Must be from " << startRange << ".." << endRange << ".\n";
		else
			break;
	} while (true);
	return input;
}
//PreCondition: spaces (boolean true or false)
//PostCondition: returns a string including space character(s) or without space character 
string inputString(string prompt, bool spaces)
{
	string input = "";
	bool displayPrompt = true;
	do
	{
		if (displayPrompt)
		{
			cout << prompt;
			//flag it to true
			displayPrompt = false; 
		}

		if (spaces)
		{
			getline(cin, input);
		}
		else
		{
			cin >> input;
			cin.clear();
			cin.ignore(999, '\n');
		}

	} while (input.empty());

	return input;
}

//PreCondition: a string input
//PostCondition: Function to remove leading and trailing spaces from a string
string removeLeadingTrailingSpaces(const string& input)
{
	size_t startPos = input.find_first_not_of(" \t\n\r");
	if (startPos == string::npos)
	{
		// The string consists only of spaces
		return "";
	}
	size_t endPos = input.find_last_not_of(" \t\n\r");
	return input.substr(startPos, endPos - startPos + 1);
}