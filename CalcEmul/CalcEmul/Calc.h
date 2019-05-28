#ifndef CALC_H
#define CALC_H

#include <string>
#include <vector>

class Calc
{
private:
	std::string problem;
	bool solveable;
public:
	Calc();
	Calc(std::string question);
	//Get-Set//
	void setProblem(std::string question);
	void setSolveable(std::string question);

	std::string getProblem();
	bool getSolveable();
	~Calc();
};

#endif