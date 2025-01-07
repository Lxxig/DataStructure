#include <iostream>
#include "LinkedList.h"

// 오류 함수.
// 이벤트 리스너(listener)함수
void OnListEmptyError()
{
	std::cout << "데이터가 없습니다.\n";
}

int main()
{
	LinkedList<int> list;

	list.AddToFront(10);
	list.AddToFront(20);
	list.AddToFront(30);
	list.AddToFront(40);
}