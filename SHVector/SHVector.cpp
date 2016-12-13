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

//============= Will DO : ����� ���� �Լ��� Heap�� ���� ������ ���ϵ���..
//============= Will DO : Google Test ����ؼ� �׽�Ʈ �� �� �ֵ���..(�Լ� ����ð� ������ �׽�Ʈ ��� ���� ���Ⱑ ������)

//============= Main Function
//============= 00. TEST Case : Stack ������� element 4�� push
//============= 01. TEST Case : Heap ������� element 5�� push
//============= 02. TEST Case : Stakc+Heap ������� element 1200�� push
//============= 03. TEST Case : STL Make_Heap() �Լ��� element 1200�� ��Ʈ�� ����
//============= 04. TEST Case : Compare Stakc+Heap vs STL Make_Heap (1200��)
int _tmain(int argc, _TCHAR* argv[])
{
	vectorType vector;
	SHVector customVector(IN vector);

	//============= 00. TEST Case : Stack ������� element 4�� push
	for (int i = 0; i < 4; i++)
	{
		customVector.push(IN i );
	}
	DisplayVector("Stack DataSET 4 EA", vector);
	cout << "TOP :   " << customVector.top() << endl;

	//============= 01. TEST Case : Heap ������� element 5�� push
	customVector.push(IN 4);
	DisplayVector("Heap DataSET 5 EA", vector);
	cout << "TOP :   " << customVector.top() << endl;
	
	//============= 02. TEST Case : Stakc+Heap ������� element 1200�� push
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

	//============= 03. TEST Case : STL Make_Heap() �Լ��� element 1200�� ��Ʈ�� ����
	make_heap(IN vectorDataSET2.begin(), IN vectorDataSET2.end());
	cout << "STL Heap TOP : " << customVectorDataSET.top() << endl;

	//============= 04. TEST Case : Compare Stakc+Heap vs STL Make_Heap (1200��)
	bool areEqual = equal(vectorDataSET.begin(), vectorDataSET.end(), vectorDataSET2.begin());
	string equalResult = "";
	if (areEqual)
		equalResult = "TRUE";
	else
		equalResult = "FALSE";
	cout << "Equal SHVector vs STL Heap (All data comparing(1200 EA)): " << equalResult << endl;

	return 0;
}

