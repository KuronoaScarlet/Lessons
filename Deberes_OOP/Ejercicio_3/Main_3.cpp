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
	cout << "-- Pirate --" << endl << "Name = " << name << endl << "Life = " << life << endl;
}

void Weapon::printWeaponInfo(const Weapon& w)
{
	cout << "-- Weapon --" << endl << "Name = " << name << endl << "Damage = " << dmg << endl;
}

void attack(Pirate* p, Weapon w)
{
	p->life = p->life - w.dmg;
}

int main()
{
	Pirate pirate;
	Weapon weapon;

	pirate.printPirateInfo(pirate);
	cout << endl;

	weapon.printWeaponInfo(weapon);
	cout << endl;

	system("pause");

	attack(&pirate, weapon);

	cout << endl;
	pirate.printPirateInfo(pirate);

	cout << endl;
	system("pause");
	return 0;

}