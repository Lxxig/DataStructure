#pragma once

template<typename KeyType, typename ValueType>
class Pair
{
public:
	Pair()
		: key(), value()  // 자료형의 기본값이 들어감.
	{

	}
	Pair(KeyType key, ValueType value)
		: key(key), value(value)
	{

	}

	// 연산자 오버로딩
	bool operator==(const Pair<KeyType, ValueType>& other)
	{
		return key == other.key && value == other.value;
	}

	// 연산자 오버로딩
	bool operator!=(const Pair<KeyType, ValueType>& other)
	{
		return !(*this == other);
	}

public:
	// Key
	KeyType key;

	// Value
	ValueType value;
};