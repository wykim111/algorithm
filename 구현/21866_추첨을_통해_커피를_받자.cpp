/*
	< 구현 >

	1. 각 문제에 할당 된 점수보다 초과되는 경우 "hacker"
	2. 모든 문제의 총 합이 100점 이상이면 "draw"
	3. 모든 문제의 총 합이 100점 미만이면 "none"

*/

#include <iostream>
#include <algorithm>

using namespace std;

typedef struct _exam
{
	int pass_point;
	int my_point;
}exam;

exam stExam[9];

void init()
{
	// 100점, 100점, 200점, 200점, 300점, 300점, 400점, 400점, 500점
	stExam[0].pass_point = 100;
	stExam[1].pass_point = 100;
	stExam[2].pass_point = 200;
	stExam[3].pass_point = 200;
	stExam[4].pass_point = 300;
	stExam[5].pass_point = 300;
	stExam[6].pass_point = 400;
	stExam[7].pass_point = 400;
	stExam[8].pass_point = 500;

}

void input()
{
	for (int i = 0; i < 9; i++)
	{
		cin >> stExam[i].my_point;
	}
}

void solution()
{
	int hacker = 0;
	int sum = 0;

	for (int i = 0; i < 9; i++)
	{
		if (stExam[i].my_point > stExam[i].pass_point)
		{
			++hacker;
		}
		
		sum += stExam[i].my_point;
	}

	if (hacker > 0)
	{
		cout << "hacker" << '\n';

		return;
	}

	if (sum >= 100)
	{
		cout << "draw" << '\n';
	}
	else
	{
		cout << "none" << '\n';
	}
}


int main()
{
	init();
	input();
	solution();

	return 0;
}