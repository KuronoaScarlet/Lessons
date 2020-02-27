#include <iostream>
#include <stdlib.h>

using namespace std;

struct Pirate 
{
	char name[30] = {"LeChuck"};
	int life = 100;

	void printPirateInfo(const Pirate& p);
};

struct Weapon
{
	char name[30] = { "Sword" };
	int	dmg = 10;

	void printWeaponInfo(const Weapon& w);
};

void Pirate::printPirateInfo(const Pirate& p)
{
	cout << "-- Pirate --" << endl << "Name = " << name << endl << "Life = " << life;
}

void Weapon::printWeaponInfo(const Weapon& w)
{
	cout << "-- Weapon --" << endl << "Name = " << name << endl << "Damage = " << dmg;
}


int main()
{
	Pirate pirate;
	Weapon weapon;

	pirate.printPirateInfo(pirate);
	weapon.printWeaponInfo(weapon);

	attack(&)


	system("pause");
	return 0;

}