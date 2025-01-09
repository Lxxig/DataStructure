#include "Stack.h"
#include <stdlib.h>
#include <time.h>

// 최소 / 최대 값 사이의 랜덤을 반환하는 함수.
int RandRange(int min, int max)
{
	// 차.
	int deff = max - min + 1;

	return (rand() * deff) / (RAND_MAX + 1) + min;
}

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	Stack<int> stack;

	if (stack.Push(RandRange(3, 10)))
	{
		std::cout << "경험처 3 ~ 10\n";
	}
	if (stack.Push(RandRange(3, 10)))
	{
		std::cout << "경험처 3 ~ 10\n";
	}
	if (stack.Push(RandRange(3, 10)))
	{
		std::cout << "경험처 3 ~ 10\n";
	}
	if (stack.Push(RandRange(3, 10)))
	{
		std::cout << "경험처 3 ~ 10\n";
	}

	// 출력.
	int count = stack.Count();
	for (int i = 0; i < count; ++i)
	{
		int value;
		if (stack.Pop(value))
		{
			std::cout << "현재 경험치: " << value << "\n";
		}
	}
}