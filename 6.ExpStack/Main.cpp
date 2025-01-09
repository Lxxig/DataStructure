#include <iostream>
#include "ExpStack.h"

int main()
{
	ExpStack stack;
	std::cout << "ù ��° ���� ���� - ����ġ 140\n";
	stack.Push(140.0f);

	std::cout << "ù ��° ���� ���� - ����ġ 180\n";
	stack.Push(180.0f);

	std::cout << "ù ��° ���� ���� - ����ġ 200\n";
	stack.Push(200.0f);

	// ���.
	int count = stack.Count();
	for (int i = 0; i < count; ++i)
	{
		float value;
		if(stack.Pop(value))
		{
			std::cout << "���� ����ġ: " << value << "\n";
		}
	}
}