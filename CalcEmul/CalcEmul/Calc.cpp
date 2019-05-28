#include "Calc.h"


//Constructor with no params require manual setting 
Calc::Calc()
{
}
//With params will fill in problem and solveable 
Calc::Calc(std::string question)
{
	setProblem(question);
	setSolveable(question);

}


/////////////////////////////////////////////////////////////
//Set Functions used to assign value to our private members//
void Calc::setProblem(std::string question) {
	this->problem = question;
}

void Calc::setSolveable(std::string question) {
	int stringSize = question.size();
	std::vector<char> paranthesis;
	std::string equation = question;
	for (int x = 0; x < stringSize; x++) {
		if (equation[x] == '(') {
			paranthesis.push_back('(');
		}
		else if (equation[x] == ')' && paranthesis.empty()) {
			this->solveable = false;
		}
		else if (equation[x] == ')') {
			paranthesis.pop_back();
		}
	}

	if (paranthesis.empty()) {
		this->solveable = true;
	}
	else
		this->solveable = false;
}
/////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
// Get Functions used to get values of our private members //
std::string Calc::getProblem() {
	return this->problem;
}

bool Calc::getSolveable() {
	return this->solveable;
}

/////////////////////////////////////////////////////////////

Calc::~Calc()
{
}
