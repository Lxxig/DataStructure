#include <iostream>
#include <string>
#include "BinaryTree.h"

int main()
{
	// 飘府 积己.
	BinaryTree<std::string> tree("1");
	tree.AddLeftChild("1", "2");
	tree.AddLeftChild("2", "4");
	tree.AddLeftChild("4", "8");
	tree.AddRightChild("4", "9");
	tree.AddRightChild("2", "5");
	tree.AddLeftChild("5", "10");
	tree.AddRightChild("5", "11");

	tree.AddRightChild("1", "3");
	tree.AddLeftChild("3", "6");
	tree.AddLeftChild("6", "12");
	tree.AddRightChild("6", "13");
	tree.AddRightChild("3", "7");
	tree.AddLeftChild("7", "14");
	tree.AddRightChild("7", "15");

	// 免仿.
	tree.PreorderTraverse();

	// 昏力.
	tree.DeleteNode("3");

	tree.PreorderTraverse();

}