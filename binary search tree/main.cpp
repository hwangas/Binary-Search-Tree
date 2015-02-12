#include <iostream>
#include "BST.h"
int main()
{
	std::cout << "this is to demonstrate the binary search tree" << std::endl;
	BST<double> myBST;
	myBST.insert(1);
	myBST.insert(2);
	myBST.insert(-1);
	myBST.insert(0);

	std::cout << "avg = " << myBST.getAvg() << std::endl;

	myBST.print(1);

	std::cin.get();
}