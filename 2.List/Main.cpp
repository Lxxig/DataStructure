#include <iostream>
#include <vector>		// ���� �迭.
//#include <list>		// ���� ����Ʈ

// ���� ���̺귯��
// Vector2 / Vector3 / Vector4

// Iterator (�ݺ���)
template<typename Vector>
class VectorIterator
{
public:
	// Ÿ�� ����.
	using ValueType = typename Vector::ValueType;  // Vector<T>
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;

public:
	VectorIterator(PointerType pointer)
		:pointer(pointer)
	{

	}

	// ������ ���� ������ �����ε�
	// ������ ���� ���� ������.
	VectorIterator& operator++()
	{
		++pointer;
		return *this;
	}

	// ������ ���� ���� ������ �����ε�
	VectorIterator& operator++(int)
	{
		VectorIterator iterator = *this;
		++(*this);
		return *iterator;
	}

	// ������ ���� ���� ������.
	VectorIterator& operator--()
	{
		--pointer;
		return *this;
	}

	// ������ ���� ���� ������ �����ε�
	VectorIterator& operator--(int)
	{
		VectorIterator iterator = *this;
		--(*this);
		return *iterator;
	}

	// �ε��� ������ �����ε�.
	ReferenceType operator[](int index)
	{
		return *(pointer + index);
	}

	// ������ ������ �����ε�
	PointerType operator->()
	{
		return pointer;
	}

	// �� ��ȯ ������
	ReferenceType operator*()
	{
		return *pointer;
	}

	// �� ������.
	bool operator==(const VectorIterator& other) const
	{
		return pointer != other.p0inter;
		//return !(*this == other);
	}

	bool operator!=(const VectorIterator& other) const
	{
		return pointer != other.pointer;
		//return !(*this != other);
	}

private:
	PointerType pointer;
};

// ���� �迭(����Ʈ) Ŭ����
template<typename T>
class List
{
public:
	using ValueType = T;
	using Iterator = VectorIterator<List<T>>;

public:
	List()
	{
		// �ʱ� ������ ���� ����.
		data = new T[capacity];
	}
	~List()
	{
		// �����Ͱ� ����Ű�� �� �迭 ���� ����.
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}

	// ���� �߰�.
	void pushBack(const T& value)
	{
		// �ڷḦ �߰��� �� �ִ� ������ �ִ��� Ȯ��.
		if (count == capacity)
		{
			ReAllocate(capacity * 2);
		}

		// ���� �迭�� ������ ��ҿ� ���޹��� ������ ����.
		data[count] = value;

		// ����� ����� �� ���� ó��.
		++count;
	}

	// Move �߰�.
	void PushBAck(T&& value)
	{
		// �ڷḦ �߰��� �� �ִ� ������ �ִ��� Ȯ��.
		if (count == capacity)
		{
			ReAllocate(capacity * 2);
		}

		// ���� �迭�� ������ ��ҿ� ���޹��� ������ ����.
		data[count] = std::move(value);

		// ����� ����� �� ���� ó��.
		++count;
	}

	// ���� �Լ�.
	const T& At(int index) const
	{
		// ����ó��
		if (index >= count)
		{
			__debugbreak();
		}
		return data[index];
	}

	// ������ �����ε�.
	T& operator[](int index)
	{
		// ����ó��
		if (index >= count)
		{
			__debugbreak();
		}
		return data[index];
	}

	const T& operator[](int index) const
	{
		// ����ó��
		if (index >= count)
		{
			__debugbreak();
		}
		return data[index];
	}

	// Iterator���� Function
	Iterator begin()
	{
		return Iterator(data);
	}

	Iterator end()
	{
		return Iterator(data + count);
	}

	// Getter.
	// ��� �� ��ȯ.
	int Count() const { return count; }

	// ���� �뷮 ��ȯ.
	int Capacity() const { return capacity; }

	// �迭 �ּ� ��ȯ.
	T* Data() const { return data; }

	// �迭 �ּ� ��ȯ.
private:
	// ������ ������ ������ �� ������ �ø��� �Լ�.
	void ReAllocate(int newCapacity)
	{
		// 1. ���ο� �޸� ���� �Ҵ�.(Allocate)
		// 2. ���� ������ ����.
		// 3. ���� ������ �� �ӽ� ������ ����.
		T* newBlock = new T[newCapacity];

		// ����.
		//for (int i = 0; i < count; ++i)
		//{
		//	//newBlock[i] = data[i];
		//	newBlock[i] = std::move(data[i]);
		//}

		memcpy(newBlock, data, sizeof(T) * count);

		delete[] data;
		data = newBlock;
		capacity = newCapacity;
	}

private:
	// ������ ���� (���� �Ҵ��� �迭 ����)
	T* data = nullptr;

	// �뷮.
	int capacity = 2;

	// �迭�� ���� ��
	int count = 0;

};

int main()
{
	// ���� �迭 ��ü ����.
	List<int> list;

	// ���� �߰�.
	for (int i = 0; i < 100; ++i)
	{
		list.pushBack(i);
	}

	char buffer[256];
	snprintf(buffer, 256, "%d, %d\n", list.Count(), list.Capacity());

	std::cout << buffer;

	std::vector<int> vector;

	//for (int i = 0; i < 100; ++i)
	//{
	//	vector.push_back(i);
	//}

	// �б�.
	//for (const auto& item : vector)
	//{
	//	std::cout << item << " ";
	//}

	for (const auto& item : list)
	{
		std::cout << item << " ";
	}

	std::cout << "\n";

	for (auto iterator = list.begin(); iterator != list.end(); ++iterator)
	{
		std::cout << *iterator << " ";
	}
	
	std::cout << "\n";

	snprintf(buffer, 256, "%d, %d", static_cast<int>(vector.size()), static_cast<int>(vector.capacity()));

	std::cout << buffer;
}