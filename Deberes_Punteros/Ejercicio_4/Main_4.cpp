#include <stdio.h>
#include <stdlib.h>



int main()
{
	int* arr1 = (int*)calloc(20, sizeof(int));
	int* arr2 = (int*)malloc(20 * sizeof(int));

	int size1 = sizeof(arr1);
	int size2 = sizeof(arr2);

	for (int i = 0; i < size2; i++)
	{
		scanf_s("%d", arr2[i]);
	}

	for (int i = 0; i < size2; i++)
	{
		printf("%d ", arr2[i]);
	}

	free (arr1);
	free (arr2);

	system("pause");
	return 0;
}