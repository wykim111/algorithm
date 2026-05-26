/*
	< 구현 >

	1. 입력된 4개의 연속된 값이 증가를 이루면, "Fish Rising"
	2. 입력된 4개의 연속된 값이 감소를 이루면, "Fish Diving"
	3. 입력된 4개의 연속된 값이 모두 동일한 경우, "Fish At Constant Depth"
	4. 그 외의 모든 경우, "No Fish"
=====================================================================================

	1. 현재 숫자가 다음 숫자보다 크면 bigger_flag = true
	2. 현재 숫자가 다음 숫자보다 작으면 smaller_flag = true
	3. 현재 숫자가 다음 숫자와 같으면 equal_flag = true
	4. 1~3번중 1개만 true이여야만 함. 
	5. 모두 false이면 "No Fish"

		

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> depth_vt;

// 💡 직관적인 이름으로 플래그 선언 (오타 수정)
bool rising_flag = false;
bool diving_flag = false;
bool equal_flag = false;

void input()
{
	for (int i = 0; i < 4; i++)
	{
		int depth_data;
		cin >> depth_data;
		depth_vt.push_back(depth_data);
	}
}

void solution()
{
	int cur_depth = depth_vt[0];

	for (int i = 1; i < 4; i++)
	{
		int next_depth = depth_vt[i];

		// 현재보다 다음 수심이 깊어짐 (숫자가 커짐)
		if (cur_depth < next_depth)
		{
			rising_flag = true;
		}
		// 현재보다 다음 수심이 얕아짐 (숫자가 작아짐)
		if (cur_depth > next_depth)
		{
			diving_flag = true;
		}
		// 수심이 같음
		if (cur_depth == next_depth)
		{
			equal_flag = true;
		}

		cur_depth = next_depth;
	}

	// 💡 오타 수정된 플래그로 최종 판별
	if (rising_flag == true && diving_flag == false && equal_flag == false)
	{
		cout << "Fish Rising" << '\n';
	}
	else if (rising_flag == false && diving_flag == true && equal_flag == false)
	{
		cout << "Fish Diving" << '\n';
	}
	else if (rising_flag == false && diving_flag == false && equal_flag == true)
	{
		cout << "Fish At Constant Depth" << '\n';
	}
	else
	{
		cout << "No Fish" << '\n';
	}
}

int main()
{
	input();
	solution();

	return 0;
}



