#include<stdio.h>

int arr[3] = { 3,5,10 };

int go(int dep,int sum)
{
	if (sum < 0)
		return 0;

	if (sum == 0)
	{
		return 1;
	}
	int ret = 0;
	for (int i = 0; i < 3; i++)
	{
		ret += go(dep + 1, sum - arr[i]);
	}
	return ret;
}

int main()
{
	int N;

	scanf("%d", &N);

	printf("%d\n",go(0,N));
	return 0;
}