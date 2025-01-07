#include <iostream>
#include <array>

template<typename T ,size_t size>
class Array
{
public:
	T& operator[](T index)
	{
		return data[index];
	}

	size_t Count() const { return size; }


private:
	T data[size];
};

void Function(Array<int, 10>& array)
{

}

int main()
{
	// ũ�Ⱑ 10�� int�� �迭.
	int array[10] = { 0,1,2,3,4,5,6,7,8,9 };
	
	// �� �迭
	int* heapArray = new int[10] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	delete[] heapArray;

	// �迭 ��ü.
	Array<int, 10> arrayObject;
	arrayObject[0] = 10;
	arrayObject[1] = 20;
	arrayObject[2] = 30;

	std::cout << arrayObject.Count() << std::endl;
}