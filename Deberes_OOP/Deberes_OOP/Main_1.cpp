#include <iostream>
#include <stdlib.h>

void doubleNum(unsigned short int& n)
{
	n = n * 2;
}

int main()
{
	unsigned short int num;

	std::cout << "Introduce un numero del 0 al 100: "; std::cin >> num;

	doubleNum(num);

	std::cout << "El doble de tu numero es: " << num << std::endl;

	system("pause");
	return 0;
}