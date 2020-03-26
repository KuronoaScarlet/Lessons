#include <string.h>

class String {
public:
	//Constructors and Destructors
	String()
	{
		_size = 0;
		_data = new char[1];
		_data[0] = '\0';
	}

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
	void clear();
	const char* c_str() const;

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
		strcat(newData, s._data);
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
	bool operator==(const String& s) const
	{
		return (strcmp(_data, s._data) == 0);
	}

private:
	char* _data;	//Puntero al array de chars
	int _size;	//Tamaño del string
};