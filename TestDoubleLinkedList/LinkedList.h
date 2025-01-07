#pragma once

#include "Node.h";

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

// ��带 ����� �ڷḦ �����ϴ� ��ũ�� ����Ʈ.
template<typename T>
class LinkedList
{
public:
	// ���� �߻� �Լ� ������ ����
	using ListEmptyErrorEvent = void (*)();

	// �� �Լ� Ÿ�� ����.
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

	// ����� �ڷ� ���� ��Ÿ���� ����.
	int count = 0;

	// �Լ� ������ ����
	ListEmptyErrorEvent errorEvent = nullptr;
};