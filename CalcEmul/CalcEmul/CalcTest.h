#pragma once
class CalcTest
{
private:
	bool overall_test_result;
public:

	CalcTest();
	void testCalc();
	bool testCalcInit();
	bool testCalcSolveable();
	bool testStringParse();
	bool testParenTrim();
	bool testSolutionProcess();
	~CalcTest();
};

