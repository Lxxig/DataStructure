#pragma once

#include "Node.h";

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

// 노드를 사용해 자료를 저장하는 링크드 리스트.
template<typename T>
class LinkedList
{
public:
	// 오류 발생 함수 포인터 변수
	using ListEmptyErrorEvent = void (*)();

	// 비교 함수 타입 선언.
	using Comparer = bool (*)(T& left, T& right);

public:
	LinkedList()
		:DummyNode(new Node<T>())
	{
		DummyNode->previous = DummyNode;
		DummyNode->next = DummyNode;
	}

	LinkedList(ListEmptyErrorEvent errorHandler)
		:DummyNode(new Node<T>())
	{
		errorEvent = errorHandler;
		DummyNode->previous = DummyNode;
		DummyNode->next = DummyNode;
	}

	void AddToFront(const T& data)
	{
		Node<T>* newNode = new Node<T>(data);
		Node<T>* next = DummyNode->next;
		newNode->next = next;
		newNode->previous = DummyNode;

		DummyNode->next = newNode;
		next->previous = newNode;

		++count;

		// [d] <-> [d]
		// [d] <-> newNode1 <-> [d]
		// [d] <-> newNode2 <-> newNode1 <-> [d]
		// [d] <-> newNode3 <-> newNode2 <-> newNode1 <-> [d]
	}

private:
	Node<T>* DummyNode = nullptr;

	// 저장된 자료 수를 나타내는 변수.
	int count = 0;

	// 함수 포인터 변수
	ListEmptyErrorEvent errorEvent = nullptr;
};