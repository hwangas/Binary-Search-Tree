/**
 *@class Node
 */

#ifndef NODE___
#define NODE___

template <typename T>
class Node
{
public:

	//constructor
	Node(T item_, Node *r_, Node *l_)
		: item(item_), r(r_), l(l_) {};

	~Node() {}

	//accessors
	T &getItem() { return item; }
	Node<T> *getR() { return r; }
	Node<T> *getL() { return l; }

	//mutators
	void setItem(T arg) { item = arg; }
	void setR(Node *r_) { r = r_; }
	void setL(Node *l_) { l = l_; }

private:
	T item;
	Node<T> *r;
	Node<T> *l;
};

#endif