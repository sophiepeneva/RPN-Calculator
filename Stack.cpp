# RPN-Calculator
reverse polish notation

#include "Stack.h"

Stack::Stack()
{
	m_size = MAX_SIZE;
	m_top = -1;
	m_stack = new double[m_size];
}

Stack::~Stack()
{
	delete[] m_stack;
}

bool Stack::full()const
{
	//This method checks if the stack is full
	return(m_top == m_size - 1);
}

bool Stack::empty()const
{
	//This method checks if the stack is empty
	return(m_top == -1);
}

void Stack::expand()
{
	//This method expands the Stack by creating one with a larger capacity
	// fills it with the elements from the previos Stack
	double* biggerStack = new double[m_size * 2];
	for (int i = 0;i < m_top;i++) {
		biggerStack[i] = m_stack[i];
	}
	delete[] m_stack;
	m_stack = biggerStack;
	m_size *= 2;
}

double Stack::pop() 
{
	//if the Stack is not empty return the last element's value and then deletes it from the Stack
	if (empty()) 
	{
		std::cout << "Error : You are trying to delete an element from an empty stack" << std::endl;
		return 0;
	}
	return m_stack[m_top--];
}

void Stack::push(double el) 
{
	//Adds a new element to the Stack
	//If the stack is full, expands it first
	if (full()) {
		expand();
	}
	if(!full())
	{
		m_stack[++m_top] = el;
	}
}

double Stack::peek()const 
{
	//returns the value of the last added element
	if (empty())
	{
		std::cout << "Error : You are trying to look at an element from an empty stack" << std::endl;
		return 0;
	}
	return m_stack[m_top];
}

void Stack::operator+(double el)
{
	double newElement=pop() + el;
	push(newElement);	
}

void Stack::operator-(double el)
{
	double newElement = pop() - el;
	push(newElement);
}

void Stack::operator*(double el)
{
	double newElement = pop() * el;
	push(newElement);
}

void Stack::operator/(double el)
{
	double newElement = pop() / el;
	push(newElement);
}

void Stack::operator%(int el)
{
	//checks if the last element is type "int" in order to carry out the operation '%'
	//, if not - gives an Error
	double initialEl = pop();
	if (initialEl == floor(initialEl)) 
	{
		int initialElInt = initialEl;
		double newElement = initialElInt % el;
		push(newElement);
	}
	else {
		std::cout << "Error" << std::endl;
	}
}
