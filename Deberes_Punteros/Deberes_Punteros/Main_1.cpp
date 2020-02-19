#include <iostream>
#include <stdlib.h>

int main()
{
	int vec1[10] = { 1, 2, 3 ,4, 5, 6, 7, 8, 9, 10 };

	for (int i = 0; i < 10; i++)
	{
		vec1[i] = (int)&vec1[i];
		std::cout << vec1[i] << std::endl;
	}

	system("pause");
	return 0;
}