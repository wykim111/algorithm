#include<stdio.h>
#include<stdlib.h>

int visit[100];
int ret[100];
int cnt = 0;

void comb(int* set,int idx,int curIdx,int size,int pick)
{
	if (idx == pick)
	{
		for (int i = 0; i < idx; i++)
		{
			printf("%d ", ret[i]);
		}
		printf("\n");
		cnt++;
		return;
	}
	for (int i = curIdx; i < size; i++)
	{
		if (visit[i] == 1)
			continue;
		ret[idx] = set[i];
		//visit[i] = 1;
		comb(set, idx + 1, i + 1, size,pick);
		//visit[i] = 0;
	}
	return;
}

int main()
{
	int* arr;
	int N,K;

	scanf("%d %d", &N,&K);

	arr = (int*)malloc(sizeof(int)*N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("조합 경우의 수  출력\n");
	comb(arr, 0, 0, N,K);

	return 0;
}