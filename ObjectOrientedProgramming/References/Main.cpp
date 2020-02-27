#include <iostream>
#include <stdlib.h>

void increment(int& n)	//Este n�mero se ha pasado por referencia. Int& es una declaraci�n que obtiene la direcci�n de memoria de a.
{
	n++;		//El incremento se realiza sobre n, que a su vez, al ser n una declaraci�n de referencia, incrementa a.
}

int main()
{
	int a = 3;
	int& ra = a;	//Obtenemos la direccion de la memoria de a.
	increment(a);	//Enviamos a pero con un puntero por detr�s, para que no se realice una copia, sino que se pase por referencia.
	std::cout << ra << std::endl;

	system("pause");
	return 0;
}