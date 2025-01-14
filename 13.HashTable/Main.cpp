#include <iostream>
#include "HashTable.h"

int main()
{
	// 해시 테이블 객체.
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
		std::cout << "키: Lee 찾았습니다.\n ";
	}
	else
	{
		std::cout << "키: Lee 찾지 못했습니다.\n ";
	}

	table.Delete("Lee");
	std::cout << "--- 삭제 후 출력 --\n";
	table.Print();
}