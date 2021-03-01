#include<iostream>
using namespace std;

class Point
{
	//class 내 class 변수들의 접근 지정은 기본적으로 private
	int x;
	int  y;

public:
	Point(int _x = 0, int _y = 0)
		:x(_x), y(_y)
	{

	}
	void Print() const
	{
		cout << x << ',' << y << endl;
	}

	const Point operator+(const Point& arg) const
	{
		Point pt;
		pt.x = this->x + arg.x;
		pt.y = this->y + arg.y;

		return pt;
	}
};


int main()
{
	Point p1(2, 3), p2(5, 5);
	Point p3;

	p3 = p1 + p2;

	p3.Print();

	p3 = p1.operator+(p2);
	p3.Print();

	return 0;
}
