#include <iostream>
#include "BST.h"
int main()
{
	std::cout << "this is to demonstrate the binary search tree" << std::endl;
	BST<int> myBST;
	myBST.insert((int) 1);
	myBST.insert((int) 2);
	myBST.insert((int)-1);
	myBST.insert((int)0);

	//myBST.remove(0);

	myBST.print(1);

	//std::cin.get();
}