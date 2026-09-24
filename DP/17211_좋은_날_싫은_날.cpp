/*
	< dp >
	1. 상태 정의	
		0 : 기분이 좋은 날
		1 : 기분이 싫은 날
		state_table[0][0] ~ [1][1]
	
	2. dp 계산
		2-1. 1일치 계산
			좋은 날일 확률 = (오늘 기분) * (싫음 -> 좋음 : state_table[1][0])
			싫은 날일 확률 = (오늘 기분) * (싫음 -> 싫음 : state_table[1][1])
		
		2-2. 2일부터 N일까지 계산
			2-2-1. i일차가 좋은 날이 되는 경우
				(i-1)일차가 좋음 && i일차도 좋음
				(i-1)일차가 싫음 && i일차 좋음
			2-2-2. i일차가 싫은 날이 되는 경우
				(i-1)일차 좋음 && i일차도 싫음
				(i-1)일차가 싫음 && i일차 싫음


*/

#include <iostream>
#include <algorithm>

#define HAPPY	0
#define SAD		1

using namespace std;

int N, today_mood;
double state_table[2][2];
double dp[1001][2]; // dp[i][0] : i일차가 좋은 날일 확률, dp[i][1] : i일차가 싫은 날일 확률

void input()
{
	cin >> N >> today_mood;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> state_table[i][j];
		}
	}
}

void solution()
{
	//0일차 계산
	if (today_mood == HAPPY)
	{
		dp[0][HAPPY] = 1.0;
		dp[0][SAD] = 0.0;
	}
	else
	{
		dp[0][HAPPY] = 0.0;
		dp[0][SAD] = 1.0; 
	}

	// 1일차 계산
	dp[1][HAPPY] = (dp[0][HAPPY] * state_table[HAPPY][HAPPY]) + (dp[0][SAD] * state_table[SAD][HAPPY]);
	dp[1][SAD] = (dp[0][HAPPY] * state_table[HAPPY][SAD]) + (dp[0][SAD] * state_table[SAD][SAD]);

	// 2일차 ~ N일차 계산
	for (int i = 2; i <= N; i++)
	{
		dp[i][HAPPY] = (dp[i - 1][HAPPY] * state_table[HAPPY][HAPPY]) + (dp[i - 1][SAD] * state_table[SAD][HAPPY]); // i일차가 좋은 날이 되는 경우
		dp[i][SAD] = (dp[i - 1][HAPPY] * state_table[HAPPY][SAD]) + (dp[i - 1][SAD] * state_table[SAD][SAD]); // i일차가 싫은 날이 되는 경우
	}

	cout << (int)(dp[N][HAPPY] * 1000) << '\n';
	cout << (int)(dp[N][SAD] * 1000) << '\n';


}

int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}