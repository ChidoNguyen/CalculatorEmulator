#include "CalcTest.h"
#include <string>
#include <vector>
#include "Calc.h"


CalcTest::CalcTest()
{
	this->overall_test_result = false;
}

void CalcTest::testCalc() {
	// run all the tests and track it here
	bool init_status = testCalcInit();
	bool solveable_status = testCalcSolveable();
	bool stringParse_status = testStringParse();
	bool solutionProcess_status = testSolutionProcess();
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
		&& status == calculate.getSolveable()
		&& knownParse == calculate.getParsedComponents()) {
		return true;
	}
	else
		return false;

}

bool CalcTest::testCalcSolveable() {
	std::vector<std::string> problems =
	{ 
		"1+1",
		"(1+1",
		"1+1)",
		"(1+1)",
		"(1+1)+(1+1)",
		"((1)+1)",
		"(1)+1)"

	};

	std::vector<bool> solutions =
	{
		true,
		false,
		false,
		true,
		true,
		true,
		false
	};

	int testcase_count = problems.size();

	for (int x = 0; x < testcase_count; x++) {
		Calc calc(problems[x]);
		if (calc.getSolveable() != solutions[x]) {
			return false;
		}
	}

	return true;
}

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

bool CalcTest::testSolutionProcess() {
	std::vector<std::string> problems =
	{
		"(1+1)",
		"1+(2+3)+4",
		"10*10*10*10",
		"10+1*10+10",
		"(10+1)*10",
		"11*2*(1+1)"
	};

	std::vector<int> solutions =
	{
		2,
		10,
		10000,
		30,
		110,
		44
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
