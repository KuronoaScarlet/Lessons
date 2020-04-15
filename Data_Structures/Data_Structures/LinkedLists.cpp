#include <iostream>
#include<assert.h>
using namespace std;

// Declaration of a doubly-linked list
class List {
public:

	// Constructor and destructor
	List();
	~List();

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

	void pop_front();
	void pop_back();
	void insert(unsigned int position, const int& value);
	void erase(unsigned int position)
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
	}

	void clear();

	// Getters
	int& front();
	int& back();
	int& value_at(unsigned int position);
	bool empty() const;
	unsigned int size() const;
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
	unsigned int index = 0;
};