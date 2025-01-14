#include "HashTable.h"
#include <iostream>

// 해시 함수. - 잘알아 두기.
int GenerateHash(std::string keyString)
{
    // 전달 받은 문자열의 길이 확인.

    // 생성할 키.
    int hash = 0;
    for (int i = 0; i < (int)keyString.size(); ++i)
    {
        hash = hash * 31 + keyString[i];
    }

    return  hash < 0 ? -hash : hash;
}

void HashTable::Add(std::string key, std::string value)
{
    // 인덱스 구하기.
    int bucketIndex = GenerateHash(key) % bucketCount;

    // 저장할 위치에 있는 컨테이너 가져오기.
    auto& position = table[bucketIndex];

    // 해시 테이블은 중복을 허용하지 않음.
    // -> 검색.
    for (int i = 0; i < (int)position.size(); ++i)
    {
        if(position[i].key == key)  // 문자열 비교.
        {
            std::cout << "이미 같은 키가 저장되어 있어 삽입 실패\n";
            return;
        }
    }

    // 데이터 삽입.
    position.push_back(Entry(key, value));
}

void HashTable::Delete(std::string key)
{
    // 인덱스 구하기.
    int bucketIndex = GenerateHash(key) % bucketCount;

    // 삭제할 위치에 있는 컨테이너 가져오기.
    auto& position = table[bucketIndex];

    // 검색.
    for (int i = 0; i < (int)position.size(); ++i)
    {
        // 키 비교
        if (position[i].key == key)  // 문자열 비교.
        {
            position.erase(position.begin() + i);
            std::cout << "키: " << key << " 항목을 삭제.\n";
            return;
        }
    }

    // 검색 실패.
    std::cout << "삭제할 데이터 항목을 찾지 못했습니다.\n";
}

bool HashTable::Find(std::string key, Entry& outValue)
{
    // 인덱스 구하기.
    int bucketIndex = GenerateHash(key) % bucketCount;

    // 검색할 위치에 있는 컨테이너 가져오기.
    auto& position = table[bucketIndex];
    
    // 예외처리.
    if (position.size() == 0)
    {
        std::cout << "해당 키로 항목을 찾지 못했습니다.\n";
    }

    // 검색.
    for (int i = 0; i < (int)position.size(); ++i)
    {
        // 키 비교.
        if (position[i].key == key)
        {
            // 검색에 성공했으면, 값 출력.
            outValue = position[i];
            return true;
        }
    }

    std::cout << "해당 키로 항목을 찾지 못했습니다.\n";
    return false;
}

void HashTable::Print()
{
    for (int i = 0; i < bucketCount; ++i)
    {
        // 건너뛸 수 잇는 상황.
        if (table[i].size() == 0) continue;
        
        // 출력.
        for (auto& entry : table[i])
        {
            std::cout << "key: " << entry.key << " value: " << entry.value << "\n";
        }
    }
}
