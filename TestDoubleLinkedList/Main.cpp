#include <iostream>
#include "LinkedList.h"

// ���� �Լ�.
// �̺�Ʈ ������(listener)�Լ�
void OnListEmptyError()
{
	std::cout << "�����Ͱ� �����ϴ�.\n";
}

int main()
{
	LinkedList<int> list;

	list.AddToFront(10);
	list.AddToFront(20);
	list.AddToFront(30);
	list.AddToFront(40);
}