#include <iostream>
#include <stdlib.h>

using namespace std;

class Pixel 
{

private:
	int r, g, b;

public:
	Pixel() : r(0), g(0), b(0) { }
	Pixel(int pR, int pG, int pB) : r(pR), g(pG), b(pB) { }

	int red() const { return r; }
	int green() const { return g; }
	int blue() const { return b; }

	Pixel mix(const Pixel& Pmix) const
	{
		Pixel res;
		res.r = (r + Pmix.r) / 2;
		res.g = (g + Pmix.g) / 2;
		res.b = (b + Pmix.b) / 2;
		return res;
	}
};

int main()
{
	Pixel black;
	Pixel blue(0, 0, 255);
	Pixel red(255, 0, 0);
	Pixel mixed = red.mix(blue);

	cout << black.red() << " " << black.green() << " " << black.blue() << endl;
	cout << mixed.red() << " " << mixed.green() << " " << mixed.blue() << endl;

	system("pause");
	return 0;
}