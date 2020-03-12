#include <iostream>
#include <stdlib.h>
#include <string.h>

#define N 12
#define DEF_DMG 10

using namespace std;

class Pokemon
{
protected:
	char name[N];
	char type[N];

public:
	Pokemon(const char* nameof)
	{
		strcpy_s(name, nameof);
		strcpy_s(type, "noType");
	}
	~Pokemon() {}

	const char* getName() const { return name; }
	const char* getType() const { return type; }
	virtual int damageAttack(Pokemon* other) const = 0;
};

class ElectricPokemon : public Pokemon
{
public:
	ElectricPokemon(const char* nameof) : Pokemon(nameof)
	{
		strcpy_s(type, "Electric");
	}

	int damageAttack(Pokemon* other) const override
	{
		if (strcmp(other->getType(), "Grass") == 0)
		{
			return (DEF_DMG / 2);
		}
		else if (strcmp(other->getType(), "Electric") == 0)
		{
			return (DEF_DMG / 2);
		}
		else if (strcmp(other->getType(), "Water") == 0)
		{
			return (DEF_DMG * 2);
		}
		else
		{
			return DEF_DMG;
		}
	}
};

class GrassPokemon : public Pokemon
{
public:
	GrassPokemon(const char* nameof) : Pokemon(nameof)
	{
		strcpy_s(type, "Grass");
	}

	int damageAttack(Pokemon* other) const override
	{
		if (strcmp(other->getType(), "Fire") == 0)
		{
			return (DEF_DMG / 2);
		}
		else if (strcmp(other->getType(), "Water") == 0)
		{
			return (DEF_DMG * 2);
		}
		else
		{
			return DEF_DMG;
		}
	}
};

class FirePokemon : public Pokemon
{
public:
	FirePokemon(const char* nameof) : Pokemon(nameof)
	{
		strcpy_s(type, "Fire");
	}

	int damageAttack(Pokemon* other) const override
	{
		if (strcmp(other->getType(), "Water") == 0)
		{
			return (DEF_DMG / 2);
		}
		else if (strcmp(other->getType(), "Grass") == 0)
		{
			return (DEF_DMG * 2);
		}
		else
		{
			return DEF_DMG;
		}
	}
};

class WaterPokemon : public Pokemon
{
public:
	WaterPokemon(const char* nameof) : Pokemon(nameof)
	{
		strcpy_s(type, "Water");
	}

	int damageAttack(Pokemon* other) const override
	{
		if (strcmp(other->getType(), "Grass") == 0)
		{
			return (DEF_DMG / 2);
		}
		else if (strcmp(other->getType(), "Fire") == 0)
		{
			return (DEF_DMG * 2);
		}
		else
		{
			return DEF_DMG;
		}
	}
};

int main()
{
	Pokemon* pikachu = new ElectricPokemon("Pikachu");
	Pokemon* bulbasaur = new GrassPokemon("Bulbasaur");
	Pokemon* charmander = new FirePokemon("Charmander");
	Pokemon* squirtle = new WaterPokemon("Squirtle");

	cout << "-- Damage Attacks --\n" << endl;

	cout << pikachu->getName() << " -> " << bulbasaur->getName() << " = " << pikachu->damageAttack(bulbasaur) << " units." << endl;
	cout << bulbasaur->getName() << " -> " << squirtle->getName() << " = " << bulbasaur->damageAttack(squirtle) << " units." << endl;
	cout << squirtle->getName() << " -> " << charmander->getName() << " = " << squirtle->damageAttack(charmander) << " units." << endl;
	cout << charmander->getName() << " -> " << pikachu->getName() << " = " << charmander->damageAttack(pikachu) << " units." << endl << endl;;

	system("pause");
	return 0;
}