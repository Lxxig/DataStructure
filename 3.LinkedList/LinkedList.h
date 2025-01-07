#pragma once

#include "Node.h";

// ��带 ����� �ڷḦ �����ϴ� ��ũ�� ����Ʈ.
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	// ��忡 �߰��ϴ� �Լ�.
	void AddToHead(int data);

	// �� �ڿ� �����ϴ� �Լ�.
	void Insert(int data);

	// �����͸� ������ �˻� �� �����ϴ� �Լ�.
	void Delete(int data);

	// ����� ��� ��� �Լ�.
	void Print();

	// ����� ����� �� ��ȭ �Լ�(Getter).
	__forceinline int Count() const;

private:
	// Head Node
	Node* head = nullptr;

	// ����� �ڷ� ���� ��Ÿ���� ����.
	int count = 0;
};