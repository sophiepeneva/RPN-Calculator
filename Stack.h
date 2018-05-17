# RPN-Calculator
reverse polish notation

#ifndef STACK_H
#define STACK_H
#include<math.h>
#include<iostream>

class Stack
{
public:
	Stack();
	~Stack();

	bool full()const;
	bool empty()const;
	void expand();
	double pop();
	void push(double element);
	double peek()const;

	void operator+ (double el);
	void operator- (double el);
	void operator* (double el);
	void operator/ (double el);
	void operator% (int el);
private:
	enum{MAX_SIZE = 100};
	int m_top;
	double* m_stack;
	int m_size;
};

#endif
