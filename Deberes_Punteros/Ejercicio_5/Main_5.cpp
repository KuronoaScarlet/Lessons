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
	result = word1;
	result[strlen(word1)] = (char)word2;
	result[strlen(word1) + strlen(word2)] = '\0';
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

	std::cout << word1 << std::endl;
	std::cout << word2 << std::endl;

	free(conc);

	system("pause");
	return 0;
}