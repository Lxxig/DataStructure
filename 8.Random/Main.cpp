#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <set>

// 최소 / 최대 값 사이의 랜덤을 반환하는 함수.
int RandRange(int min, int max)
{
	// 차.
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