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
		cout << "Please provide a math problem to solve with only ( , ), + and * arithmetics. Enter Quit to close." << endl;
		std::getline(cin, userProblem);
		if (userProblem.compare("Quit") == 0)
			break;
		Calc Emulator(userProblem);
		if(Emulator.getSolveable())
			Emulator.solve();
		else {
			cout << "Problem is cannot be solved please enter new problem." << endl;
		}
		cin.ignore(256, '\n');
	} while (userProblem.compare("Quit") != 0);


	return 0;
}