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
//   Stack, Heap 자료구조를 응용하여 element 개수가 4개 이하면 Stack 방식으로 데이터 push,pop
//   그 이상이면 벡터에 있는 데이터를 HeapTree로 구성하고 Heap방식으로 데이터를 push.pop하는 사용자 정의 벡터를 구현함.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class SHVector
{
public:
	SHVector(IN vectorType& IN_vtSHVector) : _vtSHVector(IN_vtSHVector)
	{
		if (_pStack == nullptr)
			_pStack = new Stack(IN _vtSHVector);

		//============= 생성자 호출 시점에 element 개수가 5개 이상이면 힙트리로 데이터 순서를 재구성한다.
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
			//============= push하는 시점에 element 개수가 5개 이상을 만족하면 힙트리로 데이터 순서를 재구성한다.
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