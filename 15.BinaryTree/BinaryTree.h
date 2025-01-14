#pragma once

#include "Node.h"

template<typename T>
class BinaryTree
{
public:
	BinaryTree(const T& data)
	{
		root = new Node<T>(data);
	}

	~BinaryTree()
	{
		root->Destroy();
	}

	void AddLeftChild(const T& parentData, const T& childData)
	{
		// �θ� ��� �˻�.
		Node<T>* outParent = nullptr;
		if (Find(parentData, &outParent))
		{
			outParent->AddLeftChild(childData);
			return;
		}

		// �˻� �����ϸ� �޽��� ���.
		std::cout << "Error: �θ� ��带 ã�� ���� �ڼ� ��� �߰� ����.\n";
	}

	void AddRightChild(const T& parentData, const T& childData)
	{
		// �θ� ��� �˻�.
		Node<T>* outParent = nullptr;
		if (Find(parentData, &outParent))
		{
			outParent->AddRightChild(childData);
			return;
		}

		// �˻� �����ϸ� �޽��� ���.
		std::cout << "Error: �θ� ��带 ã�� ���� �ڼ� ��� �߰� ����.\n";
	}

	bool Find(const T& data, Node<T>** outNode)
	{
		return FindRecursive(data, root, outNode);
	}

	// �����͸� ������� ��鸣 �����ϴ� �Լ�.
	bool DeleteNode(const T& data)
	{
		// ���� ��� �˻�.
		Node<T>* outNode = nullptr;
		if (Find(data, &outNode))
		{
			// �˻��� ��� ����.
			outNode->Destroy();
			return true;
		}

		// �˻��� ���������� �޽��� ���.
		std::cout << "������ ��� �˻� ����. ���� ����.\n";
		return false;
	}

	// ���� ��ȸ �Լ�.
	void PreorderTraverse(int depth = 0)
	{
		std::cout << "���� ��ȸ ����--------------\n";
		PreorderTraverseRecursive(root, depth);
		std::cout << "���� ��ȸ ��--------------\n";
	}

private:
	void PreorderTraverseRecursive(Node<T>* node, int depth)
	{
		// Ż�� ����.
		if (node == nullptr)
		{
			return;
		}

		// ���� ���.
		for (int i = 0; i < depth; ++i)
		{
			std::cout << " ";
		}

		// data ���.
		std::cout << node->data << "\n";

		// ���� ���� ��� ���.
		PreorderTraverseRecursive(node->left, depth + 1);

		// ������ ���� ��� ���.
		PreorderTraverseRecursive(node->right, depth + 1);
	}


	bool FindRecursive(const T& data, Node<T>* node, Node<T>** outNode)
	{
		if (node == nullptr)
		{
			*outNode = nullptr;
			return false;
		}

		// ���� ��忡�� ����.
		if (node->data == data)
		{
			*outNode = node;
			return true;
		}

		// ���� ������ �������� �˻�.
		if (FindRecursive(data, node->left, outNode))
		{
			return true;
		}

		// ������ ������ ������ �˻�.
		if (FindRecursive(data, node->right, outNode))
		{
			return true;
		}

		// �˻� ����.
		*outNode = nullptr;
		return false;
	}

private:
	// ��Ʈ ���.
	Node<T>* root = nullptr;

};