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
/*
Function: SetProblem
Job: stores user string input into Calc's private variable
Input: string
Output: N/a
*/
void Calc::setProblem(std::string question) {
	this->problem = question;
}
/*
Function: SetSolveable
Job: Determines if the equation is balanced i.e. equal number of ()'s
Input: string
Output: N/a ; directly alters bool value of Calc's private solveable variable
Future Expansion: Currently Assuming proper input; expand to fully check w/o assuming user proper input
*/
void Calc::setSolveable(std::string question) {
	this->solveable = processSolveable(question);
}
/*
Function: setProblemParse
Job: parses the string input into sub-strings of numbers/symbols and ()'s combo
Input: string
Output: N/A ; saves to private variable 
*/
void Calc::setProblemParse(std::string question) {
	this->parse = stringParse(question);
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

std::vector<std::string> Calc::getParsedComponents() {
	return this->parse;
}
/////////////////////////////////////////////////////////////

/*
Function: stringParse
Job: parses string input to substring of numbers/operators/ other ()' components
Input: String
Output: Returns a vector of strings
*/
std::vector<std::string> Calc::stringParse(std::string question) {
	std::vector<std::string> parseStorage;
	std::string tmp_container = "";
	std::vector<char> parenthesis;

	for (int x = 0; x < question.size(); x++) {
		// if ( )'s we keep the inside components together
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
				parseStorage.push_back(tmp_container);
				tmp_container = "";
			}
		}
		// for more than 1 digit numbers
		else if (question[x] >= 48 && question[x] <= 57) {
			tmp_container.push_back(question[x]);
		}
		// push number string into parse container , followed by operator
		else {
			parseStorage.push_back(tmp_container);
			tmp_container = "";
			tmp_container.push_back(question[x]);
			parseStorage.push_back(tmp_container);
			tmp_container = "";
		}

	}
	// pushes last number into our parse container
	parseStorage.push_back(tmp_container);
	tmp_container = "";

	return parseStorage;
}


bool Calc::processSolveable(std::string question) {
	int stringSize = question.size();
	std::vector<char> parenthesis;
	std::string equation = question;

	for (int x = 0; x < stringSize; x++) {
		if (equation[x] == '(') {
			parenthesis.push_back('(');
		}
		else if (equation[x] == ')' && parenthesis.empty()) {
			return false;
		}
		else if (equation[x] == ')') {
			parenthesis.pop_back();
		}
	}

	if (parenthesis.empty()) {
		return true;
	}
	else
		return false;
}
/*
Function: solution()
Job: calls function to solve the equation to provide an answer and print
Input: N/a
Output: void return; prints answer to console
*/
void Calc::solution() {

	//run the solution process
	//print to screen
}
Calc::~Calc()
{
}
