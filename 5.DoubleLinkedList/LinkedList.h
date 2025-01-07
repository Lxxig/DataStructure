#pragma once

#include "Node.h";

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

// 노드를 사용해 자료를 저장하는 링크드 리스트.
template<typename T>
class LinkedList
{
public:
	// 오류 발생 함수 포인터 변수
	using ListEmptyErrorEvent = void (*)();

	// 비교 함수 타입 선언.
	using Comparer = bool (*)(T& left, T& right);

public:
	LinkedList() 
		:first(new Node<T>()), last(new Node<T>())
	{ 
		// 시작할 때는 first와 last가 서로 가리키게 설정.
		first->next = last;
		last->previous = first;
	} 

	LinkedList(ListEmptyErrorEvent errorHandler)
		: LinkedList<T>()
	{
		errorEvent = errorHandler;
	}

	~LinkedList()
	{
		// Todo: 삭제 함수 구현 후 호출해야 함.
		if (count > 0) Clear();

		delete first;
		delete last;
	}

	// 삭제 함수.
	void Clear()
	{
		// 리스트가 비어있으면 오류 발생
		if (count == 0)
		{
			RaiseEmptyErrorEvent();
			return;
		}
		// 첫 노드에서 부터 시작.
		Node<T>* current = first->next;

		// 모든 노드 삭제.
		while (current != nullptr && current != last)
		{
			// 삭젤 로직.
			Node<T>* next = current->next;
			delete current;
			current = next;
		}

		// 남은 데이터 정리.
		count = 0;
		first->next = last;
		last->previous = first;
	}

	// 리스타가 비어 있을 때 오류 이벤트를 발생시키는 함수.
	// Raise, Invoke(간접 호출). 
	void RaiseEmptyErrorEvent()
	{
		if (errorEvent != nullptr)
		{
			errorEvent();
		}
	}

	// 헤드에 추가하는 함수.
	void AddToFirst(const T& data)
	{
		// 새 노드 생성.
		Node<T>* newNode = new Node<T>(data);

		// 새 노드의 다음 노드를  first->next 노드로 설정,
		// 새 노드의 이전 노드를 first로 설정.
		Node<T>* next = first->next;
		newNode->next = next;
		newNode->previous = first;

		// 첫 노드(first->next)를 새 노드로 설정.
		// 기존 첫 노드의 이전 노드를 새 노드로 설정.
		first->next = newNode;
		next->previous = newNode;

		// last가 아니라 next인 이유
		// first <-> add1 <-> last
		// first <-> add2 <-> add1 <-> last
		// 즉, last->previous가 되면 요소 하나가 이미 
		// 존재한다고 할 때의 상황에서는 안된다. 그렇기에 
		// next노드를 하나 더 만들어서 저장하는 것이다.
		//

		// 저장된 노드 수 증가 처리.
		++count;
	}

	// 맨 뒤에 삽입하는 함수.
	void AddToLast(const T& data)
	{
		// 새 노드 생성.
		Node<T>* newNode = new Node<T>(data);

		Node<T>* previous = last->previous;
		newNode->previous = previous;
		newNode->next = last;

		previous->next = newNode;
		last->previous = newNode;

		// 저장된 노드 수 증가 처리.
		++count;
	}

	// 데이터를 지정해 검색 후 삭제하는 함수.
	void Delete(const T& data, Comparer cmp = nullptr)
	{
		// 예외 처리.
		if (count == 0)
		{
			RaiseEmptyErrorEvent();
			return;
		}

		// 삭제할 노드 검색.
		Node<T>* deleteNode = first->next;
		while (deleteNode != nullptr && deleteNode != last)
		{
			// 찾았으면 종료
			if (deleteNode->data == data)
			{
				break;
			}

			// 다음 노드로 이동(검색 계속 진행).
			deleteNode = deleteNode->next;
		}

		// 예외 처리.
		if (deleteNode == nullptr || deleteNode == last)
		{
			RaiseEmptyErrorEvent();
			return;
		}

		// 삭제.
		deleteNode->previous->next = deleteNode->next;
		deleteNode->next->previous = deleteNode->previous;

		// 요소 수 감소.
		--count;
	}

	Node<T>* Find(const T& data)
	{
		Node<T>* current = first->next;
		while (current != nullptr && current != last)
		{
			if (current->data == data)
			{
				return current;
			}
			current = current->next;
		}
		// 못 찾았을 경우.
		return nullptr;
	}

	// 저장된 요소 출력 함수.
	void Print()
	{
		Node<T>* current = first->next;
		while (current != nullptr && current != last)
		{
			std::cout << "Data: " << current->data << "\n";
			current = current->next;
		}
	}

	// 저장된 요소의 수 반화 함수(Getter).
	__forceinline int Count() const
	{
		return count;
	}

private:
	// Head(시작) Node
	Node<T>* first = nullptr;

	// 마지막 노드
	Node<T>* last = nullptr;

	// 저장된 자료 수를 나타내는 변수.
	int count = 0;

	// 함수 포인터 변수
	ListEmptyErrorEvent errorEvent = nullptr;
};