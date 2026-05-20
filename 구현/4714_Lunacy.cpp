/*
	< ±¸Çö >

	1.  Y = X * 0.167

*/

#include <iostream>
#include <algorithm>

using namespace std;

double X, Y;

void input()
{
	cin >> X;
}

void solution()
{
	Y = (X * 0.167);

	cout << fixed;
	cout.precision(2);

	cout << "Objects weighing " << X << " on Earth will weigh " << Y << " on the moon." << '\n';
}

int main()
{
	while (true)
	{
		input();

		if (X < 0)
		{
			break;
		}

		solution();
	}

	return 0;
}
