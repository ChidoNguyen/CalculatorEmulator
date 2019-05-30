#include "Calc.h"
#include <iostream>


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
		else if (question[x] == ')') {
			parenthesis.pop_back();
			tmp_container.push_back(question[x]);
			if (parenthesis.empty()) {
				parseStorage.push_back(tmp_container);
				tmp_container = "";
			}
		}
		else if (!parenthesis.empty()) {
			tmp_container.push_back(question[x]);
		}
		// for more than 1 digit numbers
		else if ((question[x] >= 48 && question[x] <= 57) || question[x] == 45) {
			tmp_container.push_back(question[x]);
		}
		// push number string into parse container , followed by operator
		else {
			if (tmp_container.size() > 0) {
				parseStorage.push_back(tmp_container);
			}
			tmp_container = "";
			tmp_container.push_back(question[x]);
			parseStorage.push_back(tmp_container);
			tmp_container = "";
		}

	}
	// pushes last number into our parse container
	if (tmp_container.size() > 0) {
		parseStorage.push_back(tmp_container);
	}
	return parseStorage;
}

/*
Function: processSolveable
Job: goes through the string to make sure the ()'s are balanced
Input: String
Output: returns a boolean
ASSUMPTION: User input is correct for the most part future expansion could be more robust on the string checks
*/
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
void Calc::solve() {

	//run the solution process
	this->solution = solutionProcess(this->parse);
	//print to screen
	std::cout << "Problem : " << this->problem << std::endl;
	std::cout << "Solution : " << this->solution << std::endl;
	
}

/*
Function: solutionProcess()
Job: processes the arithmitic required to solve * and +  as needed while handling ()
Input: vector of the parsed strings
Output: integer value
*/

int Calc::solutionProcess(std::vector<std::string> parsedQuestion) {
	// Will probably have to do this recursively
	// Solve sub-string/problems that are in parenthesis
	// Logic : Process () ---> check and do multiplication --> then check and do +

	int substring_Count = parsedQuestion.size();
	std::vector<std::string> updated_parsed;
	int runningSum = 0;

	//work on any () portions
	int foundIndex = std::string::npos;
	for (int idx = 0; idx < substring_Count; idx++) {
		std::string target = parsedQuestion[idx];
		foundIndex = target.find_first_of("(");
		if (foundIndex == std::string::npos) {
			// do stuff if no () found
			updated_parsed.push_back(parsedQuestion[idx]);
		}
		else {
			// if () found do other
			std::string removedParen = trimParenthesis(target);
			std::vector<std::string> tmpContainer;
			tmpContainer = stringParse(removedParen);
			// solve the things inside our ()
			int subSolution = solutionProcess(tmpContainer);

			std::string solution_to_string = std::to_string(subSolution);
			updated_parsed.push_back(solution_to_string);
			foundIndex = std::string::npos;
			
		}

	}
	// work on *
	int updatedSub_Count = updated_parsed.size();
	std::vector<std::string> postParen;
	std::string multi = "*";
	int astrik_index = -5;
	for (int x = 0; x < updatedSub_Count; x++) {
		if (updated_parsed[x].compare(multi) == 0) {
			int product;
			int var1_index;
			int var2_index;
			if (astrik_index + 2 == x) {
				//sequential astrik's indexes//
				std::string prev_product = postParen.back();
				astrik_index = x;
				var1_index = x + 1;
				product = multiplication(prev_product, updated_parsed[var1_index]);

			}
			else {
				var1_index = x - 1;
				var2_index = x + 1;
				astrik_index = x;

				product = multiplication(updated_parsed[var1_index], updated_parsed[var2_index]);
			}
			
			postParen.pop_back();
			postParen.push_back(std::to_string(product));
			x++;
		}
		else {
			postParen.push_back(updated_parsed[x]);
		}
	}

	// work on +
	int postParen_Count = postParen.size();
	std::string plus = "+";
	for (int x = 0; x < postParen_Count; x++) {
		if (postParen[x].compare(plus) != 0)
		{
			runningSum += std::stoi(postParen[x]);
		}
	}
	return runningSum;
}

/*
Function: trimParenthesis
Job: Removes the () from string for further "processing"/solving
Input: String
Output: updated string
*/
std::string Calc::trimParenthesis(std::string subunit) {
	// remove first and last characters for the ( and ) places
	int idx;
	std::string newSubunit = "";
	for (idx = 0; idx < subunit.size(); idx++) {
		if (idx != 0 && idx != subunit.size() - 1) {
			newSubunit.push_back(subunit[idx]);
		}
	}

	return newSubunit;
}

/*
Function: multiplication
Job: Multiply two strings which are representative of numbers;
Input: two strings
Output: An integer
*/
int Calc::multiplication(std::string firstNumb, std::string secondNumb) {
	int first = std::stoi(firstNumb);
	int second = std::stoi(secondNumb);

	return first * second;
}
Calc::~Calc()
{
}
