#pragma once

#include <vector>
#include "Pair.h"
#include <string>

class HashTable
{
	// Alias
	using Entry = Pair<std::string, std::string>;

public:
	HashTable() = default;
	~HashTable() = default;

	void Add(std::string key, std::string value);
	void Delete(std::string key);
	bool Find(std::string key, Entry& outValue);
	void Print();

private:
// ���� ������� ũ�� (�Ҽ�(Prime Number)�� ����ϴ� ���� ����).
	static const int bucketCount = 19;

	//std::vector<Pair<const char*, const char*>>
	std::vector<Entry> table[bucketCount];  // stack overflow �߻��� �� ����.
};