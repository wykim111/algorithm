#include<stdio.h>

int ret[9];
int arr[9];
int N,M;

void go(int idx, int curIdx)
{
	if (idx == M)
	{
		for (int i = 0; i < idx; i++)
		{
			printf("%d ", ret[i]);
		}
		printf("\n");
		return;
	}

	for (int i = curIdx; i < N; i++)
	{
		ret[idx] = arr[i];
		go(idx + 1, i);
	}
	return;
}
int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		arr[i] = i + 1;
	}

	go(0,0);

	return 0;
}