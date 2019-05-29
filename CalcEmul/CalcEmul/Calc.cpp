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
	setProblemParse(question);
}


/////////////////////////////////////////////////////////////
//Set Functions used to assign value to our private members//
void Calc::setProblem(std::string question) {
	this->problem = question;
}

void Calc::setSolveable(std::string question) {
	int stringSize = question.size();
	std::vector<char> parenthesis;
	std::string equation = question;
	for (int x = 0; x < stringSize; x++) {
		if (equation[x] == '(') {
			parenthesis.push_back('(');
		}
		else if (equation[x] == ')' && parenthesis.empty()) {
			this->solveable = false;
			x = INT_MAX - 1;
		}
		else if (equation[x] == ')') {
			parenthesis.pop_back();
		}
	}

	if (parenthesis.empty() && this->solveable != false) {
		this->solveable = true;
	}
	else
		this->solveable = false;
}

void Calc::setProblemParse(std::string question) {
	std::string tmp_container = "";
	std::vector<char> parenthesis;
	bool digit;
	
	for (int x = 0; x < question.size(); x++) {
		if (question[x] == '(') {
			parenthesis.push_back('(');
			tmp_container.push_back(question[x]);
		}
		else if (!parenthesis.empty()) {
			tmp_container.push_back(question[x]);
		}
		else if (question[x] == ')') {
			parenthesis.pop_back();
			tmp_container.push_back(question[x]);
			if (parenthesis.empty()) {
				this->parse.push_back(tmp_container);
				tmp_container = "";
			}
		}
		else if (question[x] >= 48 && question[x] <= 57) {
			tmp_container.push_back(question[x]);
		}
		else {
			this->parse.push_back(tmp_container);
			tmp_container = "";
			tmp_container.push_back(question[x]);
			this->parse.push_back(tmp_container);
			tmp_container = "";
		}

	}
	this->parse.push_back(tmp_container);
	tmp_container = "";
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
