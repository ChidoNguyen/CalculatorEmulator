/*
Chido Nguyen
Code Challenge Plexsys: Calculator Emulator for * and + handling w/o using shunting algo
*/

#include <iostream>
#include <string>
#include "Calc.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {

	string userProblem;
	Calc Emulator;
	cout << "Please provide a math problem to solve with only + and * arthmitics" << endl;
	cin >> userProblem;
	Emulator.setProblem(userProblem);
	Emulator.setSolveable(userProblem);

	// Or we do Calc Emulator(userProblem); either or works


	cout << userProblem;


	return 0;
}