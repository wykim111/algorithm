/*
	< DP >

	1. nC2 조합을 사용하면 원하는 최댓값을 구할 수 있음.

*/

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[11] = { 0, };

void input()
{
	cin >> N;
}

void solution()
{
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;

	for (int i = 3; i < 11; i++)
	{
		dp[i] = ((i * (i - 1)) / 2);
	}

	cout << dp[N] << '\n';
}

int main()
{
	input();
	solution();

	return 0;
}


