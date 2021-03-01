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

	const Point& operator++() // 전위 ++
	{
		++x;
		++y;
		return *this;
	}

	const Point operator++(int) // 후위 ++
	{
		Point pt(x, y);
		++x;
		++y;
		return pt;
	}
};


int main()
{
	Point p1(2, 3), p2(2, 3);
	Point result;

	//전위 증가
	result = ++p1;
	p1.Print();
	result.Print();

	result = p2++;
	p2.Print();
	result.Print();

	return 0;
}
