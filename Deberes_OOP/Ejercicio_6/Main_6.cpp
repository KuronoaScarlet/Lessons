#include <iostream>
#include <stdlib.h>

class Clock
{
private:
	int h, min, sec;

public:
	Clock() : h(0), min(0), sec(0) { }
	Clock(int pH, int pMin, int pSec) : h(pH), min(pMin), sec(pSec){ }

	//Getters
	int hours() const { return h; }
	int minutes() const { return min; }
	int seconds() const { return sec; }

	bool equal(const Clock& time2) const
	{
		bool equal = false;
		if (h == time2.h && min == time2.min && sec == time2.sec)
		{
			return true;
		}
	}

	bool minor(const Clock& time2) const
	{
		bool minor = false;
		if ((h < time2.h && min < time2.min && sec < time2.sec))
		{
			return true;
		}
	}

	Clock setTime(unsigned int h, unsigned int min, unsigned int sec)
	{
		Clock setter;

		setter.h = h;
		setter.min = min;
		setter.sec = sec;

		return setter;
	}

	void printTime()
	{
		std::cout << h << ":" << min << ":" << sec << std::endl;
	}
};

int main()
{
	Clock c1;
	Clock c2(23, 59, 59);

	c1.printTime();
	c2.printTime();

	if (c1.minor(c2) == true)
	{
		std::cout << "El primer reloj presenta un tiempo menor al segundo:" << std::endl;
	}
	else
	{
		std::cout << "El segundo reloj presenta un tiempo menor al primero:" << std::endl;
	}

	c1 = c1.setTime(23, 59, 59);

	if (c2.equal(c1) == true)
	{
		std::cout << "Tras el set time, los relojes son iguales" << std::endl;
	}

	c1.printTime();
	c2.printTime();

	system("pause");
	return 0;
}