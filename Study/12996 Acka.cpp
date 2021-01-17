/*
	부분집합 갯수 구하기
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<memory.h>
#define MOD 1000000007

using namespace std;
int S, doto, kesa, hong;
int dp[51][51][51][51]; // 곡에 대해 각 가수들이 부르는 경우의 수

int go(int n, int d, int k, int h)
{
	//baseCase1 모두 부른경우와 안 부른 사람이 있는 경우 
	if (n == 0)
	{
		if (d == 0 && k == 0 && h == 0)
			return 1;
		return 0;
	}
	//각 가수들의 부르는 곡 갯수가 음수인 경우
	if (d < 0 || k < 0 || h < 0)
	{
		return 0;
	}
	
	int& ret = dp[n][d][k][h];
	//메모이제이션
	if (ret != -1)
	{
		return ret;
	}
	//모두가 다 부르는 경우
	ret = go(n - 1, d - 1, k - 1, h - 1);
	ret %= MOD;
	// d만 부르는 경우
	ret += go(n - 1, d - 1, k, h);
	ret %= MOD;
	//k만 부르는 경우
	ret += go(n - 1, d, k - 1, h);
	ret %= MOD;

	//h만 부르는 경우
	ret += go(n - 1, d, k, h - 1);
	ret %= MOD;
	//d와 k
	ret += go(n - 1, d - 1, k - 1, h);
	ret %= MOD;
	//d와 h
	ret += go(n - 1, d - 1, k, h - 1);
	ret %= MOD;
	//k와 h
	ret += go(n - 1, d, k - 1, h - 1);
	ret %= MOD;

	return ret;
}
int main()
{
	int mainRet = 0;
	scanf("%d %d %d %d", &S, &doto, &kesa, &hong);

	memset(dp, -1, sizeof(dp));
	mainRet = go(S, doto, kesa, hong);

	printf("%d\n", mainRet);

	return 0;
}
