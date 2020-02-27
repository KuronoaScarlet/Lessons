#include <iostream>
#include <stdlib.h>

/*struct Enemy
{
	int life;
	
private:		//Parte del struct privada, no se puede acceder.
	int mana;

public:			//Parte del struct pública. Inverse ídem.
	int stamina;
};*/

class Enemy		//Las clases, por defecto, son privadas
{
private:
	int life;
	int mana;
	int stamina;

public:
	Enemy(); //Constructor por defecto
			 //Se le llama cuando un enemigo es creado.

	Enemy(int pLife, int pMana, int pStamina);

	void printValues();
	void suicide();		//Las funciones llevan implícitas todas las variables de dentro de la clase o el struct.
	void setLife(int);
};

Enemy::Enemy()
{
	life = 100;
	mana = 10;
	stamina = 80;
}

Enemy::Enemy(int pLife, int pMana, int pStamina)
{
	life = pLife;
	mana = pMana;
	stamina = pStamina;
}

void Enemy::printValues()
{
	std::cout << life << std::endl << mana << std::endl << stamina << std::endl << std::endl;
}

void Enemy::suicide()
{
	life = 0;
}

void Enemy::setLife(int newLife)
{
	life = newLife;
}

int main()
{
	Enemy enemy1;
	Enemy enemy2(200, 150, 300);

	enemy1.printValues();
	enemy2.printValues();

	/*enemy1.life = 150;
	enemy1.mana = 120;
	enemy1.stamina = 100;*/

	enemy1.suicide();
	enemy2.suicide();

	enemy1.printValues();
	enemy2.printValues();

	enemy1.setLife(100);

	enemy1.printValues();
	enemy2.printValues();

	system("pause");
	return 0;
}