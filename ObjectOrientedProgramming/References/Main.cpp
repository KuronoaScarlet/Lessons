#include <iostream>
#include <stdlib.h>

void increment(int& n)	//Este número se ha pasado por referencia. Int& es una declaración que obtiene la dirección de memoria de a.
{
	n++;		//El incremento se realiza sobre n, que a su vez, al ser n una declaración de referencia, incrementa a.
}

int main()
{
	int a = 3;
	int& ra = a;	//Obtenemos la direccion de la memoria de a.
	increment(a);	//Enviamos a pero con un puntero por detrás, para que no se realice una copia, sino que se pase por referencia.
	std::cout << ra << std::endl;

	system("pause");
	return 0;
}