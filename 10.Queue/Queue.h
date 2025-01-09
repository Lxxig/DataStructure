#pragma once

#include <iostream>

// ť�� �ִ� ũ��.
const int maxSize = 10;

class Queue
{
public:
	Queue()
	{
		// �迭�� �ʱ� ���� 0���� ����.
		memset(data, 0, sizeof(data));
	}

	// ť�� ������� Ȯ���ϴ� �Լ�.
	bool IsEmpty() const
	{
		return front == rear;
	}

	// ť�� ���� á���� Ȯ���ϴ� �Լ�.
	bool IsFull() const
	{
		return (rear + 1) % maxSize == front;
	}

	// ������ �߰�.
	void Enqueue(int value)
	{
		if(IsFull())
		{
			std::cout << "error: ť�� ������.\n";
			return;
		}

		// ������ �߰��� �ε��� ��� �� ����.
		rear = (rear + 1) % maxSize;
		data[rear] = value;
	}

	// ������ ����.
	bool Dequeue(int& outValue)
	{
		if (IsEmpty())
		{
			std::cout << "error: ť�� �������.\n";
			return false;
		}

		// ������ ������ ��ġ�� ã�Ƽ� ����.
		front = (front + 1) % maxSize;
		outValue = data[front];
		return true;
	}

	// ���.
	void Print()
	{
		std::cout << " ť ����: ";

		int max = (front < rear) ? rear : rear + maxSize;

		for (int i = front + 1; i <= max; ++i)
		{
			std::cout << data[i % maxSize] << " ";
		}
		std::cout << "\n";
	}


private:
	// �����Ͱ� ��µǴ� ��ġ.
	int front = 0;

	// �����Ͱ� �ԷµǴ� ��ġ.
	int rear = 0;

	// ������ �����.
	int data[maxSize];

};