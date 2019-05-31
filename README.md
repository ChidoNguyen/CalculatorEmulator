# CalculatorEmulator

Calculator Emulator will calculate basic arithmetic for addition and multiplication. The program will also support negative integers as well as parentheses processing. <br>
Example Problems:<br>
1 + 1<br>
(3 + 4) * 6<br>
(1 * 4) + (5 * 2)<br>
<br>
How-To-Run:<br> 
Option 1) Download/Clone and load solution into Visual Studio then compile and run.<br>
Option 2) Inside Debug folder there is an executable CalcEmul.exe, execute that to test the program.<br>
<br>
Developer's Notes:<br>
The program was draft to focus on string parsing/ conversion rather than stack/queue usage which would be more similar to the shunting algorithm. I used a semi-recursive like structure to solve this problem. The idea is we first get a string of user input ( our equation ). We process and parse it out into sub strings. (3+4) * 6 gets us 3 sub strings 1) (3+4) , * , and 6. To take a step-back our recursive function focuses on the "solution process" where we solve parentheses () first then multiplication then addition; in that priority order left to right. When we encounter a parentheses substring we pass the content of the parentheses into our "semi-recursive" function of "solution process" again. Ideally our base case is when we reach an addition step we'll sum every thing till nothing is left and return a value of our current sum.<br>
Following the above example we would pass "3+4" into our function it checks and sees no ()'s and no multiply operator; we proceed to sum 3 and 4 into 7 and return it. Our problem is now 7 * 6 ; we process the multiply operator and check for add operator. Final solution is 42.
<br>
The program does do basic user input check to verify on a basic level that the math problem inputted is solvable. Solvable in the sense that our equation does not start with an operator of add or multiply, and our equation is balanced with parentheses.
