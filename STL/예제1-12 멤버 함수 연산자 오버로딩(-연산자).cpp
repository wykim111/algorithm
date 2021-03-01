#include<iostream>

using namespace std;

class Point
{
	int mx;
	int my;

public:
	Point(int x = 0, int y = 0) : mx(x), my(y) {}
	void Print() const { cout << mx << ',' << my << endl; }
	int GetX() const { return mx; }
	int GetY() const { return my; }

	const Point operator -(const Point& arg)
	{
		return Point(mx - arg.mx, my - arg.my);
	}
};

int main()
{
	Point p1(2, 3), p2(5, 5);
	Point p3;

	p3 = p1 - p2;

	p3.Print();

	return 0;
}