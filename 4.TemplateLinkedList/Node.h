#pragma once

#include <iostream>

// 링크드 리스트의 요소인 노드 클래스.
template<typename T>
class Node
{
	// 예외. - friend라는 키워드는 좋은 방법은 아니다.
	template<typename T>
	friend class LinkedList;

public:
	Node()
		// 타입의 기본값을 찾아서 초기화 (숫자면 0, 포인터면 nulltpr)
		:data()  
	{
	}
	Node(T data)
		: data(data)
	{
	}

private:
	// 데이터 필드.
	T data;

	// 링크 필드.
	Node<T>* next = nullptr;
};