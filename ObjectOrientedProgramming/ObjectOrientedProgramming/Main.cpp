#include <iostream>
#include <stdlib.h>

namespace mathlib	//Declaración de un namespace: Zona de código dedicada a lo que suceda dentro. se le llama con el nombre del namespace::función
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