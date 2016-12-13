#ifndef __STACK_ClassH__
#define __STACK_ClassH__

#include "stdafx.h"
#include <vector>

using namespace std;

typedef int dataType;
typedef vector<dataType> vectorType;

class Stack
{
public:
	Stack(IN vectorType& IN_vtStack) : _vtStack(IN_vtStack)
	{
	}
	//============= ���� ���ܿ� �ֽ� �����͸� �״´�. (LIFO)
	void pushStack(IN dataType IN_Value)
	{
		_vtStack.push_back(IN_Value);
	}
	//============= ���� ���ܿ��� �ֽ� �����͸� �����´�. (LIFO)
	void popStack()
	{
		if (_vtStack.empty())
			throw out_of_range("Stack is empty");
		_vtStack.pop_back();
	}
	dataType topStack() 
	{
		if (_vtStack.empty())
			throw out_of_range("Stack is empty");
		return _vtStack.back();
	}
private:
	vectorType& _vtStack;
};

#endif	/* __STACK_ClassH__ */