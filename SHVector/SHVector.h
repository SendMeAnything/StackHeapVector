#ifndef __SHVector_ClassH__
#define __SHVector_ClassH__

#include "stdafx.h"
#include <vector>

using namespace std;

typedef int dataType;
typedef vector<dataType> vectorType;

#include "Stack.h"
#include "Heap.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//   Stack, Heap �ڷᱸ���� �����Ͽ� element ������ 4�� ���ϸ� Stack ������� ������ push,pop
//   �� �̻��̸� ���Ϳ� �ִ� �����͸� HeapTree�� �����ϰ� Heap������� �����͸� push.pop�ϴ� ����� ���� ���͸� ������.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class SHVector
{
public:
	SHVector(IN vectorType& IN_vtSHVector) : _vtSHVector(IN_vtSHVector)
	{
		if (_pStack == nullptr)
			_pStack = new Stack(IN _vtSHVector);

		//============= ������ ȣ�� ������ element ������ 5�� �̻��̸� ��Ʈ���� ������ ������ �籸���Ѵ�.
		if (_vtSHVector.size() >= 5)	
		{
			if (_pHeap == nullptr)
				_pHeap = new Heap(IN _vtSHVector);
		}
	}
	~SHVector()
	{
		if (_pStack != nullptr)
			delete _pStack;

		if (_pHeap != nullptr)
			delete _pHeap;
	}

	void push(IN dataType IN_nValue)
	{
		if ( (_vtSHVector.size()+1) <= 4)
		{
			_pStack->pushStack(IN IN_nValue);
		}
		else
		{
			//============= push�ϴ� ������ element ������ 5�� �̻��� �����ϸ� ��Ʈ���� ������ ������ �籸���Ѵ�.
			if (_pHeap == nullptr)
				_pHeap = new Heap(IN _vtSHVector);
		
			_pHeap->pushHeap(IN IN_nValue);
		}
	}
	void pop()
	{
		if (_vtSHVector.empty())
			throw out_of_range("SHVector is empty");
		else
		{
			if (_vtSHVector.size() <= 4)
			{
				_pStack->popStack();
			}
			else
			{
				_pHeap->popHeap();
			}
		}
	}
	dataType top()
	{
		dataType Value = 0;
		if (_vtSHVector.empty())
			throw out_of_range("SHVector is empty");
		else
		{
			if (_vtSHVector.size() <= 4)
			{
				Value = _pStack->topStack();
			}
			else
			{
				Value = _pHeap->topHeap();
			}
		}
		return Value;
	}

private:
	vectorType& _vtSHVector;
	Stack* _pStack = nullptr;
	Heap*  _pHeap = nullptr;
};

#endif /* __SHVector_ClassH__ */