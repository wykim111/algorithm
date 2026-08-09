/*
	< 구현 >
	1. 입력된 숫자를 한 자리씩 분리하여 곱함
	2. 곱한 수가 1자리수가 될 때까지 반복
	3. 한 자리수 출력.

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int num;
vector<int> arr_vt;

void input()
{
	cin >> num;
}

void solution()
{
	int total = 1;
	int digit_cnt = 0;
	int step = 0;
	

	int temp = num;

	while (true)
	{
		//각 자리수의 숫자를 나눔
		while (true)
		{
			arr_vt.push_back(temp % 10);
			temp = (temp / 10);

			if (temp == 0)
			{
				break;
			}
		}


		//자릿수가 1이면 반복문 탈출
		if (arr_vt.size() == 1)
		{
			break;
		}

		//자릿수 연산
		for (int i = 0; i < arr_vt.size(); i++)
		{
			total *= arr_vt[i];
		}
#if 0
		cout << "arr_vt.size = " << arr_vt.size() << '\n';
		cout << "total = " << total << '\n';
#endif
		temp = total;
		arr_vt.clear();
		total = 1;
		
		++step;

	}


	cout << step << '\n';


}


int main()
{
	input();
	solution();

	return 0;
}