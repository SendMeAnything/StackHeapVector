#include "stdafx.h"

//============= for DisplayVector() function
#include <iostream>
#include <string>
#include <iomanip>   

//============= for SHVector Validation
#include <vector>
#include <algorithm>
#include <functional> 

//============= for random-number generation
#include <cstdlib>   

//============= Custom vector structure ( using Stack & Heap)
#include "SHVector.h"


void DisplayVector(IN string SortingMethod, IN vectorType IN_SortedVector)
{
	cout << "==================================" << SortingMethod.c_str() << endl;
	for (unsigned int i = 0; i < IN_SortedVector.size(); i++)
	{
		cout << "[" << i << "] " << setw(5) << IN_SortedVector[i] << endl;
	}
	cout << "----------------------------------" << endl;
}

//============= Will DO : 사용자 정의 함수로 Heap에 정렬 기준을 정하도록..
//============= Will DO : Google Test 사용해서 테스트 할 수 있도록..(함수 수행시간 측정과 테스트 결과 비교해 보기가 용이함)

//============= Main Function
//============= 00. TEST Case : Stack 방식으로 element 4개 push
//============= 01. TEST Case : Heap 방식으로 element 5개 push
//============= 02. TEST Case : Stakc+Heap 방식으로 element 1200개 push
//============= 03. TEST Case : STL Make_Heap() 함수로 element 1200개 힙트리 구성
//============= 04. TEST Case : Compare Stakc+Heap vs STL Make_Heap (1200개)
int _tmain(int argc, _TCHAR* argv[])
{
	vectorType vector;
	SHVector customVector(IN vector);

	//============= 00. TEST Case : Stack 방식으로 element 4개 push
	for (int i = 0; i < 4; i++)
	{
		customVector.push(IN i );
	}
	DisplayVector("Stack DataSET 4 EA", vector);
	cout << "TOP :   " << customVector.top() << endl;

	//============= 01. TEST Case : Heap 방식으로 element 5개 push
	customVector.push(IN 4);
	DisplayVector("Heap DataSET 5 EA", vector);
	cout << "TOP :   " << customVector.top() << endl;
	
	//============= 02. TEST Case : Stakc+Heap 방식으로 element 1200개 push
	vectorType vectorDataSET;
	vectorType vectorDataSET2;
	for (int i = 0; i < 1200; i++)
	{
		vectorDataSET.push_back(IN rand());
	}
	vectorDataSET2 = vectorDataSET; //============= Copy vectorDataSET -> vectorDataSET2 
	SHVector customVectorDataSET(IN vectorDataSET);
	cout << "==================================" << "DataSET 1200 EA" << endl;
	cout << "SHVector TOP : " << customVectorDataSET.top() << endl;

	//============= 03. TEST Case : STL Make_Heap() 함수로 element 1200개 힙트리 구성
	make_heap(IN vectorDataSET2.begin(), IN vectorDataSET2.end());
	cout << "STL Heap TOP : " << customVectorDataSET.top() << endl;

	//============= 04. TEST Case : Compare Stakc+Heap vs STL Make_Heap (1200개)
	bool areEqual = equal(vectorDataSET.begin(), vectorDataSET.end(), vectorDataSET2.begin());
	string equalResult = "";
	if (areEqual)
		equalResult = "TRUE";
	else
		equalResult = "FALSE";
	cout << "Equal SHVector vs STL Heap (All data comparing(1200 EA)): " << equalResult << endl;

	return 0;
}

