/*
	LIS 알고리즘 활용

	증가하는 부분 수열이 확인된다면 현재 탐색하고 있는 인덱스를 더해준다.

	if(arr[cur] > arr[cur-1,,,,0])
	{
		m = max(m,LIS(cur-1,,,0));
	}
*/
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int N;
int arr[1000];
int dp[1000];

int LIS(int cur)
{
	int& ret = dp[cur];

	if (cur == 0)
		return dp[0] = arr[0];
	if (ret != -1)
		return ret;

	ret = arr[cur];
	int m = arr[cur];

	for (int next = cur - 1; next >= 0; next--)
	{
		if(arr[cur]> arr[next])
			m = max(m, LIS(next) + arr[cur]);
	}

	return ret = m;
}

int main()
{
	int maxSum = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		dp[i] = -1;
	}
	for (int i = N - 1; i >= 0; i--)
	{
		maxSum = max(maxSum, LIS(i));
	}
	printf("%d\n", maxSum);
	return 0;
}