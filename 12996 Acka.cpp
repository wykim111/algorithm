/*
	�κ����� ���� ���ϱ�
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<memory.h>
#define MOD 1000000007

using namespace std;
int S, doto, kesa, hong;
int dp[51][51][51][51]; // � ���� �� �������� �θ��� ����� ��

int go(int n, int d, int k, int h)
{
	//baseCase1 ��� �θ����� �� �θ� ����� �ִ� ��� 
	if (n == 0)
	{
		if (d == 0 && k == 0 && h == 0)
			return 1;
		return 0;
	}
	//�� �������� �θ��� �� ������ ������ ���
	if (d < 0 || k < 0 || h < 0)
	{
		return 0;
	}
	
	int& ret = dp[n][d][k][h];
	//�޸������̼�
	if (ret != -1)
	{
		return ret;
	}
	//��ΰ� �� �θ��� ���
	ret = go(n - 1, d - 1, k - 1, h - 1);
	ret %= MOD;
	// d�� �θ��� ���
	ret += go(n - 1, d - 1, k, h);
	ret %= MOD;
	//k�� �θ��� ���
	ret += go(n - 1, d, k - 1, h);
	ret %= MOD;

	//h�� �θ��� ���
	ret += go(n - 1, d, k, h - 1);
	ret %= MOD;
	//d�� k
	ret += go(n - 1, d - 1, k - 1, h);
	ret %= MOD;
	//d�� h
	ret += go(n - 1, d - 1, k, h - 1);
	ret %= MOD;
	//k�� h
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