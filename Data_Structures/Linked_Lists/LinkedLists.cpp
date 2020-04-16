#include <iostream>
#include <assert.h>
using namespace std;

//Declaración de una lista "Double-Linked"
class LinkedList 
{
public:

	//Constructor y destructor
	LinkedList() {}
	~LinkedList() {}

	//Modificadores
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

	void insert(unsigned int index, const int& value)
	{
		assert(index >= 0 && index <= num_elems);
		if (index == 0)
		{
			push_front(value);
		}
		else if (index != 0 && index != num_elems)
		{
			Node* node = new Node;
			Node* itf = first;
			Node* itl = last;
			node->value = value;

			for (unsigned int i = 1; i < index - 1; i++)
			{
				itf = itf->next;
			}
			for (unsigned int i = num_elems; i > index + 1; i--)
			{
				itl = itl->prev;
			}

			node->prev = itf;
			node->next = itl;
			itf->next = node;
			itl->prev = node;
			num_elems++;
		}
		else if (index == num_elems)
		{
			push_back(value);
		}
	}

	void erease(unsigned int index)
	{
		assert(index <= num_elems);
		Node* toErease;
		Node* itf = first;
		Node* itl = last;

		if (index == 0)
		{
			toErease = first;
			itf = itf->next;
			delete toErease;
		}
		

		for (unsigned int i = 1; i < index - 1; i++)
		{
			itf = itf->next;
		}
		for (unsigned int i = num_elems; i > index + 1; i--)
		{
			itl = itl->prev;
		}

		toErease = itf->next;

		if (toErease == itl->prev)
		{
			delete toErease;
			itf->next = itl;
			itl->prev = itf;
		}
		num_elems--;
	}

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

	//Getters
	int& front() { return first->value; }
	int& back() { return last->value; }
	//int& value_at(unsigned int index);
	bool empty() const { return true == (num_elems == 0); }
	unsigned int size() const { return num_elems; }

private:
	//Estructura interna para los nodos de la lista
	struct Node {
		int value;
		Node* next;
		Node* prev;
	};

	//Lista de internos
	Node* first = nullptr;
	Node* last = nullptr;
	unsigned int num_elems = 0;
};

int main()
{
	LinkedList list1;

	//TODO 1: push_back, push_front, print
	list1.push_back(10);
	list1.push_back(20);
	list1.push_back(30);
	list1.push_front(0);
	list1.print();
	//Shuold print 0 10 20 30

	cout << endl;

	//TODO 2: insert
	list1.insert(0, -1);
	list1.insert(5, 100);
	list1.insert(3, 15);
	list1.print();
	//Should print -1 0 10 15 20 30 100

	cout << endl;

	//TODO 3: erease
	list1.erease(6);
	list1.erease(0);
	list1.erease(3);
	list1.print();
	//Should print 0 10 15 30


	system("pause");
	return 0;
}