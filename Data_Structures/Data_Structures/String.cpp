#include <iostream>
using namespace std;

class String {
public:
	//Constructors and Destructors
	String()
	{
		_size = 0;
		_data = new char[1];
		_data[0] = '\0';
	}

	String(const char* s)
	{
		_size = strlen(s);
		_data = new char[_size + 1];
		strcpy_s(_data, _size + 1, s);
	}

	~String()
	{
		delete[] _data;
	}

	//Methods
	bool empty() const { return (_size == 0); }
	int size() const { return _size; }


	//Operators

	//Para asignar
	void operator=(const char* s)
	{
		delete[] _data;
		_size = strlen(s);
		_data = new char[_size + 1];
		strcpy_s(_data, _size + 1, s);
	}

	//Para concatenar
	void operator+=(const String& s)
	{
		int newSize = _size + s._size;
		char* newData = new char[newSize];
		strcpy_s(newData, _size, _data);
		strcat_s(newData[_size + 1], s._data);
		delete[] _data;
		_data = newData;
		//TODO: Calcular el numero total de letras entre _size y s._size
		//TODO: Reservar memoria para todas esas letras
		//TODO: Copiar (strcpy_s) _data en el nuevo string
		//TODO: Copiar (strcat) s._data en el nuevo string
		//TODO: Liberar _data
		//TODO: Guardar el nuevo string en _data
	}
	
	//Para comparar
	bool operator==(const String &s) const
	{
		return (strcmp(_data, s._data) == 0);
	}
private:
	char *_data;	//Puntero al array de chars
	int _size;	//Tamaño del string
};


int main()
{
	String s1;
	String s2;

	String concat;


	s1 = "Ignasi";
	s2 = "Alejandra";

	if (s1 == s2)
	{
		cout << "Son iguales" << endl;
	}
	else
	{
		cout << "No son iguales" << endl;
	}

	concat += s1;
	concat += s2;

	system("pause");
	return 0;
}