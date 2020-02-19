#include <stdio.h>
#include <iostream>
#include <stdlib.h>

void absSwap(int* arr1, int sizeArr1, int* arr2, int sizeArr2) 
{
	for (int i = 0; i < sizeArr1; i++)
	{
		arr1[i] = abs(arr2[i]);
	}
}

int main()
{
	int* arr1 = (int*)calloc(20, sizeof(int));
	int* arr2 = (int*)malloc(20 * sizeof(int));

	int size1 = 20;
	int size2 = 20;


	std::cout << "Introduce 20 valores, positivos, negativos o 0:" << std::endl;

	for (int i = 0; i < size2; i++)
	{
		std::cin >> arr2[i];
	}

	absSwap(arr1, size1, arr2, size2);

	std::cout <<"Array1:"<< std::endl;

	for (int i = 0; i < size1; i++)
	{
		std::cout << arr1[i];
		std::cout << " ";
	}
	std::cout << std::endl;

	std::cout << "Array2:" << std::endl;

	for (int i = 0; i < size2; i++)
	{
		std::cout << arr2[i];
		std::cout << " ";
	}
	std::cout << std::endl;

	free (arr1);
	free (arr2);

	system("pause");
	return 0;
}