#include <iostream>
#include <stdlib.h>

namespace mathlib	//Declaraci�n de un namespace: Zona de c�digo dedicada a lo que suceda dentro. se le llama con el nombre del namespace::funci�n
{
	int max(int a, int b)
	{
		if (a > b) return a;
		return b;
	}

	int min(int a, int b)
	{
		if (a < b) return a;
		return b;
	}
}

int main()
{
	bool isAlive = true;
	int c = mathlib::max(1, 2);

	system("pause");
	return 0;
}