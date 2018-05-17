# RPN-Calculator
reverse polish notation c++

#include "Stack.h"
#include <iostream>

using namespace std;

double RPNCalcultor(const char* string) 
{
	double result = 0;
	
	int lenght = strlen(string);
	Stack equation;
	//filling the stack with the numbers from the string
	for (int i = 0;i < lenght;i++) {
		if (string[i] >= '0' && string[i] <= '9') {
			double number = 0;
			int dec = 10;
			while (string[i] != '.'&&string[i]!=' ')
			{
				number = number * 10 + (string[i] - '0');
				i++;
			}
			if(string[i]=='.')
			{
				i++;
				while (string[i] != ' ')
				{
					double NumDec = string[i] - '0';
					number = number + NumDec / dec;
					dec *= 10;
					i++;
				}
			}
			equation.push(number);
		}
		//if the current string element is '+','-','*','/' or '%' , carries out the operation
		if (string[i] == '+')
		{
			double el = equation.pop();
			
			equation + el;
		}
		if (string[i] == '-')
		{
			double el = equation.pop();
			equation - el;
		}
		if (string[i] == '*')
		{
			double el = equation.pop();
			equation * el;
		}
		if (string[i] == '/')
		{
			double el = equation.pop();
			equation / el;
		}
		if (string[i] == '%') {
			double el = equation.pop();
			if (el != floor(el))cout << "Error" << endl;
			else if (el == floor(el))
				equation % el;
		}

	}
	result = equation.peek();
	return result;
}

int main() {
	double result = RPNCalcultor("5 10 17 + * 134 -");
	cout << result << endl;
	system("pause");
}
