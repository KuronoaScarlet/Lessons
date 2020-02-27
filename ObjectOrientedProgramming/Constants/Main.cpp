#include <iostream>
#include <stdlib.h>

#define Pi 3,141595	//El define es una declaración de una constante global.

class Foo
{
public:
	/*Métodos de inicialización de variables en clases*/
	//int n = 0;		//Método 1
	//Foo() { n = 0; }	//Método 2
	Foo() : n(0) {}		//Método 3

	void set(int v) { n = v; }
	int get() const { return n; }

private:

	int n;
};

int main()
{
	const Foo f1;
	int n1 = f1.get();
	//f1.set(3);  No compilará!

	Foo f2;
	f2.set(3);	//Sí que compilará

	/*const int a = 4;	//inicialización de una variable constante.
	//a = 3;	error! las variables constantes no se pueden cambiar de ninguna manera.

	int b = 4;

	const int* p1 = &b; //puntero a datos constantes
	//puedes cambiar p1, pero no *p1

	int* const p2 = &b; //puntero constante a datos
	//no puedes cambiar p2, pero si *p2

	const int* const p3 = &b; //puntero constante a datos constantes
	//no puedes modificar nada*/

	system("pause");
	return 0;
}