#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

void printCharPtr(char* myString)
{
	std::cout << myString << std::endl;
}

int sizeWord(char* word)
{
	int num = strlen(word);

	return num;
}

void concat(char* word1, char* word2, char* result) 
{
	int size1 = strlen(word1);
	int size2 = strlen(word2);

	for (int i = 0; i < size1; i++)
	{
		result[i] = word1[i];
	}

	for (int i = 0; i < size2; i++)
	{
		result[size1 + i] = word2[i];
	}

	result[size1 + size2] = '\0';
}

int main()
{
	char word1[50];
	char word2[50];
	int size1 = 0, size2 = 0;

	std::cout << "Intruduce la primera palabra: " << std::endl;
	std::cin >> word1;

	size1 = sizeWord(word1);
	
	std::cout << "Introduce la segunda palabra: " << std::endl;
	std::cin >> word2;

	size2 = sizeWord(word2);

	char* conc = (char*)malloc((size1 + size2 + 1)*sizeof(char));

	concat(word1, word2, conc);
	
	printCharPtr(conc);

	free(conc);

	system("pause");
	return 0;
}