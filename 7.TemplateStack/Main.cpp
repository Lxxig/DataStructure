#include "Stack.h"
#include <stdlib.h>
#include <time.h>

// �ּ� / �ִ� �� ������ ������ ��ȯ�ϴ� �Լ�.
int RandRange(int min, int max)
{
	// ��.
	int deff = max - min + 1;

	return (rand() * deff) / (RAND_MAX + 1) + min;
}

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	Stack<int> stack;

	if (stack.Push(RandRange(3, 10)))
	{
		std::cout << "����ó 3 ~ 10\n";
	}
	if (stack.Push(RandRange(3, 10)))
	{
		std::cout << "����ó 3 ~ 10\n";
	}
	if (stack.Push(RandRange(3, 10)))
	{
		std::cout << "����ó 3 ~ 10\n";
	}
	if (stack.Push(RandRange(3, 10)))
	{
		std::cout << "����ó 3 ~ 10\n";
	}

	// ���.
	int count = stack.Count();
	for (int i = 0; i < count; ++i)
	{
		int value;
		if (stack.Pop(value))
		{
			std::cout << "���� ����ġ: " << value << "\n";
		}
	}
}