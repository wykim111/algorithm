#include <stdio.h>

#define MOD	1000000007
#define LLD	long long int

int n;
LLD dp[1000001];

void input()
{
	scanf("%d",&n);
}

void solution()
{
	dp[0] = 0;
	dp[1] = 1;

	for(int i = 2; i <= n; i++)
	{
		dp[i] = ((dp[i-1] + dp[i-2])%MOD);
	}


	printf("%lld\n",dp[n]);
}

int main()
{
	input();
	solution();

	return 0;
}
