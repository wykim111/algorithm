/*
		a + b = c ->  b = c - a

		b = (c.x - a.z, c.y / a.y ,c.z - a.x)
*/
#include<iostream>
#include<cstdio>

using namespace std;

class Cake
{
public:
	int x;
	int y;
	int z;

	const Cake operator-(Cake& args)
	{
		Cake pt;

		pt.x = this->x - args.z;
		pt.y = this->y / args.y;
		pt.z = this->z - args.x;

		return pt;
	}

	void Print()
	{
		cout << x << " " << y << " " << z;
	}
};


int main()
{
	Cake a, b, c;

	cin >> a.x >> a.y >> a.z;
	cin >> c.x >> c.y >> c.z;

	b = c.operator-(a);

	b.Print();

	return 0;
}