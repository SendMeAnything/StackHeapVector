﻿////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ■ Win32 콘솔 응용프로그램으로 제작되었습니다. (Visual Studio 2013)
// ■ 실행방법 : 
// - cmd창에서 SortPVector.exe 실행
// - Visual Studio에서 컴파일 후 디버깅 하지 않고 시작(Ctrl+F5)
//
// ■ Stack과 Heap을 직접 구현
// ■ element 4개 이하면 Stack을 사용하고 그 이상이면 Heap을 사용하는 Vector 구현
// ■ 아래와 같은 시나리오 테스트 진행 하였습니다.
//============= 00. TEST Case : Stack 방식으로 element 4개 push
//============= 01. TEST Case : Heap 방식으로 element 5개 push
//============= 02. TEST Case : Stakc+Heap 방식으로 element 1200개 push
//============= 03. TEST Case : STL Make_Heap() 함수로 element 1200개 힙트리 구성
//============= 04. TEST Case : Compare Stakc+Heap vs STL Make_Heap (1200개)
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////