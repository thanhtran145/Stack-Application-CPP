// Console Stacks Application

#include<iostream>
#include"input (1).h"
#include"SimpleCalculator.h"
#include"TranslationArithmetic.h"
#include"n_Queens.h"
using namespace std;

//prototype
int menuOption();
void challenge1();
void challenge2();
void challenge3();

int main()
{
	do {
		switch (menuOption()) {
		case 0: exit(1); break;
		case 1: challenge1(); break;
		case 2: challenge2(); break;
		case 3: challenge3(); break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

	return EXIT_SUCCESS;
}

//precondition: N/A
//postcondition: Display the main menu
int menuOption() {
	system("cls");
	cout << "\n\tApplications using Stacks by Thanh Tran ";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t1> Simple Calculator ";
	cout << "\n\t\t2> Translation of arithmetic expression ";
	cout << "\n\t\t3> N-Queens Problem ";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t0> Exit";
	cout << "\n\t" << string(100, char(205));
	return inputInteger("\n\t\tOption: ", 0, 3);
}

//precondition: N/A
//postcondition: Simple Calcutor Menu
void challenge1() {
	SimpleCalculator menu;
	menu.calculatorMenu();
}
//precondition: N/A
//postcondition: Translation Arithmetic Menu
void challenge2() {
	TranslationArithmetic menu;
	menu.menuInformation();
}
//precondition: N/A
//postcondition: N-queens menu
void challenge3() {
	n_Queens menu;
	menu.n_QueensMenu();
}
