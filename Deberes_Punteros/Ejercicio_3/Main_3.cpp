#include <iostream>
#include <stdlib.h>

void reverse(int* array)
{
	for (int i = 9; i >= 0; i--)
	{
		std::cout << *(array + i) << std::endl;
	}
}


int main()
{
	int vec[10];
	
	std::cout << "Dame 10 valores: "; 
	for (int i = 0; i < 10; i++)
	{
		std::cin >> vec[i];
	}

	reverse(vec);

	std::cout << "\n";

	system("pause");
	return 0;
}