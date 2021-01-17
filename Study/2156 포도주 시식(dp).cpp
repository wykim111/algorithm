/*
	1.현재 포도주를 마시지 않고 건너 뛰는 경우(i-1,i+1)
	2.현재 포도주와 이전 포도주를 마시는 경우(i,i-1)
	3. 현재 포도주와 그 이전이전 포도주를 마시는 경우(i,i-2)

*/
#include<stdio.h>

int grape[10001];
int N;
int ret = 0;
int dp[10001];

int max(int n1, int n2)
{
	if (n1 > n2)
		return n1;
	return n2;
}


int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &grape[i]);
	}

	dp[1] = grape[1];
	dp[2] = grape[2] + grape[1];

	for (int i = 3; i <= N; i++)
	{
		dp[i] = max(dp[i - 2] + grape[i], dp[i-3]+ grape[i-1]+grape[i]);
		dp[i] = max(dp[i], dp[i - 1]);
	}
	
	printf("%d\n", dp[N]);

	return 0;
}