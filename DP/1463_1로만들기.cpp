/*
	- X가 3으로 나누어 떨어지면, 3으로 나눈다.
	- X가 2로 나누어 떨어지면, 2로 나눈다.
	- 1을 뺀다

	 메모이제이션 활용
	1. dp 테이블 -1로 초기화
	2. dp[n] = min(memo(n%2),dp[n])
	2. dp[n] = min(memo(n%3),dp[n])
	2. dp[n] = min(memo(n-1),dp[n])

*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#include <climits>
using namespace std;

int dp[1000001];
int N;

void input()
{
	cin >> N;
}


#if 0
int go(int n)
{
	if (n == 1)
	{

		return 0;
	}

	int& ret = dp[n];

	if (ret != MAX_NUM)
	{
		return ret;
	}


	// 3으로 나누어 떨어질 때: (현재까지 구한 최솟값)과 (n/3을 1로 만드는 횟수 + 1) 비교
	if ((n % 3) == 0)
	{
		ret = min(ret, go(n / 3) + 1);
	}

	// 2로 나누어 떨어질 때: (현재까지 구한 최솟값)과 (n/2를 1로 만드는 횟수 + 1) 비교
	if ((n % 2) == 0)
	{
		ret = min(ret, go(n / 2) + 1);
	}

	ret = min(ret, go(n - 1) + 1);


	return ret;
}

void solution()
{
	memset(dp, 0x3f, sizeof(dp));

	cout << go(N) << '\n';


}
#endif

void solution()
{
	memset(dp, 0x00, sizeof(dp));

	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1;

		if ((i % 2) == 0)
		{
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
		if ((i % 3) == 0)
		{
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
	}

	cout << dp[N] << "\n";
}



int main()
{
	input();
	solution();

	return 0;
}