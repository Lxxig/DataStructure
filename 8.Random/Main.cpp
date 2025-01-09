#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <set>

// �ּ� / �ִ� �� ������ ������ ��ȯ�ϴ� �Լ�.
int RandRange(int min, int max)
{
	// ��.
	int deff = max - min + 1;

	return (rand() * deff) / (RAND_MAX + 1) + min;
}

int main()
{
	std::set<int> s;
	srand(static_cast<unsigned int>(time(nullptr)));
	while (s.size() < 6)
	{
		s.insert(RandRange(1, 46));
	}

	for (int i : s)
	{
		std::cout << i << " ";
	}
}