#include <iostream>
#include <stdlib.h>

class Player
{
private:
	char name[15];
	unsigned short int lifes;
	bool invencible;
	bool* capabilities;
	bool* weapon;

public:
	Player(char name[15]) 
	{
		lifes = 3;
		invencible = false;
	}
	~Player();

	char getName()
	{
		return name[15];
	}

	void printNumLifes()
	{
		std::cout << lifes << std::endl;
	}

	void printInvencible()
	{
		if (invencible == true) std::cout << name << " is invencible" << std::endl;
	}

	void printCapabilities()
	{
		std::cout << capabilities[0] << capabilities[1] << capabilities[2] << std::endl;
	}


};