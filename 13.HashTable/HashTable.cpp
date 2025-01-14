#include "HashTable.h"
#include <iostream>

// �ؽ� �Լ�. - �߾˾� �α�.
int GenerateHash(std::string keyString)
{
    // ���� ���� ���ڿ��� ���� Ȯ��.

    // ������ Ű.
    int hash = 0;
    for (int i = 0; i < (int)keyString.size(); ++i)
    {
        hash = hash * 31 + keyString[i];
    }

    return  hash < 0 ? -hash : hash;
}

void HashTable::Add(std::string key, std::string value)
{
    // �ε��� ���ϱ�.
    int bucketIndex = GenerateHash(key) % bucketCount;

    // ������ ��ġ�� �ִ� �����̳� ��������.
    auto& position = table[bucketIndex];

    // �ؽ� ���̺��� �ߺ��� ������� ����.
    // -> �˻�.
    for (int i = 0; i < (int)position.size(); ++i)
    {
        if(position[i].key == key)  // ���ڿ� ��.
        {
            std::cout << "�̹� ���� Ű�� ����Ǿ� �־� ���� ����\n";
            return;
        }
    }

    // ������ ����.
    position.push_back(Entry(key, value));
}

void HashTable::Delete(std::string key)
{
    // �ε��� ���ϱ�.
    int bucketIndex = GenerateHash(key) % bucketCount;

    // ������ ��ġ�� �ִ� �����̳� ��������.
    auto& position = table[bucketIndex];

    // �˻�.
    for (int i = 0; i < (int)position.size(); ++i)
    {
        // Ű ��
        if (position[i].key == key)  // ���ڿ� ��.
        {
            position.erase(position.begin() + i);
            std::cout << "Ű: " << key << " �׸��� ����.\n";
            return;
        }
    }

    // �˻� ����.
    std::cout << "������ ������ �׸��� ã�� ���߽��ϴ�.\n";
}

bool HashTable::Find(std::string key, Entry& outValue)
{
    // �ε��� ���ϱ�.
    int bucketIndex = GenerateHash(key) % bucketCount;

    // �˻��� ��ġ�� �ִ� �����̳� ��������.
    auto& position = table[bucketIndex];
    
    // ����ó��.
    if (position.size() == 0)
    {
        std::cout << "�ش� Ű�� �׸��� ã�� ���߽��ϴ�.\n";
    }

    // �˻�.
    for (int i = 0; i < (int)position.size(); ++i)
    {
        // Ű ��.
        if (position[i].key == key)
        {
            // �˻��� ����������, �� ���.
            outValue = position[i];
            return true;
        }
    }

    std::cout << "�ش� Ű�� �׸��� ã�� ���߽��ϴ�.\n";
    return false;
}

void HashTable::Print()
{
    for (int i = 0; i < bucketCount; ++i)
    {
        // �ǳʶ� �� �մ� ��Ȳ.
        if (table[i].size() == 0) continue;
        
        // ���.
        for (auto& entry : table[i])
        {
            std::cout << "key: " << entry.key << " value: " << entry.value << "\n";
        }
    }
}
