#include <iostream>
using namespace std;

#define CHUNK_SIZE 5

class Queue
{
public:
	Queue()
	{
		_data = new int[CHUNK_SIZE];
		_size = 0;
		_capacity = CHUNK_SIZE;
		_front = -1;
		_back = -1;
	}

	int front() const 
	{ 
		//TODO: Controlar posibles errores (Assert).
		return _data[_front]; 
	}

	int size() const { return _size; }
	bool empty() const { return _size == 0; }

	void enqueue(int value)
	{
		if (_size == _capacity)
		{
			increaseCapacity();
		}

		if (_size == 0)
		{
			_front = 0;
			_back = 0;
			_size++;
			_data[_back] = value;
		}
		else
		{
			//TODO: Cuando _size no es 0;
			//Front no cambia
			_back = (_back + 1) % _capacity;
			_size++;
			_data[_back] = value;
		}
	}

	void dequeue()
	{
		//TODO: Controlar posibles errores (Assert).
		_front = (_front + 1) % _capacity;
		_size--;
	}

private:

	void increaseCapacity()
	{
		//TODO
		int newCpacity = _capacity + CHUNK_SIZE;
		int* _newData = new int[newCpacity];

		if (_front < _back)
		{
			for (int i = 0; i < _size; i++)
			{
				_newData[i] = _data[_front + 1];
			}
			_front = 0;
			_back = _size;
		}
		else
		{
			int i;
			for ( i = 0; i < _capacity - _front; i++)
			{
				_newData[i] = _data[_front + 1];
			}
			for (int j = 0; j < _back; j++)
			{
				_newData[i] = _data[j];
			}
			_front = 0;
			_back = _size;
		}
		
		_capacity = newCpacity;
		delete[] _data;
		_data = _newData;
	}

	int* _data;		//Puntero a memoria dinámica con espacio reservado
	int _back;		//Índice del último elemento
	int _front;		//Índice del primer elemento
	int _size;		//Vantided de elementos ocupados.
	int _capacity;	//Número total de elementos del Array
};


int main()
{
	Queue q;

	q.enqueue(0);
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);

	q.dequeue();
	q.dequeue();
	q.dequeue();

	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);

	system("pause");
	return 0;
}