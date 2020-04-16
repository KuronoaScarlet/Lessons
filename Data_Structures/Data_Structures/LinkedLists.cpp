#include <iostream>
#include<assert.h>
using namespace std;

// Declaration of a doubly-linked list
class LinkedList {
public:

	// Constructor and destructor
	LinkedList();
	~LinkedList();

	// Modifiers
	void push_front(const int& value)
	{
		if (num_elems == 0)
		{
			first = last = new Node;
			first->value = value;
			first->prev = nullptr;
			first->next = nullptr;
		}
		else
		{
			Node* node = new Node;
			node->value = value;
			node->prev = nullptr;
			node->next = first;
			first->prev = node;
			first = node;
		}
		num_elems++;
	}
	void push_back(const int& value)
	{
		if (num_elems == 0)
		{
			first = last = new Node;
			first->value = value;
			first->prev = nullptr;
			first->next = nullptr;
		}
		else
		{
			Node* node = new Node;
			node->value = value;
			node->prev = last;
			node->next = nullptr;
			last->next = node;
			last = node;
		}
		num_elems++;
	}

	//void pop_front();

	//void pop_back();

	//void insert(unsigned int position, const int& value);

	/*void erase(unsigned int index)
	{
		assert(index < num_elems);
		Node* toErease = first;

		for (int i = 0; i < index; i++)
		{
			toErease = toErease->next;
		}

		if (toErease->prev != nullptr)
		{
			toErease->prev->next = toErease->next;
		}
		else 
		{
			first = toErease->next;
		}

		if (toErease->next != nullptr)
		{
			toErease->next->prev = toErease->prev;
		}
		else
		{
			last = toErease->prev;
		}

		delete toErease;
		num_elems--;
	}*/

	void print()
	{
		Node* it = first;
		while (it != nullptr)
		{
			cout << it->value << endl;
			it = it->next;
		}
	}

	//void clear();

	// Getters
	int& front() { return first->value; }

	int& back() { return last->value; }

	/*int& value_at(unsigned int index)
	{
		Node* it = first;
		for (int i = 0; i <= index; i++)
		{
			if (it->next == nullptr)
			{
				it = last;
				i = index;
			}
			it->next;
		}

		return it->value;
	}*/

	//bool empty() const;

	unsigned int size() const
	{
		
	}
private:

	// Internal struct for list nodes
	struct Node {
		int value;
		Node* next;
		Node* prev;
	};

	// List internals
	Node* first = nullptr;
	Node* last = nullptr;
	unsigned int num_elems = 0;
};int main(){
	LinkedList list1;

	//TODO: push_back, push_front, print
	list1.push_back(10);
	list1.push_back(20);
	list1.push_back(30);
	list1.push_front(0);
	list1.print();
	//Shuold print 0 10 20 30
	

	system("pause");	return 0;}