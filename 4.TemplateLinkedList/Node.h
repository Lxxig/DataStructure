#pragma once

#include <iostream>

// ��ũ�� ����Ʈ�� ����� ��� Ŭ����.
template<typename T>
class Node
{
	// ����. - friend��� Ű����� ���� ����� �ƴϴ�.
	template<typename T>
	friend class LinkedList;

public:
	Node()
		// Ÿ���� �⺻���� ã�Ƽ� �ʱ�ȭ (���ڸ� 0, �����͸� nulltpr)
		:data()  
	{
	}
	Node(T data)
		: data(data)
	{
	}

private:
	// ������ �ʵ�.
	T data;

	// ��ũ �ʵ�.
	Node<T>* next = nullptr;
};