#include <string.h>

class String {
public:
	//Constructors and Destructors
	String()
	{
		_size = 0;
		_data = new char[1];
		_data[0] = "\0";
	}

	String(const char *s);
	String(const String& s);
	~String();

	//Methods
	bool empty() const { return (_size == 0); }
	int size() const { return _size; }
	void clear();
	const char* c_str() const;

	//Operators
	//Para asignar
	void operator=(const char *s)
	{
		int newSize = strlen(s);
	}
	void operator+=(const String&);	//Para concatenar
	bool operator==(const String&) const;	//Para comparar
	bool operator!=(const String&) const;	//Para comparar

private:
	char* _data;	//Puntero al array de chars
	int _size;	//Tamaño del string
};