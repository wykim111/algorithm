#include<stdio.h>

int N, X;
int arr[1000];

int isSubsetSum(int dep,int sum)
{

	if (arr[dep] > X )
	{
		return isSubsetSum(dep + 1, sum);
	}
	if (dep == N)
	{
		if (sum == X)
		{
			return 1;
		}
		return 0;
	}

	return isSubsetSum(dep + 1, sum + arr[dep]) || isSubsetSum(dep + 1, sum);
}
int main()
{
	scanf("%d %d", &N, &X);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	if (isSubsetSum(0, 0) == 1)
	{
		printf("가능\n");
	}
	else
	{
		printf("불가능\n");
	}
	return 0;
}

