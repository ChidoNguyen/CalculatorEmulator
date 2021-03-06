#ifndef CALC_H
#define CALC_H

#include <string>
#include <vector>

class Calc
{
private:
	std::string problem;
	bool solvable; // remove preset
	std::vector<std::string> parse;
	int solution;

public:
	Calc();
	Calc(std::string question);
	//Get-Set//
	void setProblem(std::string question);
	void setSolvable(std::string question);
	void setProblemParse(std::string question);

	std::string getProblem();
	bool getSolvable();
	std::vector<std::string> getParsedComponents();
	int getSolution();
	//////////

	//Mathematics and other logic problems//
	std::vector<std::string> stringParse(std::string question);
	bool processSolvable(std::string question);
	void solve();
	int solutionProcess(std::vector<std::string> parsedQuestion);
	int multiplication(std::string firstNumber, std::string secondNumber);


	//Utility Function//
	std::string trimParenthesis(std::string subunit);

	~Calc();
};

#endif