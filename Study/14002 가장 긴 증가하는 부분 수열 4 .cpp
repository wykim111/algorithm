/*
	https://www.acmicpc.net/problem/11055
	LIS 알고리즘
if(arr[N] > arr[i])
	ret = max(LIS(i),ret);

*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include<cstring>
int N;
int arr[1000];
int dp[1000];

int max(int n1, int n2)
{
	if (n1 < n2)
		return n2;
	return n1;
}
//메모이제이션 재귀
int LIS(int n)
{
	int& ret = dp[n];

	if (n == 0)
		return ret = 1;

	if (ret != -1)
		return ret;
	ret = 0;
	int maxLen = 0;

	for (int i = n - 1; i >= 0; i--)
	{
		if(arr[n] > arr[i])
			maxLen = max(maxLen, LIS(i));
	}
	return ret = maxLen+1;
}
//backtracking
void backtracking(int idx,int len)
{
	if (idx == -1)
		return;
	if (dp[idx] == len)
	{
		backtracking(idx - 1, len - 1);
		printf("%d ", arr[idx]);
	}
	else
	{
		backtracking(idx - 1, len);
	}
}

int main()
{
	int maxLen = 0;
	memset(dp, -1, sizeof(dp));

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	for (int i = N - 1; i >= 0; i--)
	{
		maxLen = max(maxLen, LIS(i));
	}
	printf("%d\n", maxLen);
	/*
	for (int i = 0; i < N; i++)
	{
		printf("%d ", dp[i]);
	}
	printf("\n");
	*/
	
	//백트렉킹
	backtracking(N - 1, maxLen);
	return 0;
}