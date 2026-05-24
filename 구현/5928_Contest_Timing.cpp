/*
	< 구현 >

	1. 11일 11시 11분을 분 단위로 기준을 잡음(671분).
		-> 기준이니까 0일 11시 11분으로 봐야함.
	2. 입력한 D, H, M을 구함.
		2-1. 종료 분 = ((D - 11) * 1440) + (H * 60) + M
	3. 소요 시간 = 종료 분 - 671분
		3-1. 소요 시간이 음수인 경우, "-1" 출력

*/

#include <iostream>
#include <algorithm>

using namespace std;

int start_time_minute = 671;
int D, H, M;

void input()
{
	cin >> D >> H >> M;
}

void solution()
{
	int cur_time_minute = (((D - 11) * 1440) + (H * 60) + M);
	int ans_time_minute = cur_time_minute - start_time_minute;

	if (ans_time_minute < 0)
	{
		cout << "-1" << '\n';
	}
	else
	{
		cout << ans_time_minute << '\n';
	}

	
}

int main()
{
	input();
	solution();

	return 0;
}