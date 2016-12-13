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
//   현재 기본 DES Sorting으로 구현됨.
//   추후 사용자 정의 함수로 Sorting 할 수 있도록 업데이트 예정.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Heap
{
public:
	//============= 생성자에서 Input 벡터를 받아서 힙을 구성함.
	Heap(IN vectorType& IN_vtHeap) : _vtHeap(IN_vtHeap) 
	{
		_makeHeap();
	}
	//============= 힙트리 마지막에 새데이터 pushBack하고 부모 노드와 대소 비교하면서 본인의 자리를 찾아들어감. 
	void pushHeap(IN dataType IN_Value)
	{
		_vtHeap.push_back(IN IN_Value);
		_nodeUp(_vtHeap.size() - 1); //============= 해당 함수는 재귀적으로 호출됨
	}
	//============= 힙트리 마지막에 데이터 popBack하고 ROOT 부터 내려가면서 L,R Child 대소 비교해서 힙트리 다시 구성함. 
	void popHeap()
	{
		int nNodeSize = _vtHeap.size();
		if (_vtHeap.empty())
			throw out_of_range("Heap is empty");
		else
		{
			_vtHeap[0] = _vtHeap[nNodeSize - 1];
			_vtHeap.pop_back();
			_nodeDown(0); //============= 해당 함수는 재귀적으로 호출됨
		}
	}
	//============= 벡터 인덱스 0이 힘트리 ROOT를 의미함
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