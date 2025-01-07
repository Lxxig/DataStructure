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
	// 크기가 10인 int형 배열.
	int array[10] = { 0,1,2,3,4,5,6,7,8,9 };
	
	// 힙 배열
	int* heapArray = new int[10] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	delete[] heapArray;

	// 배열 객체.
	Array<int, 10> arrayObject;
	arrayObject[0] = 10;
	arrayObject[1] = 20;
	arrayObject[2] = 30;

	std::cout << arrayObject.Count() << std::endl;
}