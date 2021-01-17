#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>

using namespace std;
int N, S;
int arr[41];
map<int, int> mp;
int ret = 0;

void leftSequence(int dep, int sum)
{
	if (dep == N / 2)
	{
		mp[sum]++;
		return;
	}
	leftSequence(dep + 1, sum + arr[dep]);
	leftSequence(dep + 1, sum);
}

void rightSequence(int dep, int sum)
{
	if (dep == N)
	{
		ret += mp[S - sum];

		return;
	}

	rightSequence(dep + 1, sum + arr[dep]);
	rightSequence(dep + 1, sum);
}

int main()
{
	int halfLen = 0;

	scanf("%d %d", &N,&S);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	leftSequence(0, 0);
	rightSequence(N / 2, 0);

	if (S == 0)
		ret--;

	printf("%d\n", ret);


	return 0;
}