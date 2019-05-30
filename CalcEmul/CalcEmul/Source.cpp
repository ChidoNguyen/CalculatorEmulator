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

	CalcTest calcTest;
	calcTest.testCalc();

	string userProblem;
	Calc Emulator;
	cout << "Please provide a math problem to solve with only + and * arithmetics" << endl;
	cin >> userProblem;
	//Emulator.trimParenthesis(userProblem);
	Emulator.setProblem(userProblem);
	Emulator.setSolveable(userProblem);
	Emulator.setProblemParse(userProblem);
	Emulator.solve();

	// Or we do Calc Emulator(userProblem); either or works


	cout << userProblem;


	return 0;
}