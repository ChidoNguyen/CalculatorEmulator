#include "CalcTest.h"
#include <string>
#include <vector>
#include <iostream>
#include "Calc.h"

using std::cin;
using std::cout;
using std::endl;


CalcTest::CalcTest()
{
	this->overall_test_result = false;
}

void CalcTest::testCalc() {
	// run all the tests and track it here
	std::vector<std::string> testNames= {
		"Class Initiliation",
		"Problem Solvable Check",
		"String Parse Check",
		"String Parse Parenthesis Trimming Check",
		"Solution Procedure Check"
	};
	std::vector<bool>outcome;
	outcome.push_back( testCalcInit());
	outcome.push_back(testCalcSolvable());
	outcome.push_back(testStringParse());
	outcome.push_back(testParenTrim());
	outcome.push_back(testSolutionProcess());

	for (int x = 0; x < testNames.size(); x++) {
		cout << testNames[x] << " : ";
		if (outcome[x])
			cout << "pass" << endl;
		else
			cout << "fail" << endl;
	}
	

	
		
}

/*Test Initilization:
This can help us confirm that our Set and Get works as well. Feed in our own manual constructed "question" which we know the solvable bool value of and how it should be parsed. Use the Get-ters to confirm that our setters work and our init works
*/
bool CalcTest::testCalcInit() {
	std::string question = "1+(2*3)+4";
	Calc calculate(question);
	bool status = true;
	std::vector<std::string> knownParse = { "1", "+", "(2*3)", "+", "4" };

	if (question.compare(calculate.getProblem()) == 0
		&& status == calculate.getSolvable()
		&& knownParse == calculate.getParsedComponents()) {
		return true;
	}
	else
		return false;

}
/*
Test Solvable Function:
Role of the function is to determine if equation is do-able i.e. proper input/ balanced ()'s
Currently: Only checks () and if equation starts with a digit vs operator
Future: Could expand on more complex checks
*/
bool CalcTest::testCalcSolvable() {
	std::vector<std::string> problems =
	{ 
		"1+1",
		"(1+1",
		"1+1)",
		"(1+1)",
		"(1+1)+(1+1)",
		"((1)+1)",
		"(1)+1)",
		"+1+2"

	};

	std::vector<bool> solutions =
	{
		true,
		false,
		false,
		true,
		true,
		true,
		false,
		false
	};

	int testcase_count = problems.size();

	for (int x = 0; x < testcase_count; x++) {
		Calc calc(problems[x]);
		if (calc.getSolvable() != solutions[x]) {
			return false;
		}
	}

	return true;
}
/*
Test String Parser:
Examining our parser's ability to ignore white spaces, group multi-digit values together and separating ()'s component from digits from operators
*/
bool CalcTest::testStringParse() {
	std::vector<std::string> problems =
	{
		"1+1",
		"(1+1)",
		"(1+1)+(1+1)",
		"((1+1)+1)+1",
		"1*5+1*5"

	};

	std::vector<std::vector<std::string>> solutions =
	{
		{"1","+","1"},
		{"(1+1)"},
		{"(1+1)","+","(1+1)"},
		{"((1+1)+1)", "+", "1"},
		{"1", "*", "5", "+", "1","*","5"}

	};

	int testcase_count = problems.size();

	for (int x = 0; x < testcase_count; x++) {
		Calc calc(problems[x]);
		if (calc.getParsedComponents() != solutions[x]) {
			return false;
		}
	}

	return true;
}

/*
Test Parentheses Trim:
Making sure our trim function strips leading and trailing () pairs accordingly
*/
bool CalcTest::testParenTrim() {

	std::vector<std::string> problems =
	{
		"(1+1)",
		"((1+1))",
		"(((1+1)+1)+1)"
	};
	std::vector<std::string> solutions =
	{
		"1+1",
		"(1+1)",
		"((1+1)+1)+1"
	};
	int testcase_count = problems.size();

	for (int x = 0; x < testcase_count; x++) {
		Calc calc;
		if (calc.trimParenthesis(problems[x]) != solutions[x]) {
			return false;
		}
	}

	return true;
}
/*
Test solution process:
Making sure our equation are solved appropriately when checked against input and solutions
*/
bool CalcTest::testSolutionProcess() {
	std::vector<std::string> problems =
	{
		"(1+1)",
		"1+ (2+3) +4",
		"10 * 10 * 10 * 10",
		"10+1*10+10",
		"(10+1)*10",
		"11*2*(1+1)",
		"-10*10",
		"-10*-10",
		"-1+1",
		"-1+-1"
	};

	std::vector<int> solutions =
	{
		2,
		10,
		10000,
		30,
		110,
		44,
		-100,
		100,
		0,
		-2
	};
	
	int testcase_count = problems.size();
	for (int x = 0; x < testcase_count; x++) {
		Calc calc(problems[x]);
		calc.solve();
		if (calc.getSolution() != solutions[x]) {
			return false;
		}
	}

	return true;
}
CalcTest::~CalcTest()
{
}
