#ifndef __HEAP_ClassH__
#define __HEAP_ClassH__

#include "stdafx.h"
#include <vector>

using namespace std;

typedef int dataType;
typedef vector<dataType> vectorType;

#define LCHILD_IDX(x)    (2*x + 1)
#define RCHILD_IDX(x)	 (2*x + 2)
#define PARENT_IDX(x)    ((x-1)/2)
#define SWAP(a,b)		 {dataType t; t = a; a=b; b=t;}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//   ���� �⺻ DES Sorting���� ������.
//   ���� ����� ���� �Լ��� Sorting �� �� �ֵ��� ������Ʈ ����.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Heap
{
public:
	//============= �����ڿ��� Input ���͸� �޾Ƽ� ���� ������.
	Heap(IN vectorType& IN_vtHeap) : _vtHeap(IN_vtHeap) 
	{
		_makeHeap();
	}
	//============= ��Ʈ�� �������� �������� pushBack�ϰ� �θ� ���� ��� ���ϸ鼭 ������ �ڸ��� ã�Ƶ�. 
	void pushHeap(IN dataType IN_Value)
	{
		_vtHeap.push_back(IN IN_Value);
		_nodeUp(_vtHeap.size() - 1); //============= �ش� �Լ��� ��������� ȣ���
	}
	//============= ��Ʈ�� �������� ������ popBack�ϰ� ROOT ���� �������鼭 L,R Child ��� ���ؼ� ��Ʈ�� �ٽ� ������. 
	void popHeap()
	{
		int nNodeSize = _vtHeap.size();
		if (_vtHeap.empty())
			throw out_of_range("Heap is empty");
		else
		{
			_vtHeap[0] = _vtHeap[nNodeSize - 1];
			_vtHeap.pop_back();
			_nodeDown(0); //============= �ش� �Լ��� ��������� ȣ���
		}
	}
	//============= ���� �ε��� 0�� ��Ʈ�� ROOT�� �ǹ���
	dataType topHeap()
	{
		if (_vtHeap.empty())
			throw out_of_range("Heap is empty");
		else
			return _vtHeap[0];
	}
private:
	vectorType& _vtHeap;
	void _nodeDown(IN int IN_nNodeIDX)
	{
		if (_vtHeap.empty())
			throw out_of_range("Heap is empty");
		else
		{
			int nNodeSize = _vtHeap.size();
			int nLchildIDX = LCHILD_IDX(IN_nNodeIDX);
			int nRchildIDX = RCHILD_IDX(IN_nNodeIDX);

			if (nLchildIDX >= nNodeSize)
				return;

			int nHiPriIDX = IN_nNodeIDX;

			if (_vtHeap[IN_nNodeIDX] < _vtHeap[nLchildIDX])
			{
				nHiPriIDX = nLchildIDX;
			}

			if ((nRchildIDX < nNodeSize) && (_vtHeap[nHiPriIDX] < _vtHeap[nRchildIDX]))
			{
				nHiPriIDX = nRchildIDX;
			}

			if (nHiPriIDX != IN_nNodeIDX)
			{
				SWAP(_vtHeap[IN_nNodeIDX], _vtHeap[nHiPriIDX]);
				_nodeDown(nHiPriIDX);
			}
		}
	}
	void _nodeUp(IN int IN_nNodeIDX)
	{
		if (_vtHeap.empty())
			throw out_of_range("Heap is empty");
		else
		{
			if (IN_nNodeIDX == 0)
				return;

			int nParentIDX = PARENT_IDX(IN_nNodeIDX);
			if (_vtHeap[nParentIDX] < _vtHeap[IN_nNodeIDX])
			{
				SWAP(_vtHeap[IN_nNodeIDX], _vtHeap[nParentIDX]);
				_nodeUp(nParentIDX);
			}
		}
	}
	void _makeHeap()
	{
		if (_vtHeap.empty())
			throw out_of_range("Heap is empty");
		else
		{
			int nNodeSize = _vtHeap.size();
			for (int i = nNodeSize - 1; i >= 0; --i)
			{
				_nodeDown(i);
			}
		}
	}
};

#endif	/* __HEAP_ClassH__ */