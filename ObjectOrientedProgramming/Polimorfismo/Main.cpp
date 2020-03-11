#include <iostream>

using namespace std;

class Enemy
{
public:
	//Función virtual
	virtual void update() //Virtual baja hasta la siguiente función llamada update dentro de las Sub clases.
	{
		cout << "Enemy::Update" << endl;
	}

	//Función abstracta
	virtual void update() = 0;
};

class Alien : public Enemy
{
public:
	void update() override
	{
		cout << "Alien::Update" << endl;
	}
};

class Centaleon : public Enemy
{
public:
	void update() override
	{
		cout << "Centaleon::Update" << endl;
	}
};

class Zombie : public Enemy
{
public:
	void update() override
	{
		cout << "Zombie::Update" << endl;
	}
};



int main()
{
	Enemy* enemies[3] = {};
	/*enemies[0] = new Enemy*/ //No es legal, ya que la clase contiene ahora una función abstracta
	enemies[0] = new Alien;
	enemies[1] = new Centaleon;
	enemies[2] = new Zombie;

	for (int i = 0; i < 3; i++)
	{
		enemies[i]->update();
	}

	for (int i = 0; i < 3; i++)
	{
		delete enemies[i];
	}

	system("pause");
	return 0;

}