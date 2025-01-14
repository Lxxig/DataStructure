#include <iostream>
#include "HashTable.h"

int main()
{
	// �ؽ� ���̺� ��ü.
	HashTable table;

	table.Add("Lee", "010-7348394");
	table.Add("Kim", "010-7348394");
	table.Add("Choi", "010-7348394");
	table.Add("Park", "010-7348394");
	table.Add("Lee", "010-7348394");

	table.Print();

	Pair<std::string, std::string> value;
	if(table.Find("Lee", value))
	{
		std::cout << "Ű: Lee ã�ҽ��ϴ�.\n ";
	}
	else
	{
		std::cout << "Ű: Lee ã�� ���߽��ϴ�.\n ";
	}

	table.Delete("Lee");
	std::cout << "--- ���� �� ��� --\n";
	table.Print();
}