#include <iostream>
#include "Queue.h"

int main()
{
	Queue queue;

	for (int i = 0; i < 10; ++i)
	{
		queue.Enqueue(i + 10);
	}
	
	queue.Print();
}