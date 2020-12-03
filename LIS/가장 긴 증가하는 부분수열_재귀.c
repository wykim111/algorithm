#include<stdio.h>

int arr[100];
int maxRet = -1;

void go(int dep,int idx,int choice,int len)
{
	if (dep == 0)
	{
		if (maxRet < len)
		{
			maxRet = len;
		}
		return;
	}

	if (arr[idx] < arr[idx - 1])
	{
		go(dep - 1, idx - 1, choice,len);
	}
	else if(arr[idx] >  arr[idx-1])
	{
		go(dep - 1, idx - 1, arr[idx-1],len+1);
		go(dep - 1, idx - 1, choice,len);
	}


}


int main()
{
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = N - 1; i >= 0; i--)
	{
		go(i, i, arr[i], 1);
	}
	printf("%d\n", maxRet);

	return 0;
}
