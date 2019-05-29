#ifndef CALC_H
#define CALC_H

#include <string>
#include <vector>

class Calc
{
private:
	std::string problem;
	bool solveable = true;
	std::vector<std::string> parse;
public:
	Calc();
	Calc(std::string question);
	//Get-Set//
	void setProblem(std::string question);
	void setSolveable(std::string question);
	void setProblemParse(std::string question);

	std::string getProblem();
	bool getSolveable();
	std::vector<std::string> getParsedComponents();
	//////////

	//Mathematics and other logic problems//
	std::vector<std::string> stringParse(std::string question);
	bool processSolveable(std::string question);
	void solution();
	int solutionProcess();

	~Calc();
};

#endif