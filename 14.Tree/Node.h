#pragma once

#include "List.h"



// Ʈ���� ��� Ŭ����.
template<typename T>
class Node
{

	// ģ�� ���.
	// friend class Node<T>;  // ��� ���ص���.

	template<typename T>
	friend class Tree;

public:
	Node(const T& data = T())
		:data(data)
	{
		// �ڼ� ��� ������ ����Ʈ ����.
		children = new List<Node<T>*>();
	}

	// ���� ������ ����.
	Node(const Node& other) = delete;

	// �Ҹ���.
	~Node()
	{
		parent = nullptr;
		delete[] children;
		children = nullptr;
	}

	// ���� �����ؼ� �ڼ��� �߰��ϴ� �Լ�.
	void AddChild(const T& newData)
	{
		AddChild(new Node<T>(newData));
	}

	// ������ ��带 ���� �߰��� �ڼ��� �߰��ϴ� �Լ�.
	void AddChild(Node<T>* newChild)
	{
		// �θ� ��� ����.
		newChild->parent = this;

		// �ڼ� ��� ����Ʈ�� ���ο� �ڼ� �߰�.
		children->PushBack(newChild);
	}

	// �ڼ� �簡�� �Լ� -> ������ �ڼ� ��带 ����.
	void RemoveChild(Node<T>& child)
	{
		// ��������� �˻��ؼ� ����.
		RemoveChildRecursive(child);
	}

	// ���� ��带 ������ ����� ���� ��ȯ�ϴ� �Լ�.
	int Getcount()
	{
		// ��� ���� �� �� �ڽ� ����.
		int count = 1;

		// �ڼ� ��� �� ����.
		for (int i = 0; i < children->Size(); ++i)
		{
			count += children->At(i)->GetCount();
		}

		return count;
	}

private:
	// ��������� �����ϴ� �Լ�.
	void RemoveChildRecursive(Node<T>* child)
	{
		// ���� ó��.
		if (child == nullptr) return;
		
		// ã�Ƽ� ����.
		
		// ���� ��� ����Ʈ Ȯ��.
		List<Node<T>*>* children = child->children;

		// ����� ��1: �ڼ��� ���� ���.
		// children�� null�̰ų� ��Ⱑ 0�� ���.
		if (children == nullptr || children->Size() == 0)
		{
			// �θ��� �ڼ� ��Ͽ��� �ڽ��� ����.
			child->parent->children->Remove(child);

			// ��� ����.
			delete child;

			return;
		}

		// ����� ��2: �ڼ��� �ִ� ���.
		while (children != nullptr && children->Size() > 0)
		{
			// �ڼ��� ��ȸ�ϸ鼭 ��������� �ڼ��� ���� ��� ����.
			RemoveChildRecursive(children->At(0));
		}

		// ��� �ڼ��� ������ �Ŀ� �θ� ��忡�� ����.
		child->parent->children->Remove(child);

		// �޸� ����.
		delete child;
		child = nullptr;
	}

private:
	// ��忡 �����ϴ� ������.
	T data;

	// �θ� ���.
	Node<T>* parent = nullptr;

	// �ڼ� ��� ���.
	List<Node<T>*>* children = nullptr;

};