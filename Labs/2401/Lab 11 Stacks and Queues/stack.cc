/*************************************************************************
   The implementations of the calculator-useful functions
	John Dolan			Spring 2014
*************************************************************************/

#include <cstdlib>
#include <iostream>
#include <stack>

using namespace std;

bool isop(char op){
    return op =='+' || op == '-' || op == '*' || op == '/';
}

int evaluate(int num1, int num2, char op){
    if(op == '+') return num1 + num2;
    if(op == '-') return num1 - num2;
    if(op == '*') return num1 * num2;
    if(op == '/') return num1 / num2;
    else return 0;
}

double evaluate(double num1, double num2, char op){
    if(op == '+') return num1 + num2;
    if(op == '-') return num1 - num2;
    if(op == '*') return num1 * num2;
    if(op == '/') return num1 / num2;
    else return 0;
}

//Finish this function
void EvaluateExpression(std::istream& ins, std::ostream& outs){
    char c;
	int onenum, twonum;
	//define a stack called "nums" here
	stack<int> nums;

	if(&outs == &cout)
		outs << "Please enter your expression:\n";

	c = ins.get(); // priming read for the sentinel loop.
	while(c != '\n'){
		if(isdigit(c)){
			ins.putback(c);
			ins >> onenum;
			// stack operation here.
			nums.push(onenum);
		}
		else if(isop(c)){
			if(nums.size() >= 2){
				// pop two numbers from the stack
				onenum = nums.top();
				nums.pop();
				twonum = nums.top();
				nums.pop();
				// evaluate them using the evaluate from stack_useful
				// evaluate(onenum, twonum, c);
				// push result onto the stack
				nums.push(evaluate(twonum, onenum, c));
			}
			else{
				outs << "Error: Expression doesn't contain enough numbers.\n";
				return;
			}
		}
		c = ins.get(); // reading at the bottom of the sentinel loop
	} // bottom of the loop that reads a single expression from the keyboard
	
	// output the final result from the top of the stack
	// but only after you check to make sure there's something on the stack
	if(nums.size() == 1){
		int result = nums.top();
		outs << "Result: " << result << endl;
	}else{
		outs << "Error: Incorrect amount of numbers entered.\n";
	}
}