#include <iostream>
#include "String.h"
#include "Node.h"
#include "Tree.h"

int main()
{
	Tree<String> tree("A");
	tree.AddChild("B");
	tree.AddChild("B", "E");
	tree.AddChild("B", "F");
	tree.AddChild("B", "G");

	tree.AddChild("C");
	tree.AddChild("C", "H");

	tree.AddChild("D");
	tree.AddChild("D", "I");
	tree.AddChild("D", "J");
}