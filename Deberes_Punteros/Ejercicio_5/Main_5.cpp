#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>


int main()
{
	char* word1;
	char* word2;
	char* conc = (char*)malloc(sizeof(char));

	std::cout << "Intruduce la primera palabra: " << std::endl;
	std::cin >> word1;
	

	std::cout << "introduce la segunda palabra: " << std::endl;
	std::cin >> word2;
	
	std::cout << word1 << std::endl;
	std::cout << word2 << std::endl;


	free(conc);

	system("pause");
	return 0;
}