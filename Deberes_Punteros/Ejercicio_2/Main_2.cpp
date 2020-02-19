#include <iostream>
#include <stdlib.h>

void sum(int val1, int val2, int* result)
{
	(*result) = val1 + val2;
}


int main()
{
	int val1, val2;

	std::cout << "Dame dos valores para sumarlos: ";
	std::cin >> val1;
	std::cin >> val2;

	int result;

	sum(val1, val2, &result);

	std::cout << "Resultado: ";
	std::cout << result << std::endl;

	system("pause");
	return 0;
}