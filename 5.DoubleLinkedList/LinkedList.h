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
		:first(new Node<T>()), last(new Node<T>())
	{ 
		// ������ ���� first�� last�� ���� ����Ű�� ����.
		first->next = last;
		last->previous = first;
	} 

	LinkedList(ListEmptyErrorEvent errorHandler)
		: LinkedList<T>()
	{
		errorEvent = errorHandler;
	}

	~LinkedList()
	{
		// Todo: ���� �Լ� ���� �� ȣ���ؾ� ��.
		if (count > 0) Clear();

		delete first;
		delete last;
	}

	// ���� �Լ�.
	void Clear()
	{
		// ����Ʈ�� ��������� ���� �߻�
		if (count == 0)
		{
			RaiseEmptyErrorEvent();
			return;
		}
		// ù ��忡�� ���� ����.
		Node<T>* current = first->next;

		// ��� ��� ����.
		while (current != nullptr && current != last)
		{
			// ���� ����.
			Node<T>* next = current->next;
			delete current;
			current = next;
		}

		// ���� ������ ����.
		count = 0;
		first->next = last;
		last->previous = first;
	}

	// ����Ÿ�� ��� ���� �� ���� �̺�Ʈ�� �߻���Ű�� �Լ�.
	// Raise, Invoke(���� ȣ��). 
	void RaiseEmptyErrorEvent()
	{
		if (errorEvent != nullptr)
		{
			errorEvent();
		}
	}

	// ��忡 �߰��ϴ� �Լ�.
	void AddToFirst(const T& data)
	{
		// �� ��� ����.
		Node<T>* newNode = new Node<T>(data);

		// �� ����� ���� ��带  first->next ���� ����,
		// �� ����� ���� ��带 first�� ����.
		Node<T>* next = first->next;
		newNode->next = next;
		newNode->previous = first;

		// ù ���(first->next)�� �� ���� ����.
		// ���� ù ����� ���� ��带 �� ���� ����.
		first->next = newNode;
		next->previous = newNode;

		// last�� �ƴ϶� next�� ����
		// first <-> add1 <-> last
		// first <-> add2 <-> add1 <-> last
		// ��, last->previous�� �Ǹ� ��� �ϳ��� �̹� 
		// �����Ѵٰ� �� ���� ��Ȳ������ �ȵȴ�. �׷��⿡ 
		// next��带 �ϳ� �� ���� �����ϴ� ���̴�.
		//

		// ����� ��� �� ���� ó��.
		++count;
	}

	// �� �ڿ� �����ϴ� �Լ�.
	void AddToLast(const T& data)
	{
		// �� ��� ����.
		Node<T>* newNode = new Node<T>(data);

		Node<T>* previous = last->previous;
		newNode->previous = previous;
		newNode->next = last;

		previous->next = newNode;
		last->previous = newNode;

		// ����� ��� �� ���� ó��.
		++count;
	}

	// �����͸� ������ �˻� �� �����ϴ� �Լ�.
	void Delete(const T& data, Comparer cmp = nullptr)
	{
		// ���� ó��.
		if (count == 0)
		{
			RaiseEmptyErrorEvent();
			return;
		}

		// ������ ��� �˻�.
		Node<T>* deleteNode = first->next;
		while (deleteNode != nullptr && deleteNode != last)
		{
			// ã������ ����
			if (deleteNode->data == data)
			{
				break;
			}

			// ���� ���� �̵�(�˻� ��� ����).
			deleteNode = deleteNode->next;
		}

		// ���� ó��.
		if (deleteNode == nullptr || deleteNode == last)
		{
			RaiseEmptyErrorEvent();
			return;
		}

		// ����.
		deleteNode->previous->next = deleteNode->next;
		deleteNode->next->previous = deleteNode->previous;

		// ��� �� ����.
		--count;
	}

	Node<T>* Find(const T& data)
	{
		Node<T>* current = first->next;
		while (current != nullptr && current != last)
		{
			if (current->data == data)
			{
				return current;
			}
			current = current->next;
		}
		// �� ã���� ���.
		return nullptr;
	}

	// ����� ��� ��� �Լ�.
	void Print()
	{
		Node<T>* current = first->next;
		while (current != nullptr && current != last)
		{
			std::cout << "Data: " << current->data << "\n";
			current = current->next;
		}
	}

	// ����� ����� �� ��ȭ �Լ�(Getter).
	__forceinline int Count() const
	{
		return count;
	}

private:
	// Head(����) Node
	Node<T>* first = nullptr;

	// ������ ���
	Node<T>* last = nullptr;

	// ����� �ڷ� ���� ��Ÿ���� ����.
	int count = 0;

	// �Լ� ������ ����
	ListEmptyErrorEvent errorEvent = nullptr;
};