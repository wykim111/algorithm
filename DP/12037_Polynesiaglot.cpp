/*
	<DP>

	1. 마지막 글자가 "모음"인 경우, 단어 끝에 "모음"을 하나 붙임
		1-1. dp[i] = (dp[i-1] * V)
	2. 마지막 두 글자가 "자음 + 모음"인 경우, "자음 + 모음" 조합을 붙임.
		2-1. dp[i] = (dp[i-2] * C * V)
	초기 값 : dp[0] = 1, dp[1] = 모음의 갯수
	점화식 : dp[i] = (dp[i-1] * V) + (dp[i-2] *C * V);

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T;
int C, V, L;
int dp[16];

void init()
{
	for (int i = 0; i < 16; i++)
	{
		dp[i] = 0;
	}

}

void input()
{
	cin >> C >> V >> L;
}

void solution(int tc)
{
	dp[0] = 1;
	dp[1] = V; 

	for (int i = 2; i <= L; i++)
	{
		dp[i] = ((dp[i - 1] * V) + (dp[i - 2] * C * V));
	}

	cout << "Case #" << tc << ": " << dp[L] << '\n';
}

int main()
{
	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		input();
		solution(i);
	}

	return 0;
}
