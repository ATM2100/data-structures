#include <stdio.h>
#include "binarytree.hpp"

void print(int& item)
{
	std::cout << item << " ";
}

int main(int argc, char* argv[]) {
	BinaryTree<int> bt;
	int a = 50;
	int b = 3;

	bt.put(0);
	bt.put(42);
	bt.put(10);
	bt.put(90);
	bt.put(50);
	bt.put(20);
	bt.put(10);
	bt.put(3);
	bt.put(-100);
	bt.put(-10000);
	bt.put(-30);
	bt.put(-20);
	bt.put(-2);
	bt.put(-35);

	//std::cout << bt.inorderString() << "\n";

	//std::cout << bt.getHeight();

	std::cout << "\n" << bt.lca(a, b);

	bt.countInRange(3, -100);

	bt.inorderTraversal(print);
	return 0;
}