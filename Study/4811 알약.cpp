#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;
int N;
long long int dp[31][31];

long long int go(int W, int H)
{
	//base  case
	if (W < 0 || H < 0)
		return 0;
	//base  case
	if (W == 0 && H == 0)
	{
		return 1;
	}
	long long int& ret = dp[W][H];

	if (ret != 0)
		return ret;
	

	if (W > 0)
	{
		ret += go(W - 1, H + 1);
	}
	if(H > 0)
	{
		ret += go(W, H - 1);
	}

	return ret;
}

int main()
{
	memset(dp, 0, sizeof(dp));
	while (scanf("%d", &N) != EOF && N != 0)
	{
		printf("%lld\n", go(N, 0));
	}

	return 0;
}
