/**
 * @class BST
*/

#ifndef BST___
#define BST___

#include <iostream>
#include "node.h"
#include <exception>

template <typename T>
class BST
{
public:
	BST() : head(nullptr) {};

	~BST()
	{
		while (head != nullptr)
			remove(head->getItem());
	}

	void insert(T item)
	{
		if (head == nullptr) {
			head = new Node<T>(item, nullptr, nullptr);
		}
		else helperInsert(head, item);
	}

	void helperInsert(Node<T> *begin, T item)
	{
		if (begin->getItem() == item) throw std::exception("duplicate item!");
		if (item < begin->getItem()) {
			if (begin->getL() == nullptr) {
				begin->setL(new Node<T>(item, nullptr, nullptr));
			}
			else helperInsert(begin->getL(), item);
		}
		else {
			if (begin->getR() == nullptr) {
				begin->setR(new Node<T>(item, nullptr, nullptr));
			}
			else helperInsert(begin->getR(), item);
		}
	}

	void remove(T item) {
		head = helperRemove(head, item);
	}

	void getTotal(Node<T> *root, T &total, T &count)
	{
		if (root == nullptr) return;
		total += root->getItem();
		++count;
		getTotal(root->getL(), total, count);
		getTotal(root->getR(), total, count);
	}

	T getAvg()
	{
		T total = 0;
		T count = 0;
		getTotal(head, total, count);
		return (count == 0) ? 0 : total / count;
	}

	Node<T> *helperRemove(Node<T> *begin, T item) {
		if (begin == nullptr) return nullptr;
		if (begin->getItem() == item)
		{
			if (begin->getL() == nullptr && begin->getR() == nullptr) return nullptr; //no children
			if (begin->getL() == nullptr) return begin->getL(); //only has right child
			if (begin->getR() == nullptr) return begin->getR(); //only has left  child

			//both children
			Node<T> *right = begin->getR();
			while (right->getL() != nullptr){
				right = right->getL();
			}

			// copy key field from tmp to T
			begin->getItem() = right->getItem();

			// now delete tmp from T's right subtree and return
			begin->setR(helperRemove(begin->getR(), right->getItem()));

		}
		else if (item < begin->getItem()) {
			begin->setL(helperRemove(begin->getL(), item));
		}
		else {
			Node<T> *tmp = begin->getR();
			begin->setR(helperRemove(begin->getR(), item));
		}

		return begin;
	}

	void print(int order)
	{
		switch (order) {
		case 1:
			helperPrint_preOrder(head);
			break;
		case 2:
			helperPrint_postOrder(head);
			break;
		case 3:
			helperPrint_inOrder(head);
			break;
		}
	}

	void helperPrint_inOrder(Node<T> *begin)
	{
		if (begin == nullptr) return;
		helperPrint_inOrder(begin->getL());
		std::cout << begin->getItem() << std::endl;
		helperPrint_inOrder(begin->getR());
	}


	void helperPrint_preOrder(Node<T> *begin)
	{
		if (begin == nullptr) return;
		std::cout << begin->getItem() << std::endl;
		helperPrint_inOrder(begin->getL());
		helperPrint_inOrder(begin->getR());
	}

	void helperPrint_postOrder(Node<T> *begin)
	{
		if (begin == nullptr) return;
		helperPrint_inOrder(begin->getL());
		helperPrint_inOrder(begin->getR());
		std::cout << begin->getItem() << std::endl;
	}

private:
	Node<T> *head;
};

#endif