/*
Chido Nguyen
Code Challenge Plexsys: Calculator Emulator for * and + handling w/o using shunting algo
*/

#include <iostream>
#include <string>
#include "Calc.h"
#include "CalcTest.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
	
	/*CalcTest calcTest;
	calcTest.testCalc();*/

	string userProblem;
	do {
		cout << "Please provide a math problem to solve with only ( , ), + and * arithmetics." << endl <<"Good Input = (1+2)*4. Bad Input = ((+1)+2 unbalanced parentheses and leading operator." << endl << "Enter Quit to close." << endl;
		std::getline(cin, userProblem);
		if (userProblem.compare("Quit") == 0)
			break;
		Calc Emulator(userProblem);
		//if we can solve it we do//
		if(Emulator.getSolvable())
			Emulator.solve();
		else {
			cout << "Problem is cannot be solved please enter new problem." << endl;
		}
		cout << "Press enter to Continue." << endl;
		cin.ignore(256, '\n');

	} while (userProblem.compare("Quit") != 0);


	return 0;
}